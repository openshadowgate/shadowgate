// sea elf wants fish
#include <std.h>
#include <daemons.h>
#include "../elf.h"
inherit "/std/monster";

create() {
  ::create();
  set_name("sea elf");
  set_id(({"elf","monster","sea elf","fisher"}));
  set_gender("female");
  set_race("elf");
  set_short("Sea Elf Fisher");
  set_long("This elf is dressed in some large "+
  "fish hides to fight the cold.  She has an "+
  "assortment of culinary items equipped ready to prepare seafood for dinner.");
  set_body_type("human");
  set_alignment(6);
  set_hd(6,8);
  set_stats("strength",8);
  set("aggressive",0);
  set_stats("intelligence", 16);
  set_stats("wisdom", 6);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_property("swarm",0);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(12);
  set_hp(random(50)+10);
  set_max_level(3);
  set_emotes(2,({
   "Sea Elf repairs some crab pods.",
   "Sea Elf sharpens a small knife.",
   "Sea Elf puts some crab parts in a box.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ I want lots of lobster.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ Crabs eat dead things  I bet there are lots of dead things under the ice.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ The heart of water was moved and weird things started happening in the sea.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ If you get me a lobster or a crab I will pay you for it.",
   "Sea Elf throws some firewood on the fire.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ Imagine going to dinner and getting served a six foot lobster!",
   }),0);
}
void receive_given_item(object obj){
   string name, item;
   object *ppl;
   int i;
   if(!objectp(TP)) return;
   if(!ETO) return;
   name = TPQN;
   if(!objectp(obj)) return;
   item = obj->query_name();
   if((string)obj->query_name() != "Dire Crab"
     && (string)obj->query_name() != "Dire Lobster") {
      force_me("say Ummm thanks, but this won't help.");
	   force_me("give "+obj->query_name()+" to "+name+"");
      return;
	  }

   switch (item){
     case "Dire Crab" :{
	     force_me("say Thank you for the Crab!");
   }
	 break;
	 
	 case "Dire Lobster":{

	     force_me("say Thank you for the Lobster.");
    }
	 break;}
	 
   tell_room(ETO,"The Sea Elf puts the meat away and hands you some money.");
   
   force_me("say Thanks for helping.  Trying to get those things caught in a trap is proving to be impossible but they look really tasty!");
  
   force_me("emote gets a sack of gold.");

   tell_object(TP,"Sea Elf gives you 1000 gold coins.");
   TP->add_money("gold",1000);
}
void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   set_spoken("wizish");
   if(!msg || !objectp(who)) return;

    force_me("say Hello Traveler, you look capable enough.  I'm trying to capture some of the lobsters and crabs down in the water but they are really strong.  I'll pay 1000 gold for each dead one.");

     return;
}

