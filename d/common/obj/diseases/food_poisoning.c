#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/diseases/disease_inherit";

string random_food_poisoning()
{
    switch(random(4))
    {
        case 0: 
            return "salmonella";
        case 1:
            return "e. coli";
        case 2:
            return "listeria";
        case 3:
            return "norovirus";
    }
}

void create()
{
    ::create();
//    add_disease_effect((["paralyze" : roll_dice(1,10)]), -1);
    add_disease_effect((["damage" : roll_dice(2,10)]), -1);
    add_disease_effect((["exhaustion" : roll_dice(1,10)]), 1);
    if(query_disease_name() == "The Disease") set_disease_name(random_food_poisoning());
    set_incubation_period(21600);
    set_base_incubation_period(21600);
    set_dc(14 + random(15));
    //the stage the disease starts at  
    //in effects -1 is added every time the disease does anything
    //other stages are once - so exhaustion could only possibly happen once
    set_base_disease_stage(-1);
    set_disease_stage(-1);
    set_effect_rate(1200);
    set_can_spread(0);
    set_infection_rate(100);
    set_disease_length(28800+random(2*28800));
    set_bypass_immunity(0);
    set_disease_string("$TSUB%^BOLD%^%^WHITE%^ is pale and sweating profusely.%^RESET%^");
    set_personal_disease_string("%^BOLD%^%^WHITE%^You are pale and sweating profusely.%^RESET%^");
}

void beneign_disease_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(WhoInfected)) return;
    switch(random(2))
    {
        case 0:
            tell_object(WhoInfected, "%^BOLD%^%^RED%^You double over in pain before %^BOLD%^%^GREEN%^projectile%^BOLD%^%^RED%^ vomitting!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^RED%^ doubles over in pain before %^BOLD%^"+
            "%^GREEN%^projectile%^BOLD%^%^RED%^ vomitting!%^RESET%^", WhoInfected);
            break;
        case 1:
            tell_object(WhoInfected, "%^BOLD%^%^BLACK%^You gag for a few moments and realize that something is not quite right!%^RESET%^");
            tell_room(environment(WhoInfected), WhoInfected->QCN+"%^BOLD%^%^BLACK%^ gags for a few moments, looking "+
            "off in the distance!%^RESET%^", WhoInfected);
            break;
    }
}
