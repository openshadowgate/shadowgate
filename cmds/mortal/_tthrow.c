#include <std.h>
#include <move.h>

#define VOID "/d/shadowgate/void"

inherit DAEMON;

mapping targets = ([]);

int help();

object errant_hit(object foe) {
   int i;

   object *inven = all_inventory(environment(foe));
   if(random(30)< sizeof(inven)) {
      return inven[random(sizeof(inven))];
   }
   return 0;
}

int cmd_throw(string str){

    string target, dir, what, what2, * exits, remainder;
    int distance, flag, inc, tohitroll,thaco,perfect, damage, num, targetless, i;
    object foe,current,what_ob, alt_foe;
    object *roomList, * wielded;
    flag = 0;
    targetless = -1;
    if(!str) {
        return help();
    }
    tell_object(TP, "Trying to throw something");
    if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
//////////////////Parsing the command from scratch. Lujke Feb 2017.
//First check whether any wielded item is identified by the first two words in the command
    wielded = TP->query_wielded();
    if (sizeof(wielded)<1){
      tell_object(TP, "You can only throw something you are wielding!");
      return 1;
    }
    sscanf(str, "%s %s %s", what, what2, remainder);
    for (i=0; i<sizeof(wielded);i++){
        if (wielded[i]->id(what + " " + what2)){
            what_ob = wielded[i];
            flag = 1;
            tell_object(TP, "2 word identifier confirmed");
            break;
        }
    }
    if (!objectp(what_ob)){ //If that didn't work, see if anything is identified by the first word only
    for (i=0; i<sizeof(wielded);i++){
            if (wielded[i]->id(what)){
                what_ob = wielded[i];
                flag = 0;
                tell_object(TP, "1 word identifier confirmed");
                break;
            }
        }
    }
    if (!objectp(what_ob)){
      tell_object(TP, "You can only throw something you are wielding!");
      return 1;
    }
    //adjust the remainder of the string, depending whether two words or one were used as the identifier
    switch (flag){
    case 0:
        str = what2 + " " + remainder;
        tell_object(TP, "trying to parse remainder string: " + str);
        break;
    case 1:
        str = remainder;
        tell_object(TP, "trying to parse remainder string: " + str);
        break;
    }
    //now check whether the item is to be thrown at a target
    if (interact("at", str)){ 
        tell_object(TP, "Trying to throw something at a target");
        if (sscanf(str, "at %s %s %d", target, dir, distance)!=3){
            if(sscanf(str,"at %s", target) != 1) {
                 return help();
            }
            tell_object(TP, "Trying to throw something at a target in the same room as myself");
            tell_object(TP, "Target: " + target); 
            dir = "here";
        } 
        tell_object(TP, "Target: " + target); 
        tell_object(TP, "Direction: " + dir);
        tell_object(TP, "Distance: " + distance);

    } else {
        tell_object(TP, "Trying to throw something with NO target");
        num = sscanf(str, "%s %d", dir, distance);
        tell_object(TP, "Distance: " + distance);
        targetless = 1;
    }    
    if (num <1 || dir == 0){
        dir = str;
        distance = 1;
        tell_object(TP, "Distance: " + distance);
        targetless = 1;
    }
    exits = ETP->query_exits();
    if (sizeof(exits)<1||member_array(dir, exits)==-1){
        tell_object(TP, "You can't throw in that direction. There's no '" + dir + "' exit in this room!"); 
        return 1;
    }
    if(what_ob->is_cursed()) {
        return notify_fail("The curse resists your attempt to throw.\n");
    }

    if(!what_ob->thrown()) {
        return notify_fail("You can't throw that item.\n");
    }

    if(dir == "rift")
       return notify_fail("You can't get a clear shot through the magical passage.\n");
    if(dir != "here" && (string)environment(TP)->query_exit(dir) == VOID)
       return notify_fail("You want to throw the walls?\n");

    current = environment(TP);
    if(distance > 0) {
        roomList = allocate(distance);
        roomList[0] = current;
    }
    for(inc = 0;inc < distance;inc ++) {
       current = find_object_or_load((string)current->query_exit(dir));
       if(inc < distance-1) {
          roomList[inc+1] = current;
          //tell_room(current,"Something wizzes by your head!");
          if((string)current->query_exit(dir) == VOID)
             return notify_fail("Your shot flies off and hits nothing!\n");
       }
       if(current->query_property("indoors")) {
          if((environment(TP)->query_property("indoors")) &&
             (distance > 1)) {
             return notify_fail("You can only throw one room away when throwing from indoors to indoors!\n");
          } else if(environment(TP)->query_property("indoors")) {
             if(inc < distance-1) {
                  return notify_fail("You can not throw through the indoors!\n");
             }
          }
       }
       if (current->query_door(dir) && inc < distance -1) {
          write("There seems to be a closed door between you and your target.");
          return 1;
       }
    }
    if (targetless == -1){  //added by Lujke
        if(!foe = present(target,current) )
           return notify_fail("There is no "+target+" there!\n");
        if(!TP->ok_to_kill(foe))
           return notify_fail("Greater forces prevent your malice.\n");
        if(foe->query_property("no bows"))
           return notify_fail("You can't seem to get a clean throw at them from here!!\n");

        //tohitroll = adjust_to_hit(tohitroll);
        thaco = TP->Thaco(1,foe,what_ob);
        flag = 1;
      // Funny, this stuff seemed to be missing but important... - Garrett and Styx.
      tohitroll=random(20) + 1;
      if (tohitroll == 20) perfect = 1;
     if (tohitroll == 1) perfect = -1;
    // added by Styx to log what bugged from not having a set_name() 4/17/03
        if(!what_ob->query_name())
            log_file("debug.info", base_name(what_ob)+" needs a set_name() because it's going to bug in /cmds/mortal/_throw and probably elsewhere
sooner or later.\n");
        if(((tohitroll < thaco ) && (perfect != 1)) || perfect == -1) {
           if(objectp(alt_foe = errant_hit(foe)) && (random(20) > TP->Thaco(1,alt_foe,TO))) {

              tell_room(current,capitalize(what_ob->query_name())+" flies by "+capitalize(target),foe);
              tell_object(foe,capitalize(what_ob->query_name())+" barely misses you!");
              foe = alt_foe;
           } else {
              flag = 0;
              tell_room(current,capitalize(what_ob->query_name())+" flies by "+capitalize(target),foe);
              tell_object(foe,capitalize(what_ob->query_name())+" barely misses you!");
              write("You missed...");
           }
        }
    } 
    if(flag) {
       if(perfect) write("Perfect shot!");
       tell_room(current,foe->query_cap_name()+" is hit with a "+what_ob->query_name(),foe);
       write("You hit the "+foe->query_cap_name()+" with a "+what_ob->query_name()+"!");
       tell_object(foe,"You are hit with a "+what_ob->query_name());
       foe->add_poisoning(what_ob->query_poisoning());
       damage = what_ob->thrown_hit(foe);
       damage+= distance;
       foe->add_attacker(TP);
       //foe->bow_hit(TO, damage);
       foe->do_damage(foe->query_target_limb(), damage);
       if(objectp(what_ob)) {
          if(objectp(foe)) {
            if(what_ob->move(foe) != MOVE_OK){
                what_ob->move(environment(foe));
            }
          } else {
            what_ob->move(distance>0?roomList[sizeof(roomList)-1]:ETP);
          }
       }
       if(foe->check_death()) {
          write("You have killed "+target+"!!!");
          return 1;
       }
    } else {
//       what_ob->move(distance>0?roomList[sizeof(roomList)-1]:ETP);
        what_ob->move(current);
    }
    if (targetless ==-1){  //added by Lujke
        if(!userp(foe) && living(foe)){
           //env = environment(foe);
           //file = base_name(environment(TP));
           if(foe->query_paralyzed() || 
               ((object *)foe->query_attackers()!= ({})
               && (member_array(TP,foe->query_attackers()) == -1 
               && !present(TP,ETP)))) {
              return 1;
           } else {
              if(!living(foe)) {
                 return 1;
              }
              if(!targets[foe] || targets[foe] == ({})) {
                 call_out("move_monster",2,foe, TP);
              }
              targets[foe] = roomList;
           }
        }
    } else {
      tell_room(ETP, TPQCN + " throws " + what_ob->query_short() 
                     + " in the " + dir + " direction.", TP);
      tell_object(TP, "You throw "+  what_ob->query_short()
                             + " in the " + dir + " direction.");
    }
    return 1;

 }


 void move_monster(object foe, object player) {
    object current;
    int grx,grnum_p;
    object *grplayers,grhere,grvictim, *roomList;
    if(!objectp(foe)) {
       return;
    }
    if(!targets[foe]) {
       return;
    }
    if(foe->query_paralyzed() || foe->query_tripped() || ((object *)foe->query_attackers()!= ({})
                                  && (member_array(player,foe->query_attackers()) == -1 && !present(player,environment(foe))))) {
       return 1;
    }
    roomList = targets[foe];

    if(!pointerp(roomList) || !sizeof(roomList)) {
       return;
    }

    current = roomList[sizeof(roomList)-1];
    grhere = environment(foe);
    foe->move_player(current, "in a rage");
    foe->kill_ob(player,1);

    if(foe->query_property("swarm")) {
       grplayers = all_inventory(grhere);
       grplayers -= ({foe});
       grnum_p = sizeof(grplayers);
       for(grx = 0;grx < grnum_p;grx++) {
          grvictim = grplayers[grx];
          if(living(grvictim) && !userp(grvictim) && grvictim->query_property("swarm") && grvictim != foe && !grvictim->query_paralyzed()) {

             grvictim->move_player(current, "in a rage");
             TP->kill_ob(grvictim,1);
             //grvictim->force_me("kill "+TPQN);
          }
       }
    }
    roomList -= ({current});
    targets[foe] = roomList;
    if(sizeof(roomList)) {
       call_out("move_monster",4,foe,player);
    }
 //       foe->set("aggressive",25);
    //tell_room(environment(TP),foe->query_cap_name()+" enters the room.");
}


int help(){
    write(
@OLI
    throw
    throw <object> at <target> || throw <object> at <target> <direction> <distance>

    Throw can be applied to any wielded (in hand) object. Throwing at a
    target starts combat. Some objects will do nothing when they hit a 
    target. Others will explode, capture pierce or otherwise wound the 
    target. Oh some might just break. For the time being throwing does 
    not require a proficiency. This will change.
OLI
    );
    return 1;
}
