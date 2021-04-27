//Coded by Lujke
#include <std.h>
#include <daemons.h>
#define PATHFINDER "/daemon/pathfinder_d.c"
#define TABOR "/d/darkwood/tabor/room"

#define YELL ({"She's over here! Get her, lads!",\
"There's the bugger! Make a fancy pin cushion out of her!",\
"Fall damn you, damn murderer!",\
"You are not wanted here! Crawl back under the rock you climbed out from!",\
"The enemy is in sight! Archers, shoot!",\
"Scum! Leave now or die!",\
"Daggerdale will stand for this no longer! It's time for you to leave!",\
" We will not stop until you fall!",\
"Leave now and we might spare your pathetic life!",\
"We don't like your kind around here!",\
"Now you die, guard killer!",\
"Leave now and we might spare your pathetic life!",\
"You will not defeat us! Surrender yourself!",\
"Get lost, witch of the shadows!"})


inherit MONSTER;

int is_shooting;
string target_name;
object fluffy;

void off_duty();
void shoot(object targ);
string locate_target(object target, string direction, int distance);
void set_target(string name);
string query_target();
void drawsword();
void usebow();

void create(){
      object bow,arrows,sword, lantern, pouch, band, oil;
      ::create();
  	set_name("Daggerdale archer");
  	set_id(({"archer","daggerdale archer","human",}));
  	set_short("%^BLUE%^Daggerdale archer");
  	set_long("%^ORANGE%^The archer is clothed in garments that" 
              +" mark him as a member of a viscious mercenary army. A"
              +" strong and well-trained warrior, the %^RED%^angry"
              +" %^ORANGE%^sneer on the man's face reveals his sheer"
              +" determination to accomplish the task at hand. He is"
              +" equipped with a heavy bow, and sharpened, %^BOLD%^"
              +"%^WHITE%^b%^RESET%^a%^BOLD%^%^BLACK%^rb%^RESET%^ed"
              +" %^ORANGE%^arrows, along with a wicked,%^RESET%^ shining"
              +" %^ORANGE%^scimitar. A couple of beacon lanterns are"
              +" kept close at hand and he is wearing a strange visor."
              +"\n");
  	set_race("human");
      set_wielding_limbs(({"right hand","left hand"}));
  	set_gender("male");
  	set_hd(50,4);
  	set_size(2);
  	set("aggressive",0);
	set_class("fighter");
	set_mlevel("fighter",50);
	set_level(30);
	set_guild_level("fighter",50);
   	set_hp(random(50)+400);
	set_speed(30);
   	set_exp(2000);
	set_max_level(60);
	set_property("swarm",1);
  	set_overall_ac(-20);
  	set_alignment(4);
      set_mob_magic_resistance("average");
      set_property("full attacks",1);
 	is_shooting = 0;

      bow = new("/d/common/obj/lrweapon/longbow.c");
      bow->set_property("monsterweapon",1);
      bow->move(TO);
      arrows = new("/d/common/obj/lrweapon/larrows.c");
      arrows->set_property("monsterweapon",1);
      arrows->move(TO);
      arrows = new("/d/common/obj/lrweapon/larrows.c");
      arrows->set_property("monsterweapon",1);
      arrows->move(TO);
      sword = new("/d/common/obj/weapon/scimitar");
      sword->set_property("monsterweapon",1);
      sword->move(TO);
      lantern = new("/d/common/obj/misc/bullseye.c");
      lantern->set_property("monsterweapon",1);
      lantern->move(TO);
      lantern = new("/d/common/obj/misc/bullseye.c");
      lantern->set_property("monsterweapon",1);
      lantern->move(TO);
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
      increase_skill("long bow", 200);
      increase_skill("medium blades", 100);
      target_name = "theasen";
}

void init(){
  ::init();
  force_me("wield bow");
}

void yell(){
  int i;
  i = random(sizeof(YELL));
  force_me("yell " + YELL[i]);
}

void heart_beat(){
  object tempfluff, * players, room;
  int i;
  room = ETO;
  if (!objectp(room)){return;}
  tempfluff = present(target_name, ETO);
  if (objectp(tempfluff)){
    drawsword();
    return;
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

  if (is_shooting==1){
    if (!random(5)){
      fluffy = PATHFINDER->far_present(ETO, target_name,  5);
      if (!objectp(fluffy)){
        off_duty();
      }
    }
    usebow();
    shoot(fluffy);
  }else{
    if (!random(3)){
      fluffy = PATHFINDER->far_present(ETO, target_name, 5);
      if (objectp(fluffy)){
        yell();
        is_shooting = 1;
      }else{
        off_duty();
      }
    }
  }
}

void off_duty(){
  int i,j;
  object stuff;
  stuff = present("pouch",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("oil",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("oil",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("band",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("sword",TO);
  if (objectp(stuff)){stuff->remove();}
   stuff = present("bow",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("arrows",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("arrows",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("lantern",TO);
  if (objectp(stuff)){stuff->remove();}
  stuff = present("lantern",TO);
  if (objectp(stuff)){stuff->remove();}

  force_me("emote goes back about his business");
  remove();
}

void shoot(object targ){
  string direction;
  int distance;
  direction =  locate_target(targ, direction, distance);
  if (direction!="notfound"){
    if (!random(3)){
      yell();
    }
//    force_me("say trying to: shoot " + target_name + " " + direction);
//    force_me("shoot " + target_name + " " + direction);
    force_me("shoot " + target_name + " " + direction);
    force_me("shoot " + target_name + " " + direction);
  }
}

string locate_target(object target, string direction, int distance){
  object startroom, temproom, nextroom;
  string * exits;
  int i, j;
//  force_me("say Trying to locate Target");

  if (!objectp(target)){
//    force_me("say Target is not a valid object");
    return -1;
  }
  startroom = environment(TO);
  if (!objectp(startroom)){
//    force_me("say start room is not a valid environment");
    return -2;
  }
  exits = startroom->query_exits();
  if (sizeof(exits)<1){
//    force_me("say start room has no exits");   
    return -1;
  }
  for (i=0;i<sizeof(exits);i++){
    direction = exits[i];
    temproom = startroom;
 //   force_me("say Checking for Target to the ^&BOLD%^%^CYAN%^" 
 //             + direction);
    for (j=0;j<10;j++){
//      force_me("say Checking for Target in the next room");
      if (file_exists(temproom->query_exit(direction) + ".c")){
        nextroom = find_object_or_load(temproom->query_exit(direction)
                                      +".c");
//        force_me("say there is a file going by that name");
      }
      if (!objectp(nextroom)){
//      force_me("say There is no room there!" );
        break;
      }
      if (present(target, temproom)){
 //     force_me("say The target is in that room"); 
        distance = j+1;
        return direction;
      }
      temproom = nextroom;
    }
  }
  return "notfound";
}

void drawsword(){
  force_me("unwield bow");
  force_me("wield sword");
  force_me("get band from pouch");
  force_me("wear band");
}

void usebow(){
  force_me("unwield sword");
  force_me("wield bow");
  force_me("remove band");
  force_me("put band in pouch");
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
