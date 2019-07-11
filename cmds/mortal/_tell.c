#include <std.h>
#include <daemons.h>
#include <tell.h>

inherit DAEMON;

int imm_filter(object obj,string *targ)
{
	string *listening=({});

	if(!objectp(obj)) { return 0; }
	if(!avatarp(obj)) { return 0; }
	if(!pointerp(obj->query("listen_tells"))) { obj->set("listen_tells",({})); }
	listening = (string *)obj->query("listen_tells");
	if(member_array(targ[0],listening) == -1 && member_array(targ[1],listening) == -1) { return 0; }
	return 1;
}

void tell_listening_immortals(string mess,object teller,object listener)
{/*
	object *listening_imms=({});
	string teller_name,listener_name;
	int i;

	if(!stringp(mess)) { return; }
	if(!objectp(teller)) { return; }
	if(!objectp(listener)) { return; }
	if(avatarp(teller) || avatarp(listener)) { return; }

	teller_name = lower_case(teller->query_true_name());
	listener_name = lower_case(listener->query_true_name());

	listening_imms = children("/std/user.c");
	listening_imms = filter_array(listening_imms,"imm_filter",TO,({ teller_name,listener_name }));

	if(!sizeof(listening_imms)) { return; }

	for(i=0;i<sizeof(listening_imms);i++)
	{
		tell_object(listening_imms[i],""+capitalize(teller_name)+" tells "+capitalize(listener_name)+": "+mess+"\n");
	}
	return;*/
}
	



object resolve_tell_playerob(string whom) { 
  object ob;
  string real_whom, whom2;

  ob = find_player(whom2=lower_case(whom));
//  real_whom=TP->realName(whom2);
// Moved lower due to Grendel bugging on it... Not sure why.

  if (objectp(ob) && (avatarp(ob) || avatarp(TP)))
    return ob;
  real_whom=TP->realName(whom2);
  if (objectp(ob = find_player(real_whom)))
    return ob;
}

object resolve_tell_living(string whom, string verbiage) {
  string whom2, mess2;
  object ob;

if (sscanf(verbiage,"%s %s", whom2, mess2) != 2) whom2 = verbiage;
  if (objectp(ob=find_living(capitalize(whom))))
    return ob;
  if (objectp(ob=find_living(capitalize(whom)+" "+capitalize(whom2))))
    return ob;
  return 0;
}

int cmd_tell(string str) {
  string tell_msg, who, target, msg;
  string namestr;
  string *ignored;
  object ob;
  //  string translated_real_who, mud;
  
  if (!str || sscanf(str,"%s %s",who,msg) != 2) {
    notify_fail("usage: tell <player> <message>\n");
    return 0;
  }
  
  /*  Fuck this, we're not going to use it and it's breaking my mods.
   *  - Garrett 10/18/2001.
   *
   *  if (sscanf(lower_case(who),"%s@%s",target,mud) == 2) {
   *    if (!NETWORK_D->mud_exists(mud))
   *      return notify_fail("That mud is not listed with "+mud_name()+".\n");
   *    SERVICES_D->send_gtell(mud, target, msg);
   *    return 1;
   *  }
   */
  

  /****************************
  ob = find_player(who=lower_case(who));
  translated_real_who=TP->realName(who);
  
  if (!objectp(ob) || (!avatarp(ob) && !avatarp(TP))) {
    if (!(ob = find_player(translated_real_who))) {
   
  ****************/
  if (!objectp(ob=resolve_tell_playerob(who))) {
    if (!objectp(ob=resolve_tell_living(who, msg))) {
      notify_fail(capitalize(who)+NOT_HERE+"\n");
      // This line causes a bug where you can 'tell' someone who's online and
      // it'll return 'What?", or you tell someone who's offline, and it 
      // returns that they're not here.

      return 0;
    } else {
   if (!ob->is_npc_psychic())
     return notify_fail(capitalize(who)+NOT_HERE+"\n");
  }
  }
  if(ob->is_npc_psychic())
    sscanf(str,lower_case(ob->query_true_name())+" %s",msg);

  if (!avatarp(TP) && !avatarp(ob) 
      && !(pointerp(TP->query_property("allowed tell")) 
	&& member_array(ob->query_true_name(), (string *)TP->query_property("allowed tell")) != -1)) {
    notify_fail("What?");
    return 0;
  }
   
  "/adm/daemon/verboten.c"->test_verboten(str, TP, "reply");

  if(ob->query_true_invis() || TP->query_true_invis() || avatarp(TP) || avatarp(ob)) {} // empty intentionally
  else
  {
      if((TP->query_property("shapeshifted")) && (!FEATS_D->usable_feat(TP,"wild speech")))
      {
          tell_object(TP,"You can't send tells while shapeshifted.");
          return 1;
      }
    //msg= "daemon/language_d"->translate(msg, TP->query_spoken(), TP);
  }

  ignored = ob->query_ignored();
  if (!ignored) {
    TP->reset_ignored();
    ignored = TP->query_ignored();
  }

  //  if (who == (string)TPQN)
  //    return notify_fail("Crazy eh?\n");

  if(wizardp(ob) && (ob->query_highest_level() > TP->query_highest_level()) && (!member_group(getuid(TP), "superuser")) ){
    if(TP->query_invis())
      namestr = "("+capitalize(TPQN)+")";
    else
      namestr = capitalize(TPQN);
  } else {
    namestr = capitalize(TP->getParsableName());
  }

  if ( (int)ob->query_quietness() && wizardp(ob) && !wizardp(TP) ) {
    message("info", sprintf("%s%s", capitalize(who), NOT_HERE),
	    this_player());
    return 1;
  }

  if (ob->query_invis() && (int)ob->query_level() > (int)TP->query_level() && !member_group(getuid(TP), "superuser")) 
  {
    message("info", sprintf("%s%s", capitalize(who), NOT_HERE),this_player());

    if (member_array(TPQN, ignored) == -1 || wizardp(TP)) 
	{
      message("reply", sprintf("%s is unaware of telling you: %s", namestr, msg), ob);
	  tell_listening_immortals(msg,TP,ob);
      if (!TP->query_disguised() || !wizardp(TP)) 
	  {
		ob->set("reply", TP->getParsableName(ob));
      } else {
		ob->set("reply",this_player()->query_vis_name());
      }
      ob->set("reply object",TP);
    }
    return 1;
  }

  if (ob->query_blocked("reply") && !avatarp(TP)) {
    write(ob->query_cap_name()+" is currently blocking all tells.");
    return 1;
  }

  if (ob->is_player() && !interactive(ob)) {
    notify_fail(ob->query_cap_name()+" is link-dead and cannot hear you.\n");
    return 0;
  }

  if ((member_array(TPQN, ignored) != -1) && !wizardp(TP)) {
    write(capitalize(ob->query_name())+" is ignoring you.");
    return 1;
  }

  message("reply", "%^BOLD%^%^RED%^"+ namestr + " tells you: %^RESET%^"+msg, ob);
  tell_listening_immortals(msg,TP,ob);
  if (!TP->query_disguised() || !wizardp(TP)) {
    ob->set("reply", TP->getParsableName(ob));
  } else {
    ob->set("reply",this_player()->query_vis_name());
  }
  ob->set("reply object",TP);

  if(TP->query_blocked("reply")) TP->set_blocked("reply");
  if(ob->is_npc_psychic()) {
    message("reply","%^BOLD%^%^RED%^You tell "+ob->getParsableName()+"%^RESET%^: "+msg,TP);
  } else {
    message("reply","%^BOLD%^%^RED%^You tell "+capitalize(who)+"%^RESET%^: "+msg,TP);
  }

    if(!wizardp(ob) && !wizardp(TP) && !ob->query_true_invis() && !TP->query_true_invis())
      CHAT_D->force_chat(TP,"telepathy","tells "+ob->QCN+" ( "+msg+" )",1);

  if (!ob->is_player()) return 1;
  if (query_idle(ob) > IDLE_TIME)
    write(capitalize(who)+
	  " is idle, and may not have been paying attention.");
  if (in_edit(ob) || in_input(ob))
    message("info",capitalize(who)+" is in edit and may "+
	    "not be in a position to respond.", this_player());
  return 1;
}



void help() {
  message("help",
	  "Syntax: <tell [player] [message]>\n"
	  "        <tell [player]@[mud] [message]>\n\n"
	  "Please note that tells only work when in telepathic communication with a person."
	  "\n"
	  "Sends the message to the player named either on this mud if no "
	  "mud is specified, or to the player named on another mud when "
	  "another mud is specified.\n\n"
	  "See also: say, shout, yell, emote", this_player()
          );
}
