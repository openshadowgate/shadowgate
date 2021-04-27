#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("corpse");
	set_id(({ "corpse", "eaten corpse", "humanoid corpse" }));
	set_short("%^RESET%^%^RED%^a h%^BOLD%^a%^BLACK%^l%^RESET%^%^RED%^f-e%^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^e%^RESET%^%^RED%^n h%^ORANGE%^u%^RED%^m%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^n%^WHITE%^o%^ORANGE%^i%^RED%^d c%^ORANGE%^o%^WHITE%^r%^ORANGE%^p%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^e%^WHITE%^");
	set_long("%^RED%^This unfortunate soul looks to have been the victim of some gruesome %^BOLD%^%^GREEN%^murder%^RESET%^%^RED%^. His clothes torn to shreds and with a look of panicked %^BOLD%^%^BLACK%^dread %^RES"
	"ET%^%^RED%^frozen on his face, he bears large, j%^BOLD%^%^WHITE%^a%^RESET%^%^RED%^g%^WHITE%^g%^ORANGE%^e%^RED%^d gashes all over his body, and the flesh beneath seems to have been ripped clean off. St"
	"range gouges mark much of the body's exposed bone...gouges you eventually recognize as %^BOLD%^%^WHITE%^teeth marks%^RESET%^%^RED%^.%^WHITE%^
"	);
	set_value(0);
	set_weight(100);
}
