//coded by Diego//

inherit "/std/monster";
#include <std.h>
#include <daemons.h>
#include "../melic.h"

void create() {
  	::create();
  	set_name("gammel");
  	set_id(({"old man","half-elf","gammel","guard"}));
  	set("race","half-elf");
  	set_gender("male");
  	set("short","%^BOLD%^%^BLUE%^Gammel the Retired%^RESET%^");
  	set("long","%^CYAN%^"+
  		"Gammel is a retired guard from Graez.  He is quite large, but seems to be "+
  		"misplaced as a guard.  His once %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ hair "+
		"and beard now have as many %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^ hairs as "+
		"%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ ones.  He looks clean and smells of "+
		"weapon oil.  All he does these days is sit a sleep in his chair.\n"+
		"%^RESET%^"
		);
  	set_overall_ac(-5);
  	set_level(25);
  	set_body_type("human");
  	set_class("fighter");
  	set_alignment(9);
  	set_size(2);
  	set_hd(25,1);
  	set_stats("strength",18);
  	set_stats("charisma", 9);
  	set_stats("dexterity",16);
  	set_stats("constitution",16);
  	set_stats("wisdom",9);
  	set_stats("intelligence",9);
  	set_hp(275);
  	set_exp(1);
  	call_out("do_gdog",1);
  	set_wielding_limbs(({"right hand","left hand"}));
  	new(SHWEAP+"halberd")->move(this_object());
  		command("wield halberd");
  	new(SHARM+"coif")->move(this_object());
  		command("wear coif");
  	new(SHARM+"chain")->move(this_object());
  		command("wear chain");
  	add_money("silver",random(100));
  	add_money("gold",random(250));

    	set_emotes(5,({
		"Gammel yawns and scratches himself without waking up.",
		"Gammel snorts and snores.",
		"Gammel mumbles in his sleep.",
    		"Gammel coughs and mumbles then readjusts in his chair.",
    	}),0);
}
void do_gdog() {
   	object gdog;
   	if(!objectp(ETO)) return;
   		gdog = new(MMONS+"gdog");
   		gdog->set_owner(TO);
   		gdog->move(ETO);
}
void heart_beat() {
   	object atk;
   	::heart_beat();
   	if(!objectp(TO)) return;
   	if(!objectp(ETO)) return;
   	if((atk = query_current_attacker())) {
      	command("sic "+atk->getNameAsSeen());
   		return 1;
	}
}
