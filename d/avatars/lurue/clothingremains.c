#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("scrap of clothing");
	set_id(({ "clothing", "scrap", "scrap of clothing" }));
	set_short("scrap of clothing");
	set_obvious_short("scrap of clothing");
	set_long(
@AVATAR
There is little left to this bit of cloth, though you think it might have once been a lovely dress.  Now it is nothing more then a few scraps of dirty, rank cloth, covered in mildew and stained with resin, dirt and who knows what else. You can't think of a single reason to keep it, except that it might be used to identify the wearer.

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_lore(
@AVATAR
These remains appear to be a dress made by someone who took a great deal of care with what they were doing.  Had they not, these remains would have long ago been destroyed.  Looking closely, you think perhaps you could identify who made the garment just bye the intricate stitching.

AVATAR
	);
	set_property("lore difficulty",10);
}
