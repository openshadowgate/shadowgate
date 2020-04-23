#include <std.h>

inherit POTION;

int ok;
string sex;

void create()
{
    ::create();
    set_short("%^BOLD%^%^MAGENTA%^Potion of Gender Inversion%^RESET%^");
    set_obvious_short("A vial containing a %^BOLD%^%^MAGENTA%^bright purple %^RESET%^potion");
    set_long("The %^BOLD%^%^MAGENTA%^bright purple %^RESET%^liquid in this vial steams "
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
             "a man or vice versa.");

    set_property("lore difficulty", 35);
    set("color", "%^BOLD%^%^MAGENTA%^bright purple%^RESET%^");
}

int do_effect()
{
    sex = drinker->query_gender();

    switch (sex) {
    case "male":
        drinker->set_gender("female");
        tell_object(drinker, "You feel your body begin to change.\n");
        ok = 1;
        break;

    case "female":
        drinker->set_gender("male");
        tell_object(drinker, "You feel your body begin to change.\n");
        ok = 1;
        break;

    default:
        tell_object(drinker, "You feel no different than before.\n");
        break;
    }
    return 1;
}

int do_wear_off()
{
    if (ok) {
        tell_object(drinker, "You feel the effects of the potion set into your system.\n");
    }

    return 1;
}
