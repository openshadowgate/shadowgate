#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("test");
	set_id(({ "test" }));
	set_short("test");
	set_obvious_short("test");
	set_long(
@AVATAR

AVATAR
	);
	set_weight(10);
	set_value(15);
	set_heart_beat(1);
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
		switch(random(1)) 
		{
			case 0:
				tell_object(ETO, "Your "+query_short()+" flashes brightly!");
				tell_object(EETO, "The "+query_short()+" carried by "+ETOQCN+" flashes brightly!", ({ETO}));
				break;
		}
	}
}