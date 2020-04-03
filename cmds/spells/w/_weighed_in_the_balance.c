//Weighed in the Balance - new Vigilance domain spell to
//replace Dictum with the rebalancing of domains
//Coded by ~Circe~ 5/5/08
//Based in part on the mass cure/cause wounds spells by Ares

#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <party.h>

inherit SPELL;

int calculate_healing();
int calculate_damage();

void create()
{
    ::create();
    set_author("circe");
    set_spell_name("weighed in the balance");
    set_spell_level(([ "classless" : 8 ]));
    set_spell_sphere("combat");
    set_spell_domain("vigilance");
    set_syntax("cast CLASS weighed in the balance");
    set_description("On casting this spell, the priest calls upon his deity to judge those in the surrounding area.  "
                    "Those aiding the caster will be healed (they must be in a party) while those attacking the caster will suffer damage.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
}

int preSpell()
{
    object* attackers = ({});
    attackers = caster->query_attackers();
    if (!sizeof(attackers)) {
        tell_object(caster, "You may only call upon " +
                    "" + (string)caster->query_diety() + "'s judgment when you " +
                    "are in battle!");
        return 0;
//can only be cast when there are attackers
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLUE%^You plant your feet and " +
                "point your finger at your enemy, calling for %^YELLOW%^" +
                "" + (string)caster->query_diety() + "'s %^BLUE%^aid.%^RESET%^");
    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " pauses mid-" +
              "battle to point a point a finger and fix " + caster->QP + " " +
              "attackers with a stern gaze, calling upon " + caster->QP + " " +
              "deity's aid.%^RESET%^", caster);
    return "display";
}

void spell_effect(int prof)
{
    int i;
    string party;
    object* targets = ({}), * attackers = ({});

    party = (string)caster->query_party();

    if (party) {
        targets = (object*)PARTY_OB->query_party_members(party);
    }
    attackers = caster->query_attackers();
    targets += ({ caster });
    targets = distinct_array(targets);

    tell_room(place, "%^YELLOW%^A golden balance appears in the air before " +
              "" + caster->QCN + ", the pans slowly rising and falling.%^RESET%^", caster);
    tell_object(caster, "%^YELLOW%^A golden balance appears in the air before " +
                "you, the pans slowly rising and falling.%^RESET%^", caster);
    tell_room(place, "%^BOLD%^As the balance reaches %^BLUE%^equilibrium" +
              "%^WHITE%^, a %^YELLOW%^blastwave%^WHITE%^ of %^BLUE%^force " +
              "%^WHITE%^radiates outward, shocking the area!%^RESET%^");
    if (sizeof(targets)) {
        set_helpful_spell(1);
        for (i = 0; i < sizeof(targets); i++) {
            if (!objectp(targets[i])) {
                continue;
            }
            if (!present(targets[i], place)) {
                continue;
            }
            if (targets[i]->query_property("berserked")) {
                tell_object(targets[i], "%^RED%^The rage fights off the healing!%^RESET%^");
            }else {
                tell_object(targets[i], "%^CYAN%^You are found worthy " +
                            "by the scales and feel a healing wave reach you.%^RESET%^");
                tell_room(place, "%^CYAN%^A soft wave of energy bathes " +
                          "" + targets[i]->QCN + ".%^RESET%^", targets[i]);
                damage_targ(targets[i], targets[i]->return_target_limb(), (-1 * calculate_healing()), "divine");
            }
        }
    }
    if (sizeof(attackers)) {
        set_helpful_spell(0);
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }
            if (!present(attackers[i], place)) {
                continue;
            }
            tell_object(attackers[i], "%^YELLOW%^The blast from the " +
                        "scales rocks you, searing your skin!%^RESET%^");
            tell_room(place, "%^YELLOW%^The blast from the scales " +
                      "sears %^" + attackers[i]->QCN + "!%^RESET%^", ({ attackers[i] }));
            damage_targ(attackers[i], attackers[i]->return_target_limb(), calculate_damage(), "divine");
            spell_kill(attackers[i], caster);
        }
    }
    spell_successful();
    dest_effect();
    return;
}

int calculate_healing()
{
    return sdamage;
}

int calculate_damage()
{
    return sdamage;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
