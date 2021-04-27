#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("test object");
	set_id(({ "test", " object", " test sword" }));
	set_short("test object");
	set_obvious_short("test object");
	set_long(
@AVATAR
this is a test

AVATAR
	);
	set_weight(10);
	set_value(1000);
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
				tell_object(ETO, "Your "+query_short()+" flashes for a brief moment. ");
				tell_room(EETO, "The "+query_short()+" carried by "+ETOQCN+" flashes for a brief moment!", ({ETO}));
				break;
		}
	}
}