#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "band", "silver band" }));
	set_short("%^BOLD%^%^WHITE%^A silver band%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This simple silver band has been crafted out of the purest silver metal ever seen.  The silver glitters and shines with a brilliant cast, always looking new and fresh.  The metal has been polished smooth, giving it a soft finish.  On the inside of the band there are two images carved.  One of a cloud and the other of a crescent moon.

AVATAR
	);
	set_weight(2);
	set_value(20);
	set_lore(
@AVATAR
This is the Silver Band of memories, it is gifted to someone to recall someone special from their past.'

AVATAR
	);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you slip on the ring, for a moment you think you can hear a %^BLUE%^familiar%^WHITE%^ laughter mixed with a familiar lute melody.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You remove the band, but just can't get that laughter or that melody out of your head, it seems to remind you of someone.");
	return 1;
}
