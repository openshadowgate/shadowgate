#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("shuriken");
	set_id(({ "shuriken", "weapon", "shuriken" }));
	set_short("a steel shuriken");
	set_obvious_short("a steel shuriken");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^The materials used to make this shuriken are of the highest quality steel.  Made by a master weaponsmith, the shuriken is crafted to be a fierce weapon in the hands of its wielder during combat.  Stamped with the insignia of a %^BOLD%^%^WHITE%^silver coin %^RESET%^with a woman's face surrounded by %^BOLD%^%^GREEN%^shamrocks%^RESET%^%^CYAN%^, the holy symbol of Tymora, this weapon was clearly made for those who serve and protect Tymora's faith.

AVATAR
	);
	set_weight(2);
	set_value(1500);
	set_lore(
@AVATAR
Made for those who serve as guardians of Tymora's church, this shuriken was clearly designed by a master weaponsmith and would be prized by the one who owned it.  Not only for its exceptional quality but as a symbol of status among the faith.  The loss of such a fine weapon would likely only come at the death of the original owner.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("piercing");
	set_prof_type("shuriken");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^YELLOW%^Calling upon the power of their faith, "+ETOQCN+" strikes "+targ->QCN+" a mighty blow with their "+query_short()+"!",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^Calling upon the power of your faith, you strike "+targ->QCN+" a mighty blow with your "+query_short()+"!");
	tell_object(targ,"%^YELLOW%^You are struck a mighty blow by "+ETOQCN+"'s "+query_short()+" as they call upon their faith to aid them!");
		return roll_dice(2,4)+2;	}
}