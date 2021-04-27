#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("water robes");
	set_id(({ "robes" }));
	set_short("%^BOLD%^%^CYAN%^Flowing Ma%^BOLD%^%^YELLOW%^j%^BOLD%^%^CYAN%^estic%^RESET%^");
	set_obvious_short("A long blue robe");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This long robe looks fairly normal. It glistens slightly as if some sort of magic is covering it. It is beautifully crafted and has a %^BOLD%^%^YELLOW%^gold %^BOLD%^%^CYAN%^trim around the bottom of it. The robe is light, flowing easily over armor and it trails around the wearer but never seems to hamper movement.

AVATAR
	);
	set_weight(9);
	set_value(10000);
	set_lore(
@AVATAR
These robes are usually given to major clergy in the Istishian faith.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The water in the pool before you begins to spin violently. Slowly the pool moves towards "+ETOQCN+" and crawls on too your robe and her robe begins to magically flow like water.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The water in the pool before you begins to spin violently. Slowly the pool moves towards you and crawls on too your robe and your robe begins to magically flow like water.");
	ETO->add_stat_bonus("wisdom",1);
	ETO->set_property("magic resistance",20);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The water leaps off of "+ETOQCN+"'s robe and evaporates into the ground.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The water leaps off of your robe and evaporates into the ground.");
	ETO->add_stat_bonus("wisdom",-1);
	ETO->set_property("magic resistance",-20);
	return 1;
}
