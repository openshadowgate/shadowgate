#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sledge o matic");
	set_id(({ "hammer", "sledge hammer", "sledge o matic" }));
	set_short("%^BOLD%^%^RED%^Sledge O Matic%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A big wooden %^MAGENTA%^clown %^RED%^hammer%^RESET%^");
	set_long(
@AVATAR
This is a big wooden clown hammer.  It looks like it would hurt like hell if you were hit with it.  On a side note, there appears to be some smashed watermelon and other things stuck to its face.

AVATAR
	);
	set("read",
@AVATAR
Sledge O Matic!

AVATAR
	);
     set("langage","common");	set_weight(400);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("bludgeoning");
	set_prof_type("large hammer");
	set_size(3);
	set_wc(1,20);
	set_large_wc(1,20);
	set_property("enchantment",30);
	set_ac(1000);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^RESET%^"+ETOQCN+" brings the hammer in a %^RESET%^%^RED%^vicious %^RESET%^overhead swing and hits "+targ->QCN+" square in the head, sending bits of %^BOLD%^%^BLUE%^goo %^RESET%^flying everywhere!",({ETO,targ}));
	tell_object(ETO,"%^RESET%^You bring the hammer in a %^RESET%^%^RED%^vicious %^RESET%^overhead swing and hit "+targ->QCN+" square in the head, sending bits of %^BOLD%^%^BLUE%^goo %^RESET%^flying everywhere!");
	tell_object(targ,"%^RESET%^"+ETOQCN+" brings the hammer in a %^RESET%^%^RED%^vicious %^RESET%^overhead swing and hits you square in the head, sending bits of %^BOLD%^%^BLUE%^goo %^RESET%^flying everywhere!  You fall to the ground dead as a hammer.");
		return roll_dice(10000,10000)+0;	}
}