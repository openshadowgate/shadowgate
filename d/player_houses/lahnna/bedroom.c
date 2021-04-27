#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A bedroom in the lodge");
    set_long("A bedroom in the lodge\n"
"You are in the bedroom area of the large lodge.  A %^GREEN%^thick green "
"carpet %^RESET%^covers most of the floor.  Along the southeastern corner "
"you can't miss the very large bed.  It is crafted from oak logs and covered "
"in a %^GREEN%^dark green bedspread%^RESET%^. A large oak dresser is next to "
"the bed along the eastern wall. By the southwestern corner is a large oak "
"closet that could fit a fair amount of clothes. Next to the closet sits a "
"%^RED%^large mahogany chest%^RESET%^.  Toward the north end of the room is "
"a large bathroom.  You "
"notice a latrine, a wash basin, and a shower stall inside the bathroom.  The "
"ceiling is twelve feet high, making the room quite spacious.  In the "
"northwest corner is the oak door that leads back out to the main room."
    );
    set_listen("default","The house is quiet.");
    set_smell("default","The scent of wood fills your nostrils.");
    set_items(([
       ({"carpet","floor"}) : "The bedroom floor is covered in a "
           "%^GREEN%^thick green carpet.",
       "bed" : "A large bed crafted from oak logs.  The frame is made of oak "
           "and it is covered in a %^GREEN%^dark green bedspread %^RESET%^that "
           "closely matches the carpet.",
       "dresser" : "An oak dresser has been positioned near the bed.  It is "
           "roughly five feet in height with several large drawers.",
       "closet" : "A large oak closet that looks like it could hold a fair "
           "amount of clothes.",
       "chest" : "A %^RED%^large mahogany chest %^RESET%^sits here on the "
           "floor.  The name '%^YELLOW%^Lahnna%^RESET%^' can be seen carved "
           "in gold on the top of the chest in large letters.",
       "ceiling" : "The ceiling is about twelve feet in height here also.  "
           "Along the main log beam, which stretches across the middle from "
           "one side of the room to the other, large oil lamps hang down from "
           "at intervals that keep the room well lit.",
    ] ));
    set_exits(([
       "west" : "/d/player_houses/lahnna/lodge"
    ] ));
    set_listen("default","The thick walls muffle most sounds from the outside.");
    set_smell("default","The scent of wood and cooking food fills your nostrils.");
   set_door("oak door","/d/player_houses/lahnna/lodge","west", 0);
   set_locked("oak door",0);
}
