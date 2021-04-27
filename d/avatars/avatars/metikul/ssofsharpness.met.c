#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^YELLOW%^Short Sword of Sharpness%^RESET%^");
	set_id(({ "sword", " short sword", " sword of sharpness", " short sword of sharpness" }));
	set_short("%^YELLOW%^Short Sword of Sharpness%^RESET%^");
	set_obvious_short("shiny short sword");
	set_long(
@AVATAR
This short sword has thick and broad blade.  Upon closer inspection you notice that the edges seem to %^YELLOW%^%^FLASH%^phase in and out of existence%^RESET%^, there one moment gone the next.  This betrays a somewhat more than mundane nature of the object.  You cannot help but wonder what the effects of this strange behavior would be if confronted with a solid object.  The handle is clearly designed with the ergonomics of a thrusting motion in mind.  It is wrapped in tightly fitted loops of %^YELLOW%^golden cord%^RESET%^ that feel as smooth as silk and make it very pleasant to wrap your fingers around.
AVATAR
	);
	set("read",
@AVATAR
Peering closely at the %^YELLOW%^golden cord%^RESET%^ around the handle you can make out tiny letters %^BLUE%^M%^RESET%^ made out of %^BOLD%^%^BLACK%^black silk%^RESET%^ woven into the cord.
AVATAR
	);
	set_weight(25);
	set_value(3000);
	set_lore(
@AVATAR
%^YELLOW%^Short Sword of Sharpness%^RESET%^ is a member of a broader collection of weapons collectively known as %^BOLD%^%^WHITE%^Blades of Sharpness%^RESET%^.  They share similar design and construction processes set forth by Metikul the Artificer.  Based on his research into multidimensional nature of our realm he was able to manufacture blades that %^FLASH%^%^YELLOW%^phased in and out%^RESET%^ of this dimention making them a capable adversary not only of conventional and magical suits of armor, but also enabling these finely crafted weapons to bypass more arcane forms of protection such as stone skin.
AVATAR
	);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,8);
	set_property("enchantment",4);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 500){
		tell_room(environment(query_wielded()),"The blade "+
			"of "+query_short()+" seems to disappear "+
			"from "+ETO->query_cap_name()+"'s hand only to "+
			"reappear a split moment later deep "+
			"inside "+targ->query_cap_name()+"'s flesh.",({ETO,targ}));
		tell_object(ETO,""+query_short()+"'s blade disappears "+
			"completely only to reappear a split moment later "+
			"imbedded deeply in "+targ->query_cap_name()+"'s flesh.");
		tell_object(targ,"You watch in stunned disbelief as the "+
			"blade of "+ETO->query_cap_name()+"'s "+query_short()+" "+
			"disappears from view and bypasses your defenses "+
			"materializing deep in your flesh.  Your entire "+
			"being is consumed with terrible pain of your wounding.");
   	set_property("magic",1);
		targ->do_damage("torso",random(12)+5);	
    	remove_property("magic");
	}
}