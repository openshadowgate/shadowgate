#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("%^BOLD%^%^GREEN%^S%^RESET%^%^CYAN%^h%^BOLD%^%^GREEN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^f%^BOLD%^%^GREEN%^f%^YELLOW%^ Badge%^GREEN%^ o%^RESET%^%^CYAN%^f %^BOLD%^S%^RESET%^%^CYAN%^e%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^c%^RESET%^%^CYAN%^a%^RESET%^");
	set_id(({ "badge" }));
	set_short("%^BOLD%^%^GREEN%^S%^RESET%^%^CYAN%^h%^BOLD%^%^GREEN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^f%^BOLD%^%^GREEN%^f%^YELLOW%^ Badge%^GREEN%^ o%^RESET%^%^CYAN%^f %^BOLD%^S%^RESET%^%^CYAN%^e%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^c%^RESET%^%^CYAN%^a%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^S%^RESET%^%^CYAN%^h%^BOLD%^%^GREEN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^RESET%^%^CYAN%^f%^BOLD%^%^GREEN%^f%^YELLOW%^ Badge%^GREEN%^ o%^RESET%^%^CYAN%^f %^BOLD%^S%^RESET%^%^CYAN%^e%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^c%^RESET%^%^CYAN%^a%^RESET%^");
	set_long("%^YELLOW%^This is a golden badge of the office of %^CYAN%^Sheriff%^YELLOW%^ in the city of %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^c%^RESET%^%^CYAN%^a%^RESET%^.
");
	set_value(0);
	set_size(2);
	set_property("enchantment",0);
}



