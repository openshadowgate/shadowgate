#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Lovely Silver Brooch");
	set_id(({ "brooch" }));
	set_short("%^BOLD%^%^WHITE%^Lovely silver brooch");
	set_obvious_short("A wonderfully crafted brooch");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This is a lovely %^WHITE%^s%^BLUE%^il%^BOLD%^%^WHITE%^v%^BLUE%^e%^BOLD%^%^WHITE%^r %^BOLD%^%^GREEN%^brooch with a large %^BOLD%^%^RED%^d%^CYAN%^i%^BOLD%^%^RED%^a%^CYAN%^m%^BOLD%^%^RED%^o%^CYAN%^n%^BOLD%^%^RED%^d %^BOLD%^%^GREEN%^set in the center of it. Around the %^BOLD%^%^RED%^d%^CYAN%^i%^BOLD%^%^RED%^a%^CYAN%^m%^BOLD%^%^RED%^o%^CYAN%^n%^BOLD%^%^RED%^d %^BOLD%^%^GREEN%^is a small message enscribed in %^YELLOW%^gold %^BOLD%^%^GREEN%^lettering around the %^BOLD%^%^RED%^d%^CYAN%^i%^BOLD%^%^RED%^a%^CYAN%^m%^BOLD%^%^RED%^o%^CYAN%^n%^BOLD%^%^RED%^d%^BOLD%^%^GREEN%^, you should beable to read it. The message begins and ends with a small %^BOLD%^%^RED%^ruby %^BOLD%^%^GREEN%^set at each end. The brooch is obviously ment to pin a cloak together, and is marvelously crafted.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^BLUE%^You read the finely engraved letters in %^YELLOW%^gold%^BOLD%^%^BLUE%^.
%^YELLOW%^Until the end we stand together, and the beauty within you shall shine for all to see. I will always love you, and you me.

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(7000);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^YELLOW%^"+ETO->query_cap_name()+" carefully pins together her cloak with the %^BOLD%^%^WHITE%^"+query_short()+"%^YELLOW%^.",TP);
	tell_object(TP,"%^YELLOW%^You carefully pin together your cloak with the %^BOLD%^%^WHITE%^"+query_short()+"%^YELLOW%^.");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^YELLOW%^As "+ETO->query_cap_name()+" removes her %^BOLD%^%^WHITE%^"+query_short()+" %^YELLOW%^her cloaks opens slightly as nothing holds it together anymore.",TP);
	tell_object(TP,"%^YELLOW%^Removing the %^BOLD%^%^WHITE%^"+query_short()+" %^YELLOW%^your cloak opens slightly as nothing holds it together anymore.");
	return 1;
}
