#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("luck bracelet");
	set_id(({ "bracelet", "blue bracelet", "luck bracelet", "gemmed bracelet" }));
	set_short("%^BOLD%^%^CYAN%^Luck %^BLUE%^Bracelet%^RESET%^");
        set_obvious_short("%^BOLD%^%^CYAN%^g%^BLUE%^e%^CYAN%^m%^BLUE%^m%^CYAN%^e%^BLUE%^d %^CYAN%^bracelet%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This pretty little bracelet is made of a thin %^BOLD%^%^WHITE%^band of silver %^RESET%^%^CYAN%^set with an array of %^BOLD%^blue stones%^RESET%^%^CYAN%^.  Small oval-shaped %^BOLD%^%^BLUE%^sapp%^WHITE%^h%^BLUE%^ires%^RESET%^%^CYAN%^, %^BOLD%^azurites%^RESET%^%^CYAN%^, and aquamarines are fitted along with prongs of silver, and a tiny %^YELLOW%^lucky coin %^RESET%^%^CYAN%^hangs from the clasp.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^MAGENTA%^~ %^CYAN%^Luck be with you %^MAGENTA%^~%^RESET%^

AVATAR
	);
     set("langage","elven");	set_weight(1);
	set_value(95);
	set_lore(
@AVATAR
A common item of the Tymoran faith, these luck charms are sometimes given out to those faithful who go out adventuring.  The color of the stones is often chosen based on the member's preference, as judged by those who know him or her.

AVATAR
	);
	set_property("lore difficulty",2);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETOQCN+" slips on the "+query_short()+" and smiles.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You feel as if you are in for good luck as you slip on the "+query_short()+".%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^"+ETOQCN+" sighs quietly and slips off the "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You sigh quietly as you slip off the "+query_short()+".%^RESET%^");
	return 1;
}
