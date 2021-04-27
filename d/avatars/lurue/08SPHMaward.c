#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wool overcoat");
	set_id(({ "coat", "overcoat", "jacket" }));
	set_short("%^RESET%^%^ORANGE%^a luxurious wool overcoat%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a luxurious wool overcoat%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^ORANGE%^Made from an exceptional quality of wool, this overcoat has been dyed a %^YELLOW%^rich shade of gold %^RESET%^%^ORANGE%^that complements almost any other style of clothing or color combination.  Sewn in a way that the coat can be worn over several layers of clothing, the greatcoat provides both warmth and comfort to the wearer without being too tight or heavy.  Wide in the sleeve and voluminous in the body, the coat has a high collar that can be turned up to protect the wearer's face and neck against the weather or left down to add a bit of roguish style.  %^BOLD%^%^WHITE%^Ivory buttons %^RESET%^%^ORANGE%^have been used on the cuffs and along the front to give a little contrast to the garment, while the interior has been lined in%^BOLD%^%^BLACK%^ black silk %^RESET%^%^ORANGE%^that gives the coat an overall luxurious feeling. %^RESET%^


AVATAR
	);
	set_weight(6);
	set_value(1200);
	set_lore(
@AVATAR
Created by the master tailors of the Scarlet Angel in Torm, this overcoat was commissioned as a one of a kind piece of tailoring for the winner of Honorable Mention for the First Annual Spring is Blooming Contest.  

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_ac(1);
}


