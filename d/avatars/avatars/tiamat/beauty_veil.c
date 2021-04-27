#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Beauty's Veil");
	set_id(({ "circlet", "veil", "mask", "crown", "tiara" }));
	set_short("%^RESET%^%^GREEN%^B%^MAGENTA%^e%^ORANGE%^a%^MAGENTA%^u%^GREEN%^ty's %^BLUE%^V%^BOLD%^ei%^RESET%^%^BLUE%^l%^RESET%^ ");
	set_obvious_short("%^RESET%^%^GREEN%^R%^MAGENTA%^u%^ORANGE%^n%^MAGENTA%^e%^GREEN%^d %^BOLD%^%^WHITE%^ad%^CYAN%^a%^WHITE%^mant%^CYAN%^i%^WHITE%^um %^YELLOW%^circlet%^RESET%^%^GREEN%^ with %^BOLD%^%^BLUE%^veil%^RESET%^ ");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This simple %^BOLD%^%^WHITE%^ad%^CYAN%^a%^WHITE%^mant%^CYAN%^i%^WHITE%^um %^RESET%^%^ORANGE%^circlet appears plain when first glanced at. Upon closer examination, tiny %^GREEN%^el%^BOLD%^v%^RESET%^%^GREEN%^ish %^GREEN%^r%^MAGENTA%^u%^ORANGE%^n%^MAGENTA%^e%^GREEN%^s %^ORANGE%^can be seen covering the entire %^YELLOW%^circlet%^RESET%^%^ORANGE%^. Tiny loops dangle down from half of the circlet, affixed to a delicate %^BLUE%^veil%^ORANGE%^ made from %^YELLOW%^fine %^RESET%^%^CYAN%^light %^BOLD%^%^BLUE%^blue %^RESET%^%^MAGENTA%^silk%^RESET%^%^ORANGE%^. It covers the entire face, from forehead to chin with eye holes cut out. The top of the veil has small strips of fine leather tied to the %^YELLOW%^circlet's %^RESET%^%^ORANGE%^hoops.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2000);
	set_lore(
@AVATAR
%^RESET%^%^GREEN%^B%^MAGENTA%^e%^ORANGE%^a%^MAGENTA%^u%^GREEN%^ty's %^BLUE%^V%^BOLD%^ei%^RESET%^%^BLUE%^l%^RESET%^ is a minor magical item first inspired by the legendary bard Singer in an attempt to restore beauty for a friend.  The friend's face was mutilated horribly.  The circlet and attached veil house an enchantment of illusion.  Singer, along with mages in service to Selune, crafted the circlet, veil and spell.


AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETOQCN+" pulls the %^RESET%^%^MAGENTA%^silken %^BOLD%^%^BLUE%^veil down over their face, it fizzles and %^CYAN%^slo%^BLUE%^wl%^RESET%^%^BLUE%^y %^BOLD%^vanishes into nothing, leaving behind the visage of "+ETOQCN+" as youthful, healthy and whole!",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^As you pull the %^RESET%^%^MAGENTA%^silken %^BOLD%^%^BLUE%^veil down over your face, you feel it become weightless against your skin and %^CYAN%^slo%^BLUE%^wl%^RESET%^%^BLUE%^y %^BOLD%^vanish into nothing, leaving behind a tingling sensation.");
      set_hidden(100);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^As "+ETOQCN+" begins to remove the %^YELLOW%^circlet%^RESET%^%^CYAN%^, a silken %^MAGENTA%^veil%^CYAN%^ appears over their face and is pulled away, leaving behind the visage of "+ETOQCN+" in their %^ORANGE%^natural state%^CYAN%^.",ETO);
	tell_object(ETO,"%^CYAN%^As you begin to remove the %^YELLOW%^circlet%^RESET%^%^CYAN%^, the %^MAGENTA%^veil%^CYAN%^ over your face suddenly rea%^BOLD%^ppea%^BLUE%^rs%^RESET%^%^CYAN%^ and you are left with your former self.%^RESET%^");
      set_hidden(0);
	return 1;
}

