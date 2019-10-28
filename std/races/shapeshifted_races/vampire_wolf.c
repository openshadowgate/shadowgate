#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_attack_limbs( ({ "maw" }) );
    set_new_damage_type("piercing");
    set_limbs( ({ "mouth","head","torso","right foreleg","right forepaw","left foreleg","left forepaw","right rear leg","right rear paw","left rear leg","left rear paw","tail" }) );
    set_attack_functions( ([ "maw" : (:TO,"shape_attack":) ]) );
    set_ac_bonus(2);
    set_base_attack_num(2);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("wolf");
    set_shape_profile("vampire_wolf_999");
    set_shape_bonus("perception",2);
    set_shape_bonus("survival",4);
    set_shape_bonus("cold resistance",5);
    set_shape_bonus("sight bonus",3);
    set_shape_height(30+random(12));
    set_shape_weight(90+random(50));
    set_shape_mastery_feat("knockdown");
}

int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is covered from snout to tail in smooth black fur. A maw of razor sharp teeth and keen eyes shows that the wolf is a natural predator in its own environment. Every step it takes reveals lean muscles under the heavy coat of fur.");

    obj->setDescriptivePhrase("lean black $R with intense red eyes");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in trots in quickly");
    obj->force_me("message out darts quickly to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^%^BOLD%^You turn your mind out to the darkness as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^RED%^%^BOLD%^Your senses heighten, you can feel the pulse of the night, smell countless scents, you can taste the very air. You are one with the darkness. You are WOLF!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, is now a large wolf!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^RED%^You relax your focus on the darkness.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your another body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

int init_shape(object obj,string mysubrace)
{
    string *subraces;
    if(!objectp(obj)) { return 0; } //
    if(obj->query_property("shapeshifted") || obj->query_property("altered")) { return 0; } // can't shapeshift twice
    obj->set_property("shapeshifted",shape = new(base_name(TO)+".c")); // makes a new shape and sets the shapeshifted property to it, this is where all the work is done, very important
    shape->set_owner(obj); //
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->apply_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    shape->set_old_attack_limbs((string*)obj->query_attack_limbs()); //
    obj->set_attack_limbs(shape->query_attack_limbs()); //
    obj->set_hit_funcs(shape->query_attack_functions()); //
    obj->set_fake_limbs(shape->query_limbs()); //
    shape->set_old_damage_type(obj->query_base_damage_type()); //
    shape->change_into_message(obj); //
    shape->set_base_profile((string)obj->query("relationship_profile")); //
    shape->set_shape_race(mysubrace); // NEW
    obj->set("relationship_profile",shape->query_shape_profile()); //
    obj->add_id(shape->query_shape_race()); //
    subraces = (string *)shape->query_subraces();
    if(sizeof(subraces)) {
      if(member_array(subraces[0],(string *)obj->query_id()) == -1) obj->add_id(subraces[0]);
    }

    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D); //
        if(!desc->restore_profile_settings(obj,shape->query_shape_profile())) //
        {
            shape->default_descriptions(obj); //
            desc->initialize_profile(obj); //
        }
    }

    return 1;
}


varargs int reverse_shape(object obj,int silent)
{
    string *subraces;
    if(!objectp(obj)) { return 3; } //
    if(!objectp(shape = obj->query_property("shapeshifted"))) { return 5; } //
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->reverse_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    obj->set_attack_limbs(shape->query_old_attack_limbs()); //
    obj->set_hit_funcs( ([]) ); // clears attack functions /*********** may need changed if we give unarmed combat an overhaul for unshifted players ******************/
    obj->remove_fake_limbs(); //
    obj->set("relationship_profile",shape->query_base_profile()); //
    obj->remove_id(shape->query_shape_race()); //
    obj->set_base_damage_type(shape->query_old_damage_type()); //
    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D); //
        desc->restore_profile_settings(obj,shape->query_base_profile()); //
    }
    if(!silent) shape->change_outof_message(obj); //
    shape->set_owner(0); //
    obj->remove_property("shapeshifted"); //
    clean_me = 1; //
    destruct(TO);
    return 1;
}

int can_cast()
{
    return 1;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    object etp;
    string *specials=({});
    int i,chance,dice;

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }

    chance = (int)tp->query_level();

    if(chance > 50) { chance = 50; }

    dice = ( chance / 5) + 2;

    if(roll_dice(1,100) > chance)
        return roll_dice(2,dice);

    specials = ({"heal", "trip", "high damage", "extra attack", "low damage"});
    switch(specials[random(sizeof(specials))])
    {
    case "heal":
        tell_object(tp,"%^RESET%^%^BOLD%^%^CYAN%^You pull on "+targ->QCN+"'s essence with your attack, draining "+targ->QO+" and restoring some of your vital health!");
        tell_object(targ,"%^RESET%^%^RED%^"+tp->QCN+"'s pulls at your essence, leaving you drained!");
        tell_room(etp,"%^RESET%^%^BLUE%^"+tp->QCN+"'s wounds look less severe after "+tp->QS+" attacks "+targ->QCN+"!",({tp,targ}));
        tp->do_damage(tp->return_target_limb(),(dice * -1 * 2));
        targ->cause_typed_damage(targ,targ->return_target_limb(),dice*2,get_new_damage_type());
        break;

    case "trip":
        tell_object(tp,"%^RESET%^%^RED%^You dig your teeth into "+targ->QCN+"'s shoulder and drag "+targ->QO+" to the ground!");
        tell_object(targ,"%^RESET%^%^RED%^"+tp->QCN+" digs "+tp->QP+" teeth into your shoulder and drags you to the ground!");
        tell_room(etp,"%^RESET%^%^RED%^"+tp->QCN+" digs "+tp->QP+" teeth into "+targ->QCN+"'s shoulder and drags "+targ->QO+" to the ground!",({tp,targ}));
        if(!targ->fort_save(chance)) { targ->set_tripped(1,"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); }
        break;

    case "high damage":
        tell_object(tp,"%^RESET%^%^RED%^You snarl angrily and lunge, tearing deeply into "+targ->QCN+"'s flank!");
        tell_object(targ,"%^RESET%^%^RED%^"+tp->QCN+" snarls angrily and lunges, tearing painfully into your side!");
        tell_room(etp,"%^RESET%^%^RED%^"+tp->QCN+" snarls angrily and lunches, tearing deeply into "+targ->QCN+"'s flank!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,4),get_new_damage_type());
        break;

    case "extra attack":
        tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You hit the ground and twist, immediately launching another quick attack at "+targ->QCN+"!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" hits the ground and twists, immediately launching another attack at you!");
        tell_room(etp,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" hits the ground and twists, immediately launching another attack at "+targ->QCN+"!",({tp,targ}));
        tp->execute_attack();
        break;

    case "low damage":
        tell_object(tp,"%^RESET%^%^BOLD%^%^RED%^You quickly snap inside "+targ->QCN+"'s defenses and bite a vulnerable spot!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^RED%^"+tp->QCN+" quickly snaps inside of your defenses and bites you!");
        tell_room(etp,"%^RESET%^%^BOLD%^%^RED%^"+tp->QCN+" quickly snaps inside of "+targ->QCN+"'s defenses and bites "+targ->QO+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,2),get_new_damage_type());
        break;


    }
    return roll_dice(2,dice);
}
