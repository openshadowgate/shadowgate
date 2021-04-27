// adding a zap for non-owners due to others camping out in the forge to get free materials, basically robbing them  *Styx* 3/24/06

#include <std.h>
#define GHOUSE "/d/player_houses/girruuth/"
inherit VAULT;

int searched;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("smithy",1); 
  set_name("GiGi's smithing room");
  set_short("GiGi's smithing room & forge");
  set_long("Upon entering this room, there is a %^RED%^wave of heat "
"%^RESET%^that hits you immediately.  The source of most of the heat "
"appears to be from the forging %^BOLD%^%^RED%^fire pit %^RESET%^in the "
"center of the room.  Surrounding the pit are four %^BOLD%^%^BLACK%^large "
"blackened anvils%^RESET%^.  Next to each anvil are a number of %^BOLD%^"
"tools and materials %^RESET%^needed to repair and create weapons and "
"armor.  %^ORANGE%^Animal-drawn carts%^RESET%^ sit along the walls, "
"filled with mostly metallic material.  On the ceiling above the forging "
"pit appears to be some sort of %^BOLD%^%^CYAN%^circle with ornate "
"carvings %^RESET%^along with a %^ORANGE%^grate%^RESET%^.  The walls to "
"the west and south have openings as though for doors but are currently "
"boarded shut."
  );
/*To the west is a door that leads another room and the south wall has a window built into a door that has been nailed shut.
*/
  set_smell("default", "There is a strong smell of sulfur from the coal fire.");
  set_listen("default", "The coals in the forge pop and crackle occasionally.");
  set_exits(([
//	"west" : GHOUSE+"training",
	"east" : GHOUSE+"shop",
  ]));
//  set_door("door", GHOUSE+"training", "west");
//  set_open("door",0);
  set_door("smith door","/d/player_houses/girruuth/shop","east");
//  set_open("shop door", 0); set on other side
  set_items( ([
	({"anvil", "anvils"}): "The %^BOLD%^%^BLACK%^large blackened anvils %^RESET%^have runes carved into them and appear to be quite heavy and unmovable.",
	({"tools", "material", "materials"}): "The tools include things like small ballpeen hammers, skinny stabbing tools for piercing rivet holes, tongs to handle the hot metal, and even a %^ORANGE%^water barrel %^RESET%^for quenching the metal and cooling the tools.",
	"barrel" : "%^ORANGE%^It is an old, well-used, and scorched barrel full of rusty, grimy water.",
	({"ceiling", "circle"}): "The ceiling has a %^ORANGE%^grate %^RESET%^and a carving roughly the shape of a circle which matches the %^RED%^fire pit %^RESET%^in size and position.  Occasionally some of the %^BOLD%^CYAN%^runes seem to glow%^RESET%^ but then fade out.",
	({"runes", "carvings"}) : "%^BOLD%^%^CYAN%^The runes form strange patterns and designs, which incorporate themselves within the whole circular carving.",
	({"pit", "fire pit"}) : "The fire pit appears to be about two feet deep and roughly ten feet in diameter.  The %^BOLD%^%^RED%^fire and heat %^RESET%^come from extremely hot coals in the pit itself.  There is a %^RED%^metal grate %^RESET%^covering the whole fire pit and divided into four sections, restricting access to the fire itself.",
	"grate" : "There is a ceiling grate and a forge grate, which one?",
	"ceiling grate" : "%^ORANGE%^The ceiling grate allows smoke out and a little light in, but appears to have a hood over it on the outside to keep rain out.  It is made of metal and built into the stone ceiling itself.  It does not appear to be openable in any way.",
	"forge grate" : "%^RED%^The metal grate over the forge pit is red from the heat %^RESET%^and is divided into four sections, one for each anvil.  A %^BOLD%^%^BLACK%^metal hatch %^RESET%^allows access to the fire pit.",
	({"hatch", "metal hatch"}) : "%^BOLD%^%^BLACK%^The metal hatch near each of the anvils allows fuel to be fed into the pit and metals to be placed to soak in the %^RED%^intense heat%^BLACK%^.  There is a long rod which allows the hatch to be opened without burning yourself.",
	({"cart", "carts"}) : "%^ORANGE%^The wooden carts hold various items of value and waste.  There doesn't appear to be any order as to what cart holds what material, as most anything could be found in them.  The carts are small enough to be drawn by one steed only.",

/*
*searching the cart-could find random quality material, once per reboot if allowed.
	"west door:  The door leads to the arena and sounds and scenes of combat can be
heard and seen if you concentrate on the area.
look window, look south door:  the south door has a window opening meant to pass
small goods to someone on the other side in the stables. (same interaction and rules
for the stables room regarding passing items)
*/
  ]) );
   set_search("cart", (: TO, "search_cart" :) );
   set_search("carts", (: TO, "search_cart" :) );
}

void search_cart(string str) {
   if(searched) {
     write("The carts don't seem to have any usable metals just now.");
     return;
   }
   if(member_array(TPQN, GHOUSE"shop"->query_owners()) == -1) {
	write("%^BOLD%^%^BLUE%^A glyph on the cart explodes and stuns you as you try to rob the shop's store of materials.");
	tell_room(TO, "%^BOLD%^%^BLUE%^As "+TPQCN+" digs through the carts of materials, a glyph explodes.", TP);
	TP->set_paralyzed(20 + random(15),"%^BOLD%^%^BLUE%^You are stunned from the explosion and feel your energy drained!%^RESET%^");
	TP->use_stamina(30);
	searched = 1;
	return;
   }
   write("You search the carts and find some usable metal.");
   tell_room(ETP,TPQCN+" searches through the carts and seems to find some usable metal.", TP);
   new("/std/obj/metal.c")->move(TO);
   searched = 1;
   return;
} 

void reset() {
   ::reset();
   if(!present("iron anvil")){
   }
   switch(random(10)) {
	case 0..3 : 	break;
	case 4:  tell_room(TO, "%^BOLD%^%^CYAN%^The runes from the circular carvings on the ceiling glow brightly, then fade just as quickly.");
			break;
	case 5:  tell_room(TO, "%^RED%^The fire flares up, popping and crackling as it illuminates the room and sends a blast of heat over the pit wall.");
			break;
	case 6:  tell_room(TO, "%^BOLD%^%^CYAN%^The runes on the ceiling above the fire seem to glow, or perhaps it's just the way the fire reflects off of it.");
			break;
	case 7:  tell_room(TO, "%^CYAN%^You hear faint sounds, perhaps voices, from nearby rooms.");
			break;
	case 8:  tell_room(TO, "%^ORANGE%^Wisps of smoke waft up from the fire pit and out a grate near the ceiling.");
			break;
	case 9:  tell_room(TO, "%^BOLD%^%^RED%^A bit of coal or wood in the fire pit pops and sparks fly about the room.");
			break;
   }
}
