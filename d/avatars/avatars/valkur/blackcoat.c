#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("coat");
	set_id(({ "coat", "black coat", "long coat" }));
	set_short("%^RESET%^%^ORANGE%^A long %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^coat%^RESET%^");
	set_obvious_short("A long black coat");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a long %^BOLD%^%^BLACK%^black %^RESET%^%^ORANGE%^coat made of a strong, light material. Despite being quite large the garment seems to resist catching on anything, flowing like water around jagged corners and snags that would hook any other coat. There are several leather straps with dull bra%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^s buckles along the front that can be used to adjust the fit to almost any frame. A %^BOLD%^%^BLACK%^hood %^RESET%^%^ORANGE%^hangs down the back of the coat that can completely obscure the wearer's face from view giving a very menacing appearance. %^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(4000);
	set_lore(
@AVATAR
This is a rare example of a set of coats crafted in Tharis for
a group of elven thieves who were attempting to rob the dukal palace.
The adventurers failed, but not due to any fault with the coats.
The garments are famed for being hard to catch when climbing through
windows, or sneaking about in alleys. In addition the magical 
property that gives them this trait occassionally allows a wearer
to avoid the blows of thier opponents in battle. Several of these 
found thier way onto the black market and are a rare and treasured
find for those with fashion as well as practical sense.

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The coat worn by "+ETOQCN+" catches and deflects the blow!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your opponent's strike catches in the folds of your coat!%^RESET%^ ");
	tell_object(who,"%^BOLD%^%^WHITE%^"+ETOQCN+" 's "+query_short()+" catches your blow in it's folds! %^RESET%^");
return (damage*-100)/100;	}

}
