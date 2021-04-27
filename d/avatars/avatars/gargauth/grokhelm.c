#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("helm");
	set_id(({ "helm", "thiefhelm", "helmet", "grokhelm", "coif", "leather" }));
	set_short("%^BOLD%^%^WHITE%^Leather Helm of Dexterity%^RESET%^");
	set_obvious_short("leather helmet");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This helmet seems fitted for a goblin. It smells putrid, has holes in it, and seems to be leaking some kind of %^YELLOW%^yellow ooze%^BOLD%^%^WHITE%^ out of the side. However, it still seems to have a strange sparkle, amongst all of this filth.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Blood of the Assassins%^RESET%^

AVATAR
	);
     set("langage","goblin");	set_weight(3);
	set_value(750);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^The goblin assassin, Harthugg, once wore this helm himself. He seems to have busted it from use slaying his victims over the years. Fortunately, he had a goblin sorcerer place an eerie enchantment upon it, that possibly went wrong. The only thing holding it together now is the %^YELLOW%^yellow ooze %^BOLD%^%^WHITE%^that leaks from it. However, this %^YELLOW%^ooze %^BOLD%^%^WHITE%^contains strong magical properties that are worth keeping this filthy item in existence.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set("dexbonus",1);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",1);
	set_ac(1);
}



