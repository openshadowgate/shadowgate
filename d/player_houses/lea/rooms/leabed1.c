//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    	set_short("Guest Bedroom");
	set_long(
    		"%^CYAN%^"+
    		"This room is decorated in rich %^RED%^burgandy%^CYAN%^.  The hardwood floor "+
    		"has been stained dark cherry.  A %^RED%^burgandy%^CYAN%^, hand braided, "+
    		"throw rug lies on the floor next to the bed.  There is a dresser along one "+
		"wall.  On the dresser is a %^BOLD%^%^BLUE%^wash %^RESET%^%^CYAN%^basin and "+
		"a picture stand.  The bed is a four poster.  Covering the bed is a "+
		"%^RED%^burgandy%^CYAN%^ bedspread decorated with tiny pink roses.  The "+
		"curtains on the windows match the bedspread.  Next to the bed is a table "+
		"with an oil lamp sitting upon it.\n"+
		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
   	set_smell("default","The room smells clean and fresh with a hint on rose in the air.");
    	set_listen("default","The room is quiet.");
    	set_items(([
        	"floor" : "\n%^RESET%^The hardwood floor has been stained a dark %^RED%^cherry "+
			"%^RESET%^color and has been polished to a glossy shine.\n",
		"bed" : "\n%^RESET%^This king size four poster bed has been crafted from "+
			"%^RED%^cherry%^RESET%^ wood.  A flowering iris design has been carved "+
			"into the headboard as well as vining ivy carved into the foorboard and "+
			"posts.  Draped along the sides and the top of the bed are sheer cotton "+
			"drapes that have been died to a deep %^RED%^burgandy%^RESET%^.  Many "+
			"tiny pink roses have been embriodered onto the drapes.  The drapes are "+
			"open and tied back with a pink ribbon with %^GREEN%^green%^RESET%^ ivy "+
			"embroidery.  There are four oversized goose down pillows, covered with "+
			"crisp white linen pillow cases, adorning the head of the bed and the "+
			"bed istself is covered with a %^RED%^burgandy%^RESET%^ bedspread that "+
			"is embroidered with little pink rosebuds.\n",
		"rug" : "\n%^RESET%^This woven rug is made of wool that has been died to a "+
			"rich %^RED%^burgandy %^RESET%^with strands of wool died pale pink to "+
			"accent the color",
		"table" : "\n%^RESET%^The bedside table is made of %^RED%^cherry%^RESET%^ "+
			"wood and has an ivy design carved into its front.  A glass oil lamp "+
			"sits on the table.",
		"lamp" : "\n%^RESET%^The glass oil lamp has pink roses painted onto its "+
			"base.  The lamp sits on the bedside table to provide light onto the "+
			"head of the bed.\n",
		"dresser" : "\n%^RESET%^This is a five drawer made from %^RED%^cherry "+
			"%^RESET%^wood.  An ivy design has been carved into the front of the "+
			"dresser.  The two knob handles on each of the drawers are made of "+
			"%^ORANGE%^brass%^RESET%^.\n",
		"window" : "\n%^RESET%^The window gives you a wonderful view of the valley "+
			"below.  The %^RED%^burgandy%^RESET%^ curtains are tied back with a "+
			"pale pink ribbon.\n"
        ]));

    	set_door("south door",LROOMS+"leauphall","north","brass key");
      set_open("south door",1);
    	set_string("south door","open","The door swings open to the second floor hallway.\n");

    	set_exits(([
		"north" : LROOMS+"leauphall"
    ]));
}