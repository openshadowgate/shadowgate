#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("collar");
	set_id(({ "collar" }));
	set_short("%^BOLD%^%^YELLOW%^ragged dog collar%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^ragged dog collar%^RESET%^");
	set_long("This is a leather dog collar that an owner might attach a chain or leash too. It looks badly worn and is about the size of a couple thumbs wide. 
");
	set_value(0);
	set_size(1);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_skill_bonus("thievery",30);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_skill_bonus("thievery",-30);
	return 1;
}

