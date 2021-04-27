//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LHALL;

void create(){
   ::create();
   set_name("hall4");
  	set_exits(([
		"north" : LROOMS+"post6",
		"south" : LROOMS+"hall3",
		"east" : LROOMS+"lusell",
		"west" : LROOMS+"storage"
   ]));

  	set_door("door",LROOMS+"storage","west","ruby key");
   set_door_description("door","A simple wooden door.\n");
   set_string("door","open","The door opens to the storage room.\n");
   set_locked("door",0,"lock");
		(LROOMS+"storage")->set_locked("door",0,"lock");

  	set_door("ornate door",LROOMS+"lusell","east","ruby key");
   set_door_description("ornate door","This door is made from a single "+
   	"piece of mahogony and is lacquered an inlaid with ivory, gold, and rubies.\n");
   set_string("ornate door","open","The door opens to lavishly decorated "+
   	"living quarters.\n");
   set_locked("ornate door",1,"lock");
		(LROOMS+"lusell")->set_locked("ornate door",1,"lock");
  	lock_difficulty("ornate door", "/daemon/player_housing"->get_phouse_lock_dc("common"),"lock");
}
