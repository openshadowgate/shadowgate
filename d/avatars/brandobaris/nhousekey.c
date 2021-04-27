#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("silver key");
	set_id(({ "key", "silver key", "silver and moonstone key" }));
	set_short("%^RESET%^%^BOLD%^a polished s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r and m%^RESET%^o%^BOLD%^%^CYAN%^o%^WHITE%^ns%^RESET%^t%^CYAN%^o%^BOLD%^n%^WHITE%^e key%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^a polished s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r and m%^RESET%^o%^BOLD%^%^CYAN%^o%^WHITE%^ns%^RESET%^t%^CYAN%^o%^BOLD%^n%^WHITE%^e key%^RESET%^");
	set_long("%^BOLD%^A small key of s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r, with a handle of p%^CYAN%^o%^WHITE%^l%^CYAN%^is%^WHITE%^h%^CYAN%^e%^WHITE%^d m%^CYAN%^oo%^WHITE%^ns%^RESET%^t%^BOLD%^%^CYAN%^o%^WHITE%^"
	"ne.%^RESET%^
"	);
	set_value(0);
	set_weight(0);
}
