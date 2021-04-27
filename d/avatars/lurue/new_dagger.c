#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "knife", "dagger", "howling knife" }));
	set_short("%^BOLD%^%^RED%^H%^BLUE%^o%^BLACK%^w%^RED%^li%^BLUE%^n%^RED%^g K%^BLUE%^n%^BLACK%^i%^RED%^fe%^RESET%^");
	set_obvious_short("a %^BOLD%^%^RED%^f%^BLACK%^i%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^el%^RED%^y %^RESET%^made knife");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This curious curved knife features a %^BOLD%^%^BLUE%^topaz hilt %^BLACK%^that has been drilled through with several small holes.  This causes the weapon to howl as air passes through the exposed holes, creating a disconcerting noise when used in battle.  The blade is made of steel and is sharply edged.  Curving back the tip turns back toward the wielder's hand like a hook, allowing the wielder to snag and tear at his enemy as well as slice.  Etched into the handle and blade are a series of %^RED%^odd runes %^BLACK%^that appear to be some ancient form of language or pictograph.%^RESET%^ 

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLACK%^The runes appear to be a dead language which you cannot understand.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(100);
	set_lore(
@AVATAR
The design of this dagger was first originated by renown rogue Brethane Erstocki.  A halfling with smaller then usual hands, Erstocki found that carrying several tools made his life difficult during heists and so he set out to create a weapon which would provide several functions.  Specifically the ability to grab, twist and manipulate things, as well as create a dangerous weapon.  Why he drilled the noisy holes is anyone's guess, but some speculate that it was an attempt to create a type of musical instrument that didn't turn out so well.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,3);
	set_large_wc(1,2);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^With a mighty heave, "+ETOQCN+" drags the hook of their "+query_short()+" %^BOLD%^%^RED%^backwards and gouges a hole in "+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^With a mighty heave, you drag the hook of your "+query_short()+" %^BOLD%^%^RED%^backwards and gouge a hole in "+targ->QCN+"'s flesh!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^With a mighty heave, "+ETOQCN+" drags the hook of their "+query_short()+" %^BOLD%^%^RED%^backwards and gouges a hole in your flesh!  Ouch!%^RESET%^");
		return roll_dice(1,4)+0;	}
}