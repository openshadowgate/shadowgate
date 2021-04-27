#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("gloomfrost");
	set_id(({ "hammer" }));
	set_short("%^RESET%^%^BLUE%^Gl%^BOLD%^%^CYAN%^oo%^RESET%^%^BLUE%^mf%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^s%^BOLD%^%^CYAN%^t");
	set_obvious_short("An ice war hammer");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This beautifully carved hammer looks to be made from solid %^RESET%^%^WHITE%^i%^BOLD%^%^CYAN%^c%^RESET%^%^WHITE%^e%^BOLD%^%^CYAN%^. The head of the hammer has a %^BOLD%^%^YELLOW%^gold %^BOLD%^%^CYAN%^reienforced pommel and has small indentions within it, maximizing force. The handle is wrapped in a thin layer of cloth, which seems to have melded within the weapon giving you a very steady grip. Despite being almost entirely made of ice, the hammer is not that cold to the touch.%^RESET%^

AVATAR
	);
	set_weight(9);
	set_value(5000);
	set_lore(
@AVATAR
This was forged by the dwarf Teiral Stormhammer in the dwarven city of Kinaro almost 70 years ago. His personal weapon for many years, it won him many victories. About 30 years ago, however, the famed dwarf disappeared, as did his hammer, and was never heard from again.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" shivers slightly as they grip the handle.",ETO);
	tell_object(ETO,"%^BOLD%^%^BOLD%^%^CYAN%^Your hands feel slightly cold as you wield the weapon.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" smiles a little as they unwield the weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^BOLD%^%^CYAN%^Your hands feel slightly %^BOLD%^%^RED%^warmer %^BOLD%^%^CYAN%^as you release the weapon.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" grunts loudly as they smash into "+targ->QCN+" with the hammer violently.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A chill streaks into your body as you %^BOLD%^%^YELLOW%^SLAM %^BOLD%^%^CYAN%^into your opponent!");
	tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" grunts loudly as they smash into you with the hammer %^BOLD%^%^RED%^violently%^BOLD%^%^CYAN%^!");
		return roll_dice(3,4)+-2;	}
}