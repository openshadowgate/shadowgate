#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create(){
	::create();
	set_name("%^YELLOW%^engraved g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n bracers%^RESET%^");
	set_id(({ "bracers", "golden bracers", "bracers of the phoenix" }));
	set_short("%^YELLOW%^Bracers %^YELLOW%^of the %^BOLD%^%^RED%^P%^RESET%^%^RED%^h%^YELLOW%^o%^RESET%^%^ORANGE%^e%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^x%^RESET%^");
	set_obvious_short("%^YELLOW%^engraved g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n bracers%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a set of excellent quality bracers made from bright, %^BOLD%^%^WHITE%^highly polished %^YELLOW%^gold%^RESET%^.  Covering their surface is a highly-detailed engraving of a %^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^y %^BOLD%^%^RED%^p%^YELLOW%^h%^MAGENTA%^o%^RESET%^%^RED%^e%^ORANGE%^n%^MAGENTA%^i%^BOLD%^%^RED%^x %^RESET%^with outstretched wings.  The engravings have been enameled with warm shades of %^RED%^red%^RESET%^, %^ORANGE%^orange%^RESET%^, and %^Y

AVATAR
	);
	set_weight(5);
	set_value(7550);
	set_lore(
@AVATAR
These bracers are a Darkholme family heirloom passed down from generation to generation.  They were forged in the year -1000 SG by the mage Lurielwyn when the family first converted to the Church of Lathander.  Since that time the greatest wizard of each generation has worn them until his or her retirement or death.  They were lost in the year 495 SG when the family was captured by drow raiders on a slave hunt.  Nobody really knows what happened to them afterwards.

AVATAR
	);
        set_property("lore difficulty",12);
	set_type("bracer");
      set_property("repairtype",({ "jewel","armorsmith" }));
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The phoenix on "+ETOQCN+"'s bracers glows brightly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^The phoenix begins to %^BOLD%^glow%^RESET%^ as you fasten on the bracers.");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The room seems to darken as "+ETOQCN+" removes the "+query_short()+"%^BOLD%^%^WHITE%^.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The image fades as you remove the bracers.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^"+ETOQCN+"'s bracers glow brightly!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The image of the phoenix glows brightly!%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^The phoenix on "+ETOQCN+"'s bracers glows brightly, blinding you!%^RESET%^");
		who->set_paralyzed(random(10));
return damage;	}
}
