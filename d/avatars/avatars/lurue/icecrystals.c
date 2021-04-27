#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("ice crystals");
	set_id(({ "crystals", "icecrystals", "ice crystals" }));
	set_short("%^BOLD%^%^CYAN%^a set of s%^WHITE%^p%^BLUE%^a%^RESET%^r%^BOLD%^%^CYAN%^kl%^RESET%^i%^BOLD%^%^WHITE%^n%^CYAN%^g ice crystals%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^a set of s%^WHITE%^p%^BLUE%^a%^RESET%^r%^BOLD%^%^CYAN%^kl%^RESET%^i%^BOLD%^%^WHITE%^n%^CYAN%^g ice crystals%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This set of s%^WHITE%^p%^BLUE%^a%^RESET%^r%^BOLD%^%^CYAN%^kl%^RESET%^i%^BOLD%^%^WHITE%^n%^CYAN%^g ice crystals is made up of hundreds of little crystals, each and everyone of which holds something within its reflection.  Just looking casually, you can see armor, weapons and objects of power swirling about in the images.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
%^CYAN%^%^BOLD%^These ice crystals are formed within the core of a cloud and reflect the thoughts and imaginations both from within and without.  By looking closely, you can almost reach out and grab what you see, through the clear shade of the ice.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",30);
	set_max_internal_encumbrance(500);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",5);
}



