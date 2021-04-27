#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Javelin Trophy");
	set_id(({ "trophy", "prize" }));
	set_short("%^YELLOW%^Javelin %^WHITE%^T%^YELLOW%^ro%^RED%^p%^YELLOW%^hy%^RESET%^");
	set_obvious_short("%^YELLOW%^Javelin %^WHITE%^T%^YELLOW%^ro%^RED%^p%^YELLOW%^hy%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is an impressive trophy made primarily from %^YELLOW%^gold%^RESET%^%^ORANGE%^.  The figure rests atop a stand of rich %^RED%^mahogany wood%^ORANGE%^.  The polished golden figure represents a male soldier in his physical prime.  The soldier is wearing centurion armor in a style from another age, decorated with flakes of %^RED%^ruby%^ORANGE%^ on the plume of his helm and %^BLUE%^sapphire%^ORANGE%^ embedded in his breastplate.  The golden warrior is posed with one leg on the wooden stand, preparing to launch a javelin into the air.  The javelin in his hand stands out from the rest of the trophy as it is made from %^BOLD%^%^WHITE%^pure platinum%^RESET%^%^ORANGE%^, wound with %^BOLD%^%^WHITE%^white %^YELLOW%^g%^WHITE%^old%^RESET%^%^ORANGE%^.  A small engraved plaque has been affixed to the wooden base, you could read it.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Champion, Javelin Throw!%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(2300);
}
