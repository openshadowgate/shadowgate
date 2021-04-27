#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("voldranlance");
	set_id(({ "lance" }));
	set_short("%^BOLD%^%^RED%^D%^BLACK%^e%^RED%^filer's L%^BLACK%^a%^RED%^nce%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A medium lance with a %^RED%^j%^BLACK%^a%^RED%^gged %^CYAN%^s%^BLACK%^t%^CYAN%^eel%^BLACK%^ point%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a medium horse lance standing a good 12 feet long. The %^CYAN%^s%^BLACK%^t%^CYAN%^eel%^BLACK%^ tip is %^RED%^j%^BLACK%^a%^RED%^gged%^BLACK%^ like it has been chipped against %^WHITE%^bone%^BLACK%^. It looks very sturdy and woe be to any hit by this weapon!%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^The %^CYAN%^cavalier%^BLACK%^ named Voldran once held this lance in battle. When adventuring in the town of Offestry, he discovered a %^GREEN%^c%^RESET%^%^MAGENTA%^o%^BOLD%^%^GREEN%^rrupted%^WHITE%^ gr%^BLACK%^a%^WHITE%^veyard%^BLACK%^. He explored a tomb, and upon trying to leave, he met a %^WHITE%^S%^BLACK%^k%^WHITE%^eletal K%^BLACK%^n%^WHITE%^ight%^BLACK%^ named Verdren. Voldran twice insulted the knight and then defeated him in single combat in the name of %^RED%^Bane%^BLACK%^. This lance gained some of the power of the %^WHITE%^defeated guardian.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("piercing");
	set_prof_type("lance");
	set_property("lance",1);
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",1);
}



