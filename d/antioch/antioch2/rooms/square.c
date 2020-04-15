//Created due to the addition of a jail in Antioch and to honor Saint Kyra. Kismet.
//Ready to be installed. Proper path is: /d/antioch/antioch2/rooms/square Kismet.

#include <std.h>
#include "../antioch.h"
#include <daemons.h>

inherit CVAULT;

void create()
{
    set_monsters(({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1 }));
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("The South Square");
    set_long("The South Square\n" +
             "This large square lays west of the city entrance. In its center towers a proud and healthy oak tree, spreading its branches wide above the square. It is circled by a small yet sturdy wooden platform, upon which announcements are sometimes made. This busy place if often filled with soldiers both on and off duty, as it connects the northwest barracks to the imposing building of the city jail, which towers above you to the west. Marble statues in various heroic and athletic poses stand along its perimeter, an inspiration to guards and citizens alike. The statues all lead the eye toward the grandest among them, which stands to the south of the tree: Saint Kyra, a tall and vigilant paladin of Jarmila. Roses and asters bloom by her feet, framing a golden plaque."
             );
    set("night long",
        "The South Square\n" +
        "Warm light spills forth from many lanterns hanging from the branches of a healthy oak tree in the center of this square. It is circled by a small yet sturdy wooden platform, upon which announcements are sometimes made. This busy place if often filled with soldiers both on and off duty, as it connects the northwest barracks to the imposing building of the city jail, which towers above you to the west. Marble statues in various heroic and athletic poses stand along its perimeter, an inspiration to guards and citizens alike. The statues all lead the eye toward the grandest among them, which stands to the south of the tree: Saint Kyra, a tall and vigilant paladin of Jarmila. Roses and asters bloom by her feet, framing a golden plaque."
        );
    set_smell("default", "There is a faint herbal scent in the air, mixed with flowers, sweat and musk.");
    if (query_night() == 1) {
        set_listen("default", "It is silent, save for the occasional snore of the barrack guards to the northwest.");
    }else {
        set_listen("default", "You can hear the buzz of the city all around you.");
    }
    set_items(([
                   ({ "light", "lights", "lanterns" }) : "Warm light spills out from the lanterns that hang from the tall oak tree.",
                   "barracks" : "The barracks are to the northwest.",
                   "jail" : "The city jail looms to the west, tall and oppressive.",
                   "tree" : "A large oak tree towers in the center of the square, proud and healthy.",
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The street is paved with cobblestones and kept relatively clean.",
                   ({ "statue", "statues", "Saint Kyra", "saint kyra", "kyra", "Kyra" }) : "The marble statues are expertly carved and captured in various athletic and heroic poses. The grandest of them all is the Paladin Saint Kyra of Jarmila. She stands tall and vigilant, with her helmet under her right arm and her left hand resting upon the hilt of her sheathed sword. Her long blond hair is kept in a braid and her blue eyes twinkle with happiness, lighting a warm smile. Her plate armor glows in the light, bearing the holy symbol of Jarmila.",
                   "plaque" : "The plaque reads: 'Saint Kyra, Guardian of Antioch. Forever in our hearts, forever in Jarmila's gilded halls.'",
               ]));
    set_exits(([
                   "east" : ROOMS + "street1",
                   "west" : ROOMS + "jail_main",
                   "northwest" : ROOMS + "barracks",
               ]));
}
