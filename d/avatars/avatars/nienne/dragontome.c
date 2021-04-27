#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("tome");
   set_id(({"tome","book","clothbound tome"}));
   set_short("%^RESET%^%^ORANGE%^Tome of the %^MAGENTA%^Da%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^k Sun's Ent%^BOLD%^"
"%^BLACK%^r%^RESET%^%^MAGENTA%^apment%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^an old clothbound tome%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This tome is old and tattered, with a "
"%^RED%^heavy cloth cover%^ORANGE%^. There is no writing on the cover, but "
"opening it you find thick %^RESET%^vellum pages %^ORANGE%^that are dry and "
"yellowed with age. Upon them are scrawled lines of %^BOLD%^%^BLACK%^jagged "
"characters %^RESET%^%^ORANGE%^that look like writing. You can't make sense of "
"them, however; they are written in some unknown language. While old, the text "
"is quite %^CYAN%^clear %^ORANGE%^and neatly-written, the sharp angles of each "
"character clearly shaped.  The book itself, despite its haggard appearance, "
"thrums with a tangible aura of %^MAGENTA%^ev%^BOLD%^%^BLACK%^i%^RESET%^"
"%^MAGENTA%^l%^ORANGE%^.%^RESET%^");
   set_weight(2);
}
