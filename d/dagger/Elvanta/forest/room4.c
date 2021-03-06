#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set("day long", "%^ORANGE%^Travelling through the trees, you notice that the pathway seems to end just ahead of you.  Yet you can hear voices upon the wind, and laughter in the branches.  Now the pine cones are beginning to hit you upon your head with regular monotony.%^RESET%^");
set("night long", "%^CYAN%^Travelling through the trees, you try to see ahead of you, but it seems the path comes to a dead end soon.  Yet you can hear voices upon the wind, and laughter in the trees.%^RESET%^");
set_smell ("default", "%^MAGENTA%^The fragrance of pine needles and freshly dampened earth fills your senses.");
set_listen ("default", "You hear birds, squirrels and the wind whispering through the trees.  Was that laughter you heard, as well?");
set_exits (([
"northeast" : "/d/dagger/Elvanta/forest/room5",
"southwest" : "/d/dagger/Elvanta/forest/room3"
]));
set_items
(([
"trees" : "These trees are large, large enough to hold a small city",
"pathway" : "The pathway is smooth with a lifetime of redwood needles, making it soft and fragrant.","redwoods" : "These redwoods have been here for a thousand years.  Their immense age gives you a feeling of continuity.",
"shadows" : "Shadows fill the forest as you travel.  The shadows are the least of your worries.",
"moonbeam" : "Thank whatever Gods there may be that you have some light at least.",
"lights" : "Is it your imagination or just wishful thinking perhaps, but you see high in the trees to the northwest flickering points of light."
]));
}
