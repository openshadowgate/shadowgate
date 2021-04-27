#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Gormin-Suul");
	set_id(({ "sword", "gormin", "gormin-suul", "kiss", "broadsword" }));
	set_short("%^BOLD%^%^BLUE%^Gormin%^WHITE%^-%^BLUE%^Sull%^WHITE%^, %^CYAN%^W%^WHITE%^inter's %^CYAN%^K%^WHITE%^iss%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^ancient frozen broadsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^The weapon you are examining clearly demonstrates its age, but seems no less dangerous.  It is a broadsword of classical design, reminiscent of times before the influence of Tsarven culture.  The thick, blue-tinted blade is honed to a double, hacking edge.  The blade is encased in a perpetual layer of thin ice, forming a web of hairline cracks and meeting the air with wisps of blueish steam.  The crossguard of the sword serves as traditional protection and balance, but grows more decorative as it nears the blade.  It seems somehow forged from a single piece of metal but depicts images of arctic warfare with the detail of sculpture.  An icicle motif decorates the pommel. %^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(6000);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^Gormin-Suul is the name of this impressive weapon.  Its name translates to Winter's Kiss in the language of northern barbarians untouched by Tsarven influence.  Legend says that the sword was a gift from the Frostmaiden Auril herself, in the form of one of her avatars.  Auril gave the blade to Lord Balgus, a merciless ruler who eventually earned undeath for his sacrifices to the Frostmaiden.  Lord Balgus was only defeated many years later at the hands of the drow armies under Mount Krakus.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set_type("slashing");
	set_prof_type("martial weapon proficiency");
	set_size(2);
	set_wc(1,9);
	set_large_wc(1,10);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" shivers as they wield the frosty blade.",ETO);
	tell_object(ETO,"%^CYAN%^A shiver runs up your spine as you wield the blade.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" flushes with warmth as they unwield the frosty blade.",ETO);
	tell_object(ETO,"%^ORANGE%^You begin the thaw as you unwield the blade.");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^CYAN%^As "+ETOQCN+" swings their sword in an arc, a gust of hail erupts in its wake, freezing the air around "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^CYAN%^As you swing the sword in an arc, a gust of hail erupts from its wake, freezing the air near "+targ->QCN+"!");
	tell_object(targ,"%^CYAN%^As "+ETOQCN+" strikes at you, a gust of hail erupts in their wake, freezing the air around you!");
		targ->set_paralyzed(roll_dice(10,0)+0);
return 0;	}

}
