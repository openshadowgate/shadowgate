// Lay on Hands for antipaladins
// By Grazzt@Shadowgate Sept 1996
// Based on Lay on Hands ability of paladins 
#include <std.h>
 
inherit DAEMON;
 
int cmd_cause(string str) {
    object ob;
    string str2;
 
    if(!TP->is_class("antipaladin"))
        return notify_fail("You are not an antipaladin and cannot do that!\n");
    if(!str) 
        return notify_fail("Usage: cause wracking pains <foe>\n");
    if(!sscanf(str, "wracking pains %s",str2)) 
        return notify_fail("Usage: cause wracking pains <foe>\n");
    if((int)TP->query_property("cause_pains_delay") > 0)
        return notify_fail("%^RED%^You must wait before the demons will allow you to cause wracking pains again.%^RESET%^\n");
    if(TP->query_ghost())
        return notify_fail("You are dead!\n");
    if(ETP->query_property("no attack"))
        return notify_fail("You cannot attack in this place.\n");
    if(TP->query_paralyzed()  || TP->query_bound()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!ob = present(str2,ETP)) 
        return notify_fail("That is not here!\n");
    if(!living(ob))
        return notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    if(ob == TP)
        return notify_fail("To yourself? Are you nuts?!?\n");
    if(ob->query_ghost()) 
        return notify_fail("You cannot do that to a ghost!\n");
    if(ob->is_player() && !interactive(ob))
        return notify_fail("You cannot attack link-dead players.\n");
    if(!TP->ok_to_kill(ob))
       return notify_fail("Supernatural forces stop your feeble attempt.\n");
    write("%^BOLD%^%^RED%^You summon the %^RESET%^%^MAGENTA%^demonic force%^BOLD%^%^RED%^ within you and touch "+(string)ob->query_cap_name()+" with an open hand!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" howls with demonic rage and touches "+(string)ob->query_cap_name()+" with an open hand!%^RESET%^",({TP,ob}));
    if(this_player() != ob) tell_object(ob,"%^BOLD%^%^RED%^"+TPQCN+" howls with demonic rage and touches you with an open hand!%^RESET%^");
    if(!ob->kill_ob(TP, 0)) return 1;
    ob->add_hp (-(2 * (int)TP->query_level()));
    TP->remove_property("cause_pains_delay");
    TP->set_property("cause_pains_delay",1000);
    TP->set_disable(4,ob);
    return 1;
}
 
void help() {
  write("Syntax: <cause wracking pains (player)>");
  write("  This will harm the player you choose, how much "
	"depending on your level. You will be required to wait "
	"a period of time before you may use this power again.");
  return 1;
}
