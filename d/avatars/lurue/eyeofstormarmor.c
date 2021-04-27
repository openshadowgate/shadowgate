#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("armor");
	set_id(({ "armor", "storm swept armor", "eye of the storm", "storm's eye", "storms eye" }));
	set_short("%^YELLOW%^E%^WHITE%^y%^YELLOW%^e %^BLACK%^o%^YELLOW%^f t%^CYAN%^h%^YELLOW%^e S%^BLACK%^t%^YELLOW%^o%^CYAN%^r%^YELLOW%^m%^RESET%^");
	set_obvious_short("%^RESET%^a remarkable suit of %^YELLOW%^s%^CYAN%^t%^YELLOW%^o%^BLACK%^r%^YELLOW%^m s%^CYAN%^w%^YELLOW%^e%^WHITE%^p%^YELLOW%^t%^RESET%^ armor");
	set_long(
@AVATAR

%^YELLOW%^Six bands of %^CYAN%^glistening ice %^YELLOW%^create the only tangible, lasting pieces for this suit of %^BOLD%^%^BLACK%^armor%^YELLOW%^.  One can be found at each sleeve and ankle, with another at the waist and the final one about the neck.  When worn these bands transform into %^CYAN%^icy replicas %^YELLOW%^of a gorget, a fauld, a pair of greaves and a pair of vambraces.  When worn a network of e%^WHITE%^l%^YELLOW%^ect%^WHITE%^r%^YELLOW%^ic l%^WHITE%^i%^YELLOW%^nk%^WHITE%^s %^YELLOW%^flow out from between these bands in a flickering suit of protective chain mail.  Over this, created from the admixture of li%^WHITE%^g%^YELLOW%^htn%^WHITE%^i%^YELLOW%^ng and %^CYAN%^ice%^YELLOW%^ a curiass is formed from a %^BLACK%^raging storm%^YELLOW%^.  Dark clouds roil with rain, hail and lightning over the front and back of the wearer, protecting them with the sheer violence of the storm's power.%^RESET%^


AVATAR
	);
	set_weight(50);
	set_value(0);
	set_lore(
@AVATAR

%^YELLOW%^No mortal hand formed this bizarre suit of armor, instead a creature of great power was sacrificed in the name of the hunt and the storm and the fury.  The very sacrifice reduced the creature's being into what the supplicant sought upon destroying the being.  In this case, the wear's desire was clearly a suit of unrivaled armor.  Armor formed from the very life force of the living storm.%^RESET%^


AVATAR
	);
	set_property("lore difficulty",15);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
      if((string)ETO->query_name() != "amaya" && !avatarp(ETO)) {
        tell_object(ETO,"This armor doesn't fit you.");
        return 0;
      }
	tell_room(environment(ETO),"%^YELLOW%^Lightning %^BLACK%^blazes across "+ETOQCN+"'s body as the %^CYAN%^icy bands %^BLACK%^of their "+query_short()+" %^BOLD%^%^BLACK%^melt and reform into protective armor surrounded by the power of a %^YELLOW%^l%^WHITE%^i%^YELLOW%^v%^BLACK%^i%^CYAN%^n%^YELLOW%^g s%^BLACK%^t%^WHITE%^o%^CYAN%^r%^YELLOW%^m%^BLACK%^!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slide the six bands of %^CYAN%^ice %^BLACK%^into place and throw you head back, gritting your %^WHITE%^teeth %^BLACK%^as %^YELLOW%^lightning %^BLACK%^burns across your entire body and %^CYAN%^ice %^BLACK%^melts only to reform forms into protective armor.  Only then does the %^YELLOW%^s%^BLACK%^t%^WHITE%^o%^CYAN%^r%^YELLOW%^m %^BLACK%^come to life and encase your entire body in its living power!%^RESET%^");
	ETO->do_damage("torso",random(30));
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^YELLOW%^lightning%^BLACK%^ flickers and then fades as the %^YELLOW%^s%^BLACK%^t%^WHITE%^o%^CYAN%^r%^YELLOW%^m c%^BLACK%^l%^WHITE%^o%^CYAN%^u%^YELLOW%^ds %^BLACK%^fade apart, leaving "+ETOQCN+" free of their "+query_short()+" %^BLACK%^%^BOLD%^for now.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^With an incredible display of will power, you command the %^YELLOW%^l%^WHITE%^i%^YELLOW%^v%^BLACK%^i%^CYAN%^n%^YELLOW%^g s%^BLACK%^t%^WHITE%^o%^CYAN%^r%^YELLOW%^m%^BLACK%^ back into its inert form where it waits to be unleashed once more.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A booming thunderclap sounds!%^RESET%^ ",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Your body is shaken by the concussion of a thunderclap as your %^YELLOW%^l%^WHITE%^i%^YELLOW%^v%^BLACK%^i%^CYAN%^n%^YELLOW%^g s%^BLACK%^t%^WHITE%^o%^CYAN%^r%^YELLOW%^m%^BLACK%^ absorbs and redirects the blow from "+who->QCN+"'s attack!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^A booming thunderclap sounds, sending you reeling as your attack is turned aside!%^RESET%^");
return (damage*-75)/100;	}

}
