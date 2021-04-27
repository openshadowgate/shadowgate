#include <std.h>
inherit "/d/common/obj/armour/shield";

void create(){
	::create();
	set_name("xorbag");
	set_id(({ "handbag", " bag" }));
	set_short("%^BOLD%^%^RED%^Beshabas %^RESET%^%^ORANGE%^handbag of %^MAGENTA%^diseases%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^unfashionable, old leather handbag%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This is an old leather bag that smells rather musty. It was fashionable. Maybe 500 years ago.%^RESET%^
");
	set_value(0);
	set_size(2);
	set_property("enchantment",1);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),""+who->QCN+"%^RESET%^ is %^BOLD%^%^RED%^infested%^RESET%^ with %^BOLD%^%^GREEN%^odiferous %^WHITE%^crypt %^RESET%^%^MAGENTA%^maggots%^RESET%^ as the blow glances off the "+query_short()+"%^RESET%^ held by "+ETOQCN+"!",({ETO,who}));
	tell_object(ETO,""+who->QCN+"%^RESET%^ is %^BOLD%^%^RED%^infested%^RESET%^ with %^BOLD%^%^GREEN%^odiferous %^WHITE%^crypt %^RESET%^%^MAGENTA%^maggots%^RESET%^ as the blow glances off the handbag held by "+who->QCN+"!");
	tell_object(who,"You are %^BOLD%^%^RED%^infested%^RESET%^ with %^BOLD%^%^GREEN%^odiferous %^WHITE%^crypt %^RESET%^%^MAGENTA%^maggots%^RESET%^ as your blow glances off the "+query_short()+"%^RESET%^ held by "+ETOQCN+"!");
		who->do_damage("torso",roll_dice(1,250));
return damage;	}

}
