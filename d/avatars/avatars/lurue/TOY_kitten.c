#include <std.h>
inherit OBJECT;
int squeeze;

void create(){
	::create();
	set_name("stuffed kitten toy");
	set_id(({ "stuffed toy", "kitten", "stuffed kitten", "toy", "kitten", "stuffed kitten toy", "stuffed animal" }));
	set_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a kitten%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a kitten%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This little white cotton toy is shaped like a kitten and has been stuffed with lots of soft cotton to make it squeezable. Small %^CYAN%^blue buttons %^WHITE%^have been used to make the eyes of this toy, while a %^MAGENTA%^pink button %^WHITE%^was used to make the nose. %^BLACK%^Black yarn %^WHITE%^has been sewn along the mouth line and curls up at either end in a smile. A bright %^MAGENTA%^pink bow %^WHITE%^has been tied around the toy's neck to add contrast to the white body. %^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(300);
}

void init(){
   ::init();
   add_action("squeeze","squeeze");
}

int squeeze(string str) {
   if(!str) {
      notify_fail("Squeeze what?");
   }
   if (TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(str != "belly") {
      notify_fail("Squeeze what?");
      return 0;
   }
   say("%^BOLD%^%^WHITE%^"+TPQCN+" squeezes the soft belly of the kitten and it goes%^RESET%^ ' %^BOLD%^%^CYAN%^meow%^RESET%^ '");
   write("%^BOLD%^%^WHITE%^You squeeze the soft belly of the kitten and it goes%^RESET%^ ' %^BOLD%^%^CYAN%^meow%^RESET%^ '");
    return 1;
}
