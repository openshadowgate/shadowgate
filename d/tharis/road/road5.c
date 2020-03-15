 //d/tharis/road/road5.c//
#include <std.h>
#include <objects.h>
inherit ROOM;
inherit "std/money";
void create() {
    room::create();	
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("Road between Darkwood and Tharis.");
    set_long(
@OLI
        To the south is the grand trade city of Tharis and to the north is 
the road to Darkwood. The forest looms around you. You marvel at the
rumours of the Elven civilization which lives in the forest. To the south
you can see the grand towers of the city of Tharis, made rich by its
exploitation of its natural resources.
OLI
    );
set_smell("default","The wonderful fragrances of the forest waft through your senses.");
set_listen("default"," There is an unnatural quiet about the forest.");
    set_exits(([
"south" : "/d/tharis/road/road6",
       "north" : "/d/tharis/road/road4"
    ] ));
    set_items(([
       "road" : "The road is deeply rutted by the eons of travle by heavily laden wagons of
trade.",
"forest":"The forest is impenetrable around you, yet it seems to call for help."
    ] ));
}
void init(){
	::init();
add_action("help_wagon","push");
}
void reset(){
	::reset();
	if(!present("guard")){
		new("/d/tharis/monsters/cguard")->move(TO);
		new("/d/tharis/monsters/cguard")->move(TO);
	}
	if(!present("driver")){
		new("/d/tharis/monsters/cdriver")->move(TO);
	}
if(!present("wagon")){
new("d/tharis/obj/cwagon")->move(TO);
}
	}
int help_wagon(string str){     /* you had the return as void.. *must* be */ 
				/* int for add_action functions.. :) */
object ob;
   if(!present("wagon")) {
      tell_object(TP,"You don't see a wagon here.\n");
      return 1;
   }
 if((TP->query_stats("strength"))>10){
        write(
@OLI
You feel the wagon move slightly and lean into it more.
 After becoming thoroughly covered with mud, you feel 
the mud release its hold on the wagon. The driver thanks
 you (not quite sincerely) and then throws a few coins 
 into the mud as the wagon drives off.
OLI
);
//
// ok, It needs to be a type object, to move or remove..
// So I used present to get the object, using if, in case the monster
// isn't there, IE someone kills it before they push the wagon.
// the code follows.. and works.. 
//		Melnmarn
//
if(ob = present("driver",TO)){
	ob->move("d/shadowgate/void");
	ob->remove();
}
if(ob = present("guard",TO)){
	ob->move("d/shadowgate/void");
	ob->remove();
}
if(ob = present("guard",TO)){
	ob->move("d/shadowgate/void");
	ob->remove();
}
if(ob = present("wagon",TO)){
	ob->move("d/shadowgate/void");
	ob->remove();
}
TP->add_money("silver",10);
        }
 else{
          write(
@OLI
You fall flat on your face into the mud. The guards and driver laugh at your
 feeble attempt. The driver says: Go on! Get out of here
   before I DO SOMETHING BAD TO YOU!!!!!!!!!!!!!!
OLI
);
  }


  return 1;
}
