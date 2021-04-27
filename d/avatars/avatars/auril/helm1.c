#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("e");
	set_id(({ "helm", "helmet" }));
	set_short("%^RESET%^%^GREEN%^Em%^BOLD%^%^GREEN%^er%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^ld Helm%^RESET%^");
	set_obvious_short("A thickly skinned helm");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This helm is made of thick %^BOLD%^%^BLACK%^dr%^BOLD%^%^GREEN%^ag%^BOLD%^%^BLACK%^on %^BOLD%^%^GREEN%^scales. On the base of the helmet two dragon %^BOLD%^%^WHITE%^teeth %^BOLD%^%^GREEN%^protrude menacingly about three inches past the wearers face on either side. The helmet itself forms a %^BOLD%^%^CYAN%^qu%^BOLD%^%^WHITE%^asi%^BOLD%^%^GREEN%^ dragon head form with its open face where the mouth would go and small dragon %^BOLD%^%^WHITE%^teeth %^BOLD%^%^GREEN%^above the wearers eyes down the sides of their  face and outward near the mouth for comfort. Two massive %^BOLD%^%^RED%^ru%^RESET%^%^RED%^bi%^BOLD%^%^RED%^es %^BOLD%^%^GREEN%^sit on either side like eyes. They glimmer as are obviously quite valuable themselves. 

AVATAR
	);
	set_weight(5);
	set_value(10000);
	set_lore(
@AVATAR
This item was made from the skin of the famed Geonslu, Emerald Dragon. Enchaned by Ramius, priest of Lathander and wizard famed - it was given to the ranger Aramel, the famous rebel of the western continent. 

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" wears "+query_short()+" and the teeth at the base of it extend to fit perfectly to them.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You place the helm upon your head and the %^BOLD%^%^WHITE%^teeth %^BOLD%^%^GREEN%^at the base protrude out perfectly to defend your neck. ");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 25){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"");
	tell_object(who,"");
		who->set_paralyzed(random(10));
return damage;	}
}