#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^Two small %^YELLOW%^rings%^WHITE%^ connected by c%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^s%^RESET%^");
	set_id(({ "nipple", "rings", "nipple rings", "chained" }));
	set_short("%^BOLD%^%^WHITE%^C%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^e%^BLUE%^d %^RESET%^%^MAGENTA%^nipple %^YELLOW%^rings%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^C%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^e%^BLUE%^d %^YELLOW%^rings%^RESET%^");
	set_long(
@AVATAR
This is a pair of small %^YELLOW%^rings%^RESET%^ connected together by a slender %^BOLD%^c%^BLACK%^h%^BLUE%^a%^BLACK%^i%^WHITE%^n%^RESET%^. They are designed to be inserted into ones %^MAGENTA%^nipples%^RESET%^. Only the most %^GREEN%^wickedly %^BOLD%^%^MAGENTA%^p%^YELLOW%^e%^MAGENTA%^r%^MAGENTA%^v%^YELLOW%^e%^MAGENTA%^r%^YELLOW%^s%^MAGENTA%^e%^RESET%^ would even begin to wear such a thing.

AVATAR
	);
	set_weight(1);
	set_value(100000000);
	set_lore(
@AVATAR
%^RED%^These rings are believe to have been worn under the garments (or sometimes none at all) of Sune herself! Though, only those who Sune herself deems beautiful enough have ever been able to glance at them.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("ring");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
   set_property("enchantment",1);
	set_ac(10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+"'s eyes slowly glaze over as she slides the rings into her %^RESET%^%^MAGENTA%^nipples%^YELLOW%^ and she lets out a %^RESET%^%^ORANGE%^hu%^BOLD%^s%^RESET%^%^ORANGE%^ky %^RED%^moan%^YELLOW%^.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel a sharp %^RESET%^%^RED%^pain%^YELLOW%^ as you slide the "+query_short()+" into your %^RESET%^%^MAGENTA%^nipples%^YELLOW%^ that quickly turns into an %^WHITE%^orgasmic%^YELLOW%^ feeling.%^RESET%^");
	ETO->add_stat_bonus("charisma",10);
	ETO->do_damage("torso",random(1));
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" pouts as she slides the "+query_short()+" %^YELLOW%^out of her %^RESET%^%^MAGENTA%^nipples%^YELLOW%^.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^That was almost better than sex!%^RESET%^");
	ETO->add_stat_bonus("charisma",-10);
	return 1;
}
