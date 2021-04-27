#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("olive oil");
	set_id(({ "oil", "bottle", "olive oil" }));
	set_short("%^RESET%^%^ORANGE%^A bottle of fine olive oil%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^A bottle of fine olive oil%^RESET%^");
	set_long(
@AVATAR
%^ORANGE%^This is a tall glass bottle not unlike the kind used to hold wine.  The clear glass reveals that inside is a fine cooking oil the perfect amber shade.  Although the wax seal appears to be broken, the oil seems unspoiled.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Berollini Press, Graez%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_value(3600);
	set_lore(
@AVATAR
The Berollini Press is perhaps the most well known producer of cooking oil in the Realm.  They have perfected the art of cold pressing olives, which produces less oil but greatly increases its quality.  Some vintages of their olive oil is worth more than its weight in gold!  The press is located on the island of Graez.

AVATAR
	);
	set_property("lore difficulty",5);
}