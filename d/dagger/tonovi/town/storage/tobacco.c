//storage room for Tonovi.  Circe 12/29/04
#include <std.h>
#include "../../short.h"
inherit ROOM;

#define OBJ "/d/common/obj/misc/"+

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Tobacco Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : "/d/dagger/tonovi/town/bazaar5"]));
}

void reset()
{
	::reset();
if(!present("afgan"))
 new(OBJ"afgan")->move(TO);
if(!present("brazil"))
 new(OBJ"brazil")->move(TO);
if(!present("brazil 2"))
 new(OBJ"brazil")->move(TO);
if(!present("broadleaf"))
 new(OBJ"broadleaf")->move(TO);
if(!present("broadleaf 2"))
 new(OBJ"broadleaf")->move(TO);
if(!present("cuban"))
 new(OBJ"cuban")->move(TO);
if(!present("latakia"))
 new(OBJ"latakia")->move(TO);
if(!present("turkish"))
 new(OBJ"turkish")->move(TO);
if(!present("pipe"))
 new(OBJ"pipe")->move(TO);
if(!present("pipe 2"))
 new(OBJ"pipe")->move(TO);
}
