#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^BOLD%^%^RED%^A met%^RESET%^%^RED%^al%^BOLD%^%^RED%^lic red vial%^RESET%^");
	set_id(({ "vial", "metallic vial" }));
	set_short("%^BOLD%^%^RED%^A metallic red vial%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A metallic red vial%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This is a shining red vial, tightly kept closed with a %^RESET%^%^ORANGE%^cork%^BOLD%^%^RED%^ stopper. It %^RESET%^%^MAGENTA%^vibrates%^BOLD%^%^RED%^ strangly, as if whatever is trapped inside is trying to escape. It is slightly %^RESET%^%^RED%^warm %^BOLD%^to the touch. There seems to be a small %^RESET%^inscription%^BOLD%^%^RED%^ etched into the metal.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^MAGENTA%^She who's heart is %^RED%^true %^MAGENTA%^and %^RED%^pure%^MAGENTA%^ will be complete once more, once released this %^RED%^light%^MAGENTA%^ within the body's healing can begin.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(100);
	set_type("bludgeoning");
	set_prof_type("clublike");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",0);
	set_ac(0);
}


