#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SHAPESHIFT;

int breath_timer,death_timer,wing_timer,claw_timer,tail_timer;

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "maw","right claw","left claw","tail" }) );
    set_new_damage_type("piercing");    
    set_limbs( ({ "maw","head","torso","right claw", "left claw", "right arm","right arm","left leg","left rear claw","right leg","right rear claw","tail","right wing","left wing" }) );
    set_attack_functions(([ "maw" : (:TO,"bite_attack":), "right claw" : (:TO,"claw_attack":), "left claw" : (:TO,"claw_attack":), "tail" : (:TO,"tail_attack":) ]));
    set_ac_bonus(-5); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(2); 
    set_castable(0);
    set_can_talk(0);
    set_shape_race("dragon");
    set_shape_language("sylvan");
    set_shape_profile("druid_dragon_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_bonus("perception",2);
    set_shape_bonus("survival",4);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",3);
    set_shape_bonus("attack bonus",3);
    set_shape_bonus("damage resistance",10);
    set_shape_bonus("magic resistance",10);
    set_shape_height(200+random(100));
    set_shape_weight(11000+random(5000));
    set_shape_mastery_feat("impale");
}

string * query_subraces() {
    return ({ "dragon" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("stands tall and deadly, covered in iron-hard scales from "+obj->QP+" horn "
        "covered head to "+obj->QP+" long tail.  A ridge of spines runs all the way down "+obj->QP+" back.  "
        ""+obj->QP+" are folded at "+obj->QP+" sides.  "+obj->QS+"'s clawed hands are easily the size of "
        "an ogre's fists.  Keenly intelligent eyes peer out at the world with deadly intent.");

    obj->setDescriptivePhrase("deadly $G $R");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in lumbers in");
    obj->force_me("message out lumbers off to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BLUE%^Your senses heighten, you can feel the pulse of the world, smell countless scents, "
        "you can taste the very air.  You feel centuries of intelligence pouring into your essence and feel the sensation "
        "of invulnerability as iron-hard scales cover your entire form.  You flap your wings and roar.  You are DRAGON!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands a DRAGON!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel a tinge of remose as you feel your draconic form slipping away.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing scales!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    
    return 1;
}

int can_cast() 
{ 
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells; 
}

int bite_attack(object tp, object targ)
{
    object etp,*attackers,att,head;
    string *specials=({}),*active_specials=({}),my_limb;
    int i,j,chance,dice;
 
    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();    
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }

    chance = (int)tp->query_guild_level("druid");

    if(chance > 60) { chance = 60; }
    if(chance > 25 && !FEATS_D->usable_feat(TP,"savage instincts ii")) { chance = 25; }
    if(chance > 15 && !FEATS_D->usable_feat(TP,"savage instincts i")) { chance = 15; }

    dice = ( chance / 3) + 2;
    
    if(FEATS_D->usable_feat(tp,"perfect predator")) 
    { 
        dice += 3; 
        tp->add_hp((dice*3)/2);
    }

    if(roll_dice(1,100) > chance) { return roll_dice(dice,3); }
    

    // breath weapon, bite attack, death bite, high damage, stun, heal

    // switch falls through intentionally 
    switch(chance)
    {
        case 35..60: specials += ({ "breath weapon" });
        case 30..34: specials += ({ "heal" });
        case 25..29: specials += ({ "death bite" });
        case 20..24: specials += ({ "high damage" });
        case 15..19: specials += ({ "stun" });
        case 10..14: specials += ({ "high damage" });
        default:     specials += ({ "breath weapon"  });
    }

    //////////////
    i=0;

    do
    {
        active_specials += ({ specials[random(sizeof(specials))] });
        i += 5;
    }
    while(roll_dice(1,100) < (chance - i));
    //////////////


    for(i=0;i<sizeof(active_specials);i++)
    {
        if(!objectp(tp) || !objectp(targ)) { return 0; }

        switch(active_specials[i])
        {

        case "breath weapon":

            if(time() > breath_timer)
            {
                breath_timer = time() + (ROUND_LENGTH * 35);

                tell_object(tp,"%^ORANGE%^You inhale a deep breath of air, feeling the spark of ignition deep inside of you!");
                tell_room(etp,"%^ORANGE%^"+tp->QCN+"'s chest swells with a deep breath of air!",tp);
                tell_object(tp,"%^RED%^You open your mouth and unleash the fury of dragon fire on your foes!");
                tell_room(etp,"%^RED%^"+tp->QCN+"'s mouth opens and a withering torrent of fire pours forth!",tp);

                for(j=0;j<sizeof(attackers);j++)
                {
                    if(!objectp(att = attackers[j])) { continue; }

                    if(!att->reflex_save(chance))
                    {
                        tell_object(tp,"%^BOLD%^%^RED%^"+att->QCN+" is seared horribly by the flames!");
                        tell_object(att,"%^BOLD%^%^RED%^You are seared horribly by the flames!");
                        tell_room(etp,"%^BOLD%^%^RED%^"+att->QCN+" is seared horribly by the flames!",({tp,att}));
                    
                        att->cause_typed_damage(att,att->return_target_limb(),roll_dice(chance,dice),"fire");
                    }
                    else
                    {
                        tell_object(tp,"%^MAGENTA%^"+att->QCN+" is able to dive away at the last instant, avoiding most of the flames!");
                        tell_object(att,"%^MAGENTA%^You dive away at the last instant, avoiding most of the flames!");
                        tell_room(etp,"%^MAGENTA%^"+att->QCN+" dives away at the last instant, avoiding most of the flames!",({tp,att}));

                        att->cause_typed_damage(att,att->return_target_limb(),roll_dice(chance,dice)/2,"fire");
                    }
                }
                break;     
            } // should fall through if timer isn't up


        case "death bite":

            if(time() > death_timer)
            {
                if(!targ->query_property("no death"))
                {
                    death_timer = time() + (ROUND_LENGTH * 10);
                    head = new("/std/obj/body_part.c");
                    head->set_limb(targ->query("short"),"head");
                    head->move(etp);

                    tell_object(tp,"%^BOLD%^%^BLUE%^You clamp your razor-like jaws onto "+targ->QCN+"'s head and grab onto "+targ->QO+" with both powerful clawed fists!");
                    tell_object(targ,"%^BOLD%^%^BLUE%^"+tp->QCN+" clamps "+tp->QP+" jaws onto your head and grabs your body in "+tp->QP+" powerful claws!");
                    tell_room(etp,"%^BOLD%^%^BLUE%^"+tp->QCN+" clamps "+tp->QP+" jaws onto "+targ->QCN+"'s head and grabs "+targ->QP+" body in "+tp->QP+" powerful claws!",({tp,targ}));

                    tell_object(tp,"%^RESET%^%^BOLD%^With a mighty heave, you draw your muscular neck back.  You can hear the sound of popping tendons and cracking bones as you %^RED%^pull "
                        ""+targ->QCN+"'s head free of "+targ->QP+" neck%^RESET%^%^BOLD%^!");
                    tell_object(targ,"%^RESET%^%^BOLD%^You realize in horror as "+tp->QCN+" begins to wrench "+tp->QP+" neck back, that there's nothing you can do!");
                    tell_object(targ,"%^RESET%^%^BOLD%^%^RED%^You feel incredible agony in your neck as your spine breaks, and then the world fades into blackness, your life snuffed out!");
                    tell_room(etp,"%^RESET%^%^BOLD%^You can hear the sound of popping tendons and cracking bones as "+tp->QCN+" draws "+tp->QP+" powerful neck back, %^RED%^pulling "+targ->QCN+"'s "
                        "head off of "+targ->QP+" shoulders!%^RESET%^",({tp,targ}));               
                    
                    tell_object(tp,"%^RESET%^%^BOLD%^%^GREEN%^You toss "+targ->QCN+"'s lifeless body aside and crunch the head one final time before spitting it onto the ground!");
                    tell_room(etp,"%^RESET%^%^BOLD%^%^GREEN%^"+tp->QCN+" tosses "+targ->QCN+"'s lifeless body aside and crunches "+targ->QP+" head before spitting it out on the ground!",({tp,targ}));

                    targ->cause_typed_damage(targ,targ->return_target_limb(),targ->query_max_hp()+400,"untyped");
                    targ->die();
                }
                else
                {
                    tell_object(tp,"%^BLUE%^You snap your powerful jaws down at "+targ->QCN+"'s head, but "+targ->QS+" dodges aside at the last instant, you hit "+targ->QP+" shoulder instead!");
                    tell_object(targ,"%^BLUE%^"+tp->QCN+" snaps "+tp->QP+" powerful jaws down at your head but you dodge aside at the last instant and "+tp->QS+" hits your shoulder instead!");
                    tell_room(etp,"%^BLUE%^"+tp->QCN+" snaps "+tp->QP+" powerful jaws down at "+targ->QCN+"'s head, but "+targ->QS+" dodges aside at the last instant and "+tp->QS+" hits "+targ->QP+" shoulder instead!",({tp,targ}));
                   
                    targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,6),get_new_damage_type());                    
                }

                break;
            } // should fall thorugh if timer isn't up


        case "high damage":

            tell_object(tp,"%^RED%^You snake your neck around lightning quick and bite deeply into "+targ->QCN+"'s "+(my_limb=targ->return_target_limb())+"!");
            tell_object(targ,"%^RED%^"+tp->QCN+" snakes "+tp->QP+" head around lightning quick and bites deeply into your "+my_limb+"!");
            tell_room(etp,"%^RED%^"+tp->QCN+" snakes "+tp->QP+" head around lightning quick and bites deeply into "+targ->QCN+"'s "+my_limb+"!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,6),get_new_damage_type());
            break;


        case "heal":

            tell_object(tp,"%^CYAN%^You bite into "+targ->QCN+"'s flank and feel some of "+targ->QP+" life force tranferred to you!");
            tell_object(targ,"%^CYAN%^"+tp->QCN+" bites into your flank!");
            tell_room(etp,"%^CYAN%^"+tp->QCN+" bites into "+targ->QCN+" and looks revitalized!",({tp,targ}));

            tp->do_damage(tp->return_target_limb(),roll_dice(dice,3)*-1);
            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,3),get_new_damage_type());
            break;
            

        case "stun":

            tell_object(tp,"%^YELLOW%^You quickly snap the top of your head up against "+targ->QCN+"'s face, knocking "+targ->QS+" senseless!");
            tell_object(targ,"%^YELLOW%^"+tp->QCN+" snaps "+tp->QP+" head up against your face, knocking you senseless!");
            tell_room(etp,"%^YELLOW%^"+tp->QCN+" snaps "+tp->QP+" head up against "+targ->QCN+"'s face, knocking "+targ->QO+" senseless!",({tp,targ}));

            targ->set_paralyzed(roll_dice(1,dice/2),"%^RESET%^%^YELLOW%^You are trying to recover your senses!");
            break;

        }
    }

    return roll_dice(2,dice);
}




int claw_attack(object tp, object targ)
{
    object etp,*attackers,att;
    string *specials=({}),*active_specials=({});
    int i,j,chance,dice;
 
    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();
    attackers = distinct_array(attackers);
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }

    chance = (int)tp->query_guild_level("druid");

    if(chance > 60) { chance = 60; }
    if(chance > 25 && !FEATS_D->usable_feat(TP,"savage instincts ii")) { chance = 25; }
    if(chance > 15 && !FEATS_D->usable_feat(TP,"savage instincts i")) { chance = 15; }

    dice = ( chance / 4) + 2;

    if(roll_dice(1,100) > chance) { return roll_dice(dice,3); }
    
    // switch falls through intentionally 
    switch(chance)
    {
        case 35..60: specials += ({ "wing buffet" });
        case 30..34: specials += ({ "claw swipe" });
        case 25..29: specials += ({ "claw death" });
        case 20..24: specials += ({ "wing buffet" });
        case 15..19: specials += ({ "wing buffet" });
        case 10..14: specials += ({ "claw swipe" });
        default:     specials += ({ "claw attack"  });
    }

    //////////////
    i=0;

    do
    {
        active_specials += ({ specials[random(sizeof(specials))] });
        i += 5;
    }
    while(roll_dice(1,100) < (chance - i));
    //////////////


    for(i=0;i<sizeof(active_specials);i++)
    {
        if(!objectp(tp) || !objectp(targ)) { return 0; }

        switch(active_specials[i])
        {

        case "wing buffet":

            if(time() > wing_timer)
            {
                wing_timer = time() + (ROUND_LENGTH * 25);

                tell_object(tp,"%^RESET%^%^BLUE%^You heave yourself into the air with a great flap of your wings, furiously buffeting your enemies with air!");
                tell_room(etp,"%^RESET%^%^BLUE%^"+tp->QCN+" heaves "+tp->QO+"self up into the air with a great flap of "+tp->QP+" wings, furiously butteting the area with air!",tp);

                for(j=0;j<sizeof(attackers);j++)
                {
                    if(!objectp(att = attackers[j])) { continue; }

                    if(!att->reflex_save(chance))                     
                    {
                        tell_object(tp,"%^GREEN%^The wind from your beating wings knocks "+att->QCN+" off of "+att->QP+" feet!");
                        tell_object(att,"%^GREEN%^The wind from "+tp->QCN+"'s beating wings knocks you off of your feet!");
                        tell_room(etp,"%^GREEN%^The wind from "+tp->QCN+"'s beating wings knocks "+att->QCN+" off of "+att->QP+" feet!",({tp,att}));

                        att->set_tripped(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); 
                    }
                    else
                    {
                        tell_object(tp,"%^BOLD%^%^GREEN%^"+att->QCN+" manages to withstand the assault of the winds and retains "+att->QP+" footing!");
                        tell_object(att,"%^BOLD%^%^GREEN%^You manage to withstand the assault from the winds and keep your footing!");
                        tell_room(etp,"%^BOLD%^%^GREEN%^"+att->QCN+" manages to withstand the assault from the winds and keeps "+att->QP+" footing!",({tp,att}));
                    }
                }                
                break;
            } // falls through if timer isn't up
            

        case "claw death":

            if(time() > claw_timer)
            {
                if(!targ->query_property("no death"))
                {
                    claw_timer = time() + (ROUND_LENGTH * 15);

                    tell_object(tp,"%^RED%^You throw your head back and roar with draconic rage!");
                    tell_room(etp,"%^RED%^"+tp->QCN+" throws "+tp->QP+" head back and roars with a draconic rage!",tp);

                    tell_object(tp,"%^BOLD%^%^RED%^Your whole body surges as your put your entire weight behind single, cataclysmic strike at "+targ->QCN+"!");
                    tell_object(targ,"%^BOLD%^%^RED%^"+tp->QCN+"'s whole body surges as "+tp->QS+" puts "+tp->QP+" entire weight behind a single, cataclysmic strike, aimed at you!");
                    tell_room(etp,"%^BOLD%^%^RED%^"+tp->QCN+"'s whole body surges as "+tp->QS+" puts "+tp->QP+" entire weight being a single cataclysmic strike, aimed at "+targ->QCN+"!",({tp,targ}));

                    tell_object(tp,"%^BOLD%^%^BLUE%^Your claw smashes into "+targ->QCN+" with almost unimaginable force, crushing "+targ->QP+" midsection and nearly breaking "+targ->QO+" in half!");
                    tell_object(targ,"%^BOLD%^%^BLUE%^"+tp->QCN+"'s claw smashes into you with almost unimaginable force, crushing your middle and almost breaking you in half!");
                    tell_room(etp,"%^BOLD%^%^BLUE%^"+tp->QCN+"'s claw smashes into "+targ->QCN+" with almost unimaginable force, crushing "+targ->QP+" midsection and almost breaking "+targ->QO+" in half!",({tp,targ}));

                    tell_object(tp,"%^BOLD%^%^BLACK%^You watch as "+targ->QCN+" staggers back and then collapses straight to the ground, suddering one final time and then falling motionless into death's embrace.");
                    tell_object(targ,"%^BOLD%^%^BLACK%^You stagger backwards, your insides destroyed.  You feel yourself slipping away as the ground rushes up to meet you.  Blackness overcomes you as you enter the embrace of the afterlife.");
                    tell_room(etp,"%^BOLD%^%^BLACK%^You watch as "+targ->QCN+" staggers back and then collapses straight to the ground, suddering one final time and then falling motionless into death's embrace.",({tp,targ}));

                    targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(chance*10,chance*10),"untyped");
                    targ->die();
                }
                else
                {
                    tell_object(tp,"%^BOLD%^%^RED%^You roar with draconic rage and quickly strike "+targ->QCN+" with both mightly claws!");
                    tell_object(targ,"%^BOLD%^%^RED%^"+tp->QCN+" roars with draconic rage and quickly strikes you twice in rapid succession!");
                    tell_room(etp,"%^BOLD%^%^RED%^"+tp->QCN+" roars with draconic rage and quickly strikes "+targ->QCN+" twice in rappid succession!",({tp,targ}));
                   
                    targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,3),get_new_damage_type());
                    tp->execute_attack();
                }
            } // falls through if timer isn't up
            
            break;

        case "claw attack":

            tell_object(tp,"%^RED%^You reach out and violently claw "+targ->QCN+"!");
            tell_object(targ,"%^RED%^"+tp->QCN+" reaches out and violently claws you!");
            tell_room(etp,"%^RED%^"+tp->QCN+" reaches out and violently claws "+targ->QCN+"!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,3),get_new_damage_type());

            break;

        case "claw swipe":

            tell_object(tp,"%^BOLD%^%^GREEN%^You rake your large claw across, swiping a large arc at your enemies!");
            tell_room(etp,"%^BOLD%^%^GREEN%^"+tp->QCN+" rakes "+tp->QP+" large claw in a wide arc, striking at "+tp->QP+" enemies!",tp);

            for(j=0;j<sizeof(attackers);j++)
            {
                if(!objectp(att = attackers[j])) { continue; }

                if(!att->reflex_save(chance - 10))
                {
                    tell_object(att,"%^BOLD%^"+tp->QCN+"'s claw strikes you on the way by!");
                    
                    att->cause_typed_damage(att,att->return_target_limb(),roll_dice(dice,3),get_new_damage_type());
                }
                else
                {
                    tell_object(att,"%^ORANGE%^"+tp->QCN+"'s claw narrowly misses you!");
                }
            }
            break;
        }
    }

    return roll_dice(dice,3);
}


int tail_attack(object tp, object targ)
{
    object etp,*attackers,att;
    string *specials=({}),*active_specials=({});
    int i,j,chance,dice;
 
    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();    
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }

    chance = (int)tp->query_guild_level("druid");

    if(chance > 60) { chance = 60; }
    if(chance > 25 && !FEATS_D->usable_feat(TP,"savage instincts ii")) { chance = 25; }
    if(chance > 15 && !FEATS_D->usable_feat(TP,"savage instincts i")) { chance = 15; }

    dice = ( chance / 4) + 2;

    if(roll_dice(1,100) > chance) { return roll_dice(dice,3); }
    
    // switch falls through intentionally 
    switch(chance)
    {
        case 35..60: specials += ({ "tail swipe" });
        case 30..34: specials += ({ "tail impale" });
        case 25..29: specials += ({ "tail attack" });
        case 20..24: specials += ({ "tail swipe" });
        case 15..19: specials += ({ "tail impale" });
        case 10..14: specials += ({ "tail attack" });
        default:     specials += ({ "tail swipe"  });
    }

    //////////////
    i=0;

    do
    {
        active_specials += ({ specials[random(sizeof(specials))] });
        i += 4;
    }
    while(roll_dice(1,100) < (chance - i));
    //////////////
    

    for(i=0;i<sizeof(active_specials);i++)
    {
        if(!objectp(tp) || !objectp(targ)) { return 0; }

        switch(active_specials[i])
        {

        case "tail swipe":

            if(time() > tail_timer)
            {
                tail_timer = time() + (ROUND_LENGTH * 12);

                tell_object(tp,"%^ORANGE%^You whip your tail around, trying to sweep the feet from under your enemies!");
                tell_room(etp,"%^ORANGE%^"+tp->QCN+" whips "+tp->QP+" tail around, trying to sweep the feet from under "+tp->QP+" enemies!",tp);

                for(j=0;j<sizeof(attackers);j++)
                {
                    if(!objectp(att = attackers[j])) { continue; }

                    if(!att->reflex_save(chance))                     
                    {
                        tell_object(tp,"%^YELLOW%^You catch "+att->QCN+" with your tail, knocking "+att->QO+" from "+att->QP+" feet!");
                        tell_object(att,"%^YELLOW%^"+tp->QCN+" catches you with "+tp->QP+" tail, knocking you from your feet!");
                        tell_room(etp,"%^YELLOW%^"+tp->QCN+" catches "+att->QCN+" with "+tp->QP+" tail, knocking "+att->QO+" from "+att->QP+" feet!",({tp,att}));

                        att->cause_typed_damage(att,att->return_target_limb(),roll_dice(dice,6),get_new_damage_type());
                        att->set_tripped(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); 
                    }
                    else
                    {
                        tell_object(tp,"%^ORANGE%^Your tail barely misses "+att->QCN+" on the way by!");
                        tell_object(att,"%^ORANGE%^"+tp->QCN+"'s tail barely misses you on the way by!");
                        tell_room(etp,"%^ORANGE%^"+tp->QCN+"'s tail barely misses "+att->QCN+" on the way by!",({tp,att}));
                    }
                }                
                break;
            } // falls through if timer isn't up

        case "tail impale":

            if(sizeof(attackers) > 1)
            {
                att = 0;
                while(!att)
                {
                    att = attackers[random(sizeof(attackers))];
                    if(att == targ) { att = 0; }
                }

                tell_object(tp,"%^MAGENTA%^You twist your body and send the end of your tail out in a straight line, aiming straight at "+targ->QCN+"!");
                tell_object(targ,"%^MAGENTA%^"+tp->QCN+" sends "+tp->QP+" tail straight for you!");
                tell_room(etp,"%^MAGENTA%^"+tp->QCN+" sends "+tp->QP+" tail straight for "+targ->QCN+"!",({tp,targ}));

                tell_object(tp,"%^CYAN%^Your tail drags a ragged gash through "+targ->QCN+"'s side and smashes into "+att->QCN+" behind "+targ->QO+"!");
                tell_object(targ,"%^CYAN%^"+tp->QCN+"'s tail drags a ragged gash through your side and smashes into "+att->QCN+" behind you!");
                tell_room(etp,"%^CYAN%^"+tp->QCN+"'s tail drags a ragged gash through "+targ->QCN+"'s side and smashes into "+att->QCN+" behind "+targ->QO+"!",({tp,targ,att}));

                if(!targ->fort_save(chance)) { targ->set_paralyzed(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You're struggling to move!"); }
                if(!att->fort_save(chance))  { att->set_paralyzed(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You're struggling to move!"); }

                targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,6),get_new_damage_type());
                att->cause_typed_damage(targ,att->return_target_limb(),roll_dice(dice,6),get_new_damage_type());

            }
            else
            {
                tell_object(tp,"%^MAGENTA%^You twist your body and send the end of your tail straight out, aiming for "+targ->QCN+"!");
                tell_object(targ,"%^MAGENTA%^"+tp->QCN+" sends "+tp->QP+" tail straight at you!");
                tell_room(etp,"%^MAGENTA%^"+tp->QCN+" sends "+tp->QP+" tail straight at "+targ->QCN+"!",({tp,targ}));

                tell_object(tp,"%^BOLD%^Your tail drags a deep gash through "+targ->QCN+"'s side!");
                tell_object(targ,"%^BOLD%^"+tp->QCN+"'s tail drags a deep gash through your side!");
                tell_room(etp,"%^BOLD%^"+tp->QCN+"'s tail drags a deep gash through "+targ->QCN+"'s side!",({tp,targ}));

                if(!targ->fort_save(chance)) { targ->set_paralyzed(roll_dice(1,dice),"%^RESET%^%^YELLOW%^You're struggling to move!"); }
                targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,6),get_new_damage_type());
            }

            break;            

        case "tail attack":

            tell_object(tp,"%^RED%^You flick your tail in a wide arc and it smashes into "+targ->QCN+"!");
            tell_object(targ,"%^RED%^"+tp->QCN+" flicks "+tp->QP+" tail in a wide arc and it smashes into you!");
            tell_room(etp,"%^RED%^"+tp->QCN+" flicks "+tp->QP+" tail in a wide arc and it smashes into "+targ->QCN+"!",({tp,targ}));

            targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,6),get_new_damage_type());
            break;

        }
    }

    return roll_dice(dice,3);
}
