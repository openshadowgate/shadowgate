#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Fine Elven Robe");
	set_id(({ "robe", "garmet", "elven robe", "fine elven robe", "armor" }));
	set_short("A finely made elven robe.");
	set_obvious_short("A Fine Elven Robe");
	set_long(
@AVATAR
This is a long delicate robe made from a pale, leaf green silk.  It has a wide rounded neck with gold trim.  The sleeves are long and loose.  The robe fits snugly to the waist and flares out from the bodice to just above the floor.  Dark green embroidery depicts a vine and leaf motif around the hem, with some tendrils reaching up almost to the waist.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(2);
	set_value(1500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(2);
}


