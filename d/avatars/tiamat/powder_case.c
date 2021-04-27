#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("powder case");
	set_id(({ "powder", "case", "powder case" }));
	set_short("%^BOLD%^%^WHITE%^silver case containing %^MAGENTA%^fine powder%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^silver case containing %^MAGENTA%^fine powder%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a small silver chest, finely decorated and ornamental in nature.  It even has a tiny, unlockable hinge on its face.  %^MAGENTA%^S%^GREEN%^e%^YELLOW%^m%^BLUE%^i %^WHITE%^precious stones form rows along the right angles of the case.  Contained within is a %^MAGENTA%^loose, fine powder%^WHITE%^ as well as a tiny pad to apply it.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1100);
}