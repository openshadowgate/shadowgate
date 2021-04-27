#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Silver Flute");
	set_id(({ "flute", "platinum flute" }));
	set_short("%^BOLD%^%^WHITE%^Pl%^YELLOW%^a%^WHITE%^ti%^YELLOW%^n%^WHITE%^um %^YELLOW%^F%^WHITE%^lute%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a solid platinum flute handcrafted with meticulous care and attention to detail.  It has been decorated with solid gold %^YELLOW%^t%^WHITE%^on%^YELLOW%^e%^WHITE%^ho%^YELLOW%^l%^WHITE%^es, %^YELLOW%^mechanism%^WHITE%^ and li%^YELLOW%^p-pla%^WHITE%^te.  The drawn toneholes are seamlessly sculpted from the flute's body providing a quick, flexible response amd a rich, resonant timbre.  Delicate, ornamental engraving on the lip-plate, crown and rings finish this elegant and refined instrument.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(2000);
	set_lore(
@AVATAR
%^YELLOW%^This is a very finely crafted flute, made from the highest quality materials.  On close inspection it bears a clear yet subtle makers mark that is incorporated into the engraving on the gold lip-plate.  The mark indicates that this instrument was made by 'Serlio' a well established and well respected maker of a variety of musical instruments.

AVATAR
	);
}