#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^simple aged scroll%^RESET%^");
	set_id(({ "scroll", "aged scroll" }));
	set_short("%^BOLD%^%^MAGENTA%^S%^RED%^c%^MAGENTA%^r%^RED%^o%^MAGENTA%^l%^RED%^l%^RESET%^ of the %^RESET%^%^MAGENTA%^W%^BOLD%^%^BLACK%^%^o%^CYAN%^r%^RED%^d%^RESET%^");
	set_obvious_short("%^RESET%^aged scroll%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^At first glance, this seems to be some kind of old %^GREEN%^moldering%^CYAN%^ scroll commonplace in libraries everywhere. And yet, %^RESET%^%^MAGENTA%^deep in your %^BOLD%^%^BLACK%^min"
	"d's%^RESET%^%^CYAN%^ eye%^BOLD%^, you can tell that this scroll must hold some %^WHITE%^incalculable%^CYAN%^ power. It is a %^RED%^force%^CYAN%^ so terrible that it sends %^BLUE%^s%^RESET%^%^BLUE%^h%^"
	"BOLD%^o%^RESET%^%^BLUE%^c%^BOLD%^k%^RESET%^%^BLUE%^w%^BOLD%^a%^RESET%^%^BLUE%^v%^BOLD%^e%^RESET%^%^BLUE%^s %^BOLD%^%^CYAN%^of %^BLACK%^primordial fear%^CYAN%^ through the very air around it.%^RESET%^
"
	);
	set_value(1000000);
	set_weight(10);
	set_lore("%^BOLD%^%^RED%^This is a %^CYAN%^legendary%^RED%^ scroll of untold power. It holds a %^BLACK%^word%^CYAN%^ that if uttered, might %^GREEN%^unmake the very world%^CYAN%^. It was hidden away in a tomb g"
	"uarded by %^RED%^undead %^WHITE%^solar%^CYAN%^ who agreed to this sacrifice in order to resist the temptation to use the scroll. It is said that the %^RED%^scroll%^CYAN%^ calls to the living to corrup"
	"t their souls into uttering the word.%^RESET%^
"
	);
    set_property("lore difficulty",20);
}
