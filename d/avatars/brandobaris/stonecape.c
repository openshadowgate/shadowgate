#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("Living Stone Cape");
	set_id(({ "cape", "stone cape", "gray cape", "living stone cape", "mottled gray cape", "mottled cape" }));
	set_short("%^BOLD%^%^BLACK%^L%^RESET%^i%^BOLD%^%^BLACK%^v%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g S%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^%^BLACK%^e C%^RESET%^a%^BOLD%^p%^BLACK%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a m%^RESET%^o%^BOLD%^%^BLACK%^t%^RESET%^t%^BOLD%^l%^RESET%^e%^BOLD%^%^BLACK%^d g%^RESET%^r%^BOLD%^%^BLACK%^ay c%^WHITE%^a%^RESET%^p%^BOLD%^%^BLACK%^e%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This long hooded %^RESET%^cape %^BOLD%^%^BLACK%^is created from thick lengths of some strange, m%^RESET%^o%^BOLD%^t%^BLACK%^t%^WHITE%^l%^RESET%^e%^BOLD%^%^BLACK%^d g%^RESET%^r%^BOLD%^"
	"a%^BLACK%^y material, almost impossibly tough and consistently %^RESET%^%^CYAN%^cool %^BOLD%^%^BLACK%^to the touch. The garment is readily %^RESET%^%^CYAN%^waterproofed%^BOLD%^%^BLACK%^, seeming to re"
	"pel any moisture attempting to soak into it. Despite its unusually heavy weight, it seems an almost %^RESET%^effortless %^BOLD%^%^BLACK%^task to move around while wearing it, as the cape itself seems "
	"to anticipate one's movements, its center of gravity looking to %^RESET%^shift %^BOLD%^%^BLACK%^in whichever direction best suits the wearer...%^RESET%^
"	);
	set_value(10000);
	set_lore("A feat worthy of some respect within the arcane transmutation communities is the ability to shape objects from living stone, a strange material often found making up the bodies of certain earth elemen"
	"tals and other golem-like beings. With the proper skill, this component can be enchanted to hold a rudimentary spatial awareness, reflexively adapting to suit the user's needs, and even take on the ph"
	"ysical properties of entirely different material types, such as cloth.
"	);
	set_property("lore difficulty",10);
	set_item_bonus("damage resistance",2);
	set_item_bonus("stealth",-2);
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls on the heavy gray cape.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The weight of the heavy cape s%^RESET%^h%^BOLD%^i%^RESET%^f%^BOLD%^t%^BLACK%^s as you wear it, settling comfortably over your shoulders.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls off the heavy gray cape.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The cape s%^RESET%^h%^BOLD%^i%^RESET%^f%^BOLD%^t%^BLACK%^s, taking on a more uniform weight as you remove it.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETOQCN+" catches "+who->QCN+"'s blow with their heavy cape, absorbing much of its impact!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your cape s%^RESET%^h%^BOLD%^i%^RESET%^f%^BOLD%^t%^BLACK%^s suddenly, absorbing the impact of "+who->QCN+"'s blow!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+" catches your blow with their heavy cape, absorbing much of its impact!%^RESET%^");
return (damage*-100)/100;	}

}
