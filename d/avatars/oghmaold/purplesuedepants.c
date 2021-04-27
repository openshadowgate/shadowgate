#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("suede pants");
	set_id(({ "pants", "purple pants", "purple suede pants" }));
	set_short("%^RESET%^%^WHITE%^A pair of %^RESET%^%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p p%^BOLD%^u%^RESET%^%^MAGENTA%^rple %^RESET%^suede pants");
	set_obvious_short("%^RESET%^%^WHITE%^A pair of %^RESET%^%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p p%^BOLD%^u%^RESET%^%^MAGENTA%^rple %^RESET%^suede pants");
	set_long(
@AVATAR
%^RESET%^These pants are made of a high quality suede died a deep, rich %^RESET%^%^MAGENTA%^purple%^RESET%^.  Traditional, shiny %^BOLD%^%^YELLOW%^brass buttons %^RESET%^run up the crotch to keep them on the wearer.  The supple, soft %^RESET%^%^ORANGE%^suede %^RESET%^is the calilbre of what nobles would wear, and the color adds to that effect.  They are styled in a slightly loose fashion to allow the freedom of movement of the wearers.

AVATAR
	);
        set_weight(2);
	set_value(200);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "left leg", "right leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" slips on the suede pants and looks quite pleased with them.",ETO);
        tell_object(ETO,"You slip on the suede pants and marvel at their soft feeling.");
        ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" seems less radiant as they remove the suede pants.",ETO);
        tell_object(ETO,"You languish in your removal of the suede pants.  You never looked better!");
        ETO->add_stat_bonus("charisma",-1);
	return 1;
}
