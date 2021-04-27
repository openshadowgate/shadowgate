#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("contraption");
	set_id(({ "contraption" }));
	set_short("a strange contraption");
	set_obvious_short("a strange contraption");
	set_long(
@AVATAR
Large and bulky, the shiny metal cube is covered in a confusion of colorful wires and copper tubes.  Two pipes stick out of the top, one belching smoke, while the other belches steam at odd intervals.  Six glistening jewels can be seen on what is presumably the front, while a lever with a leather handle can be seen on the right side.  On the other side is a drawer that could probably be pulled open. 

AVATAR
	);
	set_weight(150);
	set_value(0);
	set_max_internal_encumbrance(100);
	set_type("clothing");
	set_limbs(({ "left arm", "right leg" }));
	set_size(1);
	set_property("enchantment",0);
}


