
//forest2
#include <std.h>
#include "sil.h"
inherit SIL"sil_forest";

void create(){
::create();
set_post_exit_functions(({"south","east"}),({"go_out1","go_out2"}));
set_exits(([
"south":SIL"forest3",
"east":SIL"forest1",
]));
set_invis_exits(({"east","south"}));

}
int go_out1(string str){
   if(avatarp(TP) || (string)TP->query_name()== "silesse" || (string)TP->query_name()== "vicdaerrysn") {
      tell_room(TP,"%^RESET%^%^CYAN%^A faint %^RESET%^gli%^BOLD%^mm%^RESET%^er %^CYAN%^in the %^BOLD%^%^WHITE%^m%^RESET%^is%^BOLD%^t %^RESET%^%^CYAN%^covered %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st floor %^CYAN%^reveals paths headed %^BOLD%^%^GREEN%^west, north %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^south %^RESET%^%^CYAN%^to you.%^RESET%^",TO);
   return 1;
   }
return 1;
}
int go_out2(string str){
   if(avatarp(TP) || (string)TP->query_name()== "silesse" || (string)TP->query_name()== "vicdaerrysn") {
      tell_room(TP,"%^RESET%^%^CYAN%^A faint %^RESET%^gli%^BOLD%^mm%^RESET%^er %^CYAN%^in the %^BOLD%^%^WHITE%^m%^RESET%^is%^BOLD%^t %^RESET%^%^CYAN%^covered %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st floor %^CYAN%^reveals paths headed %^BOLD%^%^GREEN%^east %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^west %^RESET%^%^CYAN%^to you.%^RESET%^",TO);
   return 1;
   }
return 1;
}
