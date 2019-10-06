#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

void create()
{
    ::create();

    set_attack_limbs( ({ "right hand","left hand" }) );
    set_new_damage_type("piercing");
    set_attack_functions( ([ "right hand" : (:TO,"claw_attack":), "left hand" : (:TO,"claw_attack":),]));
    set_base_attack_num(4);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("vampyr");
    set_shape_profile("vampire_wassail_999");
    set_shape_bonus("perception",6);
    set_shape_bonus("survival",6);
    set_shape_bonus("stealth",6);
    set_shape_bonus("sight bonus",6);
    set_shape_bonus("strength",6);
    set_shape_bonus("dexterity",4);
    set_shape_bonus("intelligence",2);
    set_shape_bonus("wisdom",2);
    set_shape_bonus("charisma",4);
    set_shape_bonus("empowered",6);

    set_ac_bonus(-6);

    set_shape_bonus("fire resistance",-100);
    set_shape_bonus("silver resistance",-100);
}

int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description(" has vaguely humanoid body, with long limbs, gray skin. Its face is disfigured and longer that of humanoid, with large bat-like ears. Its eyes are glowing red. It is trailed by large bat-like wings, however they don't flap as it floats. Its hands end with razor-sharp claws.");

    obj->setDescriptivePhrase("$R");

    obj->force_me("message floats in");
    obj->force_me("message floats to the $D");

    return 1;
}

int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RED%^You fall onto your knees, feeling hunger filling your mind...");
    tell_object(obj,"%^RED%^You close your eyes... Bloodlust fills your mind...");
    tell_object(obj,"%^RED%^There is no escape from it now...");
    tell_object(obj,"%^RED%^It is time to hunt...");
    tell_object(obj,"%^RED%^%^BOLD%^You are in wassail.");

    tell_room(environment(obj),"%^RED%^Suddenly "+obj->QCN+" drops to "+obj->QP+" his knees, eyes closed.",obj);
    tell_room(environment(obj),"%^RED%^"+obj->QCN+" wavers a little, then its limbs start to grow, "+obj->QP+" skin turns gray, wings grow from the back.",obj);
    tell_room(environment(obj),"%^RED%^"+obj->QCN+" opens the eyes. There is supernatural hunger in them.",obj);
    tell_room(environment(obj),"%^RED%^%^BOLD%^"+obj->QCN+" is now a vampyr in wassail.",obj);
    return 1;
}

int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^Your hunger recedes and you regain your kith appearance.");
    tell_object(obj,"%^RESET%^%^BOLD%^You are no longer in wassail.");

    tell_room(environment(obj),"%^BOLD%^%^RED%^"+obj->QCN+" 's skin turns to normal, its body shrinks and "+obj->QS+" turns to normal.",obj);
    return 1;
}

int claw_attack(object tp, object targ)
{
        tell_object(tp,"%^BOLD%^%^RED%^You furiously claw "+targ->QCN+"!");
        tell_object(targ,"%^BOLD%^%^RED%^"+tp->QCN+" furiously claws you!");
        tell_room(ENV(tp),"%^BOLD%^%^RED%^"+tp->QCN+" furiously claws "+targ->QCN+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(1,12),"slashing");
        tp->cause_typed_damage(tp,"torso",-roll_dice(1,18),"negative energy");
}

int can_cast()
{
    return 1;
}
