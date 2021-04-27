// custom tiefling item for Enenra to cover trait brimstone smell
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("horns");
   set_id(({"horns","small horns"}));
   set_short("%^BOLD%^%^BLACK%^two small black horns%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This pair of small horns are %^BOLD%^%^BLACK%^jet black%^BOLD%^%^WHITE%^, flecked with traces of "
"%^BOLD%^%^RED%^crimson%^BOLD%^%^WHITE%^, that jut out naturally from their owner's forehead.  They are small, but not so small "
"that they can be effectively hidden behind the veil of %^BOLD%^%^BLACK%^glossy black hair %^BOLD%^%^WHITE%^that parts to either "
"side of them like a wave.%^RESET%^\n");
   set_weight(1);
   set_value(0);
   set_type("ring");
   set_limbs(({"head"}));
   set_property("death keep",1);
   set_property("no animate",1);
   set_size(-1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme(string str){
   TO->set_overallStatus(100);
   ETO->set("long","%^RESET%^%^RED%^The smell of sulfur and brimstone surrounds "+capitalize(nominative(ETO))+".%^RESET%^");
   return 1;
}

int unwearme(string str){
   ETO->set("long",0);
   return 1;
}