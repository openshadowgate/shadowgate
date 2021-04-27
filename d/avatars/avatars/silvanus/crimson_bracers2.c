#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Crimson Bracers");
	set_id(({ "bracers", "bracer", "crimson bracers", "crimson bracer", "Bracers", "Bracer", "Crimson Bracers", "Crimson Bracer" }));
	set_short("%^RED%^C%^YELLOW%^r%^RED%^i%^YELLOW%^m%^RED%^s%^YELLOW%^o%^RED%^n%^YELLOW%^ Bracers%^RESET%^");
	set_obvious_short("red bracers");
	set_long(
@AVATAR
%^RED%^These bracers are formed from a %^CYAN%^shining%^RESET%^%^RED%^ flawless ruby.  They are less than one inch thick and are very light.  Impressed into their top are %^GREEN%^four emerald guardians%^RESET%^%^RED%^, each wielding a longsword.  Engraved below the impression is a small %^YELLOW%^inscription%^RESET%^%^RED%^, that could easily be read.%^RESET%^ 

AVATAR
	);
	set("read",
@AVATAR
%^YELLOW%^Protection is given if only you request...%^RESET%^
%^YELLOW%^Four guardians await day by day to do for their master the best.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^RED%^"+ETO->query_cap_name()+" wears the perfectly fitted "+query_short()+"%^RED%^!%^RESET%^",TP);
	tell_object(TP,"%^RED%^You wear the perfectly fitted "+query_short()+"%^RED%^!%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^RED%^"+ETO->query_cap_name()+" slowly removes the perfectly fitted "+query_short()+"%^RED%^!%^RESET%^",TP);
	tell_object(TP,"%^RED%^You slowly remove the perfectly fitted "+query_short()+"%^RED%^!%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
