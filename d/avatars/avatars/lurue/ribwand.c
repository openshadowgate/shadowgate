#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("rust colored rib bone");
	set_id(({ "rib bone", "ribbone", "wand" }));
	set_short("%^RED%^rusty colored rib bone%^RESET%^");
	set_obvious_short("%^RED%^rusty colored rib bone%^RESET%^");
	set_long(
@AVATAR
%^RED%^This rib bone looks like its been soaked in blood!  Strangely, under the rusty sheath of dried blood, you can see odd %^BLUE%^r%^CYAN%^u%^MAGENTA%^n%^BLUE%^e%^CYAN%^s%^RED%^ that seem to pulse and writhe under your gaze, refusing to form into anything that your mind can lock onto.  The only sense you can make of it, is that of a dragon in motion, but that can't be right can it?%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
}
