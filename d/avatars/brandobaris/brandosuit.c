#include <std.h>
inherit "/d/common/obj/clothing/shirt";

void create(){
	::create();
	set_name("a stylish suit");
	set_id(({ "suit", "stylish suit" }));
	set_short("Stylish Suit");
	set_obvious_short("stylish suit");
	set_long("This is a stylish and classy suit. It is -so- stylish and classy that it defies all description.
");
	set_value(50000);
	set_item_bonus("charisma",4);
	set_item_bonus("stealth",5);
	set_size(1);
	set_property("enchantment",9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" slips into the "+query_short()+", and is immediately the coolest person in the room.",ETO);
	tell_object(ETO,"You slip into the "+query_short()+" and are immediately stylin'.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" takes off the "+query_short()+", and is suddenly 85% less cool.",ETO);
	tell_object(ETO,"You take off the "+query_short()+", suddenly feeling 85% less cooler.");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 50){
	tell_room(environment(query_worn()),""+who->QCN+" scuffs "+ETOQCN+"'s "+query_short()+"! That's gonna be expensive to clean...",({ETO,who}));
	tell_object(ETO,"Not cool! "+who->QCN+" scuffed your "+query_short()+"!");
	tell_object(who,"You scuffed "+ETOQCN+"'s "+query_short()+"! Was that really called for?");
	}

}
