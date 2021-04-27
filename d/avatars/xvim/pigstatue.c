#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Wooden pig statue");
	set_id(({ "statue" }));
	set_short("A wooden statue of a pig");
	set_obvious_short("A wooden statue of a pig");
	set_long(
@AVATAR
%^ORANGE%^The small statue, is about 1 foot high, and is made out of sandelwood, it is carved out of a single piece of wood, with great care for the details and has a nice soft polish making it smooth to the touch. The pig looks like a little happy fat pig, with a curly tail and big nose. its small feet rests on a small stand, with the name %^GREEN%^"Piggy"%^ORANGE%^ carved into the stand. On the buttom of the stand there is also carved the name of the Artist. %^BOLD%^%^WHITE%^A.A

AVATAR
	);
	set("read",
@AVATAR
%^WHITE%^Piggy, made by Ataar Applebean

AVATAR
	);
	set_weight(5);
	set_value(0);
	set_lore(
@AVATAR
Made by the famous wood crafter, Ataar Applebean

AVATAR
	);
}