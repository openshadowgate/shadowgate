#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("mark");
   set_id(({"mark","marking","pale mark","pale marking"}));
   set_short("a small pale marking");
   set_long("%^RESET%^%^ORANGE%^This is a small marking on the skin, almost a smudge.%^RESET%^\n");
   set_type("ring");
   set_limbs(({"left arm"}));
   set_weight(0);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_property("no remove",1);
   set_property("death keep",1);
   set_property("enchantment",-1);
   while((int)query_property("enchantment") >= 0){
     remove_property("enchantment");
     set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   ETO->set_property("hidden alignment",4);
   return 1;
}

int remove_fun() {
   ETO->remove_property("hidden alignment");
   return 1;
}