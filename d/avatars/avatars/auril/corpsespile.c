#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpses");
	set_id(({ "corpses" }));
	set_short("These are pieces of two bodies, almost unidentifiable. Various pieces of equipment are about, some you would know as Seraphen or Durias's if you have seen them before, if not, just random stuff.");
	set_obvious_short(".");
	set_long(
@AVATAR
q
q
q
~q
~q

~q

AVATAR
	);
