//Octothorpe (4/12/10)
//Belendithas HM House

#include <std.h>
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(SLICK_FLOOR);
   set_property("smithy",1);
   set_name("Vast Workroom");
   set_short("%^RESET%^%^MAGENTA%^V%^BOLD%^as%^RESET%^%^MAGENTA%^t "+
      "%^RED%^W%^BOLD%^or%^RESET%^%^RED%^k roo%^BOLD%^m%^RESET%^");
   set_long("%^RESET%^%^RED%^You have entered a large work room with "+
      "high %^BOLD%^%^BLUE%^dark%^RESET%^%^RED%^ ceilings, %^ORANGE%^"+
	  "lit %^RED%^by %^YELLOW%^candles%^RESET%^%^RED%^ and perhaps "+
	  "even magic.  There are rows upon rows of tables which hold bolts of cloth for tailoring, billets of metals for smithing, hides and skins for various other crafts.  Some of the tables have stacks of papers, perhaps invoices or notes for designs of items.  In the very center of this large works space is a %^BOLD%^%^WHITE%^brand%^BLACK%^ new%^RED%^ forge%^RESET%^%^RED%^, lit by its glowng embers and some indirect light from the high celing above. Near the forge are barrels of water and a polishing table with clean, unused stacks of cloth.%^RESET%^");
        set_smell("default","You smell burning coal, hot metal and...brimstone?");
        set_listen("default","You hear the crackling of a fire.");
        set_items(([
           ({"forge","Forge"}) : "%^BOLD%^%^BLUE%^The contraption before you seems to be the finest quality and perhaps the taletale mechanisms of tinker gnomes.  There are hinged arms, a few small cranes built of pulleies, ropes and metal stranded cables.  A shiny pedal near the smith's working space at the forge seems to cause the complicated billows to heat up the coals.  Many of the devices built near and around the forge look as though they might have been intended to aid a worker with little strength to move heavy metals or other items that may be to hot to touch with the merest of efforts.  The the workshop around the forge is large enough for a factory, this forge seems to be designed for only one person to use.%^RESET%^",
        ]));
        set_exits(([
           "southwest" : "/d/player_houses/belendithas/rooms/pawnshop",
        ]));
set_door("sliding door","/d/player_houses/belendithas/rooms/pawnshop","southwest",0);
	set_door_description("sliding door", "%^RESET%^%^ORANGE%^This simple door is a pocket door that slides right into the wall when opened and fits nearly perfectly with the wall when closed.  It is made of a tarred pine and seems well used.%^RESET%^");
}

