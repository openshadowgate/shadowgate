#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("thin needle");
	set_id(({ "needle" }));
	set_short("%^RESET%^%^ORANGE%^stitcher%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a very fine sharp needle%^RESET%^");
	set_long(
@AVATAR

%^RESET%^%^ORANGE%^This long, slender needle has perhaps the finest of points you've ever seen.  The tip tapers down and down and down beyond your sight it is so fine.  It could likely sew almost anything, though you doubt that it would be of much use to stitch fabric since there is no eyehole for thread to pass through.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(100);
	set_lore(
@AVATAR
%^RESET%^%^ORANGE%^There is something about this needle that seems important, but nothing comes to mind immediately.  Perhaps further research or study is needed.  Although, you can almost hear a nursery rhyme in your head as you look the needle over. %^RESET%^

%^YELLOW%^Sew and stitch
%^YELLOW%^Stitch and sew
%^YELLOW%^Mary's the thread
%^YELLOW%^That binds them so
%^RESET%^


AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("needle");
	set_size(1);
	set_wc(1,1);
	set_large_wc(1,1);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" looks down at the %^RESET%^"+query_short()+"%^YELLOW%^ as though they just realized something.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel you hold something incredibly powerful, yet, you're certain that you'll only break this needle if you try to use it as a weapon!%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" seems to relax a little as they put the %^RESET%^"+query_short()+"%^YELLOW%^ aside.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^Its probably for the best, you wouldn't want to break something that special.%^RESET%^");
	return 1;
}

