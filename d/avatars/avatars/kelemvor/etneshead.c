#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("etneshead");
	set_id(({ "head" }));
	set_short("The %^RED%^bloody%^RESET%^ head of a male elf");
	set_obvious_short("The %^RED%^bloody%^RESET%^ head of a male elf");
	set_long(
@AVATAR
This is the head of a male elf, his hazel eyes are wide open in a haunting death gaze and messy strands of thick black hair hang everywhere chaoticly. Gore oozes messily out of the base where it was severed from the body, causing a lingering smell of death to hang in the air.

AVATAR
	);
	set_weight(10);
	set_value(0);
}