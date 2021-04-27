#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Mask");
	set_id(({ "mask" }));
	set_short("%^RESET%^%^RED%^f%^BOLD%^%^BLACK%^ac%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^of a god%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^b%^BOLD%^%^BLACK%^lac%^RESET%^%^RED%^k %^BOLD%^%^BLACK%^leather %^RESET%^%^RED%^m%^BOLD%^%^BLACK%^as%^RESET%^%^RED%^k%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This strange, black leather mask seems to be made of a material that provides a soft, comfortable face covering, but the leather is hard enough to keep a tight wrap around the wearer's face.  It seems strangely deep, as if it would wrap around, coming perhaps to the ears before it ends.  There are a number of swirling %^RESET%^%^RED%^r%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d e%^BOLD%^%^BLACK%^ngraving%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^around the edges of the mask, each woven with the next.  Three black strings can be tied behind the wearer's head, holding the mask in place.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
Masks come in many varieties, but this one seems unusual.  There are many rumors about the mask or masks worn by the Shadowlord, each conflicting, and none with any real basis.  Perhaps the god himself wore this mask at one time.  Or, perhaps it is merely an exquisite mask.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",4);
}


