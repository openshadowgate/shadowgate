#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Sunrise Pourpoint");
	set_id(({ "sunrise pourpoint armour", "armour", "sunrise armour", "pourpoint armour" }));
	set_short("%^RESET%^%^MAGENTA%^Su%^RED%^nri%^BOLD%^%^RED%^se Po%^YELLOW%^urpo%^BOLD%^%^RED%^int A%^RESET%^%^RED%^rmo%^MAGENTA%^ur%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^Sunrise Armour%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^This is a suit of leather armour that has been studded with an assortment of enamelled metal studs.  The studs have been coloured in a variety of shades of rose, red and yellow and they have been secured to the leather in a particular pattern that forms a stylized image of a sunrise.%^RESET%^

AVATAR
	);
	set_weight(25);
	set_value(1500);
	set_lore(
@AVATAR
%^Magenta%^The image depicted on the armour is one that can be found in any number of Lathanderite temples across the realm.  Whilst no longer common, this style of armour was once very popular with members of Lathander's church.  The stylized image was copied from a famous peice of artwork commissioned by the church that depicted Lathander himself in a suit of armour with a sunrise emblazoned upon it which was formed of rose-quartz, rubies, topaz and diamonds.%^RESET%^

AVATAR
	);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^MAGENTA%^You feel a warm inner glow as you put the armour on.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^MAGENTA%^You check that none of the enamelled studs has been chipped after you remove the armour.%^RESET%^");
	return 1;
}
