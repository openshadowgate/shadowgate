#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	
	set_name("ruby ring");
	set_id(({"ring","ruby ring","bsbrubyring"}));
	
	set_short("%^RESET%^%^RED%^a flawless %^BOLD%^%^RED%^r%^RESET%^"+
	"%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^y b%^BOLD%^%^RED%^a"+
	"%^RESET%^%^RED%^n%^BOLD%^%^RED%^d%^RESET%^");
	
	set_long("%^BOLD%^%^WHITE%^This band appears to be cut from a "+
	"single, flawless %^RESET%^%^RED%^ru%^BOLD%^%^RED%^b%^RESET%^"+
	"%^RED%^y%^BOLD%^%^WHITE%^. %^BOLD%^%^RED%^F%^RESET%^%^RED%^"+
	"l%^MAGENTA%^a%^ORANGE%^m%^RED%^e%^BOLD%^%^RED%^s%^BOLD%^"+
	"%^WHITE%^ are %^RESET%^etched%^BOLD%^%^WHITE%^ around the "+
	"outside of the slender band, and they almost seem to %^BOLD%^"+
	"%^BLACK%^glow%^BOLD%^%^WHITE%^. The band is slightly warm to "+
	"the touch.%^RESET%^");
	
	set_weight(0);
	set_value(1000);
	
	set_lore("%^RESET%^While the purpose of this band is kept a "+
	"secret by those who sport one, it is occasionally seen worn "+
	"by some prominent and generally dangerous figures around the "+
	"realm.");
	set_property("lore difficulty",10);
	
	set_type("ring");
	set_limbs(({"right hand"}));
	set_size(2);
	set_property("enchantment",0);
	set_ac(0);
}
