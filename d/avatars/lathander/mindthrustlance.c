#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Mind Thrust Lance");
	set_id(({ "lance", "mind thrust lance", "mindthrustlance", "crystal lance" }));
	set_short("%^BOLD%^%^CYAN%^Jevr%^BLUE%^aa%^CYAN%^r's Lance of the Splintered Mind%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^A magnificent translucent lance of crystal%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a magnificent translucent lance of crystal. Perfectly shaped no distortions can be seen within. The shape of the lance is more seen by the play of light and movement than any actual color.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(10000);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);	set_size(medium);
	set_wc(3,6);
	set_large_wc(3,6);
	set_property("enchantment",6);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 50){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^As "+ETOQCN+"'s "+query_short()+" pierces "+targ->QCN+", the sound of a shattering glass can be heard emanating from "+targ->QCN+"'s head.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^As the "+query_short()+" pierces "+targ->QCN+", the sound of a shattering glass can &n&+ybe heard emanating from "+targ->QCN+"'s head.");
	tell_object(targ,"%^BOLD%^%^CYAN%^Horrible %^RED%^>%^RESET%^%^RED%^PAIN%^BOLD%^!< %^CYAN%^wracks your mind and the sound of shattering glass suffocates your world as "+ETOQCN+"'s "+query_short()+" strikes you.");
		targ->set_paralyzed(roll_dice(5,0)+0);
return 0;	}
}