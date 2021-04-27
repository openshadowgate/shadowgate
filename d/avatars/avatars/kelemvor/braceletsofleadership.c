#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^B%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ac%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ts of L%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ad%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rs%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^ip%^RESET%^");
	set_id(({ "bracelet", "bracelets", "bracelets of leadership", "bracelet of leadership" }));
	set_short("%^BOLD%^%^BLACK%^B%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ac%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ts of L%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ad%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rs%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^ip%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A pair of m%^WHITE%^a%^BLACK%^r%^WHITE%^bl%^BLACK%^e b%^WHITE%^ra%^BLACK%^c%^WHITE%^el%^BLACK%^e%^WHITE%^t%^BLACK%^s%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a pair of marble bracelets worn on the wrists. The marble has been worn incredibly smooth over the years, but there is no sign of any cracking. The bracelets inspire you to achieve your goals merely by looking at them, and many strange %^RESET%^%^MAGENTA%^glowing runes%^BOLD%^%^BLACK%^ pulsate along the bands. A message is written on the inside of each bracelet.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
Remember who you are.

AVATAR
	);
     set("langage","drow");	set_weight(2);
	set_value(3000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^These bracelets belonged to many drow matron over the years. Through the various wars amongst the noble houses, the bracelets came to be stolen and eventually forgotten about. It is rumored that they enhance the wearers natural leadership qualities.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" struggles to wear the bracelets, but manages to do so.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You struggle to wear the bracelets, but manage to do so and are overcome by a wave of new knowledge.%^RESET%^");
	ETO->add_stat_bonus("wisdom",1);
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the bracelets with ease.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You easily slip the bracelets from your wrists and feel like less of a leader%^RESET%^");
	ETO->add_stat_bonus("wisdom",-1);
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
