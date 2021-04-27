#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Spider silk stockings");
	set_id(({ "tights", " stockings", " web tights", " web stockings", " silk tights", " silk stockings" }));
	set_short("%^BOLD%^%^BLACK%^Sp%^RESET%^i%^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^r %^RESET%^s%^BOLD%^i%^RESET%^lk %^BOLD%^%^BLACK%^st%^WHITE%^o%^BOLD%^%^BLACK%^ck%^WHITE%^i%^BLACK%^ngs%^RESET%^ ");
	set_obvious_short("%^BOLD%^%^BLACK%^Sp%^RESET%^i%^BOLD%^%^BLACK%^d%^RED%^e%^BLACK%^r %^RESET%^s%^BOLD%^i%^RESET%^lk %^BOLD%^%^BLACK%^st%^WHITE%^o%^BOLD%^%^BLACK%^ck%^WHITE%^i%^BLACK%^ngs%^RESET%^ ");
	set_long(
@AVATAR
 %^BOLD%^%^BLACK%^These %^RESET%^wispy %^BOLD%^%^BLACK%^stockings are spun of a %^WHITE%^silky soft gossamer webbing%^BLACK%^. The web pattern of the stockings themselves are as intricate and myriad in design as one woven by an actual sp%^RED%^i%^BLACK%^der. A %^RESET%^soft %^BOLD%^glow %^BLACK%^surrounds the stockings themselves as %^BOLD%^%^WHITE%^light trails%^BLACK%^ course through the %^WHITE%^silvery %^BLACK%^material, providing a stunning %^WHITE%^highlighting %^BLACK%^effect. The stockings are extremely form fitting and obviously not intended to conceal much of anything. %^RESET%^

AVATAR
	);
	set("read",
@AVATAR
 %^RED%^As you gaze into the myriad designs of this fabric you realize that words seem to be forming within them before your eyes....




               %^BOLD%^%^BLACK%^The Queen of Spiders sees all within the darkness

AVATAR
	);
     set("langage","drow");	set_weight(1);
	set_value(40000);
	set_lore(
@AVATAR

       %^BOLD%^%^BLACK%^These tights were said to have been spun by one of Lolths hunting spiders as a reward for the High priestess Solizantia. Her beauty was unsurpassed in the city of Aurachnolus, and it was said that where she went, the will of Lolth followed. In the end though, the luminesce nature of her gift managed to make her the obvious target in a raid on one of her trade expeditions through the underdark. It is whispered that such was the intent behind Lolths gift..the lady of chaos is a fickle mistress.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" shivers as gossamer webbing slides smoothly up her legs%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The gossamer webbing slides smoothly up your legs%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	ETO->set_property("magic resistance",10);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes darken as she slips the clinging fabric from her legs%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You are filled with a strange foreboding as you remove the clinging fabric%^RESET%^");
	ETO->add_stat_bonus("charisma",-1);
	ETO->set_property("magic resistance",-10);
	return 1;
}
