#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A small laboratory");
    set_long(
"%^BOLD%^%^BLACK%^Tall wooden tables %^RESET%^in neat rows are the main "
"focus of this room.  Upon "
"these tables is a bewildering array of gadgets, papers, strange objects, "
"and discarded bits of odd materials.  Shelves line the walls and are "
"similarly cluttered with miscellaneous items.  Judging from the beakers, "
"alembics, small jars of various substances, and books, this must be a "
"laboratory. A pair of high windows in the north and east walls admits "
"sunlight in the day while there are candles set around for lighting at "
"night."  
    );
    set_listen("default","You hear the sounds of gurgling beakers on their "
        "burners.");
    set_smell("default","This is the source of that sweet smell, it is very "
        "clearly a potion being brewed.");
    set_items(([
       ({"tables", "table" }) : "Made from a %^BOLD%^%^BLACK%^darkened wood"
          "%^RESET%^, the tables have been arranged in neat rows and seem to "
          "fill the room. Various objects have been scattered about on them.",
       "shelves" : "Wooden shelves line the walls and are as cluttered "
          "with objects as the tables.",
       ({"beakers", "jars" }) : "Glassware of all shapes and sizes line "
          "the shelves.  The jars and beakers are filled to various levels "
          "with different sorts of liquids.",
       "books" : "%^ORANGE%^Old, leather bound volumes line the shelves that "
          "have been darkened with age."
    ] ));
    set_exits(([
       "west" : "/d/player_houses/slore/library",
    ] ));
}