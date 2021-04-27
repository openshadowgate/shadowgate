#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("club");
	set_id(({ "club", "crystal club", "quartz club" }));
	set_short("%^BOLD%^%^WHITE%^C%^CYAN%^r%^RESET%^%^CYAN%^y%^BOLD%^%^WHITE%^st%^CYAN%^a%^WHITE%^l C%^CYAN%^l%^RESET%^%^CYAN%^u%^BOLD%^%^WHITE%^b%^RESET%^");
	set_obvious_short("a %^RESET%^%^ORANGE%^club %^RESET%^shaped piece of %^BOLD%^%^WHITE%^q%^CYAN%^u%^WHITE%^artz%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^A large piece of quartz crystal has been carved and polished into a thick club shaped weapon.  Though imperfect in coloration, the sheer size of this club would make it a painful thing to be on the receiving end.  A thin leather wrap of %^CYAN%^bright blue %^WHITE%^wraps the club's handle, allowing it to be wielded with comfort. %^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(100);
	set_lore(
@AVATAR
Gnomes of the Offestry Valley are known for their love of gems.  They mine day and night to find beautiful stones to sell at market which then travel to many other regions to be sold again.  Occasionally a large vein of a nearly worthless stone is found and these veins are sometimes carved out and made into weapons.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("bludgeoning");
	set_prof_type("club");
	set_size(2);
	set_wc(1,7);
	set_large_wc(1,6);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The solid weight of "+ETOQCN+"'s club strikes into "+targ->QCN+" hard!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The solid weight of your club strikes into "+targ->QCN+" hard!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^The solid weight of "+ETOQCN+"'s club strikes into you hard!%^RESET%^");
		return roll_dice(1,4)+0;	}
}