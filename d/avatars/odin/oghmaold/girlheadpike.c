#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("head on pike");
	set_id(({ "pike", "head" }));
	set_short("%^RESET%^The %^RESET%^%^RED%^bloodied head %^RESET%^of a little girl on a %^RESET%^%^RED%^pike%^RESET%^");
	set_obvious_short("%^RESET%^The %^RESET%^%^RED%^bloodied head %^RESET%^of a little girl on a %^RESET%^%^RED%^pike%^RESET%^");
	set_long(
@AVATAR
This thing is a gruesome sight indeed.  The head of a human girl has been %^RESET%^%^RED%^impaled %^RESET%^upon a crude %^RESET%^%^ORANGE%^wooden pike%^RESET%^.  The girl's face is bloodied and bruised as if she recieved a cruel death indeed.  Scrawled across her forehead are the words %^BOLD%^%^RED%^VENGEANCE %^RESET%^in the common tongue.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^VENGEANCE%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(0);
	set_property("lore difficulty",0);
}