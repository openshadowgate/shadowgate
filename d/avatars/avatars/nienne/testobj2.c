#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
	::create();
	set_name("testcloak");
	set_id(({ "cloak", "cape" }));
	set_short("super awesome cape");
	set_obvious_short("long cape");
	set_long("It's a cool cape.
");
	set_value(1);
	set_lore("It's shiney!
");
	set_property("lore difficulty",4);
	set_item_bonus("wisdom",1);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" wears the cape.",ETO);
	tell_object(ETO,"You wear the cape.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes the cape.",ETO);
	tell_object(ETO,"You remove the cape.");
	return 1;
}

