#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   	set_name("ruby");
   	set_short("%^BOLD%^%^RED%^A large ruby%^RESET%^");
   	set_id(({"ruby","large ruby","plot_ruby"}));
   	set_long(
@CYTHERA
%^BOLD%^%^RED%^Larger than a human male's fist this fractured and cracked ruby has numerous flaws deep within the deep red crystals.   The round cut ruby has a slightly convex surface, with the opposite side narrows down to a point.  Almost as if it was made to be inserted into something.  With all its flaws you don't get the feeling this ruby would fetch much gold if sold.%^RESET%^
CYTHERA
);
	set_lore(
@CYTHERA
Even in this condition the ruby radiates a strong aura of magic that even you can detect without the aid of magic.  A ruby this size must have some tales or legends to it.  Though you are going to have to dig further to find anything.  OOC Please Mail Cythera what you are planning to do in your research.
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
