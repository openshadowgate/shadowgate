//Coded by Lujke
//This is a mark of disfavour from Mask. It removes a person's ability to
// sneak or to hide.

#include <std.h>
//#define DAY 24000

inherit "/std/armour";  // so it can be worn. :)

create() {
  ::create();
  set_name("");     //  set the name to ring
                        
  set_id(({"xxmarkxx"}));   

  set_short("");   
  set_long("");

  set_type("ring"); 
    
  set_ac(1);             
  set_weight(0);          
  set_value(0);         
  
  set_limbs(({"head"}));  
  set_property("enchantment",-1);
  set_property("no remove",1);
  if(query_property("enchantment") > 0){
      remove_property("enchantment");
      set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}
void init(){
  ::init();
  add_action("hide_func", "hide");
  add_action("sneak_func", "sneak");
  add_action("repent_func", "repent");
}


int hide_func()
{
  tell_object(ETO, "%^BOLD%^%^BLACK%^The shadows reject you%^RESET%^");
  return 1;
}

int sneak_func()
{
  tell_object(ETO, "%^BOLD%^%^BLACK%^The shadows reject you%^RESET%^");
  return 1;
}

int remove_func()
{
  tell_object(ETO, "%^BOLD%^%^BLACK%^The shadows shift around you. Perhaps"
                  +" all is well once more.");
  return 1;
}

void dest_effect(){
  TO->remove();
}

int repent_func(){
  remove_property("enchantment");
  set_ac(0); 
  tell_object(ETO, "%^BOLD%^%^BLACK%^You repent your transgressions");
  ETO->force_me("remove xxmarkxx");
  call_out("dest_effect", 1);
}



int wear_func()
{
  tell_object(ETO, "%^BOLD%^%^BLACK%^The shadows shift around you."
                 +" Something is wrong.");
  return 1;
}
