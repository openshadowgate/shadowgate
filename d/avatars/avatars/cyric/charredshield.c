//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("shield");
    set_id(({"armor","shield","charred shield","%^RESET%^%^BLUE%^Charred Mithril Shield%^RESET%^",}));
    set_short("%^RESET%^%^BLUE%^Charred Mithril Shield%^RESET%^");
    set_long(
@ARMOR
%^RESET%^%^BLUE%^This was once a mithril shield of shining silver, but evil magical energies have charred it black.  It provides excellent protection, and can be used with a lance.  Emblazoned on the front is a skull in starburst symbol.  This shield is generally only worn by warriors of darkness of considerable influence.
ARMOR
        );
    set_weight(5);
    set_size(2);
    set_type("armour");
    set_limbs(({"right hand",}));
    set_ac(5);
    set_property("enchantment",3);
    set_value(1000);
}