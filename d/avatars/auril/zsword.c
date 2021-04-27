#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("crimson sabre");
	set_id(({ "sabre", "blade", "sword", "crimson sabre", "weapon" }));
	set_short("%^RESET%^%^BLUE%^T%^RESET%^%^RED%^he Bl%^RESET%^%^BLUE%^o%^RESET%^%^RED%^od %^RESET%^of %^RESET%^%^BLUE%^Heroes%^RESET%^");
	set_obvious_short("A %^RESET%^%^RED%^crimson %^RESET%^sabre with a %^BOLD%^%^BLUE%^je%^BOLD%^%^RED%^well%^RESET%^%^GREEN%^ed %^RESET%^handle");
	set_long(
@AVATAR
%^RESET%^%^RED%^This long, curved sword is fashioned of a strange crimson material that gives the blade an almost fluid quality.  The hilt and crosspiece are fashioned much as a heavily jeweled sabre, giving the appearance that the
blade was snapped off at one point and replaced by the strange red material.  A fierce red glow comes from the crismon blade, and the whole sword hums with magical energy.


AVATAR
	);
	set_weight(9);
	set_value(1000);
	set_lore(
@AVATAR
The history of the blade was that a warrior carried it into battle defending his home against an overwhelming horde of enemies.  His fellow warriors were all slain, and he broke off his sword in an enemy.  When he cried to the gods for help, the blood of his fallen friends came together to make the crimson blade...

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",2);
	set_ac(-1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" appears rallied when "+ETOQCN+" grasps the crimson blade.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Your spirit is lifted by the battlecries of the fallen as you wield the crimson sword!");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" seems to calm down after releasing the crimson sword.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The cries of the fallen linger in your thoughts for a moment as you release the crimson sword.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^Roaring violently, "+ETOQCN+" rushes towards "+targ->QCN+" and slashes deftly, cutting %^RESET%^%^RED%^deep%^BOLD%^%^CYAN%^.",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The power of the fallen warriors of the past flow through you!");
	tell_object(targ,"%^BOLD%^%^CYAN%^Roaring violently, "+ETOQCN+" rushes towards you and slashes deftly, cutting %^RESET%^%^RED%^deep%^BOLD%^%^CYAN%^.");
		return roll_dice(1,10)+0;	}
}