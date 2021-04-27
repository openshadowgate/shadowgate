#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("pendant");
	set_id(({ "amulet", "pendant", "silver pendant", "amethyst pendant", "amethyst", "shadow ember", "ember pendant" }));
	set_short("%^RESET%^%^MAGENTA%^Sh%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^d%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^w E%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^ber A%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^ul%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a stunning %^RESET%^%^MAGENTA%^a%^BOLD%^m%^RESET%^%^MAGENTA%^eth%^BOLD%^y%^RESET%^%^MAGENTA%^st %^BOLD%^%^BLACK%^pendant%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^This amethyst pendant %^BOLD%^glows %^RESET%^%^MAGENTA%^with a deep purple aura that seems to radiate a dark light from its core.  Strung upon a chain of pure %^BOLD%^%^WHITE%^silver%^RESET%^%^MAGENTA%^, the gemstone is teardrop shaped and quite large, almost three inches long, making it rather heavy.  A cage of %^BOLD%^%^WHITE%^silver wire %^RESET%^%^MAGENTA%^provides an intricate woven design around the gem that displays the setting rather then hiding it in a maze of silver.  Looking deep into the stone, you can almost see a %^BOLD%^%^BLACK%^shape %^RESET%^%^MAGENTA%^moving within its center, but your mind simply refuses to give it shape or form.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(3500);
	set_lore(
@AVATAR

There is very little known about these gems except that they are of drow make.  The shadows within are rumored to be the remains of the spirits of those enemies the drow actually respected.  After they were tortured, maimed and finally slain.  Those who have studied these gems and lived long enough to tell anything about them, claim that the spirits seem to believe they are part of the body of the wearer and when they come under attack will sometimes become violent and attack their enemies.


AVATAR
	);
	set_property("lore difficulty",30);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel an unsettling weight as you place the %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^around your neck.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You breathe easier as you take the %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^from around your neck.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 250){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+who->QCN+" screams in pain as a dark energy flies from "+ETOQCN+"'s %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^into them and back out!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Something seems to pull from within as a dark shape bursts from the %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^and drives into "+who->QCN+".  "+who->QCN+" screams out in pain as the same energy shoots out and back into the gemstone.%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^You scream in pain as you feel something tear through you and then fly back into "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^!%^RESET%^");
		ETO->set_paralyzed(random(6));
return damage;	}
}