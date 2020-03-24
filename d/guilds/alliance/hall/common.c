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
    
    set_items( ([
                 "painting":"This painting is beautifully rendered. The scene that is depicted shows a backdrop of swirling blackness and shadows, pressing in on all sides. In the foreground are a group of figures standing boldly against the darkness around them. A half-elf with indigo hair and steel-grey eyes powerfully strikes a shadowy figure reaching for a stalwart Deva who is holding aloft an orb of incredible brightness that seems to push the darkness towards the right side of the frame. Next to him is a pale, hooded woman holding aloft a staff that emanates a veridian glow, seeming to push away the shadows to the left side of the frame. Around the two are several figures: A sylvan elf with twirling blade fights off everal dark figures. A brawny elf with scores of tattoos on his body glows with chaotic energy as his face twists in a feral rage. Between them stands a dark-haired, androgynous feytouched human stabs one of the shadows in the back as it attacks his companions. To the forefront another elf with black hair and green eyes stands protectively over two sleeping figures, with a blade in one hand and a blinding orb of magic in the other hand. The sleeping figures he guards are of a rawboned man in stylish clothes and a woman with auburn hair and a white robe. The woman seems to have a bright ball of energy under her arm. In the center of the painting, standing behind and above the group with his arms stretched wide is a determined looking moon-elf with red hair. Around him is a miasma of energy that seems to protect the group and attack the darkness.",
             ]) );
}
