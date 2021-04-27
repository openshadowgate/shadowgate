#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "ring of dexterity", "ring of dexterity +1", "dexterity ring", "silver ring" }));
	set_short("%^BOLD%^%^WHITE%^Ring of Dexterity +1%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a silver ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This %^BOLD%^%^WHITE%^silver ring%^BOLD%^%^BLACK%^ looks quite shiny, especially coming from the filth of a %^RESET%^%^GREEN%^goblin%^BOLD%^%^BLACK%^. It appears that a small %^BOLD%^%^WHITE%^inscription %^BOLD%^%^BLACK%^has been carved along the inside for distinction.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Blood of the Assassins%^RESET%^

AVATAR
	);
     set("langage","goblin");	set_weight(2);
	set_value(750);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^It is said that the goblin assassin, Harthugg, handed down these %^BOLD%^%^WHITE%^silver assassin rings %^BOLD%^%^BLACK%^to the promising within his kin. They are said to include magical powers enchanted by the %^RESET%^%^GREEN%^goblin sorcerers %^BOLD%^%^BLACK%^with the power of quickness and agility to those that wear them.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set("dexbonus",1);
}
