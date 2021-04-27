#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Mask of Death");
	set_id(({ "mask", "death mask", "mask of death" }));
	set_short("%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^sk of De%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^th%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a thin metal mask%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This mask is made of stainless %^BOLD%^%^CYAN%^titanium%^RESET%^%^RED%^. The mask is in the shape of an expressionless face. Their are no openings in the mask. Where the eyes on the mask are, two obsidian %^BOLD%^%^BLACK%^gems %^RESET%^%^RED%^sit. On the inside of the mask there is some small writing. You do not understand how the wearer of the mask is supposed to see through the it, much less put it on.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(2000);
	set_lore(
@AVATAR
%^RESET%^%^MAGENTA%^This mask is ancient, made many, many years ago.  That is surprising seeings how there are no marks on it.  It was created by some dark magic by an old wizard.  He was not as wise as he needed to be to overcome the throws of death so he built this mask thinking it would help him.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",40);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^CYAN%^"+ETOQCN+" %^RESET%^%^MAGENTA%^starts to choke and gag as they put on the %^BOLD%^%^CYAN%^"+query_short()+" %^RESET%^%^MAGENTA%^but then settles after it is completely on.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^Your eyes bug out slightly and you get a deep pain in your head as you struggle to put on the %^BOLD%^%^CYAN%^"+query_short()+"%^RESET%^%^MAGENTA%^.%^RESET%^");
	ETO->add_stat_bonus("wisdom",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^CYAN%^"+ETOQCN+" %^RESET%^%^MAGENTA%^sighs deeply and stumbles slightly as they remove %^BOLD%^%^CYAN%^"+query_short()+"%^RESET%^%^MAGENTA%^, then quickly recovers.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You grimmace in pain momentarily as you remove the %^BOLD%^%^CYAN%^"+query_short()+"%^RESET%^%^MAGENTA%^.%^RESET%^");
	ETO->add_stat_bonus("wisdom",-2);
	return 1;
}
