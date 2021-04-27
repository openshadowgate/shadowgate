#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("heart");
	set_id(({ "heart" }));
	set_short("test heart");
	set_obvious_short("test heart");
	set_long("This is a test item for proof of concept.
");
	set_value(10);
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"As you slip "+query_short()+" into the hole in your chest, you feel full of life, and health returns to you as the heart begins beating.");
	ETO->do_damage("torso",random(-200));
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"You feel desperate to have the heart, beating in your chest, and you feel life slip from you");
	ETO->do_damage("torso",random(200));
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 50){
	tell_room(environment(query_worn()),"",({ETO,who}));
	tell_object(ETO,"The blow to the heart is stopped");
	tell_object(who,"");
return (damage*0)/100;	}

}
