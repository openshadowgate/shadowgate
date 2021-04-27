#include <std.h>
inherit "/d/magic/spellbook";

void init() {
string *mastered;
int i, masterflag;
   ::init();
   if((string)TP->query_name() == owner) {
     mastered = ({});
     masterflag = 0;
     if(sizeof(TP->query_mastered_spells())) {
       mastered += (string)TP->query_mastered_spells();

       for(i = 0;i < sizeof(mastered); i++) {
         if(member_array(mastered[i],keys(spells)) == -1) {
           set_spellbook(mastered[i]);
           masterflag = 1;
         }
       }
       if(masterflag) tell_object(TP,"Mastered spells added successfully!");
     }
   }
}
