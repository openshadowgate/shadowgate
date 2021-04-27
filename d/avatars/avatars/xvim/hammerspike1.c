#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("hammerspike");
	set_id(({ "hammerspike", "hammer", "spike" }));
	set_short("%^RESET%^BOLD%^%^RED%^E%^BOLD%^%^BLACK%^n%^RED%^g%^BOLD%^%^BLACK%^r%^RED%^a%^BOLD%^%^BLACK%^v%^RED%^e%^BOLD%^%^BLACK%^d%^RESET%^ %^RED%^spiked hammer made of Adamantium%^RESET%^");
	set_obvious_short("%^RESET%^BOLD%^%^RED%^E%^BOLD%^%^BLACK%^n%^RED%^g%^BOLD%^%^BLACK%^r%^RED%^a%^BOLD%^%^BLACK%^v%^RED%^e%^BOLD%^%^BLACK%^d%^RESET%^ %^RED%^spiked hammer made of Adamantium%^RESET%^");
	set_long(
@AVATAR
%^RED%^The hammer head is %^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^n%^RED%^g%^BOLD%^%^BLACK%^r%^RED%^a%^BOLD%^%^BLACK%^v%^RED%^e%^BOLD%^%^BLACK%^d%^RESET%^ %^RED%^with the symbol of %^RED%^T%^BOLD%^%^BLACK%^E%^RESET%^%^RED%^M%^BOLD%^%^BLACK%^P%^RESET%^%^RED%^U%^BOLD%^%^BLACK%^S,%^RESET%^%^RED%^ surrounded by a pattern of small %^BOLD%^%^RED%^rubies%^RESET%^%^RED%^ forming a %^BOLD%^%^WHITE%^"%^BOLD%^%^RED%^D%^BOLD%^%^WHITE%^".
%^RESET%^%^ORANGE%^The handle of the hammer is surrounded by a mesh made of adamantium connecting it solidly to the hammer head and to a a counterweight on the other end.
%^RESET%^%^RED%^The handle ends in a counterweight made of adamantium, forming an unicorn head with %^BOLD%^%^BLUE%^sapphire eyes%^RESET%^%^RED%^, from which a %^BOLD%^%^WHITE%^spiral%^RESET%^%^RED%^ formed spike emerges. %^RESET%^%^RED%^The weight of the head and that of the counterweight at the spike end, provides a perfect ballance to the hammer so it can be easily twisted around in battle.

AVATAR
	);
	set_weight(10);
	set_value(0);
	set_type("piercing");
	set_prof_type("hammerspike");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),""+ETOQCN+" %^GREEN%^spins the "+query_short()+"%^GREEN%^ around and slams the handle through "+targ->QCN+"'s %^RED%^%^BOLD%^guts.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^GREEN%^You spin the "+query_short()+"%^GREEN%^ around and slam the handle through "+targ->QCN+"'s %^RED%^%^BOLD%^guts.%^RESET%^");
	tell_object(targ,""+ETOQCN+"%^GREEN%^ spins the "+query_short()+"%^GREEN%^ around and slams the handle through %^BOLD%^%^BLACK%^YOUR %^RED%^%^BOLD%^guts.%^RESET%^");
		return roll_dice(2,3)+0;	}
}