//updated by Circe 7/11/04 with new desc, etc.
//edited by Saide to use TO, ETO, EETO, and have
//some appropriate checks - also, just basically
//cleaned up the code so it looks better
#include <std.h>
#include <move.h>

inherit OBJECT;

#define WOODS ({"%^YELLOW%^oak","%^BOLD%^pine","%^RESET%^%^ORANGE%^birch",\
"%^BOLD%^%^BLACK%^ash","%^BOLD%^walnut","%^RESET%^%^ORANGE%^cypress",\
"%^RESET%^%^ORANGE%^chestnut","%^RESET%^%^RED%^cherry",\
"%^YELLOW%^hickory","%^YELLOW%^maple",\
"%^RESET%^%^RED%^teak","%^RESET%^%^ORANGE%^poplar","%^RESET%^%^RED%^rose wood",\
"%^RESET%^%^ORANGE%^elm","%^RESET%^%^ORANGE%^cedar","%^RESET%^%^RED%^redwood"})

object ob; 
string tobacco_type;
int lit, packed, tobacco, light_time, sp_adjust, con_req;
 
void create() 
{
	int i;
	string str,WOOD;
  	::create();
    	i = random(sizeof(WOODS));
    	WOOD = WOODS[i];
    	if(WOOD == "%^YELLOW%^oak" || WOOD == "%^BOLD%^%^BLACK%^ash" || 
	WOOD == "%^RESET%^%^ORANGE%^elm")
	{
      	str = "an";
    	}
	else
	{
      	str = "a";
    	}
    	set_name("wooden pipe");
    	set_id(({"pipe",""+WOOD+" pipe","wooden pipe","a wooden pipe"}));
    	set_short("a wooden pipe%^RESET%^");
    	set_long("This hand-carved creation is made of seasoned "+WOOD+" %^RESET%^"+
       "fashioned into a slender pipe and fitted with a %^BOLD%^%^BLACK%^"+
       "black mouthpiece%^RESET%^.  The bowl of the pipe is deep and "+
       "decorated with %^ORANGE%^burned scrollwork %^RESET%^that give "+
       "it an elegant appearance.\n"
       "Try packing/filling it with some tobacco, then smoking it.\n"
       "Douse it to put it out.\n");
    	set_weight(0);
    	set_value(0);
    	tobacco = 0;
    	packed = 0;
    	lit = 0;
    	con_req = 0;
    	sp_adjust = 0;
}
 
void init() 
{
	add_action("extinguish", "douse");
    	add_action("smoke","smoke");
    	add_action("pack_pipe","pack");
    	add_action("pack_pipe","fill");
}
 
int smoke(string str) 
{
	if(!objectp(ETO)) return 0;
    	if(!id(str)) 
	{
      	notify_fail("Smoke what?\n");
        	return 0;
    	}
    	if(!packed) 
	{
      	notify_fail("Why would you want to smoke an empty pipe?\n");
        	return 0;
    	}
    	if(lit) 
	{
      	notify_fail("You're already smoking it!\n");
        	return 0;
    	}
    	if(con_req > ETO->query_stats("constitution"))
	{
  		tell_object(ETO, "You can't smoke this tobacco, it is too strong for you!");
		tell_object(ETO, "You unpack the pipe, and drop the contents on the ground.");	
		set_short("a wooden pipe%^RESET%^");
		packed = 0;
		return 1;
    	}
    	tell_object(ETO, "You begin smoking your pipe.\n");
	if(objectp(EETO))
	{
    		tell_room(EETO, ETOQCN+" begins smoking a pipe.\n", ({ETO}));
	}
	//Afi somehow had like 36000 tobacco on their
	//pipe - this way, if tobacco is > 500 then set
	//it to 500 to prevent this and all the
	//call outs that will go with it - Saide
	if(tobacco > 500) 
	{
		tobacco = 500;
	}
    	call_out("go_out", tobacco);
    	call_out("take_drag", 5);
    	light_time = time();
    	set_short("A lit pipe");
    	set_property("lit pipe",1);
    	lit = 1; 
    	return 1;
}
 
int extinguish(string str) 
{
	if(!objectp(ETO)) return 0;	
    	if(!id(str)) 
	{
      	notify_fail("Douse what?\n");
        	return 0;
    	}
    	if(!lit) 
	{
      	notify_fail("Your pipe is not lit!\n");
        	return 0;
    	}
    	tell_object(ETO, "You douse your pipe.\n");
	if(objectp(EETO))
	{	
		tell_room(EETO, ETOQCN + " douses a pipe.", ({ETO}));
	}
	tobacco -= (light_time - time());
    	remove_call_out("go_out");
    	remove_call_out("take_drag");
    	set_short("A packed pipe");
    	remove_property("lit pipe");
    	lit = 0;
    	return 1;
}
 
void go_out() 
{
	tobacco = 0;
	if(!objectp(ETO)) return;
	if(living(ETO)) 
	{	
		if(objectp(EETO))
		{
			tell_room(EETO, ETOQCN+" pipe goes out.",({ETO}));
		}
		tell_object(ETO, "Your pipe goes out.\n");
	}
    	remove_call_out("take_drag");
    	set_short("a wooden pipe");
    	remove_property("lit pipe");
    	lit = 0;
    	packed = 0;
}

void take_drag() 
{
	if(!objectp(ETO)) return;
	if(living(ETO)) 
	{
		tell_object(ETO, "%^RED%^You take a long, deep drag on your pipe.");
		if(objectp(EETO))
		{
			tell_room(EETO, ETOQCN+"%^RED%^ takes a long, deep drag on a pipe.",({ETO}));
	      }
	}
    	if(tobacco_type == "afgan") 
	{
		ETO->add_intox(7);
		tell_object(ETO, "You start to feel strange, your mind wanders...");
	}
	if(objectp(EETO))
	{
    		tell_room(EETO, ETOQCN+"%^RED%^ giggles and stares off into the distance", ({ETO})); 
	}
    	ETO->set_sp((int)ETO->query_sp()+sp_adjust);
    	call_out("take_drag", 50, TO); 
}
 
int pack_pipe(string str)
{
    	string pipe;

    	if(!objectp(ETO)) return 0;
    	if(!str) return 0;	
	if(packed)
	{
		notify_fail("Your pipe is already packed!\n");
		return 0;
	}
    	if((sscanf(str, "%s with %s", pipe, tobacco_type)) !=2) return 0;
	if(pipe != "pipe") return 0;
    	if(tobacco_type == "tobacco") 
	{
		notify_fail("That is not a valid type of tobacco!\n");
		return 0;
	}
    	if(!(ob = present(tobacco_type,ETO)))
	{
       	notify_fail("You can't pack your pipe with "+tobacco_type+"!!!\n");
		return 0;
      }
    	if(ob->id("tobacco"))
	{ 

		//con_req = (int)ob->query_con_check();
		tell_object(ETO, "You pack your pipe with "+tobacco_type+" tobacco.");
		if(objectp(EETO)) 
		{
			tell_room(EETO, ETOQCN+ " packs "+ ETO->QP + 
			" pipe with some "+tobacco_type+ " tobacco.", ({ETO}));
		}
		set_short("A packed pipe");
     		tobacco=500;
		packed=1;
		sp_adjust = ob->set_uses();
		return 1;
	}
	return 0;
}

remove()
{
   	if (lit) 
	{
		lit = 0;
		packed = 0;
        	remove_call_out("take_drag");
        	remove_call_out("go_out");
        	remove_property("lit pipe");
   	}
 
   	if(packed) packed = 0;
   	TO->set_short("a wooden pipe");
   	return ::remove();  
}
/*
int drop(){

	write("You decide to keep the pipe, and return it to your inventory.");
	return 1;
}
*/
/*
void save_me(string fname) 
{
   if (lit)
   {
     tobacco -= (light_time - time());
     remove_call_out("take_drag");
     remove_call_out("go_out");
     packed = 1;
     lit = 0;
     this_object()->set_short("a packed pipe");
   }

  return ::save_me(fname);
}
*/

//mixed *query_auto_load(){ return ({"/d/shadow/obj/misc/pipe",({}) });}

//restore_me(){return 1;}
//save_me(){return 1;}

