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

    TP->set_paralyzed(400, "%^BOLD%^%^BLACK%^You are held in place %^RED%^feeding%^BLACK%^ of "+targobj->QCN+"!%^RESET%^
%^BOLD%^%^BLACK%^Hit %^RED%^<return>%^BLACK%^ to stop feeding.%^RESET%^");
    tell_object(TP,"%^BOLD%^%^BLACK%^Hit %^RED%^<return>%^BLACK%^ to stop feeding.%^RESET%^");
    input_to("stop_drain",1);
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
    TP->remove_paralyzed(0);
    tell_object(TP,"%^BOLD%^%^RED%^You retract your %^BLACK%^fa%^RED%^n%^BLACK%^gs%^RED%^ and float backwars.%^RESET%^");
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
    if(target->query_hp()<-100)
    {
        stop_drain();
        return;
    }
    if(type=="health")
        drain_health(target);
    else
        drain_life(target);
    tell_object(TP,"%^BOLD%^%^RED%^Fresh blood runs down your tongue.");
    tell_object(target,"%^RED%^"+TARGMSGS[random(sizeof(TARGMSGS))]+"%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TP->QCN+" leaning over "+target->QCN+", with face in the neck.%^RESET%^",TP);
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
    write(
"%^CYAN%^NAME%^RESET%^

drain - drain someone's blood

%^CYAN%^SYNTAX%^RESET%^

drain %^ORANGE%^%^ULINE%^TARGET%^RESET%^ [for life|health]

%^CYAN%^DESCRIPTION%^RESET%^

Draining is an activity vampires engage in when they are hungry.

A vampire must drain proper kith race, such as human, or elf, or shade, to saturate her hunger. Draining other vampires or undead creatures will not work.

Feeding just once saturates vampires bloodlust for a while. Draining can be done for two effects. By default and without argument, draining for life will heal the vampire, while draining for health will increase max health bonus, but no more than double vampire's base maximum hp.

%^CYAN%^SEE ALSO%^RESET%^

vampire, undead, recall
");
}
