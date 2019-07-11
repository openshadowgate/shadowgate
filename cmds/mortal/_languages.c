#include <std.h>
inherit DAEMON;

int cmd_languages(string str){
   mapping skills;
   string *skillslist,mylang;
   int i,j,freelang,usedlang,points,newtotal,grammar;

   freelang = ((int)TP->query_age()) / 75000;
   usedlang = (int)TP->query("used language points");
   skills = TP->query_all_langs();
   skillslist = keys(skills);
   j = sizeof(skillslist);

   if(!str) { //commence display code
     tell_object(TP,"%^MAGENTA%^Your languages are as follows.");
     tell_object(TP, ""+arrange_string("Language",20)+arrange_string("prof. level", 15)+arrange_string("Language",20)+arrange_string("prof. level", 15)+"\n");
     for(i=0;i<j;i+=2){
       if(i+1 < j){
	   tell_object(TP, ""+arrange_string(skillslist[i],20)+arrange_string(skills[skillslist[i]]+"("+TP->query_grammar(skillslist[i])+")", 15)+arrange_string(skillslist[i+1],20)+arrange_string(skills[skillslist[i+1]]+"("+TP->query_grammar(skillslist[i+1])+")", 15));
       }
       else {
         tell_object(TP, ""+arrange_string(skillslist[i],20)+arrange_string(skills[skillslist[i]]+"("+TP->query_grammar(skillslist[i])+")", 15));
       }
     }
     tell_object(TP,"%^GREEN%^You are currently speaking in "+TP->query_spoken()+".\n");
     tell_object(TP,"%^ORANGE%^You have used "+usedlang+" of your total "+freelang+" language points.%^RESET%^");
     return 1;
   }
   str = lower_case(str);
   if(sscanf(str,"add %d to %s",points,mylang) != 2) return notify_fail("See <help languages> for syntax.\n");
   if(member_array(mylang,skillslist) == -1) return notify_fail("You don't know "+mylang+".\n");
   if(points < 1) return notify_fail("You can only add a positive number of points to a language.\n");
   newtotal = skills[mylang] + points;
   if(newtotal > 100) return notify_fail("There's no point taking a language above 100%.\n");
   if((usedlang+points) > freelang) return notify_fail("You don't have that many free points to spend.\n");
   grammar = (int)TP->query_grammar(mylang);
   TP->set_lang(mylang,newtotal);
   TP->set_grammar(mylang,grammar);
   TP->set("used language points",(usedlang+points));
   tell_object(TP,"%^BOLD%^%^WHITE%^You have increased your understanding of "+mylang+" by "+points+" points.%^RESET%^");
   return 1;
}

void help(){
    write(
"
%^CYAN%^NAME%^RESET%^

languages - display your languages

%^CYAN%^DESCRIPTION%^RESET%^

This command will display languages you know, you can choose what you say with %^ORANGE%^<speak %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

speak, speech, line use
"
);
}

