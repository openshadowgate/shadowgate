#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^Crimson colored robe%^RESET%^");
	set_id(({ "robe", "robes" }));
	set_short("%^RESET%^%^RED%^Cri%^MAGENTA%^m%^RED%^son Robe of the An%^MAGENTA%^d%^RED%^ur%^MAGENTA%^a%^RED%^ns%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^Crimson colored robe%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a simple yet finely crafted robe. It is made of a soft cloth that flows lo%^BOLD%^o%^RESET%^s%^BOLD%^e%^RESET%^ly around the wearer's body. D%^GREEN%^i%^ORANGE%^r%^RESET%^t and wrinkles seem unable to touch the fine robe. It has been dyed a %^BOLD%^%^BLACK%^dark%^RESET%^ shade of %^RED%^crimson%^RESET%^, and is mostly unadorned. A %^RED%^red%^RESET%^ silken sash ties around the waist to hold the robe securely closed. Each tip of the sash has been delicately embroidered with the holy symbol of %^BOLD%^Torm the Brave%^RESET%^.

AVATAR
	);
	set_weight(10);
	set_value(550);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^These fine robes are commonly worn by Andurans of Torm's faith. Each rank of Torm's strict heirarchy is denoted by the color of the priest's robe or armor, dark crimson being the color of the Andurans.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",7);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" stands proudly as he wears the "+query_short()+"%^BOLD%^%^WHITE%^.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Donning the robe, you are filled with a strong sense of %^YELLOW%^duty%^WHITE%^.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" sets aside his "+query_short()+" %^BOLD%^%^WHITE%^for now.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully remove the fine robe.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}
