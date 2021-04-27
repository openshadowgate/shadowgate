#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("mystic chainmail");
	set_id(({ "chain", "chainmail", "mystic chainmail", "mystic chain", "armor", "mystic armor" }));
	set_short("%^BOLD%^%^BLACK%^M%^CYAN%^y%^BOLD%^%^BLACK%^s%^CYAN%^t%^BOLD%^%^BLACK%^i%^CYAN%^c Chainmail%^RESET%^");
	set_obvious_short("chainmail");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This chainmail is made from interlocking bands of a %^YELLOW%^glowing%^BOLD%^%^BLACK%^, unknown %^BLUE%^metal%^BOLD%^%^BLACK%^.  It falls down to below the waist of the wearer and has been woven so that it covers all of the area it's worn on.  Engraved into the front of it, in a dull %^RED%^red%^BOLD%^%^BLACK%^, is the insignia of the %^CYAN%^Dagger Royal Guard%^BOLD%^%^BLACK%^, two %^BOLD%^%^WHITE%^d%^CYAN%^i%^BOLD%^%^WHITE%^a%^CYAN%^m%^BOLD%^%^WHITE%^o%^CYAN%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^ swords raised and crossed.%^RESET%^ 

AVATAR
	);
	set_weight(12);
	set_value(4000);
	set_type("chain");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^CYAN%^"+ETO->query_cap_name()+" slips on the "+query_short()+".%^RESET%^",TP);
	tell_object(TP,"%^CYAN%^You slip into the perfectly fitted "+query_short()+".%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^CYAN%^"+ETO->query_cap_name()+" slips out of the "+query_short()+"%^RESET%^",TP);
	tell_object(TP,"%^CYAN%^You remove the perfectly fitted "+query_short()+".%^RESET%^");
	return 1;
}
