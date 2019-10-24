#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_attack_limbs( ({ "maw" }) );
    set_new_damage_type("piercing");
    set_limbs( ({ "mouth","head","torso","waist ","left arm","left hand","right arm","right hand","left leg","left foor","right leg" ,"right food", "tail", "maw" }) );
    set_attack_functions( ([ "maw" : (:TO,"shape_attack":) ]) );
    set_base_attack_num(4);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("werewolf");
    set_shape_profile("werewolf_hybrid_999");
    set_shape_bonus("perception",2);
    set_shape_bonus("survival",2);
    set_shape_bonus("cold resistance",5);
    set_shape_bonus("silver resistance",-66);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("damage bonus",2);
    set_shape_bonus("attack bonus",2);
}

int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is a strange humanoid with wolfish head that ends in predatory maw. It is covered from head to toe in dark bluesh fur, its gray eyes are full of insane anger.");
    obj->setDescriptivePhrase("lean $R with dark blue fur");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^%^BOLD%^You turn your mind out to the darkness as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^RED%^%^BOLD%^Your senses heighten, you can feel the pulse of the night, smell countless scents, you can taste the very air. You are werewolf!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, is now a werewolf!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^RED%^You relax your focus on the wilds.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your another body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

int can_cast()
{
    return 1;
}


// init_shape(object obj) and reverse_shape(obj) are the core functions, they change into and outof form
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

int shape_attack(object tp, object targ)
{
    object etp,*attackers;
    string *specials=({});
    int i,chance,dice;
    string RND_COLORS = ({"%^BOLD%^%^RED%^","%^RED%^","%^BOLD%^%^BLACK%^","%^BLUE%^"});
    string clr = RND_COLORS[random(sizeof(RND_COLORS))];

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    chance = (int)tp->query_level();

    if(chance > 60) { chance = 60; }

    dice = ( chance / 4) + 2;

    if(roll_dice(1,100) > chance)
        return roll_dice(2,dice);

    specials = ({ "blind",
            "heal",
            "trip",
            "high damage",
            "stun",
            "extra attack",
            "low damage" });

    switch(specials[random(sizeof(specials))])
    {
    case "blind":
        tell_object(tp,"%^RESET%^"+clr+"You leap up and savagely tear at "+targ->QCN+"'s eyes, narrowly missing!");
        tell_object(targ,"%^RESET%^"+clr+tp->QCN+" leaps up and tears at your face, nearly ripping your eyes out!");
        tell_room(etp,"%^RESET%^"+clr+tp->QCN+" leaps up and tears at "+targ->QCN+"'s face, nearly ripping out "+targ->QP+" eyes!",({tp,targ}));
        if(!targ->reflex_save(chance)) { targ->set_temporary_blinded(dice/2); }
        break;

    case "heal":
        tell_object(tp,"%^RESET%^"+clr+"You pull on "+targ->QCN+"'s essence with your attack, draining "+targ->QO+" and restoring some of your vital health!");
        tell_object(targ,"%^RESET%^"+clr+tp->QCN+"'s pulls at your essence, leaving you drained!");
        tell_room(etp,"%^RESET%^"+clr+tp->QCN+"'s wounds look less severe after "+tp->QS+" attacks "+targ->QCN+"!",({tp,targ}));
        tp->do_damage(tp->return_target_limb(),(dice * -1 * 2));
        targ->cause_typed_damage(targ,targ->return_target_limb(),dice*2,get_new_damage_type());
        break;

    case "trip":
        tell_object(tp,"%^RESET%^"+clr+"You dig your teeth into "+targ->QCN+"'s shoulder and drag "+targ->QO+" to the ground!");
        tell_object(targ,"%^RESET%^"+clr+tp->QCN+" digs "+tp->QP+" teeth into your shoulder and drags you to the ground!");
        tell_room(etp,"%^RESET%^"+clr+tp->QCN+" digs "+tp->QP+" teeth into "+targ->QCN+"'s shoulder and drags "+targ->QO+" to the ground!",({tp,targ}));
        if(!targ->fort_save(chance)) { targ->set_tripped(roll_dice(1,2),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); }
        break;

    case "high damage":
        tell_object(tp,"%^RESET%^"+clr+"You snarl angrily and lunge, tearing deeply into "+targ->QCN+"'s flank!");
        tell_object(targ,"%^RESET%^"+clr+tp->QCN+" snarls angrily and lunges, tearing painfully into your side!");
        tell_room(etp,"%^RESET%^"+clr+tp->QCN+" snarls angrily and lunches, tearing deeply into "+targ->QCN+"'s flank!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,4),get_new_damage_type());
        break;

    case "stun":
        if(!random(3)){

            tell_object(tp,"%^RESET%^"+clr+"You lower your head and circle around "+targ->QCN+" before lunging, "
                        "knocking "+targ->QO+" off balance!");
            tell_object(targ,"%^RESET%^"+clr+tp->QCN+" lowers "+tp->QP+" head and circles around you before "
                        "lunging and knocking you off balance and unable to move!");
            tell_room(etp,"%^RESET%^"+clr+tp->QCN+" lowers "+tp->QP+" head and circles around "+targ->QCN+" "
                      "before lunging and knocking "+targ->QO+" off balance!",({tp,targ}));

            targ->set_paralyzed(roll_dice(1,2)*8,"%^RESET%^%^YELLOW%^You're struggling to regain your balance!");
        }
        break;

    case "extra attack":

        tell_object(tp,"%^RESET%^"+clr+"You hit the ground and twist, immediately launching another quick attack at "+targ->QCN+"!");
        tell_object(targ,"%^RESET%^"+clr+tp->QCN+" hits the ground and twists, immediately launching another attack at you!");
        tell_room(etp,"%^RESET%^"+clr+tp->QCN+" hits the ground and twists, immediately launching another attack at "+targ->QCN+"!",({tp,targ}));
        tp->execute_attack();
        break;

    case "low damage":
        tell_object(tp,"%^RESET%^"+clr+"You quickly snap inside "+targ->QCN+"'s defenses and bite a vulnerable spot!");
        tell_object(targ,"%^RESET%^"+clr+tp->QCN+" quickly snaps inside of your defenses and bites you!");
        tell_room(etp,"%^RESET%^"+clr+tp->QCN+" quickly snaps inside of "+targ->QCN+"'s defenses and bites "+targ->QO+"!",({tp,targ}));

        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,2),get_new_damage_type());
        break;
    }

    return roll_dice(2,dice);
}
