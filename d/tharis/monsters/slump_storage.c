#include <std.h>
#include <daemons.h>

inherit "/std/obj/fence_store_int";

void create(){
	::create();
   set_property("no teleport",1);
	
	set_properties((["light":2,"indoors":1]));
	
	set("short","thief storage");
	set("long","If your here you shouldn't be");
}

void reset(){
      object ob, ob2;
	int x, val;
      ::reset();
		
	if(!present("playersettabletrapkit"))
	{
		x = 4;
		while(x)
		{
			if(!random(3)) 
			{
				ob = TRAP_D->get_trap_object("high", "random");
				val = 1000 + random(251);
			}
			else 
			{
				ob = TRAP_D->get_trap_object("mid", "random");
				val = 550 + random(251);
			}
			if(objectp(ob)) 
			{
				ob->move(TO);
				ob->set_value(val);
			}
			x--;
			continue;
		}
	}

	if(!present("tools")){
		new("/d/tharis/obj/thief_tools")->move(TO);
		new("/d/tharis/obj/thief_tools")->move(TO);
		}
		
	if(random(20) <8)
		if(!present("sheath")){
			new("/d/tharis/obj/wrist_sheath")->move(TO);
			new("/d/tharis/obj/wrist_sheath")->move(TO);
			new("/d/tharis/obj/wrist_sheath")->move(TO);
		}
		
	if(random(20) < 8)
		if(!present("bag")){
			new("/d/tharis/obj/bpowder")->move(TO);
			new("/d/tharis/obj/bpowder")->move(TO);
		}
  	if(random(20) < 12)
	{
		if(!present("poison_vial_object_xxx", TO)) 
		{
			POISON_D->QueryPoisonObject("any", "contact")->move(TO);
			if(!random(2)) POISON_D->QueryPoisonObject("any", "contact")->move(TO);
			POISON_D->QueryPoisonObject("any", "ingested")->move(TO);
			if(!random(2)) POISON_D->QueryPoisonObject("any", "ingested")->move(TO);
			POISON_D->QueryPoisonObject("any", "injury")->move(TO);
			if(!random(2)) POISON_D->QueryPoisonObject("any", "injury")->move(TO);
		}
	}

  if(random(10) < 7)
    if(!present("caltrops"))
      new("/d/tharis/obj/caltrops")->move(TO);
    if(!present("smokebomb")) {
      ob = new("/d/tharis/obj/smokebomb");
      ob->move(TO);
      ob->set_origin("tharis");
    }
    while(ob2 = present("kitxyz")) ob2->remove();
    while(!present("brilliant rose 3")) {
      ob = new ("/d/common/obj/potion/advanced_heal");
      ob->set_uses(15 + random(5));
      ob->move(TO);
    }
}
