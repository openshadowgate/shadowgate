//_protect.c

#include <std.h>

inherit DAEMON;

int cmd_protect(string str){
  object ob, protectee;

   if(!str) return notify_fail("Protect who?\n");


   if (TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   protectee=find_player((string)TP->realName(str));
   if( (!objectp(protectee)) || (!ob = present(protectee, ETP))) {
     if (!ob = present(str,ETP))
       return notify_fail("You can't seem to find that to protect.\n");
   }
   //if (!objectp(ob))
   //  return notify_fail("You can't seem to find that to protect. 2\n");
   if(!newbiep(TP)  && newbiep(ob) )
      return notify_fail("You can only protect those of your social status.\n");

   if(ob == TP)
      return notify_fail("Yeah, right.  NOT!\n");

   //if(!interactive(ob) && (!ob->is_npc()) && (!(ob->is_animal() && ((object)ob->query_owner() == TP)) ) ) 
    //  return notify_fail("You can't seem to protect that.\n");

    if(!living(ob))
    {
        tell_object(TP, "You can only protect living creatures!");
        return 1;
    }

   if(member_array(ob, TP->query_attackers()) != -1)
   {
       tell_object(TP, "You cannot protect something that you are already fighting!");
       return 1;
   }
   if(interactive(TP) && member_array(ob,TP->query_protectors()) != -1)
      return notify_fail("They're trying to protect you!\n");

   if((int)TP->query_stats("intelligence") < random(15)){
     write("You can't find a good way to protect "+ob->query_cap_name()+"!!\n");
     return 1;
   }

   tell_room(ETP,"%^RED%^"+TPQCN+" stands boldly in protection of "+ob->query_cap_name()+"!",({ob,TP}));
   tell_object(ob,"%^RED%^"+TPQCN+" stands boldly in protection of you.");
   write("%^RED%^You boldly stand in protection of "+ob->query_cap_name()+".");
   ob->add_protector(TP);
   return 1;
}

int help() {
   write(
@HELP
   Command: protect
   Syntax: protect <player | npc | pet>

   This command allows you to protect another player from that
   player's current enemies.  This is useful for those who are
   about to die, or magi who need to maintain concentration in
   order to cast a spell.  Of course, you can't indefinitely
   protect a person from an enemy you cannot kill before you are
   worn out.  So therefore, one by one, the enemies you are
   blocking may slip past you.

  NOTE: You can protect pets that you own, as well as NPC's now.
See also: unprotect, wimpy, wimpydir, follow, party, kill
          fighters also have "rescue"
HELP
   );
   return 1;
}
