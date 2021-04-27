#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Boots of Enlightenment");
	set_id(({ "boots" }));
	set_short("%^BOLD%^%^BLACK%^Boots of%^RESET%^%^CYAN%^ Enlightenment%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Boots of%^RESET%^%^CYAN%^ Enlightenment%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These knee-high boots are made from black leather that has been polished to a high %^RESET%^sheen%^BOLD%^%^BLACK%^.  The sole and heel are heavily treaded as to be slip proof, giving them a slight lift which adds about 1" to the wearer's height. This boot has a %^RESET%^%^BOLD%^steel%^BLACK%^ reinforced toe so the wearer's foot will be well protected. There is a series of %^RESET%^%^BOLD%^silver buckles%^BLACK%^ on the outside of the boot starting just above the little toe and ending at below the knee, just about where the boot itself ends.  Around the heel is a %^RESET%^%^BOLD%^silver plate%^BLACK%^ that has some writing on it.  A man would feel cool wearing these boots!

AVATAR
	);
	set("read",
@AVATAR
Enlighten your mind.

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(4000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^These boots were worn by Auppenser in his mortal days.  Upon his death, then ascension he had them enchanted so he could wear them on his spiritual form.  He is never without these boots.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",30);
	set_ac(50);
}


