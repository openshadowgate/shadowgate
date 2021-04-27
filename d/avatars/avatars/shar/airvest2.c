#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("vest");
	set_id(({ "vest of the winds", "vest" }));
	set_short("%^BOLD%^%^BLACK%^Ve%^BLUE%^st%^WHITE%^ of %^BLUE%^th%^BLACK%^e W%^BLUE%^in%^WHITE%^ds%^RESET%^");
	set_obvious_short("A sky blue silken vest");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^A silken vest cut into a fashionable style.  The torso section of the vest is made from sky blue silk and fitted close to the body.  A high collor rises up from the neckline, though nothing to binding.  ELectrum buttons in the shape of birds alternate from the left to the right side, giving the vest a bit of added flare.  Strips of %^BLACK%^storm gray%^BLUE%^ and %^WHITE%^cloud white%^BLUE%^ silk has been twisted together to form a slight padded roll at each shoulder.  The ends of the silken fabric remain untethered and free to billow in the breeze.

AVATAR
	);
	set_weight(5);
	set_value(200);
	set_lore(
@AVATAR
The Vest of the Winds first arrived via the south and the Tsavarian Empire.  The lands to the south are rumored to be so tropical and warm that anyone in heavy clothing will find themselves dehydrated in a matter of hours.  Since it's arrivals into these lands, the vest has become a prized possesion of any Akadian.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" buttons up their silken vest",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You button up the silken vest.");
	ETO->add_stat_bonus("dexterity",1);
	ETO->add_stat_bonus("constitution",-1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" unbuttons their vest",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You unbutton the vest");
	ETO->add_stat_bonus("dexterity",-1);
	ETO->add_stat_bonus("constitution",1);
	return 1;
}
