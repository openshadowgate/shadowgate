#include <std.h>
#include <daemons.h>
#include "../daelmas.h"
inherit MONSTER;

void cook_em(int num);
void cooking(int num,int num2);
int FLAG;

create() {
   object ob;
   ::create();
   set_name("Fenegal");
   set_id(({"fenegal","Fenegal","human","cook"}));
   set_short("Fenegal the cook");
   set_long("The cook has a three day growth of beard, oily black hair "+
   	"and wears a dirty, grease stained apron.  Fenegal moves about the "+
   	"kitchen mumbling to himself and slamming pots and pans about."
    );
    set_hd(25,10);
    set_level(25);
    set_class("fighter");
    set_guild_level("fighter",25);
    set_class("thief");
    set_mlevel("thief",25);
    set_body_type("human");
    set_alignment(3);
    set_race("human");
    set_gender("male");
    set_ac(2);
    set_size(2);
    set_stats("strength",18);
    set_stats("dexterity",17);
    set_stats("charisma",12);
    set_stats("constitution",12);
    set_stats("wisdom",12);
    set_stats("intelligence",18);
    set_exp(2500);
    set_max_hp(200);
    set_hp(query_max_hp());
    set_achats(3,({
		"%^BOLD%^%^RED%^Fenegal grumbles: %^RESET%^Ye 'r black 'earted matey!",
		"%^BOLD%^%^RED%^Fenegal grumbles: %^RESET%^Fennie 'ill rip out yer gizzard!",
		"%^BOLD%^%^RED%^Fenegal grumbles: %^RESET%^Landlubbers!!",
		"%^BOLD%^%^RED%^Rubin grumbles: %^RESET%^Tha Cap'n 'ill take ye down!",
 		"%^BOLD%^%^RED%^Rubin grumbles: %^RESET%^Fennie 'ill cut yer 'eart out with a spoon!!",
   	}),0);
    set_emotes(1,({
		"Fenegal hums a ditty to himself.",
		"Fenegal washes the counter tops with a dirty rag.",
		"Fenegal spits on a glass and rubs it clean.",
		"Fenegal scratches himself absentmindedly.",
		"%^BOLD%^%^MAGENTA%^Fenegal grumbles: %^RESET%^cook this, cook that, "+
			"cook now, nev'r a thank ye.",
		"Fenegal mumbles to himself.",
		"Fenegal checks on the food cooking on the stove.",
		"%^BOLD%^%^MAGENTA%^Fenegal grumbles: %^RESET%^need more fishes.",
		"Fenegal brandishes a meat cleaver and then chops the head off "+
			"of a fish loudly before gutting it.",
   }),0);
   ob = new("/d/tharis/obj/wrist_sheath.c");
   	ob->set_property("monsterweapon", 1);
   	ob->move(TO);
   ob = new("/d/attaya/obj/screamer.c");
   	ob->set_property("monsterweapon", 1);
   	ob->move(TO);
   command("wear sheath");
   command("put screamer in sheath");
   add_search_path("/cmds/fighter");
   add_search_path("/cmds/thief");
  	set_property("swarm",1);
  	set_property("full attacks",1);
  	command("speak common");
  	command("speech %^BOLD%^%^MAGENTA%^growl");
   set_scrambling(1);
   set_thief_skill("move silently", 95);
   set_thief_skill("hide in shadows", 95);
   FLAG = 0;
}
void init(){
	string mname=TP->query_name();
   ::init();

	add_action("prepare_em","prepare");

   if(TP->query_invis()) return;
	if(mname == "vaser"){
		command("bow vaser awkwardly with a gap-toothed smile");
		command("say welcome 'ome Cap'n! Are ye 'ungry?");
		return;
	}
}
int prepare_em(string str)
{
	int i,MEAL;

  	if(!str)
    {
    	tell_object(TP,"%^BOLD%^Prepare what?");
     	return 1;
  	}

  	if(str)
    {
  		if(FLAG <2)
        {
  			MEAL = random(5);
    		switch(str)
            {
    			case "meal for one":
     				cooking(0,MEAL);
   				FLAG = FLAG + 1;
    				return 1;
    			case "meal for 1":
  					cooking(0,MEAL);
    				FLAG = FLAG + 1;
    				return 1;
    			case "meals for two":
    				for(i=0;i<2;i++)
                    {
    					cooking(0,MEAL);
                    }
    				FLAG = FLAG + 1;
    				return 1;
    			case "meals for 2":
    				for(i=0;i<2;i++){
    					cooking(0,MEAL);
      			}
    				FLAG = FLAG + 1;
    				return 1;
     			case "meals for three":
    				for(i=0;i<3;i++){
    					cooking(0,MEAL);
      			}
    				FLAG = FLAG + 1;
    				return 1;
     			case "meals for 3":
    				for(i=0;i<3;i++){
    					cooking(0,MEAL);
      			}
    				FLAG = FLAG + 1;
    				return 1;
   			case "meals for four":
    				for(i=0;i<4;i++){
    					cooking(0,MEAL);
      			}
    				FLAG = FLAG + 1;
    				return 1;
   			case "meals for 4":
    				for(i=0;i<4;i++){
    					cooking(0,MEAL);
      			}
    				FLAG = FLAG + 1;
    				return 1;
				default:
    				tell_object(TP,"%^RESET%^%^MAGENTA%^Fenegal grumbles:%^RESET%^ "+
    					"This ain't no damn cafeteria.\n");
    				return 1;
    		}
    	}
        else tell_room(ETO,"%^RESET%^%^MAGENTA%^Fenegal grumbles:%^RESET%^ I'm "+
    		"done cookin', ye comes back later.\n");
    	return 1;
 	}
}
void cook_em(int num){
	switch(num){
		case 0:
     		new(DOBJ+"fish_stew")->move(ETO);
			return;
		case 1:
     		new(DOBJ+"shark_steak")->move(ETO);
			return;
		case 2:
     		new(DOBJ+"fish_sandwich")->move(ETO);
			return;
		case 3:
     		new(DOBJ+"calamari")->move(ETO);
			return;
		case 4:
     		new(DOBJ+"salad")->move(ETO);
			return;
	}
}
void cooking(int num,int num2)
{
 	switch(num){
      case 0:
         break;
      case 1:
         break;
     	case 2:
   		tell_room(ETO,"%^RESET%^%^MAGENTA%^Fenegal rolls his eyes and walks "+
   			"slowly over to the stove mumbling to himself.");
         break;
      case 3:
         break;
         break;
      case 4:
         break;
      case 5:
         break;
      case 6:
   		tell_room(ETO,"Fenegal grabs up a plate from a cabinet.");
         break;
      case 7:
         break;
      case 8:
         break;
   	case 9:
   		tell_room(ETO,"%^RESET%^%^MAGENTA%^The cook stirs the pots and "+
   			"grumbles to himself.");
         break;
      case 10:
         break;
      case 11:
         break;
      case 12:
      	tell_room(ETO,"Fenegal fills the plate with food.");
         break;
      case 13:
         break;
      case 14:
         break;
     	case 15:
   		tell_room(ETO,"%^RESET%^%^MAGENTA%^The cook walks slowly back over "+
   			"to your table and slides the plate in front of you.");
         break;
      case 16:
         break;
      case 17:
			cook_em(num2);
         return;
	}
   num++;
	call_out("cooking",1,num,num2);
	return;
}
void reset(){
  	::reset();
	FLAG = 0;
}
