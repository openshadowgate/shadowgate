/*
  common.c
  
  Written for the new guild Alliance Reborn.
  
  -- Tlaloc -- 3.24.20
*/

#include <std.h>

inherit VAULT;

void create()
{
    ::create();
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_indoors(1);
    set_light(3);
    set_property("teleport proof", 67);
    set_short("Quarters Common Area");
    set_long("\n\
%^CYAN%^Quarters Common Area%^RESET%^\n"+
"This is the common area for the various living quarters in the Alliance Reborn Keep. The area is very spacious and comfortable, and serves as a nice lounging area, with leather couches and cushioned chairs arranged around a beautiful stone fireplace. Above the fireplace is a beautiful painting depicting a group of heroes standing tall and shining in a background of darkness. On the fireplace mantle is a cigar box, for special occasions. On a small table in one of the corners is a magical decanter with a gentle amber liquid withing it and several cups arranged neatly.");
    set_exits( ([
                 "east":"/d/guilds/alliance/hall/hall",
                 "north":"/d/guilds/alliance/hall/quartersnorth",
                 "west" :"/d/guilds/alliance/hall/quarterswest",
                 "south" :"/d/guilds/alliance/hall/quarterssouth",
               ]) );
               
    set_door("west door", "/d/guilds/alliance/hall/quarterswest", "west");
    set_door("north door", "/d/guilds/alliance/hall/quartersnorth", "north");
    set_door("south door", "/d/guilds/alliance/hall/quarterssouth", "south");
}
