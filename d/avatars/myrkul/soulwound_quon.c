#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("soulwound");
	set_id(({ "soulwound", "wound", "soul wound" }));
	set_short("%^RESET%^%^MAGENTA%^C%^CYAN%^a%^MAGENTA%^tast%^CYAN%^r%^MAGENTA%^oph%^CYAN%^i%^MAGENTA%^c %^BOLD%^%^WHITE%^Soul%^RED%^ W%^RESET%^%^RED%^o%^BOLD%^und%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^C%^CYAN%^a%^MAGENTA%^tast%^CYAN%^r%^MAGENTA%^oph%^CYAN%^i%^MAGENTA%^c %^BOLD%^%^WHITE%^Soul%^RED%^ W%^RESET%^%^RED%^o%^BOLD%^und%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^You feel %^RED%^terrible%^BLACK%^, as if afflicted with some %^GREEN%^disease%^BLACK%^ without a name. Your body seems almost %^CYAN%^translucent%^BLACK%^ like some permanent substance has somehow been removed from you. You %^RESET%^%^MAGENTA%^suffer%^BOLD%^%^BLACK%^ from %^YELLOW%^malaise%^BLACK%^, as if your life has lost its purpose and the very act of drawing breath is a chore. %^RED%^Fevers%^BLACK%^ wrack your body, while %^MAGENTA%^hallucinations%^BLACK%^ and %^YELLOW%^m%^RED%^a%^WHITE%^d%^GREEN%^n%^RESET%^%^ORANGE%^e%^MAGENTA%^s%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^ wracks your brain.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
Your soul has been feasted on by the Sin Eater. Your sins are many, including Wrath, Greed, Envy, Pride, and Gluttony. You have little if any soul left.

AVATAR
	);
	set_property("lore difficulty",0);
	set("dexbonus",-10);
	set("conbonus",-10);
	set("chabonus",-5);
	set_type("clothing");
	set_limbs(({ "right foot" }));
	set_size(1);
	set_property("enchantment",-1);
	set_ac(1);
}



