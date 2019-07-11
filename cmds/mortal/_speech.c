//_speech.c

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_speech(string str)
{
    object desc;
   string speech, describe;

   desc = new(DESC_D);

   if(!str || str == ""){
      TP->set("speech string",0);
      TP->set("describe string",0);

      desc->set_profile_stuff(0,"speech string",TP);
      desc->set_profile_stuff(0,"describe string",TP);


      tell_object(TP,"Your speech has been reset to <say>");
      return 1;
   }

   if(sscanf(str, "%s %s",speech,describe) != 2){
      speech = str;
   }

    TP->set("speech string",speech);
    TP->set("describe string",describe);

    desc->set_profile_stuff(speech,"speech string",TP);
    desc->set_profile_stuff(describe,"describe string",TP);

   tell_object(TP,"Your speech is now set to <"+str+">.");
   return 1;
}

int help(){
   write(
@OLI
   speech <emote>
   This will set your speech verb. Currently set to says
   <speech wail>
   will appear to others as
   Bob wails: hey there

   <speech wail loudly>
   will appear to others as
   Bob wails loudly: hey there
OLI
   );
   return 1;
}
