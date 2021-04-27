#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("Greydon's archmagi robe");
	set_id(({ "robe" }));
	set_short("%^BOLD%^%^BLACK%^Robe of the Archmagi%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black hooded robe%^RESET%^");
	set_long(
@AVATAR
%^GREEN%^This robe was made in ancient times, from one of the strongest magi ever to walk the world, it offers great protection to its wearer, and also draws magical powers from the weave giving the wearer powers beyond any normal mortal.

AVATAR
	);
	set_weight(20);
	set_value(2000);
	set_lore(
@AVATAR
The robe was made by a powerfull magi and has been handed down for generations in the Greydon family.

AVATAR
	);
	set_max_internal_encumbrance(50);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(ETP,"%^BLUE%^"+TP->query_cap_name()+" wears the thick black robe and his face disappears inside the dark hood",TP);
	tell_object(TP,"%^YELLOW%^You wear the thick robe, but it feels as it weighs nothing");
	TP->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(ETP,"%^BLUE%^"+TP->query_cap_name()+" looks very concerned at the robe as he removes it.",TP);
	tell_object(TP,"%^RED%^You remove the thick robe and instantly feel the need to wear it again.");
	TP->set_property("magic resistance",-5);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 475){
	tell_room(environment(query_worn()),"%^YELLOW%^"+ETO->query_cap_name()+" laughs as "+who->query_cap_name()+" tries to hit him",({ETO,who}));
	tell_object(ETO,"%^GREEN%^The robe absorbs the hit and you feel little pain");
	tell_object(who,"%^B_BLACK%^You hit "+ETO->query_cap_name()+" but he doesn't seem to take damage from your attempt.");
		return (damage*10)/100;
	}
}