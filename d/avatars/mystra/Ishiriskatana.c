#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("sword");
	set_id(({ "sword", "katana", "blade" }));
	set_short("%^BOLD%^%^BLUE%^M%^WHITE%^oo%^BLUE%^nB%^WHITE%^lad%^BLUE%^e %^WHITE%^K%^BLUE%^atan%^WHITE%^a%^RESET%^");
	set_obvious_short("%^BLUE%^a small katana%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^The elegance of this blade can be seen from handle to tip in the quality of the workmanship that went into it's creation.  The blade is well tempered to harden to steel making it harder to knick or chip when used.  Ancient runes glow along the blade when held upright in the moonlight.  Hide has been tightly wrapped around the handle as smoothly as you've ever seen done.  A gentle blue ribbon is tied shortly up the hilt and dangles from the end in ceremonial fashion.
%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(10000);
	set("dexbonus",2);
	set_type("slashing");
	set_prof_type("martial");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,8);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" appears quicker as he slashes the "+query_short()+" through the air%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You feel much more graceful and deadly as you wield "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" seems to slow down as "+query_short()+" is released.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You feel less agile as you release the "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}

void init(){
   ::init();
   set_wc(1,8);
   set_large_wc(1,8);
}