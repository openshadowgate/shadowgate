#include <std.h>
#include "../defs.h"
inherit INH+"path";

void create() {
   ::create();
   set_long((:TO,"long_desc":));
   add_item(({"rocks","stones","rubble"}),(:TO,"stones_desc":));
   add_item(({"black stone","dark stone","dark black stone"}),"%^ORANGE%^This stone seems oddly out of "
"place amongst the rubble at the base of the mountainside.  It is a %^BLACK%^%^BOLD%^dark black "
"shade%^RESET%^%^ORANGE%^, with a precise shape that is almost unnatural, like it was formed by mortal "
"hands.  Your fingertips suddenly itch to tap upon the dark stone.%^RESET%^");
   add_item(({"stone wall","wall"}),(:TO,"mountain_desc":));
   set_exits(([
     "north" : ROOMS+"path2"
   ]));
}

string path_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^The rocks part here in a seemingly natural formation, leaving a trail of sorts "
"that leads upward into the mountains on a slight incline, ending abruptly at the stone wall before you.  "
"A light sprinkling of snow covers the trail here.%^RESET%^");
   }
   return("%^ORANGE%^The rocks part here in a seemingly natural formation, leaving a trail of sorts that "
"leads upward into the mountains on a slight incline, ending abruptly at the stone wall before "
"you.%^RESET%^");
}

string mountain_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^The %^WHITE%^snowcapped%^ORANGE%^ peaks of the %^BLUE%^mountains%^ORANGE%^ loom "
"above you to the south.  Just at the base of the mountainside, you can see a rather large pile of "
"%^BLACK%^%^BOLD%^rocks%^RESET%^%^ORANGE%^, perhaps from a landslide.%^RESET%^");
   }
   return("%^ORANGE%^The tall peaks of the %^BLUE%^mountains%^ORANGE%^ loom above you to the south.  "
"Just at the base of the mountainside, you can see a rather large pile of "
"%^BLACK%^%^BOLD%^rocks%^RESET%^%^ORANGE%^, perhaps from a landslide%^RESET%^");
}

string stones_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^At the base of the mountainside is a rather large pile of rocks and rubble.  "
"Amongst the %^WHITE%^snow-sprinkled%^ORANGE%^ rocks, one in particular stands out, a dark stone that "
"looks almost %^BLACK%^%^BOLD%^black%^RESET%^%^ORANGE%^.%^RESET%^");
   }
   return("%^ORANGE%^At the base of the mountainside is a rather large pile of rocks and rubble.  "
"Amongst the rocks, one in particular stands out, a dark stone that looks almost "
"%^BLACK%^%^BOLD%^black%^RESET%^%^ORANGE%^.%^RESET%^");
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^ORANGE%^The path reaches an abrupt dead end here, with %^BLACK%^%^BOLD%^sheer stone "
"walls%^RESET%^%^ORANGE%^ surrounding it on all sides except back to the north, toward the "
"%^YELLOW%^be%^WHITE%^a%^YELLOW%^ch%^RESET%^%^ORANGE%^.  A light sprinkling of %^WHITE%^snow "
"%^ORANGE%^coats the path at your feet, and the stone walls around you.  The smooth walls of stone are "
"far too high now to see anything above or beyond them, and it seems there is nothing you can do but "
"return the way you came.%^RESET%^\n");
   }
   return("%^ORANGE%^The path reaches an abrupt dead end here, with %^BLACK%^%^BOLD%^sheer stone "
"walls%^RESET%^%^ORANGE%^ surrounding it on all sides except back to the north, toward the "
"%^YELLOW%^be%^WHITE%^a%^YELLOW%^ch%^RESET%^%^ORANGE%^.  The smooth walls of stone are far too high now "
"to see anything above or beyond them, and it seems there is nothing you can do but return the way you "
"came.%^RESET%^\n");
}

void init() {
   ::init();
   add_action("tap_fun","tap");
}

int tap_fun(string str) {
   if(!str) {
     notify_fail("What do you want to tap?\n");
     return 0;
   }
   if(str != "dark stone" && str != "black stone") {
     notify_fail("Nothing happens.\n");
     return 0;
   }
   if(member_array("south",ETP->query_exits()) != -1) {
     tell_object(TP,"%^BLACK%^%^BOLD%^You tap on the black stone, and hear a rumble as a portion of the "
"wall before you moves, closing the pathway into the forest!");
     tell_room(ETP,"%^BLACK%^%^BOLD%^"+TP->QCN+" taps on a stone, and you hear a rumble as a portion of "
"the wall before you moves, closing the pathway into the forest!",TP);
     remove_exit("south");
     tell_room(ROOMS+"forest1","%^BLACK%^%^BOLD%^You hear a rumble, as a portion of the stone wall before "
"you moves, to reveal a rocky path leading out of the forest!");
     (ROOMS+"forest1")->remove_exit("north");
   }
   else{
     tell_object(TP,"%^BLACK%^%^BOLD%^You tap on the black stone, and hear a rumble as a portion of the "
"wall before you moves aside to reveal the entrance to an enclosed forest!");
     tell_room(ETP,"%^BLACK%^%^BOLD%^"+TP->QCN+" taps on a stone, and you hear a rumble as a portion of "
"the wall before you moves aside to reveal the entrance to an enclosed forest!",TP);
     add_exit(ROOMS+"forest1","south");
     tell_room(ROOMS+"forest1","%^BLACK%^%^BOLD%^You hear a rumble as a portion of the stone wall before "
"you moves aside, to reveal a rocky path leading out of the forest!");
     (ROOMS+"forest1")->add_exit(ROOMS+"path1","north");
   }
   return 1;
}
