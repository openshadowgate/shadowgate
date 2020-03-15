#include <std.h>
#include "/d/undead/undead.h"

inherit POTION;

int ok,sex;

void create() 
{
    ::create() ;
   add_id("gender potion");
   set_short("A vial containing a menacing potion");
    set_long("The crystal clear liquid in this vial steams "
        "the side of it's container with a glowing white smoke.  "
        "It is of a thick consistency, like cold honey, even "
        "though the vial itself is warm to the touch.  There "
        "can be little doubt that whatever substance is inside "
        "of this vial is dangerous at best.");
    
    set_lore("This potion was rumored to be created several "
        "centuries ago by a derranged wizard who had multiple "
        "personalities.  The formula was said to have been lost "
        "with his untimely death when one furious suitor learned "
        "that his lovely mistress was normally a man.  This "
        "particular potion is said to be a counter for the "
        "original, capable of physically changing a woman into "
        "a man, regardless of wether or not she was a man "
        "originally.");
    
    set_property("lore difficulty",35);
   set("color", "clear");
   set_value(25000);
}

int do_effect()
{
    if(drinker->query_gender("female"))
    {
        drinker->set_gender("male");
        ok = 1;
        tell_object(drinker,"You feel your body begin to change.\n");
        return 1;
    }
    

    else 
    {
        tell_object(drinker,"You feel no different than before.\n");
        return 0;
    }
    return 1;
}

int do_wear_off()
{
    if(ok)
    {
        tell_object(drinker,"You feel the effects of the potion set into your system.\n");
    }
    
    return 1;
}

