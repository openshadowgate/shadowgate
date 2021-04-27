#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("surcoat of the dawn");
	set_id(({ "surcoat" }));
	set_short("%^YELLOW%^Surcoat of the %^MAGENTA%^%^BOLD%^Dawn%^RESET%^");
	set_obvious_short("A golden silk surcoat");
	set_long(
@AVATAR
%^YELLOW%^This breathtaking surcoat is crafted out of the finest silk in the lands.  The silk it seems has been enchanted as to remain lightweight, but posses an unnatural strength that seems resistant to rips and tears.  The surcoat has a high collar and a close, snug, fitting body.  The sleeves on the surcoat stop just above the elbows.  The silk has been slashed open with bursts of %^BOLD%^%^MAGENTA%^rose%^RED%^red%^YELLOW%^ silk blazing through in spots.  Slashing of garments has caught on in the recent years with the clergy of Lathander and many nobles.  Etched with thread into the golden silk is the image of %^BOLD%^%^RED%^red aster flowers%^YELLOW%^.  The coat closes with golden silk ties.

AVATAR
	);
	set_weight(3);
	set_value(3000);
	set_lore(
@AVATAR
The Surcoat of the Dawn is a gift to Lathander to those of the Aster

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You feel as if the asters on the coat respond to you");
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
