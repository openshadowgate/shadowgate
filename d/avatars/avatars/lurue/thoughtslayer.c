#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

// Thought Slayer Mob - Created in February 2009 by Ari
// Use & Intent: Mob for Soul Food Plot (Shadow Attacked)

create(){
	::create();
		set_name("aberration");
		set_id(({"aberration","thought slayer","mind eater",
			"creature","thoughtslayer"}));
		set_short("%^BOLD%^%^BLACK%^a %^RESET%^s%^BOLD%^%^WHITE%^h"+
			"%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w"+
			"%^BOLD%^%^WHITE%^y %^BLACK%^aberration%^RESET%^");
		set_long("%^BOLD%^%^BLACK%^This monsterous creature stands as "+
			"tall as a house and has the bone structure of a "+
			"ridden mount, though you can't imagine anyone ever "+
			"riding such a horrific thing.  Looking%^RESET%^ "+
			"skeletal%^BOLD%^%^BLACK%^, the beast has tattered "+
			"ephemeral skin that seems to constantly drift on an "+
			"unfelt breeze.  At times, patches of the skin seem "+
			"almost solid with a %^RESET%^dull gray sheen%^BOLD%^"+
			"%^BLACK%^, at other times, it is as though this "+
			"creature is nothing but a skeleton.  The aberration's "+
			"%^YELLOW%^yellow eyes %^BLACK%^blaze with a keen "+
			"intelligence, though there is a savage hunger within "+
			"them as well.  Its long snout terminates in a "+
			"razor sharp curve, not unlike a bird of prey's.  "+
			"Hovering a few inches above the ground, it moves "+
			"silently despite its size.%^RESET%^");
		
		set_stats("strength",16);
		set_stats("intelligence",25);
		set_stats("wisdom",16);
		set_stats("dexterity",22);
		set_stats("constitution",10);
		set_stats("charisma",10);
		
		set_race("aberration");
		set_body_type("quadruped");
		set_gender("neuter");
		set_alignment("8");
		set_size(3);
		set_exp(15000);
		set_class("fighter");
		set_mlevel("fighter",25);
		set_hd(random(200)+500);
		set_overall_ac(-16);
		
		add_limb("mouth","head",0,0,0);
		add_limb("right forepaw","right foreleg",0,0,0);
		add_limb("left forepaw","left foreleg",0,0,0);
		set_attack_limbs(({"mouth","right forepaw","left forepaw"}));
		set_base_damage_type("bludgeoning");
		set_damage(4,6);
		
		set_mob_magic_resistance("average");
		set_property("no animate",1);
		set_property("no death",1);
		set_property("no steal",1);
		set_property("no dominate",1);
		
		set_funcs(({"consuming_gaze","psionic_blast","mind_wave",
			"rearing_strike","soul_bite"}));
		set_func_chance(25);
}

int consuming_gaze(object target){
	tell_object(target,"%^BOLD%^%^BLACK%^The %^RESET%^s%^BOLD%^"+
		"%^WHITE%^h%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w"+
		"%^BOLD%^%^WHITE%^y %^BLACK%^aberration gazes upon you and "+
		"you feel your body slipping away!%^RESET%^");
	tell_room(ETO,"%^BOLD%^%^BLACK%^"+target->QCN+" begins to "+
		"tremble as they meet the creature's gaze!",target);
	target->do_damage("torso",roll_dice(3,6));	
	target->set_paralyzed(12,"%^BOLD%^%^BLACK%^"+
			"You can't tear your eyes away from the creature's "+
			"gaze!%^RESET%^");
}

int psionic_blast(object target){
	tell_object(target,"%^RESET%^%^MAGENTA%^Pain %^RED%^s%^BOLD%^u"+
		"%^RESET%^%^MAGENTA%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^es "+
		"%^MAGENTA%^through your mind!%^RESET%^");
	tell_room(ETO,"%^RESET%^%^MAGENTA%^"+target->QCN+" screams in "+
		"pain!%^RESET%^",target);
	target->do_damage("torso",roll_dice(4,6));
}

int rearing_strike(object target){
	string dir;
		switch(random(8)){
			case 0: dir = "northeast"; break;
			case 1: dir = "east"; break;
			case 2: dir = "southeast"; break;
			case 3: dir = "south"; break;
			case 4: dir = "southwest"; break;
			case 5: dir = "west"; break;
			case 6: dir = "northwest"; break;
			case 7: dir = "north"; break;
		}
	tell_object(target,"%^YELLOW%^The %^RESET%^s%^BOLD%^%^WHITE%^"+
		"h%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w%^BOLD%^"+
		"%^WHITE%^y %^BLACK%^aberration%^YELLOW%^ rears and kicks "+
		"you with its rear hooves, sending you tumbling "+
		"backwards!%^RESET%^");
	tell_room(ETO,"%^YELLOW%^"+target->QCN+" is sent "+
		"flying!%^RESET%^",target);
	target->do_damage("torso",random(20)+20);
	target->force_me(dir);
	}


int soul_bite(object target){
	tell_object(target,"%^RESET%^%^RED%^The %^RESET%^s%^BOLD%^"+
		"%^WHITE%^h%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o"+
		"%^RESET%^w%^BOLD%^%^WHITE%^y %^BLACK%^aberration "+
		"%^RESET%^%^RED%^snaps down tearing a piece of your "+
		"%^BOLD%^%^WHITE%^soul %^RESET%^%^RED%^away!%^RESET%^");
	tell_room(ETO,"%^RESET%^%^RED%^The %^RESET%^s%^BOLD%^%^WHITE%^"+
		"h%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w%^BOLD%^"+
		"%^WHITE%^y %^BLACK%^aberration %^RESET%^%^RED%^snaps "+
		"down tearing a piece of "+target->QCN+"'s %^BOLD%^"+
		"%^WHITE%^soul %^RESET%^%^RED%^away!%^RESET%^",target);
	tell_room(ETO,"%^RESET%^%^RED%^"+target->QCN+" screams in "+
		"pain!%^RESET%^",target);
	target->do_damage("torso",random(10)+20);
}

void mind_wave(object target){
	object *pplz;
	int i,freeze;
	pplz = all_living(ETO);
	TO->set_property("magic",1);
		tell_room(ETO,"%^BOLD%^%^BLACK%^A wave of pure %^CYAN%^me"+
			"%^RESET%^%^CYAN%^nt%^BLUE%^al en%^CYAN%^er%^BOLD%^gy "+
			"%^BLACK%^pulses outward from the %^RESET%^s%^BOLD%^"+
			"%^WHITE%^h%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o"+
			"%^RESET%^w%^BOLD%^%^WHITE%^y %^BLACK%^aberration"+
			".%^RESET%^");
		tell_room(ETO,"%^BOLD%^%^RED%^Pain%^BLACK%^ courses through "+
			"every nerve in your body!%^RESET%^");
	if(!sizeof(pplz)) return;
	for(i=0;i<sizeof(pplz);i++){
		if(avatarp(pplz[i])) continue;
		if(pplz[i]->id("thoughtslayer")) continue;
		pplz[i]->set_paralyzed((random(6)+12),"%^BOLD%^%^BLACK%^"+
			"You are recovering from the mental blast!%^RESET%^");
		target->do_damage("torso",random(10)+10);
	}
}

void heart_beat(){
	::heart_beat();
		if(!objectp(TO)) return;
		if(!objectp(ETO)) return;
		if(query_attackers() != ({}))
			add_hp(random(20)+30);
		else set_hp(query_max_hp());
}