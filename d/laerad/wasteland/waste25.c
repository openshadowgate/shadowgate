#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste14",
	"east":"/d/laerad/wasteland/waste34",
	"north":"/d/laerad/wasteland/waste24",
	"south":"/d/laerad/wasteland/waste26"
    ]) );
}
int clean_up(){return 1;}

reset()
{
    ::reset();
    if (!objectp(present("silvim", TO))) {
        new("/d/laerad/mon/anti")->move(this_object());
    }
}
