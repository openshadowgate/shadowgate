#include <std.h>
#include "../drille.h"
inherit VAULT;

int mykey;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(MEADOWLANDS);
    set_travel(FOOT_PATH);
    set_name("A house in the forest");
    set_short("%^BOLD%^%^WHITE%^A house in the forest%^RESET%^");
    set_long("The path leads to a fairly sized %^BOLD%^house%^RESET%^. The "
"area in around the house is overtaken by a %^BOLD%^%^GREEN%^lush %^RESET%^lawn "
"with some %^GREEN%^shrubberies %^RESET%^here and there. Around the "
"little garden, the huge trees of the forest rise up majestically. Somewhere "
"in the forest you hear the gushing of a small %^BOLD%^%^CYAN%^spring%^RESET%^"
". Out on the lawn stands a cute little %^BOLD%^%^RED%^windmill%^RESET%^, "
"which moves in accordance with the winds. "
"%^BOLD%^%^BLACK%^Smoke %^RESET%^rises up from the chimney of the house, "
"making the whole scenery look rather idyllic. The path ends at the front "
"%^ORANGE%^door %^RESET%^of the house.");
    set_smell("default","The smells of the forest surround you.");
    set_listen("default","Animals can be heard scurrying about through the woods.");
    set_items(([
      "knockers" : "%^BOLD%^%^BLACK%^A pair of iron dice hangs from the mouth "
"of a knave. You can use them to %^RESET%^knock %^BOLD%^%^BLACK%^on the door, "
"letting the people inside know you are waiting at the door.%^RESET%^",
    ]));
    set_exits(([
      "west" : ROOMS"path3",
      "enter" : ROOMS"foyer",
    ]));
    set_door("front door",ROOMS"foyer","enter","drille key");
    set_door_description("front door","%^ORANGE%^The door is made of oak and "
"looks very solid and strong. A set of knockers has been studded fast to the "
"door. You could probably use them to %^WHITE%^knock%^ORANGE%^.%^RESET%^");
    set_locked("front door",1);
   mykey = 0;
}

void init(){
   ::init();
   add_action("knock_fun","knock");
   add_action("blow_fun","blow");
}

void reset() {
   ::reset();
   if(mykey) mykey = 0;
}

int knock_fun(string str){
   object ob;
   if(str) return 0;
   tell_object(TP,"%^BOLD%^%^BLACK%^You raise the iron dice and use them to "
"knock on the door.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" lifts the iron dice and uses "
"them to knock on the door.%^RESET%^",TP);
   ob = find_object_or_load(ROOMS"foyer");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"balcony");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"bathroom");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"bed1");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"bed2");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"forge");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"kitchen");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"living");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   ob = find_object_or_load(ROOMS"platform");
   tell_room(ob,"%^BOLD%^%^BLACK%^You hear the heavy thump of someone "
"knocking on the front door.%^RESET%^");
   return 1;
}

int blow_fun(string str){
   if(!str) return 0;
   if(str != "windmill") return 0;
   if(mykey){
     tell_object(TP,"%^BOLD%^%^CYAN%^You blow on the windmill, making the "
"wings spin.%^RESET%^");
     tell_room(TO,"%^BOLD%^%^CYAN%^As "+TP->QCN+" blows on the windmill, the "
"wings start to spin.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You blow on the windmill, making the wings "
"spin. The little door on the mill opens, and a key falls out.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^CYAN%^As "+TP->QCN+" blows on the windmill, the "
"wings start to spin. A little door opens and a key falls out.%^RESET%^",TP);
   new(OBJ+"key")->move(TO);
   mykey = 1;
   return 1;
}
