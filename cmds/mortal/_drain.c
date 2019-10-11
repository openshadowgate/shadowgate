#include <std.h>
#include <daemons.h>
#include <magic.h>

string type;
int draining = 0;

string *TARGMSGS = ({
        "You feel your life leaves you with the blood lost.",
            "The cold spreads from the bite stop.",
            "You are oblivious and blissful as the life leaves you.",
            "Everything is serene and calm.",
            "You wish you could be held like that for ever",
            "You feel small stream of blood running down your neck",
            "Cold but pleasant, this kiss is.",
            "Is this love? But you will die.",
    });

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

    tell_object(TP,"%^BOLD%^%^BLACK%^Hit %^RED%^<return>%^BLACK%^ to stop feeding.%^RESET%^");
    add_action("stop_drain","");
    input_to("stop_drain",0);
    draining = 1;
    drain_process(targobj);
    TP->add_bloodlust(20000);

    return 1;
}

int verify_conditions(object target)
{
    return (target->query_asleep() ||
            target->query_unconscious() ||
            target->query_paralyzed() ||
            target->query_bound());
}

void stop_drain()
{
    TP->remove_paralyzed(0);
    tell_object(TP,"%^BOLD%^%^RED%^You retract your %^BLACK%^fa%^RED%^n%^BLACK%^gs%^RED%^ and float backwards.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TP->QCN+" %^BOLD%^%^RED%^stops %^RED%^f%^BLACK%^e%^RED%^e%^RED%^d%^BLACK%^i%^RED%^n%^BLACK%^g%^RED%^ and floats backwards.%^RESET%^",TP);
    draining=0;
}

void drain_process(object target)
{
    if(!objectp(target))
    {
        tell_object(TP,"%^BOLD%^%^RED%^Your victim is no longer here.%^RESET%^");
        stop_drain();
        return;
    }
    if(ENV(target)!=ETP)
    {
        tell_object(TP,"%^BOLD%^%^RED%^Your victim is no longer here.%^RESET%^");
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
    if(target->query_hp()<-(target->query_max_hp()/5))
    {
        stop_drain();
        return;
    }
    if(TP->query_max_hp_bonus() > (TP->query_max_hp_base()/2 ) && type == "health")
    {
        tell_object(TP,"%^BOLD%^%^RED%^You feel too infused as it is. You continue to drain for life.%^RESET%^");
        type = "life";
    }
    if(type=="health")
        drain_health(target);
    else
        drain_life(target);
    TP->set_paralyzed(ROUND_LENGTH*8, "%^BOLD%^%^BLACK%^You are held in place %^RED%^feeding%^BLACK%^ of "+target->QCN+"!%^RESET%^
%^BOLD%^%^BLACK%^Hit %^RED%^<return>%^BLACK%^ to stop feeding.%^RESET%^");
    tell_object(TP,"%^BOLD%^%^RED%^Fresh blood runs down your tongue.");
    tell_object(target,"%^RED%^"+TARGMSGS[random(sizeof(TARGMSGS))]+"%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TP->QCN+" is leaning over "+target->QCN+"'s neck%^RESET%^",TP);
    call_out("drain_process",ROUND_LENGTH,target);
}

void drain_health(object target)
{
    int dam;
    dam = roll_dice(TP->query_level(),8);
    target->cause_typed_damage(target,"torso",dam,"negative energy");
    TP->add_max_hp_bonus(dam*2);
    //target->cause_typed_damage(caster,"torso",dam,"negative energy");
}

void drain_life(object target)
{
    int dam;
    dam = roll_dice(TP->query_level(),8);
    target->cause_typed_damage(target,"torso",dam,"negative energy");
    target->cause_typed_damage(TP,"torso",dam*2,"negative energy");
}

void help()
{
    write(
"%^CYAN%^NAME%^RESET%^

drain - drain someone's blood

%^CYAN%^SYNTAX%^RESET%^

drain %^ORANGE%^%^ULINE%^TARGET%^RESET%^ [for life|health]

%^CYAN%^DESCRIPTION%^RESET%^

Draining is an activity vampires engage in when they are hungry.

Your %^ORANGE%^%^ULINE%^TARGET%^RESET%^ must be either asleep, paralyzed, grappled, bound or unconscious to be drained.

A vampire must drain proper kith race, such as human, or any race on %^ORANGE%^<help races>%^RESET%^ to saturate her hunger. Draining lesser creature, other vampires or undead creatures will not work.

Feeding just once saturates vampires bloodlust for a while. Draining can be done for two effects. By default and without an argument, draining for life will heal the vampire, while draining for health will increase max health bonus, but no over than half of vampire's base maximum hp.

%^CYAN%^SEE ALSO%^RESET%^

vampire, undead, recall
");
}
