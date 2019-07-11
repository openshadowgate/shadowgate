/*  _steal.c
 *  Rogue ability
 *  coded by Descartes of Borg October 1992
 *  small modifications by Hanse November 1992
 *  changed to make stealing harder for non-rogues and to allow
 *  the stealing of wielded/worn objects by powerful rogues
 *  by Gregon October 1993
 *  Heavily revised by Bohemund March 1994
 *    - check for available light
 *    - removed useless variables
 *    - added a function to handle the moving of the stolen object
 *    - cleaned up messages
 *    - checked weight of item being stolen (heavier = harder)
 *    - revised the way wielded/worn items are stolen (monster now
 *      attacks when the player fails)
 *    - alignment is calculated (randomly 1-10) depending on the
 *      alignment of the victim (i.e. stealing from good beings
 *      makes you more evil and stealing from evil beings makes
 *      you good)
 *    - added defines for easier configuration
 *  Slightly modified by Bohemund March 1994
 *    - check if monster does not allow stealing
 *    - neaten up a string or two
 */

#include <std.h>
#define WEIGHT_PENALTY 20
#define INVIS_PENALTY 75
#define WIELD_PENALTY 50
#define WORN_PENALTY 75

inherit DAEMON;

void check_caught(int roll, object target, object ob);
 
int cmd_steal(string str) {
  object *inv, victim, ob;
  string what, whom;
  int i, skip, which, steal, x, align_formula;

/* Various checking */
  if(TP->query_ghost()) {
    notify_fail("You cannot do that in your immaterial state.\n");
    return 0;
  }

   if (TP->query_bound() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

  if(ETP->query_property("no steal")) {
    notify_fail("A magic force prevents you from doing that!\n");
    return 0;
  }
  if(!str) {
    notify_fail("Steal what from whom?\n");
    return 0;
  }
  if(TP->query_disable()) return 1;
  if(sscanf(str, "%s from %s", what, whom) != 2) {
    notify_fail("Steal what from whom?\n");
    return 0;
  }
  if(TP->query_current_attacker()) {
    notify_fail("You cannot do that while in combat!\n");
    return 0;
  }                                                                             
  victim = present(whom, ETP);
  if(!victim) {
    notify_fail(capitalize(whom)+" is not here!\n");
    return 0;
  }
  if(!living(victim)) {
    notify_fail(capitalize(whom)+" is not a living thing!\n");
    return 0;
  }
  if(victim->is_player() && !interactive(victim)) {
    notify_fail("You cannot steal from link-dead players.\n");
    return 0;
  }
  if(TP->query_lowest_level()<6 && interactive(victim)){
     notify_fail("You haven't learned enough to try that yet.\n");
      return 0;
   }
     if(!TP->ok_to_kill(victim)) return notify_fail("Super natural forces prevent you.\n");
  TP->set_disable();
  if(wizardp(victim)) {
      tell_object(victim,TPQCN+" just tried to steal from you... break "+TP->query_possessive()+" arms.\n");
      notify_fail(victim->query_cap_name()+" is going to hurt you when "+victim->query_subjective()+" gets this message.\n");
    return 0;
  }
  if(interactive(victim) && ((string)victim->query_position() == "newbie"  
     && (string)TP->query_position() != "newbie")){      
    notify_fail("Let the newbie alone!\n");
    return 0;
  }
  if(victim->query_property("no steal")) {
    notify_fail((string)victim->query_cap_name()+" cannot be stolen from!\n");
    return 0;
  }
  if(total_light(TP) < -1) {
    notify_fail("It is too dark.\n");
    return 0;
  }
  ob = present(what, victim);
  if(victim == TP) {
    notify_fail("Steal from yourself?\n");
    return 0;
  }
  if(!ob) {
    inv = all_inventory(victim);
    if(sscanf(what, "%s %d", what, which) != 2) {
      notify_fail(capitalize(whom)+" does not have that!\n");
      return 0;
    }
    for(i=0, skip=0; i<sizeof(inv) && !ob; i++) {
      if(inv[i]->id(what)) {
        skip ++;
        if(skip == which) ob = inv[i];
      }
    }
    if(!ob) {
      notify_fail(capitalize(whom)+" does not have that!\n");
      return 0;
    }
  }
  if(!ob->get()) {
    notify_fail("You cannot steal that!\n");
    return 0;
  }
  if(ob->query_property("no steal")) {
    write((string)victim->query_cap_name()+"'s "+(string)ob->query_name()+" cannot possibly be stolen.");                                       
    return 1;
  }

/* Calculations */
  steal = (int)TP->query_thief_skill("pick pockets");
  if((object *)TP->all_armour() != ({})) steal -= 30;
  else steal += 5;
  if(ob->query_wielded()||ob->query_worn()) {
      notify_fail("That would be impossible!\n");
      return 0;
  }
  if(victim->query_invis()) steal -= INVIS_PENALTY;
  if((int)ob->query_weight() >50 ) steal -= WEIGHT_PENALTY;
  if(!TP->is_class("thief") && !TP->is_class("bard")){
    notify_fail("AHH ask a thief how.\n");
    return 1; 
  }
/* Display messages */
  x = random(99)+1;
  if(x>(100-steal)){
    write("You successfully steal "+victim->query_cap_name()+"'s "+
          ob->query_name()+".\nYou are not sure if anyone noticed.");
    if(ob->move(TP)) {
      write("You cannot carry that!\nYou drop "+ob->query_name()+".");
      say(TPQCN+" drops "+ob->query_name()+".", TP);
      ob->move(ETP);
    }
    check_caught(x,victim,ob);
    if(interactive(victim))
        log_file("stealing", TPQN+" stole "+ob->query_short()+" from "+victim->query_name()+" on "+ctime(time())+"\n");
    return 1;
  }
  else {
    write("You fail to steal "+victim->query_cap_name()+"'s "+
          ob->query_name()+", but you are unsure if it went unnoticed.");
   check_caught(x,victim,ob);
    return 1;   
  }

}

void help() {
  message("help", "Syntax: <steal [item] from [being]>\n"
          "The steal command allows you to steal objects from other "
          "players and monsters.  A fight can automatically ensue if "
          "a monster becomes aware of your attempt.  And you never "
          "know what a player might do.  The command is sometimes "
          "successfull, and sometimes the victim or others might notice, "
          "or sometimes no one will notice at all.  It all depends "
          "on your ability to steal, the lighting, and other factors.\n", 
          this_player());
}
void check_caught(int roll, object target, object ob){
  int test;
   int weight;
   string *pkills;

  test = 50 + (((int)target->query_level() - (int)TP->query_level()));
  if(roll<test){
    TP->set_hidden(0);
    tell_object(target,"You catch "+TPQCN+" with "+TP->query_possessive()+" hand in your pocket.\n");
    tell_object(target,capitalize(TP->query_subjective())+" was stealing your "+ob->query_name()+".\n");
    tell_object(TP,"You get caught.");
    tell_room(environment(TP),"You see "+target->query_cap_name()+" catch "+TPQCN+" trying to steal something.",({TP,target})); 
    if(!interactive(target)) target->kill_ob(TP,0);
    if(ob->query_weight() < 1) 
      weight = 1;
    else
      weight = ob->query_weight();
    if((int)TP->query_stats("dexterity") < (random(20) + weight/10)){
      TP->force_me("drop "+((string *)ob->query_id())[0]);
    }
    TP->set_paralyzed(2,"You have been caught!");
   if(interactive(TP)){
      pkills = TP->query_pkilled();
      if(member_array(target->query_name(),pkills) == -1){
         pkills += ({target->query_name()});
         TP->set_pkilled(pkills);
      }
   }
  }
}
