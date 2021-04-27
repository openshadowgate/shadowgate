#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^MAGENTA%^gem shard%^RESET%^");
	set_id(({ "gem", "shard", "shard of gem" }));
	set_short("%^MAGENTA%^gem shard%^RESET%^");
	set_obvious_short("%^MAGENTA%^gem shard%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^A gem shard, softly glowing. It is no larger then a grain of rice%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}