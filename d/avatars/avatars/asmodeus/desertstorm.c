#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

// Desert Storm Falchion - Jan 2012
// Designed by Asmodeous, Coded by Ari 


void create(){
  ::create();
  set_name("a graceful falchion");
  set_id(({"falchion","desert storm","storm"}));
  set_short("%^RESET%^%^ORANGE%^D%^YELLOW%^e%^RESET%^%^ORANGE%^s"+
    "%^YELLOW%^e%^RESET%^%^ORANGE%^r%^YELLOW%^t %^BOLD%^%^BLACK%^S"+
	"t%^YELLOW%^o%^BLACK%^%^CYAN%^r%^BLACK%^m");
  set_obvious_short("%^BOLD%^%^WHITE%^G%^YELLOW%^r%^BOLD%^%^WHITE%^e"+
    "%^YELLOW%^a%^BOLD%^%^WHITE%^t %^RED%^W%^RESET%^%^RED%^ar "+
	"%^BOLD%^%^BLACK%^F%^CYAN%^a%^BLACK%^lch%^CYAN%^io%^BLACK%^n");
  set_long("%^BOLD%^%^WHITE%^This great %^RED%^falchion%^WHITE%^ is "+
    "a larger version of the %^RESET%^%^CYAN%^Tsarven %^CYAN%^war "+
	"%^RED%^falchion%^WHITE%^. The slender and graceful %^RESET%^"+
	"%^RED%^f%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^v%^BOLD%^%^BLACK%^e"+
	"%^RESET%^%^RED%^r %^BOLD%^%^BLACK%^i%^RESET%^%^RED%^r"+
	"%^BOLD%^%^BLACK%^on%^WHITE%^ blade is close to seven feet long, "+
	"and the %^BOLD%^%^BLACK%^blade%^WHITE%^ curves from a "+
	"%^RESET%^%^CYAN%^slender%^BOLD%^%^WHITE%^ blade at the "+
	"%^RESET%^%^WHITE%^hilt%^BOLD%^ to a %^YELLOW%^broader%^WHITE%^ "+
	"blade near the %^BOLD%^%^BLACK%^tip%^WHITE%^. The blade looks "+
	"%^BOLD%^%^BLACK%^r%^GREEN%^a%^BLACK%^z%^GREEN%^o%^BLACK%^r"+
	"%^WHITE%^ sharp on one side, and %^ORANGE%^blunt%^WHITE%^ on "+
	"the other. %^RESET%^%^CYAN%^Tsarven %^BOLD%^%^CYAN%^w%^WHITE%^"+
	"r%^BOLD%^%^CYAN%^i%^WHITE%^t%^BOLD%^%^CYAN%^i%^WHITE%^n"+
	"%^BOLD%^%^CYAN%^g%^WHITE%^s are %^RESET%^%^MAGENTA%^etched"+
	"%^BOLD%^%^WHITE%^ into the length of the blade, and the "+
	"%^BOLD%^%^CYAN%^letters%^WHITE%^ almost seems to %^BLACK%^s"+
	"%^WHITE%^h%^RESET%^i%^BOLD%^%^BLACK%^m%^WHITE%^m%^RESET%^e"+
	"%^BOLD%^%^BLACK%^r%^WHITE%^ with the %^YELLOW%^warmth%^WHITE%^ "+
	"of the %^RESET%^%^ORANGE%^desert%^BOLD%^%^WHITE%^. The hilt is "+
	"made of %^RESET%^i%^YELLOW%^v%^RESET%^%^WHITE%^ory"+
	"%^BOLD%^%^WHITE%^ and images of %^YELLOW%^falcons%^WHITE%^ "+
	"and %^RED%^hawks%^WHITE%^ in flight are %^RESET%^%^CYAN%^"+
	"artistically%^BOLD%^%^WHITE%^ designed with %^YELLOW%^g%^RESET%^"+
	"%^ORANGE%^o%^YELLOW%^l%^ORANGE%^d%^YELLOW%^e%^ORANGE%^n%^WHITE%^ "+
	"inl%^CYAN%^a%^WHITE%^ys and %^BLUE%^pr%^RED%^ec%^YELLOW%^io"+
	"%^GREEN%^us %^CYAN%^gemstones.");
	
  set_lore("%^BOLD%^%^WHITE%^This great falchion is said to have "+
    "been made for a grand dervish warrior of anhur 1000 years ago. "+
	"The derrvish was a half-djiin who fought for the Falcon of War "+
	"in many great battles. With this sword he fought and defeated "+
	"an ancient and powerful Storm Elemental who had been conjured "+
	"up by Talos himself to weaken Anhurs power in the realm. It is "+
	"said only a true believer can wield this weapon and can "+
	"channel the powers of Anhur.");
  set_property("lore difficulty", 15);
  
  set_value(6300);
  set_property("enchantment",4);
    
  set_wield((:TO,"wieldme":));
  set_unwield((:TO,"removeme":));
  set_hit((:TO,"hit_function":));
}

int wieldme(){
    tell_room(environment(ETO),"%^BOLD%^%^WHITE%^A %^BOLD%^%^BLACK%^c%^BLUE%^r"+
      "%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l"+
	  "%^BOLD%^%^BLACK%^e %^WHITE%^of %^BLUE%^l%^YELLOW%^i%^BLUE%^"+
	  "ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ surrounds "+
	  ""+ETO->QCN+"'s hand as he "+
	  "wields the %^CYAN%^g%^YELLOW%^r%^CYAN%^a%^YELLOW%^c%^CYAN%^e"+
	  "%^YELLOW%^f%^CYAN%^u%^YELLOW%^l%^WHITE%^ falchion.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^A "+
	  "%^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^"+
	  "a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l"+
	  "%^BOLD%^%^BLACK%^e %^WHITE%^of %^BLUE%^l%^YELLOW%^"+
	  "i%^BLUE%^ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ "+
	  "surrounds your hand as you wield the "+
	  "%^CYAN%^g%^YELLOW%^r%^CYAN%^a%^YELLOW%^c%^CYAN%^e"+
	  "%^YELLOW%^f%^CYAN%^u%^YELLOW%^l%^WHITE%^ falchion.");
    
	return 1;
}

int removeme(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The falchion %^BOLD%^%^BLACK%^"+
      "c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^"+
	  "l%^BOLD%^%^BLACK%^e %^WHITE%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^"+
	  "ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ as the hilt is removed "+
	  "from "+ETO->QCN+"'s hand.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The falchion %^BOLD%^%^BLACK%^"+
      "c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^"+
	  "l%^BOLD%^%^BLACK%^es %^WHITE%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^"+
	  "ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ as the hilt is removed "+
	  "from your hand.");
	
	return 1;
}

int hit_function(object targ){
  if(random(1000) < 200){
    switch(random(10)){
	  case 0..6:
	  tell_room(environment(ETO),"%^BOLD%^"+
	    "%^WHITE%^"+ETO->query_cap_name()+" brings the "+
		"%^BOLD%^%^BLACK%^F%^CYAN%^a%^BLACK%^lch%^CYAN%^io"+
		"%^BLACK%^n%^WHITE down in a %^CYAN%^g%^YELLOW%^r"+
		"%^CYAN%^a%^YELLOW%^c%^CYAN%^e%^YELLOW%^f%^CYAN%^u"+
		"%^YELLOW%^l%^WHITE%^ %^YELLOW%^arc%^WHITE%^ drawing "+
		"%^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d %^WHITE%^"+
		"from "+targ->query_cap_name()+" causing the %^BOLD%^"+
		"%^CYAN%^w%^WHITE%^r%^BOLD%^%^CYAN%^i%^WHITE%^t%^BOLD%^"+
		"%^CYAN%^i%^WHITE%^n%^BOLD%^%^CYAN%^g%^WHITE%^s on the "+
		"blade to begin to %^YELLOW%^glow%^WHITE%^ with a "+
		"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^"+
		"%^ORANGE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n "+
		"light.%^RESET%^",({targ,ETO}));
	  tell_object(ETO,"%^WHITE%^%^BOLD%^As you bring the %^BOLD%^%^BLACK%^"+
	    "F%^CYAN%^a%^BLACK%^lch%^CYAN%^io%^BLACK%^n%^WHITE%^ down in "+
		"a %^CYAN%^g%^YELLOW%^r%^CYAN%^a%^YELLOW%^c%^CYAN%^e"+
		"%^YELLOW%^f%^CYAN%^u%^YELLOW%^l%^WHITE%^ %^YELLOW%^arc,"+
		"%^WHITE%^ drawing %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^"+
		"d %^WHITE%^from "+targ->query_cap_name()+", the "+
		"%^BOLD%^%^CYAN%^w%^WHITE%^r%^BOLD%^%^CYAN%^i%^WHITE%^t"+
		"%^BOLD%^%^CYAN%^i%^WHITE%^n%^BOLD%^%^CYAN%^g%^WHITE%^s on "+
		"the blade begin to %^YELLOW%^glow%^WHITE%^ with a "+
		"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^"+
		"d%^YELLOW%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^ light "+
		"and the power of %^RED%^Anhur%^WHITE%^ adds a bit of "+
		"strength to you.",);
	  tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" "+
	    "sweeps the%^BOLD%^%^BLACK%^ F%^CYAN%^a%^BLACK%^lch%^CYAN%^io"+
		"%^BLACK%^n%^BOLD%^%^WHITE%^ down in a %^CYAN%^g%^YELLOW%^r%^CYAN%^"+
		"a%^YELLOW%^c%^CYAN%^e%^YELLOW%^f%^CYAN%^u%^YELLOW%^l%^WHITE%^ "+
		"%^YELLOW%^arc%^WHITE%^.  As he strikes "+
		""+targ->query_cap_name()+", "+
		"the %^BOLD%^%^CYAN%^w%^WHITE%^r%^BOLD%^%^CYAN%^i%^WHITE%^t"+
		"%^BOLD%^%^CYAN%^i%^WHITE%^n%^BOLD%^%^CYAN%^g%^WHITE%^s on "+
		"the blade begin to %^YELLOW%^glow%^WHITE%^ with a %^YELLOW%^"+
		"g%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d"+
		"%^YELLOW%^e%^RESET%^%^ORANGE%^n light.%^RESET%^");
	        set_property("magic", 1);
	        ETO->do_damage("torso",-25);
	        remove_property("magic");
	  break;
	  
	  case 7..9:
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^BOLD%^"+
	    "%^CYAN%^w%^WHITE%^r%^BOLD%^%^CYAN%^i%^WHITE%^t%^BOLD%^%^CYAN%^"+
		"i%^WHITE%^n%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^ "+
		"on "+ETO->query_cap_name()+"'s %^BOLD%^%^BLACK%^F%^CYAN%^a"+
		"%^BLACK%^lch%^CYAN%^io%^BLACK%^n%^BOLD%^%^BLACK%^ begin "+
		"to %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c"+
		"%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e "+
		"%^BOLD%^%^BLACK%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn"+
		"%^YELLOW%^i%^BLUE%^ng%^BOLD%^%^BLACK%^ and a loud "+
		"%^BOLD%^%^BLACK%^th%^CYAN%^u%^BLACK%^ndercl%^YELLOW%^a"+
		"%^BLACK%^p stuns "+targ->query_cap_name()+" as"+
		" "+ETO->query_cap_name()+" slams the flat of the blade "+
		"into "+targ->query_cap_name()+"'s face.%^RESET%^", ({targ,ETO}));
	  tell_object(ETO,"%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^w"+
	    "%^WHITE%^r%^BOLD%^%^CYAN%^i%^WHITE%^t%^BOLD%^%^CYAN%^i"+
		"%^WHITE%^n%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^ "+
		"on "+ETO->query_cap_name()+" %^BOLD%^%^BLACK%^F%^CYAN%^"+
		"a%^BLACK%^lch%^CYAN%^io%^BLACK%^n%^BOLD%^%^BLACK%^ begin "+
		"to %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^"+
		"c%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e %^BOLD%^"+
		"%^BLACK%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn%^YELLOW%^"+
		"i%^BLUE%^ng%^BOLD%^%^BLACK%^ and a loud t%^BOLD%^%^BLACK%^"+
		"th%^CYAN%^u%^BLACK%^ndercl%^YELLOW%^a%^BLACK%^p "+
		"stuns "+targ->query_cap_name()+" "+
		"as "+ETO->query_cap_name()+" slam the flat of the blade "+
		"into "+targ->query_cap_name()+"'s face.%^RESET%^");
	  tell_object(targ,"%^BOLD%^%^BLACK%^The %^BOLD%^%^CYAN%^w"+
	    "%^WHITE%^r%^BOLD%^%^CYAN%^i%^WHITE%^t%^BOLD%^%^CYAN%^"+
		"i%^WHITE%^n%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^ "+
		"on "+ETO->query_cap_name()+"'s %^BOLD%^%^BLACK%^F"+
		"%^CYAN%^a%^BLACK%^lch%^CYAN%^io%^BLACK%^n%^BOLD%^%^BLACK%^ "+
		"begin to %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a"+
		"%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e "+
		"%^BOLD%^%^BLACK%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn"+
		"%^YELLOW%^i%^BLUE%^ng%^BOLD%^%^BLACK%^ and a loud "+
		"%^BOLD%^%^BLACK%^th%^CYAN%^u%^BLACK%^ndercl%^YELLOW%^"+
		"a%^BLACK%^p stuns "+targ->query_cap_name()+" "+
		"as "+ETO->query_cap_name()+" slams the flat of the blade "+
		"into "+targ->query_cap_name()+" face.%^RESET%^");
	        targ->set_paralyzed(roll_dice(2,4));
	  break;
	  
	  return 1;
	}
  }
}
