#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "broken ring", "assassin ring", "blood of the assassins ring" }));
	set_short("%^BOLD%^%^WHITE%^Ring of the Assassins%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^broken silver ring%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This %^BOLD%^%^WHITE%^silver ring %^RESET%^%^CYAN%^has been broken into two pieces. It appears, perhaps, as if it was not sufficiently repaired after wear and tear. Or maybe it was destroyed for some reason. Regardless, you notice a small %^BOLD%^%^WHITE%^inscription %^RESET%^%^CYAN%^set into the band if you try to examine it carefully.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Blood of the Assassins%^RESET%^

AVATAR
	);
     set("langage","goblin");	set_weight(2);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^It is said that this ring is passed down by the goblin assassin, Harthugg, himself to those he feels worthy of taking his place and sharing his abilities in due time. This is a treasured item among the %^BOLD%^%^BLACK%^goblin assassins%^BOLD%^%^WHITE%^. It is so sacred, that supposedly, even the %^RESET%^%^YELLOW%^goblin king %^BOLD%^%^WHITE%^does not know that they exist. Apparently, one of the %^RESET%^%^RED%^goblin sorcerers %^BOLD%^%^WHITE%^placed a small %^RESET%^%^CYAN%^enchantment %^BOLD%^%^WHITE%^upon the ring to give the wearer added protection.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set("dexbonus",1);
}
