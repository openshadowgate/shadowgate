//      Chill Touch
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string target_limb, element;


create()
{
    ::create();
    set_spell_name("polar ray");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS polar ray on TARGET");
    set_damage_desc("cold");
    set_description("A blue-white ray of freezing air and ice springs from casters hand as she touches her target, freezing them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}


string query_cast_string() { return caster->QCN+" utters a deathly chant."; }

spell_effect(int prof)
{
    string mycolor, myhue, myhue2, myfeeling;
    int bonus, roll;

    if(!objectp(caster) || !objectp(target))
    {
        target = 0;
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();

    bonus = 0;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        target = 0;
        dest_effect();
        return;
    }

    mycolor = "%^CYAN%^";
    myhue = "white glowing";
    myhue2 = "white glow";
    myfeeling = "ghastly chill";

    tell_object(caster,"%^BOLD%^"+mycolor+"Your hand starts to develop a "+myhue2+".");
    tell_room(place,"%^BOLD%^"+mycolor+caster->QCN+"'s hand starts to develop a "+myhue2+".",caster );

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(caster,""+mycolor+"You try and touch "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand, but miss!");
        tell_object(target,""+mycolor+caster->QCN+"'s "+myhue+" hand gropes for your "+target_limb+" unsuccessfully.");
        tell_room(place,""+mycolor+caster->QCN+" reaches out for "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand and misses!", ({ caster, target}) );
        target = 0;
        dest_effect();
        return;
    }

    if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target))
    {
        target = 0;
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^"+mycolor+"You reach out and touch "+target->QCN+"'s "+target_limb+" with your "+myhue+" hand.");
    tell_object(target,"%^BOLD%^"+mycolor+caster->QCN+" touches your "+target_limb+" with a "+myhue+" hand.\n%^WHITE%^A "+myfeeling+" runs through you, sapping your strength!");
    tell_room(place,"%^BOLD%^"+mycolor+caster->QCN+" reaches out and touches "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand!\n%^WHITE%^All life and color seems drawn out of the limb!",({ caster, target}) );
    spell_successful();

    damage_targ(target, target_limb, sdamage ,"cold" );
}

void dest_effect()
{
    if(find_call_out("dest_effect") != -1) { remove_call_out("dest_effect"); }
    if(objectp(target))
    {
        stat_change(target,"strength",1);
        target->remove_property_value("spelled", ({TO}) );
        tell_room(environment(target),"%^ORANGE%^"+target->QCN+" loses "+target->QP+" pale complexion.", target);
        tell_object(target,"%^ORANGE%^The skeletal white color in your "+target_limb+" fades away.");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
