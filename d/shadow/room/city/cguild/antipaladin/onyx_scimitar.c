//Adapted from Antioch items.  Circe 3/23/04
#include <std.h>
inherit WEAPON;

void create()
{
	::create();
	set_name("Onyx Scimitar");
	set_short("%^BOLD%^%^BLACK%^Onyx Scimitar%^RESET%^");
	set_id(({"sword","scimitar","black scimitar","Onyx Scimitar","onyx scimitar","black sword"}));
	set_long(
         "%^BOLD%^%^BLACK%^This blackened blade has been sharpened "+
         "to a wicked edge and glitters like the night sky.  The "+
         "scimitar widens as it moves further away from the hilt, and "+
         "it ends in a fork much like a serpent's tongue.  The hilt "+
         "has been set with a multi-faceted onyx black as the abyss."
	);
	set_weight(7);
	set_size(2);
      set_value(40);
	set_wc(1,8);
	set_large_wc(1,12);
	set_type("thiefslashing");
	set_weapon_speed(4);
	set_property("enchantment",1);
}
