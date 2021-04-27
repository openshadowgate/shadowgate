#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("crysknife");
	set_id(({ "knife", "crysknife" }));
	set_short("%^RESET%^%^ORANGE%^Cry%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^kn%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^fe%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A knife carved from a sharpened %^BOLD%^tooth%^RESET%^");
	set_long(
@AVATAR
This is an extremely %^BOLD%^%^WHITE%^sharp %^RESET%^knife that appears to be carved from a giant %^BOLD%^%^WHITE%^tooth%^RESET%^.  The blade portion has been sharpened to an unnaturally keen edge that looks as if it would slice through %^BOLD%^%^BLACK%^armor %^RESET%^and %^ORANGE%^flesh %^RESET%^with equal ease.  A rough, desert tanned %^RESET%^%^ORANGE%^leather %^RESET%^has been secured around the hilt to make it fit to the wearer's hand easily.

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_lore(
@AVATAR
This is a legendary crysknife.  It is carved from a great sandworm's tooth.  They are extremely rare these days and to find one is a treasure indeed.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(3,3);
	set_large_wc(2,3);
	set_property("enchantment",5);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),""+ETOQCN+" %^BOLD%^%^RED%^cuts %^RESET%^"+targ->QCN+" easily with a side swipe then spin the dagger deftly before plunging it deeply into them!",({ETO,targ}));
	tell_object(ETO,"You %^BOLD%^%^RED%^cut %^RESET%^"+targ->QCN+" easily with a side swipe then spin the dagger deftly before plunging it deeply into them!");
	tell_object(targ,""+ETOQCN+" %^BOLD%^%^RED%^cuts %^RESET%^you easily with a side swipe then spin the dagger deftly before plunging it deeply into you!");
		return roll_dice(2,4)+0;	}
}