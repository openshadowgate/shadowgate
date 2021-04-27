#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
	::create();
	set_name("robes of the warmage");
	set_id(({ "robes" }));
	set_short("%^YELLOW%^r%^RED%^o%^YELLOW%^b%^RED%^e%^YELLOW%^s%^RED%^ of the %^YELLOW%^w%^RED%^a%^YELLOW%^r%^RED%^m%^YELLOW%^a%^RED%^g%^YELLOW%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Blood red robes%^RESET%^");
	set_long("%^BOLD%^%^RED%^This robe has been dyed into a deep blood red crimson color. The robe looks heavy and is padded with extra layers of cloth for protection, but does not hinder the mobility. The robe is "
	"sleeveless so the wearer has quick access to weapons and spellcasting. Sewn into the folds of the robe are several large hidden pouches. A large scene has been sown onto the back of the robe, showing "
	"a large armored man riding with one leg on a %^YELLOW%^f%^RED%^ie%^YELLOW%^r%^RED%^y %^BOLD%^%^BLACK%^black stallion %^BOLD%^%^RED%^and the other on a %^WHITE%^gr%^MAGENTA%^a%^WHITE%^ci%^CYAN%^o%^WHIT"
	"E%^us white stallion%^BOLD%^%^RED%^. The background is a large sword with %^YELLOW%^f%^RED%^l%^YELLOW%^a%^RED%^m%^YELLOW%^e%^RED%^s %^BOLD%^%^RED%^engulfing it. The image has been sewn with %^WHITE%^s"
	"i%^BOLD%^%^BLACK%^l%^WHITE%^ver %^BOLD%^%^RED%^and %^YELLOW%^golden %^BOLD%^%^RED%^threads making the image seem almost alive.%^RESET%^
"	);
	set_value(3200);
	set_lore("%^BOLD%^%^RED%^Legends holds that these Robes of the Warmage belonged to a half-elf Wizard called%^RESET%^ %^BOLD%^%^MAGENTA%^'Drognaki Balshrun'. Droganki%^RESET%^ %^BOLD%^%^RED%^were one of the firs"
	"t%^RESET%^ %^CYAN%^mages%^RESET%^ %^BOLD%^%^RED%^seen fighting in the front-ranks in the battles of the First Crown wars. People never expected this half-elf to survive. But in the end he was one of t"
	"he few left standing. It is said that just before the last cataclysmic battle of the Crown Wars the knight called 'Red' appeared before Drognaki and bestowed the blessing of battle on his only armor ."
	".. these robes. 
It is unknown what happened to %^RESET%^ %^BOLD%^%^MAGENTA%^Drognaki%^RESET%^ %^BOLD%^%^RED%^after Crown Wars. But many ancient paintings has detailed a half-elf only dressed in these"
	" robes holding his own against a mass of enemies.%^RESET%^
"	);
	set_property("lore difficulty",25);
	set_size(2);
	set_property("enchantment",5);
}



