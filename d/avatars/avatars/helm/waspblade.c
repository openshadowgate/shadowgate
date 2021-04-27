#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Blade of the Wasp");
	set_id(({ "blade", "weapon", "sword", "longsword", "long sword", "blade of the wasp", "waspblade" }));
	set_short("%^RESET%^%^GREEN%^Blade of the Wasp%^RESET%^");
	set_obvious_short("ornate longsword");
	set_long(
@AVATAR
This sword is straight-bladed, double-edged and only marginally shorter than your normal longsword. It carries the marks of elven craftsmanship and writings in a gently flowing script can be seen along the length of the blade.

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^GREEN%^'Until the stones forget'%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(7);
	set_value(368);
	set_lore(
@AVATAR
These blades originally hail from a clan of wood elves in the remote west. Being hard pressed by orc-kin they created the swords and imbued them with the magic of nature, resulting in several different kinds of magic weapons.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,12);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+" feints and gashes "+targ->query_cap_name()+" badly.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^GREEN%^You feint and gashes "+targ->query_cap_name()+" deeply.%^RESET%^");
	tell_object(targ,"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+" feints and gashes you badly.%^RESET%^");
		return roll_dice(1,6)+0;	}
}