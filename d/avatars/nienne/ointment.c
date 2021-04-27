#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("ointment");
   set_id(({"vial","ointment","substance","yellow substance"}));
   set_short("%^RESET%^%^ORANGE%^A clear vial filled with a %^YELLOW%^thick "
"yellow ointment%^RESET%^");
   set_long("%^RESET%^This vial is made of %^BOLD%^%^CYAN%^clear glass"
"%^RESET%^, with a %^ORANGE%^cork stopper%^RESET%^. The ointment in it is "
"thick, with a slight scent of %^YELLOW%^beeswax %^RESET%^and a much "
"stronger, quite pungent, scent of %^ORANGE%^cloves %^RESET%^and %^GREEN%^"
"camphor%^RESET%^.");
   set_value(100);
   set_weight(1);
}

void init(){
   :: init();
   add_action("wear_per","wear");
}


int wear_per(string str){
   string long;
   if(str == "ointment" || str == "substance"){
     if(count > 4){
       tell_object(TP,"The vial of ointment is empty.");
       return 1;
     }
     tell_object(TP,"%^ORANGE%^The salve warms your skin as it is applied, "
"the heat growing %^RED%^searing %^ORANGE%^till it slowly fades.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" applies some rather pungent-smelling "
"salve.%^RESET%^",TP);
     long = TP->query_long();
     TP->set("long","%^YELLOW%^There is a faint, but pungent, smell of cloves "
"and camphor about "+TP->QO+".%^RESET%^");
     count++;
     return 1;
   }
   return 0;
}
