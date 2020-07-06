// A mirror [meant as a target for the magic mirror spell]
// Place this in mage towers, and other places of magical
// artifice.
// Thorn@ShadowGate
// 010103
// mirror.c

#include <std.h>

inherit OBJECT;

create() {
	::create();
	set_name("portable scrying mirror");
	set_id(({
		"mirror", "fine mirror", "scrying mirror", "portable mirror", "portable scrying mirror"
	}));
	set_short("a portable scrying mirror");
	set_property("no animate", 1);
	set_long("This is a rather plain, but finely made mirror.  The reflective surface appears to be silver polished to an incredible lustre.  The surface is large and with the stout frame, this mirror looks to weigh quite a bit, and is even bulkier than it is heavy.");
	set_value(10000);
	set_weight(100000);
	set_no_clean(1);
}

int is_scrying_mirror()
{
	return 1;
}
