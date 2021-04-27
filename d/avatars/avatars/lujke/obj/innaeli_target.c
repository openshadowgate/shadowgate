//Coded by Lujke

#define SHADOW "/d/shadow/room/city/"
#include <std.h>

inherit "/std/armour";  // so it can be worn. :)
void place_archer(object * creatures);

create() {
  ::create();
  set_name("feeling of being unwelcome in Shadow");   
                        
  set_id(({"feeling"}));   

  set_short("%^BLUE%^a strange feeling%^RESET%^");   
  set_long("%^BLUE%^As you reflect inwards into your emotions, you are"
          +" aware of a distinct feeling that you are not welcome in the"
          +" city of Shadow, and that they might shoot arrows at you if"
          +" you go there.");
  set_type("ring"); 
   
  set_ac(1);             
  set_weight(0);          
  set_value(0);         
  
  set_limbs(({"head"}));  
  set_property("enchantment",-1);
  set_property("no remove",1);
  if(query_property("enchantment") > 0){
      remove_property("enchantment");
      set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_heart_beat(5);
}
int wear_func(){
  int i, num;
  tell_object(ETO, "You realise that you are really not wanted in Shadow");

  num = sizeof(children("d/avatars/lujke/innaeli_hunter.c"));
  if (num>0){
    for (i=0;i<num;i++){
      children("/d/avatars/lujke/innaeli_hunter.c")[0]->remove();
    }
  }
  set_hidden(1);
  return 1;
}

int remove_func(){
    tell_object(ETO, "You are reminded that going to Shadow might be a bad"
                    +" idea");
    set_hidden(0);
    return 1;
}

void heart_beat(){
  object wearer,place, creature, * creatures;
  int i,j, num, groups;
  wearer= ETO;
  if (!objectp(wearer)){
    return;
  }
  place = EETO;
  if (!objectp(place)){
    return;
  }
  creatures = ({});

 
  if (!objectp(wearer)||!objectp(place)){
    return;
  }

  if(!objectp(query_worn())){
    return;
  }
  if (!interactive(query_worn())){
    return;
  }
  if (file_name(place)[0..strlen(SHADOW)-1] == SHADOW
      || file_name(place)[0..21] == "/d/shadowgate/adv_main"[0..21]){
    if ((wearer->query_invis() || wearer->query_hidden())&& random(45)< 44){
      return;
    }
    if ((int)place->query_property("indoors")==1){

      if (!random(10)){
        if (sizeof(children("/d/avatars/lujke/innaeli_hunter.c"))>1){

          for (i=sizeof(children("/d/avatars/lujke/innaeli_hunter.c"))-1
                                           ;i>=0;i--){
            creature = present(children("/d/avatars/lujke/innaeli_hunter.c")[i], EETO);
            if (!objectp(creature)){
              children("/d/avatars/lujke/innaeli_hunter.c")[i]->off_duty();


            }
          }
        }
        if (sizeof(children("/d/avatars/lujke/innaeli_hunter.c"))<2){

          creature = new("/d/avatars/lujke/innaeli_hunter.c");
          if (!objectp(creature)){

          return;
        }
         tell_room(place, "%^BLUE%^A vicious %^RED%^bounty hunter%^BLUE%^"
              +" bursts in and attacks "+ wearer->QCN + "!", wearer);
          tell_object(wearer,"%^BLUE%^A vicious %^RED%^bounty hunter"
              +" %^BLUE%^bursts in and attacks you!");
          creature->move(place);
          creature->set_target(ETO->query_name());
          creature->force_me("kill " + wearer->QCN);
          creature->rush_em(wearer);
        }
      }
    }else{
      if (sizeof(children("/d/avatars/lujke/innaeli_archer.c"))<5){
        groups = random(2)+1;
        for (j=0;j<groups;j++){
          num = random (3)+1;
          for(i=0;i<num;i++){
            creature = new("/d/avatars/lujke/innaeli_archer.c");
            creature->set_target((string)ETO->query_name());
            creatures += ({creature});
          }
          place_archer(creatures);
        }
      }
    }
  }else{
//  tell_object (wearer,"You are %^BOLD%^%^RED%^NOT%^RESET%^ in Tabor!");
  }
//  tell_object(wearer, "end of heartbeat");
}

void place_archer(object * creatures){
  object startroom, temproom, nextroom;
  string * exits, direction;
  int i, distance;

  if (sizeof(creatures)<1){
    return;
  }
  startroom = EETO;
  if (!objectp(startroom)){
    return;
  }
  exits = startroom->query_exits();
  if (sizeof(exits)<1){
    return;
  }
   i = random(sizeof(exits));
  direction = exits[i];
  distance = random(6)+1;
  temproom = startroom;
  for (i=0;i<distance;i++){
    if (((string)temproom->query_exit(direction))[0..strlen(SHADOW)-1] != SHADOW){
      break;
    }
    nextroom = find_object_or_load(temproom->query_exit(direction)+".c");
    if (objectp(nextroom)){
      temproom = nextroom;
    }
  }
  if (objectp(temproom)){
    tell_room(EETO, "%^BLUE%^Some movement to the "+direction + " catches"
                   +" your attention as a some %^ORANGE%^Shadow city archers"
                   +" %^RESET%^appear from hiding places%^RESET%^");
    for (i=0;i<sizeof(creatures);i++){
//      tell_object(ETO, "Placing creature " + i);
      creatures[i]->move(temproom);
    }
  }else{
    for (i=0;i<sizeof(creatures);i++){
//      tell_object(ETO, "Removing creature " +i);
      creatures[i]->remove();
    }
  }
}