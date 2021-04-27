
#include <std.h>
#include <daemons.h>

#define KHOUSE "/d/player_houses/kiervalan/"
#define PSTORE "/std/pstore"

inherit PSTORE;

#define MAX_ITEMS 10

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_owners(({"kiervalan"}));
  set_storage(KHOUSE+"sell");
  set_drop_storage(KHOUSE+"repairs");
  set_drop_deposit(500);   // owner can specify, but setting static here
  set_items_allowed( ({ "armor", "weapon" }) );
  set_name("The Pack's Creche");
  set_short("%^RESET%^%^ORANGE%^The Pack's Creche%^RESET%^");
  set_long("%^RESET%^%^ORANGE%^This shop is a small building that is nestled in the forest "+
  "outside the city, though what it lacks in size it makes up for in how amazingly "+
  "everything has been arranged to make use of every square foot of space. As you walk "+
  "into the shop on either side of you are %^BLACK%^%^BOLD%^twin dummies%^RESET%^%^ORANGE%^, "+
  "with various pieces of %^RESET%^armor%^RESET%^%^ORANGE%^ draped off of them. "+
  "A %^RESET%^%^CYAN%^counter%^RESET%^%^ORANGE%^ runs along the north, east, and southern "+
  "walls and behind it are even more %^BLACK%^%^BOLD%^weapons%^RESET%^%^ORANGE%^ and "+
  "pieces of armor ready for sale. The store is lit with %^BLACK%^%^BOLD%^lanterns%^RESET%^%^ORANGE%^ "+
  "that hang from the high vaulted ceiling and has a comfortable yet oddly hurried feeling. "+
  "The only section of wall not covered in equipment for sale is right center of the eastern "+
  "wall, which hangs a %^BLACK%^%^BOLD%^large banner%^RESET%^%^ORANGE%^.%^RESET%^\n");
  set_smell("default", "%^RESET%^%^ORANGE%^you smell well oiled leather and cold steel.%^RESET%^");
  set_listen("default", "%^BLACK%^%^BOLD%^You hear other shoppers talk about the different items for sale.");
  set_exits(([
	"east": "/d/shadow/room/village/path12",
	"archway" : KHOUSE+"forge",
  ]));
  set_door("door", "/d/player_houses/kiervalan/forge", "archway", "wolf key");
    set_open("door",0);
    lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "lock");
  set_items( ([
	({"light", "lights", "lighting"}): " .",
	({"book", "log book"}): "The book is a log book which shows who has come here and what services they requested.  "+
	"The book glows slightly with a %^BOLD%^%^BLUE%^bluish aura%^RESET%^, or perhaps it's just the way the light shines off of it.",
	({"wall", "walls"}): "There are several walls, what direction?",
	({"east wall", "eastern wall"}): "%^RESET%^%^ORANGE%^The eastern wall has the entrance way, or the way out, "+
	"depending on your idea.%^RESET%^",
	({"south wall", "southern wall"}): "%^BLACK%^%^BOLD%^Rows upon rows of swords, spears, and various "+
	"sets of %^RESET%^%^ORANGE%^leather armor%^BLACK%^%^BOLD%^ hang on the wall%^RESET%^.",
	({"north wall", "northern wall"}): "There is a heavy vault door on the northern wall behind the counter.",
    ({"west wall", "western wall"}): "Two exquisite oil paintings hang on this wall, one on each side of the door.",
	"sign": "The sign proclaims - '%^BOLD%^The Pack's Creche!\n  It will cost you a "+
	   "mere %^YELLOW%^"+TO->query_deposit()+
	   " %^WHITE%^gold deposit to leave your weapon or armor with the clerk "
	   "for repair and later pickup.  Actual repair cost with the balance to "
	   "be paid on pickup will be at the discretion of management.'",
	({"vault door", "frame"}): "%^BLACK%^%^BOLD%^The vault door and frame have intricate carvings upon them and look to be made of "+
	"some sort of stone material.  It looks quite sturdy and impenetrable.%^RESET%^",
	"painting": "There is a west painting and an east painting, which are you looking at?",
	"plaque": "There is a %^YELLOW%^brass plaque %^RESET%^and a %^ORANGE%^bronze plaque%^RESET%^, which one?",
	"counter": "%^RESET%^%^CYAN%^The heavy glass counter is filled with all manner of weapons and armor from the mundane "+
	"to the exotic. All along the edge of the glass are runes carved into the panes, and you wonder if they have been "+
	"enchanted to ensure that merchandise is safe from fast hands or sticky fingers.%^RESET%^'",
	({"banner", "flag" }) : "%^BLACK%^%^BOLD%^This fine black silk banner hangs on the wall, taking up "+
	"what could have been filled with even more weapons and armor. In the center of the banner is "+
	"a %^WHITE%^stark white wolf's paw print%^BLACK%^%^BOLD%^ that almost glows in its contrast.%^RESET%^",
   ]) );

}

void reset(){
    ::reset();
    if(!present("clerk")){new("/d/player_stores/clerks/kiervalan.c")->move(TO);}
}
