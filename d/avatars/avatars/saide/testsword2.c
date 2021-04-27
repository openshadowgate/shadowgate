#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("test sword");
	set_id(({ "sword", " test sword", " test" }));
	set_short("A test sword");
	set_obvious_short("A test sword");
	set_long(
@AVATAR
This is a test sword.

AVATAR
	);
	set_weight(10);
	set_value(1000);
	set_heart_beat(1);
	set_type("slashing");
	set_prof_type("blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",3);
}





void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
	 if(random(500) > 495) 
	 {
		switch(random(2)) 
		{
			case 0:
				tell_object(ETO, "Your "+query_short()+" glows brightly!");
				tell_object(EETO, "The "+query_short()+" carried by "+ETOQCN+" glows brightly!", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "Your "+query_short()+" hums a soft tune!");
				tell_object(EETO, "The "+query_short()+" carried by "+ETOQCN+" hums a soft tune.", ({ETO}));
				break;
		}
	}
}