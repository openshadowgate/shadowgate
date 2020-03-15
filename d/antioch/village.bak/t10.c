// /d/antioch/village/t10.c

#include "/d/antioch/areadefs.h"
#include <std.h>

inherit ROOM;

int clean_up(){return 1;}
void create(){
object ob;
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("The top of the tower.");
  set_long(
@ANTIOCH
%^BOLD%^You are in the Dark Tower%^RESET%^
%^BLUE%^You are in what seems to be the top of the tower, but you can see some
light coming from the east.  To the west, there appears to be complete
nothingness.  There is a large sign made out of rat bones here.
%^RESET%^%^YELLOW%^READ THE SIGN%^RESET%^.
ANTIOCH
);
  set_exits(([
    "east":VIL+"t11",
    "down":VIL+"t9"
  ]));
  set_items(([
    "skeleton":"This is a dried up skeleton of a human."
  ]));
  set_smell("default","You can smell the cold steam.");
  set_listen("default","You can hear the sound of swords and fighting.");
  //f(!find_living("elzyn"))
      new("/realms/grazzt/assassins/elzyn")->move(TO);
}

void init() {
  ::init();
  add_action("read_sign","read");
}
 
int read_sign(string str) {
  if(str != "sign") return 0;
  write("%^RED%^%^BOLD%^ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
%^RED%^ |%^WHITE%^   Do not go east unless    %^RED%^|
%^RED%^ |%^WHITE%^     you have a power       %^RED%^|
%^RED%^ |%^WHITE%^     greater than god.      %^RED%^|
%^RED%^ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  ");
  tell_room(TO,TPQCN+" reads over the sign.",TP);
  return 1;
}

