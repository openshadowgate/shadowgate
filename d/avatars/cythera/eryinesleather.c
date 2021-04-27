// updated con and cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;
string OWNER;
int FLAG;

void init() {
 	::init();
    	if(interactive(ETO) && ETO==environment(TO) && !OWNER) OWNER = ETOQN;
}

void create(){
	::create();
	set_name("black leather bodice");
	set_id(({"leather bodice","leather","bodice","armor","black bodice","black leather bodice","bodice of the eryines" }));
	set_short("%^BOLD%^%^BLACK%^The Bodice of the %^RESET%^%^CYAN%^"+
		"E%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^n"+
		"%^RESET%^%^CYAN%^y%^MAGENTA%^e%^BOLD%^%^BLACK%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black leather bodice%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Soft black leather is used in the"+
		" creation of this bodice.  The leather pieces are"+
		" joined together in smaller sections, allowing it to have"+
		" a closer fit.  Though the leather is soft, it seems as if"+
		" it might protect, somewhat.  The sleeveless fullbodice "+
		"covers the wearer's torso fully.  The sleeveless armholes are"+
		" trimmed with black plumes, the feathers in a variety of "+
		"sizes and lengths. Strips of%^RESET%^%^CYAN%^"+
		" metal boning%^BOLD%^%^BLACK%^ are housed within casing, "+
		"inside the bodice.  This gives the bodice its rigid shape,"+
		" and probably offers some additional protection.  Miniature"+
		" %^RESET%^%^CYAN%^steel hooks%^BOLD%^%^BLACK%^ and"+
		" %^RESET%^%^CYAN%^eyes%^BOLD%^%^BLACK%^ down the front of "+
		"the bodice serve to close the armor off without "+
		"sacrificing its look. A high collar covers the neck tightly. "+
		"This leather, while unusual, does retain a sense of style.%^RESET%^\n");
	set_weight(10);
	set_value(1900);
	set_lore("Similar to the Succubus, the Eryines is a devil that"+
		" takes the form usually of a female human or elf."+
		"  Unlike the Succubus, the Eryines has long feathered wings "+
		"that aid her in flight, not bat wings.  The Succubus seems"+
		" to prey on more carnal desires than an Eryines, which adds"+
		" to their infamy.  An Eryines is just as deadly as any"+
		" other devil, some might say even more so because of the"+
		" unassuming forms they take. -The Ecology of Devil -"+
		" Orim Zal'Rashad");
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set("chabonus",1);
      set("conbonus",-1);
}
int wear_func(){
        if((int)ETO->query_highest_level() < 14) {
   		notify_fail("You can't seem to lace the bodice up.");
   	return 0;
	}
	if((string)ETO->query_gender() == "male") {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^How do women manage to get"+
			" these things on!?!");
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
      		" scowls at the numerous hooks on the bodice, giving up with"+
			" a frustrated sigh.",ETO);
		return 0;
	}
	if(interactive(ETO) && (string)ETO->query_name() != OWNER){
		tell_object(ETO,"%^RESET%^%^MAGENTA%^The armor rejects you forcefully!");
    			set_property("magic",1);
    			ETO->do_damage("torso",random(40));
    			set_property("magic",-1);
		return 0;
	}
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
		" %^BOLD%^%^BLACK%^wraps the leather bodice around"+
		" her, tugging on it as she fastens it closed.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You exhale deeply and"+
		" tug on the leather bodice, fastening it closed about you.");
			ETO->add_attack_bonus(-1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
		" gasps for air after tearing off her leather bodice.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You gap for air as you"+
		" are finally free from that damn thing");
			ETO->add_attack_bonus(1);
	return 1;
}
