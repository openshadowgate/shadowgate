#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Mithril Tattooing Needle");
	set_id(({ "needle", "tattoo needle", "tattooing needle" }));
	set_short("Mithril Tattooing Needle");
	set_obvious_short("Mithril Tattooing Needle");
	set_long(
@AVATAR
This is a simle tatooing needle made from mithril.  Its size is larger than that of a sewing needle and it has a reservoir  in which to hold ink.

AVATAR
	);
	set_weight(1);
	set_value(0);
}