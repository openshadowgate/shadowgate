//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("Tsarvani recurved bow");
    set_id(({"weapon","Tsarvani recurved bow","bow","Tsarvani recurved bow",}));
    set_short("Tsarvani recurved bow");
    set_long(
@WEAPON
This is a composite recurved bow such as is made for the Imperial Army
of Tsarven and many inhabitants of Oudh Province of that same Empire. 
The outer arms of the bow are curved away from the archer when the bow
is strung, which imparts a mechanical advantage at the end of the draw,
hence the name "recurved".  The composite bow's superior pull weight is
increased by reinforcing the rear, or belly, of the bow with horn and
its speed.  The power in recoil is increased by overlaying the front of
the bow with sinew, usually applied under tension. The wooden structure
of this composite thus consists of little more than thin wooden strips
supporting the horn and sinew.  This powerful composite bow, being very
highly stressed, will actually reverse its curvature when unstrung.
WEAPON
        );
    set_weight(5);
    set_size(2);
    set_type("bludgeoning");
    set_prof_type("composite bow");
    set_ac(0);
    set_property("enchantment",0);
    set_value(100);
    set_wc(1,5);
    set_large_wc(1,5);
}