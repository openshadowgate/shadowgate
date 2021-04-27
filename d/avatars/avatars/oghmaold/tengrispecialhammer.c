#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("moradin's hammer");
	set_id(({ "hammer", "smithy hammer", "moradin's hammer" }));
	set_short("%^BOLD%^%^RED%^Moradin's Hammer of Smithing%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^BLACK%^black %^WHITE%^and %^RED%^red %^BLACK%^smithy's hammer%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This is an exquisite smithy hammer.  The head is made of an odd alloy of %^BOLD%^%^BLACK%^adamantium %^RESET%^and %^BOLD%^%^WHITE%^mithril%^RESET%^.  The two foot shaft is made of %^RESET%^%^ORANGE%^ironwood %^RESET%^that looks to be as sturdy as the head itself.  Along one side of the head is a carving of the holy symbol of %^BOLD%^%^RED%^Tempus %^RESET%^and along the other is a %^RED%^fiery anvil%^RESET%^.  Along the shaft are %^BLUE%^ancient %^RED%^Dwarven runes %^RESET%^that reverberate with power.  An almost tangible aura of magic surrounds this hammer, and items crafted with it would be awesome indeed!

AVATAR
	);
	set("read",
@AVATAR
Moradin

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(4000);
	set_property("lore difficulty",0);
}