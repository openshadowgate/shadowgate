#include <std.h>
#include <daemons.h>

inherit OBJECT;
void create() 
{
    ::create();
    set_short("");
    set_long("");
    set_property("no drop", 1);
    set_property("death keep", 1);
    set_id(({"setter object"}));
    set_weight(0);
    set_property("no animate", 1);
    set_property("soulbound", 1);
}

string *query_hair_colors(object who) 
{ 
    int cha;
    string *choices = ({});
    choices += ({"dark green", "dark blue", "blonde"});
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    choices += ({"dark brown", "black"});
    return choices;
}