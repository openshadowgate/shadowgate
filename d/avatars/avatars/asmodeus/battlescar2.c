#include <std.h>

inherit ARMOUR;

void create()
{
    set_weight(0);
    set_name("battlescars");
    set_obvious_short("a jagged scar");
    set_short("a jagged scar");
    set_id(({"scar","battlescar"}));
    set_long("Something that you should never see.");
    set_type("ring");
    set_value(0);
    set_limbs(({"head"}));
    set_wear( (: TO,"wear_scar" :) );
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(ETO->is_player() && !avatarp(ETO)) { remove(); return; }
}

int wear_scar()
{
    if(!objectp(ETO)) { return 0; }
    ETO->set_property("no tripped",1);
    ETO->set_property("no paralyze",1);
    return 1;
}

string *query_identified() { return ({}); }

