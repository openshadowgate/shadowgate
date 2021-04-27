#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("moonfire bracers");
	set_id(({ "bracers", "moonfire bracers" }));
	set_short("%^BOLD%^%^WHITE%^M%^CYAN%^oo%^WHITE%^nfire Bracers%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^milky white bracers%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^This set of bracers has been formed of pure %^CYAN%^moonfire%^WHITE%^.  The etheral light bracers glow with a soft silvery light.  The moonfire substance is semi-transparent, allowing a hazy view of the skin underneath.  There are no laces on these bracers, instead they seem quite magical.  Deep within the bracers the twinkling of hundreds of stars can be seen.
%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_lore(
@AVATAR
The Moonfire Bracers are made through a secret ritual by the priestesses of Selune.  Offerings of milk and wine are poured over the altar as the priestesses dance about singing hymns of devotion.  When Selune is extremely pleased or in times of need moonfire is born from this ritual.  The priestesses gather up the moonfire substance and use it to enchant magical items.  The Moonfire Bracers are one of the rarest kind.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" is bathed in a soft silvery glow.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You are bathed in the soft glow from the bracers, feeling a deeper connection to %^CYAN%^Selune%^RESET%^.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The soft silvery glow that bathed "+ETOQCN+" fades.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The glow about you fades, though in your heart you still feel the deep connection to %^CYAN%^Selune%^RESET%^.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 175){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^"+ETOQCN+" vanishes in a flash of silvery light and avoids "+who->QCN+"'s attack.  She reappears in a different spot.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^In a flash of silvery light you feel yourself transported to a different spot, avoiding "+who->QCN+"'s attack!");
	tell_object(who,"%^BOLD%^%^WHITE%^"+ETOQCN+" vanishes in a flash of silvery light and avoids your attack.  She reappears in a different spot.");
return (damage*100)/100;	}
}