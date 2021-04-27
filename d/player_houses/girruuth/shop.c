/* Notes:  The paintings have glyphs of protection on the frames to protect them from anything but powerful magic.  If anyone decides to RP out stealing or damaging them, it should be difficult at best.
*/
/* adding Shay (Shayland), non-precedent setting as a non-hm.  Girruuth is to explain he's really only supposed to have limited access and to play it that way until we get a second level of access coded in for PC employees. Adding Thayil as well*/
//Adding Nom on Tengri's request - Circe 9/7/04
// Gwen traded majority interest to Godzilla, removed non-owners who are gone, adding Kiervalan as an employee for Godzilla
// added Drille on request by godz.
// nienne, 07/08
#include <std.h>
#include <daemons.h>

#define GHOUSE "/d/player_houses/girruuth/"
//#define TCITY GHOUSE
#define TCITY "/d/dagger/Torm/city/"
#define PSTORE "/std/pstore"

inherit PSTORE;

#define MAX_ITEMS 10

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_owners(({"gwenhwyfar","tengri","godzilla","quinnen","cedric","drille"}));
  set_storage(GHOUSE+"sell");
  set_drop_storage(GHOUSE+"repairs");
  set_drop_deposit(500);   // owner can specify, but setting static here
  set_items_allowed( ({ "armor", "weapon" }) );
  set_name("GiGi's");
  set_short("GiGi's");
  set_long("The shop interior is well lit with %^BOLD%^magical lighting "
	"%^RESET%^in various shades of %^YELLOW%^yellows %^RESET%^and %^BOLD%^"
	"%^CYAN%^soft white%^RESET%^.  Intricate %^BOLD%^oil paintings %^RESET%^"
	"hang on the south wall, one on each side of the door to the street.  There "
	"are several simple %^ORANGE%^wooden chairs %^RESET%^sitting about the room."
	"  The room is cut off almost in half by a %^ORANGE%^wooden counter "
	"%^RESET%^which runs east to west from wall to wall.  There is a %^BLUE%^"
	"book %^RESET%^of some kind on the counter.  There is a vault door "
	"behind the counter that is rather ornate, with many rune carvings on "
	"the door frame itself.  On the wall to the left of the vault door is a "
	"%^BOLD%^%^GREEN%^sign %^RESET%^to list the shop's offerings."
  );
  set_smell("default", "There is a strong smell of sulfur from the smithing fires.");
  set_listen("default", "You hear the sounds of a crackling fire and metal upon metal from the west.");
  set_exits(([
	"south":TCITY+"c38",
	"west" : GHOUSE+"forge",
	"east" : GHOUSE+"bedroom",
  ]));
  set_door("shop door",TCITY+"c38","south");  //no key here so people don't get locked in
  set_door("bedroom door", GHOUSE+"bedroom", "east", "gir_key");
    set_open("bedroom door",0);
//      "/d/player_houses/girruuth/bedroom"->set_open("bedroom door", 0);
    set_locked("bedroom door", 1);
//      "/d/player_houses/girruuth/bedroom"->set_locked("bedroom door", 1);
    lock_difficulty("bedroom door", "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "lock");
  set_door("smith door", "/d/player_houses/girruuth/forge", "west", "gir_key");
    set_open("smith door",0);
//    "/d/player_houses/girruuth/forge"->set_open("smith door", 0);
    set_locked("smith door", 1);
//      "/d/player_houses/girruuth/bedroom"->set_locked("smith door", 1);
    lock_difficulty("smith door", "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "lock");
  set_items( ([
	({"light", "lights", "lighting"}): "The lights dance about in the corners of the room, changing occassionaly from %^YELLOW%^yellow %^RESET%^to a %^BOLD%^%^CYAN%^bluish white %^RESET%^and then back to %^YELLOW%^yellow%^RESET%^.",
	"counter": "The counter is slightly taller than waist height for most humans and
goes to the floor.  It has a %^BLUE%^log book %^RESET%^which looks attached and secure.",
	({"book", "log book"}): "The book is a log book which shows who has come here and what services they requested.  The book glows slightly with a %^BOLD%^%^BLUE%^bluish aura%^RESET%^, or perhaps it's just the way the light shines off of it.",
	({"wall", "walls"}): "There are several walls, but the southern wall and back wall are the most interesting.",
	"back wall": "A sign hangs on this wall and the door frame has intricate carvings.",
	"south wall": "Two exquisite oil paintings hang on this wall, one on each side of the door.",
	"paintings": "There are two exquisite oil paintings on the south wall.  The west painting depicts %^BOLD%^%^RED%^a battle %^RESET%^and the east one depicts a scene of %^GREEN%^pastoral serenity%^RESET%^.  Both have strange glyphs on their frames.",
	"glyphs" : "The glyphs are arcane symbols and perhaps magical in nature.",
	"sign": "The sign proclaims - '%^BOLD%^Gigi's armor and weapon repair "
	   "now open!\n  It will cost you a mere %^YELLOW%^"+TO->query_deposit()+
	   " %^WHITE%^gold deposit to leave your weapon or armor with the clerk "
	   "for repair and later pickup.  Actual repair cost with the balance to "
	   "be paid on pickup will be at the discretion of management.'",
	({"vault door", "frame"}): "The vault door and frame have intricate carvings upon them and look to be made of some sort of stone material.  It looks quite sturdy and impenetrable.",
	"painting": "There is a west painting and an east painting, which are you looking at?",
	"plaque": "There is a %^YELLOW%^brass plaque %^RESET%^and a %^ORANGE%^bronze plaque%^RESET%^, which one?",
	"brass plaque": "%^YELLOW%^It reads:  '%^RESET%^%^MAGENTA%^Those who are free, never have need of a key.'",
	"bronze plaque": "%^ORANGE%^It reads:  '%^MAGENTA%^In the end, all shall be revealed.'",
	({"chair", "chairs" }) : "%^ORANGE%^Simple wooden chairs scattered around the room.  They are large enough and look sturdy enough even for large humanoids.",
	"east painting": (: TO, "epaint" :),
	"west painting": (: TO, "wpaint" :),
   ]) );
/*  maybe to add later....
read book:  (would list the contents of the book)
read sign:  (list the menu just like any old shop)
*/
//   new("/d/avatars/tsera/girruuth_box1.c")->move(TO); taking out per Gwen's request *Styx*
}

void init() {
   ::init();
   add_action("sit_chair", "sit");
}

int sit_chair(string str) {
   if(!str) {
     tell_object(TP,"The chairs look like a good place to sit.");
     tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
     return 1;
   }
   if(str == "chair") {
      tell_object(TP,"You sit on one of the wooden chairs.");
      tell_room(ETP,""+TPQCN+" takes a seat in one of the chairs.",TP);
      return 1;
   }
   return 0;
}


string epaint() {
    return("The painting depicts a bald, muscled man sitting in a %^GREEN%^"
"grassy meadow %^RESET%^as the focus with a %^GREEN%^forest scene %^RESET%^in "
"the background.  The man is wearing very simple clothing.  The shirt is an "
"%^BOLD%^%^GREEN%^emerald color %^RESET%^and he is wearing %^ORANGE%^dark tan "
"pants%^RESET%^.\n\nHe is facing toward you in a sitting position, but hunched "
"over slightly, so details of his face are hidden.  He is looking at a "
"%^BOLD%^%^MAGENTA%^rose-colored flower %^RESET%^in front of him.  All around "
"him are a few small %^YELLOW%^f%^CYAN%^e%^MAGENTA%^y%^RESET%^ creatures "
"flying above his head, sticking their tongues out and sprinkling %^BOLD%^%^CYAN%^"
"glittering dust %^RESET%^about.  In the background, a well lit lush %^GREEN%^"
"forest life %^RESET%^is taking place with %^ORANGE%^animals grazing%^RESET%^ "
"peacefully and looking around.  A %^MAGENTA%^lavender-colored panther %^RESET%^is "
"approaching from behind the man.\n\n%^B_YELLOW%^%^BOLD%^A brass plaque is "
"attached to the frame and has an inscription on it.%^RESET%^");
}

string wpaint() {
   return("%^BOLD%^%^RED%^This painting depicts a bald, well-muscled "
"warrior wearing a %^RESET%^%^GREEN%^breast plate %^BOLD%^"
"%^RED%^as armor, holding a %^RESET%^%^GREEN%^shield%^BOLD%^%^RED%^, and " 
"%^RED%^wielding an %^BLACK%^a%^WHITE%^x%^BLACK%^e %^RED%^as the focus of "
"a battle scene going on in the background.  Above the battle scene, the "
"%^WHITE%^brightness of the moon looms and shines %^RED%^on the left side "
"of the warrior.  %^BLACK%^Darkened clouds cast shadows %^RED%^on his "
"right side.\n\nThe axe-wielding "
"%^BLACK%^w%^WHITE%^a%^BLACK%^r%^WHITE%^r%^BLACK%^i%^WHITE%^o%^BLACK%^r "
"%^RED%^is engaged in battle with two shapes to his left "
"and right.  The shapes are both ghostly in appearance, but one is "
"%^WHITE%^white %^RED%^and the other is %^BLACK%^black%^RED%^.  In the "
"background where the larger battle is taking place, there are numerous "
"men and beasts fighting each other with %^RESET%^%^RED%^magic and "
"weapons %^BOLD%^%^RED%^alike.\n\nThe axe the warrior "
"is wielding is %^BLACK%^double-%^WHITE%^bladed%^RED%^.  The blade "
"facing the moon and %^WHITE%^white ghostly figure %^RED%^is %^BLACK%^"
"blackened steel%^RED%^.  The other axe blade is facing the %^BLACK%^darkened "
"sky %^RED%^and the %^BLACK%^blackened ghost %^RED%^with a %^WHITE%^silver "
"blade %^RED%^and %^WHITE%^glowing white aura%^RED%^. \n\n"
"%^RESET%^%^ORANGE%^There is a small bronze plaque attached to the frame.");
}


void reset() {
   string clerk, scribe;
   ::reset();
   clerk = "/d/player_stores/clerks/girruuth_shop";
   scribe = "/d/player_stores/clerks/gwen_scribe.c";
// have clerks to alternate now, so staffing all the time
//   if(query_night() == 1)  return;
   if(!present("shop clerk")) 
      if(!objectp(environment(find_object_or_load(clerk)))) 	
	find_object_or_load(clerk)->move(TO);
/*
   if(!present("scribe")) 
      if(!objectp(environment(find_object_or_load(scribe)))) 	
	find_object_or_load(scribe)->move(TO);
*/
      set_open("bedroom door",0);
      "/d/player_houses/girruuth/bedroom"->set_open("bedroom door", 0);
      set_locked("bedroom door", 1);
}
