#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^RED%^tunic%^RESET%^");
	set_id(({ "robe" }));
	set_short("%^BOLD%^%^RED%^T%^RESET%^%^RED%^u%^BOLD%^n%^RESET%^%^RED%^i%^BOLD%^c%^RESET%^ of the %^BOLD%^%^RED%^S%^RESET%^%^RED%^q%^BOLD%^u%^RESET%^%^RED%^i%^BOLD%^r%^RESET%^%^RED%^e%^RESET%^ of the %^BOLD%^%^GREEN%^Eastern Reaches%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^S%^RESET%^%^RED%^q%^BOLD%^u%^RESET%^%^RED%^i%^BOLD%^r%^RESET%^%^RED%^e%^BOLD%^s %^RESET%^%^RED%^T%^BOLD%^u%^RESET%^%^RED%^n%^BOLD%^i%^RESET%^%^RED%^c%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a squires tunic bearing the heraldry of a %^RED%^fire-breathing serpent%^CYAN%^ over a %^GREEN%^crossed axe and sword%^CYAN%^ -- the mark of eastern Daggerdale nobility. It is a simple slip on top which falls to the hips, with very beautiful embroidery. This garb is the mark of a %^BOLD%^%^RED%^Squire%^CYAN%^ aspiring to be a knight.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1000);
	set_lore(
@AVATAR
This is the mark of the Squire of Lady Shalla, the Red Knight of the Eastern Reaches of Dagger. She has never had a successful squire before, as she rigorously follows the code of Knights. It was given to Sir Tryren who aspires to become an Antipaladin under her tutelage.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(1);
}



