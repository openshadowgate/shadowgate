#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("birthday box");
   set_id(({"box","birthday box"}));
   set_short("%^RESET%^%^CYAN%^a birthday box!%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a little wooden box that someone has "
"crayon'ed brightly.  Flowers and unicorns and dingos and pies have been "
"painted on the sides, and %^YELLOW%^'Happy birthday Hashi!'%^WHITE%^ is "
"scrawled across the top.  Looking inside the box, you find a %^CYAN%^babu head"
"%^WHITE%^.  It seems to be just waiting to be lobbed at a player, if you "
"wanted to %^YELLOW%^grab %^WHITE%^it and do just that!%^RESET%^");
   set_weight(0);
   set_value(0);
}

void init() {
   ::init();
   add_action("grab_fun","grab");
}

int grab_fun(string str) {
   object ob;
   if(TP != ETO) return 0;
   if(!str) return 0;
   if(str != "a head" && str != "head") return 0;
   tell_object(TP,"You grab a head out of the birthday box, ready to throw at "
"someone!");
   ob = new("/std/obj/body_part");
   ob->set_limb("Babu","head");
   ob->move(TP);
   return 1;
}
