#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring" }));
	set_short("%^BOLD%^%^BLACK%^Shadow Thieves Guild Ring%^RESET%^");
	set_obvious_short("scuffed steel ring");
	set_long("This is a nondescript steel ring. Its like a wedding band, but made out of a nonprecious metal. 
");
	set_value(1);
	set_lore("Inside the scratches, the careful eye will note that the symbol of the thieves guild of Shadow can be discerned. It is a dagger overlaid on top of a golden coin. Only an experienced eye would catch on"
	" as the entire idea of the ring is to go unnoticed.
"
	);
    set_property("lore difficulty",15);
	set_size(2);
	set_property("enchantment",0);
}



