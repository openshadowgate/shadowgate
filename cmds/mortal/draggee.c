#include <std.h>

inherit OBJECT;

object draggee;

void create(){
   ::create();

   set_name("draggee");
   set_short("draggee");
   set_long("draggee");
   set_id(({"draggee"}));
   set_property("no animate",1);
    set_property("no offer",1);

}

void set_draggee(object ob){
   if (!objectp(ob)) {
      return;
   }

   draggee = ob;
   if (draggee->query_disguised()) {
      set_name(draggee->setParsableName());
      add_id(draggee->query_name());
   }
    add_id(draggee->query_race());

   draggee->set_property("draggee",TO);
   set_short("Dragging "+draggee->query_short());
   set_long(draggee->query_long());
   switch (draggee->query_size()) {
   case 1:
      set_weight(50);
      break;
   case 2:
      set_weight(100);
      break;
   case 3:
      set_weight(150);
      break;
   case 4:
      set_weight(200);
      break;
   }
   set_heart_beat(1);
}

int drop(){
   if (query_verb() == "give") {
      write("You will need to drop the poor soul and have the other person pick "+draggee->query_objective()+" up.");
      return 1;
   }


   if (query_verb() == "put") {
      write("Your gonna put "+draggee->query_objective()+" into where?");
      return 1;
   }
   ETO->set_draggee(0);
   set_short(draggee->query_short());
   draggee->remove_property("draggee");
   return 0;
}

void init(){
   ::init();

   if (!living(ETO)) {
      if (objectp(draggee)) {

         draggee->remove_property("draggee");
      }
      remove();
   }
}

void heart_beat(){
   if (!objectp(draggee)) {
      if(userp(ETO)) ETO->set_draggee(0);
      remove();
      return;
   }
   if (draggee->query_ghost()) {

      draggee->remove_property("draggee");
      if(userp(ETO)) ETO->set_draggee(0);
      remove();
      return;
   }

   if (!draggee->query_bound() && !draggee->query_unconscious()) {
      tell_object(ETO,draggee->query_short()+" struggles free of your grip.");
      tell_object(draggee,"You struggles free of "+ETO->query_cap_name()+" grip.");
      draggee->remove_property("draggee");
      ETO->set_draggee(0);
      remove();
   }
}


int save_me(string file){
   return 1;
}
