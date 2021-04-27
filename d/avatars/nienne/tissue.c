#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("tissue");
   set_id(({"tissue","handkerchief"}));
   set_short("%^BOLD%^%^BLACK%^a grubby little tissue%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^This little cloth tissue is covered in %^RESET%^%^ORANGE%^dirt%^BLACK%^%^BOLD%^"
" and %^RESET%^%^BLUE%^grime%^BLACK%^%^BOLD%^, so that you can't even tell what colour it might once have "
"been.  Do you really want to blow your nose on this?%^RESET%^\n");
   set_value(0);
   set_weight(0);
}