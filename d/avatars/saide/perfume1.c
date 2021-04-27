#include <std.h>
inherit OBJECT;

int quanity;

void create()
{
    ::create();
	set_name("bottle of perfume");
    set_id(({"perfume","bottle of perfume","bottle",
    "sweet pine perfume","pine perfume","mysterious perfume"}));
    set_short("A bottle of sweet pine perfume");
    set_long("%^GREEN%^This is a round bottle that holds a "+
    "light green liquid.  The concoction within it smells much "+
    "like a pine thicket with a faint sweet fragrance "+
    "blended in.%^RESET%^");
    set_value(100);
    set_weight(1);
    quanity = 10 + random(11);
}

void init()
{
	::init();
    if(living(ETO)) {
	    add_action("wear_me","wear");
    }
}

int wear_me(string str)
{
	if(strsrch(str,"perfume")==-1) return 0;
	else {
	    if(quanity) {
		   quanity--; 
           write("You spray on a bit of the sweet pine perfume.");
           tell_room(EETO,ETOQCN+"%^GREEN%^ sprays on some sweet "+
           "pine perfume.%^RESET%^",ETO);
		   ETO->set("long","%^BOLD%^%^GREEN%^"+
           capitalize(nominative(TP))+" is wearing "+
           "a sweet pine fragrance.");
           return 1;
		}
		else {
			write("The bottle is empty.");
			set_long("This small crystal "+
            "bottle used to contain a sweet, pine smelling "+
            "liquid, but now it is empty.");
			set_short("An empty perfume bottle.");
			set_value(0);
			return 1;
		}
	}
}
