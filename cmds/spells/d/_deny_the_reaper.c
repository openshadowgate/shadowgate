#include <std.h>
#include <spell.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("deny the reaper");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS deny the reaper on TARGET (dead player's name)");
    set_description("This spell will send out necromantic energies to snatch a dead person away from the afterlife. The deceased will be returned to the site of death and revived. A successfully revived person will be barely alive and need significant healing, due to the strain of being dragged away from death's embrace, and will still be weakened by the touch of death despite their restoration.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
     // school specific mage spell
    set_components(([ "mage" : ([ "diamond dust" : 1, "drop of blood" : 1, ]), ]));
    set_helpful_spell(1);
}


void spell_effect(int prof)
{
    string what;
    object corpse;
    object targ;

    ::spell_effect();

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!arg)
    {
        tell_object(caster,"syntax: cast CLASS deny the reaper on TARGET");
        dest_effect();
        return;
    }

    what = "corpse of $&$"+caster->realName(lower_case(arg))+"$&$";
    targ = find_player(caster->realName(lower_case(arg)));

    if(!targ)
    {
        tell_object(caster,"You can only revive interactive players.");
        dest_effect();
        return;
    }

    if(!interactive(targ))
    {
        tell_object(caster,"You can only revive interactive players.");
        dest_effect();
        return;
    }

    if((string)TO->query_spell_type() != "potion")
    {
        if (interactive(caster) )
        {
            tell_object(caster, "%^BLUE%^You send out tendrils of necromantic energy, attempting to ensnare "+capitalize(arg)+"'s soul.%^RESET%^");
            tell_room(environment(CASTER),"%^BLUE%^"+caster->QCN+" spreads "+caster->QP+" fingers and voices an unsettling chant over the body of "+capitalize(arg)+".%^RESET%^", ({CASTER,TARGET}));
        }
        else
        {
            set_cast_string("%^BLUE%^"+caster->QCN+" spreads "+caster->QP+" fingers and voices an unsettling chant over the body of "+capitalize(arg)+".%^RESET%^\n");
        }
    }

    if (!targ->query_ghost())
    {
        tell_object(caster,capitalize(arg)+" does not need to be revived.");
        dest_effect();
        return;
    }

    if(!corpse = present(what,environment(caster)))
    {
        tell_object(caster,capitalize(arg)+"'s corpse is not here.");
        tell_object(targ,"You think you feel a faint pull on your soul, but it is gone as soon as it begins.");
        dest_effect();
        return;
    }

    tell_object(caster,"%^CYAN%^You feel the power of your spellcraft contact the familiar energies of "
        +targ->QCN+"'s soul, and know that "+targ->QP+" life is in "+targ->QP+" own hands now.%^RESET%^");

    tell_room(environment(caster),"%^CYAN%^The power of "+caster->QCN+"'s spell flows through the area as "+caster->QS+" "
        "tries to bring "+targ->QCN+" back to life!%^RESET%^",caster);

    targ->set("RaisingPriestGod","an unknown");
    targ->set("RaisingPriestAlignment",10);
    targ->set("RaisingRoom",base_name(environment(caster)));
    targ->set("RaisingExpLoss",0);
    targ->set("RaisingType","deny the reaper");

    tell_object(targ,"%^RESET%^%^B_CYAN%^You can feel a pull on your soul.  You sense "
        "tendrils of arcane energy trying to steal you away from the afterlife!\n"
        "Type <accept> to return to life, or <cancel> to leave your fate in Lysara's "
        "hands.%^RESET%^");

    if(objectp(corpse)) corpse->remove();
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
