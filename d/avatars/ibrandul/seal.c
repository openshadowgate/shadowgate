#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^a seal%^RESET%^");
	set_id(({ "seal" }));
	set_short("%^RESET%^%^ORANGE%^seal%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^seal%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^this small wooden seal is decoraded sparsley, and when it impacts it leaves a very intricate design of a bloodied dagger%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}