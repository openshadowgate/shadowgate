#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("canvas tent");
   set_id(({"canvas tent","tent","large tent","large canvas tent"}));
   set_short("%^BOLD%^%^WHITE%^a large canvas tent%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Before you stands a %^MAGENTA%^c%^RED%^a%^YELLOW%^r%^WHITE%^ni%^YELLOW%^v%^RED%^a"
"%^MAGENTA%^l %^WHITE%^sized tent positioned longways. The entrance to the tent consists of flaps that have "
"been neatly rolled up and tied off to the left and right of the main opening. Above the tent's entrance is a "
"large sign made on a piece of slightly curved %^RESET%^%^ORANGE%^wood %^BOLD%^%^WHITE%^in big bold common "
"letters that say %^MAGENTA%^'Help the Hopeless'%^WHITE%^. The tent itself spans several yards across with a "
"main center pole supporting it's center. The walls of the tent are made of a thick canvas that has been "
"%^RESET%^white washed %^BOLD%^%^WHITE%^through and through so as to make it easy to see, even with the "
"dimmest %^BLACK%^s%^WHITE%^t%^RESET%^a%^BOLD%^%^WHITE%^r%^BLACK%^li%^WHITE%^g%^BLACK%^ht %^WHITE%^at night."
"%^RESET%^");
   set_weight(9999);
   set_value(0);
}

void init(){
   ::init();
   add_action("fold","pack");
}

int fold(string str){
   object ob;
   if(!str)
      return notify_fail("Pack what?\n");
   if(str != "tent")
      return notify_fail("You can't fold that.\n");
   tell_room(EETO,""+TPQCN+" starts pulling down the tent, packing all the canvas and stakes into a bag.",ETO);
   tell_object(ETO,"You start pulling down the tent, packing all the canvas and stakes into a bag.");
   new("/d/avatars/nienne/foldedtent")->move(ETO);
   TO->move("/d/shadowgate/void");
   return 1;
}