#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Devine Plate");
	set_id(({ "plate", "armor" }));
	set_short("%^BOLD%^%^BLUE%^Devine fullplate");
	set_obvious_short("%^BOLD%^%^BLUE%^Blue fullplate");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Forged from unknown metal, this plate has a clear blue color. Massive and incredebly heavy, this fullplate seems to be impossible to penetrate. A curved virtual wall protects the wearers neck and head from blows. Two huge should plates hold the arms of the plate, smaller plates laid in fold to ease bending of the arms. The breast plate is equally impressive, with large %^RESET%^%^WHITE%^silver shield%^BOLD%^%^WHITE%^. The groin is equally protected. The legs of the plate end a few inches inside the boots of the wearer, Two knee plates protect and small strips of plate on the inside of the knee aid bending of the joints.

AVATAR
	);
	set_weight(150);
	set_value(0);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(500);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^BLUE%^Looking extremly difficult "+ETO->query_cap_name()+" manages to fit the "+query_short()+" to his body.",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^Taking much of your strength, you are able to fit the "+query_short()+" to your body.");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^%^BLUE%^With a sigh of relief, "+ETO->query_cap_name()+" removes the heavy "+query_short()+".",TP);
	tell_object(TP,"%^BOLD%^%^BLUE%^With a sigh of relief you remove the heavy armor from yourself, but you miss is impressive protection.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^As "+who->query_cap_name()+" strikes "+ETO->query_cap_name()+" the "+query_short()+" gives off a loud bang.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^With a loud bang, the blow does little damage.");
	tell_object(who,"%^BOLD%^%^BLUE%^With a loud bang you strike "+ETO->query_cap_name()+", wondering if you did the man any damage.");
		return (damage*90)/100;
	}
}