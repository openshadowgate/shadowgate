#include <std.h>
inherit "/d/common/obj/armour/leather";

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^Sp%^BLACK%^%^BOLD%^a%^RESET%^%^ORANGE%^rr%^RESET%^o%^ORANGE%^w's %^MAGENTA%^We%^BOLD%^a%^RESET%^%^MAGENTA%^vi%^BLACK%^%^BOLD%^n%^MAGENTA%^g D%^BOLD%^an%^MAGENTA%^c%^BLACK%^%^BOLD%^e leather armor%^RESET%^");
	set_id(({ "Sparrow Armor", "sparrow armor", "sparrowarmor", "armor", "leather armor", "black leather armor" }));
	set_short("%^RESET%^%^ORANGE%^Sp%^BLACK%^%^BOLD%^a%^RESET%^%^ORANGE%^rr%^RESET%^o%^ORANGE%^w's %^MAGENTA%^We%^BOLD%^a%^RESET%^%^MAGENTA%^vi%^BLACK%^%^BOLD%^n%^MAGENTA%^g D%^BOLD%^an%^MAGENTA%^c%^BLACK%^%^BOLD%^e leather armor%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^black leather armor%^RESET%^");
	set_long("%^BLACK%^%^BOLD%^Crafted from soft leather that has been treated and dyed to %^RESET%^black%^BLACK%^%^BOLD%^, this set of studded has been cut to a woman's "
"%^RESET%^%^MAGENTA%^lithe form%^BLACK%^%^BOLD%^. It has a daring low cut in the front that would only accentuate a woman's figure. The entire surface of the armor is engraved "
"and etched with a design of a multitude of %^RESET%^%^ORANGE%^sparrows%^BLACK%^%^BOLD%^ in flight, and that etching has been filled with %^YELLOW%^molten gold%^BLACK%^%^BOLD%^ "
"and crushed %^RESET%^%^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e j%^BOLD%^as%^RESET%^%^BLUE%^per%^BLACK%^%^BOLD%^. The armor ties with heavy %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l"
"%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ in a crisscross pattern down "
"the wearer's back, and long %^RESET%^%^BLUE%^blue%^BLACK%^%^BOLD%^ and %^RESET%^%^MAGENTA%^purple%^BLACK%^%^BOLD%^ ribbons hang down from the armor.%^RESET%^");
	set_value(75000);
	set_lore("%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^sp%^BLACK%^%^BOLD%^a%^RESET%^%^ORANGE%^rr%^RESET%^o%^ORANGE%^w %^MAGENTA%^we%^BOLD%^a%^RESET%^%^MAGENTA%^v"
"%^BLACK%^%^BOLD%^e%^MAGENTA%^s %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^d%^BOLD%^an%^MAGENTA%^c%^BLACK%^%^BOLD%^e%^MAGENTA%^s%^BOLD%^%^BLACK%^,\n"
"%^BOLD%^%^BLACK%^Amid the %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o"
"%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^.\n"
"%^MAGENTA%^F%^BOLD%^l%^BLACK%^y %^RESET%^%^ORANGE%^sp%^BLACK%^%^BOLD%^a%^RESET%^%^ORANGE%^rr%^RESET%^o%^ORANGE%^w%^BOLD%^BLACK%^, %^MAGENTA%^f%^BOLD%^l%^BLACK%^y.");
	set_property("lore difficulty",15);
	set_size(2);
	set_property("enchantment",4);
	set_item_bonus("magic resistance",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+" slips on the black leather armor and ties the %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ behind her.%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You slip on the the black leather armor, the %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ swirling around you.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BLACK%^%^BOLD%^"+ETOQCN+" slips off the black leather armor and unties the %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ from behind her.%^RESET%^",ETO);
	tell_object(ETO,"%^BLACK%^%^BOLD%^You slip off the the black leather armor, the %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ swirling away from you.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ dance and distract %^RED%^"+who->QCN+"!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ dance and distract %^RED%^"+who->QCN+"!");
	tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s %^BLUE%^s%^MAGENTA%^i%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^k %^BLUE%^r%^BLACK%^%^BOLD%^i%^RESET%^%^BLUE%^b%^MAGENTA%^b%^BLUE%^o%^BLACK%^%^BOLD%^n%^RESET%^%^MAGENTA%^s%^BLACK%^%^BOLD%^ dance and distract %^RED%^you!");
		who->set_paralyzed(random(2)+ 1);
       }
}