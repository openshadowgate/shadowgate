// Sleep
// skip newbies from room effect added by Styx 10/17/02

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int x,time;
int max_hd, counter;
object target2,*party,*prospective,*targets;
void dest_effect();
int check();


create()
{
    ::create();
    set_spell_name("sleep");
    set_spell_level(([ "mage" : 1, "bard" : 1, "psion" : 1, "assassin" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS sleep [on TARGET]");
    set_description("This spell will force your target or everyone in the room, excluding your party, to fall asleep. Attacks on the sleepers will awaken them; normal noise won't, however. Successful save will negate the effect. Immunity to mental attacks will cause damage instead.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    mental_spell();
}


spell_effect(int prof)
{
    int success;
    string myrace;

    success = 0;

    time = clevel*2;
    if(time > 60)
        time = 60;

    if(!objectp(target))
    {
        prospective = all_inventory(place);
        prospective = target_filter(prospective);
    }
    else
        prospective = ({target});

    party = ob_party(caster);

    targets = ({target});
    for (x = 0; x < sizeof(prospective); x++) {
        if (!objectp(prospective[x])) {
            continue;
        }
        if ((member_array(prospective[x], party) != -1) || !living(prospective[x])) {
            continue;
        }
        if (!caster->ok_to_kill(prospective[x])) {
            continue;
        }

        target2 = prospective[x];

        if (do_save(target2, -2)) {
            continue;
        }

        if (target2->query_level() > clevel) {
            continue;
        }

        myrace = (string)target2->query_race();

        if (race_immunity_check(target2, "sleep")) {
            continue;
        }

        if (mind_immunity_damage(target2, "default")) {
            continue;
        }

        if (!success) {
            success = 1;
        }

        tell_room(environment(target2), "%^CYAN%^%^BOLD%^" + target2->QCN + " wavers for a bit, then falls to the ground in a deep slumber.", target2);
        tell_object(target2, "%^CYAN%^%^BOLD%^You suddenly become drowsy and fall asleep.");
        target2->set_asleep(time, "You are asleep!");
        target2->set_property("spelled", ({ TO }));
        targets += ({ target2 });
    }
    spell_successful();
    if(!success)
    {
        tell_object(caster, "%^CYAN%^%^BOLD%^Your sleep attempt fails to affect anything.%^RESET%^");
        dest_effect();
        return;
    }
    call_out("dest_effect",time);
    return;
}


void dest_effect()
{
    object *spells_on, *newtargs;
    newtargs = ({});
    for (x=0;x<sizeof(targets);x++)
    {
        if (targets[x])
        {
            target2 = targets[x];
            if (spells_on=target2->query_property("spelled"))
            {
                target2->remove_property_value("spelled", ({TO}) );
            }
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


string query_cast_string() { return caster->QCN+" throws some rose petals in the air!"; }
