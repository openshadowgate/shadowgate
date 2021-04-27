#include <std.h>
int hits;




inherit OBJECT;

void create() {
   ::create();
   set_name("arrowdam");
   set("id", ({ "arrowdam"}) );
   set_short("");
   set_long("");
   set_property("no animate", 1);
   set_weight(0);
   hits=random(10)+10;
   set_heart_beat(1);

}
void heart_beat() {
   if(!objectp(ETO)){
   return ; 
   }
   if(hits<1){
      TO->remove();
   return ;
   }  
   if(hits>0){
      tell_object(ETO,"%^RESET%^%^RED%^The fire caused by the arrow continues to burn into your skin!%^RESET%^");
      ETO->do_damage("torso",1);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      hits --;
      return 1;
   }
}