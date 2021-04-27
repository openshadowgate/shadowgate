//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Sitting Room");
    set_long(
    	"%^CYAN%^"+
    	"The cool darkness of this room is refreshing.  The floor is covered in a deep "+
	"%^BOLD%^%^BLUE%^sky-blue %^RESET%^%^CYAN%^wool rug.  Everything in the room "+
	"looks new as if it has never been used.  There is a couch in the corner of the "+
	"room that is covered with an expensive looking %^BOLD%^%^BLACK%^dove-grey "+
	"%^RESET%^%^CYAN%^brocade and numerous throw pillows.  A matching chair and "+
	"loveseat sit in the opposite end of the room closer to the fireplace.  An "+
	"exotic %^ORANGE%^roan wood %^CYAN%^coffee table dominates the center of the "+
	"room.  There are matching end tables on both sides of the couch and the "+
	"loveseat.  The walls are covered with stucco giving the the look of fresh "+
	"meringue.\n"+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells of flower and wood polish.");
    set_listen("default","The cottage is quiet.");
    set_items(([
      "rug" : "\n%^RESET%^The rug looks as deep as as ocean.  The wool has been "+
        	"combed repeatedly to make it soft and fluffy.  The color reminds you of a "+
		"cloudless day.\n",
	({"couch","loveseat","chair"}) : "\n%^RESET%^The %^BOLD%^%^BLACK%^gray "+
		"%^RESET%^brocade that covers this furniture looks to have been imported "+
		"from Seneca.  There is a design of %^RED%^roses %^RESET%^and %^GREEN%^ivy "+
		"%^RESET%^woven into the brocade that gives the fabric %^GREEN%^green "+
		"%^RESET%^and pink highlights.  All of the furniture looks, cozy, fluffy, "+
		"and soft.\n",
	({"end tables","end table"}) : "tables",
	"coffee table" : "coffee table"
        ]));
    set_exits(([
	"west" : LROOMS+"leahall"
    ]));
}