#include <std.h>

inherit "/d/magic/obj/mirror.c";

create() {
   ::create();
   set_name("mirror");
   set_id(({"mirror", "fine mirror","basin","water basin"}));
   set_short("%^RESET%^A %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^basin");
   set_property("no animate", 1);
   set_long("Dominating the center of the room is this basin.  It stands roughly three feet tall and is roughly circular in shape.  It is comprised of %^BOLD%^%^WHITE%^an%^RESET%^%^WHITE%^c%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^nt%^RESET%^, well-worn %^BOLD%^%^BLACK%^fieldstone %^RESET%^covered in %^GREEN%^moss %^RESET%^and is topped by a shallow, well-shined %^BOLD%^%^WHITE%^mithril bowl%^RESET%^.  The bowl is filled with %^BOLD%^%^CYAN%^crystal clear water %^RESET%^and gives off a very clear reflection.");
   set("value", 1001);
   set_weight(100000);
   set_no_clean(1);
}
int get() { return 0; }
int drop() { return 1; }
