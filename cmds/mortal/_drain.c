#include <std.h>
#include <daemons.h>
#include <magic.h>

string type;
int draining = 0;

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

    if(targobj->is_undead())
    {
        notify_fail("You should eat fresh food.\n");
        return 0;
    }

    if(!RACE_D->is_race(targobj->query_race()))
    {
        notify_fail("Feeding from this is beneath you.\n");
        return 0;
    }

    if(!(verify_conditions(targobj)))
    {
        notify_fail("Your target is not incapacitated.\n");
        return 0;
    }

    // 10 minutes?
    add_action("stop_drain","stop");
    TP->set_paralyzed(400, "%^BOLD%^%^BLACK%^You are held in place %^RED%^feeding%^BLACK%^ of "+targobj->QCN+"!%^RESET%^
%^BOLD%^%^BLACK%^Use %^RED%^<stop>%^BLACK%^ to stop feeding.%^RESET%^");
    draining = 1;
    drain_process(targobj);
    TP->add_bloodlust(20000);

    return 1;
}

int verify_conditions(object target)
{
    return (target->query_asleep() ||
            target->query_unconscious() ||
            target->query_paralyzed());
}

void stop_drain()
{
    TP->set_paralyzed(0);
    tell_object(TP,"%^BOLD%^%^RED%^You retract your %^BLACK%^fa%^RED%^n%^BLACK%^gs%^RED%^ and float backwars.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TP->QCN+" %^BOLD%^%^RED%^stops %^RED%^f%^BLACK%^e%^RED%^e%^RED%^d%^BLACK%^i%^RED%^n%^BLACK%^g%^RED%^ and floats backwards.%^RESET%^");
    draining=1;
}

void drain_process(object target)
{
    if(!objectp(target))
    {
        tell_object(TP,"%^BOLD%^%^RED%^Your victim has escaped!%^RESET%^");
        stop_drain();
        return;
    }
    if(ENV(target)!=ETP)
    {
        tell_object(TP,"%^BOLD%^%^RED%^Your victim has escaped!%^RESET%^");
        stop_drain();
        return;
    }
    if(!verify_conditions(target))
    {
        tell_object(TP,"%^BOLD%^%^RED%^"+target+"%^BOLD%^%^RED%^comes to %^BLACK%^sen%^RED%^s%^BLACK%^es%^RED%^ and %^BLACK%^str%^RED%^u%^RED%^g%^BLACK%^gl%^RED%^e%^RED%^s%^RED%^ out of your grip!%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^RED%^"+target+"%^BOLD%^%^RED%^comes to %^BLACK%^sen%^RED%^s%^BLACK%^es%^RED%^ and %^BLACK%^str%^RED%^u%^RED%^g%^BLACK%^gl%^RED%^e%^RED%^s%^RED%^ out of "+TP->QCN+"'s grip!%^RESET%^",TP);
        tell_object(target,"%^BOLD%^%^RED%^You %^RED%^f%^RED%^i%^BLACK%^nally%^RED%^ come to senses and struggle out of%^RESET%^ "+TP->QCN+"'s grip!");
        stop_drain();
        return;
    }
    if(!draining)
    {
        return;
    }
    if(target->query_hp()<-100)
    {
        stop_drain();
        return;
    }
    write("Feeding message");
    call_out("drain_process",ROUND_LENGTH,target);
}

void drain_health(object target)
{
    int dam;
    if(TP->query_max_hp_bonus() > TP->query_max_hp_base())
    {
        tell_object(TP,"%^BOLD%^%^RED%^You are too infused as it is. Continuing to drain for life.%^RESET%^");
        type = "life";
    }
    dam = roll_dice(TP->query_level(),6);
    target->cause_typed_damage(target,"torso",dam,"negative energy");
    TP->add_max_hp_bonus(dam);
    //target->cause_typed_damage(caster,"torso",dam,"negative energy");
}

void drain_life(object target)
{
    int dam;
    dam = roll_dice(TP->query_level(),6);
    target->cause_typed_damage(target,"torso",dam,"negative energy");
    target->cause_typed_damage(TP,"torso",dam*2,"negative energy");
}

void help()
{
    write("");
}
