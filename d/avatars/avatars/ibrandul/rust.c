#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^rust%^RESET%^");
	set_id(({ "rust", "pile" }));
	set_short("%^RED%^pile of dust%^RESET%^");
	set_obvious_short("%^RED%^pile of rust%^RESET%^");
	set_long(
@AVATAR
%^RED%^This is a small pile of a mixture of %^ORANGE%^sand%^RED%^ and rust. It is sharp and would cause quite the infection%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
%^RED%^this dust is odd, but you've heard stories about an assassin, a once human who sold his soul and life to dark powers in exchange for power. His entire existance and legend was about the power he had, yet it was a power of corruption. The dust that covered him was caustic, and any blow by his weapons could eventually kill the victim from blood poisoning. He was reputed to be hired as an assassin to the daggerdale thieves guild after the departure of Vethor%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
}