#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("jeweled armband");
	set_id(({ "jeweled armband", "armband", "band", "bracelet" }));
	set_short("%^GREEN%^j%^WHITE%^e%^YELLOW%^w%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^l%^WHITE%^e%^YELLOW%^d %^GREEN%^a%^RESET%^r%^BOLD%^%^BLACK%^m%^WHITE%^b%^YELLOW%^a%^RESET%^%^GREEN%^n%^ORANGE%^d%^RESET%^");
	set_obvious_short("%^GREEN%^j%^WHITE%^e%^YELLOW%^w%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^l%^WHITE%^e%^YELLOW%^d %^GREEN%^a%^RESET%^r%^BOLD%^%^BLACK%^m%^WHITE%^b%^YELLOW%^a%^RESET%^%^GREEN%^n%^ORANGE%^d%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This armband is made of %^WHITE%^silvery adamantium %^YELLOW%^with a %^RESET%^%^ORANGE%^golden finish %^YELLOW%^to it, which causes it to change coloring depending on how the light strikes it.  Designed as a cuff that can fit around the wearer's biceps, the metal is free of etchings except for the lightning like design formed of three shards of %^GREEN%^green jade%^YELLOW%^.   An oval cut %^BOLD%^%^BLACK%^black opal %^YELLOW%^is set to either side of the lightning design, the dark fire adding a cold %^WHITE%^s%^BLACK%^p%^RESET%^%^ORANGE%^a%^WHITE%^r%^BOLD%^%^BLACK%^k%^YELLOW%^l%^WHITE%^e%^YELLOW%^ to the stunning armband.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(2500);
	set_lore(
@AVATAR


Designed for the %^BOLD%^%^CYAN%^second place winner %^RESET%^of the 1st annual %^BOLD%^%^BLACK%^Spooky Story Contest %^RESET%^this armlet was presented to %^YELLOW%^Ahmul %^RESET%^for his tantalizing tale of logic and deception when challenged to do the impossible. 



AVATAR
	);
	set_property("lore difficulty",15);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^WHITE%^ and %^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^metal %^WHITE%^s%^BLACK%^p%^RESET%^%^ORANGE%^a%^WHITE%^r%^BOLD%^%^BLACK%^k%^YELLOW%^l%^WHITE%^e%^YELLOW%^s%^WHITE%^ as "+ETOQCN+" wears the "+query_short()+"%^BOLD%^%^WHITE%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^WHITE%^ and %^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^metal %^WHITE%^s%^BLACK%^p%^RESET%^%^ORANGE%^a%^WHITE%^r%^BOLD%^%^BLACK%^k%^YELLOW%^l%^WHITE%^e%^YELLOW%^s%^WHITE%^ as you wear the "+query_short()+"%^BOLD%^%^WHITE%^.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^WHITE%^ and %^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^metal %^WHITE%^s%^BLACK%^p%^RESET%^%^ORANGE%^a%^WHITE%^r%^BOLD%^%^BLACK%^k%^YELLOW%^l%^WHITE%^e%^YELLOW%^s%^WHITE%^ as "+ETOQCN+" removes the "+query_short()+"%^BOLD%^%^WHITE%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^WHITE%^ and %^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^WHITE%^metal %^WHITE%^s%^BLACK%^p%^RESET%^%^ORANGE%^a%^WHITE%^r%^BOLD%^%^BLACK%^k%^YELLOW%^l%^WHITE%^e%^YELLOW%^s%^WHITE%^ as you remove the "+query_short()+"%^BOLD%^%^WHITE%^.%^RESET%^");
	return 1;
}
