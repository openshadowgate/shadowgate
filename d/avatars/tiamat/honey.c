#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("jar of honey");
	set_id(({ "jar", "honey" }));
	set_short("%^RESET%^%^MAGENTA%^Wil%^BOLD%^dfl%^RESET%^%^GREEN%^ow%^MAGENTA%^er%^RESET%^ %^ORANGE%^honey%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^Wil%^BOLD%^dfl%^RESET%^%^GREEN%^ow%^MAGENTA%^er%^RESET%^ %^ORANGE%^honey%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This is a durable glass jar filled with a thick, %^ORANGE%^amber%^CYAN%^ colored liquid.  Small bubbles appear in the liquid.  The jar has been sealed closed with a cork, stopper and hinge.  As you investigate the jar and stopper you realize the liquid is none other than fragrant %^YELLOW%^honey%^RESET%^%^CYAN%^, infused with the smell of wildflowers.  Once, there was a %^RESET%^label%^CYAN%^ on the jar, but it has long since faded away.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
You can't read the label silly, its faded away!

AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(2800);
	set_lore(
@AVATAR
%^RESET%^%^MAGENTA%^Wil%^BOLD%^dfl%^RESET%^%^GREEN%^ow%^MAGENTA%^er%^RESET%^ %^ORANGE%^honey%^RESET%^ is perhaps the finest natural sweetener known in this part of the world.  The painstaking process of its manufacture is performed mostly be bees that have grown fond of the windflowers of Yntala forest, but some forest dwellers or fey creatures have braved the task of harvesting it.  It is remarkably valuable, especially in the South.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
}
