#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sea urchin stilleto");
	set_id(({ "sea urchin", "urchin stilleto", "dagger", "dirk", "knife", "stilleto", "urchin", "spike", "black spike" }));
	set_short("%^BOLD%^%^CYAN%^S%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^a %^BLACK%^U%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^n %^BOLD%^%^BLACK%^Spike%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^black spike%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This long %^BLACK%^black spike%^BLUE%^ is roughly shaped into a serviceable stilleto. The handle is wrapped in %^RESET%^%^BLUE%^sharkskin%^BOLD%^ and there is no hilt. There is a tiny hole in the very tip of the spike, but that does not detract from the fact that it would make a formidable piercing weapon. There is no ornamentation to the spike but there is a faint whiff of %^RESET%^salt%^BOLD%^%^BLUE%^ waffting off of it.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_lore(
@AVATAR
This spike is actually fashioned from a sea urchin. Taking one of it's longer spikes, it is then enchanted and fashioned into a weapon that would still deliver a bit of venom to an individual. The Sahuagin are known for utilizing any and everything from around their environment and fashioning them into deadly weapons.

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",3);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+" jams their %^BLACK%^black spike%^BLUE%^ into "+targ->QCN+"'s neck and grins wickedly as it slides in even deeper!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^You jam the %^BLACK%^black spike%^BLUE%^ into "+targ->QCN+"'s neck and feel it jerk in even more.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" jams the %^BLACK%^black spike%^BLUE%^ into your neck, then it slides in even deeper, injecting a burning liquid, causing %^RED%^intense%^BLUE%^ pain.%^RESET%^");
		return roll_dice(3,4)+0;	}

}
