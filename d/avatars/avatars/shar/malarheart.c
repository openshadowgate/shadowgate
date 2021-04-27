#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("heart of the beast");
	set_id(({ "heart", "heart of the beast" }));
	set_short("%^RESET%^%^RED%^Heart%^ORANGE%^ of the %^RED%^Beast%^RESET%^");
	set_obvious_short("A withered heart on a leather thong");
	set_long(
@AVATAR
%^RED%^A withered heart has been strung on a leather cord.   It is difficult to determine what type of creature the slightly larger than fist size organ came from.  It has been dried and withered into a dull red-brown color.  The leather cord looks as if it's seen better days as well, looking very frayed and beaten.

AVATAR
	);
	set("read",
@AVATAR


AVATAR
	);
     set("langage","str");	set_weight(4);
	set_value(1000);
	set_lore(
@AVATAR
The Heart of the Beast is gifted from Malar to worthy followers.  There are  many rumors around about what type of heart it is.  Some say it is the heart of a unicorn.  Some whisper it's the heart of a paladin or elf.  So far anyone's attempts to try to divine what type of creature this heart belonged to, turns up nothing.

AVATAR
	);
	set_type("leather");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" ties a withered %^RED%^heart%^ORANGE%^ on a leather thong around their neck.  It looks as if the %^RED%^heart%^ORANGE%^ begins to%^BOLD%^%^RED%^ beat %^RESET%^%^ORANGE%^again!",ETO);
	tell_object(ETO,"%^ORANGE%^You tie the cord around your neck.  It almost seems as if the %^RED%^heart%^ORANGE%^ begins to %^BOLD%^%^RED%^beat%^RESET%^%^ORANGE%^ again.");
	ETO->add_attack_bonus(1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slips off the leather cord around their neck.  The %^RED%^heart%^ORANGE%^strung on the cord, stops beating and lays quiet.",ETO);
	tell_object(ETO,"%^ORANGE%^You slip off the leather cord and the %^RED%^heart%^ORANGE%^ quiets it's beating.");
	ETO->add_attack_bonus(-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 275){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^"+ETOQCN+" lets out a low ferral growl at the heart around their neck begins to beat faster!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^The beating of the heart quickens it's pace!  Your natural instincts are heightened, causing to avoid part of the attack!");
	tell_object(who,"%^BOLD%^%^RED%^"+ETOQCN+" lets out a low ferral growl at the heart around their neck begins to beat faster!");
return (damage*75)/100;	}
}