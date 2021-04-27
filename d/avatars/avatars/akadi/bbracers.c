#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("gemmed bracers");
	set_id(({ "bracers", "gemmed bracers", "silver bracers" }));
	set_short("%^BOLD%^%^BLUE%^B%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e %^BOLD%^%^CYAN%^G%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^-%^BOLD%^%^CYAN%^En%^BOLD%^%^BLUE%^c%^BOLD%^%^CYAN%^ru%^BOLD%^%^BLUE%^s%^BOLD%^%^CYAN%^ted %^BOLD%^%^WHITE%^Bra%^RESET%^%^CYAN%^c%^BOLD%^%^WHITE%^ers%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^m%^RESET%^m%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^WHITE%^g %^RESET%^s%^BOLD%^%^BLACK%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^RESET%^er %^BOLD%^%^BLACK%^b%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^s%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^The surface of the sparkling s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r bracers is encrusted with small, circular gems, which have been sized to fit perfectly between small links of the shining, flawless metal. Consisting of milky o%^RESET%^%^CYAN%^p%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^s, %^RESET%^crystal q%^BLUE%^u%^RESET%^artz, %^GREEN%^tur%^BOLD%^%^GREEN%^q%^BOLD%^%^BLUE%^u%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^ise%^BOLD%^%^WHITE%^ and %^BOLD%^%^BLUE%^sa%^CYAN%^p%^RESET%^%^CYAN%^phi%^BOLD%^%^CYAN%^r%^BLUE%^es%^BOLD%^%^WHITE%^, the armor gives off a magnificent shimmer. The inside of the bracers have been lined with %^BOLD%^%^BLUE%^pale blue%^BOLD%^%^WHITE%^ velvet for comfort.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^Crafted by Akadi%^RESET%^

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("bracer");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",5);
	set_ac(5);
}


