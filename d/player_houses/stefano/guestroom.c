//guestroom.c - Guest room for Stefano's cottage.  Coded by Circe 9/20/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A comfortable guest room");
        set_short("A comfortable guest room");
        set_long("%^YELLOW%^This room is decorated in light beige tones with "+
           "%^BOLD%^%^BLUE%^Blue drapes%^RESET%^%^YELLOW%^, a %^BOLD%^%^WHITE%^white "+
           "ceiling%^RESET%^ %^YELLOW%^and a %^BOLD%^%^BLUE%^blue carpet%^RESET%^%^YELLOW%^.  "+
           "A simple single bed provides a place for visitors to sleep. There is also a wash basin, "+
           "a heated towel rail and a large oak wardrobe.  The window looks out over the gardens "+
           "just in front of the cottage.  The overall effect of the room is a simple, but snug "+
           "and comfortable place to stay."+
           "\n");
        set_smell("default","The room smells of fresh laundry and cut flowers.");
        set_listen("default","There are the faint sounds of the gardens and the stream outside.");
        set_items(([
           "wardrobe" : "A free standing wardrobe with hanging space for clothes, shelves, "+
              "rails, drawers, and a small mirror on the inside of one of the doors.",
           "mirror" : "You are just as beautiful as the last time you checked.",
           "window" : "The view from the window reveals a pleasant scene.  The garden below "+
              "is bounded by the narrow stream.",
           "bed" : "It is freshly made, the crisp white sheets turned back at the top, over "+
              "the light blue coverlet. There are plenty of pillows to help ensure a comfortable "+
              "night's sleep. The mattress is comfortably firm.",
           "basin" : "The basin is supplied with soap, flannels and towels, and taps with both "+
              "hot and cold running water - a great luxury indeed.",
           ({"towel", "rail", "towel rail"}) : "The metal rail over which the towel hangs "+
              "is kept heated by some unseen means, leaving the towel constantly warm, and "+
              "helping to maintain the room at a comfortable temperature.",
        ]));
        set_exits(([
           "out" : SHOUSE"landing"
     ]));
        set_door("guest door",SHOUSE"landing","out",0);
        set_door_description("guest door", "A solid oak door.");
        set_search("bed","Under the bed, you find a chamber pot.");
}