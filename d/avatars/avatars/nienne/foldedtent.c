#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("tent bag");
   set_id(({"tent","tent bag","bag","duffle bag","large bag"}));
   set_short("%^RESET%^%^ORANGE%^a large duffle bag%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a large %^BOLD%^%^BLACK%^duffle bag %^RESET%^%^ORANGE%^filled with "
"neatly rolled %^BOLD%^%^WHITE%^canvas %^RESET%^%^ORANGE%^and many sectional poles. On the side of the bag are "
"a series of %^BOLD%^%^BLACK%^stakes %^RESET%^%^ORANGE%^and lengths of coiled %^WHITE%^%^BOLD%^rope%^RESET%^"
"%^ORANGE%^.%^RESET%^");
   set_weight(3);
   set_value(400);
}

void init(){
   ::init();
   add_action("fold","unfold");
}

int fold(string str){
   if(!str)
      return notify_fail("Unfold what?\n");
   if(str != "tent")
      return notify_fail("You can't unfold that.\n");
   if(!userp(ETO))
      return notify_fail("You should pick that up first so you can set it up properly.\n");
   tell_room(EETO,""+TPQCN+" takes out a length of canvas, rope and some stakes, and starts setting up a "
"tent.",ETO);
   tell_object(ETO,"You take out a length of canvas, rope and some stakes, and start setting up a tent.");
   new("/d/avatars/nienne/tent")->move(EETO);
   TO->move("/d/shadowgate/void");
   return 1;
}