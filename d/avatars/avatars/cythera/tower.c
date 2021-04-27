#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   	set_name("copper shape");
   	set_short("%^ORANGE%^A copper and steel cylindrical shape%^RESET%^");
   	set_id(({"tower","shape","copper","steel","object","plot_obj"}));
   	set_long("Rising out of"+
		" the ground is a bronze and steel cylindrical shape."+
		"  Standing at least ten feet into the air, the metal"+
		" object looks almost like a small enclosed tower.  "+
		"Cut into the tower are seven vacant holes.  The holes"+
		" offer no view inside the metal shape, but look as if "+
		"they were once crafted to hold something, which is now "+
		"long gone.  There are no apparent doors or entry ways "+
		"inside the metal shape.  Waves of extremely powerful magic"+
		" emanate from the tower like shape.");
   	set_weight(10000);
 }