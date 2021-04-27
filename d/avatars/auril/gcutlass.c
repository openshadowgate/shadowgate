#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("glass cutlass");
	set_id(({ "cutlass", "sword", "weapon", "glass cutlass" }));
	set_short("%^BOLD%^%^WHITE%^Unbreakable%^RESET%^");
	set_obvious_short("A %^BOLD%^%^WHITE%^gl%^RESET%^a%^BOLD%^%^WHITE%^ss%^RESET%^ cutlass");
	set_long(
@AVATAR
This cutlass looks to be made out of perfectly cut %^BOLD%^%^WHITE%^glass%^RESET%^. The bladed edge of the cutlass looks to have been sharpened and has a cutting %^BOLD%^%^RED%^blood groove %^RESET%^along its edge. The basket-handle, also made of glass has been perfectly carved with smooth ridges for comfort while in the hand. Small etchings have been made in the glass along the basket archs and within the etchings it has been marked with a %^RESET%^%^MAGENTA%^purple ink%^RESET%^. The pommel of the blade is simple and light, just a small spike with a %^RESET%^%^BLUE%^steel tip%^RESET%^.

AVATAR
	);
	set_weight(8);
	set_value(10000);
	set_lore(
@AVATAR
This rare weapon was crafted for the great pirate Remmels. Remmels sailed the coasts of Deku and traded with the continent often through black trade networks with his smuggled goods. While on a raid, he happened upon a wizard who was being held captive by the merchant. On oath of release, the wizard was commissioned to have created (with the help of his most trusted craftsmen, Kerolys) a perfectly glass blade. This had been a dream of the pirate for many years. The blade made and the oath fulfilled, the wizard left the pirate to his days. Not a week later, word of the pirate's ship sunk and the demise was heard throughout the shipyards and cove. Rumors say the pirate survived and the blade still lives on, for this was to have happened thirty years ago. Others say the sword has been spotted near the coastal regions of Torm. Or...it could be at the bottom of the ocean.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You realize how smooth the grip is as you wield the glass blade.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
