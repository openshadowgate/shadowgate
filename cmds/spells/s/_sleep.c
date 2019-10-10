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
    set_syntax("cast CLASS sleep on TARGET");
    set_description("Upon casting the sleep spell, 2d4 HD of monsters will fall asleep.  Attacks on the sleepers will "
        "awaken them; normal noise won't, however.  Monsters with 4 HD + 3hp will not be affected.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}


spell_effect(int prof)
{
    int success;
    string myrace;

    success = 0;

    time = ((clevel * 5 * prof ) / 100);
    if (time > 300) time = 300;

    prospective = all_inventory(place);
    prospective = target_filter(prospective);

    party = ob_party(caster);

    counter = 0;
    targets = ({target});

    max_hd = ((int)DICE_D->roll_dice(4)) + ((int)DICE_D->roll_dice(4)) - (4*(4-prof/25));

    for (x=0;x < sizeof(prospective);x++)
    {
        if(!objectp(prospective[x])) continue;
        if ((member_array(prospective[x], party) != -1) || !living(prospective[x])) continue;
        if(!caster->ok_to_kill(prospective[x])) continue;

        target2 = prospective[x];
        counter += target2->query_level();

        if(do_save(target2,0)) { continue; }

        myrace = (string)target2->query_race();

        if(race_immunity_check(target2, "sleep")) { continue; }

        if(mind_immunity_check(target2, "default"))
        {
            target2->add_attacker(caster);
            damage_targ(target2, target2->return_target_limb(), roll_dice(1,8),"untyped");
            continue;
        }

        if (!success)
        {
            spell_successful();
            success = 1;
        }

        if (counter >= max_hd) break;

        tell_room(environment(target2),"%^CYAN%^%^BOLD%^"+target2->QCN+" wavers for a bit, then falls to the ground in a deep slumber.", target2);
        tell_object(target2, "%^CYAN%^%^BOLD%^You suddenly become drowsy and fall asleep.");
        target2->set_asleep(time, "You are asleep!");
        target2->set_property("spelled", ({TO}) );
        targets += ({target2});
    }
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
