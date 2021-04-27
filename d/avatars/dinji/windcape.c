#include <std.h>
inherit ARMOUR;
void create(){
	::create();
	set_name("windrunner's cape");
	set_id(({"cape","blue cape","wind cape","windrunner's cape"}));
        set_obvious_short("%^BOLD%^%^CYAN%^light blue cape%^RESET%^");
	set_short("%^BOLD%^%^CYAN%^Windrunner's C%^BOLD%^%^YELLOW%^a%^BOLD%^%^CYAN%^pe%^RESET%^");
	set_long("This cape is long and flowing. Its made from silk"+
	" that has been dyed light blue. The collar of the cape"+
	" is trimmed in a thicker, darker, blue silk. There is a little"+
	" gold chain fitted onto the collar, used to secure the cape"+
	" around the wearer's neck.");
	set_property("lore",19);
	set_lore("Who made this cape is unknown, but it was worn by"+
	" Saliene the Wind Walker on one her visits to Prime Material"+
	" Plane many years ago. She left the cape with her very good friend"+
	" Lariel, as a parting gift.");
	set_type("clothing");
	set_limbs(({"neck"}));
	set_size(2);
	set_weight(5);
	set_value(2000);
     set_property("enchantment",3);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel a bit swifter all of a sudden%^RESET%^.");
	ETO->add_attack_bonus(2);
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel a bit heavy all of a sudden%^RESET%^.");
	ETO->add_attack_bonus(-2);
	return 1;
}
