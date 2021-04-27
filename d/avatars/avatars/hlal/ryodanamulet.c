#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("ruby pendant");
	set_id(({ "ruby necklace", "necklace", "necklace of ages", "ruby necklace of ages" }));
	set_short("%^RESET%^%^RED%^N%^BOLD%^e%^RESET%^%^RED%^cklace of A%^BOLD%^g%^RESET%^%^RED%^es%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^by necklace%^RESET%^");
	set_long("%^BOLD%^%^RED%^Large rubies make up this elaborate necklace. It is a heavy piece that not many would be willing to flaunt for long. Something about the necklace makes it look ages old and yet still sh"
	"ines and shimmers like a brand new piece of jewelry.%^RESET%^
"	);
	set_value(25000);
	set_lore("Centuries ago, a young man sought to find a treasure that would allow him and his beloved to be together forever. It took the man most of his adult life to find what he was looking for deep in the hoa"
	"rde of dragon treasure. Noone knows how the necklace worked for him, only that it did indeed work as it is rumored the couple still walks the lands together.
"	);
	set_property("lore difficulty",5);
	set_item_bonus("magic resistance",2);
	set_size(2);
	set_property("enchantment",3);
}



