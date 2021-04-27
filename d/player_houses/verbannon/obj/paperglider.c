#include <std.h>
#include "../defs.h"
inherit OBJECT;

void create() {
   ::create();
   set_name("glider");
   set_id(({ "glider","paper glider"}));
   set_short("%^RESET%^a %^BOLD%^%^WHITE%^paper glid%^CYAN%^e%^WHITE%^r%^RESET%^");
   set_long("This is a sheet of paper folded into the form of a glider. Getting a glimpse of some of the wording on it, it "
"seems this may once have been an important document someone decided to turn into a toy. You could probably <throw glider>.");
   set_weight(0);
   set_value(0);
}

void init() {
   ::init();
   add_action("throw_fun","throw");
}

int save_me(string file) { return 1; }

int throw_fun(string str) {
   if(!str) return 0;
   if(str == "glider" || str == "paper glider"){
     tell_object(TP,"The %^BOLD%^%^WHITE%^glid%^CYAN%^e%^WHITE%^r%^RESET%^ floats through the %^BOLD%^%^CYAN%^air%^RESET%^, "
"before turning around and %^BOLD%^%^RED%^smacking%^RESET%^ you in the %^BOLD%^%^WHITE%^e%^BLUE%^y%^WHITE%^e%^RESET%^. Ouch!");
     tell_room(ETP,""+TP->QCN+" throws the %^BOLD%^%^WHITE%^glid%^CYAN%^e%^WHITE%^r%^RESET%^ into the %^BOLD%^%^CYAN%^air"
"%^RESET%^. The %^BOLD%^%^WHITE%^glid%^CYAN%^e%^WHITE%^r%^RESET%^ floats in the %^BOLD%^%^CYAN%^air%^RESET%^ before turning "
"around and %^BOLD%^%^RED%^smacking%^RESET%^ "+TP->QO+" in the %^BOLD%^%^WHITE%^e%^BLUE%^y%^WHITE%^e%^RESET%^. Ouch!",TP);
     TO->remove();
     return 1;
   }
   return 0;
}