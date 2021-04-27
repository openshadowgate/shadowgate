#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Red Velvet Dress");
	set_id(({ "dress", "velvet dress", "red dress", "red velvet dress" }));
	set_short("%^BOLD%^%^RED%^Long Velvet Dress%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^red velvet dress%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is an exquisite dress made from a cherry red velvet.  The dress has a full back with a high half -collar.  The edges of the collar rest either side of a gently curving neckline that frames the wearer's decolette.  The sleeves are long and narrow and are l%^RESET%^%^RED%^ac%^BOLD%^%^RED%^ed %^RESET%^%^RED%^al%^BOLD%^%^RED%^on%^RESET%^%^RED%^g t%^BOLD%^%^RED%^he %^RESET%^%^RED%^to%^BOLD%^%^RED%^p s%^RESET%^%^RED%^ea%^BOLD%^%^RED%^m with %^RESET%^%^RED%^a deep red ribbon%^BOLD%^%^RED%^ which is tied in a bow at each cuff.  The bodice and skirt are tailored to be figure-hugging and cling to the wearer's body.

AVATAR
	);
	set_weight(8);
	set_value(2500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RED%^The dress clings to "+ETOQCN+"'s curves.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^The dress clings to your curves.%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+"'s dress slides to the floor.%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^The dress slides to the floor allowing you to step out of it.%^RESET%^");
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
