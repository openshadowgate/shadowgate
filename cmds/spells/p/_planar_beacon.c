#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
#include <teleport.h>
inherit SPELL;

#define DELAY 300 //5min delay between uses

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("planar beacon");
    set_spell_level(([ "mage" : 9, "cleric" : 9]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS planar beacon on TARGET");
    set_description("This spell pinpoints a foe, regardless of what plane they are on, making them glow like a beacon within the weave. They can then attempt to draw this beacon to their current location. However, a foe with the strength of mind to resist may cause the spell to backfire, instead sending the caster to his or her target. Once this spell is used, the caster must rest for a short while before attempting its use again.  Note this spell will automatically fail if either the caster or target are within the protection of a temple.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_save("will");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " snarls the first syllables of a summoning.";
}

int preSpell()
{
    if ((int)caster->query_property("spell summon time") + DELAY > time()) {
        tell_object(caster, "You cannot summon anyone to you again so quickly.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int i, matches;
    string real;
    object targ;
    mapping map;
    string* map_keys;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (!stringp(arg)) {
        tell_object(CASTER, "You must specific a target for this spell.");
        TO->remove();
        return;
    }
    arg = lower_case(arg);
    if (!(targ = find_player(caster->realNameVsProfile(arg)))) {
        tell_object(CASTER, capitalize(targ) + " cannot be found to establish a link.\n");
        TO->remove();
        return;
    }
    tell_object(caster, "%^BOLD%^%^CYAN%^You cast out tendrils of seeking energy, and in your mind you can see the weave "
                "energies around " + targ->QCN + " flare brightly with magical energy!");
    call_out("do_summon", 6, targ);
}

void do_summon(object target)
{
    object* party, endplace, target_room, startplace;
    int i, success, fail, targlevel, mylevel;
    int mypower, startpower, endpower, bonus;

    if (!objectp(caster) || !objectp(target)) {
        dest_effect();
        return;
    }

    endplace = environment(target);
    startplace = environment(caster);

    if (!objectp(place) || !objectp(endplace)) {
        tell_object(caster, "The summoning has failed.");
        dest_effect();
        return;
    }

    if(endplace->is_temple() || startplace->is_temple() )
        return notify_fail("You feel a divine intervention disrupt your beacon.");

    if(!TELEPORT->object_can_be_teleported(target,endplace,clevel))
    {
      tell_object(caster, "You try to tug the beacon through the weave to you, but interference causes you to fail.");
      dest_effect();
      return;
    }

    // This increments intentionally. Player has about two chances to
    // be mean within reasonable time

    caster->set_property("spell summon time", time());
    success = 0;

    if (!do_save(target, -2)) {
        success = 1;
    }else {
        success = 0;
        if (do_save(caster, bonus * (-1))) {
            fail = 1;
        }
    }
    if (fail) {
        tell_object(target, "%^CYAN%^You feel a strange tugging at your soul before it ceases.%^RESET%^");
        tell_object(caster, "%^CYAN%^You try to forcefully yank the glowing magical beacon to you, but the spell turns upon "
                    "you and it is all you can do to resist being thrown through the weave at " + target->QCN + "!%^RESET%^", target);
        dest_effect();
        return;
    }
    if (success) {
        tell_object(target, "%^BOLD%^%^CYAN%^You feel a rough tug on your soul, and suddenly you find yourself standing "
                    "before " + caster->QCN + "!");
        tell_object(caster, "%^BOLD%^%^CYAN%^You forcefully yank forward the glowing magical beacon, drawing "
                    + target->QCN + " through the weave to appear before you!");
        tell_room(ENV(target), "%^BOLD%^%^CYAN%^" + target->QCN + " disappears in a flash!.");
        TELEPORT->teleport_object(caster, target, ENV(caster), clevel);
        dest_effect();
        return;
    }else {
        tell_object(target, "%^BOLD%^%^BLUE%^You feel a strange tugging at your soul, before " + caster->QCN + " suddenly "
                    "appears before you!");
        tell_object(caster, "%^BOLD%^%^BLUE%^You try to forcefully drag " + target->QCN + " through the weave to you, but the "
                    "spell backfires and you are thrown forward to appear before " + target->QO + "!");
        tell_object(caster, "%^BOLD%^You are transported to another place!");
        tell_room(place, "%^BOLD%^%^CYAN%^" + target->QCN + " disappears in a flash!.");
        TELEPORT->teleport_object(caster, caster, ENV(target), clevel);
        dest_effect();
        return;
    }
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
