#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("flu mask");
	set_id(({ "mask", "flu mask", "flumask" }));
	set_short("%^BOLD%^%^WHITE%^flu mask with a %^MAGENTA%^piggy %^WHITE%^face%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^flu mask with a %^MAGENTA%^piggy %^WHITE%^face%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a paper-thin mask that can be worn over your mouth and nose (or snout) to protect you from infectious disease.  It ties around the back of the head.  It is the true opposite of fashionable, but at least it sports a cute %^MAGENTA%^piggy face %^WHITE%^in the center.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^Beware the swine flu.  Do not fight wereboars with anything less than a ten foot pole.  Made of silver.  Or magic.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(1);
	set_lore(
@AVATAR
%^CYAN%^Swine flu spread throughout the Realms during one very memorable season.  People blamed it on wereboars.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" looks silly when they put on the flu mask.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Sterile and loving it!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" laughs in the face of germ warfare and removes the mask!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You laugh in the face of germ warfare!%^RESET%^");
	return 1;
}

