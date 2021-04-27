#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BOLD%^%^RED%^heart%^RESET%^");
	set_id(({ "heart", "human heart" }));
	set_short("%^BOLD%^%^RED%^h%^RESET%^%^RED%^u%^BOLD%^m%^RESET%^%^RED%^a%^BOLD%^n h%^RESET%^%^MAGENTA%^e%^BOLD%^%^RED%^a%^RESET%^%^MAGENTA%^r%^BOLD%^%^RED%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^h%^RESET%^%^RED%^u%^BOLD%^m%^RESET%^%^RED%^a%^BOLD%^n h%^RESET%^%^MAGENTA%^e%^BOLD%^%^RED%^a%^RESET%^%^MAGENTA%^r%^BOLD%^%^RED%^t%^RESET%^");
	set_long("%^BOLD%^%^RED%^This is a human heart, a little over the size of a clenched fist. It is still beating, and while no blood is pumped, it looks and feels slick to the touch. The very fact it is still ali"
	"ve is %^CYAN%^miraculous%^RED%^ and clearly some great work of %^YELLOW%^faith%^RED%^ or %^MAGENTA%^art%^RED%^ has made it so.%^RESET%^ 
"
	);
	set_value(10000);
	set_weight(0);
