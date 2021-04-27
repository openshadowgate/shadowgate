#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Head of a young man");
	set_id(({ "head" }));
	set_short("%^RED%^Head of a young man");
	set_obvious_short("%^RED%^Severed head");
	set_long(
@AVATAR
%^RED%^This is the head of a young man, severed from the middle of his neck. Blood still slowly oozes from it. It seems to have been severed with a serrated blade. A nail drivin into its forehead has a note attached to it.

AVATAR
	);
	set("read",
@AVATAR
%^RED%^The bloodly note says
%^RED%^Former alcoyte of Akadi, not the first, not the last.

AVATAR
	);
     set("langage","str");	set_weight(5);
	set_value(0);
}