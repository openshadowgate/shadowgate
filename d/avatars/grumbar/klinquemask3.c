#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("mask of death");
	set_id(({ "mask" }));
	set_short("%^RESET%^%^MAGENTA%^Ma%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^k of De%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^th%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a thin metal mask%^RESET%^");
	set_long(
@AVATAR
add later

AVATAR
	);
	set_weight(5);
	set_value(2000);
	set_lore(
@AVATAR
%^RESET%^%^BOLD%^%^MAGENTA%^This mask was created by a wizard who died many, many years ago.  Myth has it that he was trying to cheat death but %^RESET%^%^MAGENTA%^realized he was no wise enough to figure out how.  So he created this mask which he thought would assist him in this area.  No one knows if it worked or not, but he is dead so that should say something, eh?%^RESET%^

AVATAR
	);
	set_property("lore difficulty",35);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^As %^BOLD%^%^CYAN%^"+ETOQCN+" %^RESET%^%^MAGENTA%^wears %^BOLD%^%^CYAN%^"+query_short()+"%^RESET%^%^MAGENTA%^, the %^BOLD%^%^BLACK%^gems %^RESET%^%^MAGENTA%^in it seem to stare at you and you freeze momentarily.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^Death seems to fill you as you slide this mask on.%^RESET%^");
	ETO->add_stat_bonus("wisdom",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^At the sight of %^BOLD%^%^CYAN%^"+query_short()+" %^RESET%^%^MAGENTA%^being removed by %^BOLD%^%^CYAN%^"+ETOQCN+"%^RESET%^%^MAGENTA%^, you relax visibly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^The feeling of emptiness and death leave you as you remove %^BOLD%^%^CYAN%^"+query_short()+"%^RESET%^%^MAGENTA%^.%^RESET%^");
	ETO->add_stat_bonus("wisdom",-2);
	return 1;
}
