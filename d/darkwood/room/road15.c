//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/9/94
//	Darkwood forest
//	road15
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
    set_long(
@THORN
You are on the Royal Southern Road.  The road seems to be
skirting the southern edge of a dark forest.  To the south
of you appears to be some hills and a wide plain stretching
to the horizon.  The road continues to the east-west.
THORN
    );
    set_exits(
              (["west" : "/d/darkwood/room/road14",
				"east" : "/d/darkwood/room/road16"]) );
    set_smell("default","The scent of pine lingers in the air.");
}

