//storage room for herb shop, new Seneca
//~Circe~ 4/20/08 with help from Ares :)
// moved herb inherit data to new /d/common/obj/brewing file. N, 12/11.
#include <std.h>
#include "../seneca.h"
inherit ROOM;

void create() {
    ::create();
    set_property("no teleport",1);
    set_light(3);
    set_indoors(1);
    set_name("Seneca Herb Storage");
    set_short("Seneca Herb Storage");
    set_long("This is a storage room filled with all sorts of herbs.  You shouldn't be here!");
    set_exits(([
       "up" : ROOMS"herb_shop"
    ]));
}

void reset() {
    string herb;
    object ob;
    string hn;
    int i;
    ::reset();
   while(!present("packet of herbs 100")) {
        ob = new("/d/common/obj/brewing/herb_inherit");
        ob->move(TO);
        hn = ob->query_herb_name(); 
        
        if (!present(hn + " 9")) {
            i = 0;
            while (i < 9) {
                ob = new("/d/common/obj/brewing/herb_inherit");
                ob->set_herb_name(hn);
                ob->move(TO);
                i++;
            }
        }
   }
   if(!present("herb pouch")) new("/d/common/obj/brewing/herb_pouch")->move(TO);
   if(!present("herb pouch 2")) new("/d/common/obj/brewing/herb_pouch")->move(TO);
   if(!present("herb pouch 3") && !random(3)) new("/d/common/obj/brewing/herb_pouch")->move(TO);
}