#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("red dragon");
	set_id(({ "sword", "red dragon", "red dragon sword", "weapon" }));
	set_short("An %^RESET%^%^RED%^or%^BOLD%^%^WHITE%^nat%^RESET%^%^RED%^e %^RESET%^long sword");
	set_obvious_short("%^BOLD%^%^RED%^Sraveliegn, the red dragon%^RESET%^");
	set_long(
@AVATAR
This ornately crafted long sword is in near perfect condition. The %^BOLD%^%^WHITE%^adamantite %^RESET%^blade has a %^BOLD%^%^RED%^glowing red %^RESET%^hue about it, tracing up the razor sharp edges. The hilt of the blade looks to be two %^BOLD%^%^RED%^dragon %^RESET%^claws sitting apart from one another in a clutched grip. The handle of the blade is made of a set of flat %^BOLD%^%^RED%^rubies %^RESET%^that are layered in such a way to seem like you are gripping the scales of a dragon. The heavy pommel is made of dense %^BOLD%^%^BLACK%^volcanic %^RESET%^rock, shaped into a eerily dark sphere.

AVATAR
	);
	set_weight(14);
	set_value(10000);
	set_lore(
@AVATAR
Crafted by the great Artificer, Carcascus, the dragon blades were a tribute to the fourth King of Asgard, Stararach, nearly six centuries ago. The swords were rumored to have the power to control dragons of a specific type as well as slay them. After the collapse of the kings reign, Stararach's precious weapons were lost to history.

AVATAR
	);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,12);
	set_large_wc(1,8);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+" lowers his head slightly as the weapon is wielded and "+ETOQCN+"'s pupils glow %^BOLD%^%^RED%^red%^RESET%^ for a moment.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The rage of millenium fills your heart but quickly fades, leaving the quiet but ever-present lust for wealth and power in your mind.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" struggles to unwield the weapon but finally succeeds.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Grudgingly you free the sword of your grip. The lust leaves your mind, though you remember the taste.");
	return 1;
}
