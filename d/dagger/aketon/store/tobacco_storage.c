#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon Tobacco Shop Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("broadleaf"))
      new(MISCPATH+"broadleaf")->move(TO);
   if(!present("broadleaf 2"))
      new(MISCPATH+"broadleaf")->move(TO);
   if(!present("broadleaf 3"))
      new(MISCPATH+"broadleaf")->move(TO);
   if(!present("latakia"))
      new(MISCPATH+"latakia")->move(TO);
   if(!present("latakia 2"))
      new(MISCPATH+"latakia")->move(TO);
   if(!present("latakia 3"))
      new(MISCPATH+"latakia")->move(TO);
   if(!present("brazil"))
      new(MISCPATH+"brazil")->move(TO);
   if(!present("brazil 2"))
      new(MISCPATH+"brazil")->move(TO);
   if(!present("brazil 3"))
      new(MISCPATH+"brazil")->move(TO);
   if(!present("cuban"))
      new(MISCPATH+"cuban")->move(TO);
   if(!present("cuban 2"))
      new(MISCPATH+"cuban")->move(TO);
   if(!present("turkish"))
      new(MISCPATH+"turkish")->move(TO);
   if(!present("turkish 2"))
      new(MISCPATH+"turkish")->move(TO);
   if(!present("afgan"))
      new(MISCPATH+"afgan")->move(TO);
}
