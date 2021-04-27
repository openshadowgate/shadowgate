#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^BLACK%^%^BOLD%^strange stuffed toy%^RESET%^");
	set_id(({ "toy", "stuffed toy", "bane toy" }));
	set_short("%^BLACK%^%^BOLD%^strange stuffed toy%^RESET%^");
	set_obvious_short("%^BLACK%^%^BOLD%^strange stuffed toy%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^BLACK%^This little figure of a man, is anything but cute. It is covered in black 
fur, with%^RESET%^%^BOLD%^%^GREEN%^ bright green threads %^RESET%^%^BOLD%^%^BLACK%^woven onto the surface to give shape to the 
scowling facial features of the %^RESET%^%^BOLD%^%^GREEN%^eyes%^RESET%^%^BOLD%^%^BLACK%^, %^RESET%^%^BOLD%^%^GREEN%^nose%^RESET%^%^BOLD%^%^BLACK%^, and %^RESET%^%^BOLD%^%^GREEN%^mouth%^RESET%^%^BOLD%^%^BLACK%^. %^RESET%^%^BOLD%^%^GREEN%^Floppy green horns%^RESET%^%^BOLD%^%^BLACK%^
are sewn onto the top of the head. They are designed in the likeness of ram 
horns. %^RESET%^%^BOLD%^%^GREEN%^Matching claws %^RESET%^%^BOLD%^%^BLACK%^are set into what seems to be more like paws, instead 
of hands. That is not the only abnormality of this little man, as a set of 
black bat wings are set into the back of the stuffed object.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(10);
}