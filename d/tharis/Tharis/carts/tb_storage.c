#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;
void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
    set("short", "tobacco vendor's cart");
    set("long", "Supplies and such are stored here.\n");
}
void reset() {
::reset();
if(!present("cuban"))
 new(MISCDIR+"cuban")->move(this_object());
if(!present("turkish"))
 new(MISCDIR+"turkish")->move(this_object());
if(!present("brazil"))
 new(MISCDIR+"brazil")->move(this_object());
if(!present("latakia"))
 new(MISCDIR+"latakia")->move(this_object());
if(!present("broadleaf"))
 new(MISCDIR+"broadleaf")->move(this_object());
             }
void call_reset(){ reset(); }   
