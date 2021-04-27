#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bracelets");
	set_id(({ "bracelets", "bracelets of harmony","bracers" }));
	set_short("%^BOLD%^%^WHITE%^Bracelets of %^RED%^H%^RESET%^"+
		"%^RED%^a%^BOLD%^r%^RESET%^%^RED%^m%^BOLD%^o%^RESET%^"+
		"%^RED%^n%^BOLD%^y%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A pair of slender bracelets%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Made from exotic titanium these slender bracelet"+
		"s have a harmonious beauty to them.  The twin bracelets are made "+
		"identical in everyway.  A trio of three metal bells has been artfully"+
		" woven to each pale bracelet, complementing the white metal "+
		"harmoniously.  Each bell is made from silver that has been "+
		"enameled a vibrant shade of %^RED%^red%^WHITE%^.  Carved "+
		"around the surface of the bracelets are images of musical"+
		" notes, instruments, and masks of comedy and tragedy.  The "+
		"bells chime softly when shaken, creating for a pleasant melody.");
	set_weight(10);
	set_value(1200);
	set_lore("The Bracelets of Harmony are a special pair of bracers that"+
		" only the faith of Oghma knows how to create.  The Bracelets "+
		"are given to those bards, entertainers, and performers they "+
		"feel demonstrates the dogma to the highest level.  The envy"+
		" of other bards, the wearer of these bracelets will find their"+
		" fame and status growing at least ten fold among the community "+
		"of bards and their patrons.");
	set_property("lore",14);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	if(!ETO->is_class("bard")){
   		tell_object(ETO,"%^CYAN%^You are to tone deaf to even be able to get those on.");
      		return 0;
        }

	tell_object(ETO,"%^BOLD%^%^RED%^The bracelets sparkle and"+
		"chime a harmonious tune as you slip them on.");
	return 1;
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^RED%^The bracelets chime a harmonious"+
		" tune as you slip them off.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^"+ETOQCN+" strikes"+
		" "+ETO->QP+" bracelets together to create a burst of harmonious"+
		" melodies that knocks "+who->QCN+" back.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^You strike your bracelets together, "+
		"creating a burst of harmonious melodies that knocks "+who->QCN+" back.");
	tell_object(who,"%^BOLD%^%^RED%^"+ETOQCN+" strikes "+ETO->QP+" bracelets "+
		"together to create a burst of harmonious melodies that knocks"+
		" you back.");
		who->do_damage("torso",random(8)+1);
	}
}