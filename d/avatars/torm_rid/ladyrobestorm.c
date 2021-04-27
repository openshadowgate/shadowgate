#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Robes of Torm");
	set_id(({ "robe", "robes" }));
	set_short("%^BOLD%^%^WHITE%^ Beautiful robes of %^YELLOW%^Torm%^RESET%^");
	set_obvious_short("%^WHITE%^White robes");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^These robes have been made with a young womans figure in mind. Hugging the body in the right places to show her feminism, but without overdoing it. The holy symbol of %^BOLD%^%^BLUE%^Torm %^BOLD%^%^WHITE%^are embroided on the back of the robes. They drape down the wearer allmost touching the floor. %^YELLOW%^Gold fiber has been sown into the sides of the robes, shimmering as the robes move.

AVATAR
	);
	set_weight(1);
	set_value(4500);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^After "+ETO->query_cap_name()+" clasps on the "+query_short()+" she looks absolutly stunning.",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^As you clasp the "+query_short()+" to your body you feel very comfortable.");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" sighs as she removes the robes.",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^You miss the feel of the soft robes as you remove them.");
	return 1;
}
