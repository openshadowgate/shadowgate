
//clearing.c
#include <std.h>
#include "sil.h"
inherit SIL"sil_forest";
inherit "/std/pier";

void create(){
::create();
set_post_exit_functions(({"northwest"}),({"go_out1"}));
   set_exits(([
"northwest":SIL"forest4"
]));
set_invis_exits(({"east","south","west","north","northeast","northwest","so
theast","southwest"}));
set_property("fill waterskin",1);
set_long("%^RESET%^%^GREEN%^Here, the %^CYAN%^serenity %^GREEN%^of the %^BOLD%^forest %^RESET%^%^GREEN%^meets the edge of a %^BLUE%^blue lagoon%^GREEN%^." 
" A sharply %^ORANGE%^sloping bank %^GREEN%^along the forests eastern edge is covered in a thick carpet of %^BOLD%^moss %^RESET%^%^GREEN%^and descends rapidly from the edge of the "
"%^BOLD%^lush forest %^RESET%^%^GREEN%^to the still %^CYAN%^waters %^GREEN%^of the %^BLUE%^lagoon%^GREEN%^.  A thin %^RESET%^shroud %^GREEN%^of %^RESET%^mist %^GREEN%^hangs low over the %^BLUE%^water%^GREEN%^, lending it an almost %^RESET%^ethereal presence%^GREEN%^."
" Beyond the %^BLUE%^lagoon%^GREEN%^, the view of the %^BOLD%^%^WHITE%^pristine beach%^RESET%^%^GREEN%^ on the opposite shore, flanked by the %^CYAN%^calm ocean waters %^GREEN%^greets all with"
"%^CYAN%^views %^GREEN%^that could be the envy of many.%^RESET%^");
}
int go_out1(string str){
   if(avatarp(TP) || (string)TP->query_name()== "silesse" || (string)TP->query_name()== "vicdaerrysn") {
      tell_room(TP,"%^RESET%^%^CYAN%^A faint %^RESET%^gli%^BOLD%^mm%^RESET%^er %^CYAN%^in the %^BOLD%^%^WHITE%^m%^RESET%^is%^BOLD%^t %^RESET%^%^CYAN%^covered %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st floor %^CYAN%^reveals paths headed %^BOLD%^%^GREEN%^north, west %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^southeast %^RESET%^%^CYAN%^to you.%^RESET%^",TO);
   return 1;
   }
return 1;
}
