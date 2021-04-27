#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("aged amulet");
	set_id(({ "amulet", "aged amulet", "swansglide" }));
	set_short("%^BOLD%^%^BLACK%^s%^RESET%^w%^BOLD%^%^WHITE%^a%^BLACK%^nsg%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^de%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^g%^ORANGE%^e%^BOLD%^%^BLACK%^d a%^RESET%^%^GREEN%^m%^ORANGE%^u%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is a curious bobble that appears to have been created out of cast off bits and pieces.  It begins with a thin loop of chain, one side made of %^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^g%^ORANGE%^e%^BOLD%^%^BLACK%^d b%^RESET%^%^GREEN%^r%^ORANGE%^a%^BOLD%^%^BLACK%^ss %^RESET%^and the other of %^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^x%^RESET%^i%^ORANGE%^di%^BOLD%^%^BLACK%^z%^RESET%^%^GREEN%^e%^ORANGE%^d c%^BOLD%^%^BLACK%^o%^RESET%^p%^ORANGE%^p%^GREEN%^e%^ORANGE%^r%^RESET%^, with a third smaller looped chain of tarnished %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^ver %^RESET%^circling off one side.  These chains join at the back with a simple hook and eye clasp and end at a silvery piece of shaped metal.  Abstract, the metal has flowing ribbons of molted metal that give it a look of a bird gliding upon the water.  Different treatments have been applied to the metal, giving it a %^BOLD%^%^BLACK%^b%^BLUE%^l%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck%^BLUE%^i%^BLACK%^sh-b%^BLUE%^l%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^e %^RESET%^gleam upon the bird and a more %^BOLD%^%^BLUE%^m%^RESET%^%^BLUE%^et%^CYAN%^a%^BLUE%^l%^BOLD%^lic b%^RESET%^%^BLUE%^l%^CYAN%^u%^BOLD%^%^BLUE%^e %^RESET%^to the water.  Other portions above the bird's head have been left in their natural silver tone to create the sky.  The amulet tilts at an odd angle with one chain hooking into the tail feathers of the bird and the other into the sky.  Hanging from the base a tiny %^BOLD%^%^BLACK%^black feather %^RESET%^can be seen.

AVATAR
	);
	set_weight(2);
	set_value(6000);
	set_lore(
@AVATAR
Because of the high cost of metals and precious gems, jewelers have always had a tendency to use every scrap, cast off and broken chain.  When molds fail, chains break and other mistakes happen, the bits are set aside and eventually cobbled together by apprentices or, sometimes, even masters of the craft.  Though made from cast off remains, the items are often amazing in their uniqueness and an occasional few come out so stunning that they are considered masterworks because of their flaws.  This piece, created after too hot of metal was poured into a wax mold was created by a master jeweler from Tharis, the motif of a bird gliding on the water was popular during the mid sixth century.  

AVATAR
	);
	set_property("lore difficulty",13);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The tiny %^BLACK%^black feather %^WHITE%^flutters as you place the %^RESET%^"+query_short()+" %^BOLD%^%^WHITE%^about your neck.%^RESET%^");
	ETO->set_property("magic resistance",3);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The tiny %^BLACK%^black feather%^WHITE%^ grows still as you remove your %^RESET%^"+query_short()+"%^BOLD%^%^WHITE%^.%^RESET%^");
	ETO->set_property("magic resistance",-3);
	return 1;
}

