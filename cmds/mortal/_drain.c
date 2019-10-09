#include <std.h>
#include <daemon.h>

string type;

int cmd_drain(string args)
{
    string targ;
    object targobj;
    if (!TP->is_vampire()&&
        !avatarp(TP))
    {
        return 0;
    }

    if (!args)
    {
        notify_fail("Target required.\n");
        return 0;
    }

    if(sscanf(args,"%s for %s",targ,type)!=2)
    {
        targ=args;
        type="life";
    }
    if(member_array(type,({"life","health"}))==-1)
    {
        notify_fail("Invalid drain type. Drain for life or health.\n");
        return 0;
    }
    if(!objectp(targobj=present(targ,ETP)))
    {
        notify_fail("No such target present.\n");
        return 0;
    }

    if(!(targobj->query_asleep()||
         targobj->query_unconscious()||
         targobj->query_paralyzed()))
    {
        notify_fail("Your target is not incapacitated.\n");
        return 0;
    }

    if(targobj->is_undead())
    {
        notify_fail("You should eat fresh food.\n");
        return 0;
    }
    write("all ok");
    return 1;
}

void drain_health(object target)
{
    int dam;
    if(TP->query_max_hp_bonus() > TP->query_max_hp_base())
    {
        tell_object(TP,"%^BOLD%^%^RED%^You are too infused as it is. Continuing to drain for life.%^RESET%^");
        type = "life";
    }
    dam = roll_dice(TP->query_level(),4);
    target->cause_typed_damage(target,"torso",dam,"negative energy");
    caster->add_max_hp_bonus(dam);
    //target->cause_typed_damage(caster,"torso",dam,"negative energy");
}

void drain_health(object target)
{
    int dam;
    dam = roll_dice(TP->query_level(),4);
    target->cause_typed_damage(target,"torso",dam,"negative energy");
    target->cause_typed_damage(caster,"torso",dam,"negative energy");
}

void help()
{
    write("");
}
