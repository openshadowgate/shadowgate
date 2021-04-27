#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Dwarvenkingrobe");
	set_id(({ "robe" }));
set_short("%^RED%^King %^BOLD%^%^BLUE%^Thorvald %^RED%^'The Goblin Grinder' %^BLUE%^Steelboot's %^RESET%^%^RED%^Robe Of War%^RESET%^");
	set_obvious_short("%^RED%^A bloodred robe, with %^BOLD%^%^BLACK%^silver linen%^RESET%^");
	set_long(
@AVATAR
%^RED%^King %^BOLD%^%^BLUE%^Thorvald %^RED%^"The Goblin Grinder" %^BLUE%^Steelboot's %^RESET%^%^RED%^Robe Of War%^RESET%^ %^GREEN%^used to be worn by the mighty dwarven king in his many battles for Tempus. The robe is a color of deep %^RED%^red%^RESET%^%^GREEN%^, with a %^BOLD%^%^BLACK%^silver linen %^RESET%^%^GREEN%^around the edges. It was granted to %^CYAN%^Ungrim Ironfist%^GREEN%^ at a later date, for his courageous defense of the city of shadow, in %^RED%^The Great Demon Attack of 598 SG%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^CYAN%^I grant Ye me fine robe, for ye saviour of us all from the hideous beast from the north.

%^GREEN%^Signed

%^BOLD%^%^BLUE%^King Thorvald %^RED%^"The Goblin Grinder" %^BLUE%^Steelboot%^RESET%^

AVATAR
	);
     set("langage","dwarvish");	set_weight(4);
	set_value(500);
	set_lore(
@AVATAR
The robe was given to Ungrim, for his dedicated efforts to slay the Great Demon of Antioch.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(-2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set("strbonus",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^RED%^As "+ETOQCN+" wears the "+query_short()+", he gleams with power.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^As you wear the "+query_short()+", you feel powerful as %^BLUE%^Thorvald Steelboot%^RED%^ himself.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^RED%^As "+ETOQCN+" removes the "+query_short()+", the gleam of power disapears.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^As you remove the "+query_short()+", you feel the power disappear.%^RESET%^");
	return 1;
}
