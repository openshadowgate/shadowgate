#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^intricately %^RESET%^%^GREEN%^l%^RESET%^%^CYAN%^a%^GREEN%^c%^CYAN%^e%^GREEN%^d %^GREEN%^bracelets%^RESET%^");
	set_id(({ "bracelet", "bracelets" }));
	set_short("%^BOLD%^%^GREEN%^Br%^RESET%^%^GREEN%^a%^BOLD%^cel%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^ts of W%^RESET%^%^GREEN%^ove%^BOLD%^%^GREEN%^n %^GREEN%^V%^RESET%^%^ORANGE%^i%^BOLD%^%^RED%^n%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^intricately %^RESET%^%^GREEN%^l%^RESET%^%^CYAN%^a%^GREEN%^c%^CYAN%^e%^GREEN%^d %^GREEN%^bracelets%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^GREEN%^Colored vines have been meticulously brought together to form this set of %^BOLD%^%^BLACK%^eni%^RESET%^%^CYAN%^g%^GREEN%^m%^CYAN%^a%^BOLD%^%^BLACK%^tic %^RESET%^%^GREEN%^bracelets. Not only jewelry but also true works of art, the vines are shaped into a series of complex yet symmetrical loops that are a %^RESET%^%^CYAN%^p%^GREEN%^u%^BOLD%^%^BLACK%^zz%^RESET%^%^GREEN%^l%^CYAN%^e%^RESET%^%^GREEN%^ to the mind and eye. At first glance, the %^BOLD%^lus%^RESET%^%^GREEN%^h g%^BOLD%^%^GREEN%^reen%^RESET%^%^GREEN%^, %^ORANGE%^br%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^wn%^RESET%^%^GREEN%^ and %^BOLD%^v%^RESET%^%^GREEN%^ibran%^BOLD%^t %^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d%^RESET%^%^GREEN%^ vines seem chaotically linked together but a trained eye will reveal a precise pattern to the %^RESET%^w%^CYAN%^e%^RED%^a%^CYAN%^v%^RESET%^e%^RESET%^%^GREEN%^. Despite this underlying order, even the most patient of people would turn exhausted from too closely attempting to follow the intricacy of the loops, turns and links - in fact, there doesn't appear to be a beginning or an end, implying the bracelet is not comprised of many vines but just one. Most perplexing are the %^RED%^s%^ORANGE%^h%^GREEN%^ifti%^ORANGE%^n%^RED%^g%^GREEN%^ colors, which seem to course through the vine like blood through a body.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(4000);
	set_lore(
@AVATAR
%^BOLD%^%^BLUE%^Some say Mystra personally blessed these vines, and that she grants their use to protectors of the weave who have shown great strength and faith in magic. It is thought that the possessor of this stunning set of bracelets will be given strength of will and the power to think clearly in times of trouble. The vines are incapable of withering and for this reason many are inclined to believe that the rumors are true. Others laugh at the fools who believe such silly myths. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("clothing");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You are briefly enveloped by a warm feeling.%^RESET%^");
	ETO->add_stat_bonus("intelligence",1);
	ETO->add_stat_bonus("wisdom",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^Your mind feels slightly numb as you slip off the bracelets.%^RESET%^");
	ETO->add_stat_bonus("intelligence",-1);
	ETO->add_stat_bonus("wisdom",-1);
	return 1;
}
