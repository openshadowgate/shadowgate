#include <std.h>
#include <daemons.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("mark");
   set_id(({"mark","marking","dark marking"}));
   set_short("a small dark marking");
   set_long("%^RESET%^%^ORANGE%^This is a small marking, like a smudge or skin discoloration.%^RESET%^\n");
   set_type("ring");
   set_limbs(({"left arm"}));
   set_weight(0);
   set_value(0);
   set_size(1);
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
   tell_object(ETO,"%^ORANGE%^The mark adheres to your skin.%^RESET%^");
   ETO->set_property("hidden alignment",6);
   return 1;
}

int remove_fun() {
   ETO->remove_property("hidden alignment");
   return 1;
}