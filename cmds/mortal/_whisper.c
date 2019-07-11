// mods by Styx for eavesdropping nwp (originally by Grendel as a guild command) 10/16/02
//modified to hopefully work with avsay to allow players to whisper "non-existent" avatar NPCS - Saide

#include <std.h>

inherit DAEMON;

void eavesdrop(object targ, string prefix, string msg);


int is_listening_immortal(object obj)
{
    if(!obj->query("listen_to_whispers")) { return 0; }
    if(!avatarp(obj)) { return 0; }
    return 1;
}

int is_listening_to(object obj, object *targs)
{
    int x;
    object *listening_to, targ;
    if(!avatarp(obj)) return 0;
    if(!obj->query("listening_to_whispers")) { return 0; }
    if(!pointerp(targs)) return 0;
    listening_to = obj->query("listening_to_whispers");
    if(!pointerp(listening_to)) return 0;
    for(x = 0;x < sizeof(targs);x++)
    {
        targ = find_player(targs[x]);
        if(!objectp(targ)) continue;
        if(avatarp(targ)) return 0;
        if(member_array(targs[x], listening_to) != -1) return 1;
        continue;
    }
    return 0;
}



int cmd_whisper(string str) 
{
   string who, msg, lang, pseudoname = 0;
   object ob, * people,*immortals,shape;
// adding for eavesdrop
//   object *list1, *list2;  // this is for when change to lists
   object lis1, lis2;
   mapping tmp;
   int i, x, pseudo;

   if (!str || sscanf(str, "%s %s", who, msg) != 2)  {
      notify_fail("usage: whisper <player> <message>\n");
      return 0;
   }
   if (TP->query_gagged()) {
      return notify_fail(TP->query_gagged_message()+"\n");
   }
   
   immortals = all_living(ETP);
   for(x = 0;x < sizeof(immortals);x++)
   {
       if(!avatarp(immortals[x])) continue;
       if(!mapp(tmp = immortals[x]->query("avsayprofile"))) continue;
       if(who == tmp["Character Name"]) 
       {
           who = lower_case(tmp["Character Name"]);
           ob = immortals[x];
           pseudo = 1;
       }
       else continue;
   }
   if(!objectp(ob)) 
   {
        who = lower_case(who);
        ob = present(who,ETP);
   }
   
   lang = TP->query_spoken();
    if(ob == TP) return notify_fail("You can whisper to yourself all you want, just don't whisper back.\n");
   
   if(!ob || !living(ob)) 
   {
      notify_fail(capitalize(who) +" does not appear to be within whispering distance.\n");
      return 0;
   }
   
   if(avatarp(TP))
   {    
       tmp = TP->query("avsayprofile");
       if(mapp(tmp))
       {
           pseudoname = tmp["Character Name"];
           lang = tmp["Language"];
           if(lang == "All" || "all") lang = "wizish";           
       }
   }
   
   immortals = all_living(ETP);
   immortals = filter_array(immortals,"is_listening_immortal",TO);
    "/adm/daemon/verboten.c"->test_verboten(str, TP, "whisper");
   //if(interactive(TP)) msg= "daemon/language_d"->translate(msg, lang,TP);

// nwp stuff to send msg to eavesdropper, we do want to let the speaker's language prof 
// (above) scramble if appropriate before passing it to the eavedropper *Styx*
   lis1 = TP->query_property("eavesdropper");
   lis2 = ob->query_property("eavesdropper");
   if(lis1 && objectp(lis1))      lis1->catch_eavesdrop(TP, ob, msg, lang);
   else if(lis2 && objectp(lis2)) lis2->catch_eavesdrop(TP, ob, msg, lang);

/* need to pass both objects & the message so we can check for the eavesdropper detecting invis.  Hopefully this works when I figure out how to make it handle a list of eavesdroppers
This is the start, but may need other stuff
    list1 = TP->query_property("eavesdropper");
    list2 = ob->query_property("eavesdropper");
// Automatically allow imms to hear whispers, except from other imms
// Added by Lujke 04 April 2007
  if (objectp(ETP) && !avatarp(TP)&& !avatarp(ob)){
    people = all_living(ETP);
    for (i=0;i<sizeof(people);i++){
      if (avatarp(people[i])){
        tell_object(people[i], "%^CYAN%^"+TPQCN + "%^RESET%^%^CYAN%^"
          +" whispers to " + ob->QCN + "%^RESET%^%^CYAN%^: %^RESET%^" 
          + msg);
      } 
    }
  }

// use filter_array instead (see /daemon/messaging_d.c) ?? - Garrett's suggestion
    if(list1) {
	i = sizeof(list1);
	while(i--) {
	   if(!objectp(list1[i]))  continue;
	   list1[i]->catch_eavesdrop(TP, ob, msg, lang);
        }
    }
    if(list2) {
	i = sizeof(list2);
	while(i--) {
	   if(!objectp(list2[i]))  continue;
	   list2[i]->catch_eavesdrop(TP, ob, msg, lang);
        }
    }
*/
// end nwps - check for invis of each, etc. & eavesdropper detecting invis in the persnoop
   if(ob == TP)
   {
	   tell_room(ETP,TPQCN+" whispers something to "+TP->query_objective()+"self.",TP);
      message("whisper", "%^CYAN%^You whisper to yourself%^RESET%^: "+msg, TP);
      return 1;
   }

   if(ob->query_invis() && !TP->detecting_invis() && !pseudo) 
   {
      notify_fail(capitalize(who)+" does not appear to be within whispering distance.\n");
// so it doesn't confirm to someone that they are thief hidden *Styx*  12/5/02
      if(ob->query_hidden())
      {
          if(stringp(pseudoname)) message("whisper", "%^BOLD%^%^CYAN%^"+capitalize(pseudoname)+" whispers to you: %^RESET%^"+msg,ob);
          else message("whisper","%^BOLD%^%^CYAN%^"+TPQCN+" whispers to you:  %^RESET%^"+msg,ob);
      }
      else
      {
          if(stringp(pseudoname)) message("whisper",capitalize(pseudoname)+" is unaware of whispering to you: " + msg,ob);
          else message("whisper",TPQCN+" is unaware of whispering to you: " + msg,ob);
      }
      return 0;
   }
        
   if(avatarp(ob) && pseudo)
   {
       message("whisper","%^BOLD%^%^CYAN%^"+TPQCN+" whispers to you:  %^RESET%^"+msg,ob);
       message("whisper", "%^BOLD%^%^CYAN%^You whisper to "+capitalize(who)+": %^RESET%^"+msg, TP);
       tell_room(ETP,"%^CYAN%^"+TPQCN+" whispers something to %^RESET%^" + capitalize(who)+".",({TP,ob}));
       if(sizeof(immortals))
       {
            for(i=0;i<sizeof(immortals);i++)
            {    
                tell_object(immortals[i],"%^RESET%^%^BOLD%^"+TP->QCN+" whispers to "+ob->QCN+": "+msg+"%^RESET%^");
            }
       }           
       return 1;
   }
   
   if(ob->is_player() && !interactive(ob)) 
   {
      notify_fail(ob->query_cap_name()+" is link-dead and cannot hear you.\n");
      return 0;
   }

   if(stringp(pseudoname)) message("whisper","%^BOLD%^%^CYAN%^"+capitalize(pseudoname)+" whispers to you: %^RESET%^"+msg,ob);
   else message("whisper","%^BOLD%^%^CYAN%^"+TPQCN+" whispers to you:  %^RESET%^"+msg,ob);
   if(avatarp(ob) && ob->query_disguised())
   {       
      message("whisper", "%^BOLD%^%^CYAN%^You whisper to "+capitalize(ob->query_vis_name())+": %^RESET%^"+msg, TP);
      tell_room(ETP,"%^CYAN%^"+TPQCN+ " whispers something to %^RESET%^" + capitalize(ob->query_vis_name())+".",({TP,ob}));
   }
   if(avatarp(TP) && stringp(pseudoname))
   {
       message("whisper", "%^BOLD%^%^CYAN%^You whisper to "+ob->QCN+": %^RESET%^"+msg, TP);
       tell_room(ETP,"%^CYAN%^"+capitalize(pseudoname)+ " whispers something to %^RESET%^" + ob->QCN+".",({TP,ob}));
   }
   else{
      message("whisper", "%^BOLD%^%^CYAN%^You whisper to "+ob->query_cap_name()+": %^RESET%^"+msg, TP);
      tell_room(ETP,"%^CYAN%^"+TPQCN+ " whispers something to " +ob->query_cap_name() +".",({TP,ob}));
   }

   if(sizeof(immortals))
   {
       for(i=0;i<sizeof(immortals);i++)
       {
           tell_object(immortals[i],"%^RESET%^%^BOLD%^"+capitalize(TP->query_name())+" whispers to "+capitalize(ob->query_name())+": "+msg+"%^RESET%^");
       }
   }
   
   immortals = filter_array(users(), "is_listening_to", TO, ({TP->query_name(), ob->query_name()}));
   if(sizeof(immortals))
   {
       for(i=0;i < sizeof(immortals);i++)
       {
           tell_object(immortals[i], "%^RESET%^%^BOLD%^"+capitalize(TP->query_name())+" whispers to "+capitalize(ob->query_name())+": "+msg+"%^RESET%^");
           continue;
       }
   }
   
   return 1;
}

void help() {
   write("Syntax: <whisper [player] [message]>\n\n"+
        "This command is used to whisper a message to another " 
        "player who is in the same room as you without other "
        "players being able to hear what you are saying.\n"
        "See also: say, emote, yell\n");
}

/* I think we want to go directly back to the persnoop mob with the info and skip this
  may want to put a couple of the checks above though
void eavesdrop(object targ, string prefix, string msg){
    object lis, per;

    lis = (object)targ->query_property("eavesdropper");
    per = (object)lis->query_caster();
    if(!objectp(lis) || !objectp(per)){
// need to only remove the specific one, not all eavesdroppers
      targ->remove_property("eavesdropper");
      return;
    }

    if(environment(lis) != environment(targ)) return;

    lis->catch_eavesdrop("%^BOLD%^%^CYAN%^You catch %^RESET%^"+msg);
    return;
}
*/