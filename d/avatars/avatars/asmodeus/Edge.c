#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("edge of discord");
	set_id(({ "sword", "blade", "edge" }));
	set_short("%^BOLD%^%^BLACK%^E%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ge of %^RESET%^%^RED%^D%^BOLD%^%^RED%^i%^RESET%^%^RED%^s%^BOLD%^%^RED%^c%^RESET%^%^RED%^o%^BOLD%^%^RED%^r%^RESET%^%^RED%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A twisted blacksteel blade%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This long twisted blade is made from a black, unknown metal, both
light-weight and durable. The double-edged blade is %^BOLD%^RED%^razor-sharp, %^BOLD%^%^BLACK%^barbed and
serrated in some parts, smooth and fine edged in others - a blade of
%^GREEN%^chaos. %^BOLD%^%^BLACK%^A deep %^BOLD%^RED%^blood%^ %^BOLD%^%^BLACK%^groove travels along the length of the blade, flanked
on either side by jagged %^BOLD%^CYAN%^runes. %^BOLD%^%^BLACK%^There is a sense of wrongness about the
%^BOLD%^CYAN%^runes, %^BOLD%^%^BLACK%^to look on them is to feel uneasy. The hilt is carved from soft
black stone, wrapped in supple leather of some unknown beast. A thick
%^BOLD%^RED%^blood-ruby %^BOLD%^%^BLACK%^has been set into the end of the hilt, seccured firmly by a set
of black claws.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^GREEN%^CHAOS%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(1000);
	set("strbonus",2);
	set_type("slashing");
	set_prof_type("blades");
	set_size(2);
	set_wc(3,6);
	set_large_wc(6,6);
	set_property("enchantment",5);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^BLACK%^The %^BOLD%^CYAN%^runes %^BOLD%^BLACK%^on "+query_short()+" %^BOLD%^%^BLACK%^come to life, as the sword impales "+targ->QCN+" spilling it's %^BOLD%^RED%^blood %^BOLD%^BLACK%^on the ground%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^BLACK%^The %^BOLD%^%^CYAN%^runes %^BOLD%^%^BLACK%^on your blade come to life, the smell of %^BOLD%^RED%^blood %^BOLD%^%^BLACK%^overwhelms your senses as you impale the "+query_short()+"%^RESET%^");
	tell_object(targ,"%^BOLD%^BLACK%^"+ETOQCN+" sword gives off a %^YELLOW%^bright %^BOLD%^%^BLACK%^glow and before you can react the sword is buried deep in your chest spilling %^BOLD%^%^RED%^blood %^BOLD%^%^BLACK%^everywhere%^RESET%^");
		return roll_dice(6,6)+20;	}

}
