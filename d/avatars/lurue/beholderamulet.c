#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("amulet");
	set_id(({ "amulet", "watchful eye", "eyestalk", "eye stalk" }));
	set_short("%^RESET%^%^RED%^w%^GREEN%^a%^RED%^tch%^WHITE%^f%^RED%^ul e%^GREEN%^y%^RED%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^an e%^RESET%^y%^RED%^es%^GREEN%^t%^RED%^al%^RESET%^k %^RED%^with a shriveled e%^GREEN%^y%^RED%^e%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^RED%^This rather foul piece of jewelry is made from the withered remains of a beholder's e%^GREEN%^y%^RED%^est%^RESET%^a%^RED%^lk.  Ripped from the head of the beast and cut down the center, the two pieces have been knotted in the back, while the %^GREEN%^eye %^RED%^itself was left untouched.  Though shriveled, the %^GREEN%^g%^BOLD%^r%^RESET%^e%^GREEN%^en%^RESET%^i%^GREEN%^sh %^RED%^colored eye still leaks a %^RESET%^g%^RED%^o%^BOLD%^o%^RESET%^ey p%^RED%^u%^RESET%^ss %^RED%^from one corner and the smell emitting from the thing would make even the strongest of stomachs roll.  Reddish-brown, the leathery stalk has thankfully been hollowed out so that what touches the neck is simply a rubbery stretch of skin.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(100);
	set_lore(
@AVATAR
Beholders have many powers and abilities which make them frightful opponents.  These powers are believed to be housed within the eyes themselves and it is a common practice among many wizards and power seekers to harvest these stalks and attempt to capture that innate power.  Some claim that the procedure of tanning the stocks but not the eyes allows the power to remain trapped within the orb and thus, a strong willed person could command it to do something.  Others claim that the eye will do as it wishes, if the power even exists within it.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You shudder as you place the preserved remains of a beholder's eyestalk about your neck.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You peel the remains of a beholder's eyestalk from your body and sigh with relief that its no longer touching your skin.%^RESET%^");
	return 1;
}

