
#include <std.h>
#include <daemons.h>

inherit ARMOUR;
void create(){
   ::create();
   set_name("mark");
   set_id(({"mark"}));
   set_short("");
   set_long("");
   set_type("ring");
   set_property("enchantment",1);
   set_limbs(({ "right hand" }));
   set_ac(1);
   set_size(2);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}
int wear_func(){
   ETO->set_property("no knockdown",1);
   ETO->set_property("no shieldbash",1);
   ETO->set_property("no stun",1);
   ETO->set_property("no paralyze",1);
   set_hidden(1);
   return 1;
}

int remove_func(){
   ETO->set_property("no knockdown", -1);
   ETO->set_property("no shieldbash", -1);
   ETO->set_property("no paralyze", -1);
   ETO->set_property("no stun", -1);
   set_hidden(0);
   return 1;
}

int is_detectable()
{
        return !query_worn();
}
