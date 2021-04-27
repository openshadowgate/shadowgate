#include <std.h>
inherit OBJECT;

void create() {
   ::create();
     set_name("folded plaster screen");
   set_id(({"frame","colorful frame","screen","wooden screen","wooden frame","colorful screen,""plaster screen","colorful plaster screen"}));
   set_short("%^RESET%^%^CYAN%^a %^GREEN%^c%^CYAN%^o%^BOLD%^l%^BLUE%^o%^RESET%^%^MAGENTA%^r%^RED%^f%^ORANGE%^u%^YELLOW%^l %^RESET%^%^CYAN%^plaster-coated screen supported by a %^ORANGE%^wooden %^CYAN%^frame%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This screen is a little less than the height of an adult person, perhaps four feet tall in all. A sturdy %"+
   "^ORANGE%^wooden %^CYAN%^frame supports it and keeps it standing, held by struts that sit across the floor behind it. Cleverly-disguised %^BOLD%^%^BLACK%^hinges %^RESET%^%^CYAN%^can be seen at several points of the frame, perhaps allowing it to be folded down. The "+
   "screen itself is made of %^RESET%^plaster%^CYAN%^, painted in an array of %^BOLD%^r%^BLUE%^a%^RESET%^%^MAGENTA%^i%^RED%^n%^ORANGE%^b%^YELLOW%^o%^BOLD%^%^GREEN%^w %^RESET%^%^CYAN%^colors depicting all sorts of %^GREEN%^f%^MAGENTA%"+
   "^l%^GREEN%^ow%^BOLD%^%^WHITE%^e%^RESET%^%^GREEN%^rs %^CYAN%^and %^YELLOW%^bu%^RESET%^%^ORANGE%^tte%^RED%^rf%^MAGENTA%^lie%^BLUE%^s%^CYAN%^, and in one section a bright %^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%"+
   "^en %^CYAN%^sun. In the middle of the upper panel, a hole has been cut much like a window, and two little mobile %^BOLD%^%^BLACK%^f%^CYAN%^i%^BLACK%^xtu%^GREEN%^r%^BLACK%^es %^RESET%^%^CYAN%^are set within it, one in each of the upper corners.");
set_weight(3);
set_value(900);
}
void init(){
::init();
add_action("fold","fold");
}

int fold(string str){
   object ob;
   if(!str)
      return notify_fail("Fold what?");
    if((str=="wooden frame")) {
      if(!present("wooden frame",TP))
      return notify_fail("You don't have the frame to unfold.");
   ob=(present("wooden frame",TP));
   ob->move("/d/shadowgate/void");
   say("%^RESET%^%^ORANGE%^"+TPQCN+" folds the frame up, neatly securing the legs with lockable hinges and taking the legs out of sight.%^RESET%^");
   write("%^RESET%^%^ORANGE%^You fold the frame up, neatly securing the legs with lockable hinges and taking the legs out of sight.%^RESET%^");
   ob= new("/d/avatars/dinji/screen.c");
   ob->move(TP);
   return 1;
}
}
