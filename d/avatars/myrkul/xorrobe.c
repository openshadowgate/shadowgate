#include <std.h>
inherit "/d/common/obj/clothing/robe";

void create(){
	::create();
	set_name("xorrobe");
	set_id(({ "robe" }));
	set_short("%^BOLD%^%^RED%^Beshaba's %^RESET%^%^ORANGE%^robe of %^MAGENTA%^disease%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^unfashionable old lady robe%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This is a shabby old robe that smells rather musty. It was fashionable. Maybe 500 years ago.%^RESET%^
");
	set_value(0);
	set_size(2);
	set_property("enchantment",1);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),""+who->QCN+"%^RESET%^ is %^BOLD%^%^RED%^infested%^RESET%^ with %^BOLD%^%^GREEN%^deadly %^WHITE%^mummy %^RESET%^%^MAGENTA%^rot%^RESET%^ as the blow glances off the "+query_short()+"%^RESET%^ worn by "+ETOQCN+"!",({ETO,who}));
	tell_object(ETO,""+who->QCN+"%^RESET%^ is %^BOLD%^%^RED%^infested%^RESET%^ with %^BOLD%^%^GREEN%^deadly %^WHITE%^mummy %^RESET%^%^RED%^rot%^RESET%^ as the blow glances off the robe warn by "+who->QCN+"!");
	tell_object(who,"You are %^BOLD%^%^RED%^infested%^RESET%^ with %^BOLD%^%^GREEN%^deadly %^WHITE%^mummy %^RESET%^%^RED%rot %^RESET%^ as your blow glances off the "+query_short()+"%^RESET%^ worn by "+ETOQCN+"!");
		who->do_damage("torso",roll_dice(1,300));
return damage;	}

}
