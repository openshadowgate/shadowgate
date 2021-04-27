#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create(){
	::create();
	set_name("tower shield");
	set_id(({ "shield", "tower shield", "towershield", "watchful eye shield" }));
	set_short("%^BOLD%^%^WHITE%^Wa%^CYAN%^t%^WHITE%^ch%^CYAN%^f%^WHITE%^ul E%^CYAN%^y%^WHITE%^e Sh%^CYAN%^i%^WHITE%^eld%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a stunning %^BLACK%^m%^WHITE%^i%^RESET%^t%^BOLD%^%^WHITE%^h%^BLACK%^ril%^WHITE%^ tower shield%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^Formed from two crescents of %^CYAN%^burnished steel %^BOLD%^%^WHITE%^set around a large oval of %^BLACK%^s%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^BLACK%^ery m%^WHITE%^i%^RESET%^t%^BOLD%^%^WHITE%^h%^BLACK%^ril%^WHITE%^, this tower shield is nearly the height of a human standing and would completely dwarf a smaller being.  Polished to a mirror sheen, the mithril is etched with runic glyphs that glow with a pale %^CYAN%^mystical energy%^WHITE%^.  In the center of these runes a %^BLACK%^gaunt

AVATAR
	);
	set_weight(10);
	set_value(5000);
	set_lore(
@AVATAR

The watchful eye shield was designed for a sect of Helmite watchmen assigned to aid the city of Seneca during the great battle between the last bastion of light and Intruder's armies.  Aided by several other sects, groups and adventurers, the city was able to repel the undead and free itself from Intruder's attempts to conquer.  The shields were forged in mass then prayed over by the high priests of several temples before being given to the Helmite Watchmen to help them identify each other as the unit was 

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("shield");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^Taking a firm grip on the handle of the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^, you stand ready and watchful for the call to battle.%^RESET%^");
	ETO->set_property("magic resistance",3);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You release your grip on the handle of the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^, but never relax your watchful guard.%^RESET%^");
	ETO->set_property("magic resistance",-3);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+ETOQCN+" moves their %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ into the perfect position to block "+who->QCN+"'s attack!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^Always watchful and alert, the %^RESET%^"+query_short()+" %^BOLD%^%^CYAN%^on your arm comes to life and brings itself to the perfect spot to protect you from "+who->QCN+"'s attack!%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^"+ETOQCN+" moves their %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ into the perfect position to block your attack!%^RESET%^");
return (damage*-75)/100;	}

}
