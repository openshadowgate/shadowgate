#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("serpent tooth");
	set_id(({ "tooth", "aysu's tooth", "serpent tooth", "large tooth" }));
	set_short("%^BOLD%^%^CYAN%^Aysu%^BLUE%^, %^BLACK%^Terror %^BLUE%^of the N%^BLACK%^i%^BLUE%^g%^BLACK%^h%^BLUE%^t %^BLACK%^S%^BLUE%^e%^BLACK%^a%^BLUE%^'s Tooth%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a large curved tooth%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This large curved tooth is over a foot in length and curves wickedly back with a jagged hook that is made only for one thing, taking hold of whatever its driven into and %^RED%^ripping %^WHITE%^it apart.  Around the top edge a ring of tiny %^CYAN%^scales%^WHITE%^ can be seen.  Looking a great deal like fish scales they appear to be growing out of the tooth.  A small hole has been drilled in the top with a %^RESET%^%^ORANGE%^leather %^BOLD%^%^WHITE%^cord run through it to allow the tooth to be hung about the neck or attached to a piece of armor or clothing.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1000);
	set_lore(
@AVATAR
This tooth was taken from Aysu, Terror of the Night Sea.  A creature long feared by fishermen and sailors.  Many are the people who claim to have seen or felt this great creature brush against their boat, but few are the ones who have lived to bring back a prize such as this.  Although, there are stories about a young group of adventurers who traveled between worlds and encountered Aysu in person.  So horrific was the creature, that it nearly destroyed the beach they were protecting, but the young group of heroes managed to send Aysu to the deep dark waters, where it is rumored she will return from one day.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}



