#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^YELLOW%^Dagger of Sharpness%^RESET%^");
	set_id(({ "dagger", " dagger of sharpness" }));
	set_short("%^YELLOW%^Dagger of Sharpness%^RESET%^");
	set_obvious_short("shining dagger");
	set_long(
@AVATAR
This long dagger has an unusually thin and broad blade.  Upon closer inspection you notice that the edges seem to %^FLASH%^%^YELLOW%^phase in and out of existence%^RESET%^, there one moment gone the next.  This betrays a somewhat more than mundane nature of the object.  You cannot help but wonder what the effects of this strange behavior would be if confronted with a solid object.  The handle is clearly designed with the ergonomics of a thrusting motion in mind.  It is wrapped in tightly fitted loops of %^YELLOW%^golden cord%^RESET%^ that feel as smooth as silk and make it very pleasant to wrap your fingers around. 

AVATAR
	);
	set("read",
@AVATAR
Peering closely at the %^YELLOW%^golden cord%^RESET%^ around the handle you can make out tiny letters %^BLUE%^M%^RESET%^ made out of %^BOLD%^%^BLACK%^black silk%^RESET%^ woven into the cord.

AVATAR
	);
	set_weight(12);
	set_value(1000);
	set_lore(
@AVATAR
%^YELLOW%^Daggers of Sharpness%^RESET%^ belong to a much wider collection of blades originally manufactured by %^BLUE%^Metikul%^RESET%^, sometimes known as %^BLUE%^the Artificer%^RESET%^.  The entire collection of blades is fabled for its unusual blade properties which allow these weapons to threaten even the best armor by %^FLASH%^phasing out%^RESET%^ of the %^BOLD%^%^WHITE%^Prime Material Plane%^RESET%^, therefore bypassing any solid objects in their way.

AVATAR
	);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",4);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 500){
	tell_room(environment(query_wielded()),""+ETO->query_cap_name()+"'s blade seems to vanish from view only to reappear deep in "+targ->query_cap_name()+"'s flesh.",({ETO,targ}));
	tell_object(ETO,""+query_short()+"'s blade disappears completely only to materialize deep "+targ->query_cap_name()+"'s flesh.");
	tell_object(targ,""+ETO->query_cap_name()+"'s dagger vanishes from your view and a fraction of a moment later you're wracked with terrible pain of a narrow and wide blade imbedded in your flesh.");
        set_property("magic",1);
	targ->do_damage("torso",random(10)+1);	
        remove_property("magic");
	}
}