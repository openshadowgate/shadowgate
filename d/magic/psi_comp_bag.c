//changed from pouch to satchel after suggestions from psions to 
//avoid conflicts with normal pouches.  ~Circe~ 9/27/05
//   Adapted for Psionic characters by ~Circe~ 7/15/05
//   Components Bag for Wizard Characters [v0.2]
//   Thorn@Shadowgate
//   10/10/94 [0.2: 12/7/94]
//   General Wizard Class Items
//   comp_bag.c

//   0.2.1: New components list fun added; components saved to disk file, improved!
//   0.2.2: New components producing fun added;

#include <std.h>
#include <move.h>
//#include <psi_components.h>
#include <spellcomponents.h>

#define PSI_COMP "/d/magic/store_comp"
// converted to generic mage comps in the move to single bags. N, 5/14

//inherit OBJECT;
inherit "/d/magic/comp_bag.c";

void create() {
   ::create();
   set_name("crystals satchel");
   set_short("a leather satchel for crystals");
   add_id("satchel");
   add_id("leather satchel");
   set_long(
      "%^RESET%^%^ORANGE%^This is a slender satchel made of soft "+
      "leather, lined with %^BOLD%^%^BLACK%^velvet %^RESET%^%^ORANGE%^"+
      "to protect crystals from scratches.  The satchel is decorated "+
      "with faint etchings of crystals in various shapes and features "+
      "a leather thong that serves as a drawstring to close the satchel.\n\n"+
      "%^RESET%^"+
      "     To check what is in the satchel, type <components>.\n\n"+
      "     To put a crystal into the satchel, type:\n"+
      "     <put [component name] into components bag>\n\n"+
      "     To see how many of a particular crystal you have, type:\n"
      "     <rummage for [component name]>\n\n"
      "     To retrieve crystals from the satchel, type:\n"+
      "     <produce [quantity] [component name]>\n"+
	"     <produce [all] [component name]>\n\n"+
      "     To produce all components in the bag at once, type:\n"
      "     <empty bag>\n"
      "     %^BOLD%^%^RED%^NOTE:%^RESET%^ Make sure the satchel you want to empty\n "
      "     is the first in your inventory.\n\n"
      "     This satchel will only hold those crystals needed for \n"+
      "     manifesting psionic powers.\n"
           );
}