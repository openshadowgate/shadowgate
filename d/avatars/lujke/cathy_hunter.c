#include "/d/dagger/Torm/tormdefs.h"
#include <daemons.h>
#include <std.h>
#define PATHFINDER "/daemon/pathfinder_d.c"

inherit MONSTER;
string target_name;

void powder_em(object ob);
void rush_em(object ob);
void off_duty();

void create (){
  object pouch, oil, band;
  ::create ();
  set_moving(0);
  set_name("hunter");
  set_id(({
  "hunter","bounty hunter",
  "human",
  }));
  set_property("swarm",1);
  set_property("no dominate",1);
  set_property("no bows",1);
  set_mob_magic_resistance("average");
  set_property("magic",1);
   set_short("A fearsome Daggerdale bounty hunter");
  set_property("bounty hunter",1);
  add_damage_bonus(7);
  set_long(
  "A muscular woman dressed in Daggerdale livery and clothing. Everything she posesses is top quality and"
 +" immaculately well looked after. Her face is unreadable, her expression implacable but for a hint of"
 +" steely determination. She wears a strange visor over her eyes."
  );
set_property("swarm",1);
set_gender("female");
  set_race("human");
  add_search_path("/cmds/fighter/");
  add_search_path("/cmds/mortal/");
set_body_type("human");
  set_hd(56,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",56);
  set_property("full attacks",1);
  set_stats("strength",18);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 18);
set_alignment(1);
  set_max_hp(600);
  set_hp(600);
  set_exp(5000);
set("aggressive", 0);
  set_overall_ac(-10);
  add_money("gold",random(200));
  add_money("platinum",random(10));
  new("/d/avatars/lujke/hunter_sword.c")->move(TO);
  command("wield sword");
//  new(OBJ+"fullplateb.c")->move(TO);
  new("/d/common/obj/armour/fullplate")->move(TO);
  new(OPATH+"Mcoif.c")->move(TO);
  //if(random(5)){
  present("coif",TO)->set_property("monsterweapon",1);
  present("sword",TO)->set_property("monsterweapon",1);
  present("plate",TO)->set_property("monsterweapon",1);
  //}

      pouch = new ("/d/common/obj/misc/pouch.c");
      pouch->set_property("monsterweapon",1);
      pouch->move(TO);
      oil = new ("/d/common/obj/misc/oil.c");
      oil->set_property("monsterweapon",1);
      oil->move(pouch);
      oil = new ("/d/common/obj/misc/oil.c");
      oil->set_property("monsterweapon",1);
      oil->move(pouch);
      band = new("/d/azha/obj/gmr_ring.c");
      band->set_property("monsterweapon",1);
      band->move(pouch);

 command("wearall");
  target_name = "theasen";
}

void heart_beat(){
  object fluffy, tempfluff, * players;
  int i;
  if (!objectp(ETO)){
    return;
  }
  tempfluff = present(target_name, ETO);
  if (objectp(tempfluff)){
    force_me("get band from pouch");
    force_me("wear band");
    if (!tempfluff->query_property("powdered")){
      powder_em(tempfluff);
    }
    return;
  }else{
    force_me("put band in pouch");
  }

  if(total_light(TO) < 1)   {
    force_me("light lantern");
    if(total_light(TO) < 1)  {
      force_me("light lantern 2");
    }
  }
  if(total_light(TO) > 2)   {
    force_me("douse lantern");
    if(total_light(TO) >2)  {
      force_me("douse lantern 2");
    }
  }
  if (!random(5)){
    fluffy = PATHFINDER->far_present(ETO, target_name,  5);
    if (!objectp(fluffy)){
      off_duty();
    }
  }
}



void off_duty(){
  object stuff, place;
  place = ETO;
  stuff = present("pouch",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("oil",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("oil",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("band",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("plate",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("sword",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("coif",TO);
  if (objectp(stuff)){stuff->remove();}

  if (objectp(place)){
    tell_room(place, "%^BLUE%^Tsvarani %^ORANGE%^bounty hunter%^BLUE%^ goes off in search of profit");
  }

  remove();
}

void powder_em(object ob){
  if(!(present("powder",TO))){
  new("/d/tharis/obj/bpowder")->move(TO);
  command("wield powder");
  present("powder",TO)->set_property("monsterweapon",1);
  command("toss powder at "+ob->query_name());
  command("get all");
  }
  call_out("rush_em", 5, ob);
}
void rush_em(object ob){
  object room;
  string targ_name;
  room = ETO;
  if (!objectp(room)||!objectp(ob)||!present(ob, room)){return;}
  targ_name = ob->query_name();
  command("unwield powder");
  command("offer powder");
  command("rush " + targ_name);
  TO->kill_ob(ob,1);
  command("parry");
  return 1;
}
void set_target(string name){
  target_name = name;
}
string query_target(){
  return target_name;
}

void catch_tell(string str){
 if (str=="Your lantern goes out."||str=="The lantern is out of fuel.\n"){
    force_me("get oil from pouch");
    force_me("fill lantern with oil");
    force_me("fill lantern 2 with oil");
    force_me("light lantern");
    force_me("light lantern 2");
  }
}

