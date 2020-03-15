//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",2);
     set_short("This is a dark cleaing.");
        set_long(
@BUILD
You are in the second room of the jail.  Many %^RED%^skulls%^RESET%^
lurk around the room looking from side of the prison to the other.
A huge zombie guard stands here and watches you.  Water seeks in through
a small hole in the ground.  A shovel is here for some odd reason.
BUILD
);
        set_exits(([

"south"  :"/d/antioch/village/jail1.c"
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
                "sign":"This is a worn sign, you may be able to read it.",
"shovel":"maybe you could <%^CYAN%^grab%^RESET%^> the shovel.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","The smell of Death is in the air.");
     set_listen("default","You can hear the shouts of the crowd and "+
           "the sound of battle raging.");

}

void init(){
::init();
add_action("grab_shovel", "grab");
}




int kill_zombie(string str){
if(!str) {
notify_fail("kill what?\n");
return 0;
}
new("/d/antioch/mon/"+str)->move(TO);
new("/d/antioch/mon/"+str)->move(TO);
new("/d/antioch/mon/"+str)->move(TO);
new("/d/antioch/mon/"+str)->move(TO);
new("/d/antioch/mon/"+str)->move(TO);
write("%^MAGENTA%^A voice cheers:%^RESET%^ You will never defeat me.\n");
write("%^YELLOW%^An army of zombies arise from the ground!!!\n");
return 1;
}
grab_shovel(string str) {
write("A huge hole forms and sucks you out.\n");
  TP->move_player(VIL+"town_sq2w");
write("%^MAGENTA%^A voice yells:%^RESET%^ NO!!!, you shalt not defeat me.\n");
return 1;
}

void reset(){


if (!present("zombie"))

new("/d/antioch/mon/zombie.c") -> move(this_object());

}








