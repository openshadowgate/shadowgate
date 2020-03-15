#include "/d/shadow/room/city/melnmarn.h"
#include "/d/antioch/areadefs.h"

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
     set_short("The Antioch Village Bar");
    set_long(
@ANTIOCH
%^BOLD%^Welcome to the Antioch Village Bar!%^RESET%^
%^MAGENTA%^This bar is one of the least famous bars in Antioch.  A drunk sits here
night and day doing nothing but drinking and talking.  The drunk seems
to be saying something of great importance but you can't understand one
word he is saying.  The bar tender also seems to be under some sort of
strange spell.
ANTIOCH
);
  set_smell("default","You smell the odor of beer and sweat.");
  set_listen("default","You hear the sounds of glasses clanging.");
  set_items(
    (["pub" : "The most hoppin' place in Shadow.",
    "bar" : "The CrossRoads Bar",
    "list" : "It looks like a list of drinks. Read it to see what's available."
  ]));
  set_exits(([
    "east":VIL+"main_st7.c"
  ]));
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
  if(!present("makun"))
    new("/d/antioch/mon/makun")->move(this_object());
  new("/d/antioch/mon/drunk")->move(this_object());
}

int read(string str) {
  object ob;
  string *menu_item,melnmarn;
  int length;

  ob = present("makun");
  if(!ob) {
    write("You cannot read the menu, as it is splattered with blood.");
    return 1;
  }
  menu_item = ob->query_menu();
  length = sizeof(menu_item);
  message("Ninfo", "%^MAGENTA%^This is a list of the drinks sold at the Crossroads Bar.\n",TP);
  message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n",TP);
  while(length--){
    melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
    write(melnmarn);
  }
  message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n",TP);
  message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n",TP);
  return 1;
}
