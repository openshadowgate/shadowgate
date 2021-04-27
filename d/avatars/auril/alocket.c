#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Aramel's locket");
	set_id(({ "locket" }));
	set_short("%^BOLD%^%^WHITE%^A silver heart locket%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A silver heart locket%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This locket is obviously of elven craftsmanship and the silver is of the highest quality. The locket is attached to a very thin silver linked chain. On the cover of the heart shaped locket a crescent moon is carved into the metal. When the locket is opened there is a tiny picture on one side and an inscription on the other side. The picture is of a sapphire eyed female elf and blue eyed male elf resting in the forest, bathed in the moonlight.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^The inscription reads: "%^BOLD%^%^YELLOW%^Just as the moon washes over the earth, so does your love over my heart.%^BOLD%^%^WHITE%^"%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(2000);
	set_lore(
@AVATAR
Given to Shrydelhi on her birthday by the ranger Aramel.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The necklace brings fond memories of the person who gave it to you.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Reluctantly you remove the locket.");
	return 1;
}
