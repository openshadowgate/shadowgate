//   Adapted for Bardic characters by -Nienne 08/10
//   Components Bag for Wizard Characters [v0.2]
//   Thorn@Shadowgate
//   10/10/94 [0.2: 12/7/94]
//   General Wizard Class Items
//   comp_bag.c
//   0.2.1: New components list fun added; components saved to disk file, improved!
//   0.2.2: New components producing fun added;

#include <std.h>
#include <move.h>
//#include <bardcomps.h>
#include <spellcomponents.h>

#define BARD_COMP "/d/magic/store_comp"
// converted to generic mage comps in the move to single bags. N, 5/14
//inherit OBJECT;
inherit "/d/magic/comp_bag.c";


void create() {
   ::create();
   add_id("book");
   add_id("lore book");
   set_name("lore book");
   set_short("a book of prose and poetry");
   set_long(
      "%^RESET%^%^ORANGE%^This slim book is bound in soft leather, "+
      "smooth from regular handling and a little worn at the edges.  "+
      "Inside lie numerous pages of seemingly unrelated prose and "+
      "poetry, some short and some long, and occasionally you find "+
      "a sheet marked with a musical composition.  Its cover is "+
      "marked with a short series of lettering and several musical "+
      "notes. A small bag-like pouch has been stitched inside to hold components.\n\n"+
      "%^RESET%^"+
      "     To check what is in the lore book type <components>.\n"+
      "     To put writing into the book type:\n"+
      "     <put [component name] into components bag>\n"+
      "     To retrieve writings from the book type:\n"+
      "     <produce [quantity] [component name]>\n"+
	"     <produce [all] [component name]>\n"+
      "     This book will only hold those compositions needed for \n"+
      "     intoning bardic spells.\n"
           );
}
