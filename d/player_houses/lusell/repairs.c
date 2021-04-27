#include <std.h>
#define SHOPR "/d/player_houses/lusell/rooms/"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   remove_property("no teleport");
   set_property("no teleport",1);
   set_name("Storage closet");
   set_short("%^YELLOW%^A storage closet for repairs%^RESET%^");
   set_long("%^YELLOW%^You have entered a small bare room.  There is a lone table standing "+
   "directly in the center of it.%^RESET%^");
   set_smell("default","The intense foul odor of sweat permeates the air.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^Silence permeates the air, causing your ears to ring.");
   set_exits(([
    "out" : SHOPR+"shop",
    ]));
/*    We really don't need any of this until/unless we open these up to breakins *Styx*
   set_door("door",SHOPR+"shop","out");
   set_door_description("door", "%^MAGENTA%^This door is made from a dark brown wood that has an oddly shaped keyhole inset into the left side of it.%^RESET%^");
   set_locked("door",1,"lock");
   set_lock_description("door","lock","%^MAGENTA%^This is a strangely designed lock.  The keyhole is thin and is horizontal rather than vertical.  Several small holes line the edge of it, suggesting that whatever key fits this lock is quite complex.%^RESET%^");
   lock_difficulty("door",10,"lock");
*/
   set_no_clean(1);
   set_storage(1);
   restore_room();
}
