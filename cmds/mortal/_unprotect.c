//_unprotect.c

#include <std.h>

inherit DAEMON;

int cmd_unprotect(string str){
  object ob, unprotectee;

  if(!str) return notify_fail("Unprotect who?\n");
  unprotectee = find_player((string)TP->realName(str));
  if( (!objectp(unprotectee)) || (!ob = present(unprotectee, ETP))) {
    if (!ob = present(str,ETP))
      return notify_fail("You can't seem to find that to unprotect.\n");
  }

  if(!interactive(ob) && (!ob->is_npc()) && (!(ob->is_animal() && ((object)ob->query_owner() == TP)) ) )
    return notify_fail("You can't seem to unprotect that.\n");


  if ( (member_array(TP,(object *)ob->query_protectors()) == -1))
    return notify_fail("You aren't protecting them!");

  tell_room(ETP,"%^RED%^"+TPQCN+" stops protecting "+ob->query_cap_name()+" and goes back to "+TP->query_possessive()+" own business.",({ob,TP}));
  tell_object(ob,"%^RED%^"+TPQCN+" stops protecting you and goes back to "+TP->query_possessive()+" own business.");
  tell_object(TP,"%^RED%^You stop protecting "+ob->query_cap_name()+".");
  ob->remove_protector(TP);
  return 1;
}

int help() {
  write(
@HELP
	Command: unprotect
	Syntax: unprotect <player | npc | pet>

	This command allows you to stop protecting an other player you are
	already protecting.

        You can also protect pets of yours. (paladin's horses) as well as NPC's.
	See also: protect, wimpy, wimpydir, follow, party, kill
HELP
	);
  return 1;
}
