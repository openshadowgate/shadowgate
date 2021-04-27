#include <std.h>
inherit "/d/common/obj/armour/banded";

void create(){
	::create();
	set_name("bandedtest");
	set_id(({ "banded armor", "banded", "armor", "banded mail" }));
	set_short("A suit of banded armor");
	set_obvious_short("A suit of banded armor");
	set_long("This armor is made up of overlapping strips of metal sewn to a backing of leather and chainmail. Generally the strips cover only the vulnerable areas, while the chain and leather protect the joints, w"
	"here freedom of movement must be assured. Through straps and buckles, the weight is more or less evenly distributed.
"	);
	set_value(250);
	set_size(2);
	set_property("enchantment",1);
}



