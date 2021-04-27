#include <std.h>
inherit OBJECT;

int quanity;

void create()
{
    ::create();
	set_name("bottle of perfume");
    set_id(({"perfume","bottle of perfume","bottle",
    "sweet daisy perfume","daisy perfume","mysterious perfume"}));
    set_short("A fragrance of daisy");
    set_long("%^YELLOW%^This is a round bottle that holds a "+
    "light yellow liquid.  The concoction within it smells much "+
    "like a fresh daisy with a soft touch of pine and a faint hint "+
    "of honey.%^RESET%^");
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
           write("You spray on some of the fragrance of daisy.");
           tell_room(EETO,ETOQCN+"%^YELLOW%^ sprays on some "+
           "fragrance of daisy.%^RESET%^",ETO);
    	   ETO->set("long","%^BOLD%^%^YELLOW%^"+
           capitalize(nominative(TP))+" is wearing "+
           "a fragrance of daisy.");
           return 1;
		}
		else {
			write("The bottle is empty.");
			set_long("This small crystal "+
            "bottle used to contain a liquid with the "+
            "fragrance of a fresh daisy, but now it is empty.");
            set_short("An empty perfume bottle.");
			set_value(0);
			return 1;
		}
	}
}
