#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT ;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create();
  remove_property("can_hold");
  set_property("can_hold",({ "short blades","small blades","fan","knuckles","rapier", "wand"}));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({"left leg", "right leg"}));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",1);
  set_property("original_weight",1);
  set_obvious_short("%^RESET%^%^GREEN%^drop-leg %^RESET%^knife %^ORANGE%^sheath%^RESET%^");
	set_name("drop-leg knife sheath");
	set_short("%^RESET%^%^GREEN%^drop-leg %^RESET%^knife %^ORANGE%^sheath%^RESET%^");
	set_id(({"sheath","knife sheath","drop-leg sheath","drop leg knife-sheath"}));
	set_long("%^RESET%^%^GREEN%^This %^ORANGE%^sheath %^GREEN%^is worn much like a garter belt around a %^CYAN%^womans leg%^GREEN%^. A single thick strap is made of braided vines from which a %^ORANGE%^leather sheath%^GREEN%^, perfectly sized for a %^RESET%^small blade%^GREEN%^, hangs against the outer thigh.%^RESET%^");
  set_property("enchantment", 6);
  set_item_bonus("strength", 4);
  set_item_bonus("fire resistance", 28);
  set_max_internal_encumbrance(10);
  set_limbs( ({ "left leg"}) );
}
