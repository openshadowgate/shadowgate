#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("golden cuff bracelet");
	set_id(({ "cuff bracelet", "bracelet", "golden cuff bracelet" }));
	set_short("%^YELLOW%^a %^RESET%^ORANGE%^golden %^YELLOW%^cuff bracelet%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^Designed to expand or shrink to fit the size of a wearer's arm, this cuff bracelet is made from some of the purest %^RESET%^%^ORANGE%^gold%^YELLOW%^ metal.  Fanciful designs are etched onto its surface, swirling and enchancing the luster of the metal.  At the center a square cut %^RED%^ruby%^YELLOW%^ has been set, flanked by two leaf shaped %^GREEN%^emeralds%^YELLOW%^ to either side.  This gives the bracelet's design a very natural feel despite the metal that makes it.%^YELLOW%^ Clearly made by a master jeweler, there is a small mark on the underside that appears to be writing.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^ORANGE%^A gift for those who help without thought of reward.  %^YELLOW%^A.P.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(200);
	set_lore(
@AVATAR
%^RESET%^%^ORANGE%^It is said that this cuff bracelet and others like it were made for the owner of the Crown and Castle Inn of Tabor as a gift for a few special people who aided him in a time of need.  Though who crafted them isn't known, it is rumored that they were made by one of the many patrons who often frequent the well known Inn.
%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set("chabonus",1);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
}


