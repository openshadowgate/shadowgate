#include <std.h>
#include <move.h>
inherit PARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_id(({"quiver","akadi quiver","quiver of the winds","quiver of winds","silk-wrapped quiver","silk quiver"}));
   set_short("%^WHITE%^%^BOLD%^Qui%^CYAN%^v%^WHITE%^er of t%^CYAN%^h%^WHITE%^e Win%^CYAN%^d%^WHITE%^s%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^si%^CYAN%^l%^WHITE%^k-wra%^BLACK%^p%^WHITE%^ped qu%^BLUE%^i%^WHITE%^ver%^RESET%^");
   set_long("%^CYAN%^This quiver consists primarily of %^WHITE%^soft white leather%^CYAN%^, forming an open-"
"ended sleeve to contain a large number of arrows.  The outer surface, however, has been wrapped in layers "
"of pale, %^WHITE%^%^BOLD%^mu%^BLACK%^l%^WHITE%^ti-%^CYAN%^c%^WHITE%^olo%^BLUE%^u%^WHITE%^red "
"%^RESET%^%^CYAN%^silks, the ends of which have been left loose, to hang freely and sway in any breeze.  A "
"strap of leather is attached to hold the quiver within easy reaching range on the wearer's back, also "
"wrapped in the silken cloth, making it very soft and comfortable to wear.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^These quivers are rarely found, and are usually associated with followers of "
"the Queen of Air.  They are specially crafted by priests of the faith, and some say they are shaped from "
"the essense of the winds themselves.");
   set_property("lore difficulty",7);
   set_name("quiver");
   set_max_internal_encumbrance(128);
   set_limbs(({"torso"}));
   set_type("sheath");
   set_weight(10);
   set_value(0);
   set_ac(1);
   set_wear((:TO,"wear_fun":));
   set_remove("%^WHITE%^%^BOLD%^You feel the touch of the winds dissipate as you remove the quiver.");
}

void init() {
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
     owner = TPQN;
     OWNED = 1;
     set_size(TP->query_size());
   }
}

int wear_fun() {
   if((string)TPQN != owner) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The quiver refuses to fit you!");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" tries to force the quiver on, but fails.",ETO);
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You are filled with confidence as you slide the quiver on.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" slides the quiver on with an air of assurance.",ETO);
   return 1;
}

int item_allowed(object item) {
   if(!item->is_arrows()){
     notify_fail("This is meant for arrows only.");
     return 0;
   }
   return 1;
}
