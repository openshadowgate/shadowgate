#include <std.h>
#include "/d/undead/undead.h"

inherit POTION;

int ok,sex;

void create() 
{
    ::create() ;
   add_id("gender potion");
   set_short("A vial containing a sickly sweet potion");
    set_long("The crystal clear liquid in this vial steams "
        "the side of it's container with a glowing white smoke.  "
        "It is of a thick consistency, like cold honey, even "
        "though the vial itself is warm to the touch.  There "
        "can be little doubt that whatever substance is inside "
        "of this vial is dangerous at best.  A sickly sweet "
        "aroma arises with the smoke when the vial is opened.");

    set_lore("This potion was rumored to be created several "
        "centuries ago, to counter a potion made by a deranged "
        "wizard.  It was commissioned for quite a small fortune!  "
        "This particular potion is said to be capable of physically "
        "changing a woman into a man.");
    
    set_property("lore difficulty",35);

   set("color", "clear");
   set_value(25000);
}

int do_effect()
{
    if((string)drinker->query_gender() == "female")
    {
        drinker->set_gender("male");
        ok = 1;
        tell_object(drinker,"You feel your body begin to change.\n");
        return 1;
    } 
    else 
    {
        tell_object(drinker,"You feel no different than before.\n");
        return 1;
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

