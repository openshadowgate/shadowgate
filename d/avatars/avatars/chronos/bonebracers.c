#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bone bracers");
	set_id(({ "bracers" }));
	set_short("%^RESET%^%^ORANGE%^An%^WHITE%^c%^ORANGE%^ie%^WHITE%^n%^ORANGE%^t %^BOLD%^%^WHITE%^b%^BLACK%^on%^WHITE%^e%^RESET%^%^BLUE%^ gu%^CYAN%^ar%^BLUE%^ds%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^B%^BLACK%^on%^WHITE%^e%^RESET%^%^ORANGE%^ br%^WHITE%^a%^ORANGE%^c%^WHITE%^e%^ORANGE%^rs%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Stunningly crafted from the %^WHITE%^bones%^ORANGE%^ of some ancient %^RED%^beast%^ORANGE%^. Taut %^BOLD%^%^BLACK%^adamantium%^RESET%^%^ORANGE%^ bands keep the bracers wrapped tightly around the wearer's forearms. Etched onto the bracers depictions of %^YELLOW%^heroes%^RESET%^%^ORANGE%^ overcoming great beasts are seen. When closed they seal shut without a trace of where they open. %^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(10000);
	set_lore(
@AVATAR
Supposedly the bones of ancient dragons are used to make bracers such as these. It is said that the very essece of the great beasts are kept bound within these to use thier conciderable strength to protect the wearer.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
      set_ac(1);
     //set_ac(5); -> Was 5 but that is too high - Cythera
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set("dexbonus",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" seals the "+
		"bracers on, and "+ETO->QS+" glance over "+ETO->QP+" shoulder.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You close the bracers around your "+
		"arms and feel %^BLACK%^something%^WHITE%^ watching over you.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" breathes a little "+
		"sigh of relief as "+ETO->QS+" removes "+ETO->QP+" bracers%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you remove the bracers you feel"+
		" %^YELLOW%^vulnerable%^RESET%^");
	return 1;
}
