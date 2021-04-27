#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("deathwear");
	set_id(({ "shroud", "death shroud", "armor" }));
	set_short("%^BOLD%^%^WHITE%^Death Shroud%^RESET%^");
	set_obvious_short("a burial shroud");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a burial shroud.  It was crafted from fine linen but deteriorated many eons ago.  It was once pure white, but has long since become discolored by age and mould.  It looks as though it would fit a medium sized creature, but you sense it would invite death.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1);
	set("chabonus",2);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(-5);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 400){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The attack passes through "+ETOQCN+"%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The attack from "+who->QCN+" passes through "+query_short()+"%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^Your attack passes through "+ETOQCN+"%^RESET%^");
return (damage*100)/100;	}
}