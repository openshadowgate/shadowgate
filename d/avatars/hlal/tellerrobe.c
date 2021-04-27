#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
	::create();
	set_name("lusterous robe");
	set_id(({ "robe", "lusterous robe", "a lusterous robe" }));
	set_short("%^BOLD%^%^RED%^A %^RESET%^%^RED%^lu%^BOLD%^%^RED%^st%^WHITE%^e%^RED%^ro%^RESET%^%^RED%^us %^BOLD%^%^RED%^robe%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A %^RESET%^%^RED%^lu%^BOLD%^%^RED%^st%^WHITE%^e%^RED%^ro%^RESET%^%^RED%^us %^BOLD%^%^RED%^robe%^RESET%^");
	set_long("%^BOLD%^%^RED%^What once must have been a simple, scarlet robe has been tailored and designed to catch the %^BLACK%^appetite %^RED%^without %^RESET%^%^CYAN%^revealing %^BOLD%^%^RED%^the %^RESET%^%^MAG"
	"ENTA%^flesh%^BOLD%^%^RED%^. Two parts coming into one, the dress-robe is %^WHITE%^strapless%^RED%^, leaving the shoulders and collarbones bare without revealing, tailored perfectly to encompas and %^W"
	"HITE%^flatter %^RED%^the %^MAGENTA%^wearer's %^RED%^curves. Beneath the bosom %^BLACK%^black lace %^RED%^straps hold tight a corset, hugging around the waist and flaring at the hips. And the closer to"
	" the hips the more the %^BLACK%^lace %^RED%^cloth intersects into an organzied %^CYAN%^ch%^BLACK%^a%^CYAN%^os%^RED%^, criss-crossing into a weave that leads into the dress. Past the hips the cloth is "
	"loose and %^RESET%^%^CYAN%^flowing%^BOLD%^%^RED%^. %^BLACK%^Black lace %^RED%^from the corset turning into the pattern of %^RESET%^%^GREEN%^vines %^BOLD%^%^RED%^over the %^BLUE%^sea %^RED%^of %^RESET%"
	"^%^RED%^scarlet %^BOLD%^%^RED%^red. The lower hem ending just above the knees as the %^BLACK%^black %^RED%^fabric blooms into %^CYAN%^i%^BLUE%^c%^CYAN%^y %^BLUE%^blue %^RED%^ro%^RESET%^%^RED%^s%^BOLD%"
	"^%^RED%^es of %^RESET%^%^BLUE%^tr%^BOLD%^%^BLUE%^an%^WHITE%^s%^BLUE%^lu%^RESET%^%^BLUE%^ce%^CYAN%^nt %^BOLD%^%^CYAN%^blue silk%^RED%^. The dress is broken by a slit, from hem to hip that hints at the "
	"right %^RESET%^%^MAGENTA%^leg %^BOLD%^%^RED%^of the woman wearing the garment. Furthermore, the loose, rippling fabric seems to contain several small, perfectly hidden pockets to store various small i"
	"tems.%^RESET%^
"	);
	set_value(12000);
	set_item_bonus("wisdom",2);
	set_size(2);
	set_property("enchantment",2);
}



