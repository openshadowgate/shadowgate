#include "/d/dagger/tonovi/town/short.h"

inherit VAULT;

void create(){
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors",0);
   set_short("Entryway");
   set_long("This wide opening is bordered on either side by "+
      "two buildings.  It is the entrance way to a small "+
      "store building.  The %^BOLD%^%^WHITE%^gray stone%^RESET%^ "+
      "road you are walking on continues up to an "+
      "%^GREEN%^old pine door%^RESET%^ that has been set into "+
      "the front of the store.  The entryway opens to meet "+
      "the tonovi bazaar directly to the south."
   );
   
   set_smell("default", "You smell several strange smells, especially strong are those of fruits.");
   set_listen("default", "You can hear the merchants peddling their wares from all around.");
   set_items(([
     ({"road","gray stone","stone road",
     "gray stone road"}) : "%^BOLD%^%^WHITE%^This gray stone "+
     "road continues up to the front door of the small building "+
     "at the north of this entryway and continues southward back "+
     "to the bazaar.%^RESET%^",
     ]));
     
   set_exits( ([
	"south" : RPATH "bazaar3",
    	"north" : "/d/player_houses/lusell/rooms/shop"
    ]) );

    set_door("old pine door", "/d/player_houses/lusell/rooms/shop", "north", "lusell_shop_key","lock");
    set_locked("old pine door",0,"lock");
    set_lock_description("old pine door","lock","%^MAGENTA%^This is "+
       "a strangely designed lock.  The keyhole is thin and is "+
       "horizontal rather than vertical.  Several small holes line "+
       "the edge of it, suggesting that whatever key fits this lock "+
       "is quite complex.%^RESET%^");
    set_door_description("old pine door", "%^GREEN%^This door is made from several thick and aged pine slabs.  The slabs have been woven together with a thick rope.  A knob sets on one side of it with a horizontal keyhole in the center of it.%^RESET%^");  
    lock_difficulty("old pine door",10,"lock");
}
