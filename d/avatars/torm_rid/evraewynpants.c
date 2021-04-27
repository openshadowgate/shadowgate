#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Ornate Red Pants");
	set_id(({ "pants" }));
	set_short("%^RED%^Ornate Red Pants");
	set_obvious_short("%^RED%^Suede red pants");
	set_long(
@AVATAR
%^RED%^These pants are highly fashionable and look quite comfortable. They are made from %^ORANGE%^suede%^RED%^ that has been dyed a deep shade of %^BOLD%^%^RED%^red%^RESET%^%^RED%^ and fit easily over the wearer's body. Worn by men of %^WHITE%^wealth%^RED%^, these pants would look good on mostly anyone and appear to offer some %^BOLD%^%^RED%^protection%^RESET%^%^RED%^, aswell.

AVATAR
	);
	set_weight(1);
	set_value(4500);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^RED%^As "+ETO->query_cap_name()+" wears the "+query_short()+" he lets out a sigh of relaxation.",TP);
	tell_object(TP,"%^RED%^As you slip into the "+query_short()+", you feel relaxed in them.");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^RED%^As "+ETO->query_cap_name()+" slips out of the "+query_short()+" he takes a look at them and sighs.",TP);
	tell_object(TP,"%^RED%^As you slip out of the "+query_short()+" you miss the feel of the cloth.");
	return 1;
}
