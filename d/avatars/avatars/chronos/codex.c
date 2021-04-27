#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("darkbook");
	set_id(({ "book", "codex" }));
	set_short("%^BOLD%^%^BLACK%^The Codex Da%^RED%^e%^BLACK%^monis%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A dark leather %^RESET%^%^ORANGE%^tome%^BOLD%^%^BLACK%^ sealed with a thick %^WHITE%^chain%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Eldrich runes cover the front of this codex, gazing too long upon it begins to make your eyes water. Within it's pages however a veritable resourse on all manner of %^MAGENTA%^demons%^BLACK%^ and %^RED%^devils%^BLACK%^, striking contracts and binding daemons to the material plane. Some if not all of the pages depict gruesome things from beyond your imagination, and is quite possibly inked in what appears to be %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^. The pages are old and it is only with careful delicate motions that you are able to turn the pages.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Various rituals are inscribed upon the pages, written in %^RESET%^%^RED%^blood%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(10);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^This is one of the fabled ancient codexs written by the dark mages that once worshipeed the fell powers that dwelt in the immaterium. These books are often found locked away in soem crazed mages tower, or anicent libraires. Impossibly dangerous in the wrong hands.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
}