#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed dog toy");
	set_id(({ "toy", "dog", "stuffed dog", "stuffed dog toy", "brown dog", "brown dog toy", "stuffed toy" }));
	set_short("%^RESET%^%^ORANGE%^a stuffed toy in the shape of a dog%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a stuffed toy in the shape of a dog%^RESET%^");
	set_long(
@AVATAR
Padded with plenty of soft cotton, this little stuffed animal is shaped like a %^RESET%^%^ORANGE%^dog%^WHITE%^. Durable %^RESET%^%^ORANGE%^brown%^RESET%^ and %^BOLD%^%^WHITE%^white %^RESET%^broadcloth has been used to make the body of this stuffed animal. Long floppy ears hang on either side of the head, while %^BOLD%^%^BLACK%^black buttons %^RESET%^have been used to make the nose, eyes and ears. A %^BOLD%^%^MAGENTA%^pink felt %^RESET%^tongue extends from the yarn sewn mouth and several %^BOLD%^%^WHITE%^white spots %^RESET%^have been sewn over the %^ORANGE%^brown body %^RESET%^adding contrast. 

AVATAR
	);
	set_weight(1);
	set_value(350);
}