#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SHAPESHIFT;

#include "mage_shapes.h"

int clevel;

string element, elemname;
mapping elementmap;
elementmap = ([
                  "fire":"%^RESET%^%^ORANGE%^e%^RESET%^a%^ORANGE%^r%^YELLOW%^t%^RESET%^%^ORANGE%^h",
                  "air":"%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^r",
                  "earth":"%^RESET%^%^ORANGE%^e%^RESET%^a%^ORANGE%^r%^YELLOW%^t%^RESET%^%^ORANGE%^h",
                  "water":"%^BOLD%^%^BLUE%^w%^CYAN%^a%^WHITE%^t%^CYAN%^e%^BLUE%^r"
                  ]);

void set_clevel(int x)
{
    clevel = x;
}

void set_element(string arg)
{
    elemname = arg;
    element = elementmap[elemname];
}

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "right hand","left hand"}) );
    set_new_damage_type("bludgeoning");
    set_limbs( ({ "head","torso","right arm", "left arm" }) );
    set_attack_functions(([ "right arm" : (:TO,"shape_attack":), "left arm" : (:TO,"shape_attack":) ]));
    set_base_attack_num(2);
    set_castable(1);
    set_can_talk(1);

    set_shape_race("elemental");
    set_shape_bonus("sight bonus",3);

    set_shape_height(144);
}

string * query_subraces() {
    return ({ "elemental" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("%^RESET%^Standing over twelve feet tall, this vaguely humanoid shape "
       "is composed entirely of "+element+"%^RESET%^.  It attacks much "
       "as a human would, but its body is crafted from strands of "
       ""+element+" %^RESET%^that seem to shift and move, adjusting "
       "to the movements of the creature.  Its eyes are filled with "
       ""+element+"%^RESET%^, and a menacing purpose seems to lurk "
       "within those depths.");

    obj->setDescriptivePhrase("%^RESET%^"+element+"%^RESET%^ $R");

    obj->set("speech string","reverb");
    obj->set("describe string","eerly");

    obj->force_me("message in floats in");
    obj->force_me("message out floats $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^You turn your mind elsewhere.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BLUE%^Your shift, embracing your new elemental body.");
    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands an elemental!",obj);
    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus, releasing the elements.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing elemental infusion!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    return 1;
}

int can_cast()
{
    return 1;
}

int shape_attack(object tp, object target)
{
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The %^RESET%^"+element+" elemental %^RESET%^%^YELLOW%^moves pummels you with %^RESET%^"+element+"%^RESET%^%^YELLOW%^!");
    tell_room(ENV(tp),"%^YELLOW%^The %^RESET%^"+element+" elemental %^RESET%^%^YELLOW%^moves pummels "+target->QCN+" with %^RESET%^"+element+"%^RESET%^%^YELLOW%^!",target);
    target->do_damage("torso",random(70)+clevel);
    return roll_dice(2,6);
}

int init_shape(object obj,string myelement)
{
    string *subraces;
    set_element(myelement);
    if(!objectp(obj))
        return 0;
    if(obj->query_property("shapeshifted") || obj->query_property("altered"))
        return 0;
    obj->set_property("shapeshifted",shape = new(base_name(TO)+".c"));
    shape->set_owner(obj);
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->apply_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    shape->set_old_attack_limbs((string*)obj->query_attack_limbs());
    obj->set_attack_limbs(shape->query_attack_limbs());
    obj->set_hit_funcs(shape->query_attack_functions());
    obj->set_fake_limbs(shape->query_limbs());
    shape->set_old_damage_type(obj->query_base_damage_type());
    shape->change_into_message(obj);
    shape->set_base_profile("mage_"+elemname+"_elemental_999");
    obj->set("relationship_profile",shape->query_shape_profile());
    obj->add_id(shape->query_shape_race());

    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D);
        if(!desc->restore_profile_settings(obj,shape->query_shape_profile()))
        {
            shape->default_descriptions(obj);
            desc->initialize_profile(obj);
        }
    }

    return 1;
}


varargs int reverse_shape(object obj,int silent)
{
    string *subraces;
    if(!objectp(obj))
        return 3;
    if(!objectp(shape = obj->query_property("shapeshifted")))
        return 5;
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->reverse_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    obj->set_attack_limbs(shape->query_old_attack_limbs());
    obj->set_hit_funcs( ([]) );
    obj->remove_fake_limbs();
    obj->set("relationship_profile",shape->query_base_profile());
    obj->remove_id(shape->query_shape_race());
    obj->set_base_damage_type(shape->query_old_damage_type());
    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D);
        desc->restore_profile_settings(obj,shape->query_base_profile());
    }
    if(!silent) shape->change_outof_message(obj);
    shape->set_owner(0);
    obj->remove_property("shapeshifted");
    clean_me = 1;
    destruct(TO);
    return 1;
}
