#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("button");
	set_id(({ "button", "little button" }));
	set_short("%^BOLD%^%^BLACK%^a special button%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a little button%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^BLACK%^This little button is smooth to the touch due to the enamel coating the covers it.  Under the clear glaze you can make out a odd, smiling %^RESET%^face%^BOLD%^%^BLACK%^.  One that looks like it's %^RESET%^%^MAGENTA%^winking %^BOLD%^%^BLACK%^or %^RESET%^%^RED%^smirking %^BOLD%^%^BLACK%^with knowledge that no one else has.  The features are a bit %^RESET%^rough%^BOLD%^%^BLACK%^, and there is just something slightly %^BLUE%^sinister %^BLACK%^about his appearance, but otherwise it seems like just your average button, worn on a lapel or cloak to keep it closed.%^RESET%^


AVATAR
	);
	set("read",
@AVATAR

%^RESET%^%^BLUE%^I completed that -damn- quest
%^RESET%^%^BLUE%^   And all I got for it
%^RESET%^%^BLUE%^  Was this lousy button!%^RESET%^


AVATAR
	);
     set("langage","undercommon");	set_weight(0);
	set_value(0);
	set_lore(
@AVATAR
It's just a little button.  Isn't it?  Maybe if you came across it legit, you'd know the truth.  Now all you have is speculation.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Just a little too late, but at least it holds your cloak closed.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^But it doesn't want to let go, it likes it here.. over your %^RESET%^%^RED%^heart%^BOLD%^%^BLUE%^.%^RESET%^");
	return 1;
}

