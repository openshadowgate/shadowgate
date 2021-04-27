#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("tattoo");
	set_id(({ "tattoo" }));
	set_short("a %^YELLOW%^t%^RED%^a%^GREEN%^t%^YELLOW%^t%^RED%^o%^YELLOW%^o %^RESET%^with three %^YELLOW%^i%^RED%^n%^GREEN%^t%^YELLOW%^e%^RED%^r%^GREEN%^l%^YELLOW%^o%^RED%^c%^GREEN%^k%^YELLOW%^i%^RED%^n%^GREEN%^g %^YELLOW%^l%^RED%^i%^GREEN%^n%^YELLOW%^k%^RED%^s%^RESET%^");
	set_obvious_short("a tattoo");
	set_long(
@AVATAR
This %^YELLOW%^t%^RED%^a%^GREEN%^t%^YELLOW%^t%^RED%^o%^GREEN%^o%^RESET%^ has three interlocking links to it.  Each link is a different color.  One is %^YELLOW%^yellow%^RESET%^%^RESET%^, one is %^BOLD%^%^RED%^red %^RESET%^and the last is %^BOLD%^%^GREEN%^green%^RESET%^.  They seem to almost glow with a %^YELLOW%^divine light%^RESET%^.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR

%^YELLOW%^Gold the oath to bring Ahmul in for punishment.

%^BOLD%^%^RED%^Red for the oath to return the Hammer that is the core of the offense.

%^BOLD%^%^GREEN%^Green for the penance owed to the Elves for your mistake.%^RESET%^


AVATAR
	);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
}


