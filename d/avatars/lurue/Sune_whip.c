#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("whip");
	set_id(({ "whip", "weapon", "whip" }));
	set_short("a leather whip");
	set_obvious_short("a leather whip");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^The materials used to make this whip are of the highest quality leather.  Made by a master weaponsmith, the whip is crafted to be a fierce weapon in the hands of its wielder during combat.  Stamped with the insignia of a feminine face with %^RED%^crimson hair%^CYAN%^, %^BOLD%^%^WHITE%^ivory skin%^RESET%^%^CYAN%^ and bright %^GREEN%^%^BOLD%^green eyes%^RESET%^%^CYAN%^, the holy symbol of Sune, this weapon was clearly made for those who serve and protect Sune's faith.

AVATAR
	);
	set_weight(2);
	set_value(1500);
	set_lore(
@AVATAR
Made for those who serve as guardians of Sune's church, this whip was clearly designed by a master weaponsmith and would be prized by the one who owned it.  Not only for its exceptional quality but as a symbol of status among the faith.  The loss of such a fine weapon would likely only come at the death of the original owner.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("lash");
	set_prof_type("whip");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
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