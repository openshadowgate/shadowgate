#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("blue necklace");
	set_id(({ "necklace", "pendant", "jewelry", "chain", "silver chain" }));
	set_short("%^BOLD%^%^WHITE%^a s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r necklace with a %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^lu%^BOLD%^%^BLUE%^e %^RESET%^%^BLUE%^p%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^nda%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^t%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^A %^RESET%^pale %^BOLD%^%^BLUE%^blue%^BOLD%^%^WHITE%^, oval-shaped pendant is attached to a %^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r cha%^RESET%^i%^BOLD%^n. Small chips of %^"
	"BOLD%^%^BLACK%^ivory%^BOLD%^%^WHITE%^ have been inlaid within the pendant, forming the image of a %^RESET%^white dove%^BOLD%^%^WHITE%^. The pendant is attached to a simple %^RESET%^s%^BOLD%^%^WHITE%^i"
	"%^BLACK%^lv%^BOLD%^%^WHITE%^e%^RESET%^r chain%^BOLD%^%^WHITE%^, its delicate links interlocking. While pretty, the necklace appears to be a bit %^RESET%^worn%^BOLD%^%^WHITE%^, some s%^RESET%^c%^BOLD%^"
	"%^WHITE%^rat%^RESET%^ch%^BOLD%^%^WHITE%^es apparent across the surface of the pendant.%^RESET%^
"
	);
	set_value(10);
	set_weight(1);
	set_lore("%^BOLD%^%^WHITE%^The white dove was the signet of a wealthy family by the same name, Dove, which once held influence in the Daggerdale reaches. Little else is remembered of the family.%^RESET%^
");
    set_property("lore difficulty",35);
}
