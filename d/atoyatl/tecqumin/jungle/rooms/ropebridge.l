#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

mapping __PosDir;
int demon_pos, demon_dir;

void enter_east(object ob);
void enter_west(object ob);
void show(string * what);
string * get_picture(object ob, int dir);
void show_bridge(object looker);

void create() {
  ::create();
  set_exits(([
      "east" : JUNGLE + ""
   ]));
  __PosDir = ([]);
}

void set_PosDir(object ob, int * PosDir){
  object * obs;
  obs = keys(__PosDir);
  if (member_array(ob, obs)!=-1){
    map_delete(__PosDir, ob); 
  }
  __PosDir += ([ob : PosDir]);
}

void set_pos(object ob, int pos){
  object * obs;
  int dir;
  dir = 0;
  obs = keys (__PosDir);
  if (member_array(ob, obs)!=-1){
    dir = __PosDir[ob][1];
    map_delete(__PosDir, ob); 
  }
  __PosDir += ([ob : ({pos, dir})]); 
}
int query_pos(object ob){
  return __PosDir[ob][0];
}

void set_dir(object ob, int dir){
  object * obs;
  int pos;
  pos = 0;
  obs = keys (__PosDir);
  if (member_array(ob, obs)!=-1){
    pos = __PosDir[ob][0];
    map_delete(__PosDir, ob); 
  }
  __PosDir += ([ob : ({pos, dir})]); 
}

void set_demon_pos(int pos){
  demon_pos = pos;
}

int query_demon_pos(){
  return demon_pos;
}

int set_demon_dir(int dir){
  demon_dir = dir;
}

int query_demon_dir(){
  return demon_dir;
}

void show_demon(){
  show(({"Daemon", "(\//)", "|..|", " VV--<", " ||", " LL"}));
}

void show(string * what){
  int i, rows;
  rows = sizeof(what);
  for (i=0;i<rows;i++){
    tell_room(TO, what[i]);
  }  
}

string * colour_bridge(string * bridge){
  int j;
  for(j=0;j<sizeof(bridge);j++){
  switch(j){
  case 0..5:
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_CYAN%^",0);
    break;
  case 6:
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_CYAN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_CYAN%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 7:
        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",30);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 26);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 8:
        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",30);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 26);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 9:

        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",29);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 25);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 10:
        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",29);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 24);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 11:
        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",28);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 23);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 12:
        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",28);
    bridge[j] = "/daemon/str_insert_d.c"->insert_string(bridge[j],"%^B_BLUE%^", 22);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 13:
        bridge[j] = "/daemon/str_insert_d.c"->insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",29);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 22);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
  case 14:
        bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",60);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^",31);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_BLUE%^", 23);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_ORANGE%^", 9);
    bridge[j] = "/daemon/str_insert_d.c"->brute_insert_string(bridge[j],"%^B_GREEN%^",0);
    break;
    }
  }
  return bridge;
}

void show_bridge(object looker){
  string * bridge, *pic;
  object * critters, *obs, ob;
  int i, j, *posDir, vPos, vHeight;

  bridge = ({"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"   ||  ||                                                   ||  ||   ",
"   ||  ||                                                   ||  ||   ",
"___||__||                                                   ||__||___",
"---||--||\\                                                 /||--||---",
"   ||  ||\\\\- - - - - - - - - - - - - - - - - - - - - - - -//||  ||   ",
"   ||  || \\\\_____________________________________________// ||  ||   ",
"   ||  ||  \\---------------------------------------------/  ||  ||   ",
"   ||  ||                                                   ||  ||   ",
"   ||  ||                                                   ||  ||   ",
"   ||  ||                                                   ||  ||",
"   ||  ||                                                   ||  ||   "});
  critters = all_living(TO);
  if (sizeof(critters)<1){
    show(bridge);
    return;
  }
  for (i=0;i<sizeof(critters);i++){
    tell_room(TO, " count " + i + ". Checking critter: " + critters[i]->query_name());
    posDir = ({0,0});
    obs = keys(__PosDir);
    ob = critters[i];
    if (member_array(ob, obs)!=-1){
      posDir = __PosDir[ob];
    }
    pic = get_picture(ob, posDir[1]);
    switch (posDir[0]){
    case 0..9:
      vPos = 9;
      break;
    case 10:
      vPos = 10;
      break;
    case 11:
      vPos = 11;
      break;
    case 12:
      vPos = 12;
      break;
    case 13:
      vPos = 13;
      break;
    case 14..60:
      vPos = 14;
      break;
    case 61:
      vPos = 6;
      break;
    case 62:
      vPos = 7;
      break;
    case 63:
      vPos = 8;
      break;
    default:
      vPos = 9;
      break;
    }
    vPos -= 6;
    vHeight = sizeof(pic);
    for (j=vPos; j<vPos + vHeight;j++){
      bridge[j]= "/daemon/str_insert_d.c"->insert_string(bridge[j],pic[j-vPos],posDir[0]);
    }
  }
  colour_bridge(bridge);
  show(bridge);
}

string * get_picture(object ob, int dir){
  object * wielded, wpn;
  if (!objectp (ob)||!interactive(ob)){
    return({});
  }
  wielded = ob->query_wielded();
  if (sizeof(wielded)>1){
    switch(dir){
    case 0:
      return ({"Adventurer", "\ (..) /", " \-||-/", "   //"});
    case 1:
      return ({"Adventurer", "\ (..) /", " \-||-/", "   LL"});
    }
  }
  if (sizeof(wielded)>0){
    wpn = wielded[0];    
    if (objectp(wpn)){
      if (wpn->id("sword")){
        switch (dir){
        case 0:
          return ({"Adventurer", "\ (..)", " \-||", "   //"});
        case 1:
           return ({"Adventurer", "(..) /", " ||-/", " LL"});
        }
      } 
      if (wpn->id("mace")){
        switch(dir){
        case 0:
          return ({"Adventurer", "O (..)", " \-||", "   //"});
        case 1:
          return ({"Adventurer", "(..) O", " ||-/", " LL"});
        }
      }
      if (wpn->id("staff")){
        switch (dir){
        case 0:
          return ({"Adventurer", "|(..)", "|-||", "' //"}); 
        case 1:
          return ({"Adventurer", "(..)|", " ||-|", " LL '"});
        }
      }
      if (wpn->id("spear")){
        switch (dir){
        case 0:
          return ({"Adventurer", "\ (..)", " \-||", "  \// "}); 
        case 1:
          return ({"Adventurer", "(..) /", " ||-/", " LL/"});
        }
      }
    }
  }
  switch(dir){
  case 0:
    return ({"Adventurer", " (..)", " -||", "  //"});
  default:
    return ({"Adventurer", "(..)", " ||-", " LL" });
  }
}
