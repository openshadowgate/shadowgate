#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("loviatar whip");
	set_id(({ "whip" }));
	set_obvious_short("A cat 'o nine tails whip");
	set_short("Whip of %^BOLD%^%^CYAN%^Frost %^RED%^Fire%^RESET%^ and %^MAGENTA%^Fear%^RESET%^");
	set_long(
@AVATAR
Nine long lean strands of black leather have been attached to a mithril hilt.  The hilt is wrapped in a similar leather that has minute barbs poking out.  The extensions from the whip, on a closer inspection, are imbedded with mithril barbs.  The strands are divided as such, three possessing a %^RED%^red%^RESET%^ hued metal, three with %^BOLD%^%^CYAN%^silvery blue%^RESET%^ barbs, and the final three, %^MAGENTA%^deep violet%^RESET%^.

AVATAR
	);
	set_weight(4);
	set_value(100);
	set_lore(
@AVATAR
These powerful whips have been bestowed upon those that the Mistress of Pain has taken a liking to for their dedication to her teachings.  Many would abhor the idea, but not the followers of Loviatar.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("whip");
	set_size(2);
	set_wc(2,4);
	set_large_wc(2,4);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" smirks cruelly as her fingers wrap around the hilt of the "+query_short()+"",ETO);
	tell_object(ETO,"As your curl your fingers about the hilt of the " +query_short()+", the barbs slice into your flesh giving you a taste of the pain you are about to deal out.");
	ETO->do_damage("torso",random(20));
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),""+ETO->query_cap_name()+" sighs and gets a longing look in her eyes as she slides her fingers from the "+query_short()+"",ETO);
	tell_object(ETO,"You long for the pain again soon after unwrapping your fingers from the "+query_short()+"");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 300){
	  switch(random(3)) {
	   case 0: 
	    	tell_room(environment(query_wielded()),"%^BOLD%^CYAN%^The blue strands glow as they hit "+targ->query_cap_name()+" and freeze the blood they draw.", ({ETO,targ}));
	      tell_object(ETO,"%^BOLD%^CYAN%^The blue strands glow as they hit "+targ->query_cap_name()+" and freeze the blood they draw.");
	      tell_object(targ,"%^BOLD%^CYAN%^The blue strands glow as the barbs cut into you and freeze the blood they draw.");
         targ->do_damage("torso",random(6)+5);
         break;
	   case 1: 
	    	tell_room(environment(query_wielded()),"With a swift crack of her whip, "+ETO->query_cap_name()+" sends a paralyzing shiver of fear down "+targ->query_cap_name()+" 's spine.",({ETO,targ}));
	      tell_object(ETO,"With a swift crack of your whip, you bless "+targ->query_cap_name()+" with the fear of Loviatar's gifts.");
	      tell_object(targ,"With a swift crack of her whip, "+ETO->query_cap_name()+" sends a shiver of paralyzing fear down your spine.");
	      targ->set_paralyzed(roll_dice(1,5)+3);
         break;
	   case 2: 
	    	tell_room(environment(query_wielded()),"%^BOLD%^RED%^The red barbs sizzle as they hit "+targ->query_cap_name()+", searing the wound.", ({ETO,targ}));
	      tell_object(ETO,"%^BOLD%^RED%^The red barbs flash and sizzle as they hit "+targ->query_cap_name()+", searing the wound.");
	      tell_object(targ,"%^BOLD%^RED%^The red barbs flash and sizzle as they cut and then sear the wound.");
         targ->do_damage("torso",random(6)+5);
         break;
       }
      return 0;
      }
}
