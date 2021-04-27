// coppied code from N's golem rod
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("brain in a jar");
    set_id(({ "brain","jar","brain in a jar" }));
    set_short("Brain in a jar");
    set_obvious_short("Jar of Illithid");
    set_long("%^ORANGE%^This is a strange jar filled"+
	" with a yellow liquid.  There is a pulsing brain"+
	" suspended in the liquid with a dirty cork cap "+
	"on top of it.  Perhaps you could read jar.%^RESET%^\n");
    set("read","%^BOLD%^%^WHITE%^The liquid resolves into two "
"words before your eyes:\n\n%^BOLD%^%^WHITE%^-%^YELLOW%^use jar%^WHITE%^-%^RESET%^");
    set_lore("This jar holds part of a brain of an illithid hive mind."+
	"  It may be used to draw up an illithid servant.  "+
	"The servant of the vase may be asked to <lead>, "+
	"<unlead>, <protectem>,or perform small tasks <illemote>.");
    set_property("lore difficulty",25);
    set_weight(1);
    set_language("wizish");
    set_value(1602);
    set_property("death keep",1); 
    set_weight(15);
    set_property("enchantment",-1);
}

void init() {
    ::init();
    add_action("my_conjure","use");

}

int my_conjure(string str) {
   object ob;
   if(!str) {
     tell_object(TP,"Use what?");
     return 1;
   }
   if(str != "jar") {
     tell_object(TP,"You can't use that.");
     return 1;
   }
   if(present("illithid")) return 1;
   tell_room(ETP,"%^BOLD%^%^WHITE%^You focus on the jar and an Illithid appears!%^RESET%^");
   ob=new("/d/avatars/hades/ill");
   ob->move(ETP);
   ob->set_owner((string)TP->query_name());
   return 1;
}
