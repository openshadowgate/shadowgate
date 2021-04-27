#include <std.h>
inherit OBJECT;

int quanity;

void create()
{
    ::create();
	set_name("bottle of perfume");
    set_id(({"perfume","bottle of perfume","bottle",
    "fragrance of nature","nature perfume","mysterious perfume"}));
    set_short("A fragrance of nature");
    set_long("%^BOLD%^%^GREEN%^This is a round bottle that holds a "+
    "light green liquid.  The concoction within it smells much "+
    "like a forest after a light rain, with a faint "+
    "odor of daisy.%^RESET%^");
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
           write("You spray on some of the fragrance of nature.");
           tell_room(EETO,ETOQCN+"%^BOLD%^%^GREEN%^ sprays on some "+
           "fragrance of nature.%^RESET%^",ETO);
    	   ETO->set("long","%^BOLD%^%^GREEN%^"+
           capitalize(nominative(TP))+" is wearing "+
           "a fragrance of nature.");
           return 1;
		}
		else {
			write("The bottle is empty.");
			set_long("This small crystal "+
            "bottle used to contain a liquid with the "+
            "fragrance of a frest after a light rain, "+
            "but now it is empty.");
            set_short("An empty perfume bottle.");
			set_value(0);
			return 1;
		}
	}
}
