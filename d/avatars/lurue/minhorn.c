#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("minotaur horn");
	set_id(({ "horn", "minotaur horn" }));
	set_short("%^RESET%^%^ORANGE%^minotaur horn%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^minotaur horn%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This appears to be a horn off of some large bull like creature.  Perhaps even the fabled minotaur.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}