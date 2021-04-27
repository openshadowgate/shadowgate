#include <std.h>
inherit WEAPONLESS;

void sicing(object tp, int num);

void create(){
	object obj;
	::create();
	set_name("shadow hound");
	set_short("a shadow hound");
	set_id(({"shadow hound","hound","monster"}));
	set_long(
		"This is a large dog-like creature made out of the stuff of shadows and "+
		"evil essence.  It is rumored that this is one of Malar's personal "+
		"beasts sent to punish those that array themselves against malar.  "+
		"The beast's baleful red glowing eyes stare at you with a the hideous "+
		"intelligence of a creature formed for a malignant purpose.  The "+
		"creature's body is made from the stuff of the shadows, but yellow "+
		"blood stained teeth and claws look to be very substantial."
	);
	set_gender("neuter");
	set_race("shadow");
	set_body_type("quadruped");
	set_hd(25,4);
	set_max_hp(200+random(40));
	set_hp(query_max_hp());
	set_alignment(9);
	set_overall_ac(-15);
	set_class("fighter");
	set_mlevel("fighter",25);
	set_level(25);
	set_property("full attacks",1);
	set_max_level(25);
	set_exp(2500);
	set_stats("strength",25);
	set_property("swarm",1);
	set("aggressive",25);
	set_mob_magic_resistance("average");
	remove_limb("right hand");
	remove_limb("left hand");
	add_limb("right claw","right foreleg",0,0,0);
	add_limb("left claw","left foreleg",0,0,0);
	add_limb("fangs","mouth",0,0,0);
	set_attack_limbs(({"right claw","left claw","right claw","left claw","fangs"}));
	set_attacks_num(5);
	set_damage(1,8);
	set_base_damage_type("slashing");
	set_emotes(19, ({
		"%^BOLD%^%^BLACK%^The shadow hound %^CYAN%^howls %^BLACK%^wickedly!%^RESET%^",
		"%^BOLD%^%^BLACK%^The beast snaps at you wildly!%^RESET%^",
		"%^BOLD%^%^BLACK%^The shadow hound snarls viciously!",
		"%^BOLD%^%^BLACK%^The beast circles you hungrily!%^RESET%^",
		"%^BOLD%^%^BLACK%^The shadow hound smells your %^RED%^blood%^BLACK%^ and "+
			"salivates uncontrollably!%^RESET%^",
		"%^BOLD%^%^BLACK%^The beast darts in and out looking for an opening.%^RESET%^",
		"%^BOLD%^%^BLACK%^The shadow hound sniffs the air and barks wildly!%^RESET%^",
		"%^BOLD%^%^BLACK%^The beast lunges at your face snapping wildly!%^RESET%^",
		"%^BOLD%^%^BLACK%^The hound tears at your clothing and your armor!%^RESET%^",
		"%^BOLD%^%^BLACK%^The beast licks his canine lips savoring the taste "+
			"of your flesh.%^RESET%^"}), 1);
}
void init(){
::init();
	add_action("sic_em","sic");
	force_me("watch");
	if(TP->query_invis() && !avatarp(TP) && TP->query_level() > 20) {
		tell_object(TP,"%^RED%^The beast howls and then attacks!");
		TO->force_me("kill "+TP->query_name()+"");
	}
	else if(!TP->query_invis() && interactive(TP) && TP->query_level() > 20) {
		tell_object(TP,"%^RED%^The beast howls and then attacks!");
		TO->force_me("kill "+TP->query_name()+"");
	}
	else if(!TP->query_invis() && interactive(TP) && TP->query_level() < 21) {
		tell_object(TP,"The beast sniffs you, snaps his teeth menacingly then "+
			"ignores you.");
	}
}
int sic_em(string str) {
	object ob;
	string target;
    	if(!avatarp(TP)){
    		notify_fail("I don't think so!\n");
    		return 0;
    	}
    	if(!str) {
       	notify_fail("What?\n");
        	return 0;
    	}
    	target = str;
    	ob = find_player(target);
    	if(!ob) {
        	notify_fail("The hound looks around lost and confused!\n");
        	return 0;
    	}
    	if(wizardp(ob)) {
        	notify_fail("The beast looks suddenly very afraid and wimpers pitifully.\n"+
        		"Don't you think that wizard would be pissed if you did that?\n"+
        		"Send it after an avatar instead!\n");
        	return 0;
    	}
     	sicing(ob,0);
    	return 1;
}
void sicing(object tp,int num){
     	switch(num){
      	case(0):tell_object(ETP,"The hound bounds off to do your bidding.\n");
      		tell_room(environment(tp),"%^BOLD%^%^RED%^In the distance you "+
      			"can hear the baying of a hound. \n");
                  break;
            case(1):tell_room(environment(tp),"%^BOLD%^%^RED%^The baying grows louder.\n");
			break;
            case(2):tell_room(environment(tp),"%^BOLD%^%^RED%^The baying grows even "+
            		"louder.  Barking and growling accompany the mournful sound of the "+
            		"hound's wail.\n");
                  break;
            case(3):tell_room(environment(tp),"%^BOLD%^%^RED%^Growling, barking and "+
	      		"howling can be heard from the next room.\n");
                  break;
            case(4):tell_room(environment(tp),"%^BOLD%^%^RED%^A huge dog-like beast "+
            		"composed of the stuff of shadows bounds into the room intent on "+
				"mayhem.\n");
	      	TO->move(environment(tp));
	      	TO->force_me("kill "+tp->query_name()+"");
                	return;
    	}
    	num++;
    	call_out("sicing",0,tp,num);
    	return;
}