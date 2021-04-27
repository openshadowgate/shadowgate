#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("arm gems");
	set_id(({ "gems", "set of gems" }));
	set_short("%^BOLD%^%^RED%^A set of g%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^m%^MAGENTA%^s %^RED%^set directly into the forearms%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A set of g%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^m%^MAGENTA%^s %^RED%^set directly into the forearms%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This piece of art is a %^RESET%^%^RED%^gruesome %^YELLOW%^sight indeed.  A beautiful mosaic of %^RESET%^%^MAGENTA%^ame%^BOLD%^%^MAGENTA%^th%^RESET%^%^MAGENTA%^yst %^YELLOW%^and %^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x %^RESET%^%^CYAN%^stones %^YELLOW%^have been bored into the wearers forearms in pattern reminescent of a %^BOLD%^%^BLACK%^spider's web%^YELLOW%^.  It appears the stones were %^BOLD%^%^RED%^heated%^YELLOW%^, then set into the %^RESET%^%^ORANGE%^flesh %^YELLOW%^by %^BOLD%^%^BLUE%^force%^YELLOW%^.  The %^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x %^YELLOW%^forms the background on which the dark %^RESET%^%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst %^YELLOW%^stones rest.  The gems at the knuckles have been sharpened to an almost magical keeness.  Needless to say this one enjoys %^RESET%^%^RED%^pain%^RESET%^.  

AVATAR
	);
	set_weight(2);
	set_value(0);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "left hand", "right hand" }));
	set_size(2);
	set_property("enchantment",-1);
      set_property("death keep",1);
//added by Circe 5/3/05 because they were supposed to always stay
}


