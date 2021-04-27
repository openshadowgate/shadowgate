#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^CYAN%^Azure runes%^RESET%^");
	set_id(({ "tattoo", "runes", "rune", "body runes" }));
	set_short("%^BOLD%^%^CYAN%^Az%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e body r%^BOLD%^un%^WHITE%^e%^RESET%^%^CYAN%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^Az%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e body r%^BOLD%^un%^WHITE%^e%^RESET%^%^CYAN%^s%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This is a series of intricate runes somehow glowing just under the skin.  The runes %^BOLD%^pu%^WHITE%^ls%^RESET%^%^CYAN%^e and g%^BOLD%^l%^WHITE%^o%^RESET%^%^CYAN%^w occasionally as though possessing some kind of their own intelligence.  Although the runes share some symbols with the Common alphabet, the language or meaning of them seems ancient and foreign.  This individual wears the runes along parts of their upper arms, torso, and creeping up the neck.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^MAGENTA%^You can make no sense of the symbols, but feel their divine origin.%^RESET%^

AVATAR
	);
	set("langage","common");	
	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
According to some of the scholars that have studied the rebirth of Anhur, these runes appear on the Warhawk's Chosen.  If one could decipher the words, they would have the capacity to bring life to the god.  Only two mortals are known to have worn the runes: Ahrwah the Warhawk and Othos the Dwarven champion of Anhur.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^CYAN%^The runes on Othos %^BOLD%^gl%^WHITE%^o%^RESET%^%^CYAN%^w with life!",ETO);
	tell_object(ETO,"%^CYAN%^The body runes %^BOLD%^da%^WHITE%^nc%^CYAN%^e %^RESET%^%^CYAN%^with life!");
	ETO->set_property("magic resistance",8);
	set_overallStatus(100);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BLUE%^The runes on "+ETOQCN+" grow dull and fade away.",ETO);
	tell_object(ETO,"%^BLUE%^The runes on your body grow dull and lifeless.");
	ETO->set_property("magic resistance",-8);
	return 1;
}

