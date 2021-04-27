#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("badge");
	set_id(({ "badge", "bitch badge" }));
	set_short("%^BOLD%^%^MAGENTA%^The %^RED%^Bitch%^MAGENTA%^ Badge%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^MAGENTA%^Congrats!  You have been named bitch by (insert whiner's name).  The title of Bitch is not something to be feared or loathed over.  It means you are one of the rare few women who stand up and won't back down, even more so when you are right :).  Wear this badge in pride, as you have earned it.  And just remember, if they think you were being a bitch before, it can get worse %^RED%^Bwahahahahahaha%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
The Bitch Badge was made by Shar to give to those immortals who have been branded bitch by whiners, dmf, or idiots in an attempt to wound her with the title.  Just goes to show you how dumb they are, because there is nothing wrong with being a bitch!

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",45);
	set_ac(300);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETOQCN+" pins on a pretty badge",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You pin the badge on and can't help but feel proud to be a %^RED%^bitch%^RESET%^");
	ETO->add_stat_bonus("wisdom",1);
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" unpins a pretty badge",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You take off the %^RED%^bitch badge%^MAGENTA%^ but know that the secrets of bitchdom are still locked away in your mind.");
	ETO->add_stat_bonus("wisdom",-1);
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
