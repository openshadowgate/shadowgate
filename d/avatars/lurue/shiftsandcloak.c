#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shell pendant");
	set_id(({ "pendant", "cloak", "clasp", "clasp of the shifting sands" }));
	set_short("%^RESET%^%^CYAN%^Clasp of the %^RED%^Shi%^ORANGE%^fti%^BOLD%^%^BLUE%^ng Sa%^CYAN%^nds%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^BLACK%^pearl %^RESET%^%^CYAN%^and %^ORANGE%^oyster shell %^CYAN%^pendant%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^A half moon shard of polished %^ORANGE%^oyster shell %^CYAN%^hangs from a thin %^BOLD%^%^WHITE%^mithril chain%^RESET%^%^CYAN%^.  The pendant's shape is such that the curves of the half moon nearly touch their points together.  Only the tiniest of space between the curves of oyster shell remains open.  Hanging within the center of that opening, a perfect %^BOLD%^%^BLACK%^black pearl %^RESET%^%^CYAN%^can be seen.  Tiny mithril links bind it to the center of the oyster shell, allowing it to swing freely and shed a fine, %^RED%^mu%^ORANGE%^lti%^BOLD%^%^BLUE%^hu%^CYAN%^ed %^RESET%^%^CYAN%^sand.  The dust sifts down to the point where the shell nearly closes and then vanishes, causing you to wonder just what is going on with this pendant.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_lore(
@AVATAR
When Captain Escuoso sailed from his war torn home to seek aid from foreign ports, his beautiful wife gifted him with a protective necklace much like this one.  Though there are only rumors as to what it does exactly, it is said that Escuoso's wife offered a prayer to each of the elemental deities, asking that they grant her husband their gifts.  In answer to such earnest prayers the gods sent four things to her, a shell for water, a lustrous pearl for fire, a fine mithril chain for earth and finally an ever shifting wind.  Each of these she collected up and formed into a necklace to give her husband telling him he had but to set his %^RED%^will%^RESET%^ to one element or another and they would aid him.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(1);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" sets the "+query_short()+" %^BOLD%^%^WHITE%^about their neck, a flowing cloak of shifting sands flows out from the mithril links.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^As the pendant settles around your neck, the %^RESET%^%^RED%^fi%^ORANGE%^ne %^BOLD%^%^BLUE%^du%^CYAN%^st %^WHITE%^pours out of its small hole and swirls up around you, following the line of mithril and shimmering down about your shoulders into an ever shifting cloak!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" undoes the clasp of their "+query_short()+" %^BOLD%^%^WHITE%^causing the cloak of sand to scatter apart and drift away.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You undo the clasp and the fine sands of the cloak fall apart and drift away in the air.%^RESET%^");
	return 1;
}

