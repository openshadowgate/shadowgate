//Coded by Bane//
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"net","net of entrapment"}));
    set_name("net of entrapment");
    set_short("A small black net");
    set_long(
            "This is a net of entrapment.  You can <throw net at (target)> to "+
            "try and trap living objects in it.  It disappears after it traps its "+
            "victim."
            );
    set_weight(10);
    set_value(1000);
    set_size(1);

}


int thrown_hit(object ob) {

   TP->setAdminBlock(2);
    tell_object(ob,"%^BOLD%^GREEN%^"+TP->query_cap_name()+" tosses a magical net over you!");
    tell_object(TP,"%^BOLD%^GREEN%^You toss a magical net over "+ob->query_cap_name()+"!");
    tell_room(ETP,"%^BOLD%^GREEN%^"+TP->query_cap_name()+" tosses a magical net over "+ob->query_cap_name()+"!",({ob,TP}));
    ob->set_tripped(random(3)+4, "You are struggling to break free from the net!");
    TO->remove();
    return 1;
}

int get() {
   if (TP->query_paralyze() || TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("combat",TP);
      return 0;
   }
//  TP->set_paralyzed(6,"You are busy folding the net for a second throw.");
  TP->setAdminBlock(3);
  write("You begin folding the net back up.");
   message("combat",TPQCN+" begins folding a magic net back up as "+TP->query_subjective()+" takes it.",ETP,({TP}));
  return 1;
}
