#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dark scimitar");
	set_id(({ "scimitar","sword", "dark scimitar" }));
     set_short("Shlefflix's dark scimitar");
	set_obvious_short("Rune covered dark scimitar");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This dark scimitar is heavily covered with %^BOLD%^%^YELLOW%^runes%^BOLD%^%^BLACK%^. The single bladed weapon is wickedly curved, much like eastern assassin daggers. Its blade is thick and heavy. It's covered with %^BOLD%^%^RED%^dark runes %^BOLD%^%^BLACK%^. The runes appear to be set in such a way as to %^BOLD%^%^BLUE%^lacerate %^BOLD%^%^BLACK%^as the blade slides through, making stitching a wound much more difficult. The hilt is lithe and fitted for a delicate hand, it however is longer allowing a larger hand to still fit. The balance at first glance appears to be blade heavy, but it holds well for a ewapon with such a heavily made blade.

AVATAR
	);
	set("read",
@AVATAR
Shlefflix is master. Shlefflix is my master. Shlefflix shall master all by my hand.

AVATAR
	);
     set("langage","str");	set_weight(10);
	set_value(500);
	set_lore(
@AVATAR
This is a heavy drow weapon. The rune obviously appear to be drow. This is meant as a individual warriors weapon. It lacks the subtlty of typical drow weapons. Its as if drow made this weapon to polute the human world.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(2,5);
	set_large_wc(2,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_object(TP,"%^BOLD%^You heft the blade and feel Shlefflix's presence.%^RESET%^");
    TP->add_attack_bonus(1);
	return 1;
}

int unwield_func(){
	tell_object(TP,"%^BOLD%^Shlefflix's presence is lost to you.%^RESET%^");
	TP->add_attack_bonus(-1);
	return 1;
}

int hit_func(object targ) {
   if(!random(5)) {
     switch(random(9)) {
	case 0..5:
	  tell_object(targ, "%^BOLD%^%^BLUE%^The dark scimitar rips into your skin, lacerating deeply and sending waves of %^RED%^pain %^BLUE%^through your body.");
	  tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The dark scimitar rips into "+targ->query_cap_name()+"'s skin, lacerating deeply and making %^RED%^"+targ->query_objective()+" wince from the pain.", targ);
	  targ->do_damage(targ->return_target_limb(),5);
	  break;
	case 6..7:
	   tell_object(targ, "%^BOLD%^%^BLACK%^The scimitar slashes quickly across your chest, cutting deeply before "+ETO->query_cap_name()+" spins to %^RED%^SMASH %^BLACK%^you in the jaw with the hilt of the blade, stunning you.");
	   tell_room(environment(ETO), "%^BOLD%^%^BLACK%^The scimitar slashes quickly across "+targ->query_cap_name()+"'s chest, cutting deeply before "+ETO->query_cap_name()+" spins to %^RED%^stun %^BLACK%^"+targ->query_objective()+" with a hit to the jaw with the hilt.",({targ, ETO}));
	   tell_object(ETO, "%^BOLD%^%^BLACK%^The scimitar slashes quickly across "+targ->query_cap_name()+"'s chest, cutting deeply before you spin to %^RED%^stun %^BLACK%^"+targ->query_objective()+" with a hit to the jaw with the hilt.");
	   targ->set_paralyzed(15,"%^BOLD%^You are recovering from that hit.");
	   break;
	case 8 :
	   tell_object(targ, "%^RED%^"+ETO->query_cap_name()+" slips to the side and thrusts up, flashing the blade in a weaving pattern and cutting you multiple times.");
	   tell_room(environment(ETO), "%^RED%^"+ETO->query_cap_name()+" slips to the side, and thrusts up, flashing the blade in a weaving pattern, cutting "+targ->query_cap_name()+" multiple times.",({targ, ETO}));
	   tell_object(ETO, "You tumble to the side and thrust up, flashing the blade in a weaving pattern, cutting "+targ->query_cap_name()+" multiple times.");
	   ETO->execute_attack();
	   break;
	default:
	   break;
      }
   return 1;
   }
}
