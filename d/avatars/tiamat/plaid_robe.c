#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("plaid robe");
	set_id(({ "robe", "robes", "mage robes", "mage robe", "plaid robe", "plaid robes" }));
	set_short("%^RESET%^%^RED%^P%^BOLD%^l%^YELLOW%^a%^RED%^i%^RESET%^%^RED%^d Mage Robe%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^p%^BOLD%^l%^YELLOW%^a%^RED%^i%^RESET%^%^RED%^d robe%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^RED%^This is a long robe woven into a durable, if slightly itchy tweed in a colorful and mature p%^BOLD%^l%^YELLOW%^a%^RED%^i%^RESET%^%^RED%^d design.  The inseam is made of soft cotton dyed a %^BOLD%^deep scarlet %^RESET%^%^RED%^color.  The robe is worn over the shoulders and is closed by small %^ORANGE%^brass %^RED%^buttons that have a bit of tarnish.  Pockets are carefully hidden in the seams, allowing you to keep things inside the robes.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(15);
	set_lore(
@AVATAR
Mage robes are common among magic users of all kind.  Some wizards prefer to steer away from the traditional black and white robes because of the message they feel this conveys about their natures.  Some time ago a small coterie of wizards and witches began to design robes they felt were more stylish and individualized.  The plaid mage robes are a favorite among wizards that teach magic in the towers.

AVATAR
	);
	set_property("lore difficulty",5);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" wears a p%^BOLD%^l%^YELLOW%^a%^RED%^i%^RESET%^%^RED%^d robe%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^You don the colorful p%^BOLD%^l%^YELLOW%^a%^RED%^i%^RESET%^%^RED%^d robe%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETOQCN+" looks less nerdy without the p%^BOLD%^l%^YELLOW%^a%^RED%^i%^RESET%^%^RED%^d robe%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^You remove your robe.%^RESET%^");
	return 1;
}
