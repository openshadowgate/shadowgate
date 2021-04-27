#include <std.h>
inherit WEAPONLESS;

// Hyena created for Tiamat's "The Other White Meat" plot.
// For use during plot and to be awarded as a player item.
// Created in February 2009 by Ari

string location;

void init(){
	::init();
		add_action("pose_me","hyenapose");
		add_action("tell_me","hyenakill");
		add_action("lead_me","hyenalead");
		add_action("unlead_me","hyenaunlead");
		add_action("protect_me","hyenaprotect");
		add_action("unprotect_me","hyenaunprotect");
		add_action("dismiss_me","hyenadismiss");
}

void create(){
	::create();
		set_name("hyena");
		set_id(({"hyena","striped hyena","eversorhyena"}));
		
		set_short("%^RESET%^%^ORANGE%^vicious s%^BOLD%^%^BLACK%^"+
			"t%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^p"+
			"%^BLACK%^e%^RESET%^%^ORANGE%^d hyena%^RESET%^");
		set_long((:TO,"long_desc":));
	
		set_gender("female");
		set_race("hyena");
			set_body_type("quadruped");
	
		set_alignment(6);
		set_hd(15,6);
			set_hp(random(20)+100);
		set_size(1);
			set_class("fighter");
			set_level(15);
			set_mlevel("fighter",15);
		set_exp(1200);
		set_overall_ac(0);

		set_stats("strength",18);
		set_stats("dexterity",18);
		set_stats("constitution",18);
		set_stats("intelligence",18);
		set_stats("wisdom",18);
		set_stats("charisma",18);
		
		add_limb("right claw","right forepaw",0,0,0);
		add_limb("left claw","left forepaw",0,0,0);
		add_limb("mouth","head",0,0,0);
			set_damage(1,6);
			set_attacks_num(2);
			set_base_damage_type("slashing");
				set_attack_limbs(({"right claw","left claw",
					"mouth"}));
			remove_property("swarm");
		
		set_funcs(({"bite_them","rend_them"}));
			set_func_chance(20);
			
	set_emotes(2,({
		"%^RESET%^%^ORANGE%^The vicious s%^BOLD%^%^BLACK%^t"+
			"%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^"+
			"p%^BLACK%^e%^RESET%^%^ORANGE%^d hyena paces "+
			"around, snapping and growling.%^RESET%^",
		"%^RESET%^%^ORANGE%^The vicious s%^BOLD%^%^BLACK%^t"+
			"%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^"+
			"p%^BLACK%^e%^RESET%^%^ORANGE%^d hyena lifts her "+
			"snout into the air, yipping with a harsh "+
			"laughter like sound.%^RESET%^",
		"%^RESET%^%^ORANGE%^The vicious s%^BOLD%^%^BLACK%^t"+
			"%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^p"+
			"%^BLACK%^e%^RESET%^%^ORANGE%^d hyena growls low "+
			"in her throat, showing her sharp teeth.%^RESET%^",
		"%^RESET%^%^ORANGE%^The vicious s%^BOLD%^%^BLACK%^t"+
			"%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^p"+
			"%^BLACK%^e%^RESET%^%^ORANGE%^d hyena paces around "+
			"the area, her body tense.%^RESET%^",
	}),0);
}

string long_desc(){
	if((string)TP->query_name() == "eversor" || avatarp(TP)){
		return("%^RESET%^%^ORANGE%^You are facing a nasty "+
			"looking hyena. Though almost dog-like, the beast "+
			"is too wiry and angular to be mistaken for a "+
			"common animal. It has long forelimbs and a strange "+
			"gait as it stalks or runs. The hyena wears a coat "+
			"of coarse fur with an irregular s%^BOLD%^%^BLACK%^"+
			"t%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^p"+
			"%^BLACK%^e%^RESET%^%^ORANGE%^d pattern. Its pointy "+
			"ears and long guard hairs give it a primitive, "+
			"dangerous appearance. As the creature utters its "+
			"eerie, chattering howl, you notice sharp front "+
			"teeth as well as powerful crushing jaws.%^RESET%^\n\n"+
			"%^BOLD%^%^WHITE%^Your commands are: %^YELLOW%^"+
			"hyenakill%^WHITE%^, %^YELLOW%^hyenapose%^WHITE%^, "+
			"%^YELLOW%^hyenalead%^WHITE%^, %^YELLOW%^hyenaunlead"+
			"%^WHITE%^, %^YELLOW%^hyenaprotect%^WHITE%^, %^YELLOW%^"+
			"hyenaunprotect%^WHITE%^ and %^YELLOW%^hyenadismiss"+
			"%^WHITE%^.%^RESET%^");
		}
			
		return("%^RESET%^%^ORANGE%^You are facing a nasty "+
			"looking hyena. Though almost dog-like, the beast "+
			"is too wiry and angular to be mistaken for a "+
			"common animal. It has long forelimbs and a strange "+
			"gait as it stalks or runs. The hyena wears a coat "+
			"of coarse fur with an irregular s%^BOLD%^%^BLACK%^"+
			"t%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i%^WHITE%^p"+
			"%^BLACK%^e%^RESET%^%^ORANGE%^d pattern. Its pointy "+
			"ears and long guard hairs give it a primitive, "+
			"dangerous appearance. As the creature utters its "+
			"eerie, chattering howl, you notice sharp front "+
			"teeth as well as powerful crushing jaws.%^RESET%^");		
}

int bite_them(object target){
		tell_object(target,"%^BOLD%^%^BLACK%^The hyena flashes her "+
			"sharp %^WHITE%^teeth%^BLACK%^ before ripping a chunk "+
			"out of your skin!%^RESET%^");
		tell_room(ETO,"%^BOLD%^%^BLACK%^The hyena flashes her sharp "+
			"%^WHITE%^teeth%^BLACK%^ before ripping a chunk out "+
			"of "+target->QCN+" skin!%^RESET%^",target);
			target->do_damage("torso",random(5)+10);
}

int rend_them(object target){
		tell_object(target,"%^BOLD%^%^RED%^The hyena swipes first "+
			"one and then the other claw across your exposed flank!"+
			"%^RESET%^");
		tell_room(ETO,"%^BOLD%^%^RED%^The hyena swipes first one "+
			"and then the other claw across "+target->QCN+" exposed "+
			"flank!%^RESET%^",target);
			target->do_damage("torso",random(4)+5);
			target->do_damage("torso",random(4)+5);
}

int tell_me(string str){
	if(!str){
		notify_fail("emote looks confused as to what you want "+
			"her to do.");
		return 0;
	}
	if((string)TP->query_name() != "eversor" && !avatarp(TP)){
		force_me("emote doesn't appear to care for your "+
			"commands.");
		force_me("growl");
		return 1;
	}
	force_me("kill "+str+"");
	return 1;
}

int protect_me(string str){
	if(!str){
		notify_fail("emote looks confused as to what you want "+
			"her to do.");
		return 0;
	}
	if((string)TP->query_name() != "eversor" && !avatarp(TP)){
		force_me("emote doesn't appear to care for your "+
			"commands.");
		force_me("growl");
		return 1;
	}
	force_me("protect "+str+"");
	return 1;
}

int unprotect_me(string str){
	if(!str){
		notify_fail("emote looks confused as to what you want "+
			"her to do.");
		return 0;
	}
	if((string)TP->query_name() != "eversor" && !avatarp(TP)){
		force_me("emote doesn't appear to care for your "+
			"commands.");
		force_me("growl");
		return 1;
	}
	force_me("unprotect "+str+"");
	return 1;
}
		
int pose_me(string str){
	if(!str){
		notify_fail("emote looks confused as to what you want "+
			"her to do.");
		return 0;
	}
	if((string)TP->query_name() != "eversor" && !avatarp(TP)){
		force_me("emote doesn't appear to care for your "+
			"commands.");
		force_me("growl");
		return 1;
	}
	force_me("pose "+str+"");
	return 1;
}

int lead_me(string str){
	if(!str){ 
		notify_fail("What are you going to lead?"); 
		return 0;
	}
	if(str != "hyena"){
		notify_fail(""+str+" doesn't respond to your command.");
		return 0;
	}
	if((string)TP->query_name() != "eversor" && !avatarp(TP)){
		force_me("emote ignores "+TPQCN+".");
		return 1;
	}
	TP->add_follower(TO);
		tell_object(TP,query_cap_name()+" is now following you.");
		return 1;
}

int unlead_me(string str){
	if(!str){
		notify_fail("That doesn't appear to be following you.");
		return 0;
	}
	if(str != "hyena"){
		notify_fail("That's not following you, how can you "+
			"unlead it?");
		return 0;
	}
	if(member_array(TO,TP->query_followers()) == -1)
		return notify_fail(""+TO->QCN+" is not following you now.");
		TP->remove_follower(TO);
		tell_object(TP,"You motion to "+TO->QCN+" and she relaxes "+
			"her guard.  "+TO->QCN+" will no longer follow you.");
		tell_room(ETP,TPQCN+" motions to "+TO->QCN+" who seems to "+
			"understand the command and relaxes her watch.",TP);
		return 1;
}

int dismiss_me(string str){
	object *inven;
	inven = all_inventory(TO);
		if(!str){
			notify_fail("Dismiss what?");
			return 0;
		}
		if(str != "hyena"){
			notify_fail("Nothing runs off, maybe you should be "+
				"more selective with what you're commanding.");
			return 0;
		}
		if((string)TP->query_name() != "eversor" && !avatarp(TP)){
			force_me("emote growls and stays where she is.");
			return 1;
		}
		if(sizeof(inven) > 0){
			tell_room(ETO,"%^RESET%^%^ORANGE%^The hyena gently "+
				"sets her prize down before her master's "+
				"feet, then looks up for "+TPQCN+"'s next "+
				"command.%^RESET%^");
			TO->force_me("drop "+inven[0]->query_name());
		}
		tell_object(TP,"%^RESET%^%^ORANGE%^With a series of "+
			"quick, high pitched whistles, you send the hyena "+
			"bounding off into the brush.%^RESET%^");
		tell_room(ETO,"%^RESET%^%^ORANGE%^"+TPQCN+" gives a quick "+
			"series of high pitched whistles.%^RESET%^",TP);
		tell_room(ETO,"%^RESET%^%^ORANGE%^The large hyena seems "+
			"to understand and goes bounding off into the "+
			"nearby brush. Vanishing from sight.%^RESET%^",TP);
		TO->remove();
		return 1;
}

void receive_given_item(object obj){
	object *inven;
	inven = all_inventory(TO);
	if (sizeof(inven) > 1) {
		tell_object(TP,"The hyena can't seem to carry more than "+
			"one item at a time... It tries to keep hold of both "+
			"items, but drops one.");
     TO->force_me("drop "+inven[random(2)]->query_name());
     return;
   }
}

void die(object ob){
	tell_room(ETO,"%^RESET%^%^ORANGE%^The hyena yelps and "+
		"escapes into the nearest cover!%^RESET%^");
	TO->remove();
}