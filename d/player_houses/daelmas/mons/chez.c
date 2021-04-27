#include <std.h>
#include <daemons.h>
#include "../daelmas.h"
inherit MONSTER;

int xx,FLAG,HFLAG,timer;

create() {
   	object ob;
    	::create();
    	set_name("Chezalethek");
    	set_id(({"chez","Chez","gremlin","Chezalethek","chezalethek"}));
    	set_short("Chezalethek");
    	set_long("%^BOLD%^%^GREEN%^The little gremlin stands about three "+
    		"feet tall with it's arms reaching down to it's knees. The "+
    		"creature's hands are huge, obviously larger then normal "+
    		"sized as they take the creatures arms down to ground. Long, "+
    		"curving fingers adorn it's giant hands, ending in sharp "+
    		"talons, which seem retractable. The creatures skin a scaly "+
    		"and green, it looks extremely tough and dry. The gremlin's "+
    		"face is not unlike a gnolls, an elongated snout, except "+
    		"that it has no hair. The creatures chest and torso make "+
    		"up most of the rest of it's body, it's short, stubby legs "+
    		"making it look almost comical. A white toga covers the "+
    		"creatures modesty.%^RESET%^"
    	);
    	set_hd(16, 6);
    	set_level(15);
    	set_class("mage");
    	set_guild_level("mage",16);
    	set_mlevel("mage",16);
    	set_class("fighter");
    	set_mlevel("fighter",15);
    	set_class("thief");
    	set_mlevel("thief",18);
    	set_body_type("human");
    	set_alignment(9);
    	set_race("gremlin");
    	set_gender("male");
    	set_ac(2);
    	set_stats("strength",18);
    	set_stats("dexterity",17);
    	set_stats("wisdom",12);
    	set_stats("intelligence",18);
    	set_exp(1500);
    	set_max_hp(150);
    	set_hp(query_max_hp());
    	set_achats(3,({
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^Yum! Yum!",
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^Still you stand! "+
			"Me bite, you let!",
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^BOLD%^%^RED%^GONE GET YOU!!",
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^ACK! STILL YOU BE HERE, WHY?!?!",
 		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^Hurts it does?!?!",
   	}),0);
    	set_emotes(1,({
		"Chezalethek chirps to himself as he polishes the marble surfaces.",
		"Chezalethek snickers as he looks you over.",
		"Chezalethek hums in a high pitched voice as he cleans.",
		"Chezalethek takes a rag and cleans the marble and wood surfaces.",
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^cleaning you help?",
		"Chezalethek grumbles about the dirty room.\n"+
			"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^Clean me "+
			"always, mess they always.",
		"Chezalethek traces arcane patterns over the walls while he chants quietly.",
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^Boss you seen?",
		"%^BOLD%^%^GREEN%^Chezalethek squeaks: %^RESET%^Big D, be he where?",
    	}),0);
    	set_spell_chance(50);
    	set_func_chance(35);
    	set_spells( ({"magic missile","hideous laughter","chill touch","fireball"}));
    	set_funcs(({"special_spell"}));
	new("/d/azha/obj/mr_ring")->move(TO);
    		command("wear ring");
  	ob=new("/d/shadow/obj/armor/robe.c");
  		ob->set_short("A toga");
  		ob->set_long("This robe is a toga that barely covers the wearers modesty.");
  		ob->move(TO);
  		command("wear robe");
  	new(DOBJ+"marble_key")->move(TO);
  	new("/d/shadow/obj/misc/pouch.c")->move(TO);
  		command("wear pouch");
  		command("put key in pouch");
    	add_search_path("/cmds/fighter");
    	add_search_path("/cmds/thief");
    	add_search_path("/cmds/mage");
    	set_max_level(8);
    	set_property("swarm",1);
    	set_property("full attacks",1);
    	command("speak elven");
    	command("speech %^BOLD%^%^GREEN%^squeak");
    	set_scrambling(1);
    	set_thief_skill("move silently", 95);
    	set_thief_skill("hide in shadows", 95);
    	set_speed(30);
    	set_mob_magic_resistance("average");
	set_property("magic",2);
	FLAG = 0;
	HFLAG = 0;
}
int special_spell() {
	object me = TO;
	object vic = me->query_current_attacker();
    	xx=random(4)+1;
    	switch(xx) {
    		case 1:
			me->force_me("giggle wildly");
        		me->force_me("cast powerword stun at "+vic->query_name());
        		return 1;
    		case 2:
        		me->force_me("grin impishly");
        		me->force_me("cast lightning bolt at "+vic->query_name());
        		return 1;
    		case 3:
        		me->force_me("cackle");
        		tell_object(vic,"%^BOLD%^%^RED%^Chezalethek open his hands "+
        			"with his palms toward you and magic needles shoot at you!");
        		tell_room(ETO,"%^BOLD%^%^RED%^Chezalethek open his hands, "+
        			"palms towards "+vic->query_cap_name()+" and shoots "+
        			"his full of magic needles!",vic);
        		vic->do_damage("torso",random(20)+3);
        		return 1;
    		case 4:
			if(me->query_hp() < 50) {
	    			me->add_hp(random(10)+6);
	    			tell_room(ETO,"%^MAGENTA%^Chezalethek touches himself "+
	    				"and his wounds heal a little.");
	    			return 1;
  			}
        		return 1;
    	}
}
void init(){
	string mname=TP->query_name();
    	::init();

	add_action("pat_em","pat");

    	if(avatarp(TP) || TP->query_invis()) return;
	if(mname == "daelmas"){
		command("bow daelmas deeply");
		command("say hallo elfie boss, whatcha need?");
		return;
	}else if(mname == "gabrielle"){
		command("emote starts to tremble");
		command("emote watches Gabrielle fearfully and runs into a "+
			"wall trying to leave the room hurriedly");
		command("emote falls on his butt and shakes his head groggily");
		return;
	}else{
		command("say belong you here?");
		command("emote raises his eyebrow at you.");
		command("say boss me tell, trouble you in!");
		return;
	}
}
int pat_em(string str) {
	string mname=TP->query_name();

    	if(!str) {
       	notify_fail("%^BOLD%^%^CYAN%^Pat yourself do you? Nasty!\n");
        	return 0;
    	}
	if(str == "gremlin" || str == "chez" || str == "Chez" ||
		str == "Chezalethek" || str == "chezalethek"){
		if( mname == "daelmas" || mname == "diego"){
			if (FLAG == 0){
				tell_room(ETP,""+TPQCN+" pats the little gremlin on the head.\n");
				command("emote purrs contendedly!");
				command("get key from pouch");
				command("give key to daelmas");
				command("give key to diego");
				command("say dat you want boss?");
				FLAG = 1;
				return 1;
			}else{
				tell_room(ETP,""+TPQCN+" pats the little gremlin on the head.\n");
				command("whisper daelmas %^BOLD%^%^GREEN%^keys no more boss, "+
					"later maybe.");
				command("whisper diego %^BOLD%^%^GREEN%^keys no more boss, "+
					"later maybe.");
				return 1;
			}
		}else if(mname == "gabrielle"){
			if (FLAG == 0){
				tell_room(ETP,""+TPQCN+" pats the little gremlin on the head.\n");
				command("say sorry me am mistress.");
				command("emote starts to cry");
				command("say me no hurt again, PLEASE!");
				command("get key from pouch");
				command("drop key");
				command("emote trembles and grovels at "+
					"Gabrielle's feet");			
				FLAG = 1;
				return 1;
			}else{
				tell_room(ETP,""+TPQCN+" pats the little gremlin on the head.\n");
				command("whisper gabrielle %^BOLD%^%^GREEN%^keys no more "+
					"mistress, me make special for you...soon...soon.");
				command("whisper gabrielle %^BOLD%^%^GREEN%^no hurt Chezzie "+
					"please.");
				command("emote trembles fearfully covering his head");
				return 1;
			}				
		}else{
			tell_room(ETP,""+TPQCN+" tries to pet the gremlin.\n");
			command("emote tries to bite your hand.");
			command("say dog me not!!");
			command("growl");
    			return 1;
    		}
    	}
}
void heart_beat(){
    	::heart_beat();
    	timer++;
    	if(timer > 100){
      	timer = 0;
      	if(!random(5)){
      		if(HFLAG = 0){
      			command("hide_in_shadows");
      			HFLAG = 1;
      			return 1;
      		}else{
      			command("step");
      			HFLAG = 0;
      			return 1;
      		}
      	}
    	}
}
void reset(){
	::reset();
	if(FLAG == 1){
		FLAG = 0;
	  	new(DOBJ+"marble_key")->move(this_object());
	  	command("put key in pouch");
		return;
	}
}