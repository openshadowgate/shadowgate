#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Splatterific");
	set_id(({ "dagger", "Dagger", "splatterific", "Splatterific" }));
	set_short("%^RESET%^%^RED%^Splatterific%^RESET%^");
	set_obvious_short("dagger");
	set_long(
@AVATAR
A horrible grusome weapon this little dagger is. A long and twisted blade jutting out from the handle, a strange red dotting the black blade up and down. A groove in the middle of the blade running from the tip into the hilt, the groove is lined with looks to be a really dark emerald. You suspect the groove must be a blood channel. The handle is made up of a dark red substance that almost seems to move, but doesnt.

AVATAR
	);
	set("read",
@AVATAR
Stabby stab stab

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(1000);
	set_lore(
@AVATAR
A legendary dagger, said to be used to stab things and well, splatter them. Hence the daggers name, Splatterific.

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("piercing");
	set_prof_type("splatterific");
	set_size(1);
	set_wc(1000,1);
	set_large_wc(1000,1);
	set_property("enchantment",30);
	set_ac(1000);
}


