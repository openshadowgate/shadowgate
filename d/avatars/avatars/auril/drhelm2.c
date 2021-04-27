#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dragon helm");
	set_id(({ "helm", "helmet" }));
set_short("%^BOLD%^%^GREEN%^Hel%^BOLD%^%^RED%^m o%^BOLD%^%^GREEN%^f the %^BOLD%^%^GREEN%^Dr%^BOLD%^%^RED%^ago%^BOLD%^%^GREEN%^n Sl%^BOLD%^%^RED%^ay%^BOLD%^%^GREEN%^er");
	set_obvious_short("%^BOLD%^%^GREEN%^A thickly skinned helm%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This helm is made of thick %^BOLD%^%^BLACK%^dr%^BOLD%^%^GREEN%^ag%^BOLD%^%^BLACK%^on %^BOLD%^%^GREEN%^scales. On the base of the helmet two dragon %^BOLD%^%^WHITE%^teeth %^BOLD%^%^GREEN%^protrude menacingly three inches past the wearers face on either side. The helm itself forms a %^BOLD%^%^CYAN%^qu%^BOLD%^%^WHITE%^asi %^BOLD%^%^GREEN%^dragon head form with its open face where the mouth would go and small dragon %^BOLD%^%^WHITE%^teeth %^BOLD%^%^GREEN%^above the wearers eyes down the sides 

AVATAR
	);
set_weight(2);
	set_value(10000);
	set_lore(
@AVATAR
This helm was crafted for the ranger Aramel Silverpond by the druid and craftsman Oran Eldralrich. The skin used to craft this magnificent helm came from the great Geonslu, Emerald Dragon. The helm was crafted in commemoration of the great event of its slaying by the famous ranger.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" places the helm upon his head and the teeth of the helmet extend outward menacingly.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You place the helm upon your head and you feel it fit perfectly to you.");
	ETO->set_property("magic resistance",15);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" removes the helmet and the teeth retract normally.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^With a lot of effort you remove the helmet.");
	ETO->set_property("magic resistance",-15);
	return 1;
}
int strike_func(int damage, object what, object who){
   if(random(50) < 2){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The helmet shrieks loudly at "+who->QCN+"!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^The helmet shrieks loudly at "+who->QCN+"!");
	tell_object(who,"%^BOLD%^%^RED%^The helmet shrieks loudly and you feel its effects immediately!");
   who->set_paralyzed(random(4));
return damage;	}
}
