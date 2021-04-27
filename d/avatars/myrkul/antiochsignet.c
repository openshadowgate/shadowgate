#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("%^RESET%^%^MAGENTA%^s%^CYAN%^i%^MAGENTA%^g%^CYAN%^n%^MAGENTA%^e%^CYAN%^t%^YELLOW%^ ring%^RESET%^%^MAGENTA%^ of %^YELLOW%^Antioch%^RESET%^");
	set_id(({ "ring", "signet ring" }));
	set_short("%^RESET%^%^MAGENTA%^S%^CYAN%^i%^MAGENTA%^g%^CYAN%^n%^MAGENTA%^e%^CYAN%^t%^YELLOW%^ ring%^RESET%^%^MAGENTA%^ o%^CYAN%^f %^YELLOW%^Antioch%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^s%^CYAN%^i%^MAGENTA%^g%^CYAN%^n%^MAGENTA%^e%^CYAN%^t%^YELLOW%^ ring%^RESET%^");
	set_long("%^BOLD%^%^GREEN%^This is a beautiful %^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ng%^GREEN%^ made of the purest %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^GREEN%^. It bears an %^RESET%^%^MAGENTA%^i%^CY"
	"AN%^n%^MAGENTA%^s%^CYAN%^i%^MAGENTA%^g%^CYAN%^n%^MAGENTA%^i%^CYAN%^a%^BOLD%^%^GREEN%^ of nobility:%^CYAN%^ A beautiful %^RESET%^w%^BOLD%^%^WHITE%^h%^RESET%^i%^BOLD%^%^WHITE%^t%^RESET%^e%^BOLD%^%^WHITE"
	"%^ p%^RESET%^e%^BOLD%^%^WHITE%^g%^RESET%^a%^BOLD%^%^WHITE%^s%^RESET%^u%^BOLD%^%^WHITE%^s%^CYAN%^ stands sideways on a field of %^RESET%^%^MAGENTA%^royal purple.%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^BOLD%^%^CYAN%^This %^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ng%^CYAN%^ is one of three matching rings bequeathed to %^WHITE%^three worthies%^CYAN%^ for saving %^YELLOW%^Antioch%^CYAN%^ from a horde "
	"of %^BLACK%^C%^WHITE%^y%^BLACK%^rists%^CYAN%^ including a %^BLACK%^b%^WHITE%^l%^BLACK%^ack d%^WHITE%^r%^BLACK%^ag%^WHITE%^o%^BLACK%^n%^CYAN%^. One ring went to %^BLUE%^Saradin%^CYAN%^, who was made th"
	"e %^BLUE%^Pirate Knight%^CYAN%^. One ring went to %^MAGENTA%^Marie%^CYAN%^, who was made the %^MAGENTA%^Bard of the Crown%^CYAN%^. And one ring went to %^RESET%^%^CYAN%^Aashaenael%^BOLD%^%^CYAN%^, who"
	" was made %^RESET%^%^CYAN%^Forester of the Crown%^BOLD%^%^CYAN%^. All this happened under the %^WHITE%^reign%^CYAN%^ of %^WHITE%^King Caelith%^CYAN%^ of the Kingdom of Antioch.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_skill_bonus("influence",3);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	ETO->add_skill_bonus("influence",-3);
	return 1;
}

