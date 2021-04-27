#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("crown");
	set_id(({ "crown", "velsharoon crown", "velsharoons crown" }));
	set_short("%^BOLD%^%^WHITE%^Velsharoon's %^RESET%^%^ORANGE%^C%^BLUE%^r%^ORANGE%^o%^BLUE%^w%^ORANGE%^n%^RESET%^");
	set_obvious_short("%^ORANGE%^sp%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d %^BOLD%^golden%^RESET%^%^ORANGE%^ crown%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This once regal %^YELLOW%^crown%^WHITE%^ appears as if it would've once graced a humble king's head. Now it is pitted and %^BLACK%^aged%^WHITE%^ and sits upon a %^GREEN%^giant%^WHITE%^ sk%^RESET%^u%^BOLD%^ll. The crown itself practically %^CYAN%^h%^MAGENTA%^u%^CYAN%^m%^MAGENTA%^s%^WHITE%^ with untold power.

AVATAR
	);
	set_weight(10);
	set_value(0);
	set("intbonus",1);
	set("wisbonus",1);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(2);
}



