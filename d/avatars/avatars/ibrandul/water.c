#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^BOLD%^%^WHITE%^the %^RESET%^%^CYAN%^w%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^RESET%^%^BOLD%^%^BLUE%^e%^RESET%^%^CYAN%^r%^RESET%^%^BOLD%^%^WHITE%^ of %^RESET%^%^CYAN%^l%^RESET%^%^BOLD%^%^GREEN%^i%^RESET%^%^BOLD%^%^CYAN%^f%^RESET%^%^GREEN%^e%^RESET%^%^WHITE%^");
	set_id(({ "water", "water of life", "vial", "crystal vial" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^the %^RESET%^%^CYAN%^w%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t%^RESET%^%^BOLD%^%^BLUE%^e%^RESET%^%^CYAN%^r%^RESET%^%^BOLD%^%^WHITE%^ of %^RESET%^%^CYAN%^l%^RESET%^%^BOLD%^%^GREEN%^i%^RESET%^%^BOLD%^%^CYAN%^f%^RESET%^%^GREEN%^e%^RESET%^%^WHITE%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^cr%^RESET%^%^WHITE%^y%^RESET%^%^BOLD%^%^WHITE%^sta%^RESET%^%^WHITE%^l vial of %^RESET%^%^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^%^CYAN%^t%^RESET%^%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^r%^RESET%^%^WHITE%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^this %^RESET%^%^BOLD%^%^WHITE%^cr%^RESET%^%^BOLD%^%^BLACK%^y%^RESET%^%^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^t%^RESET%^%^BOLD%^%^WHITE%^al vial%^RESET%^%^CYAN%^, about the size of an apple, is closed by a small %^RESET%^%^ORANGE%^cork stopper%^RESET%^%^CYAN%^. The liquid held inside looks like %^RESET%^%^BOLD%^%^CYAN%^wat%^RESET%^%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^, flows like %^RESET%^%^BOLD%^%^CYAN%^wat%^RESET%^%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^, but if you smell it.. It smells like pure life. You remember suddenly every scent that reminds you of health. A %^RESET%^%^GREEN%^ve%^RESET%^%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^dant gro%^RESET%^%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^e%^RESET%^%^CYAN%^, a rainstorm in the %^RESET%^%^GREEN%^spring%^RESET%^%^CYAN%^, or a %^RESET%^%^ORANGE%^f%^RESET%^%^YELLOW%^r%^RESET%^%^ORANGE%^es%^RESET%^%^YELLOW%^h%^RESET%^%^ORANGE%^ly so%^RESET%^%^YELLOW%^w%^RESET%^%^ORANGE%^n field.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(5000);
}