#include <std.h>
#define LROOMS "/d/player_houses/lusell/rooms/"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_name("A storage closet");
   set_short("%^YELLOW%^A storage closet%^RESET%^");
   set_long("%^YELLOW%^This is a small storage room and it is a mess.  Piled up"+
   " all over the room are bolts upon bolts of cloth.  In one small place on the "+
   "west wall is a %^BOLD%^%^WHITE%^plaque%^YELLOW%^.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^Fresh cloth and dank sweat intermingle and assault your senses.");
   set_listen("default","%^RESET%^%^BLUE%^Silence permeates the air, causing your ears to ring.");
   set_items(([
    ({"bolts","cloth"}) : "%^YELLOW%^There are stacks upon stacks of bolts of cloth.  "+
       "Silk, satin, muslin, broadcloth... all types are here.  The ones laying on "+
       "the top of the piles appear newer while some on the bottom of the "+
       "piles appear a bit dusty or musty.%^RESET%^",
    "plaque" : "%^YELLOW%^This plaque is covered in dust.  As you examine it "+
       "further you can make out a quote.. '%^CYAN%^If the sky is the limit, why must "+
       "prices be set?%^YELLOW%^'  - %^RED%^Smegma Torner%^YELLOW%^, self-proclaimed master tailor%^RESET%^",
    ]));
   set_exits(([
    "out" : LROOMS+"shop",
   ]));
//   set_door("brown door",LROOMS+"shop","out","lusell_shop_key","lock"); no keys on inside of doors.... *Styx*  1/4/03
   set_door("brown door",LROOMS+"shop","out");
   set_door_description("brown door", "%^MAGENTA%^This door is made from a dark brown wood that has an oddly shaped keyhole inset into the left side of it.%^RESET%^");
   set_locked("brown door",1,"lock");
   set_lock_description("brown door","lock","%^MAGENTA%^This is a strangely designed lock.  The keyhole is thin and is horizontal rather than vertical.  Several small holes line the edge of it, suggesting that whatever key fits this lock is quite complex.%^RESET%^");
   lock_difficulty("brown door",10,"lock");
}
