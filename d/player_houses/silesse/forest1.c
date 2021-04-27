
//forest1
#include <std.h>
#include "sil.h"
inherit SIL"sil_forest";

void create(){
::create();
set_post_exit_functions(({"west",}),({"go_out1"}));

set_exits(([
"west":SIL"forest2",
"east":SIL"beach1",
]));
set_invis_exits(({"east","west"}));

}


int go_out1(string str){
   if(avatarp(TP) || (string)TP->query_name()== "silesse" || (string)TP->query_name()== "vicdaerrysn") {
      tell_room(TP,"%^RESET%^%^CYAN%^A faint %^RESET%^gli%^BOLD%^mm%^RESET%^er %^CYAN%^in the %^BOLD%^%^WHITE%^m%^RESET%^is%^BOLD%^t %^RESET%^%^CYAN%^covered %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st floor %^CYAN%^reveals paths headed %^BOLD%^%^GREEN%^south %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^east %^RESET%^%^CYAN%^to you.%^RESET%^",TO);
   return 1;
   }
return 1;
}
