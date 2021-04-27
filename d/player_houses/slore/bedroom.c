#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A bedroom and study");
    set_long(
"This is a spacious bedroom and study.  A large bed with a %^YELLOW%^polished "
"brass frame %^RESET%^is the centerpiece of the room, while against one wall "
"is a desk cluttered with papers.  Tall bookshelves along the walls are "
"empty, but dust marks along the edge of each shelf indicate that the shelves "
"have been emptied but recently.  Tall candles that are arranged about the "
"room provide sufficient light to read by.  The clutter suggests that the "
"room is inhabited, although the resident seems to be away at the moment."
    );
    set_listen("default","It is quiet here except for your disturbances.");
    set_smell("default","The sweet aroma seems to fade a little.");
    set_items(([
       "bed" : "The bed is large with an %^YELLOW%^elaborately worked brass "
           "headpiece%^RESET%^.  The bed is neatly made and the bedding clean.",
       "desk" : "The desk is made of hardwood, has no drawers or other "
           "compartments, and is covered with papers.",
       "candles" : "The candles are neatly trimmed and burn brightly "
           "and smoothly.",
       "bookshelves" : "The bookshelves are tall constructs made of "
           "wood.  The shelves are slightly bowed and each has a two or "
           "three inch line of dust along the edge facing you.  In several "
           "places the dust has been disturbed in a pattern suggesting that "
           "they have been looked through recently.",
    ] ));
    set_exits(([
       "east" : "/d/player_houses/slore/library",
    ] ));
   set_door("door","/d/player_houses/slore/library","east",0);
//   set_locked("door",1);
}

