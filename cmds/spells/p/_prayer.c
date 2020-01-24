#include <std.h>
#include <spell.h>
#include <magic.h>
#include <skills.h>
#include <daemons.h>

inherit SPELL;

int timer, flag, stage, toggle, counter;

object *allies_tracker = ({});
object *enemies_tracker = ({});

void create()
{
    ::create();
    set_spell_name("prayer");
    set_spell_level(([ "mage" : 3, "cleric":3]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS prayer");
    set_description("");
    set_verbal_comp();
    set_somatic_comp();
    traveling_spell(1);
    set_save("fort");
}

void spell_effect(int prof)
{
    tell_object(caster, "%^BOLD%^%^BLACK%^You draw your hands forward, causing %^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^lo%^RESET%^%^GREEN%^u%^GREEN%^d%^BOLD%^%^BLACK%^s %^BLACK%^o%^RESET%^%^GREEN%^f%^BOLD%^ %^BLACK%^s%^RESET%^%^GREEN%^t%^GREEN%^i%^BOLD%^%^BLACK%^nk%^RESET%^%^GREEN%^y%^BOLD%^ %^BLACK%^f%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^m%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^s%^BLACK%^ to materialize in the area.%^RESET%^");
    tell_room(place, "%^GREEN%^" + caster->QCN + "%^BOLD%^%^BLACK%^materializes few %^BLACK%^clo%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^ds %^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^f %^BLACK%^sti%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^ky %^RESET%^%^GREEN%^f%^BOLD%^%^BLACK%^umes%^BLACK%^ in the area!%^RESET%^", caster);
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object * foes = ({}), *allies = ({});
    object targ;
    object place;
    int i, dam;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster) || !objectp(place) || !present(caster, place) || counter < 0) {
        dest_effect();
        return;
    }

    place = environment(caster);

    foes = caster->query_attackers();
    foes = target_filter(foes);
    foes -= ({ caster });

    if (caster->query_party()) {
        object* party;
        party = PARTY_D->query_party_members(caster->query_party());
        allies = all_inall_inventory(place) - (all_inventory(place) - party);
    }
    allies += ({caster});
    allies += caster->query_followers() - caster->query_attackers();
    allies = distinct_array(allies);

    counter--;
    place->addObjectToCombatCycle(TO, 1);
}

void dest_effect()
{
    if (objectp(place)) {
        tell_object(place, "%^GREEN%^S%^BOLD%^%^BLACK%^ti%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^ky %^BLACK%^cl%^RESET%^%^GREEN%^o%^GREEN%^u%^GREEN%^d%^GREEN%^s%^BOLD%^%^BLACK%^ finally disappear!%^RESET%^");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

void modify_effect(object targ, int direction)
{
    int i;

    targ->add_damage_bonus(-direction);
    targ->add_attack_bonus(-direction);
    targ->set_property("empowered", -direction);
    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        targ->add_skill_bonus(CORE_SKILLS[i], -direction);
    }
    targ->add_saving_bonus("all", -direction);
}
