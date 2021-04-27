#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   	set_name("topaz");
   	set_short("%^RESET%^%^ORANGE%^A large topaz%^RESET%^");
   	set_id(({"topaz","large topaz","plot_topaz"}));
   	set_long(
@CYTHERA
%^ORANGE%^Larger than a human male's fist this fractured and cracked topaz has numerous flaws deep within the deep golden crystals.   The square cut topaz has a slightly convex surface, with the opposite side narrows down to a point.  Almost as if it was made to be inserted into something.  With all its flaws you don't get the feeling this topaz would fetch much gold if sold.%^RESET%^
CYTHERA
);
	set_lore(
@CYTHERA
Even in this condition the topaz radiates a strong aura of magic that even you can detect without the aid of magic.  A topaz this size must have some tales or legends to it.  Though you are going to have to dig further to find anything.  OOC Please Mail Cythera what you are planning to do in your research.
CYTHERA
	);
	set_property("lore",20);
   	set_weight(3);
   	set_value(0);
 }
int isMagic(){
 int y;
 y = ::isMagic();
 y = y + 5;
 return y;
}
