#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bracelet of superiority");
	set_id(({ "bracelet", "glass bracelet", "gold bracelet", "bracelet of superiority" }));
	set_short("%^RESET%^%^RED%^Bracelet of Superiority%^RESET%^");
	set_obvious_short("%^BOLD%^%^YELLOW%^Gold %^BLACK%^and %^CYAN%^Glass %^BLACK%^Bracelet%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^Glass bubbles filled with a warm %^BOLD%^liquid %^RESET%^%^RED%^make up this bracelet.  Gold %^YELLOW%^filigree %^RESET%^%^RED%^is scripted around the bubbles reinforcing the glass and making it stronger.  The script mingles with the swirling %^BOLD%^%^RED%^liquid %^RESET%^%^RED%^inside making it look like it is alive.  Along the inside is an inscription.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Worn together your mind will flood, warm to the touch is this elven blood%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(1000);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
}


