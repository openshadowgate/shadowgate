#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Katana");
	set_id(({ "katana", "ancient katana", "exquisite katana", "exquisite ancient katana", "sword", "ancient sword" }));
	set_short("%^YELLOW%^E%^RED%^x%^WHITE%^q%^YELLOW%^uisite A%^RED%^n%^WHITE%^c%^YELLOW%^ient K%^RED%^a%^WHITE%^t%^YELLOW%^ana%^RESET%^");
	set_obvious_short("%^YELLOW%^Ancient Katana%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This Katana is made from the %^BOLD%^%^WHITE%^finest quality s%^RESET%^t%^BOLD%^%^WHITE%^eel imaginable.  %^RESET%^%^CYAN%^The blade is e%^BOLD%^%^CYAN%^x%^WHITE%^q%^CYAN%^u%^RESET%^%^CYAN%^isitely sharp.  The centre of the gentle curve is very slightly past the middle of the blade towards the point.  The blade back has been finished in the iorimune style.  The %^BOLD%^%^BLACK%^iron handguard %^RESET%^%^CYAN%^has a %^YELLOW%^f%^MAGENTA%^l%^GREEN%^o%^RESET%^%^RED%^r%^MAGENTA%^a%^GREEN%^l%^CYAN%^ and %^BOLD%^%^WHITE%^c%^CYAN%^l%^BLUE%^o%^WHITE%^ud %^RESET%^%^CYAN%^design, the translucent enamels are separated by %^ORANGE%^copper gilt %^CYAN%^wire.  No part of this superb sword has been overlooked by fine detail.

AVATAR
	);
	set_weight(6);
	set_value(15000);
	set_lore(
@AVATAR
%^CYAN%^The origins of the distinctive blade of the katana is surrounded in myth and legend.  It is said that Lathander created a sword as a gift for a mortal king, and since that time weaponsmiths of extraordinary skill have tried to immitate its aesthetics and remarkably fine edge.  Other tales attribute the style and design of katanas to elven craftsmen many centuries ago and that is was they who presented such a blade to a human ruler as a splendid gift.
%^CYAN%^The style of this particular blade in all its detailing suggests that it is a very ancient example of the works of a master swordsmith.  The floral and cloud design of the handguard is likely in immitation of the very first legendary katana.  It would be an act of unspeakable ignorance to sheath this blade in anything other than the finest quality sheath that money can buy.

AVATAR
	);
	set_type("slashing");
	set_prof_type("large blades");
	set_size(3);
	set_wc(3,6);
	set_large_wc(2,6);
	set_property("enchantment",3);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" appears momentarily serene as they wield an old katana",ETO);
	tell_object(ETO,"%^YELLOW%^You feel one with the spirit of the blade!");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" sighs quietly as they unwield the old katana",ETO);
	tell_object(ETO,"%^YELLOW%^You treat the katana with great respect as you put it aside");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 215){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^You are one with the blade as it strikes "+targ->QCN+"!");
	tell_object(targ,"%^YELLOW%^"+ETOQCN+"'s katana cuts you deeply!");
		return roll_dice(1,4)+1;	}
}