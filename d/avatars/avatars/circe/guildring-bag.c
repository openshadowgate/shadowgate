//bag to represent the guild rings Aashaenael has collected in a plot by Myrkul
//~Circe~ 5/1/11
#include <std.h>

inherit OBJECT;

void create(){
	::create();
	set_name("canvas sack");
	set_id(({ "sack", "canvas sack", "bag", "canvas bag" }));
	set_short("%^RESET%^%^ORANGE%^a canvas sack%^RESET%^");
	set_long("This is a simple canvas sack without any sort of adornment. "+
         "Strangely, it has been filled with dozens of nondescript rings, "+
         "all of which seem to match. A quick glance shows nothing special "+
         "about either rings or sack.");
	set_value(3);
	set_lore("Inside the scratches on each ring, the careful eye will note "+
         "that the symbol of the thieves guild of Shadow can be discerned. It "+
         "is a dagger overlaid on top of a golden coin. Only an experienced eye "+
         "would catch on as the entire idea of the ring is to go unnoticed.");
      set_property("lore difficulty",15);
      set_weight(2);
}



