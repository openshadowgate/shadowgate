#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
	::create();
	set_name("claw");
	set_id(({ "claw" }));
	set_short("This is a test claw");
	set_obvious_short("A test claw");
	set_long("I made this test claw
");
	set_value(7999);
	set_lore("This best test claw ever.
");
	set_property("lore difficulty",19);
	set_item_bonus("damage resistance",20);
	set_property("enchantment",4);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),""+query_short()+" cuts the mess outta "+targ->QCN+" as "+ETOQCN+" slings it wildly",({ETO,targ}));
	tell_object(ETO,""+query_short()+" cuts the mess outta "+targ->QCN+"");
	tell_object(targ,""+ETOQCN+" hits you with the "+query_short()+"");
		return roll_dice(3,5)+1;	}

}
