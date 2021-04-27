#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Tachi");
	set_id(({ "tachi", "sword", "two-handed sword" }));
	set_short("%^BOLD%^%^BLACK%^A %^RED%^S%^BLACK%^pl%^RED%^e%^BLACK%^nd%^RED%^i%^BLACK%^d Tachi%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A Tachi%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This Tachi is made from high quality steel.  The aesthetically curved blade is exquisitely sharp.  The curve is more exagerrated than it would be on a Katana.  The blade back has been rounded in the marumune style.  The hilt has been covered with a %^BOLD%^%^RED%^rich red laquer%^WHITE%^ than has been decorated with %^YELLOW%^gold foil%^WHITE%^.  %^BLACK%^A bla%^RED%^c%^YELLOW%^k%^RED%^ b%^BLACK%^ind%^RED%^i%^YELLOW%^n%^RED%^g%^BLACK%^ has been wound around the hilt to ensure a secure grip.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(1500);
	set_lore(
@AVATAR
%^RED%^A %^YELLOW%^tachi%^RESET%^%^RED%^ is a curved blade, usually longer than a katana, that is worn edge downwards, whilst the katana and wakizashi are word edge upwards.  The name is said to derive from an ancient Elven word '%^MAGENTA%^tachikiru%^RED%^' which translates roughly into Common as '%^GREEN%^to cut in two%^RED%^'.  %^RED%^Few of these ancient weapons are still in existance.  Of those that have survived they are commonly found in elaborately decorated scabbards which were often decorated with fine patterns in cut out gold foil and covered in laquer which was then highly polished.  It is thought that tachi held primarily ceremonial functions which is why they were often so highly decorated, but they could also serve as very practical weapons.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(5,4);
	set_large_wc(5,6);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" calmly wields a tachi",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel calm as you wield the tachi!");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" unwields tachi with care",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You take care as you put aside the tachi");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 550){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" cuts "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^You cut cleanly into "+targ->QCN+"!");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s tachi cuts you deeply!");
		return roll_dice(2,4)+0;	}
}