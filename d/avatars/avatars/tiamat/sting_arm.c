#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armband");
	set_id(({ "armband" }));
	set_short("%^BOLD%^%^BLACK%^dark hide %^WHITE%^a%^RED%^r%^WHITE%^m%^BLACK%^band%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^dark hide %^WHITE%^a%^RED%^r%^WHITE%^m%^BLACK%^band%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a simple loop of dark tanned hide, smooth to the touch.  It could properly be worn as an armband just under the shoulder.  The band has a round %^WHITE%^insignia%^BLACK%^ stitched in its center: Made from felt, it depicts a round, white %^WHITE%^field%^BLACK%^ with a prominent blood red %^RED%^scorpion stinger%^BLACK%^.  It smells strongly of new leather.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2);
	set_lore(
@AVATAR
%^BOLD%^%^RED%^The insignia on this armband is used by a gang of bandits knows as the Sting Clan.  They are an entirely local group devoted to petty crimes and limit their activities to Quiet Forest and Royal Southern roads, primarily.  Their organizational structure or the identity of their leaders are unknown.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "left arm" }));
	set_size(2);
	set_property("enchantment",0);
}



