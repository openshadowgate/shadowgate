#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Quill");
	set_id(({ "quill", " feather", " feather quill" }));
	set_short("%^RESET%^%^CYAN%^A Feather Quill%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a long, pale blue feather.  It has been trimmed to a delicately blunted point to create a decorative writing implement.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(2);
	set_lore(
@AVATAR
%^RESET%^This is a feather quill, those with the skill can use these to write with.

AVATAR
	);
	set_property("lore difficulty",0);
}