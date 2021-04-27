#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^A white coat%^RESET%^");
	set_id(({ "coat", "Coat", "robe", "Robe" }));
	set_short("%^BOLD%^%^WHITE%^Coat of the W%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e Dragon%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A white coat%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a pristine white coat, no sign of %^RESET%^%^ORANGE%^dirt %^BOLD%^%^WHITE%^or wear on it. The sleeves are cut short, stopping at the elbow. A row of six small white buttons runs up the front of the coat. On the back of the coat is a intricate design of a w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e dragon. The design is sewn in with a %^RESET%^%^BLUE%^dark blue %^BOLD%^%^WHITE%^thread. Along the cuff of the sleeves and bottom of the coat is a %^RESET%^%^BLUE%^dark blue %^BOLD%^%^WHITE%^thread, lacing in a slight spiral pattern. %^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 334){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^A %^RED%^snarl %^WHITE%^is heard as "+who->QCN+" hits "+ETOQCN+".%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^A %^RED%^snarl %^WHITE%^emits from the coat as "+who->QCN+" hits you.%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^A w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e dragon flies out and pelts you with %^RESET%^%^CYAN%^ice %^BOLD%^%^WHITE%^as you hit "+ETOQCN+".%^RESET%^");
		who->do_damage("torso",random(15));
return damage;	}
}