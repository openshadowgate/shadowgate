#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("soulbottle");
	set_id(({ "bottle", "soul bottle", "soulbottle" }));
	set_short("%^BOLD%^%^CYAN%^s%^RED%^o%^CYAN%^ul%^BLUE%^b%^CYAN%^ott%^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^sinister %^ORANGE%^bottle%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This wine bottle has a slightly %^BOLD%^%^GREEN%^greenish tint%^RESET%^%^ORANGE%^ and looks fairly normal. It has no label on it, and has a kind of cork stopper. Nevertheless, you f"
	"eel a sensation of %^MAGENTA%^sinister intent%^ORANGE%^ emanating from the bottle. You feel if you removed the stopper, something %^BOLD%^%^RED%^terrible would happen.%^RESET%^
"
	);
	set_value(0);
	set_weight(0);
	set_lore("%^BOLD%^%^CYAN%^These bottles are ancient tools of %^BLACK%^necromancers%^CYAN%^ used to trap %^WHITE%^souls%^CYAN%^. The %^RESET%^%^MAGENTA%^mystical design%^BOLD%^%^CYAN%^ of such bottles closely re"
	"sembles the famous tools that summoners used to trap %^BLUE%^elementals and djinn%^CYAN%^. However, these bottles are not used for protection, but rather as ultimate %^BLACK%^weapons%^CYAN%^. It canno"
	"t be used against a foe who can resist. But against the unconscious or bound enemies, they can be used to trap souls for %^RED%^evil purposes.%^RESET%^
"
	);
    set_property("lore difficulty",15);
}
