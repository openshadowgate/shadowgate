#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("gold trimmed veil");
	set_id(({ "gold trimmed veil", "gold veil", "veil" }));
	set_short("%^BOLD%^%^WHITE%^A %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld %^WHITE%^tr%^BLACK%^i%^WHITE%^mmed %^CYAN%^azure %^YELLOW%^ve%^WHITE%^i%^YELLOW%^l%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld %^WHITE%^tr%^BLACK%^i%^WHITE%^mmed %^CYAN%^azure %^YELLOW%^ve%^WHITE%^i%^YELLOW%^l%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This %^BOLD%^%^WHITE%^stunning %^RESET%^%^CYAN%^peice of %^CYAN%^fashion appears to take the modesty of the veil and turned it on its head. Silken fabric that %^BOLD%^%^BLACK%^s%^CYAN"
	"%^h%^BLACK%^i%^CYAN%^m%^BLACK%^m%^CYAN%^e%^BLACK%^r%^CYAN%^s %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^shines %^RESET%^%^CYAN%^like %^BLUE%^water %^WHITE%^rippling %^CYAN%^in %^YELLOW%^sunlight %^RESET%^%"
	"^CYAN%^is transparent just enough to hint at the sculpture of the face beneath while still hiding it. A narrow oval has been cut out, each edge just past the eyes of the woman beneath on either side a"
	"nd just enough to hint at the bridge of her nose and eyebrows, the edges trimmed with ornamental %^YELLOW%^gold %^RESET%^%^CYAN%^thread in the pattern of %^GREEN%^vines %^CYAN%^and %^RED%^r%^BOLD%^%^R"
	"ED%^o%^RESET%^%^RED%^ses%^CYAN%^, each %^RED%^rose %^CYAN%^highlighted with a single small %^BOLD%^%^RED%^ruby %^RESET%^%^CYAN%^gem. The narrow oval slit drawing attention to the eyes beneath the garm"
	"ent in an alluring fashion. A circlet hugs the veil to her face comfortably, and that is there the garment ends, allowing hair to spill out in any fashion she desires, the upper fringes lined with the"
	" same %^YELLOW%^golden %^RESET%^%^GREEN%^vines %^CYAN%^and %^BOLD%^%^RED%^ruby %^RESET%^%^RED%^roses%^CYAN%^. Ending just past her chin the fabric follows her jawline and stopping just beyond her ears"
	".%^RESET%^
"	);
	set_value(8000);
	set_size(2);
	set_property("enchantment",1);
}



