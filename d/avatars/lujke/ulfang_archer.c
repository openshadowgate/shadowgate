//Coded by Lujke
#include <std.h>
#include <daemons.h>
#define PATHFINDER "/daemon/pathfinder_d.c"
#define TABOR "/d/darkwood/tabor/room"

#define YELL ({"Leave this place or die, you fiend!",\
"Begone, foul beast of the woods!",\
"Fall damn you, creature of the Malar!",\
"You are not wanted here! Crawl back under the rock you climbed out from!",\
"The enemy is in sight! Archers, shoot!",\
"Scum! Leave now or die!",\
"Tabor will stand for this no longer! It's time for you to leave!",\
" We will not stop until you fall!",\
"Leave now and we might spare your pathetic life!",\
"We don't like your kind around here!",\
"Now you die, Fiend of Malar!",\
"Leave now and we might spare your pathetic life!",\
"You will not defeat us! Surrender yourself!"})


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
  	set_name("tabor archer");
  	set_id(({"archer","tabor","tabor archer","human",}));
  	set_short("%^CYAN%^Tabor archer");
  	set_long("%^ORANGE%^The archer is clothed in regular garments that" 
              +" mark him as a soldier of the city of Tabor. A"
              +" well-trained warrior, he appears competent and"
              +" disciplined. He is"
              +" equipped with a heavy bow, and sharpened, %^BOLD%^"
              +"%^WHITE%^b%^RESET%^a%^BOLD%^%^BLACK%^rb%^RESET%^ed"
              +" %^ORANGE%^arrows, along with a wicked,%^RESET%^ shining"
              +" %^ORANGE%^scimitar."
              +"\n");
  	set_race("human");
      set_wielding_limbs(({"right hand","left hand"}));
  	set_gender("male");
  	set_hd(22,4);
  	set_size(2);
  	set("aggressive",0);
	set_class("fighter");
	set_mlevel("fighter",22);
	set_level(22);
	set_guild_level("fighter",22);
   	set_hp(random(80)+100);
	set_speed(30);
   	set_exp(800);
	set_max_level(30);
	set_property("swarm",1);
  	set_overall_ac(-6);
  	set_alignment(4);
      set_property("magic resistance",5);
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
      pouch = new ("/d/common/obj/misc/pouch.c");
      pouch->set_property("monsterweapon",1);
      pouch->move(TO);
      band = new("/d/azha/obj/gmr_ring.c");
      band->set_property("monsterweapon",1);
      band->move(pouch);
      increase_skill("long bow", 200);
      increase_skill("medium blades", 100);
      target_name = "ulfang";
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
  object tempfluff, * players;
  int i;
  tempfluff = present(target_name, ETO);
  if (objectp(tempfluff)){
    drawsword();
    return;
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

