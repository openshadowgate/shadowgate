#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("disembodied eye");
	set_id(({ "eye" }));
	set_short("%^BOLD%^%^RED%^d%^BOLD%^%^WHITE%^isem%^BOLD%^%^GREEN%^bod%^BOLD%^%^WHITE%^ied ey%^BOLD%^%^RED%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This white orb stares blankly at nothing, and was seemingly delicately, but brutally removed from it's previous owner.  The %^BOLD%^%^RED%^nerves %^BOLD%^%^WHITE%^at the back of the orb dangle and still drip blood, while the %^BOLD%^%^GREEN%^emerald green iris %^BOLD%^%^WHITE%^is obvious around the %^BOLD%^%^BLACK%^pupil.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
}