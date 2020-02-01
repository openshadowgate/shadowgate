//spell to allow a brief glimpse at a person's
//location without a scrying device ~Circe~ 8/28/05
#include <std.h>
#include <priest.h>

inherit SPELL;

object dest, mytarg, myplace;

int clairvoyance_delay()
{
    return 60;
}

void create()
{
    ::create();
    set_spell_name("clairvoyance");
    set_spell_level(([ "psion" : 1, "mage" : 2, "bard" : 3, "assassin" : 4, "inquisitor" : 3, "oracle":2, "cleric":2]));
    set_discipline("seer");
    set_domains("travel");
    set_mystery("lore");
    set_spell_sphere("divination");
    set_syntax("cast CLASS clairvoyance on TARGET");
    set_description("A skilled seer can attempt to gain a brief image of a target. All they will see is a second's "
        "glimpse of their surroundings, and who else may be nearby. Anti-scrying effects will block this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
}


int preSpell()
{
    if (spell_type != "psion" && ((int)caster->query_property("clairvoyance time") + clairvoyance_delay()) > time()) {
        tell_object(caster, "You need to take a moment's rest before you can try that again.");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    if (spell_type == "psion") {
        tell_object(caster, "%^BOLD%^Closing your eyes, you press your fingers" +
                    " to your temple, and focus your energies.");
        tell_room(place, "%^BOLD%^%^WHITE%^" + caster->QCN + " closes " + caster->QP + " eyes" +
                  ", pressing " + caster->QP + " fingers to " + caster->QS + " temples.");
        return "display";
    }
    tell_object(caster, "%^BOLD%^Seeking inner calm, you open your mind to the world around you and the target you seek.");
    tell_room(place, "%^BOLD%^%^WHITE%^" + caster->QCN + " closes " + caster->QP + " eyes and takes on an expression of calm.");
    return "display";
}


void spell_effect(int prof)
{
    string targ, real, * map_keys;
    object mytarg, myplace, blockobj;
    int matches, i, bonus, scrypower, stop;
    mapping map;

    if (!arg || !stringp(arg)) {
        tell_object(caster, "You must focus upon a target!");
        if (objectp(TO)) {
            TO->remove();
        }
        return 1;
    }

    targ = lower_case(arg);

    if (targ == (string)caster->QCN) {
        tell_object(caster, "%^BOLD%^That won't work. You should know your own location.");
        dest_effect();
        return;
    }

    if (!find_player(caster->realName(targ))) {
        tell_object(CASTER, capitalize(targ) + " cannot be found to scry.\n");
        TO->remove();
        return;
    }


    if (avatarp(caster)) {
        write("You know who you're looking for.");
    }

    mytarg = find_player(caster->realNameVsProfile(targ));

    if (!objectp(mytarg)) {
        tell_object(caster, "%^BOLD%^%^RED%^The target of your power is not available!");
        dest_effect();
        return;
    }

    if (mytarg->query_true_invis()) {
        tell_object(caster, "%^BOLD%^%^RED%^The target of your power is not available!");
        dest_effect();
        return;
    }

    bonus = caster->query_stats(casting_stat);
    bonus = bonus - 10;
    scrypower = CLEVEL + bonus + query_spell_level(spell_type) * 2;

    if (blockobj = present("blockerx111", environment(mytarg)) || blockobj = present("blockerx111", mytarg)) {
        if (scrypower < blockobj->query_block_power()) {
            tell_object(CASTER, "%^BOLD%^RED%^There appears to be " +
                        "interference blocking your scrying attempt in the " +
                        "vicinity of the target!%^RESET%^");
            dest_effect();
            return 1;
        }
    }
