#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
	::create();
	set_name("plate of the planar inferno");
	set_id(({ "plate", "full plate", "blazing plate", "armor", "fullplate" }));
	set_short("%^BOLD%^%^RED%^P%^RESET%^%^ORANGE%^l%^BOLD%^%^RED%^a%^ORANGE%^t%^RED%^e of the P%^RESET%^%^ORANGE%^l%^BOLD%^%^RED%^a%^ORANGE%^n%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^r I%^RESET%^%^ORANGE%^n%^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^e%^BOLD%^r%^RESET%^%^ORANGE%^n%^BOLD%^%^RED%^o%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^a suit of %^ORANGE%^b%^RED%^l%^ORANGE%^a%^WHITE%^z%^ORANGE%^i%^RED%^n%^ORANGE%^g %^RED%^f%^RESET%^%^RED%^u%^BOLD%^l%^RESET%^%^RED%^l%^BOLD%^p%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^e a%^RESET%^%^RED%^r%^BOLD%^m%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^");
	set_long("%^BOLD%^%^RED%^This suit of full plate armor is surrounded by an intense aura of f%^ORANGE%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^RED%^e, encasing its wearer in a %^RESET%^%^RED%^sweltering%^BOLD%^, %^ORANGE"
	"%^c%^WHITE%^h%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^o%^WHITE%^t%^RESET%^i%^YELLOW%^c i%^RED%^n%^RESET%^%^RED%^f%^YELLOW%^e%^RESET%^%^RED%^r%^ORANGE%^n%^BOLD%^o %^RED%^that seems to burn endlessly withou"
	"t any need for fuel. Within the flames, numerous plates of some strange, %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^"
	"o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e-l%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^k%^ORANGE%^e r%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^c%^ORANGE%^k %^BOLD%^%^RED%^fit smoothly over one another to ward the wearer "
	"against blows from nearly any angle, yet even this seems to remain in a %^RESET%^%^RED%^m%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^lt%^WHITE%^e%^RED%^n %^BOLD%^state, held to its shape only by a %^RESET%^f%^Y"
	"ELLOW%^a%^RESET%^i%^YELLOW%^n%^RESET%^t f%^YELLOW%^i%^RESET%^e%^YELLOW%^l%^RESET%^d %^BOLD%^%^RED%^of %^ORANGE%^a%^RESET%^%^ORANGE%^m%^BOLD%^b%^RESET%^%^ORANGE%^e%^BOLD%^r%^RESET%^%^ORANGE%^-%^BOLD%^h"
	"%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^e%^ORANGE%^d e%^WHITE%^n%^ORANGE%^er%^WHITE%^g%^ORANGE%^y %^RED%^that also seems to render the armor wearable without harm to oneself. Strangely, there appear to b"
	"e no catches or other mechanisms by which to unfasten or secure the armor, leaving it unclear how one is meant to even put it on.%^RESET%^
"	);
	set_value(50000);
	set_lore("%^BOLD%^%^RED%^Of the Prime's four Inner Planes, the %^ORANGE%^Plane of Fire %^RED%^is perhaps the one most instinctively feared by mortals for its greedy and consuming nature, yet is also one of the "
	"most valued, for its ability to bring warmth and light. This plate armor is wrought entirely of energies drawn from the Plane of Fire itself, and was summoned and shaped into the form it now holds usi"
	"ng powerful rituals known only to %^CYAN%^Mystra's %^RED%^clergy, upon the request of a Kossuthan warrior known as %^GREEN%^Elurion Meriot%^RED%^. The attributes displayed by this odd material reflect"
	" the duality of fire, burning away harmful energies and scalding those who would grow too close.%^RESET%^
"	);
	set_property("lore difficulty",30);
	set_item_bonus("spell damage resistance",20);
	set_item_bonus("fortitude",2);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" draws the plate armor close, pulling it tight. A blast of %^RESET%^%^RED%^sweltering air %^BOLD%^erupts as the flames shift and settle into place.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You trust to the flames and embrace the plate armor tightly. You feel a rush of %^ORANGE%^intense heat %^RED%^erupt around you as the fire %^RESET%^%^ORANGE%^s%^BOLD%^%^RED%^h%^RESET%^%^RED%^i%^BOLD%^f%^RESET%^%^RED%^t%^ORANGE%^s %^BOLD%^%^RED%^to embrace you in return, lending you its nature for a time.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+"'s blazing armor seems to flicker and die down, pulling away.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You will the flames to recede, for now. You feel colder as they pull away from your body.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^A blast of intense heat singes "+ETOQCN+"'s attacker!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^A blast of intense heat singes "+who->QCN+"!%^RESET%^");
	tell_object(who,"%^BOLD%^%^RED%^A blast of intense heat singes you!%^RESET%^");
		who->do_damage("torso",roll_dice(10,3));
return damage;	}

}
