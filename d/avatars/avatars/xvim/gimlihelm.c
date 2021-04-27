#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^WHITE%^Skull of Kraklor%^RESET%^");
	set_id(({ "helm", " skull", " skull helmet", " skull helm" }));
	set_short("%^WHITE%^Skull of Kraklor%^RESET%^");
	set_obvious_short("%^WHITE%^A glossy white Frost giant skull%^RESET%^");
	set_long(
@AVATAR
%^WHITE%^This is the skull of a %^CYAN%^Frost Giant%^WHITE%^. The eye sockets are filled by magnificent %^RED%^rubies%^WHITE%^ that glow with a inner %^YELLOW%^f%^RED%^i%^YELLOW%^r%^RED%^e.%^WHITE%^ The crown of the skull is lines with small spikes made of %^CYAN%^Admantium%^WHITE%^. The lower and upper portions of the jaw and teeth are also plated with this rare metal. The lower jaw hangs open as if the beast still roars and acts as protection for the face and neck.%^RESET%^

AVATAR
	);
	set_weight(18);
	set_value(200);
	set_lore(
@AVATAR
Gimli killed a huge frost giant and nows wears its skull

AVATAR
	);
	set_type("armor");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^CYAN%^As "+ETO->query_cap_name()+" %^CYAN%^wears the helm a mournful vail fills the room, sending goosebumps down your neck%^RESET%^",TP);
	tell_object(TP,"%^CYAN%^As you wear the helm a mournful vail fills the room, sending goosebumps down your neck%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^CYAN%^As "+ETO->query_cap_name()+" %^CYAN%^ removes the helmet, one last roar from the giant is heard%^RESET%^",TP);
	tell_object(TP,"%^CYAN%^As you remove the helmet, one last roar from the giant is heard%^RESET%^");
	return 1;
}
