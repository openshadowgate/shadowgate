// using Circe's new version from slip the bonds, allows caster to choose when to use
#include <std.h>
inherit OBJECT;

void set_mycaster(object obj);
void set_mylevel(int x);
void end_it();

object mycaster, myspellob;
int mylevel,FLAG;

void create() {
   ::create();
   set_name("freedom");
   set_id(({"freedom_remotexoli"}));
   set_short("");
   set_long("");
   set_property("no animate",1);
   set_weight(0);
   //set_heart_beat(1);
   //FLAG = 0;
}

void init(){
   ::init();
   add_action("freeme","freeme");
}

void freeme(){
   if(!objectp(ETO)){
      return; 
   }
   if(!(string)ETO->query_paralyzed() && !(string)ETO->query_tripped()){
	tell_object(TP,"%^BOLD%^%^CYAN%^You are not tripped or paralyzed!%^RESET%^");
      return; 
   }
   tell_object(TP,"%^BOLD%^You release the focus hidden within your mind, "
      "refusing to bow to the force that tries to contain you!%^RESET%^");
   tell_room(EETO,"%^BOLD%^With a resolute expression, "+ETOQCN+" casts off "
      "the forces that try to contain "+ETO->QO+"!%^RESET%^",ETO);
   ETO->set_paralyzed(0);
   ETO->set_tripped(0);
   call_out("end_it",1);
   return;
}

/*
void heart_beat(){
   if(FLAG) return;
   if(!objectp(mycaster)) {
      call_out("end_it",1); 
      return; 
   }

   if(mycaster->query_paralyzed() && !(mycaster->query_property("memorizing"))){
      tell_object(mycaster,"%^CYAN%^Your blessing of freedom breaks "+
         "you out of your paralyzation!%^RESET%^");
      mycaster->set_paralyzed(0);
      FLAG = 1;
      call_out("end_it",1); 
      return; 
   }

   if(mycaster->query_tripped() && !(mycaster->query_property("memorizing"))){
      tell_object(mycaster,"%^CYAN%^Your blessing of freedom breaks "+
         "you out of your paralyzation!%^RESET%^");
      mycaster->set_tripped(0);
      FLAG = 1;
      call_out("end_it",1); 
      return; 
   }
   return;
}*/

void set_mycaster(object obj){
   mycaster = obj;
}

void set_mylevel(int x){
   mylevel = x*5;
}

void set_spellob(object spellob) {
   myspellob = spellob;
}

int drop(){
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }

int save_me(string file) { return 0; } // for some reason, these were saving in people's inventory.. like.. a lot of them

void end_it(){
   if(objectp(mycaster)){
      if(objectp(myspellob)) myspellob->dest_effect();
      mycaster->set_property("freedom time",time());
      mycaster->remove_property("freedom");
   }
   if(objectp(TO)) TO->remove();
   return;
}