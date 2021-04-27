#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("helm");
	set_id(({ "twilight helm", "helm", "twilight" }));
	set_short("%^RESET%^%^BLUE%^Helm of %^BLUE%^Tw%^MAGENTA%^il%^WHITE%^i%^MAGENTA%^gh%^BLUE%^t ");
	set_obvious_short("a helm");
	set_long(
@AVATAR
%^RESET%^%^BLUE%^A helm made of a lightweight blue hued metal.  Etched into the metal of the helm is tiny stars that are filled with %^BOLD%^%^WHITE%^silver%^RESET%^%^BLUE%^.  The top of the helm features a relief made of silver of a crescent moon.  A midnight blue feathered plume juts out of the top of the relief.  It is not uncommon to see a warrior of a high enough station to be given the honor of wearing a plume.  The outer edges of the graceful helm is trimmed in %^BOLD%^%^WHITE%^molten silver%^RESET%^%^BLUE%^.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^The stars seem to spell out something.
%^CYAN%^%^BOLD%^Invoke my name, and those pure of heart and mind shall call upon the raidance of the moon to aid them.%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(6);
	set_value(250);
	set_lore(
@AVATAR
The Helm of Twilight is seen as a blessing from Selune herself to those worthy mortals.  Though the wearers of these helms have met with tragic fates, and many populate the lands, it is said only those pure of heart and mind might invoke the blessing that is carried with these helms.

AVATAR
	);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}
