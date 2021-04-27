#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shadowgauntlets");
	set_id(({ "gauntlets", "shadow gauntlets" }));
	set_short("%^BLACK%^%^BOLD%^sh%^RESET%^a%^BLACK%^%^BOLD%^do%^RESET%^w g%^BLACK%^%^BOLD%^r%^RESET%^i%^BLACK%^%^BOLD%^p%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^black shiftless gauntlets%^RESET%^");
	set_long(
@AVATAR
%^BLACK%^%^BOLD%^Seemingly crafted from shadows themselves, these gauntlets shift and move on thier own accord. The cuffs of the gauntlets are %^RESET%^cold iron%^BLACK%^%^BOLD%^, small studs lining it at regular intervals. As the fingers of the gauntlets move, you can almost hear a soft %^RESET%^%^CYAN%^whisper%^BLACK%^%^BOLD%^ in many voices at once.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(5000);
	set_type("chain");
	set_limbs(({ "right hand", "left hand" }));
	set_size(3);
	set_property("enchantment",1);
	set_ac(0);
	set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        set("dexbonus",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^As "+ETOQCN+" slips on the "+query_short()+", a slight whisper can be heard%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^As you slip on the "+query_short()+", you can feel the shadows form around your fingers%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^An angry hiss can be heard as "+ETOQCN+" pulls off the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You pull off the "+query_short()+", causing a sharp hiss of anger from them as the shadows pull away%^RESET%^");
	return 1;
}
