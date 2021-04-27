#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("silverbark and maple guitar");
	set_id(({ "guitar", "silverbark guitar", "silverbark and maple guitar" }));
	set_short("%^BOLD%^%^BLUE%^a %^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^RESET%^e%^WHITE%^%^BOLD%^r%^BLACK%^b%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^k %^BLUE%^and %^RESET%^%^ORANGE%^m%^RED%^a%^ORANGE%^p%^RED%^l%^ORANGE%^e %^BOLD%^%^BLUE%^guitar%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a %^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^RESET%^e%^WHITE%^%^BOLD%^r%^BLACK%^b%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^k %^BLUE%^and %^RESET%^%^ORANGE%^m%^RED%^a%^ORANGE%^p%^RED%^l%^ORANGE%^e %^BOLD%^%^BLUE%^guitar%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This guitar is a showpiece of craftsmanship. It's solid top is made of %^WHITE%^burled silverbark %^BLUE%^with colors ranging from dark slate gray to %^WHITE%^silvery white %^BLUE%^playing across the surface. The lonestar-shaped tone hole is outlined with %^BLACK%^b%^CYAN%^o%^BLUE%^u%^BLACK%^ld%^GREEN%^e%^BLACK%^r o%^CYAN%^p%^BLACK%^al %^BLUE%^with flashes of %^CYAN%^bl%^GREEN%^ue%^BLUE%^-%^GREEN%^gre%^CYAN%^en %^BLUE%^visible in the dark matrix. The pick guard is made of the same opal. The body and sides of the guitar are %^RESET%^%^ORANGE%^maple %^BOLD%^%^BLUE%^for good round tones. The fretboard is of %^BLACK%^ebony %^BLUE%^with %^WHITE%^silver %^BLUE%^frets. Star-shaped fret inlays of %^BLACK%^b%^CYAN%^o%^BLUE%^u%^BLACK%^ld%^GREEN%^e%^BLACK%^r o%^CYAN%^p%^BLACK%^al %^BLUE%^tie the neck of the guitar in with the top to make a truly beautiful instrument. On the base of the neck is a tiny silver plate upon which is a stylized scroll containing a capital %^RESET%^%^MAGENTA%^M.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
Crafted by the artisan Molara, this guitar was jeweled and enhanced as a gift for her friend Wick.  Though unenchanted, a gift of friendship often comes with its own brand of magic. 

AVATAR
	);
	set_property("lore difficulty",12);
	set("chabonus",1);
}

int is_instrument(){return 1;}