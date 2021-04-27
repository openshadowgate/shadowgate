// coppied code from N's golem rod
#include <std.h>
inherit OBJECT;

int full = 1;

void create() {
    ::create();
    set_name("blue vase");
    set_id(({ "vase","blue vase","water elemental base" }));
    set_short("%^BOLD%^%^WHITE%^Vase of %^RESET%^%^CYAN%^W%^BOLD%^a%^RESET%^%^CYAN%^ter Control%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^a %^RESET%^%^CYAN%^p%^BOLD%^a%^RESET%^t%^CYAN%^tered blue vase%^RESET%^");
    set_long("%^CYAN%^ This light blue vase is about three feet "+
	"in height with a diameter of about a foot and a half. "+
	"It is etched all around with darker blue patters of waves."+
	"  The finish is polished to a shimmer in light and it is "+
	"smooth, glass-like to the touch.  At the top there is "+
	"a sloping spout for pouring out the water.  On the other"+
	" side, there is a long handle that can be used to carry it."+
	"  The waves seem almost to move on their own reminding one "+
	"of a shore with breakers crashing into the water. %^RESET%^\n");
    set("read","%^BOLD%^%^WHITE%^The waves resolve themselves into two "
"words before your eyes:\n\n%^BOLD%^%^WHITE%^-%^YELLOW%^pour vase%^WHITE%^-%^RESET%^");
    set_lore("Your hold in your hands an ancient relic of the "+
	"faith of Istishia. The lady of waters has channelled part"+
	" of her power into the water which flow from this vase. "+
	"In times of need, such relics could call forth mighty servants "+
	"of the waves to protect Istishian clerics. When the vase has "+
	"run dry they must be refilled once again in the Temple of "+
	"Istishia to restore their powers. Little is remembered of "+
	"how such powerful artifacts came into being, but they are "+
	"sacred to Istishian clerics and woe be to the unbeliever "+
	"who came into possession of such a vase without their blessing.  "+
	"The servant of the vase may be asked to <follow>, "+
	"<unfollow>, <protectme>,or perform small tasks <elementalemote>.");
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
    add_action("my_conjure","pour");
	add_action("fill_em","fill");
}
void fill_em(){
  if(base_name(EETO) != "/d/magic/temples/istisha") 
  return notify_fail( "The vase refuses to be filled with this water");
  write("You fill the vase with water from the temple");
  full = 1;
}

int my_conjure(string str) {
   object ob;
   if(!str) {
     tell_object(TP,"Summon what?");
     return 1;
   }
   if(str != "vase") {
     tell_object(TP,"You can't summon that.");
     return 1;
   }
   if(!full) {
     tell_object(TP,"The vase has no water in it.");
     return 1;
   }
   full = 0;
   tell_room(ETP,"%^BOLD%^%^WHITE%^The waves on the vase %^BLUE%^splash %^WHITE%^"
"to life, water pours out and pools on the ground."
"%^CYAN%^. A massive form begins to solidify before you.%^RESET%^");
   ob=new("/d/avatars/hades/w_ele");
   ob->move(ETP);
   ob->set_owner((string)TP->query_name());
   return 1;
}
