// open gates *Styx* 2/10/06

#include <std.h>
#include <daemons.h>
#include "../pass.h"


inherit "/d/shadow/room/inherits/pass_parent";
inherit VAULT;

void create(){
    ::create();

    set_long(desc_start + 

"%^ORANGE%^Meeting the northern gate of the %^BOLD%^city of Shadow%^RESET%^%^ORANGE%^ in the south " +
"the " +desc_dragon_pass_road + " %^ORANGE%^comes to an abrupt end or sudden start along "+
"the edge of a set of %^WHITE%^steel bound %^BOLD%^%^BLACK%^g%^WHITE%^a%^BLACK%^t%^WHITE%^e%^BLACK%^s %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^p%^WHITE%^o%^BLACK%^r%^WHITE%^t%^BLACK%^c%^WHITE%^u%^BLACK%^l%^WHITE%^l%^BLACK%^i%^WHITE%^s%^RESET%^%^ORANGE%^ " +
"walled by %^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^ower%^BOLD%^s%^RESET%^%^ORANGE%^ on either side. To " +
"the north there is a " + desc_flat_plain + " %^ORANGE%^which turns into " + desc_foothills + " %^ORANGE%^off in the " +
"distance before fading into the intimidating " + desc_charu_mountains + "%^ORANGE%^. "
+ desc_trees




);

    set_exits(([
        "south" : "/d/shadow/city/room/northgate",
    "north" : PASSDIR+"pass2"
    ]));

    set_door("gate", "/d/shadow/city/room/northgate","south",0);

    set_lock_description("gate","lock","This is a huge bar across the giant door.");
     lock_difficulty("gate",-2000,"lock");

    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
}

void reset(){
    ::reset();
    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
    set_locked("gate", 0);
    if(!present("law sign")){
       new("/d/shadow/obj/lawsign")->move(TO);
    }
}
