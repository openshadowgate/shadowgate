#include <std.h>

inherit OBJECT;

void create() {
   ::create();
   set_name("plaster screen");
   set_id(({"frame","colorful frame","screen","wooden screen","wooden frame","colorful screen,""plaster screen","colorful plaster screen"}));
   set_short("%^RESET%^%^CYAN%^a folded %^ORANGE%^wooden %^CYAN%^frame supporting a %^GREEN%^c%^CYAN%^o%^BOLD%^l%^BLUE%^o%^RESET%^%^MAGENTA%^r%^RED%^f%^ORANGE%^u%^YELLOW%^l %^RESET%^%^CYAN%^plaster screen%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This little folded %^ORANGE%^wooden %^CYAN%^frame bears cleverly-disguised %^BOLD%^%^BLACK%^hinges%^RESET%^%^CYAN%^, obviously allowing it to unfold and become something much larger. The frame supports solid screens of"+
   "%^RESET%^ plaster%^CYAN%^, painted in an array of %^BOLD%^r%^BLUE%^a%^RESET%^%^MAGENTA%^i%^RED%^n%^ORANGE%^b%^YELLOW%^o%^BOLD%^%^GREEN%^w %^RESET%^%^CYAN%^colors depicting all sorts of %^GREEN%^f%^MAGENTA%^l%^GREEN%^ow%"+
   "^BOLD%^%^WHITE%^e%^RESET%^%^GREEN%^rs %^CYAN%^and %^YELLOW%^bu%^RESET%^%^ORANGE%^tte%^RED%^rf%^MAGENTA%^lie%^BLUE%^s%^CYAN%^, and in one section a bright %^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en %^CYAN%"+
   "^sun. One of the screens bears a cut hole in it, much like a window. Within their upper edges, two small %^BOLD%^%^BLACK%^f%^CYAN%^i%^BLACK%^xtu%^GREEN%^r%^BLACK%^es %^RESET%^%^CYAN%^are set, though you can't figure out quite what they are for.");

set_weight(3);
set_value(900);
}

void init(){
::init();
add_action("unfold","unfold");
}

int unfold(string str){
   object ob;
   if(!str)
      return notify_fail("Unfold what?");
      if((str=="wooden frame")) {
      if(!present("wooden frame",TP))
      return notify_fail("You don't have the frame to unfold.");
   ob=(present("wooden frame",TP));
   ob->move("/d/shadowgate/void");
   say("%^RESET%^%^ORANGE%^"+TPQCN+" unfolds the wooden frame out to reveal sturdy legs allowing it to stand at about 4 feet tall.%^RESET%^");
   write("%^RESET%^%^ORANGE%^You unfold the frame to reveal a set of sturdy legs, bringing it out to be about 4 feet tall.%^RESET%^");
   ob= new("/d/avatars/dinji/folded_screen.c");
   ob->move(TP);
   return 1;
}
}
