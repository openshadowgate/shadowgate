#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("plate");
   set_id(({"plate","dinner plate","magical plate","china plate","plate of cleanliness"}));
   set_short("%^RESET%^%^MAGENTA%^China Plate of C%^CYAN%^l%^MAGENTA%^eanl%^BOLD%^i%^RESET%^%^MAGENTA%^ness%^RESET%^ +1");
   set_obvious_short("%^RESET%^%^MAGENTA%^a spotlessly clean china plate%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This plate is made of %^WHITE%^fine bone "
"china%^MAGENTA%^.  It has been painted with the image of %^RED%^colorful "
"flowers %^MAGENTA%^across its surface, and has been %^CYAN%^glazed %^MAGENTA%^"
"to preserve it from damage.  The edges of the china bear small inward "
"%^ORANGE%^notches %^MAGENTA%^to add a crimped, decorative edge to the plate.  "
"It is absolutely %^RESET%^spotless%^MAGENTA%^, as though it had never been "
"used.%^RESET%^");
   set_lore("Plates such as this are highly prized by housekeepers everywhere.  "
"Such an enchantment as lies upon this one, is usually reserved for only the "
"finest of plates and dinnerware.  The magic serves both to protect the plate "
"from harm, as no damage will chip or crack it, and to keep it spotlessly clean "
"without need of washing.  The perfect addition to any kitchen!");
   set_property("lore difficulty",15);
   set_value(0);
   set_weight(0);
}
int isMagic(){ return 1; }
