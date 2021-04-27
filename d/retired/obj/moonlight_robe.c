#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("robe of moonlight");
     set_id(({"robe","robe of moonlight","silver robe"}));
     set_short("%^BOLD%^%^WHITE%^Robe of M%^RESET%^o%^BOLD%^o%^RESET%^n%^BOLD%^l%^RESET%^"+ 
       "i%^BOLD%^g%^RESET%^h%^BOLD%^t%^RESET%^");
     set_obvious_short("%^BOLD%^%^WHITE%^A loose fitting silver robe%^RESET%^");
     set_long("%^BOLD%^%^WHITE%^Shimmering like molten %^CYAN%^s%^WHITE%^ilv%^CYAN%^e%^WHITE%^r"+
       ", this loose fitting robe carries an almost %^RESET%^%^MAGENTA%^ethereal%^BOLD%^%^WHITE%^"+
       " quality to it.  The soft milky white cloth of the robe is cut full, giving little "+
       "shape to the garment. The rounded scoop collar of the robe bears an uncanny "+
       "resemblance to a %^CYAN%^crescent moon%^BOLD%^%^WHITE%^.  The thin cloth of "+
       "the robe flows in gentle folds and pleats as it pools on the floor.  A belt of"+
       " %^RESET%^silver%^BOLD%^ chains with moonstone charms serves as the only way"+
       " to secure this ethereal robe to one's body.  The moonstone charms cycle through"+
       " the phases of the %^YELLOW%^moon%^WHITE%^, each one made with a delicate precision. %^RESET%^\n");
      set_value(1500);
	set_lore("The Robe of Moonlight was crafted by an human sorceress devoted "+
		"to Selune by the name of Moiraine. Moriane was one of those rare "+
		"types of wizards who didnt lock herself away in a tower - instead "+
		"she travelled from village to village looking for how she could "+
		"help others.  Noted for the cool seriene nature, Moriaine was "+
		"trusted by many rules and common folk alike.  One of her greatest"+
		" mages that she clashed over was a Sharran who like to infest "+
		"herself in others dreams.");
	set_property("lore difficulty",16);
	set_ac(0);
      set_type("clothing");
      set_limbs(({"torso"}));
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
   if(userp(ETO) && !avatarp(ETO)) { // copy just for NPC Kiya to wear!
      tell_object(ETO,"The magic within these robes "+
         "prevents you from wearing them.");
      return 0;
   }
if((string)ETO->query_diety() == "selune") {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^Sliding into"+
			" the milky white robe, you feel a soothing serenity.");
      	tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
      		" slides into "+ETO->QP+" milky white robe, the "+
                  "moonstone charms around "+ETO->QP+" waist glow softly.",ETO);
      return 1;
   	}else{
		tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips in"+
			" a milky white robe.",ETO);
		tell_object(ETO,"%^BOLD%^You slip on the milky white"+
			" robe, you can almost a calm serenity wash over you.%^RESET%^");
	return 1;
	}
}
int remove_func(){
	if((string)ETO->query_diety() == "selune") {
      	tell_object(ETO,"%^BOLD%^%^WHITE%^Sliding out of"+
			" the milky white robe, the soothing serenity fades away gently.");
      	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->QCN+""+
      		" slides out of "+ETO->QP+" milky white robe, the "+
			"moonstone charms around "+ETO->QP+" waist cease to glow.",ETO);
	return 1;
	}
	else{
		tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips "+
			"out of the milky white robe.",ETO);
		tell_object(ETO,"%^BOLD%^You slip out of the milky white robe.");
	return 1;
	}
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 125){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^Motes of silver"+
	" light flash around "+ETOQCN+"'s robe, jolting  "+
         ""+who->QCN+" in the process.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Motes of silver light rise off the robe"+
         " in your defense, jolting "+who->QCN+".");
	tell_object(who,"%^BOLD%^%^WHITE%^Motes of silver light rise off of"+
        " "+ETOQCN+"'s robe, slamming into you with a jolt.");
			who->do_damage("torso",random(4)+6);
	}
}

