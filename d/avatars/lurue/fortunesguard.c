#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("fortunes guard");
	set_id(({ "armguards", "armguard", "bracer", "bracers", "fortunes guards", "a fortunate guard", "blue armguards", "deep blue armguards", "guards" }));
	set_short("%^BOLD%^%^BLUE%^A F%^RESET%^%^BLUE%^o%^CYAN%^r%^BOLD%^%^BLUE%^t%^RESET%^u%^BLUE%^n%^CYAN%^a%^BOLD%^%^BLUE%^te G%^RESET%^%^BLUE%^u%^RESET%^a%^BOLD%^%^BLUE%^rd%^RESET%^");
	set_obvious_short("%^RESET%^A pair of %^BLUE%^%^BOLD%^d%^RESET%^e%^BLUE%^e%^BOLD%^%^BLUE%^p b%^RESET%^%^BLUE%^l%^CYAN%^u%^BOLD%^%^BLUE%^e %^RESET%^armguards");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^Crafted from several panels of hardened leather, these %^BOLD%^%^BLUE%^ar%^RESET%^%^BLUE%^m%^BOLD%^gu%^RESET%^%^BLUE%^ar%^BOLD%^ds%^RESET%^%^CYAN%^ attach to the forearms of the wearer through a clever use of hidden snaps that make the %^BOLD%^%^BLUE%^ar%^RESET%^%^BLUE%^m%^BOLD%^gu%^RESET%^%^BLUE%^ar%^BOLD%^ds%^RESET%^%^CYAN%^ seem as though they are seamless.  The ten overlapping panels provide both an %^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^n%^CYAN%^t%^BLUE%^r%^BOLD%^%^BLUE%^ic%^RESET%^%^BLUE%

AVATAR
	);
	set("read",
@AVATAR


%^YELLOW%^  ,-------,  ,--------,
%^YELLOW%^.-------.'| .-------.'|
%^YELLOW%^| %^BLUE%^o%^YELLOW%^     | | | %^BLUE%^o   o%^YELLOW%^ | |
%^YELLOW%^|   %^BLUE%^o%^YELLOW%^   | | |       | |
%^YELLOW%^|     %^BLUE%^o%^YELLOW%^ |.' | %^BLUE%^o   o%^YELLOW%^ |.'
%^YELLOW%^'-------'   '-------'%^RESET%^



AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(2500);
	set_lore(
@AVATAR


Designed for the %^BOLD%^%^CYAN%^first place winner %^RESET%^of the 1st annual %^BOLD%^%^BLACK%^Spooky Story Contest%^RESET%^ these armguards were presented to %^YELLOW%^Kharion %^RESET%^for his epic tale of a haunted keep whose deathknight ruler was soundly defeated by the heroic Sheridan, restoring peace and the vanished maidens to the frightened nearby village.



AVATAR
	);
	set_property("lore difficulty",12);
	set_type("bracer");
      set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" secures the "+query_short()+"%^YELLOW%^ tightly about their arms.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You secure the "+query_short()+"%^YELLOW%^ tightly about your arms.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^With a quick snap of the wrist, "+ETOQCN+" removes their "+query_short()+"%^YELLOW%^.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^With a snap of the wrist, the "+query_short()+"%^YELLOW%^ comes free.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^YELLOW%^Luck favors the fortunate, turning "+who->QCN+"'s attack on "+ETOQCN+" aside!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Luck favors the fortunate, turning "+who->QCN+"'s attack aside!%^RESET%^");
	tell_object(who,"%^YELLOW%^Luck favors the fortunate, turning your attack on "+ETOQCN+" aside!%^RESET%^");
return (damage*0)/100;	}
}
