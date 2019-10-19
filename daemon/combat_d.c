/**
 * @file
 8 @brief Various combat subroutines
 */


//Daemon that handles Combat related stuff
//Currently handling checks for shieldmiss/concealing amorpha
//damage modifications from body.c - including stoneskin checks, typed damage modifications, etc.
//my intention was to make all of this easier to modify on the fly - Saide
#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <damage_types.h>
#include <security.h>

#define PO previous_object()
#define DAMAGE_TRACKER_OBJECT "/realms/saide/damage_tracking_saide"
#define BAD_LIMBS ({"torso","neck","waist","lower torso","tail"})
#define TEMP_HIT_BONUS "/realms/ares/temporary_hit.c"  // remove this when done
#define DEATHS_DOOR_MESSAGE "You are at %^BOLD%^Death's door%^RESET%^. Your body is slipping from you."
#define PK_OB "/d/shadowgate/pkill_tracker"

mapping DAMAGE_TRACKING;

//***** FUNCTIONS DEFINED IN THIS FILE *****//

void save_damage_tracker();
void restore_damage_tracker();
varargs int extra_hit_calcs(object attacker, object victim, object weapon, string limb);
void track_damage(object attacker, object victim, int damage);
varargs int damage_adjustment(object attacker, object victim, int damage);
varargs int typed_damage_modification(object attacker, object targ, string limb, int damage, string type);
void check_extra_abilities(object attacker, object target, object weapon, int crit_hit);
varargs void calculate_damage(object attacker, object targ, object weapon, string target_thing, int critical_hit);
int damage_done(object attacker, object weap, int damage, int isranged);
varargs int get_damage(object attacker, object weap, object targ);
varargs int get_lrdamage(object attacker, object weap, object targ);
int get_hand_damage(object attacker, string limb1, int damage, object attacked);
void send_messages(object attacker, int magic, object weapon, string what, int x, object victim, int fired, string ammo, int critical_message);
void new_struck(int damage, object weapon, object attacker, string limb, object victim, int fired, string ammo, int critical_hit);
void do_fumble(object attacker, object weapon);
void miss(object attacker, int magic, object target, string type, string target_thing);
int calculate_unarmed_damage(object attacker);


//****** END OF FUNCTION DEFINITIONS ******//
void save_damage_tracker()
{
    seteuid(UID_RESTORE);
    save_object(DAMAGE_TRACKER_OBJECT);
    seteuid(geteuid());
}

void restore_damage_tracker()
{
    seteuid(UID_RESTORE);
    restore_object(DAMAGE_TRACKER_OBJECT);
    seteuid(geteuid());
}

//this is called in internal_execute_attack in combat.c
//is also called in feat.c in the thaco() function can be ignored there for touch attack type feats
//can be called anywhere you want to check to see if a person successfully deflects or avoids an attack
//called when the dice roll is not 20 or not a miss - so
//only when attacker hits with a dice roll that is not 20
//I am treating 20s as automatic hits bypassing shields and concealing amorpha - Saide
//a return value of 1 will be processed as a hit
//a return value of 0 is a miss - tell the attacker and the victim - Saide

varargs int extra_hit_calcs(object attacker, object victim, object weapon, string limb)
{
    object env;
    int ShieldMissChance, MissChance, AttackerMissChance;
    if(!objectp(attacker)) return 1;
    if(!objectp(victim)) return 1;
    if(victim->query_paralyzed()) return 1;
    MissChance = (int)victim->query_missChance();
    ShieldMissChance = (int)victim->query_shieldMiss();
    AttackerMissChance = (int)attacker->query_property("noMissChance");
    //attacker has a property set so that they cannot miss - Saide
    if(AttackerMissChance) return 1;
    if(attacker == victim) return 1;
    if(!MissChance && !ShieldMissChance) return 1;
    if(attacker->is_spell()) return 1;

    env = environment(attacker);

    if(!ShieldMissChance || MissChance > ShieldMissChance)
    {
        if(MissChance > roll_dice(1,100))
        {
            tell_object(victim, attacker->QCN+"%^BOLD%^%^WHITE%^ cannot see you and misses!");
            tell_object(attacker, "%^BOLD%^%^WHITE%^You cannot see "+victim->QCN+" and miss "+victim->QO+"!");
            attacker->delete("featMiss");
            attacker->set("featMiss", victim->QCN+" avoided your");
            if(objectp(env)) tell_room(env, attacker->QCN+"%^BOLD%^%^WHITE%^ misses "+victim->QCN+"!%^RESET%^", ({victim, attacker}));
            return 0;
        }
        return 1;
    }
    else
    {
        if(victim->query_property("shapeshifted")) return 1;
        if(ShieldMissChance > roll_dice(1,100))
        {
            if(living(attacker))
            {
                tell_object(attacker,"%^RESET%^%^BOLD%^Your attack is deflected off of "+victim->QCN+"'s "
                "shield!%^RESET%^");
                attacker->delete("featMiss");
                attacker->set("featMiss", victim->QCN+" deflected your");
                tell_object(victim,"%^RESET%^%^BOLD%^You deflect "+attacker->QCN+"'s attack with your "
                "shield!%^RESET%^");

                if(objectp(env))
                {
                    tell_room(env,"%^RESET%^%^BOLD%^"+victim->QCN+" deflects "+attacker->QCN+"'s attack with "
                    ""+victim->QP+" shield!%^RESET%^",({attacker, victim}));
                }
                if(FEATS_D->usable_feat(victim,"counter")) if(random(4)) { victim->counter_attack(victim); }
                return 0;
            }
            else
            {
                tell_object(victim,"%^RESET%^%^BOLD%^You deflect the attack with your shield!%^RESET%^");
                if(objectp(env))
                {
                    tell_room(env,"%^RESET%^%^BOLD%^"+victim->QCN+" deflects the attack with "+victim->QP+" shield!%^RESET%^",({victim}));
                }
                if(FEATS_D->usable_feat(victim,"counter")) if(random(4)) { victim->counter_attack(victim); }
                return 0;
            }
        }
        return 1;
    }
    return 1;
}


//let us track damage - we can keep up with each time this function
//is called on a player - and then divide the overall amount / number
//of attacks to estimate an average and then go from there - Saide - September 2016

void track_damage(object attacker, object victim, int damage)
{
    string *being_tracked, tname;
    int myhits = 0, myignore = 0, isuser = 0, mylev = 0, maxdamage = 0;
    int mindamage = 0, avgdamage = 0;
    return;
    if(damage > 0) myhits = 1;
    else myignore = 1;
    if(!objectp(attacker)) return;
    //if(!objectp(victim)) return;
    if(!mapp(DAMAGE_TRACKING)) restore_damage_tracker();
    if(!mapp(DAMAGE_TRACKING)) DAMAGE_TRACKING = ([]);
    being_tracked = keys(DAMAGE_TRACKING);
    if(userp(attacker)) isuser = 1;
    mylev = attacker->query_level();
    tname = attacker->query_name() + " @ level "+mylev;
    if(!sizeof(being_tracked))
    {
        DAMAGE_TRACKING = ([tname : (["damage" : damage, "hits" : myhits, "ignored" : myignore, "user" : isuser, "max damage" : damage, "min damage" :
damage, "average damage" : damage]) ]);
        save_damage_tracker();
        return;
    }
    else
    {
        if(member_array(tname, being_tracked) == -1)
        {
            DAMAGE_TRACKING += ([tname : (["damage" : damage, "hits" : myhits, "ignored" : myignore, "user" : isuser, "max damage" : damage, "min
damage" : damage, "average damage" : damage]) ]);
        }
        else
        {
            DAMAGE_TRACKING[tname]["damage"] += damage;
            DAMAGE_TRACKING[tname]["hits"] += myhits;
            DAMAGE_TRACKING[tname]["ignored"] += myignore;
            maxdamage = DAMAGE_TRACKING[tname]["max damage"];
            mindamage = DAMAGE_TRACKING[tname]["min damage"];
            if(damage < mindamage) DAMAGE_TRACKING[tname]["min damage"] = damage;
            if(damage > maxdamage) DAMAGE_TRACKING[tname]["max damage"] = damage;
            if(DAMAGE_TRACKING[tname]["hits"] > 0) avgdamage = DAMAGE_TRACKING[tname]["damage"] / DAMAGE_TRACKING[tname]["hits"];
            DAMAGE_TRACKING[tname]["average damage"] = avgdamage;
        }
    }
    save_damage_tracker();
    return;
}


//moved a bunch of code from the do_damage function here - Saide

varargs int damage_adjustment(object attacker, object victim, int damage)
{
    int mod, num, layers;
    object env, myspl;
    mapping logdata;
    if(!objectp(attacker)) return damage;
    if(!objectp(victim)) return damage;
    if(!intp(damage)) return damage;
    env = environment(attacker);

     //adding some damage mitigation after discussion with Octothorpe
    //should be 2 per 5 levels above 20 only counting melee
    //type levels only
    //with current DR feats this would equal 13 points of DR at level 40
    //only having it kick in in the event of damage being >= 10 - Saide
    //tell_object(find_player("saide"), "Damage against "+identify(victim)+ " from "+identify(attacker)+" = "+damage +" in damage_adjustment");
    if(interactive(victim) && damage >= 10 && (int)victim->query_level() >= 20)
    {
        mod = 0;
        if((int)victim->query_class_level("fighter") ) mod += (int)victim->query_class_level("fighter");
        if((int)victim->query_class_level("thief")) mod += (int)victim->query_class_level("thief");
        if((int)victim->query_class_level("antipaladin")) mod += (int)victim->query_class_level("antipaladin");
        if((int)victim->query_class_level("paladin")) mod += (int)victim->query_class_level("paladin");
        if((int)victim->query_class_level("cavalier")) mod += (int)victim->query_class_level("cavalier");
        if((int)victim->query_class_level("ranger")) mod += (int)victim->query_class_level("ranger");
        if((int)victim->query_class_level("barbarian")) mod += (int)victim->query_class_level("barbarian");
        if((int)victim->query_class_level("monk")) mod += (int)victim->query_class_level("monk");
        mod = ((mod - 20)/ 5) * 2;
        if(mod > 0) damage -= mod;
        if(damage < 0)
        {
            damage = 0;
            //track_damage(attacker, victim, damage);
            return damage;
        }
    }

    // adding a damage resistance property which will directly
   // reduce the damage by the amount.  We can probably do away
   // with this when the types and resistances go into place -Ares

    // adding in check for new feat 21+ thief/monk to reduce mass-damage blows. N, 4/13.
    if(FEATS_D->usable_feat(victim,"defensive roll"))
    {
        num = (int)victim->query_max_hp() / 4;
        if(damage > num) { // kicks in for any blow greater than 25% of hp.

            num = ((int)victim->query_level()/2) + 18; // DC to be roughly 50% success for SC without feats/etc
            logdata = "/daemon/saving_throw_d.c"->debug_reflex_save(victim,((-1)*num)); // logging success rate

            if(logdata["save_result"])
            {
                if(userp(victim)) log_file("defensiveroll", "Player "+(string)victim->query_name()+" %^BOLD%^%^RED%^passed"
                    "%^RESET%^. Character level was "+(int)victim->query_level()+", DC was "+num+", varied by "+logdata["final_roll"]+".\n");
                damage = damage /2;
                if(damage < 0) damage = 0;
                if(living(attacker))
                {
                    tell_object(attacker, victim->QCN+"%^RESET%^%^BOLD%^ rolls with your attack, lessening its force!%^RESET%^");
                    if(objectp(env)) tell_room(env, victim->QCN+"%^RESET%^%^BOLD%^ rolls with "+attacker->QCN+"%^RESET%^%^BOLD%^'s
attack, lessing its force!%^RESET%^");
                }
                tell_object(victim, "%^RESET%^%^BOLD%^You roll with the attack, lessening its force!%^RESET%^");
                if(damage <= 0)
                {
                    //track_damage(attacker, victim, damage);
                    return damage;
                }
            }
            else
            {
                if(userp(victim)) log_file("defensiveroll", "Player "+(string)victim->query_name()+" %^BOLD%^%^RED%^failed"
                    "%^RESET%^. Character level was "+(int)victim->query_level()+", DC was "+num+", varied by "+logdata["final_roll"]+".\n");
            }
        }
    }


    layers = (int)victim->query_stoneSkinned();
    if(!layers)
    {
        //track_damage(attacker, victim, damage);
        return damage;
    }

    //added && damage >-1 to stop bug with not regenerating HP while
    //unconscious and stoneskinned.  Circe 2/6/04
    if(layers && damage > -1)
    {
        if(!victim->query_magic_attack() && !victim->query_spell_attack() && !attacker->query_property("magic")&& !attacker->is_spell() &&
        ( objectp(attacker->query_current_weapon()) && !(attacker->query_current_weapon())->query_property("magic") ) )
        {
            if(damage > 0) {
/*                layers = stoneSkinned;
                if(layers < 10) { layers = 10; } */
                layers = 10; // stoneskin is supposed to knock down 10DR at all times, now that we have greater equivs (eg/ iron body). N, 11/15.

                if((int)victim->query_stoneSkinned() > 0) {
                    damage = damage - layers;
                }
                layers = (int)victim->query_stoneSkinned();
                layers -= layers>0?1:-1; // let's remove the stoneskin layer AFTER it checks if we had one to get the DR!
                victim->set_stoneSkinned(layers);
                if(damage < 0) { damage = 0; }
            }
        }

        if(!layers && victim->query_property("spelled"))
        {
            while(objectp(myspl = MAGIC_D->get_spell_from_array(victim->query_property("spelled"), "stoneskin")))
            {
                victim->remove_property_value("spelled", ({myspl}));
                myspl->dest_effect();
            }
        }
    }
    //track_damage(attacker, victim, damage);
    return damage;
}

varargs int typed_damage_modification(object attacker, object targ, string limb, int damage, string type)
{
    object myEB;
    int resist_perc,resist, reduction, mod, amt;
    float percentage;
    if(!objectp(targ)) { return 0; }
    if(!stringp(limb)) { limb = targ->return_target_limb(); }
    if(!damage) { return 0; }
    targ->set_magic_attack(0);
    targ->spell_attack(0);
    limb = targ->adjust_targeted_limb(attacker, limb);
    damage = targ->do_typed_damage_effects(attacker,limb,damage,type);
    if(!targ->initialized_resistances()) { targ->init_limb_data(); }

    if(!stringp(type) || !targ->valid_resistance(type))
    {
        if(objectp(attacker)) { log_file("invalid_damage_types",""+ctime(time())+" "+base_name(attacker)+" tried to use an invalid damage type:
"+type+"\n"); }
        return damage;
    }

    if(objectp(targ) && FEATS_D->usable_feat(targ,"kinetic conversion"))
    {
        switch(type)
        {
            case "bludgeoning":
            case "piercing":
            case "slashing":
            case "silver":
            case "cold iron":
            case "force":

                amt = damage / 4; // might need to adjust this
                if(amt > 3) { amt = 3; }
                if(amt < 1) { amt = 1; }
                targ->add_mp(amt);
                break;

            default:
                break;
        }
    }

    if(objectp(targ) && FEATS_D->usable_feat(targ,"way of the learned pupil")){
        USER_D->regenerate_ki(targ,1);
    }

    resist_perc = (int)targ->query_resistance_percent(type);
    resist = (int)targ->query_resistance(type);

    if(resist_perc > 500) { resist_perc = 500; }
    if(resist_perc < -500) { resist_perc = -500; }

    switch(resist_perc)
    {
    case (-500)..(-1): // resistance less than 0 equals more damage done
        percentage = to_float( (100 + absolute_value(resist_perc)) / to_float(100) );
        break;

    case 0..100: // resistance between 0 and 100 equals reduced damage
        percentage = to_float( (100 - resist_perc)/ to_float(100) );
        break;

    case 101..500: // resistance greater than 100 equals healing
        percentage = to_float( (100 - resist_perc) / to_float(100) );
        break;
    }

    damage = to_int(damage * percentage);

    if(damage > 0)
    {
        damage = damage - resist;
        if(damage < 0) { damage = 0; }
    }

    if(type == "negative energy")
    {
        if(targ->is_undead() ||
           targ->query_property("heart of darkness") ||
           targ->query("subrace")=="dhampir")
            damage = -abs(damage);
        else
            damage = abs(damage);
    }

    if(type == "positive energy")
    {
        if(targ->is_undead() ||
           targ->query("subrace")=="dhampir")
            damage = abs(damage);
        else
            damage = -abs(damage);
    }

    if(damage > 0 && type != "force" && objectp(myEB = targ->query_property("empty body")))
    {
        return 0;
    }

    if(targ->query_verbose_combat())
    {
        if(damage > 0) { tell_object(targ,"You take "+type+" damage."); }
        if(damage < 0) { tell_object(targ,"You are healed by "+type+" damage."); }
    }


    if(objectp(attacker))
    {
        if(attacker->query_property("noMissChance") || attacker->query_property("magic") || ( objectp(attacker->query_current_weapon()) &&
(attacker->query_current_weapon())->query_property("magic")))
        {
            targ->set_magic_attack(1);
        }

        if(PO->is_spell())
        {
            targ->set_spell_attack(1);
        }
    }

    //basically I am modifying the "damage resistance" property to
    //work ONLY for physical type attacks - anything that causes
    //some type of physical damage - spell damage resistance will work
    //on anything that causes any other type of damage - Saide, June, 2017
    if((int)targ->query_property("damage resistance") && member_array(type, PHYSICAL_DAMAGE_TYPES) != -1)
    {
        if(damage > 0)
        {
            reduction = (int)targ->query_property("damage resistance");
            //basically 1 point in the set_property("magic") ignores 10 points of damage resistance - Saide
            if(attacker->query_property("magic"))
            {
                mod = (int)attacker->query_property("magic") * 10;
            }
            else if( objectp(attacker->query_current_weapon()) && (attacker->query_current_weapon())->query_property("magic"))
            {
                mod = (int)attacker->query_current_weapon()->query_property("magic") * 10;
            }
            reduction -= mod;
            if(reduction < 0) reduction = 0;
            damage -= reduction;
            if(damage < 0)
            {
                damage = 0;
                return damage;
            }
        }
    }

    if((int)targ->query_property("spell damage resistance") && member_array(type, (VALID_DAMAGE_TYPES - PHYSICAL_DAMAGE_TYPES)) != -1)
    {
        if(damage > 0)
        {
            reduction = (int)targ->query_property("spell damage resistance");
            //if we want something to work through this property, it should be set here - Saide
            mod = 0;
            reduction -= mod;
            if(reduction < 0) reduction = 0;
            damage -= reduction;
            if(damage < 0)
            {
                damage = 0;
                return damage;
            }
        }
    }
    return damage;
}

void check_extra_abilities(object attacker, object target, object weapon, int crit_hit)
{
    int effect_chance;
    if(!objectp(attacker)) return;
    if(!objectp(weapon)) return;

    if( FEATS_D->usable_feat(attacker, "shadow master")
        && !attacker->query_property("shapeshifted") && objectp(weapon) && crit_hit) {
        if(!random(3)) {
            tell_object(attacker,"%^BLUE%^You strike "+target->QCN+" with precision as you channel your command of the shadows, and " +target->QS+ " blinks sightlessly!%^RESET%^");
            tell_object(target,"%^BLUE%^As "+attacker->QCN+" strikes you, your vision grows momentarily clouded!%^RESET%^");
            target->set_temporary_blinded(1,"Your vision is clouded!");
        }
    }
    if( FEATS_D->usable_feat(attacker, "spell critical") && crit_hit) {
        tell_object(attacker,"%^CYAN%^You cry a brief warsong and unleash wave of %^YELLOW%^w%^MAGENTA%^i%^WHITE%^l%^RED%^d %^GREEN%^m%^BLUE%^a%^WHITE%^g%^ORANGE%^i%^RED%^c%^RESET%^%^CYAN%^ at "+target->QCN+"!%^RESET%^");
        tell_object(target,"%^CYAN%^"+attacker->QCN+" shouts a brief warsong, and %^YELLOW%^w%^MAGENTA%^i%^WHITE%^l%^RED%^d %^GREEN%^m%^BLUE%^a%^WHITE%^g%^ORANGE%^i%^RED%^c%^RESET%^%^CYAN%^ burns through you!%^RESET%^");
        tell_room(environment(attacker),"%^CYAN%^"+attacker->QCN+" shouts a brief warsong and unleashes wave of %^YELLOW%^w%^MAGENTA%^i%^WHITE%^l%^RED%^d %^GREEN%^m%^BLUE%^a%^WHITE%^g%^ORANGE%^i%^RED%^c%^RESET%^%^CYAN%^ at "+target->QCN+"!%^RESET%^",({target,attacker}));
        target->do_damage(target->return_target_limb(),roll_dice(1,8));
    }
    if(weapon->is_lrweapon() &&
       FEATS_D->usable_feat(attacker, "arcane arrows") &&
       crit_hit)
    {
        string element;
        element=attacker->query_property("arcane arrows");
        switch(element)
        {
        case "acid":
            tell_room(environment(target),"%^GREEN%^The projectile explodes with ooze of acid all over "+target->QCN+"%^RESET%^",({target}));
            tell_object(target,"%^GREEN%^The missile explodes with ooze of acid all over you%^RESET%^");                  break;
        case "cold":
            tell_room(environment(target),"%^BLUE%^The projectile explodes with sharp shards of ice that pierce "+target->QCN+"%^RESET%^",({target}));
            tell_object(target,"%^GREEN%^The missile explodes with ooze of acid all over you%^RESET%^");
            break;
        case "sonic":
            tell_room(environment(target),"%^CYAN%^The projectile explodes sonic scream that shatters "+target->QCN+"%^RESET%^",({target}));
            tell_object(target,"%^GREEN%^The missile explodes with sonic scream that shatters you%^RESET%^");             break;
        default:
            tell_room(environment(target),"%^RED%^The projectile explodes and scorches "+target->QCN+"%^RESET%^",({target}));
            tell_object(target,"%^GREEN%^The missile explodes and burns you!%^RESET%^");
            break;
        }
        target->cause_typed_damage(target,target->return_target_limb(),roll_dice(attacker->query_character_level(),8),element);
    }
    if(objectp(weapon) && !attacker->query_property("shapeshifted"))
    {
        if(objectp(target) && (int)weapon->query("PoisonDoses"))
        {
            POISON_D->is_object_poisoned(weapon, target, "hit", 1);
        }
    }
    else if(attacker->query_property("natural poisoner"))
    {
        effect_chance = attacker->query_property("poison chance");
        if(!intp(effect_chance)) effect_chance = 10;
        if(effect_chance > roll_dice(1,100))
        {
            POISON_D->ApplyPoison(target, attacker->query_property("natural poison"), attacker, "injury");
        }
    }
    //monster feat stuff
    if(attacker->query("combat_feats_enabled") && !attacker->query_property("using instant feat"))
    {
        effect_chance = attacker->query_property("feat chance");
        if(!intp(effect_chance)) effect_chance = 15;
        if(effect_chance > roll_dice(1, 100))
        {
            MONSTER_FEAT_D->execute_monster_feat(attacker, attacker->return_player_target(100));
        }
    }
    //disease stuff
    if(attacker->query_property("infects disease"))
    {
        effect_chance = (int)attacker->query("disease chance");
        if(!intp(effect_chance)) effect_chance = 10;
        if(effect_chance > roll_dice(1, 100))
        {
            "/daemon/disease_d.c"->infect_with_disease(attacker, target, random(2));
        }
    }
    else if(objectp(weapon) && !attacker->query_property("shapeshifted"))
    {
        if(objectp(target) && weapon->query_property("infects disease"))
        {
            "/daemon/disease_d.c"->infect_with_disease(weapon, target, 0);
        }
    }
    return;
}

//all melee damage calculations should be here now
//condensing the do_hits() function from /std/living/combat.c
//and the damage_done() function

int crit_damage(object attacker, object targ, object weapon, int size, int damage)
{
    int mult, crit_dam, perc;
    string targRace;
    object *wielded;
    if(damage <= 0) return 0;
    if(objectp(weapon) && !attacker->query_property("shapeshifted") && weapon != attacker)
    {
        mult = (int)weapon->query_critical_hit_multiplier();

        if(FEATS_D->usable_feat(attacker,"skull collector") && attacker->is_wielding("two handed"))
        {
            if(objectp(targ))
            {
                perc = 25 + roll_dice(1,25);
                if( (targ->query_hp_percent() < perc) && (targ->query_hp_percent() > 0) )
                {
                    if(!FEATS_D->usable_feat(targ,"death ward") && !targ->query_property("no death"))
                    {
                        if(!targ->fort_save(attacker->query_highest_level()))
                        {
                            tell_object(targ,"%^BOLD%^%^RED%^"+attacker->QCN+" swings "+attacker->QP+" "+weapon->query_short()+" in a brutal
swipe, hitting you in the head!\nEverything goes black...");
                            tell_object(attacker,"%^BOLD%^%^RED%^You swing your "+weapon->query_short()+" in a brutal swipe, hitting
"+targ->QCN+" in the head with a certainly fatal strike!");
                            tell_room(environment(targ),"%^BOLD%^%^RED%^"+attacker->QCN+" swings "+attacker->QP+" "+weapon->query_short()+" in
a brutal swipe, hitting "+targ->QCN+" in the head "
                                "with what must cetainly be a fatal strike!",({attacker,targ}));
                            targ->set_hp(-100);
                        }
                    }
                }
            }
        }

    }
    else
    {
        mult = 2; // currently all unarmed attacks have x2 multiplier
        if(attacker->is_class("monk"))
        {
            mult += (int)"/std/class/monk.c"->critical_multiplier(attacker);

            if(FEATS_D->usable_feat(attacker,"way of the merciful soul"))
            {
                if(objectp(targ))
                {
                    if(targ->query_hp_percent() < 26 && targ->query_hp_percent() > 0)
                    {
                        if(!FEATS_D->usable_feat(targ,"death ward") && !targ->query_property("no death"))
                        {
                            if(!targ->fort_save(attacker->query_prestige_level("monk")) && USER_D->can_spend_ki(attacker, 3))
                            {
                                tell_object(targ,"%^BOLD%^%^BLUE%^"+attacker->QCN+" strikes you swiftly on the forehead and everthing goes
black!%^RESET%^");
                                tell_object(attacker,"%^BOLD%^%^BLUE%^You strike "+targ->QCN+" precisely on the forehead and release pure ki
into "+targ->QP+" mind, "
                                    "granting "+targ->QO+" the mercy of a painless death.");
                                tell_room(environment(targ),""+attacker->QCN+" strikes "+targ->QCN+" swiftly on the head and "+targ->QS+" drops
instantly to the "
                                    "ground!",({attacker, targ}));
                                USER_D->spend_ki(attacker, 3);
                                targ->set_hp(-100);
                            }
                        }
                    }
                }
            }
        }
    }
    if((int)"/daemon/config_d.c"->check_config("critical damage") == 0)
    {
        if(objectp(targ))
        {
            //races that are more/less vulnerable to critical hits - Saide, November 2016
            targRace = (string)targ->query_race();
            if(CRIT_DAMAGE_MODIFIER[targRace])
            {
                mult = mult * CRIT_DAMAGE_MODIFIER[targRace];
                if(mult < 1) mult = 1;
            }
        }
        return (damage * mult);
    }
    else if((int)"/daemon/config_d.c"->check_config("critical damage") == 1)
    {
        mult -= 1;
        if(FEATS_D->usable_feat(attacker, "lethal strikes") && !attacker->query_property("shapeshifted"))
        {
            wielded = (object *)attacker->query_wielded();
            if(sizeof(wielded) >= 2)
            {
                if(wielded[0] != wielded[1]) mult += 1;
                if((int)wielded[0]->query_size() == 1 && (int)wielded[1]->query_size() == 1) mult += 1;
            }
            else if(sizeof(wielded) == 1)
            {
                mult += 1;
                if((int)wielded[0]->query_size() == 1) mult += 1;
            }
        }
        crit_dam = 0;
        while(mult > 0)
        {
            mult--;
            if(objectp(weapon) && !attacker->query_property("shapeshifted") && weapon != attacker)
            {
                if(size < 3)            { crit_dam += weapon->query_wc(); }
                else                    { crit_dam += weapon->query_large_wc(); }
                continue;
            }
            else
            {
                //unarmed crit damage
                if(attacker->is_class("monk"))
                {
                    crit_dam += (int)"/std/class/monk.c"->critical_damage(attacker);
                    continue;
                }
                crit_dam += roll_dice(1, 4);
                continue;
            }
        }
        if(objectp(targ))
        {
            targRace = (string)targ->query_race();
            if(CRIT_DAMAGE_MODIFIER[targRace])
            {
                crit_dam = crit_dam * CRIT_DAMAGE_MODIFIER[targRace];
            }
        }
        return (damage + crit_dam);
    }
    return damage;
}

int unarmed_enchantment(object who)
{
    int mod = 0;
    if(!objectp(who)) return mod;
    if(who->is_class("monk")) mod += (int)"/std/class/monk.c"->effective_enchantment(who);
    else if(FEATS_D->usable_feat(who, "precise strikes")) { mod += ((int)who->query_base_character_level() / 8); }
    return mod;
}


varargs void calculate_damage(object attacker, object targ, object weapon, string target_thing, int critical_hit)
{
    int attacker_size, damage, mod;
    int res, eff_ench, ench;
    int i, j, mysize;
    int speed, enchantment, fired = 0;// added for new stamina formula -Ares
    object *armor,shape,ammo;
    string ammoname;

    if(!objectp(attacker)) { return; }
    if(!objectp(targ)) { return; }
    attacker_size = (int)targ->query_size();
    if(objectp(weapon) && weapon != attacker && !attacker->query_property("shapeshifted"))
    {
        if(attacker_size < 3)   { damage = (int)weapon->query_wc(); }
        else                    { damage = (int)weapon->query_large_wc(); }
        if(weapon->is_lrweapon())
        {
            ammoname = weapon->query_ammo();
            ammo = present(ammoname,attacker);
            if(FEATS_D->usable_feat(attacker,"point blank shot") && objectp(ammo) && ammo->use_shots()) { fired = 1; }
            if(fired)
            {
                damage += get_lrdamage(attacker, weapon, targ);
                if(FEATS_D->usable_feat(attacker,"deadeye")) { damage += BONUS_D->damage_bonus(attacker->query_stats("dexterity")); }
            }
        }
        else
        {
            damage += get_damage(attacker, weapon, targ);
            mysize = (int)attacker->query_size();
            if(mysize == 1) mysize++; //run small creatures as normal size please.
            mysize -= (int)weapon->query_size();
            if(FEATS_D->usable_feat(attacker,"weapon finesse") && (mysize >= 0)) // if has-feat & weapon is smaller than / same size as user - Saide, November 23rd, 2017
            {
                damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("dexterity"));
            }
            else
            {
                damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("strength"));
            }
        }
        if(!targ->query_unconscious() && !targ->query_bound())
        {
            enchantment = (int)weapon->query_property("enchantment");
            if(enchantment) { damage += enchantment; }
        }
    }
    else if(!weapon || weapon == attacker || attacker->query_property("shapeshifted"))
    {
        if(attacker->query_unarmed_damage())
        {
            damage = get_hand_damage(attacker, (string)attacker->return_target_limb(), damage, targ);
            if(targ->query_unconscious() || targ->query_bound()) { damage = damage*2; }
        }
        else
        {
            if(targ->query_unconscious() || targ->query_bound()) { damage = 4; }
            else damage = random(4);
        }
        if(FEATS_D->usable_feat(attacker,"weapon finesse"))
            damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("dexterity"));
        else damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("strength"));
        damage += COMBAT_D->unarmed_enchantment(attacker);
    }
    damage = damage_done(attacker, weapon, damage, fired);
    if(!objectp(targ))
        return;
    if(!objectp(attacker))
        return;

    if(res = targ->query_property("weapon resistance") > 0)
    {
        if(!weapon || weapon == attacker)
        {
            eff_ench = (int)attacker->query_property("effective_enchantment");
            eff_ench += COMBAT_D->unarmed_enchantment(attacker);
            if(eff_ench < res) damage = 0; // no need for these to stack, greatest is sufficient to override.
        }
        else
        {
            ench = (int)weapon->query_property("enchantment");
            eff_ench = (int)weapon->query_property("effective_enchantment");
            if(( ench + eff_ench ) < res) damage = 0;
        }
    }
    if(objectp(weapon) && !attacker->query_property("shapeshifted")) { weapon->reaction_to_hit(targ,damage); }

    armor = targ->query_armour(target_thing);
    j = sizeof(armor);
    for (i=0;i<j;i++)
    {
        if(targ->query_property("shapeshifted")) { continue; }
        if (!objectp(armor[i])) continue;
        mod = armor[i]->do_struck(damage,weapon,attacker);
        if(mod <= 0) damage += mod;
        if(mod > 0) damage = mod;
    }

    if(critical_hit)
    {
        damage = crit_damage(attacker, targ, weapon, attacker_size, damage);
    }
    new_struck(damage,weapon, attacker, target_thing, targ, fired, ammoname, critical_hit);

    if (!objectp(weapon) || attacker->query_property("shapeshifted")) { attacker->increment_stamina(1); }
    else
    {
        speed       = (int)weapon->query_weapon_speed();
        enchantment = (int)weapon->query_property("enchantment");

        i = speed - enchantment;

        if(i<1) { i = 1; }
        if(i>5) { i = 5; }
        attacker->increment_stamina(i);
    }
    check_extra_abilities(attacker, targ, weapon, critical_hit);

    if(fired) { // add the flag here for shot on the run, affects only rounds where an attack has hit
        if(FEATS_D->usable_feat(attacker,"shot on the run") && !attacker->query_property("shotontherun"))
            attacker->set_property("shotontherun",1);
    }

    // added only 1/3 chance to decay weapon on hit; weapons degrade super fast. N, 4/13.
    if((damage > 0) && (weapon && !attacker->query_property("shapeshifted")) && !random(3)) { weapon->decay(); }
    return;
}

int damage_done(object attacker, object weap, int damage, int isranged)
{
    object *wielded;
    int prof;

    if(!objectp(attacker)) { return damage; }
    if(!userp(attacker)) { return damage; }
    if(!objectp(weap)) { return damage; }
    if(!weap->query_prof_type()) { return damage; }
    switch(weap->query_weapon_prof())
    {
        case "simple":  if(FEATS_D->usable_feat(attacker,"simple weapon proficiency"))  prof = 100; break;
        case "martial": if(FEATS_D->usable_feat(attacker,"martial weapon proficiency")) prof = 100; break;
        case "exotic":  if(FEATS_D->usable_feat(attacker,"exotic weapon proficiency"))  prof = 100; break;
        default: prof = 30; break;
    }

    if(avatarp(attacker)) { prof = 100; }

    if(pointerp(wielded=(object *)attacker->query_wielded()) && !attacker->query_property("shapeshifted"))
    {
        if(isranged)
        {
            if(FEATS_D->usable_feat(attacker,"deadeye"))
            {
                prof = to_int(prof*1.50);
            }
        }
        else if(sizeof(wielded) == 2)
        {
            if(objectp(wielded[0]) && objectp(wielded[1]))
            {
                if(wielded[0] == wielded[1] && FEATS_D->usable_feat(attacker,"strength of arm"))
                {
                    prof = to_int(prof*1.50);
                }
            }
        }
        else if(sizeof(wielded) == 1)
        {
            if(objectp(wielded[0]))
            {
                if((int)attacker->query_shieldMiss() && FEATS_D->usable_feat(attacker, "counter"))
                {
                    prof = to_int(prof * (1.25 + ((int)attacker->query_property("shieldwall") *0.10)));
                }
                if(FEATS_D->usable_feat(attacker, "opportunity strikes"))
                {
                    prof = to_int(prof*1.75);
                }
            }
        }
    }
    prof += (random(30) - random(30));

    if(prof == 0) { return 0; }
    if(prof < 0)
    {
        damage = absolute_value((damage*prof)/100 + 1);
        attacker->do_damage("torso",damage);
        tell_object(attacker,"You hurt yourself with your weapon because of your inexperience.");
        tell_room(environment(attacker),attacker->QCN+" hurts "+attacker->QO+"self with "+attacker->QP+" weapon.",attacker);
        return 0;
    }
    else
    {
        damage = (damage*prof)/100;
        return damage;
    }

}

/*The following two functions were moved from combat.c - in order to
attempt to have everything related to damage calculations in combat_d.c - Saide - September 2016
*/
varargs int get_damage(object attacker, object weap, object targ)
{
    function f;
    string hold;
    int damage;
    if(!objectp(weap)) return damage;
    if(!(hold = weap->query_hit()) || WORLD_EVENTS_D->stacking_bonus_active(attacker, -1)) { return damage; }
    if(!objectp(attacker)) return damage;
    if(!weap->query_property("fhit")) { message("my_action", hold, attacker); }
    else
    {
        if(!objectp(targ)) targ = (object)attacker->query_current_attacker();
        damage += call_other(weap, hold, targ);
    }
    return damage;
}

varargs int get_lrdamage(object attacker, object weap, object targ)
{
    function f;
    string hold;
    int damage;
    if(!objectp(weap)) return damage;
    if(!(hold = weap->query_lrhit()) || WORLD_EVENTS_D->stacking_bonus_active(attacker, -1)) { return damage; }
    if(!objectp(attacker)) return damage;
    if(!weap->query_property("flrhit")) { message("my_action", hold, attacker); }
    else
    {
        if(!objectp(targ)) targ = (object)attacker->query_current_attacker();
        damage += call_other(weap, hold, targ);
    }
    return damage;
}
//END

//moved here from /std/weaponless_users.c - Saide, September 2016
int get_hand_damage(object attacker, string limb1, int damage, object attacked)
{
    string *attack_limbs = ({});
    mapping attack_funcs = ([]);

    if(!objectp(attacker)) return 0;

    attack_limbs = attacker->return_attack_limbs();
    attack_funcs = attacker->return_attack_funcs();

    if(!stringp(limb1) || (limb1 == "") || (limb1 == " ") || !sizeof(attack_limbs) || member_array(limb1,attack_limbs) == -1)
    {
        if(!sizeof(attack_limbs)) { return (damage + (int)attacker->query_unarmed_damage()); }
        limb1 = attack_limbs[random(sizeof(attack_limbs))];
    }

        if(!attack_funcs || attack_funcs == ([]) || WORLD_EVENTS_D->stacking_bonus_active(attacker, -1))
    {
        return (damage + (int)attacker->query_unarmed_damage());
    }

    if(!attack_funcs[limb1])
    {
        return (damage + (int)attacker->query_unarmed_damage());
    }

    if(stringp(attack_funcs[limb1]))
    {
                tell_room(environment(attacker), attack_funcs[limb1], attacker);
                return (damage + (int)attacker->query_unarmed_damage());
        }

    if(functionp(attack_funcs[limb1]) && attacker->query_property("shapeshifted"))
    {
        damage += (int)attacker->query_unarmed_damage();
        seteuid(UID_SYSTEM);
        damage += call_other((object)attacker->query_property("shapeshifted"), (*attack_funcs[limb1])(1), attacker, attacked );
        seteuid(geteuid());
                return damage;
        }

        if(functionp(attack_funcs[limb1]))
    {
                damage += call_other(attacker, (*attack_funcs[limb1])(1), attacked);
                return damage;
        }
        return (damage + (int)attacker->query_unarmed_damage());
}

void send_messages(object attacker, int magic, object weapon, string what, int x, object victim, int fired, string ammo, int critical_message)
{
    string your_name, my_name, me, you, others, used, type, *verb, *adverb,*attack_limbs, *limbs;
    int i, verbose,num;
    object shape;

    if(!objectp(attacker) || !objectp(victim)) { return; }

    your_name = (string)victim->QCN;
    my_name = (string)attacker->QCN;
    verbose = 0;

    if(interactive(attacker)) { verbose = attacker->query_verbose_combat(); }
    else if(interactive(victim)) { verbose = victim->query_verbose_combat(); }


    if(verbose)
    {
        if(magic)        { type = "magic"; }
        if(fired)        { type = "ranged"; }
        else if(weapon) { type = (string)weapon->query_type(); }
        else             { type = "melee"; }
        if(!type)        { type= "bludgeon"; }

        if(objectp(shape = attacker->query_property("shapeshifted"))) { type = shape->get_new_damage_type(); }

        i = x/2;
        if(i<0) i=0;
        if(i>11) i=11;

        if(magic) { used = "magic"; }
        else if(fired) { used = ammo; }

        else if(weapon && !attacker->query_property("shapeshifted") && weapon != attacker) { used = (string)weapon->query_short(); }

        else
        {
            if(attack_limbs = (string*)attacker->query_attack_limbs())
            {
                used = attack_limbs[random(sizeof(attack_limbs))];
            }
            else
            {
                limbs = (string*)attacker->query_limbs();
                limbs = limbs - BAD_LIMBS;
                if(!sizeof(limbs)) { used = "body"; }
                else
                {
                    if(!used)
                    {
                        used = limbs[random(sizeof(limbs))];
                        if(!used) { used = "body"; }
                    }
                }
            }
        }
        if(x < 1)
        {
            me = "You hit "+your_name+" ineffectively in the "+what+".";
            you = my_name+" hits you ineffectively in the "+what+".";
            others = my_name+" hits "+your_name+" ineffectively in the "+what+".";
        }
        else
        {
            if(used == "head")
            {
                if(x < 5)
                {
                    me = "You bonk "+your_name+" viciously in the head.";
                    you = my_name+" bonks you viciously in the head.";
                    others = my_name+" bonks "+your_name+" viciously in the head.";
                }
                else
                {
                    me = "You headbutt "+your_name+" furiously.";
                    you = my_name+" headbutts you furiously.";
                    others = my_name+" headbutts "+your_name+" furiously.";
                }
            }
            else
            {
                if(type == "blade" || type == "lash" || type == "knife" || type == "slashing" || type == "slash" || type == "thiefslashing" || type == "magicslashing")
                {
                    verb = ({ "tap", "tickle", "sting", "slash", "cut", "slice", "slice", "shear", "strike", "mutilate", "dismember", "maim"});
                    adverb = ({ 0, 0, "sharply", 0, 0, 0, "horribly", "to pieces", "letting blood", 0, 0, "utterly"});
                }
                else if(type == "pierce" || type == "thiefpiercing" || type == "piercing" || type == "arrow" || type == "lance" || type == "polearm" || type == "magepierce"|| type == "magepiercing" || type == "ranged")
                {
                    verb = ({ "tap", "poke", "sting", "pierce", "puncture", "penetrate", "perforate", "shear", "impale", "mutilate", "dismember", "maim"});
                    adverb = ({ 0, 0, "sharply", 0, 0, 0, "sharply", "to pieces", "letting blood", 0, 0, "utterly"});
                }
                else
                {
                    verb = ({ "tap", "hit", "whack", "bash", "strike","strike", "send", "knock", "slam", "blast", "destroy", "maim"});
                    adverb = ({ "innocently", "lightly", "strongly", 0, "badly", 0, "a bone crushing blow", 0,"mercilessly", "powerfully", "utterly", "utterly"});
                }

                me = sprintf("You %s %s%sin the %s with your %s.",verb[i], your_name, (adverb[i] ? " "+adverb[i]+" " : " "), what, used);
                you = sprintf("%s %ss you%sin the %s with %s %s.",my_name, verb[i],(adverb[i] ? " "+adverb[i]+" " : " "), what,(string) attacker->QP, used);
                others = sprintf("%s %ss %s%sin the %s with %s %s.", my_name, verb[i], your_name, (adverb[i] ? " "+adverb[i]+" " : " "), what,(string)attacker->QP, used);
            }


            if(critical_message)
            {
                switch(type)
                {
                case "firearm":
                    me = "Bullet stuff";
                    you = "Bullet stuff";
                    others = "Bullet stuff";
                    break;
                case "blade": case "lash": case "knife": case "slashing": case "slash": case "thiefslashing": case "magicslashing":

                    me = "%^RED%^You land a %^BOLD%^vicious %^RESET%^%^RED%^s%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^blow with %^BOLD%^%^BLACK%^"+used+" %^RESET%^%^RED%^and %^BOLD%^tear %^RESET%^%^RED%^your weapon free of %^BOLD%^%^BLACK%^"+your_name+"%^RESET%^%^RED%^!%^RESET%^";
                    you = "%^BOLD%^%^RED%^"+my_name+" %^RESET%^%^RED%^strikes you with a %^BOLD%^vicious %^RESET%^%^RED%^s%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^blow  with %^BOLD%^%^BLACK%^"+used+" %^RESET%^%^RED%^and tears %^BOLD%^%^BLACK%^"+attacker->QP+" %^RESET%^%^RED%^weapon free from you!%^WHITE%^";
                    others = "%^BOLD%^%^RED%^"+my_name+" %^RESET%^%^RED%^strikes %^BOLD%^"+your_name+" %^RESET%^%^RED%^with a %^BOLD%^vicious %^RESET%^%^RED%^s%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^blow with %^BOLD%^%^BLACK%^"+attacker->QP+" "+used+" and %^RESET%^%^RED%^tears %^BOLD%^%^BLACK%^"+attacker->QP+" %^RESET%^%^RED%^blade free from %^BOLD%^%^BLACK%^"+your_name+"%^RESET%^%^RED%^!%^WHITE%^";
                    break;

                case "pierce": case "thiefpiercing": case "piercing": case "arrow": case "lance": case "polearm": case "magepierce": case "magepiercing": case "ranged":
                    me = "%^CYAN%^You p%^BOLD%^%^i%^RESET%^%^CYAN%^erce through %^BOLD%^"+your_name+"'s%^RESET%^%^CYAN%^ defenses and drive your "+used+" into a %^BOLD%^vital%^RESET%^%^CYAN%^ spot!%^RESET%^";
                    you = "%^CYAN%^%^BOLD%^"+my_name+"%^RESET%^%^CYAN%^ pierces through your defences and drives %^BOLD%^"+attacker->QP+" "+used+"%^RESET%^ into a v%^BOLD%^i%^RESET%^%^CYAN%^tal spot!%^RESET%^";
                    others = "%^CYAN%^%^BOLD%^"+my_name+" p%^BOLD%^i%^RESET%^%^CYAN%^erces through %^BOLD%^"+your_name+"'s%^RESET%^ defenses and drives %^BOLD%^"+attacker->QP+" "+used+"%^RESET%^%^CYAN%^ into a v%^BOLD%^i%^RESET%^%^CYAN%^tal spot!%^RESET%^";
                    break;
                default:
                    me = "%^GREEN%^You unleash a %^BOLD%^crushing%^RESET%^%^GREEN%^ blow on %^BOLD%^"+your_name+"%^RESET%^%^GREEN%^ with your %^BOLD%^"+used+"%^RESET%^%^GREEN%^ with %^BOLD%^devastating%^RESET%^%^GREEN%^ force.";
                    you = "%^GREEN%^%^BOLD%^"+my_name+"%^RESET%^%^GREEN%^ staggers you with a %^BOLD%^crushing%^RESET%^%^GREEN%^ blow from "+attacker->QP+" %^BOLD%^"+used+"%^RESET%^%^GREEN%^ with %^BOLD%^devastating%^RESET%^%^GREEN%^ force.";
                    others = "%^GREEN%^%^BOLD%^"+my_name+"%^RESET%^%^GREEN%^ staggers %^BOLD%^"+your_name+"%^RESET%^%^GREEN%^ with a %^BOLD%^crushing%^RESET%^%^GREEN%^ blow from "+attacker->QP+" %^BOLD%^"+used+"%^RESET%^%^GREEN%^ with %^BOLD%^devastating%^RESET%^%^GREEN%^ force.";
                    break;
                }

                if(!objectp(weapon))
                {
                    me = "%^BOLD%^%^BLACK%^You deliver "+your_name+" a %^BOLD%^%^WHITE%^punishing %^BOLD%^%^BLACK%^blow with
your "+used+"!%^RESET%^";

                    you = "%^BOLD%^%^RED%^"+my_name+" %^BOLD%^%^BLACK%^hits you with a %^BOLD%^%^WHITE%^punishing
%^BOLD%^%^BLACK%^blow from "+attacker->QP+" "+used+"!%^RESET%^";

                    others = "%^BOLD%^%^RED%^"+my_name+" %^BOLD%^%^BLACK%^delivers a %^BOLD%^%^WHITE%^punishing
%^BOLD%^%^BLACK%^blow to "
                        "%^BOLD%^%^RED%^"+your_name+" with "+attacker->QP+" "+used+"!%^RESET%^";
                }
            }
        }
    }


    else
    {
        if(x < 1)
        {
            me = "You hit "+your_name+" ineffectively.";
            you = my_name+" hits you ineffectively.";
            others = my_name+" hits "+your_name+" ineffectively.";
        }
        else
        {
            me = "You hit "+your_name+".";
            you = my_name+" hits you.";
            others = my_name+" hits "+your_name+".";
        }
    }


    if(critical_message)
    {
        me = "%^BOLD%^%^RED%^(Critical) %^RESET%^"+me;
        you = "%^BOLD%^%^RED%^(Critical) %^RESET%^"+you;
        others = "%^BOLD%^%^RED%^(Critical) %^RESET%^"+others;
        attacker->reset_critical();
    }

    if(objectp(attacker))
    {
        tell_object(attacker,me);
        if(objectp(environment(attacker))) tell_room(environment(attacker),others,({attacker,victim}));
    }
    if(objectp(victim)) tell_object(victim,you);
}

void new_struck(int damage, object weapon, object attacker, string limb, object victim, int fired, string ammo, int critical_hit)
{
    string damage_type,tmp,type;
    object shape;
    int damage_num,dam;

    // putting this here so it already passes the various checks to make sure the weapon has hit -Ares
    if(!objectp(attacker)) return;
    if(!objectp(victim)) return;
    victim->set_property("beingDamagedBy", attacker);
    if(objectp(weapon) && weapon->query_property("oiled"))
    {
        tmp = (string)weapon->query_property("oiled");
        if(strsrch(tmp,"damage bonus") != -1)
        {
            if(sscanf(tmp,"damage bonus %s %d",type,dam) == 2)
            {
                if(objectp(victim))
                {
                    victim->cause_typed_damage(victim,limb,dam,type);
                }
            }
        }
    }
//temp_oiled can be used by spells and abilities without overriding permanent oils
    if(objectp(weapon) && weapon->query_property("temp_oiled"))
    {
        tmp = (string)weapon->query_property("temp_oiled");
        if(strsrch(tmp,"damage bonus") != -1)
        {
            if(sscanf(tmp,"damage bonus %s %d",type,dam) == 2)
            {
                if(objectp(victim))
                {
                    victim->cause_typed_damage(victim,limb,dam,type);
                }
            }
        }
    }

    if(objectp(weapon) && !attacker->query_property("shapeshifted") && attacker != weapon) { damage_type = (string)weapon->query_damage_type(); }
    else if(objectp(attacker))                                      { damage_type = (string)attacker->query_base_damage_type(); }

    if(!damage_type || damage_type == "untyped")                    { damage_type = "bludgeoning"; }

    if(objectp(shape = attacker->query_property("shapeshifted")))   { damage_type = (string)shape->get_new_damage_type(); }

    if(damage > 0)                                                  { damage_num = (int)victim->cause_typed_damage(victim,limb,damage,damage_type); }
    else                                                            { damage_num = 0; }

    if(objectp(attacker))                                           { send_messages(attacker,0,weapon,limb,damage_num,victim,fired,ammo,critical_hit);
}
    if(objectp(victim))                                             { victim->remove_property("beingDamagedBy"); }
}

void do_fumble(object attacker, object weapon)
{
    int num;
    object *attackers, victim;
    if(!objectp(attacker)) return;
    if(!weapon || !objectp(weapon))
    {
        tell_object(attacker, "You swing wildly at your target!");
        return;
    }

    num = random(20)+1;
    attackers = attacker->query_attackers();
    if(!sizeof(attackers))
    {
        tell_object(attacker, "You swing wildly at your target!");
        return;
    }
    victim = attackers[0];
    switch (num)
    {
    case 1..9:
        break;
    case 10:
        if (!weapon) miss(attacker, (int)attacker->query_casting(), victim, 0, (string)victim->return_target_limb());
        else miss(attacker, 0, victim, (string)weapon->query_type(), (string)victim->return_target_limb());
        break;
    case 11..13:
        break;
    case 14:
        if (objectp(victim))
        {
            calculate_damage(attacker, victim, weapon, (string)victim->return_target_limb());
        }
        break;
    case 17:
        break;
    case 18:
        if(objectp(weapon))
        {
            tell_object(attacker,"%^GREEN%^You fumble your weapon badly, dropping it!");
            tell_room(environment(attacker),"%^GREEN%^You see "+attacker->QCN+" fumble "+attacker->QP+" weapon.",attacker);
            attacker->force_me("drop "+((string *)weapon->query_id())[0]);
        }
        else
        {
            tell_object(attacker,"%^GREEN%^You stumble as you wing at your opponent");
            tell_room(environment(attacker),"%^GREEN%^You see "+attacker->QCN+" stumble.",attacker);
            attacker->set_paralyzed(10,"You are recovering from having stumbled.");
        }
        break;
    case 19:
        break;
    default:
        if(objectp(weapon))
        {
            calculate_damage(attacker, attacker, weapon, (string)attacker->return_target_limb());
        }
        break;
    }
    return;
}

void miss(object attacker, int magic, object target, string type, string target_thing)
{
    int verbose;

    if(!objectp(attacker))  { return; }
    if(!objectp(environment(attacker))) { return; }

    if(magic) { return; }
    if(interactive(attacker)) { verbose = attacker->query_verbose_combat(); }

    if(objectp(target))
    {
        if(interactive(target)) { verbose = target->query_verbose_combat(); }

        if(verbose)
        {
            tell_object(attacker,"%^RESET%^%^YELLOW%^You miss your attack on "+target->QCN+"%^RESET%^");
            tell_room(environment(attacker),""+attacker->QCN+" misses "+attacker->QP+" attack on "+target->QCN+"!",({attacker,target}));
            tell_object(target,""+attacker->QCN+" missed you!");
        }
        else
        {
            tell_object(attacker, "%^YELLOW%^You miss.%^RESET%^");
            tell_object(target,""+attacker->QCN+" missed you.");
            tell_room(environment(attacker),""+attacker->QCN+" misses "+target->QCN+"",({target,attacker}));
        }
        return;
    }

    tell_object(attacker, "%^YELLOW%^You miss.%^RESET%^");
    tell_room(environment(attacker),""+attacker->QCN+" misses "+attacker->QP+" target.",attacker);
    return;
}

int is_ok_armour(object who, string myclass)
{
    int i,j;
    object *armours;
    int isnotok=0;
    if(!objectp(who)) return 0;
    armours = (object *)who->all_armour();
    j = sizeof(armours);
    switch (myclass)
    {
        case "thief":
            for (i=0;i<j;i++)
            {
                if(!objectp(armours[i])) { continue; }
                if (member_array((string)armours[i]->query_type(),({"sheath","leather","bracer","ring","clothing","thiefshield","jewelry"})) == -1 &&  !armours[i]->query_property("magicarmor"))                {
                    isnotok = 1;
                    break;
                }
            }
            break;
        /*Added barb type for barbarian unarmored defense feat - Octothorpe 1/14/16*/
        case "barb": case "barbarian":
            for (i=0;i<j;i++)
            {
                if(!objectp(armours[i])) { continue; }
                if (member_array((string)armours[i]->query_type(),({"sheath","bracer","ring","clothing","thiefshield","shield","jewelry"})) == -1 && !armours[i]->query_property("magicarmor"))
                {
                    isnotok = 1;
                    break;
                }
            }
            break;
        case "mage":
            for (i=0;i<j;i++)
            {
                if(!objectp(armours[i])) { continue; }
                if (member_array((string)armours[i]->query_type(),({"sheath","ring","bracer","clothing","jewelry"})) == -1 && !armours[i]->query_property("magicarmor"))
                {
                    isnotok = 1;
                    break;
                }
            }
            break;
        case "bard":
            for (i=0;i<j;i++)
            {
                if(!objectp(armours[i])) { continue; }
                if (member_array((string)armours[i]->query_type(),({"sheath", "chain", "bracer", "leather", "ring", "clothing", "thiefshield", "jewelry"})) == -1 &&  !armours[i]->query_property("magicarmor"))
                {
                    isnotok = 1;
                    break;
                }
            }
            break;
    }
    if (isnotok) return 0;
    return 1;
}

int is_ok_weapon(object who, string myclass)
{
    object *weapons;
    string type;
    int flag;
    int i;
    if(!objectp(who)) return 0;
    if (myclass == "fighter" || myclass == "paladin" || myclass == "antipaladin" || myclass == "cavalier" || myclass == "ranger" || myclass == "bard")
    {
        return 1;
    }
    weapons = (object *)who->query_wielded();
    for (i=0;i<sizeof(weapons);i++)
    {
        type= weapons[i]->query_type();
        if (myclass=="thief")
        {
            if (member_array(type, ({"magebludgeon","magicslashing","magepiercing","thiefpiercing","lash","thiefslashing"})) == -1)
            {
                return 0;
            }
        }
        else if (myclass == "cleric")
        {
            if (member_array(type, ({"magebludgeon","magicslashing","lash","bludgeon"})) == -1)
            {
                return 0;
            }
        }
        else if (myclass == "mage")
        {
            if (member_array(type, ({"magebludgeon","magicslashing","magepiercing"})) == -1)
            {
                return 0;
            }
        }
        else if (myclass=="psion")
        {
            if (member_array(type, ({"magebludgeon","magicslashing","magepiercing"})) == -1)
            {
                return 0;
            }
        }
    }
    return 1;
}

int calculate_unarmed_damage(object attacker)
{
    int amt;
    if(!objectp(attacker)) return 0;
    if(attacker->is_class("monk") && file_exists("/std/class/monk.c"))
    {
        return (int)"/std/class/monk.c"->unarmed_damage(attacker);
    }
    else if(FEATS_D->usable_feat(attacker, "unarmed combat"))
    {
        switch((int)attacker->query_highest_level())
        {
            case 0..20:
                return roll_dice(1,6);
                break;
            case 21..30:
                return roll_dice(1,8);
                break;
            case 31..50:
                return roll_dice(1,10);
                break;
        }
    }
    return roll_dice(1,4);
}

//Following functions were moved into here from /std/living/combat.c in January 2017 - Saide
void init_combat_vars(object who)
{
    mapping combat_vars;
    int flag;
    if(!objectp(who)) return;
    combat_vars = who->query_combat_vars();
    if(!combat_vars || (combat_vars == ([])) || !combat_vars["RNEW"])
    {
        combat_vars = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "blindfolded" : 0, "any attack" : 0,
        "paralyzed" : 0, "toAttack" : 0, "wimpy" : 0, "any attack" : 0, "react" : 0, "funcCast" : 0, "castFunc" : 0,
        "swarm" : 0, "RNEW" : 1]);
        flag = 1;
    }
    if(flag) who->set_combat_vars(combat_vars);
    return;
}

void init_combat_messages(object who)
{
    mapping combat_messages;
    int flag;
    if(!objectp(who)) return;
    combat_messages = who->query_combat_messages();
    if(!combat_messages || (combat_messages == ([])) || !combat_messages["NEW"])
    {
        combat_messages = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "paralyzed" : 0,
        "blinded" : 0, "blindfolded" : 0, "NEW" : 1]);
        flag = 1;
    }
    if(flag) who->set_combat_messages(combat_messages);
    return;
}

void init_combat_counters(object who)
{
    mapping combat_counters;
    int flag;
    if(!objectp(who)) return;
    combat_counters = who->query_combat_counters();
    if(!combat_counters || (combat_counters == ([])) || !combat_counters["NEW"])
    {
        combat_counters = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "blindfolded" : 0,
        "blinded" : 0, "healing" : 0, "block_attack" : 0, "NEW" : 1]);
        flag = 1;
    }
    if (!intp(combat_counters["gagged"])) { combat_counters["gagged"] = 0; flag = 1; }
    if (!intp(combat_counters["bound"])) { combat_counters["bound"] = 0; flag = 1; }
    if (!intp(combat_counters["tripped"])) { combat_counters["tripped"] = 0; flag = 1; }
    if (!intp(combat_counters["asleep"])) { combat_counters["asleep"] = 0; flag = 1; }
    if (!intp(combat_counters["blindfolded"])) { combat_counters["blindfolded"] = 0; flag = 1; }
    if (!intp(combat_counters["blinded"])) { combat_counters["blinded"] = 0; flag = 1; }
    if (!intp(combat_counters["unconscious"])) { combat_counters["unconscious"] = 0; flag = 1; }
    if (!intp(combat_counters["healing"])) { combat_counters["healing"] = 0; flag = 1; }
    if (!intp(combat_counters["block_attack"])) { combat_counters["block_attack"] = 0; flag = 1; }
    if (!intp(combat_counters["tripped counter"])) { combat_counters["tripped counter"] = 0; flag = 1; }
    if (!intp(combat_counters["paralyzed"])) { combat_counters["paralyzed"] = 0; flag = 1;}
    if(flag) who->set_combat_counters(combat_counters);
}

void init_combat_static_vars(object who)
{
    mapping combat_static_vars;
    int flag;
    if(!objectp(who)) return;
    combat_static_vars = who->query_combat_static_vars();
    if(!combat_static_vars || (combat_static_vars == ([])))
    {
        combat_static_vars = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "blindfolded" : 0,
                               "blinded" : 0, "critical hit" : 0, "attack count" : 0, "attack loop" : 0, "attacking" : 0,
                               "hunting" : 0, "dead" : 0, "funcing" : 0, "attack" : 0, "toattack" : 0, "lastHand" : 0,
                               "critical message" : 0, "casting" : 0]);
        flag = 1;
    }
    if(flag) who->set_combat_static_vars(combat_static_vars);
    return;
}

void init_combat_arrays(object who)
{
    mapping combat_arrays;
    int flag;
    if(!objectp(who)) return;
    combat_arrays = who->query_combat_arrays();
    if(!mapp(combat_arrays) || combat_arrays == ([]))
    {
        combat_arrays = (["attackers" : ({}), "hunters" : ({}), "atnames" : ({}), ]);
        flag = 1;
    }
    if(flag) who->set_combat_arrays(combat_arrays);
    return;
}

int ok_combat_vars(object who)
{
    if(!objectp(who)) return 0;
    init_combat_vars(who);
    init_combat_messages(who);
    init_combat_counters(who);
    init_combat_static_vars(who);
    init_combat_arrays(who);
    return 1;
}

void send_paralyzed_message(string type, object who)
{
    if(!objectp(who)) return;
    if (who->query_deaths_door())
    {
        message(type,DEATHS_DOOR_MESSAGE,who);
        return;
    }
    if (who->query_asleep())
    {
        message(type,who->query_asleep_message(), who);
        return;
    }
    if (who->query_unconscious())
    {
        message(type,who->query_unconscious_message(),who);
        return;
    }
    if (who->query_paralyzed())
    {
        message(type,who->query_combat_mapps("messages", "paralyzed"),who);
        return;
    }
    if (who->query_bound())
    {
        message(type,who->query_bound_message(),who);
        return;
    }
    if (who->query_tripped())
    {
        message(type,who->query_tripped_message(),who);
        return;
    }
}

void iterate_combat(object who)
{
    mapping combat_static_vars, combat_counters, combat_vars, combat_messages;
    object EWHO;
    int vars, counters, static_vars;
    if(!objectp(who)) return;
    EWHO = environment(who);
    //if (!who->ok_combat_vars()) who->initialize_combat_vars(); // there's a recursion error, not sure if it's caused here or not
    who->ok_combat_vars();
    combat_static_vars = who->query_combat_static_vars();
    combat_vars = who->query_combat_vars();
    combat_messages = who->query_combat_messages();
    combat_counters = who->query_combat_counters();

    if (combat_static_vars["blinded"])
    {
        if (combat_counters["blinded"] > 7)
        {
            combat_static_vars["blinded"]--;
            static_vars = 1;
            combat_counters["blinded"] = 0;
            if (!who->query_blind())
            {
                message("combat","%^BOLD%^%^BLUE%^You can see again",who);
            }
        }
        combat_counters["blinded"]++;
        counters = 1;
    }

    if (combat_vars["blindfolded"])
    {
        if (combat_counters["blindfolded"] > (25 - (int)who->query_stats("dexterity")))
        {
            vars = 1;
            combat_vars["blindfolded"]--;
            combat_counters["blindfolded"] = 0;
            if (!who->query_blind())
            {
                message("combat","%^BOLD%^%^BLUE%^You can see again",who);
            }
        }
        combat_counters["blindfolded"]++;
        counters = 1;
    }

    if (combat_vars["gagged"])
    {
        if (combat_counters["gagged"] > (25 - (int)who->query_stats("dexterity")))
        {
            vars = 1;
            combat_vars["gagged"]--;
            combat_counters["gagged"] = 0;
            if (!combat_vars["gagged"])
            {
                message("combat","%^BOLD%^%^BLUE%^You have struggled your gag off..",who);
                if(!who->query_invis() && objectp(environment(who)))
                {
                    tell_room(environment(who), "%^GREEN%^"+who->QCN+" spits out "+who->QP+" gag.%^RESET%^", who);
                }
            }
        }
        combat_counters["gagged"]++;
        counters = 1;
    }

    if (combat_vars["bound"])
    {
        if (combat_counters["bound"] > (25 - (int)who->query_stats("strength")))
        {
            vars = 1;
            combat_vars["bound"]--;
            combat_counters["bound"] = 0;
            if (!combat_vars["bound"])
            {
                message("combat","%^BOLD%^%^BLUE%^You have broken your bonds.",who);
                if(!who->query_invis() && !random(3) && objectp(environment(who)))
                {
                    tell_room(environment(who), "%^GREEN%^"+who->QCN+" breaks free of "+who->QP+" bonds.%^RESET%^", who);
                }
            }
        }
        combat_counters["bound"]++;
        counters = 1;
    }

    if (combat_vars["paralyzed"])
    {
        if(combat_counters["paralyzed"] > (1+random(2)))//-(((int)who->query_stats("dexterity") - 10) / 2)) )
        {
            combat_vars["paralyzed"]--;
            combat_counters["paralyzed"] = 0;
            if(!combat_vars["paralyzed"])
            {
                if(!who->query_tripped() && !who->query_bound() && !who->query_unconscious())
                {
                    message("combat", "%^BOLD%^%^WHITE%^You can move again!", who);
                    if(!who->query_invis() && objectp(environment(who)))
                    {
                        tell_room(environment(who), "%^BOLD%^%^WHITE%^You see "+who->QCN+" moving again.%^RESET%^", who);
                    }
                }
            }
            vars = 1;
        }
        combat_counters["paralyzed"]++;
        counters = 1;
    }

    if (combat_vars["tripped"])
    {
        if(combat_counters["tripped counter"])
        {
            combat_counters["tripped counter"]--;
                    if(combat_counters["tripped counter"] < 1 ) { combat_counters["tripped counter"] = 0; combat_vars["tripped"] = 1;
combat_counters["tripped"] = 100; }
        }
        if (combat_counters["tripped"] > (7+random(5)-(((int)who->query_stats("dexterity") - 10) / 2)  ) )
        {
            combat_vars["tripped"]--;
            vars = 1;
            combat_counters["tripped"] = 0;
            if (!combat_vars["tripped"])
            {
                if(!who->query_paralyzed() && !who->query_bound() && !who->query_unconscious())
                {
                    message("combat","%^BOLD%^%^BLUE%^You have managed to stand again.",who);
                    if(!who->query_invis() && objectp(environment(who)))
                    {
                        tell_room(environment(who), "%^BOLD%^%^GREEN%^You see "+who->QCN+" standing again.%^RESET%^", who);
                    }
                }
            }
        }
        combat_counters["tripped"]++;
        counters = 1;
    }

    if (combat_vars["unconscious"])
    {
        if (sizeof(who->query_attackers()) > 0)
        {
            combat_vars["unconscious"]=0;
            combat_counters["unconscious"] = 0;
            message("combat","%^BOLD%^%^BLUE%^You have regained consciousness.",who);
            if(!who->query_invis() && objectp(environment(who)))
            {
                tell_room(environment(who), "%^GREEN%^You notice "+who->QCN+" waking up.%^RESET%^", who);
            }
        }
        if (combat_counters["unconscious"] > (25 - (int)who->query_stats("constitution")) )
        {
            combat_vars["unconscious"]--;;
            vars = 1;
            combat_counters["unconscious"] = 0;
            if (!combat_vars["unconscious"])
            {
                message("combat","%^BOLD%^%^BLUE%^You have regained consciousness.",who);
                if(!who->query_invis() && objectp(EWHO))
                {
                    tell_room(EWHO, "%^GREEN%^You notice "+who->QCN+" waking up.%^RESET%^", who);
                }
            }
        }
        combat_counters["unconscious"]++;
        counters = 1;
    }

    if (combat_vars["asleep"])
    {
        if (combat_counters["asleep"] > (25 - (int)who->query_stats("constitution")) )
        {
            combat_vars["asleep"]--;
            vars = 1;
            combat_counters["asleep"] = 0;
            if (!combat_vars["asleep"])
            {
                if(!who->query_invis() && objectp(EWHO))
                {
                    tell_room(EWHO, "%^GREEN%^You notice "+who->QCN+" waking up.%^RESET%^", who);
                }
                message("combat","%^BOLD%^%^BLUE%^You have awakened.",who);
            }
        }
        combat_counters["asleep"]++;
        counters = 1;
    }

    if (who->query_deaths_door() )
    {
        if (combat_counters["healing"] > (25 - (int)who->query_stats("constitution")) )
        {
            who->heal(random(2)+1);
            combat_counters["healing"]=0;
            if (!who->query_deaths_door())
            {
                message("combat","%^BOLD%^%^BLUE%^You have healed sufficiently to regain consciousness.",who);
                if(!who->query_invis() && objectp(EWHO))
                {
                    tell_room(EWHO, "%^GREEN%^You notice "+who->QCN+" waking up.%^RESET%^", who);
                }
            }
        }
        combat_counters["healing"]++;
        counters = 1;
    }
    if(vars) who->set_combat_vars(combat_vars);
    if(counters) who->set_combat_counters(combat_counters);
    if(static_vars) who->set_combat_static_vars(combat_static_vars);
    return;
}

varargs void set_tripped(object who, int severity, string message, int special)
{
    int chance;
    if(!objectp(who)) return;
        if(who->query_property("no tripped"))
        {
                tell_object(who,"You cannot be tripped.");
                return;
        }
    if(intp(chance = who->query_property("untrippable")))
    {
        if(chance > roll_dice(1, 100))
        {
            tell_object(who, "You avoid the attempt to trip you!");
            if(objectp(environment(who))) { tell_room(environment(who), who->QCN+" avoids the attempt to trip "+who->QO+"!", who); }
            return;
        }
    }
    who->adjust_combat_mapps("vars", "tripped", severity);
    who->adjust_combat_mapps("messages", "tripped", message);
    if(special)
    {
        who->adjust_combat_mapps("counters", "tripped counter", special);
    }  // Added to give better control over rush, could
       // be used for other things.  -Ares 12/26/06
    return;
}

void set_asleep(object who, int xxx, string message)
{
    if(!objectp(who)) return;
    who->adjust_combat_mapps("vars", "asleep", xxx);
    who->adjust_combat_mapps("messages", "asleep", message);
}

void set_unconscious(object who, int xxx, string message)
{
    if(!objectp(who)) return;
    who->adjust_combat_mapps("vars", "unconscious", xxx);
    who->adjust_combat_mapps("messages", "unconscious", message);
}

void set_gagged(object who, int x, string message)
{
    if(!objectp(who)) return;
    who->adjust_combat_mapps("vars", "gagged", x);
    who->adjust_combat_mapps("messages", "gagged", message);
}

void set_bound(object who, int difficulty, string message)
{
    if(!objectp(who)) return;
    who->adjust_combat_mapps("vars", "bound", difficulty);
    who->adjust_combat_mapps("messages", "bound", message);
}

void set_temporary_blinded(object who, int difficulty, string message)
{
    if(!objectp(who)) return;
    if(who->query_property("no blind"))
    {
        tell_object(who, "You are immune to blindness!");
        if(objectp(environment(who)))
        {
            tell_room(environment(who), who->QCN+" seems immune to the "+
            "blindness attempt!", who);
        }
        return;
    }
    who->adjust_combat_mapps("static vars", "blinded", difficulty);
    if(stringp(message)) who->adjust_combat_mapps("messages", "blinded", message);
}

void set_blindfolded(object who, int difficulty, string message)
{
    if(!objectp(who)) return;
    who->adjust_combat_mapps("vars", "blindfolded", difficulty);
    if(stringp(message)) who->adjust_combat_mapps("messages", "blindfolded", message);
}

/**
 * Assigns paralyzed state, where 'x' is divisor of 8 rounds.
 * E.g. x = 16 will set paralyzed status for 2 rounds.
 */
void set_paralyzed(object who, int x, string paralyze_msg)
{
    if(!objectp(who) || !intp(x))
        return;
    if(archp(who))
    {
        message("my_action", "Your Archhood just saved you from being paralyzed.", who);
        return;
    }
    if(who->query_property("no paralyze"))
    {
        message("my_action","You are uneffected by the paralysis.",who);
        if(objectp(environment(who)) && !who->query_invis())
        {
            tell_room(environment(who), who->QCN+" %^BOLD%^%^GREEN%^is totally uneffected by "+
                      "the paralysis attempt!%^RESET%^");
        }
        return;
    }
    x /= 8;
    x = x<1?1:x;
    x = x>72?72:x;

    who->adjust_combat_mapps("vars", "paralyzed", x);
    who->adjust_combat_mapps("messages", "paralyzed", paralyze_msg);
    return;
}

/**
 * Removes paralyzed state
 */
void remove_paralyzed(object who)
{
    if(!objectp(who)) { return; }
    if(!who->query_paralyzed()) { return; }
    who->adjust_combat_mapps("vars", "paralyzed", 0);
    who->adjust_combat_mapps("messages", "paralyzed", 0);
    if(who->query_tripped() || who->query_bound() || who->query_unconscious()) { return; }
    tell_object(who,"You can move again.");
    if(!who->query_invis() && objectp(environment(who)))
    {
            tell_room(environment(who), "%^BOLD%^%^GREEN%^You see "+who->QCN+" is moving again.%^RESET%^", who);
    }
    return;
}

object *doProtection(object player)
{
    int i,j;
    object *pros, *tmp=({});

    if (!objectp(player)) { return ({ player }); }
    pros = player->query_protectors();

    j = sizeof(pros);
    if (!j) { return({player}); }

    for (i=0;i<j;i++)
    {
        if(!objectp(pros[i])) continue;
        if(!present(pros[i], player) && (!pros[i]->query_following() || (object)pros[i]->query_following() != player))
        {
            player->remove_protector(pros[i]);
            continue;
        }
        if(pros[i] == player)
        {
            player->remove_protector(pros[i]);
            continue;
        }
        if(member_array(pros[i], player->query_attackers()) == -1)
        {
            tmp+=({pros[i]});
        }
        if((int)pros[i]->query_hp_percent() < 30)
        {
            player->remove_protector(pros[i]);
            tell_object(pros[i], "You are too weak to continue protecting "+player->QCN+".");
            pros[i]->set("protecting",0);
            continue;
        }
        //if(random(query_highest_level()*2) > random((int)pros[i]->query_highest_level() + (int)player->query_lowest_level()))
        if(!random(7) && pros[i]->query("protecting"))
        {
            tell_object(pros[i], "You are unable to defend "+player->QCN+" this attack.");
            pros[i]->set("protecting",0);
            continue;
        }
        //tell_object(pros[i], "You stand in defense of "+player->QCN+".");
        //tell_object(player,pros[i]->QCN+" stands in defense of you.");
        pros[i]->set("protecting",1);
        tmp += ({pros[i]});
        continue;
    }
    //if (!sizeof(tmp)) tmp += ({player});
    tmp += ({player});
    tmp = distinct_array(tmp);
    return tmp;
}

object *query_active_protectors(object obj)
{
    object *protectors = ({}),*good_protectors=({});
    int i;

    if(!objectp(obj)) { return ({}); }

    protectors = (object *)obj->query_protectors();

    if(!pointerp(protectors)) { return ({}); }
    if(!sizeof(protectors)) { return ({}); }

    for(i=0;i<sizeof(protectors);i++)
    {
        if(!objectp(protectors[i])) { continue; }
        if(!protectors[i]->query("protecting")) { continue; }
        if(!present(protectors[i],environment(obj))) { continue; }
        good_protectors += ({ protectors[i] });
        continue;
    }
    if(!sizeof(good_protectors)) { return ({}); }
    return good_protectors;
}

void send_dodge(object who, object att)
{
    int i,j;
    string *verb,*adverb,v,a;
    if(!objectp(att) || !objectp(who))  return;

    verb = ({"flip","back flip","jump","dodge","roll","somersault","dance","spin","scramble"});
    adverb = ({"easily","quickly","barely","poorly","with agility","deftly"});
    v = verb[random(sizeof(verb))];
    a = adverb[random(sizeof(adverb))];
    tell_object(who,att->QCN+" "+v+"s "+a+" from your blow.");
    tell_object(att,"You "+v+" "+a+" from "+who->QCN+"'s blow.");
    tell_room(environment(who),att->QCN+" "+v+"s "+a+" from "+who->QCN+"'s blow.",({who,att}));
    return;
}

//is this even used? Saide - January 2017
void thaco_messages(object who, int thaco)
{
    if(!objectp(who)) return;
    switch (thaco)
    {
        case 8..10:
            tell_object(who, "%^YELLOW%^Your pitiful attempt at wielding two weapons is just silly.%^RESET%^");
            break;
        case 5..7:
            tell_object(who, "%^ORANGE%^You look really silly trying to wield two weapons %^RESET%^");
            break;
        case 4:
            tell_object(who, "%^RED%^You awkwardly attack with two weapons %^RESET%^");
            break;
        case 3:
            tell_object(who, "%^YELLOW%^You have trouble attacking with two weapons.%^RESET%^");
            break;
        case 2:
            tell_object(who, "%^BLUE%^You find difficulty in wielding two weapons.%^RESET%^");
            break;
        case 1:
            tell_object(who, "%^GREEN%^Wielding two weapons is harder but still effective.%^RESET%^");
            break;
        default: break;
    }
    return;
}

int ok_to_kill(object who, object targ)
{
    int vic_level, pk_age_limit;
    string str, title;
    object hold, pkob;
    if(!objectp(targ) || !objectp(who))  return 0;
    if (targ->is_invincible()) return 0;
    if(!interactive(who) && !interactive(targ)) return 1;
    if(who == targ) return 1;
    //if(ETO->query_property("no kill") || ETO->query_property("no attack")) return 0;
    if (interactive(who) && interactive(targ))
    {
        if (newbiep(who) && (!avatarp(targ)))
        {
            tell_object(who,"%^YELLOW%^You are currently under "+
            "%^CYAN%^newbie%^YELLOW%^ protection and unable to "+
            "be aggressive against "+targ->QCN+"%^YELLOW%^!%^RESET%^");
            return 0;
        }
        if (newbiep(targ) && (!avatarp(who)))
        {
            tell_object(who,targ->QCN+"%^YELLOW%^ is currently "+
            "under %^CYAN%^newbie%^YELLOW%^ protection and "+
            "cannot be attacked by you.%^RESET%^");
            return 0;
        }
        /*pk_age_limit = AVERAGE_AGE_D->return_age_needed((int)targ->query_character_level());
        if((int)targ->query_age() < pk_age_limit)
        {
            tell_object(who, targ->QCN+"%^YELLOW%^ is currently "+
            "time barred from being involved in pkill interactions.%^RESET%^");
            return 0;
        }
        pk_age_limit = AVERAGE_AGE_D->return_age_needed((int)who->query_character_level());
        if((int)who->query_age() < pk_age_limit)
        {
            tell_object(who, "%^YELLOW%^You are currently time "+
            "barred from being involved in pkill interactions.%^RESET%^");
            return 0;
        } */
        if(targ->query("no pk"))
        {
            tell_object(who, targ->QCN+"%^YELLOW%^ is currently protected "+
            "from pkill interactions.%^RESET%^");
            return 0;
        }
        if(who->query("no pk"))
        {
            tell_object(who, "%^YELLOW%^You are currently protected from pkill "+
            "interactions. See help flag in order to turn this off.%^RESET%^");
            return 0;
        }
        if (in_edit(targ) || in_input(targ) && interactive(who))
        {
            tell_object(who, targ->QCN+"%^RED%^ is currently in "+
            "edit and cannot be attacked.%^RESET%^");
            return 0;
        }
        pkob = new(PK_OB);
        pkob->move(who);
        pkob->pkill_start(who, targ, 1);
        pkob = new(PK_OB);
        pkob->move(targ);
        pkob->pkill_start(targ, who, 0);
    }
    return 1;
}

void add_attacker(object who, object ob)
{
    object *attackers;
    string *atnames;
    if(!objectp(who) || !objectp(ob)) return;
    if(!objectp(environment(who)) || !objectp(environment(ob))) return;
    attackers = who->query_attackers();
    atnames = who->query_atnames();
    if (ob == who) return;
    if (member_array(ob, attackers) !=-1) return;
    attackers += ({ob});
    if (userp(ob))
    {
        if (member_array(ob->query_name(), atnames) != -1) return;
        if (environment(who)->query_property("arena")) return;
        atnames += ({ob->query_name()});
    }
    if(sizeof(attackers)) who->set_attackers(attackers);
    if(sizeof(atnames)) who->set_atnames(atnames);
    who->check_death();
    ob->check_death();
    who->clean_up_attackers();
    ob->clean_up_attackers();
    return;
}

int light_armor_filter(object ob)
{
    if(!objectp(ob)) { return 0; }
    if((string)ob->query_armor_prof() == "heavy") { return 1; }
    if((string)ob->query_armor_prof() == "medium") { return 1; }
    return 0;
}

void ok_to_wield(object who)
{
    object *wielded,*worn;
    int Size;
    if(!objectp(who)) return;
    if (interactive(who))
    {
        wielded = who->query_wielded();
        worn    = who->all_armour();
        worn    = distinct_array(worn);
        worn    = filter_array(worn,"light_armor_filter",TO);
        if (sizeof(wielded) > 1)
        {
            Size = (int)who->query_size() - 1;
            if(Size == 0) Size = 1;

            if((wielded[0]->query_size() > Size) && (wielded[1]->query_size() > Size) && (wielded[0] != wielded[1]))
            {
                if(FEATS_D->usable_feat(who,"ambidexterity"))
                {
                    if(sizeof(worn))
                    {
                        tell_object(who,"You scramble to hang on to your "+wielded[0]->query_name()+" and "
                            "your "+wielded[1]->query_name()+" but all that armor makes it impossible!");
                        tell_room(environment(who),""+who->QCN+" scrambles to hang on to "+who->QP+" "+wielded[0]->query_name()+" "
                            "and "+who->QP+" "+wielded[1]->query_name()+" but fumbles and drops them!",who);

                        if (!wielded[0]->query_property("enchantment") || (int)wielded[0]->query_property("enchantment") > 0)
wielded[0]->move(environment(who));
                        if (!wielded[1]->query_property("enchantment") || (int)wielded[1]->query_property("enchantment") > 0)
wielded[1]->move(environment(who));
                    }
                }
                else
                {
                    tell_object(who,"In your attempt to wield two such weapons, you fumble and drop them.");
                    tell_room(environment(who),who->QCN+" fumbles with "+who->QP+" "+wielded[0]->query_name()+" and "
                        ""+who->QP+" "+wielded[1]->query_name()+" and then drops them.",who);
                    if (!wielded[0]->query_property("enchantment") || (int)wielded[0]->query_property("enchantment") > 0)
wielded[0]->move(environment(who));
                    if (!wielded[1]->query_property("enchantment") || (int)wielded[1]->query_property("enchantment") > 0)
wielded[1]->move(environment(who));
                }
            }
        }
    }
}

void clean_attacker_flags(object who)
{
    if(!objectp(who)) return;
    who->remove_property("using whirl");
    who->remove_property("using sweeping blow");
    who->remove_property("using manyshot");
    who->remove_property("using spinning kick");
    who->remove_property("using smite");
}

int sight_adjustment(object who)
{
    int elight, ret;
    ret = 0;
    elight = effective_light(who);
    if(elight > 6 || elight < 1) { ret = random(5); }
    return ret;
}

void run_away(object who)
{
    string *str;
    string dir, wimpydir;

    if(!objectp(who) || !objectp(environment(who))) return;
    str = (string*)environment(who)->query_exits();
    if(!str || !sizeof(str))
    {
        tell_object(who,"There is nowhere to run!!!");
        return;
    }

    tell_object(who,"You run away.");
    if(objectp(environment(who)) && !who->query_invis()) { tell_room(environment(who), who->QCN+" runs away!", who); }
    wimpydir = who->query_wimpydir();
    if(member_array(wimpydir, str) != -1)
    {
        dir = wimpydir;
    }
    else if(wimpydir == "retreat")
    {
        dir = environment(who)->query_direction(base_name(who->query_last_location()));
    }
    if(!dir || dir == "/d/shadowgate/void")
    {
        dir = str[random(sizeof(str))];
    }
    who->set_property("true moving",dir);
    who->set_property("running away",1);
    who->force_me(dir);
    who->remove_property("running away");
    who->remove_property("true moving");
    who->set_wimped(1);
    return;
}

string query_paralyze_message(object who)
{
    if (!objectp(who))            { return ""; }
    if (who->adminBlock())        { return ""; }
    if (who->query_deaths_door()) { return DEATHS_DOOR_MESSAGE; }
    if (who->query_unconscious()) { return who->query_unconscious_message(); }
    if (who->query_paralyzed())   { return who->query_combat_mapps("messages", "paralyzed"); }
    if (who->query_bound())       { return who->query_bound_message(); }
    if (who->query_tripped())     { return who->query_tripped_message(); }
}

//altered to allow best avoidance type to process
//added ultra counter attack if both spring attack and masters parry process
//Yves - 11/02/2018
int check_avoidance(object who, object victim, object *weapons)
{
    object EWHO, rider;
    int athleticsWho, athleticsVictim, avoidance = 0, mod = 0, springAttack = 0, counterAttack = 0;
    string avoidanceType = "";

    if(!objectp(who) || !objectp(victim)) return 0;
    if(!objectp(EWHO = environment(who))) return 0;
    if(!objectp(victim)) return 0;
    //shouldn't be parrying/scrambling, etc, if you are paralyzed
    if(victim->query_paralyzed()) return 0;
    //if they have the noMissChance property set, then don't miss via parry/scramble/ride by attack
    if(who->query_property("noMissChance")) return 0;

    athleticsWho = (int)who->query_character_level();
    athleticsWho += (int)who->query_skill("athletics");
    athleticsVictim = (int)victim->query_character_level();
    athleticsVictim += (int)victim->query_skill("athletics");

    //scramble
    if (victim->query_scrambling() && (victim->is_ok_armour("thief") || victim->query_property("shapeshifted")) )
    {
        //can't flip around if you are laying on the ground
        if(!victim->query_tripped()){
            if(victim->query_parrying()) mod = -roll_dice(1,10);
            //else mod = roll_dice(1,8);
            if((roll_dice(1, athleticsVictim)+mod) > roll_dice(1, athleticsWho))
            {
                avoidance = 1;
                avoidanceType = "TYPE_SCRAMBLE";
                if(FEATS_D->usable_feat(victim,"spring attack") && !random(5))
                {
                  springAttack = 1;
                }
            }
        }
    }

    if((sizeof(weapons) && !weapons[0]->is_lrweapon()) || !FEATS_D->usable_feat(who, "point blank shot"))
    {
        //ride-by attack
        if(victim->query_in_vehicle() && FEATS_D->usable_feat(victim,"ride-by attack") && !random(5))
        {
            if(roll_dice(1, athleticsVictim) > roll_dice(1, athleticsWho))
            {
                avoidance = 1;
                avoidanceType = "TYPE_RIDDEN";
            }
        }

        //shot on the run
        if(!FEATS_D->usable_feat(victim,"ride-by attack") && victim->query_property("shotontherun") && !random(5))
        {
            if(roll_dice(1, athleticsVictim) > roll_dice(1, athleticsWho))
            {
                avoidance = 1;
                avoidanceType = "TYPE_SHOT";
            }
        }

        //mounted combat
        if(victim->is_animal() && !random(5))
        {
            rider = (object)victim->query_current_rider();
            if(objectp(rider))
            {
                if(FEATS_D->usable_feat(rider,"mounted combat") && (roll_dice(1, athleticsVictim) > roll_dice(1, athleticsWho)))
                {
                    avoidance = 1;
                    avoidanceType = "TYPE_MOUNT";
                }
            }
        }
    }

    //parry
    if(sizeof(weapons) || FEATS_D->usable_feat(victim, "unarmed parry"))
    {
        if ((victim->query_parrying()) && (!victim->query_property("shapeshifted")))
        {
            if(victim->query_property("shield_of_whirling_steel")) {
              mod += victim->query_property("shield_of_whirling_steel");
            }
            if(victim->query_scrambling() && !victim->query_property("shield_of_whirling_steel")) {
              mod = -roll_dice(1,10);
            }
            //else mod = roll_dice(1,8);
            if((roll_dice(1, athleticsVictim)+mod) > roll_dice(1, athleticsWho))
            {
                avoidance = 1;
                avoidanceType = "TYPE_PARRY";
                if(FEATS_D->usable_feat(victim,"masters parry") && victim->is_wielding("dual wielding"))
                {
                    if(random(4)) counterAttack = 1; // should happen frequently as it's a level 47 ability
                }
            }
        }
    }

    //ensure the correct avoidance message fires
    if(counterAttack && springAttack) avoidanceType = "TYPE_COMBINED";
    else if(counterAttack) avoidanceType = "TYPE_PARRY";
    else if(springAttack) avoidanceType = "TYPE_SCRAMBLE";

    switch(avoidanceType) {
      case "TYPE_COMBINED":
          tell_object(who,"Your opponent anticipates your attack and maneuvers"
          " into perfect position!");
          tell_object(victim,"You anticipate your opponent's attack and maneuver"
          " into perfect position!");
          tell_room(EWHO,"You see "+who->QCN+"'s attack expertly avoided by "+victim->QCN+"!",({who,victim}) );
          combined_attack(who, victim);
          break;
      case "TYPE_SCRAMBLE":
          who->send_dodge(victim);
          if(springAttack) victim->spring_attack(victim);
          break;
      case "TYPE_PARRY":
          tell_object(who,"Your attack is parried by your attacker!");
          tell_object(victim,"You deftly parry your opponent's blow!");
          tell_room(EWHO,"You see "+who->QCN+"'s attack parried by "+victim->QCN+".",({who,victim}) );
          if(counterAttack) counter_attack(victim);
          break;
      case "TYPE_RIDDEN":
          tell_object(who,"%^RESET%^%^BOLD%^"+victim->QCN+" has already ridden past you and "
          "is out of reach!%^RESET%^");

          tell_object(victim,"%^RESET%^%^BOLD%^You deftly steer your steed and "+who->QCN+
          "'s blow falls short of hitting you!%^RESET%^");

          tell_room(EWHO,"%^RESET%^%^BOLD%^"+victim->QCN+" deftly steers "+victim->QP+
          " steed and "+who->QCN+"'s blow falls short of hitting "+victim->QO+
          "!%^RESET%^",({who,victim}));
          break;
      case "TYPE_SHOT":
          tell_object(who,"%^RESET%^%^BOLD%^"+victim->QCN+" uses "+victim->QP+" own attack as "
          "cover, and manages to move out of your reach!%^RESET%^");

          tell_object(victim,"%^RESET%^%^BOLD%^You use your last shot as cover to get clear "
          "of "+who->QCN+"'s attack!%^RESET%^");

          tell_room(EWHO,"%^RESET%^%^BOLD%^"+victim->QCN+" uses "+victim->QP+" last shot as "
          "cover to get clear of "+who->QCN+"'s attack!%^RESET%^",({who,victim}));
          break;
      case "TYPE_MOUNT":
          tell_object(rider,"%^RESET%^%^BOLD%^You direct your steed out of harm's way!%^RESET%^");

          tell_room(EWHO,"%^RESET%^%^BOLD%^"+rider->QCN+" directs "+rider->QP+
          "steed out of harm's way!%^RESET%^",rider);
          break;
      default: break;
    }

    return avoidance;
}

void combined_attack(object who, object victim)
{
  object *attackers, EWHO;

  if(!objectp(who) || !objectp(victim)) return;
  attackers = victim->query_attackers();
  attackers -= ({ 0 });
  if(!sizeof(attackers)) return;
  EWHO = environment(who);

  //special effect on top of an extra attack since they springed AND countered
  switch(random(50)) {
      case 0..29: //damage
          tell_object(who, "%^BOLD%^%^RED%^"+victim->QCN+" takes advantage of "+victim->QP+
          " position and delivers a devastating blow while your guard is down!%^RESET%^");
          tell_object(victim, "%^BOLD%^%^RED%^You take advantage of your position "
          "and deliver a devastating blow to "+who->QCN+" while "+who->QP+" guard is down!%^RESET%^");
          tell_room(EWHO, "%^BOLD%^%^RED%^"+victim->QCN+" takes advantage of "+victim->QP+
          " position and delivers a devastating blow to "+who->QCN+" while "+who->QP+
          " guard is down!%^RESET%^", ({who,victim}));
          who->do_damage(who->return_limb(),roll_dice(5,12)+25);
          break;
      case 30..39: //stun
          tell_object(victim, "%^BOLD%^%^WHITE%^You take advantage of your position "
          "and connect with a strike that leaves "+who->QCN+" staggered!%^RESET%^");
          tell_object(who, "%^BOLD%^%^WHITE%^"+victim->QCN+" takes advantage of "+victim->QP+
          " position and connects with a strike that leaves you staggered!%^RESET%^");
          tell_room(EWHO, "%^BOLD%^%^WHITE%^"+victim->QCN+" takes advantage of "+victim->QP+
          " position and connects with a strike that leaves "+who->QCN+
          " staggered!%^RESET%^", ({who,victim}));
          who->set_paralyzed(roll_dice(1,10) + 10, "%^BOLD%^%^WHITE%^You are staggered "
          "by the unexpected blow!%^RESET%^");
          break;
      case 40..49: //trip
          tell_object(victim, "%^BOLD%^%^BLUE%^You take advantage of your position "
          "and sweep through "+who->QCN+"'s lower limbs causing "+who->QO+
          " to fall prone!%^RESET%^");
          tell_object(who, "%^BOLD%^%^BLUE%^"+victim->QCN+" takes advantage of "+victim->QP+
          " position and sweeps through your lower limbs causing you to fall prone!%^RESET%^");
          tell_room(EWHO, "%^BOLD%^%^BLUE%^"+victim->QCN+" takes advantage of "+victim->QP+
          " position and sweeps through "+who->QCN+"'s lower limbs causing "+who->QO+
          " to fall prone!%^RESET%^", ({who,victim}));
          who->set_tripped(random(2)+1, "%^BOLD%^%^BLUE%^You are scrambling to your feet!%^RESET%^");
          break;
      default: break;
  }
  victim->execute_attack();

  return;
}


//FUNCTIONS BELOW STILL NEED CONVERTING
void internal_execute_attack(object who)
{
    int toAttack, toattack, lastHand, critical_hit;
    int i, roll, temp1, temp2, touch_attack = 0;
    object *weapons, current, victim, *protectors, *attackers, EWHO;
    string target_thing;

    if(!objectp(who)) return;
    who->set_for_attack(); //sets attacking to 0 - this function will not get called until it is 0
    EWHO = environment(who);
    if(!objectp(EWHO)) return;
    if(objectp(who)) { who->reset_critical(); }
    attackers = who->query_attackers();
    if (!sizeof(attackers))
    {
        who->prepare_attack();
        if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) { who->execute_attack();
}
        return;
    }
    if (who->query_property("flee"))
    {
        who->prepare_attack();
        if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) { who->execute_attack();
}
        return;
    }

    toAttack = random(sizeof(attackers));
    while (!objectp(attackers[toAttack]) || !present(attackers[toAttack],EWHO))
    {
        attackers -= ({attackers[toAttack]});
        who->set_attackers(attackers);
        if (!sizeof(attackers))
        {
            who->prepare_attack();
            if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
who->execute_attack(); }
            return;
        }
        toAttack = random(sizeof(attackers));
    }
    who->adjust_combat_mapps("vars", "toAttack", toAttack);

    toattack = 4;
    who->adjust_combat_mapps("static vars", "toattack", toattack);

    victim = attackers[toAttack];
    protectors = victim->query_active_protectors(victim);
    if(sizeof(protectors))
    {
        victim = protectors[random(sizeof(protectors))];
    }
    if(!living(victim) && !victim->query("not living"))
    {
        who->prepare_attack();
        if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) { who->execute_attack();
}
        return;
    }

    if(FEATS_D->usable_feat(who, "perfect self")) { if(!(int)who->has_ki()) { who->regenerate_ki(4); } }

    if (member_array(who,(object *)victim->query_attackers()) == -1)
    {
        victim->add_attacker(who);
        EWHO->add_combatant(victim);
        who->clean_up_attackers();
    }
    if ((!who->do_casting(victim) && !who->query_property("temp_perfect_caster")) && !who->do_functions())
    {
        who->ok_to_wield();
        weapons = distinct_array(who->query_wielded());
        lastHand = who->query_combat_mapps("static vars", "lastHand");
        if(pointerp(weapons) && lastHand < sizeof(weapons)) current = weapons[lastHand];
        else if(pointerp(weapons) && lastHand > (sizeof(weapons)-1))
        {
            who->adjust_combat_mapps("static vars", "lastHand", 0);
            lastHand = 0;
            if(lastHand < sizeof(weapons)) current = weapons[lastHand];
            else current = who;
        }
        else current = who;

        if(current->is_lrweapon() && !FEATS_D->usable_feat(who, "point blank shot"))
        {
            tell_object(who,"Your bow is useless in hand to hand combat.\n");
            who->prepare_attack();
            if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
who->execute_attack(); }
            return;
        }
        roll = random(20)+1;

        target_thing = (string)victim->return_target_limb();
        roll = BONUS_D->process_hit(who, victim, i, current, 0, touch_attack);
        //crit stuff
        if(sizeof(weapons) && !who->query_property("shapeshifted"))
        {
            temp1 = (int)current->query_critical_threat_range();
            if(FEATS_D->usable_feat(who, "lethal strikes") && !who->query_property("shapeshifted"))
            {
                if(sizeof(weapons) >= 2)
                {
                    if(weapons[0] != weapons[1]) temp1 += 1;
                    if((int)weapons[0]->query_size() == 1 && (int)weapons[1]->query_size() == 1) temp1 += 1;
                }
                else if(sizeof(weapons) == 1)
                {
                    temp1 += 1;
                    if((int)weapons[0]->query_size() == 1) temp1 += 1;
                }
            }
        }
        else { temp1 = 2; }

        if(roll > (20 - temp1)) // if threat range of weapon is 2, then we have a crit threat on a roll of 19 or 20
        {
            if(!victim->query_property("no crit") && ( !interactive(victim) || ((int)victim->query_level() > 5) ))
            {
                temp2 = BONUS_D->process_hit(who, victim, i, current);
                if(temp2)
                {
                    who->adjust_combat_mapps("static vars", "critical hit", 1);
                    who->adjust_combat_mapps("static vars", "critical message", 1);
                    critical_hit = 1;
                }
            }
        }
        // end crit stuff
        if (roll)
        {
            if(!victim->query_unconscious() && !victim->query_ghost() && !victim->query_bound())
            {
                if(!extra_hit_calcs(who, victim, current, target_thing) || check_avoidance(who, victim, weapons))
                {
                    if(!objectp(who)) return;
                    who->adjust_combat_mapps("static vars", "lastHand", 1, 1);
                    who->adjust_combat_mapps("static vars", "attacking", 0);
                    if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
who->execute_attack(); }
                    return;
                }
                else calculate_damage(who, victim, current, target_thing, critical_hit);
            }
            else calculate_damage(who, victim, current, target_thing, critical_hit);
        }
        if(roll == 1)
        {
            //if(find_player("saide") && userp(who)) tell_object(find_player("saide"), identify(who) + " rolled a 1 against "+identify(victim));
            if(objectp(current))
            {
                if((int)current->query("PoisonDoses"))
                {
                    if(who->reflex_save(15))
                    {
                        POISON_D->is_object_poisoned(current, who, "hit", 1);
                    }
                }
            }
        }
        if(!roll)
        {
            //if(find_player("saide") && userp(who)) tell_object(find_player("saide"), identify(who) + " missed "+identify(victim));
            if (!current || who->query_property("shapeshifted")) who->miss(who->query_casting(), victim, 0, target_thing);
            else who->miss(0, victim, (string)current->query_type(), target_thing);
        }

    }

    if(!objectp(who)) { return; }
    if(!objectp(victim))
    {
        who->adjust_combat_mapps("static vars", "lastHand", 1, 1);
        who->adjust_combat_mapps("static vars", "attacking", 0);
        if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) { who->execute_attack();
}
        return;
    }

    if(FEATS_D->usable_feat(who,"combat reflexes") &&
       who->is_ok_armour("thief") &&
       !who->query_casting() &&
       (int)who->query_property("stabs_available") > 0 &&
       !who->query_paralyzed() && !who->query_tripped())
    {
        who->set_property("stabs_available",-1);
        if(victim->query_property("stab_resilience")) {
            victim->set_property("stab_resilience",-1);
            tell_object(who,"You successfully position yourself to strike where "+victim->QCN+" is vulnerable, but "+victim->QS+" seems unaffected.");
            tell_object(victim,"You suddenly notice that "+who->QCN+" has moved to strike where you are vulnerable, but you are resilient against the worst of the attack.");
            tell_room(EWHO,""+who->QCN+" has positioned "+who->QO+"self to strike where "+victim->QCN+" is vulnerable, but "+victim->QS+" seems unaffected.",({victim,who}));
        }
        else {
            tell_object(who,"You successfully position yourself to strike where "+victim->QCN+" is vulnerable.");
            tell_object(victim,"You suddenly notice that "+who->QCN+" has moved to strike where you are vulnerable.");
            tell_room(EWHO,""+who->QCN+" has positioned "+who->QO+"self to strike where "+victim->QCN+" is vulnerable.",({victim,who}));
            "/cmds/mortal/_stab"->scramble_stab(who,victim);
        }
    }

    if (((int)who->query_scrambling() == 1)&& who->is_ok_armour("thief") && who->is_class("thief"))
    {
        if(D_BUG_D->scramble_change()) who->set_scrambling(2);
    }

    who->adjust_combat_mapps("static vars", "lastHand", 1, 1);
    who->adjust_combat_mapps("static vars", "attacking", 0);
    if(who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) { who->execute_attack(); }
    return;
}

// Does the functions returns 1 if func is executed and 0 if not
int do_functions(object who)
{
    object random_targ;
    if(!objectp(who)) return 0;
    if(who->query_combat_mapps("vars", "funcCast")) return 0;
    if(!who->clean_up_attackers()) return 0;
    who->setFuncCast(1);
    if (who->query_func_chance() > (random(100)+1))
    {
        random_targ = who->return_player_target(50);
        if ((!objectp(random_targ))) return 0;
        who->setFuncing(1);
        call_other(who, who->get_random_func(), random_targ);
        return 1;
    }
    return 0;
}

mixed return_player_target(object who, int flag)
{
    int x;
    object *myTargets = ({}), attackers;
    if(!objectp(who)) return 0;
    if(!who->clean_up_attackers()) { return 0; }
    attackers = who->query_attackers();
    if(!intp(flag)) flag = 50;
    if(roll_dice(1,100) > flag) return attackers[random(sizeof(attackers))];
    for(x = 0;x < sizeof(attackers);x++)
    {
        if(!interactive(attackers[x])) continue;
        myTargets += ({attackers[x]});
        continue;
    }
    if(sizeof(myTargets)) return myTargets[random(sizeof(myTargets))];
    else return attackers[random(sizeof(attackers))];
}

int do_casting(object who, object targ)
{
    string this_spell, spell_type, spell_file;
    object tempspell;
    if(!objectp(who) || !objectp(environment(who))) return 0;
    if(!objectp(targ)) targ = who->return_player_target(50);
    if(!objectp(targ) || !present(targ, environment(who))) return 0;
    if (who->query_combat_mapps("vars", "castFunc")) return 0;
    who->setCastFunc(1);
    if ((int)who->query_spell_chance() > (random(100)+1))
    {
        this_spell = (string)who->get_random_spell();
        if (this_spell)
        {
            spell_file="/cmds/spells/"+this_spell[0..0]+"/_"+replace_string(this_spell," ","_")+".c";
            if (file_exists(spell_file))
            {
                tempspell=new(spell_file);
                if(!objectp(tempspell))
                {
                    who->setCastFunc(0);
                    return 0;
                }
                if ((int)tempspell->query_target_required() == 1)
                {
                    tempspell->use_spell(who,targ,who->query_level());
                }
                else
                {
                    tempspell->use_spell(who,0,who->query_level());
                }
            }
        }
        return 1;
    }
    return 0;
}

void spring_attack(object ob)
{
    object *attackers;
    if(!objectp(ob)) { return; }
    attackers = ob->query_attackers();
    attackers -= ({ 0 });
    if(!sizeof(attackers)) { return; }
    tell_object(ob,"%^BOLD%^%^CYAN%^You use the momentum of your dodge to "
        "try and land another attack!");
    tell_room(environment(ob),"%^BOLD%^%^CYAN%^"+ob->QCN+" uses the momentum "
        "of "+ob->QP+" dodge to try and land another attack!",ob);
    ob->execute_attack();
    return;
}


void counter_attack(object ob)
{
    object *attackers;
    if(!objectp(ob)) { return; }
    attackers = ob->query_attackers();
    attackers -= ({ 0 });
    if(!sizeof(attackers)) { return; }
    tell_object(ob,"%^RESET%^%^BOLD%^%^GREEN%^You take advantage of the opening and "
        "counter attack!%^RESET%^");
    tell_room(environment(ob),"%^RESET%^%^BOLD%^%^GREEN%^"+ob->QCN+" takes advantage "
        "of the opening and counter attacks!%^RESET%^",ob);
    ob->execute_attack();
    return;
}

int isPkill(object who)
{
    int i,j;
    object killedBy, *attackers, EWHO;
    if(!objectp(who)) return 0;
    if(!objectp(EWHO = environment(who))) return 0;
    if(!userp(who) && !who->is_townsman()) { return 0; }
    attackers = who->query_attackers();
    if (!sizeof(attackers)) { return 0; }

    if(objectp(attackers[0]))
    {
       if (attackers[0]->query_property("spell") && objectp(attackers[0]->query_property("spell")))
       {
          killedBy = (attackers[0]->query_property("spell"))->query_caster();
       }
       if(!objectp(killedBy)) { killedBy = attackers[0]; }
    }

    if(EWHO->query_property("arena") && (who->query_property("safe arena") && killedBy->query_property("safe arena"))) { return 0; }

    j = sizeof(attackers);
    for (i=0;i<j;i++)
    {
        if(objectp(attackers[i]))
        {
            if (userp(attackers[i]) || isPlayerMonster(attackers[i]))
            {
                return attackers[i];
            }
            if (attackers[i]->is_townsman())
            {
                return attackers[i];
            }
            if (attackers[i]->query_property("knock unconscious"))
            {
                return attackers[i];
            }
            if (attackers[i]->is_spell() && objectp(attackers[i]->query_caster()) && interactive(attackers[i]->query_caster()))
            {
                return attackers[i]->query_caster();
            }
        }
    }
    return 0;
}

int isPlayerMonster(object ob)
{
    object spell;
    if(!objectp(ob))
    {
        return 0;
    }
    if(spell = ob->query_property("spell"))
    {
        if (!objectp(spell)) { return 0; }
        if (objectp(spell->query_caster()))
        {
            return userp(spell->query_caster());
        }
    }
    return 0;
}

void continue_attack(object who)
{
    object killedBy;
    int attack, toattack;
    object EWHO, *attackers;

    if(!objectp(who)) return;
    if(!objectp(EWHO = environment(who)) || who->query_ghost()) return;
    if(who->is_player() && !interactive(who) && !who->query_property("bounty hunter")) { return; }
    attackers = who->query_attackers();
    who->check_death();
    if(who->query_dead())
    {
        who->adjust_combat_mapps("static vars", "dead", 0);
        who->die((attackers && killedBy ? killedBy : 0));
        if(objectp(who)) who->cease_all_attacks();
        return;
    }
    //if((0) && !any_attack) casting = 0; // ???
    if(!who->query_combat_mapps("vars", "any attack") && !who->query_combat_mapps("static vars") &&
    !sizeof(attackers) && (userp(who) || !sizeof(who->query_combat_mapps("arrays", "atnames")))) return;

    if(!who->query_wimped() || userp(who))
    {
        if(!who->clean_up_attackers()) return;
    }

    if(((int)who->query_hp()*100)/(int)who->query_max_hp() < who->query_wimpy())
    {
        if(time() > (int)who->query_property("running_away_time"))
        {
            who->remove_property("running_away_time");
            who->set_property("running_away_time",time()+2);
            who->run_away();
            return;
        }
    }
    who->set_wimped(0);
    attack = who->query_combat_mapps("static vars", "attack");
    toattack = who->query_combat_mapps("static vars", "toattack");
    attack++;
    if (attack > toattack-1)
    {
        attack = 0;
        if (!who->query_paralyzed())
        {
            if (who->do_i_win())
            {
                EWHO->add_combatant(who);
            }
        }
        else
        {
            if(objectp(who)) { message("my_combat", who->query_paralyze_message(),who); }
        }
    }
    who->adjust_combat_mapps("static vars", "attack", attack);
    return;
}

int doPkill(object who)
{
    int i,j;
    object *attackers;
    if(!objectp(who)) { return 0; }
    if (who->query_property("to die")) { return 0; }
    if (who->query_hp() < (-20* who->query_max_hp())) { return 0; }
    attackers = who->query_attackers();
    j = sizeof(attackers);
    for (i=0;i<j;i++)
    {
        if(!objectp(attackers[i])) { continue; }
        attackers[i]->remove_attacker(who);
    }
    who->cease_all_attacks();
    who->set_hidden(0);
    who->set_magic_hidden(0);
    tell_object(who,"%^BOLD%^%^RED%^You have fallen unconscious due to egregious wounds.");
    if(objectp(environment(who))) tell_room(environment(who),"%^BOLD%^%^RED%^"+who->QCN+" falls unconscious due to horrible wounds.",who);
    return 1;
}

varargs int check_death(object who, object pot)
{
    object *death, magi, *newattackers, killedBy;
    int xxx, exp, i,minions, falling;
    object spellthing, *attackers;
    if(!objectp(who)) return 0;
    if(who->query_combat_mapps("static vars", "dead")) return 1;
    falling = who->query_property("falling");                                 // These lines added by
    if (userp(who) && who->query_hp() <1 && ( falling < time() - (__COMBAT_SPEED__*3)+4 ))  // Lujke to stop people
    {                                                                      // dying while
                                                                           // waiting for kits to hit
        who->set_property("falling", time());                             //
        return 0;                                                          //
    }                                                                      //
    if (who->query_hp() < 1 && !who->query_ghost() )
    {
        who->remove_property("falling");        // This also added by Lujke as above
        if(wizardp(who) && !who->query_killable())
        {
            who->set_hp((int)who->query_max_hp());
            tell_object(who,"You are immortal and cannot die.");
            return 0;
        }
        attackers = who->query_attackers();
        if(objectp(pot)) { attackers += ({pot}); }
        if (sizeof(attackers))
        {
            if (!who->is_player() && !who->is_townsman())
            {
                newattackers = attackers;
                for (i = 0;i < sizeof(attackers);i++)
                {
                    if(!objectp(attackers[i])) { newattackers -= ({attackers[i]}); continue; }
                    if(attackers[i]->query_property("minion")) { newattackers -= ({attackers[i]}); minions = 1; continue; }
                    if(attackers[i]->query_property("spell") && !attackers[i]->query_property("keep exp"))
                    {
                        newattackers -= ({attackers[i]});
                        spellthing = attackers[i]->query_property("spell");
                        if(!objectp(spellthing)) continue;
                        magi = spellthing->query_caster();
                        if (member_array(magi, newattackers) == -1 && objectp(magi)) { newattackers += ({magi}); }
                        continue;
                    }
                    else if(attackers[i]->is_spell())
                    {
                        newattackers -= ({attackers[i]});
                        spellthing = attackers[i];
                        magi = spellthing->query_caster();
                        if (member_array(magi, newattackers) == -1 && objectp(magi)) { newattackers += ({magi}); }
                    }
                    continue;
                }
                attackers = newattackers;
                who->adjust_combat_mapps("arrays", "attackers", attackers);
                if(sizeof(attackers) && objectp(attackers[0]))
                {
                    attackers[0]->add_kill((string)who->query_name());
                    if(avatarp(attackers[0]) && attackers[0]->query_disguised())
                    {
                        if(userp(attackers[0])) who->add_death((string)attackers[0]->getParsableName());
                        else who->add_death((string)attackers[0]->query_vis_name());
                    }
                                else
                    {
                        if(userp(attackers[0])) who->add_death((string)attackers[0]->getParsableName());
                        else who->add_death((string)attackers[0]->query_name());
                    }
                }
                for(i = 0;i < sizeof(attackers);i++)
                {
                    if(!objectp(attackers[i])) { continue; }
                    if(!objectp(environment(who)) || environment(who)->query_property("arena")) continue;
                    exp = who->query_exp();
                    attackers[i]->set_property("GainedExpFrom", who);
                    attackers[i]->doExp(attackers[i],exp,sizeof(attackers) + minions);
                    attackers[i]->remove_property("GainedExpFrom");
                    continue;
                }
                if(!sizeof(attackers)) return 1;
                killedBy = attackers[0];
                who->set("killedBy", killedBy);
                who->adjust_combat_mapps("static vars", "dead", 1);
                return 1;
            }
            if (killedBy = who->isPkill())
            {
                who->set("killedBy", killedBy);
                if(who->doPkill()) { return 1; }
            }
            newattackers = attackers;
            for (i = 0;i < sizeof(attackers);i++)
            {
                if(!objectp(attackers[i])) { newattackers -= ({attackers[i]}); continue; }
                if(attackers[i]->query_property("minion")) { newattackers -= ({attackers[i]}); minions = 1; continue; }
                if (attackers[i]->query_property("spell") && !attackers[i]->query_property("keep exp"))
                {
                    newattackers -= ({ attackers[i]});
                    spellthing = attackers[i]->query_property("spell");
                    if(!objectp(spellthing)) continue;
                    magi= spellthing->query_caster();
                    if(member_array(magi, newattackers) == -1) { newattackers += ({magi}); }
                }
                continue;
            }
            attackers = newattackers;
            who->adjust_combat_mapps("arrays", "attackers", attackers);
            if(sizeof(attackers) && objectp(attackers[0]))
            {
                attackers[0]->add_kill((string)who->query_name());
                if (avatarp(attackers[0]) && attackers[0]->query_disguised())
                {
                    if(userp(attackers[0])) who->add_death((string)attackers[0]->getParsableName());
                    else who->add_death((string)attackers[0]->query_vis_name());
                }
                else
                {
                    if(attackers[0]->is_spell())
                    {
                        if(userp(attackers[0]->query_caster())) who->add_death((string)attackers[0]->query_caster()->getParsableName());
                        else who->add_death( (attackers[0]->query_caster())->QCN );
                    }
                    if(userp(attackers[0])) who->add_death((string)attackers[0]->getParsableName());
                    else who->add_death((string)attackers[0]->query_name());
                }
                xxx = sizeof(death = all_inventory(attackers[0]));
                while (xxx--)
                {
                    death[xxx]->notify_kill(TO);
                }
                if(!objectp(killedBy) && attackers[0]->query_property("spell") && objectp(attackers[0]->query_property("spell")))
                {
                    killedBy = attackers[0]->query_property("spell")->query_caster();
                }
                if(!objectp(killedBy))
                {
                    killedBy = attackers[0];
                                    who->set("killedBy", killedBy);
                }
            }

            if (who->is_townsman())
            {
                for (i = 0;i < sizeof(attackers);i++)
                {
                    if (!objectp(attackers[i])) continue;
                    if(objectp(environment(who)) && environment(who)->query_property("arena")) continue;
                    exp = who->query_exp();
                    attackers[i]->set_property("GainedExpFrom", who);
                    attackers[i]->doExp(attackers[i],exp,sizeof(attackers) + minions);
                    attackers[i]->set_property("GainedExpFrom", who);
                    continue;
                }
            }
            if (!environment(who)->query_property("arena") || (!who->query_property("safe arena") || !killedBy->query_property("safe arena")))
            {
                if(objectp(killedBy))
                {
                    log_file("kills", who->query_name()+" ("+(int)who->query_level()+") was killed by "+killedBy->query_name()+"
("+(int)killedBy->query_level()+")\n");
                    log_file("kills","  "+file_name(killedBy)+"  (uid:"+getuid(killedBy)+") \n  (creator = "+killedBy->query_creator()+")
["+file_name(environment(who))+"]\n");
                }
                else
                {
                    log_file("kills", who->query_name()+" ("+(int)who->query_level()+") was killed by "+identify(killedBy)+"
("+identify(killedBy)+")\n");
                    if(objectp(environment(who)))
                    {
                        log_file("kills","  "+file_name(killedBy)+"  (uid:"+getuid(killedBy)+") \n  (creator = "+identify(killedBy)+")
["+file_name(environment(who))+"]\n");
                    }
                    else
                    {
                        log_file("kills","  "+file_name(killedBy)+"  (uid:"+getuid(killedBy)+") \n  (creator = "+identify(killedBy)+")
["+identify(who)+"]\n");
                    }
                }
            }
            if(who->isPkill() || killedBy->query_property("bounty hunter"))
            {
                if (!(environment(who)->query_property("arena")) || (!who->query_property("safe arena") || !killedBy->query_property("safe arena")))
                {
                    if (!wizardp(who) && !wizardp(killedBy))
                    {
                        log_file("pkills",who->query_name()+" ("+(int)who->query_alignment()+") was killed by "+killedBy->query_name()+"
("+(int)killedBy->query_alignment()+")\n");
                        KILLING_D->do_bad_pkill(killedBy,who);
                    }
                }
            }
            if (who->isPkill())
            {
                log_file("killers","       "+capitalize(who->query_name())+" was killed by "+capitalize(killedBy->query_name())+"\n");
                who->set("no pk", 1);
                who->set("just_been_pkilled",1);
                        who->set_pk_death_flag();
                who->perma_death();
                who->remove_property("to die");
                if (!random(100))
                {
                    log_file("permaDeaths","     "+capitalize(who->query_name())+" was perma killed by "+capitalize(killedBy->query_name())+"\n");
                    tell_object(who,"%^BOLD%^%^FLASH%^This really would have been be a permadeath had the code been in.");
                }
            }
            who->adjust_combat_mapps("static vars", "dead", 1);
            return 1;
        }
    }
    return 0;
}

void doExp(object who, int how, int split)
{
    int max,per;
    if(!objectp(who)) { return; }

    //how = how/split; // already getting split in the party daemon, so was getting split again

    if (who->query_max_level())
    {
        if(max = (int)who->query_max_level())
        {
            if(max < (int)who->query_lowest_level())
            {
                // 5% if they are 5 levels higher than the max level
                if((int)who->query_lowest_level() - max > 4)
                {
                    per = 5;
                }
                else
                {
                    per = (int)who->query_lowest_level() - max;
                    switch(per)
                    {
                    case 4:  per = 20; break;
                    case 3:  per = 40; break;
                    case 2:  per = 60; break;
                    case 1:  per = 80; break;
                    default: per = 5;  break;
                    }
                }
                if(per == 0) { how = 0; }
                else { how = to_int(how * (per * 0.01)); }
            }
        }
    }
    who->add_exp(how);
    return;
}

int kill_ob(object who, object victim, int which)
{
    object *borg_people, *inven, EWHO, *attackers;
    int i, initiative, k, myinit;
    string *pkill;

    if(!objectp(who)) { return 0; }
    if(!objectp(EWHO = environment(who))) return 0;
    if(!objectp(victim)) { return 0; }
    if (!objectp(environment(victim))) { return 0; }
    if ((base_name(EWHO)=="/d/shadowgate/void") || (base_name(environment(victim)) =="/d/shadowgate/void")) { return 0; }
    if (victim == who) return 0;
    if (!who->ok_to_kill(victim)) { return 0; }

    if (!sizeof(who->query_attackers())) { who->init_attack(); }
    pkill = ({});
    borg_people = (object *)victim->query_attackers();
    if (!borg_people) borg_people = ({});
    if(!(environment(victim)->query_property("arena")) && (!who->query_property("safe arena") || !victim->query_property("safe arena")))
    {
        if(member_array(who, borg_people) == -1)
        {
            if (interactive(who) && interactive(victim) || (victim->is_townsman()) || who->is_townsman())
            {
                    if (!wizardp(who) && !wizardp(victim))
                {
                    if (PO->is_spell())
                    {
                        if(objectp(PO->query_caster()))
                        {
                            if(member_array(PO->query_caster(), borg_people) == -1)
                            {
                                log_file("killers"," ##"+capitalize((PO->query_caster())->query_name())+" "
                                "attacked "+capitalize(who->query_name())+" at "+ctime(time())+".\n");
                                        if (!avatarp(PO->query_caster())) KILLING_D->check_actions(PO->query_caster(),who);
                            }
                        }
                        else
                        {
                            log_file("killers"," ##"+capitalize(who->query_name())+" attacked "
                            ""+capitalize(victim->query_name())+".\n");
                                    if (!avatarp(who)) KILLING_D->check_actions(who, victim);
                            }
                        }
                    else
                    {
                            log_file("killers","  ##"+capitalize(who->query_name())+" attacked "
                        ""+capitalize(victim->query_name())+".\n");
                        if (!avatarp(who)) KILLING_D->check_actions(who,victim);
                        }
                }
            }
        }
    }
    if(objectp(victim)) { victim->check_death(); }
    if(interactive(who) && !userp(victim))
    {
        inven = all_inventory(EWHO);
        inven = filter_array(inven,"classic_swarm",FILTERS_D);
        for(i=0;i<sizeof(inven);i++)
        {
            if(!objectp(inven[i])) { continue; }
            inven[i]->add_attacker(who);
            EWHO->add_combatant(inven[i]);
            continue;
        }
    }

    /* changed from 0 to 1 to faciliate PK patch */
    if(who->query_attacked()) { return 1; }
    attackers = who->query_attackers();
    i = member_array(victim, attackers);
    if ((i == -1) && (!which))
    {
        // roll surprise and stuff
        // assume we won
        myinit = who->query_initiative();
        if((string)who->query_race() == "human" && (string)who->query("subrace") == "tsarven") myinit -= 1;
        if (myinit < (int)victim->query_initiative())
        {
            who->set_toattack(2);
            victim->set_toattack(4);
        }
        else
        {
            who->set_attack(4);
            victim->set_toattack(2);
        }
        victim->add_attacker(who);
        EWHO->add_combatant(victim);
    }
    if (i > -1)
    {
        //tell_object(who, "You are already attacking "+victim->QCN+"!\n"); // don't really need this, it looks funny when some feats use it.
        return 1;
    }
    who->add_attacker(victim);
    EWHO->add_combatant(who);
    who->adjust_combat_mapps("vars", "any attack", 1);
    return 1;
}

int valid_object(object ob)
{
    if(!objectp(ob)) return 0;
    return 1;
}

int clean_up_attackers(object who)
{
    object *hunters_tmp=({}), *attackers_tmp=({}), *full_tmp, ob, *uncon_att=({}), EWHO;
    int i, tmp;
    string *pkillsatt, *pkillsvic, *atnames;

    if (!objectp(who)) return 0;
    if (!objectp(EWHO = environment(who))) return 0;

    full_tmp = who->query_combat_mapps("arrays", "hunters") + who->query_combat_mapps("arrays", "attackers");
    atnames = who->query_combat_mapps("arrays", "atnames");

    if (interactive(who))
    {
        pkillsatt = who->query_pkilled();
        if (!pointerp(pkillsatt)) pkillsatt = ({});
    }
    for (i=0, tmp = sizeof(full_tmp); i<tmp; i++)
    {
        if (full_tmp[i] == who || !objectp(full_tmp[i])) continue;
        if (member_array(full_tmp[i], (attackers_tmp+hunters_tmp)) != -1) continue;
        if (!objectp(environment(full_tmp[i]))) continue;
        if (environment(full_tmp[i]) != EWHO)
        {
            if (interactive(who) && interactive(full_tmp[i])) continue;
            hunters_tmp += ({ full_tmp[i]});
            continue;
        }
        if (full_tmp[i]->query_ghost())
        {
            atnames-=({full_tmp[i]->query_name()});
            continue;
        }
        if (interactive(full_tmp[i]) && interactive(who))
        {
            pkillsvic = full_tmp[i]->query_pkilled();
            if (!pointerp(pkillsvic)) pkillsvic = ({});
            if (member_array(full_tmp[i]->query_name(),pkillsatt) != -1)
                pkillsatt = pkillsatt + ({full_tmp[i]->query_name()});
            if (member_array(who->query_name(),pkillsvic) != -1)
                pkillsvic = pkillsvic + ({who->query_name()});
        }
        if (!full_tmp[i]->query_bound() && !full_tmp[i]->query_unconscious())
        {
            attackers_tmp += who->doProtection(full_tmp[i]);
        }
        else
        {
            uncon_att += ({full_tmp[i]});
        }
    }

    if (!userp(who) && !EWHO->query_property("arena"))
    {
        for (i=0, tmp = sizeof(atnames); i<tmp; i++)
        {
            if (ob=present(atnames[i],EWHO))
                attackers_tmp += ({ob});
            continue;
        }
    }

    if (sizeof(attackers_tmp) == 0)
    {
        for (i=0, tmp = sizeof(uncon_att); i<tmp; i++)
        {
            attackers_tmp += who->doProtection(uncon_att[i]);
        }
    }
    attackers_tmp = distinct_array(attackers_tmp);

    attackers_tmp -= ({ 0 });
    attackers_tmp = filter_array(attackers_tmp, "valid_object", TO);
    hunters_tmp -= ({ 0 });
    for(i = 0;i < sizeof(attackers_tmp);i++)
    {

    }
    who->adjust_combat_mapps("arrays", "attackers", attackers_tmp);
    who->adjust_combat_mapps("arrays", "hunters", hunters_tmp);
    who->adjust_combat_mapps("vars", "any attack", sizeof(attackers_tmp));
    who->adjust_combat_mapps("static vars", "hunting", sizeof(hunters_tmp));
    return who->query_combat_mapps("vars", "any attack");
}
