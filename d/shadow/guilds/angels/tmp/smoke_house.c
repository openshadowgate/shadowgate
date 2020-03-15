//Coded by Bane//
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Smoke house storage room");
    set_short("Smoke house storage room");
    set_long(
	"This is a storage room.  If you are a mortal you shouldnt be here.  "+
	"Either teleport out or ask an immort to remove you."
    );
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_smell("default","It smells of oil and old clothes.");
    set_listen("default","The room is silent.");
    set_exits( ([
    ]) );
}

void reset() {
    ::reset();
    if(!present("afgan"))
	new("/d/shadow/obj/misc/afgan")->move(this_object());
    if(!present("brazil"))
	new("/d/shadow/obj/misc/brazil")->move(this_object());
	new("/d/shadow/obj/misc/brazil")->move(this_object());
    if(!present("broadleaf"))
	new("/d/shadow/obj/misc/broadleaf")->move(this_object());
	new("/d/shadow/obj/misc/broadleaf")->move(this_object());
    if(!present("cuban"))
	new("/d/shadow/obj/misc/cuban")->move(this_object());
	new("/d/shadow/obj/misc/cuban")->move(this_object());
    if(!present("latakia"))
	new("/d/shadow/obj/misc/latakia")->move(this_object());
	new("/d/shadow/obj/misc/latakia")->move(this_object());
    if(!present("turkish"))
	new("/d/shadow/obj/misc/turkish")->move(this_object());
	new("/d/shadow/obj/misc/turkish")->move(this_object());
}
