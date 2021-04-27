#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("gold dragon");
	set_id(({ "sword", "blade", "longsword", "long sword", "gold dragon" }));
	set_short("%^BOLD%^%^YELLOW%^Illiysrial, the gold dragon%^RESET%^");
	set_obvious_short("An %^BOLD%^%^YELLOW%^ex%^BOLD%^%^WHITE%^qui%^BOLD%^%^YELLOW%^sit%^BOLD%^%^WHITE%^e %^RESET%^longsword");
	set_long(
@AVATAR
The ornate long sword looks to be in perfect condition. The %^BOLD%^%^WHITE%^adamantite %^RESET%^blade looks exteremely durable and is surrounded by a %^BOLD%^%^YELLOW%^golden %^RESET%^mist. The mist leaves a golden trace through the air as it moves. %^BOLD%^%^BLUE%^Ancient runes %^RESET%^line the length of the blade in a language long forgotten. The hilt of the blade looks to be of two %^BOLD%^%^YELLOW%^gold dragon %^RESET%^claws outstretched to the sides. The handle of the sword is made up of a long light %^RESET%^%^ORANGE%^amber %^RESET%^shards which are placed in such a way to make it look like scales. The pommel of the blade is heavy, made out of an orb of %^BOLD%^%^CYAN%^crystal%^RESET%^.

AVATAR
	);
	set_weight(14);
	set_value(10000);
	set_lore(
@AVATAR
Crafted by the great Artificer, Carcascus, the dragon blades were a tribute to the fourth King of Asgard, Stararach, nearly
  six centuries ago. The swords were rumored to have the power to control dragons of a specific type as well as slay them.
  After the collapse of the kings reign, Stararach's precious weapons were lost to history.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,12);
	set_large_wc(1,8);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^An ancient power flows into you as you wield the weapon.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^The power feels as if it is literally leaving your fingertips as you release the blade completely.");
	return 1;
}
