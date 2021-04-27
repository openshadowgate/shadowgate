#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("ghostly axe");
	set_id(({ "axe", "ghost axe", "battle axe" }));
	set_short("%^BOLD%^%^WHITE%^Phantasmal Bl%^RED%^o%^WHITE%^od%^RED%^y%^WHITE%^ Axe%^RESET%^");
	set_obvious_short("A ghostly axe");
	set_long(
@AVATAR
This is a large axe in the style of a Medieval executioner's axe. It has a long, curved end, perfect for seperating a head from a body. The axe is semi-transparent and ghostly and feels light in your hands. Droplets of %^RED%^blood%^WHITE%^ constanly fall while it is wielded, vanishing before they hit the floor.  Something appears to be written on the handle.

AVATAR
	);
	set("read",
@AVATAR
 Thou shalt not Kill

AVATAR
	);
     set("langage","common");	set_weight(4);
	set_value(1800);
	set_lore(
@AVATAR
The Phantasmal axe is said to only appear on the physical world in times of great historical discord.  Legend has it that the axe belonged to an executioner from ancient Tharis.  The executioners last victim was a high priest of Cyric, who fused the executioner to the axe forever as punishment.

AVATAR
	);
	set_property("lore difficulty",20);
	set_type("slashing");
	set_prof_type("large axe");
	set_size(3);
	set_wc(3,8);
	set_large_wc(4,8);
	set_property("enchantment",4);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^BOLD%^%^WHITE%^looks pale as they wield "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You feel your blood begin to chill as you wield "+query_short()+"%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^WHITE%^seems relieved letting go of "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^WHITE%^You feel at ease when you release "+query_short()+"%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" 's "+query_short()+" splashes %^RED%^gore%^WHITE%^ as it slices through "+targ->QCN+"%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^"+query_short()+" splashes %^RED%^gore%^WHITE%^ as it slices through "+targ->QCN+"%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^You feel death coming closer as "+query_short()+" hits you!%^RESET%^");
		return roll_dice(3,6)+0;	}
}