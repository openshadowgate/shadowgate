#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armor");
	set_id(({ "goblin armor", "armor" }));
	set_short("%^BOLD%^%^RED%^G%^MAGENTA%^o%^RED%^blin A%^MAGENTA%^r%^RED%^mor%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^G%^MAGENTA%^o%^RED%^blin A%^MAGENTA%^r%^RED%^mor%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This armor is made out of the tanned hides of critters. Its got bones hanging on it and all kind of goblin glitter. %^YELLOW%^Gold chains%^RED%^ hang around it along with %^WHITE%^finger bones%^RED%^ and fragmented %^GREEN%^luck charms%^RED%^. Overall it is an incongruous mess, but it demonstrates the prowess of a goblin huntress.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(1);
	set_lore(
@AVATAR
%^BOLD%^%^MAGENTA%^This armor was assembled by %^RESET%^%^ORANGE%^Goblin Headhunters%^BOLD%^%^MAGENTA%^ for their fearless leader, %^WHITE%^Quondangel%^MAGENTA%^ in the year 694 SG. She led a successful raid against the %^BLACK%^Maskarrans%^MAGENTA%^ which had attacked their ally Cyric. Quondagel slew the priest of Tharis, %^GREEN%^Pu Veridian%^MAGENTA%^ and brought his skull back to her church. She is a goblin hero for this bloody deed.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",5);
	set("conbonus",1);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(5);
}



