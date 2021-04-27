#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a lost boy");
	set_id(({ "boy", " child", " lost child", " lost boy" }));
	set_short("boy");
	set_obvious_short("%^BOLD%^%^MAGENTA%^lost boy%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^Before you shivers a boy-child, frightened and disoriented.  Claw marks on the soft, smooth cheek of his face indicate he was attacked by something...well unhuman.  Bruises cover his neck and arms.  His ribs poke through the shirt covered in mud, blood and feces.  His wild eyes reflect a tormented spirit that has seen too much.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(0);
}