#include <std.h>
inherit "/d/common/obj/armour/helm";

void create(){
	::create();
	set_name("helmetofthephoenix1");
	set_id(({ "helm", "helmet" }));
	set_short("%^YELLOW%^Helmet of the %^RED%^P%^YELLOW%^h%^RED%^o%^YELLOW%^e%^RED%^n%^YELLOW%^i%^RED%^x%^RESET%^");
	set_obvious_short("%^YELLOW%^Golden Helmet with a %^RED%^red %^RESET%^%^RED%^p%^BOLD%^%^RED%^l%^RESET%^%^RED%^u%^BOLD%^%^RED%^m%^RESET%^%^RED%^e%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This is a magnificent %^YELLOW%^golden%^WHITE%^ helmet with a large %^RED%^plume%^WHITE%^ of %^RED%^P%^YELLOW%^h%^RED%^o%^YELLOW%^e%^RED%^n%^YELLOW%^i%^RED%^x%^WHITE%^ feathers. The h"
        "elm is of a classic gothic style with a visor than can be raised and lowered to protect the face, and the inside of the helm is padded for comfort. The entire surface of the helmet is ornamented with "
	"%^RED%^P%^YELLOW%^h%^RED%^o%^YELLOW%^e%^RED%^n%^YELLOW%^i%^RED%^x%^YELLOW%^e%^RED%^s%^WHITE%^ in flight and %^MAGENTA%^a%^YELLOW%^s%^MAGENTA%^t%^YELLOW%^e%^MAGENTA%^r %^YELLOW%^b%^MAGENTA%^l%^YELLOW%^"
	"o%^MAGENTA%^ss%^MAGENTA%^o%^YELLOW%^m%^MAGENTA%^s%^WHITE%^ in bloom. All the small details are made with %^WHITE%^s%^BLACK%^i%^WHITE%^l%^BLACK%^v%^WHITE%^e%^BLACK%^r%^WHITE%^y thread and tiny bits of "
	"%^YELLOW%^sunstone%^WHITE%^ and %^RED%^rubies%^WHITE%^ which make the helm sparkle in the %^YELLOW%^light%^WHITE%^.%^RESET%^
"	);
	set_value(10000);
	set_lore("%^BOLD%^%^WHITE%^This is the helmet of the fabled Phoenix Knight, Sir Arionor of Lathander. He was a great knight and deeply devoted to Lathander. He was most reknown for killing the demon Lironoirlix"
	" and was granted this helm after the feat.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_size(2);
	set_property("enchantment",5);
}



