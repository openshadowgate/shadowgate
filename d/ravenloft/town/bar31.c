// Coded by Bane
// bar31.c
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("Village of Barovia");
    set_long(
	"%^RED%^"
	"You are on one of the villages main roads.  There "+
	"are houses on either side of you, most of them "+
	"are either abandoned or too dangerous to live in.  "+
	"There are a few peasants sitting in the gutter "+
	"begging for food or spare change.  The road "+
	"continues to the northwest and southeast."
	"%^RESET%^"
    );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_listen("default","The sounds of wolves howling in the distance sends a shiver up your spine.");
    set_smell("default","You can smell smoke drifting towards you from the village.");
    set_exits( ([
	"northwest":"/d/ravenloft/town/bar32",
	"southeast":"/d/ravenloft/town/bar30",
    ]) );
}
