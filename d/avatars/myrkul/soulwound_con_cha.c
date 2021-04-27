#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("soulwound");
	set_id(({ "wound", "soul wound" }));
	set_short("%^BOLD%^%^RED%^H%^RESET%^%^RED%^o%^BOLD%^rr%^RESET%^%^RED%^i%^BOLD%^ble %^WHITE%^S%^CYAN%^o%^WHITE%^ul%^RED%^ W%^RESET%^%^RED%^o%^BOLD%^und%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^H%^RESET%^%^RED%^o%^BOLD%^rr%^RESET%^%^RED%^i%^BOLD%^ble %^WHITE%^S%^CYAN%^o%^WHITE%^ul%^RED%^ W%^RESET%^%^RED%^o%^BOLD%^und%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^You feel %^RED%^terrible%^BLACK%^, as if afflicted with some %^GREEN%^disease%^BLACK%^ without a name. Your body seems almost %^CYAN%^translucent%^BLACK%^ like some permanent substance has somehow been removed from you. You %^RESET%^%^MAGENTA%^suffer%^BOLD%^%^BLACK%^ from %^YELLOW%^malaise%^BLACK%^, as if your life has lost its purpose and the very act of drawing breath is a chore. %^RED%^Fevers%^BLACK%^ wrack your body, while %^MAGENTA%^hallucinations%^BLACK%^ and %^YELLOW%^m%^RED%^a%^WHITE%^d%^GREEN%^n%^RESET%^%^ORANGE%^e%^BOLD%^MAGENTA%^s%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^ wracks your brain.


Some creature has stolen some vital piece of your %^WHITE%^s%^CYAN%^o%^WHITE%^ul%^BLACK%^ and you must get it back!!%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^You feel you know who has your soul. It is a creature who has gotten hold over you through your very own evil actions --- the %^RESET%^%^MAGENTA%^demonic%^BOLD%^%^RED%^ Sin Eater%^BLACK%^ of the dead god Myrkul. You feel some connection to the beast, you can _feel_ its %^RESET%^%^MAGENTA%^vileness%^BOLD%^%^BLACK%^.

%^BOLD%^%^BLACK%^You feel as if it has a grip on you through your very %^RED%^sins%^BLACK%^ and %^RESET%^%^MAGENTA%^darkest desires%^BOLD%^%^BLACK%^...  %^BOLD%^%^BLACK%^Part of your %^WHITE%^s%^CYAN%^o%^WHITE%^ul%^BLACK%^ was taken through: %^RED%^wrath,%^GREEN%^ greed,%^RESET%^%^GREEN%^ and envy.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
	set("conbonus",-10);
	set("chabonus",-10);
	set_type("clothing");
	set_limbs(({ "right foot" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
}



