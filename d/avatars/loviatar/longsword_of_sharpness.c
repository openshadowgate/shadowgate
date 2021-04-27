//file 

#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("sword of sharpness");
    set_id(({"weapon","sword of sharpness","sword","%^WHITE%^ Sword of Sharpness %^RESET%^",}));
    set_short("%^WHITE%^ Sword of Sharpness %^RESET%^");
    set_long(
@WEAPON
This is one of the famous weapons made by Metikul the Artificer.  Over the years he has created many a fine blades which are known collectively as "Swords of Sharpness".  This particular sword has a silver wrapped leather handle and scabbard, and a blade of shining white metal.  While this sword has no divine powers it is a more then adequate weapon in combat.
WEAPON
        );
    set_weight(15);
    set_size(2);
    set_type("slashing");
    set_prof_type("sword of sharpness");
    set_ac(0);
    set_property("enchantment",4);
    set_value(1000);
    set_wc(1,10);
    set_large_wc(1,12);
}