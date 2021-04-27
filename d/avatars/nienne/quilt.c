#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("quilt");
   set_id(({"quilt","green quilt","wool quilt","handmade quilt"}));
   set_short("%^RESET%^%^GREEN%^a handmade green wool quilt%^RESET%^");
   set_long("%^GREEN%^Dark green wool has been used as the foundation of "
"this %^RED%^m%^GREEN%^e%^RED%^d%^GREEN%^a%^RED%^l%^GREEN%^l%^RED%^i%^GREEN%^o"
"%^RED%^n %^GREEN%^style quilt.  Soft to the touch, the two facings of "
"wool are stuffed with a light layer of %^RESET%^goose down%^GREEN%^ "
"between and then bordered on the edges with a lighter %^BOLD%^forest "
"green %^RESET%^%^GREEN%^satin trim.  The trim also crisscrosses over the "
"top of the wool, breaking the pattern into four distinct corners.  In "
"the upper left and lower right corners a quilt-work, cotton %^BOLD%^"
"%^BLACK%^gray wolf %^RESET%^%^GREEN%^stands watchful atop a fabric "
"%^ORANGE%^stone rock%^GREEN%^.  Their heads and mussels lifted toward "
"the %^BOLD%^%^WHITE%^moon %^RESET%^%^GREEN%^which outlines their shape.  "
"Tiny beads of %^YELLOW%^citrine %^RESET%^%^GREEN%^have been sewn in "
"where the wolf eyes are located to give the blanket a little %^CYAN%^"
"sp%^RESET%^a%^CYAN%^rk%^RESET%^l%^CYAN%^e%^GREEN%^.  On the upper right "
"and lower left corners, a quilt-work, cotton %^ORANGE%^hawk %^GREEN%^"
"soars in mid flight.  The %^ORANGE%^brown wings %^GREEN%^are stretched "
"out wide with the pin feathers splayed as if catching a draft of %^BLUE%^"
"air%^GREEN%^.   Like the wolves, their eyes also are highlighted with "
"tiny beads but these are instead tiny %^RED%^ruby %^GREEN%^beads.  The "
"blanket is large enough to wrap a person of average size up in a cozy "
"cocoon of %^YELLOW%^warmth %^RESET%^%^GREEN%^and %^CYAN%^security"
"%^GREEN%^.%^RESET%^\n");
   set_weight(0);
   set_value(65);
}
