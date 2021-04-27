#include <std.h>
int hits;

inherit OBJECT;

object target;

void create() {
   ::create();
   set_name("rapierdam");
   set("id", ({ "remotexoli"}) );
   set_short("");
   set_long("");
   set_property("no animate", 1);
   set_weight(0);
   hits=random(10)+10;
   set_heart_beat(1);

}

void set_target(object obj)
{
    target = obj;
}

void heart_beat() 
{
   if(!objectp(ETO) || ETO != target){
      TO->move("/d/shadowgate/void");
      TO->remove();
      return;
   }

   if(hits<1)
   {
      TO->remove();
   return ;
   }  
   if(hits>0){
      tell_object(ETO,"%^RESET%^%^RED%^The torn wounds left from the rapier pulse with pain!%^RESET%^");
      ETO->do_damage("torso",1);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      hits --;
      return 1;
   }
}
