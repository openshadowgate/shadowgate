#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("thief");
	set_id(({ "thief crown", "crown" }));
	set_short("%^BOLD%^%^RED%^T%^BLUE%^h%^GREEN%^i%^YELLOW%^e%^MAGENTA%^v%^WHITE%^e%^BLUE%^s%^YELLOW%^ crown%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^T%^BLUE%^h%^GREEN%^i%^YELLOW%^e%^MAGENTA%^v%^WHITE%^e%^BLUE%^s%^YELLOW%^ crown%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^YELLOW%^This is a golden %^GREEN%^g%^RED%^e%^MAGENTA%^m%^YELLOW%^ studded circlet that is worth a small fortune. It is said to be worn by the Guildmaster of Shadow. Of course wether it means something has everything to do with the Guildmaster's dagger not his or her crown.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Honor among thieves

AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(10000);
	set_lore(
@AVATAR
%^YELLOW%^This circlet was worn by the Guildmaster %^BLACK%^Thieren%^YELLOW%^ in the time of SG 694. He was slain by a band of adventurers who discovered he was a plant for the clergy of %^BLACK%^Mask%^YELLOW%^. It is still used to this day to designate the Guildmaster of Shadow%^RESET%^.

AVATAR
	);
	set_property("lore difficulty",10);
	set("dexbonus",1);
	set("chabonus",1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
}



