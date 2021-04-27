#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("vest of shadows");
	set_id(({ "clothing", "vest", "jacket", "robe" }));
	set_short("%^BOLD%^%^BLACK%^Tenebrous V%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^st%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^fine dark v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^st%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a finely crafted vest tailored from several layers of silk and velvet.  Most of the material has been dyed deepest black, with no evidence of fading regardless of use.  The vest is worn over the shoulders and buttoned along the front by %^RESET%^si%^BOLD%^l%^RESET%^ver %^BOLD%^%^BLACK%^buttons capped with highly polished h%^WHITE%^e%^BLACK%^mat%^WHITE%^i%^BLACK%^te.  An elegant %^RESET%^%^MAGENTA%^rich purple%^BOLD%^%^BLACK%^ trim has been applied around the edge of the vest, and along a tiny decorative p%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^cket near the breast.  As you inspect the vest carefully, you realize that the inner lining is not made of a natural saysubstance, but %^RESET%^e%^BOLD%^b%^BLACK%^b%^RESET%^s%^BOLD%^%^BLACK%^ and f%^RESET%^l%^BOLD%^o%^BLACK%^ws like underwater shadow.  You consider the possibility of reaching inside.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(1800);
	set_lore(
@AVATAR
The Tenebrous Vest is said to be the creation of a monster born long ago.  When the creature needed help gaining his own immortality, he crafted several powerful items like the vest for his allies.  The vest is said to be partially woven from matter from another dimension, a world composed entirely of shadows.  Its magic and protective value is strong, in addition to providing a means to hide secrets.

AVATAR
	);
	set_property("lore difficulty",15);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^As "+ETOQCN+" wears the vest, they shiver.",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel the shadowy material chill you down to your soul.");
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^As "+ETOQCN+" removes the vest, they look warmer and more alive.",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel warmer as soon as the vest is removed.");
	ETO->set_property("magic resistance",-5);
	return 1;
}

