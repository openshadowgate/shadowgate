#include <std.h>
#include <daemons.h>
inherit ARMOUR;

// Hyena created for Tiamat's "The Other White Meat" plot.
// For use during plot and to be awarded as a player item.
// Summons a controlled Hyena mob, apx level 15
// Created in February 2009 by Ari

int tracker, trackerb;

void init(){
	::init();
		add_action("call_hyena","call");
}

void create(){
	::create();
	
	set_name("choker");
	set_id(({"choker","leather strap","collar","leather collar"}));
	set_short("a leather collar");
	set_long("This is a leather collar. It goes around the neck, duh.");
	set_type("clothing");
    set_limbs(({"neck"}));
	set_weight(5);
	set_value(500);
	set_size(2);
	set_ac(1);
	set_property("enchantment",2);
	set_property("death keep",1);
	set_wear((:TO,"wear_me":));
}

int wear_me(){
	if((string)ETO->query_name() != "eversor" && !avatarp(ETO)){
		tell_object(ETO,"Try as you might, the collar just wont "+
			"fit around your neck properly.  It's almost as "+
			"if it's trying to choke you!");
		return 0;
	}
	tell_object(ETO,"You buckle on the collar and remember that "+
		"you can %^YELLOW%^<call hyena>%^RESET%^ to call your "+
		"newest companion.");
	TO->set_overallStatus(100);
	return 1;
}

int call_hyena(string str){
	object ob;
	
	if(!str){
		notify_fail("What were you going to call again?");
		return 0;
	}
	
	if(str != "hyena"){
		notify_fail(""+str+" doesn't appear to be heeding your "+
			"call.");
		return 0;
	}
	
	if(!TO->query_worn()){
		tell_object(TP,"Without the collar about your neck, how "+
			"do you think the calling magic will be activated?");
		return 1;
	}
	
	if(ETO->present("eversorhyena")){
		tell_object(TP,"Your striped companion is already here.");
		return 1;
	}
	
	if(tracker > time()){
		tell_object(TP,"%^RESET%^%^ORANGE%^You brush your hand over "+
			"the collar and give a high pitched calling whistle, but "+
			"receive no answer.  Your hyena must be out of range.");
		return 1;
	}
	
	if(trackerb){
		tracker = time() + 14400;
		trackerb = 0;
	}
	else{ trackerb = 1; }
		
		tell_room(EETO,"%^RESET%^%^ORANGE%^"+TP->QCN+" brushes "+
			""+TP->QP+" fingers over the clasp on "+TP->QP+" collar "+
			"and gives a high pitched whistle.%^RESET%^",TP);
		tell_object(TP,"%^RESET%^%^ORANGE%^You brush your hand over "+
			"the clasp on your collar and give a high pitched whistle.");
		tell_room(EETO,"%^RESET%^%^MAGENTA%^From off in the distance "+
			"a high pitched keening howl answers!%^RESET%^");	
		tell_room(EETO,"%^RESET%^%^ORANGE%^A moment later, a large "+
			"s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^"+
			"i%^WHITE%^p%^BLACK%^e%^RESET%^%^ORANGE%^d hyena lopes "+
			"into view.");
		ob=find_object_or_load("/d/avatars/tiamat/mon/eversor_hyena");
		ob->move(EETO);
	return 1;
}
	