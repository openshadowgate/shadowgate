#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("smithing hammer");
	set_id(({ "hammer", "smithy's hammer" }));
	set_short("%^RESET%^A %^BOLD%^%^BLUE%^sturdy %^BOLD%^%^BLACK%^iron smithy's hammer %^RESET%^with an %^RESET%^%^RED%^oak handle%^RESET%^");
	set_obvious_short("%^RESET%^A %^BOLD%^%^BLUE%^sturdy %^BOLD%^%^BLACK%^iron smithy's hammer %^RESET%^with an %^RESET%^%^RED%^oak handle%^RESET%^");
	set_long(
@AVATAR
This is a sturdy little smithy's hammer.  The %^BOLD%^%^BLACK%^iron %^RESET%^head is about five inches long and two inches thick and has been forged with a flat facing on one side and a round ball peen on the other.  The handle is carved out of stout %^RESET%^%^RED%^red oak %^RESET%^and is a little over a foot long.  A %^BOLD%^%^RED%^heavy %^RESET%^%^ORANGE%^leather grip %^RESET%^has been fastened midshaft on the handle to allow for a firmer grip.  Though this hammer might provide some defense in combat its true purpose is shaping metal.

AVATAR
	);
	set_weight(4);
	set_value(200);
	set_property("lore difficulty",0);
	set_type("bludgeoning");
	set_prof_type("small hammer");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",0);
}


