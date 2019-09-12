#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit WEAPONLESS;

object master;
object weapon;

void control(object caster)
{
    if(!objectp(caster))
        return;
    if(!present(caster,environment(TO)))
        return;
    master = caster;
    call_out("protect",ROUND_LENGTH);
}

void protect()
{
    object *foes, foe;

    if(!objectp(master))
        return;

    call_out("protect",ROUND_LENGTH);
    foes=master->query_attackers();

    foreach(foe in foes)
    {
        if(!objectp(foe))
            continue;
        if(!present(foe,ENV(TO)))
            continue;
        TO->kill_ob(foe);
    }
}

void set_weap_enchant(int level)
{
    if(objectp(weapon))
        if(weapon->is_weapon())
            weapon->set_property("enchantment",level);
}
