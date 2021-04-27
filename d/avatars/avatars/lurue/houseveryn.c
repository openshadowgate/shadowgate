#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("finch statue");
	set_id(({ "statue", "finch statue", "idol", "brass idol" }));
	set_short("%^BOLD%^%^BLACK%^Id%^WHITE%^o%^BLACK%^l%^RESET%^ of %^BOLD%^%^BLACK%^H%^WHITE%^o%^BLACK%^use V%^WHITE%^e%^BLACK%^r%^RESET%^y%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^RESET%^a %^BOLD%^%^WHITE%^s%^BLACK%^i%^WHITE%^lv%^BLACK%^e%^WHITE%^r w%^BLACK%^i%^WHITE%^nged f%^BLACK%^i%^WHITE%^nch%^RESET%^ statue");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This little statue appears to be nothing more then a little %^WHITE%^s%^BLACK%^i%^WHITE%^lver h%^BLACK%^u%^WHITE%^ed %^CYAN%^finch.  Made from %^RESET%^%^ORANGE%^brass%^BOLD%^%^CYAN%^ and painted so the feathers are several shades of %^WHITE%^s%^BLACK%^i%^WHITE%^lver %^CYAN%^and %^BLACK%^g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y%^CYAN%^, it looks quite real, though is far too heavy to be an actual bird.  Only about three inches tall, tiny %^BLUE%^s%^RESET%^%^BLUE%^a%^CYAN%^p%^BOLD%^%^BLUE%^ph%^RESET%^%^BLUE%^i%^BOLD%^res %^CYAN%^have been inset for eyes, while the talons and the small beak looks like they might be made of %^YELLOW%^c%^RESET%^%^ORANGE%^i%^YELLOW%^tr%^RESET%^%^ORANGE%^i%^YELLOW%^ne%^CYAN%^.  It probably has a fair amount of value.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(550);
	set_lore(
@AVATAR
In many upper class circles the House of Veryn is not considered true nobility due to their family founder's birth status, but many of the common people of Laerad look up to them as a representation of what true nobility should be:  Lords who care for the welfare of their people.  This view caught the attention of a priest of Tymora back in 546 SG who, posing as a street beggar himself, was ministered to and aided by the House Veryn.  Their efforts to find him and other pauper's sufficient shelter and respectable work caused the priest to instill a gift from Tymora into a brass idol of a silver winged finch.  This he presented to the current patriarch, Suroife Veryn, when the priest revealed his true nature to the family.  Rumor holds that any who live under the roof where the idol rests will have Tymora's favor in all they do.

AVATAR
	);
	set_property("lore difficulty",22);
}