//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Bath");
    set_long(
    	"%^BOLD%^%^CYAN%^"+
    	"You enter a large, luxurious bathing and dressing area.  In the center of the "+
    	"room you see a large %^WHITE%^ivory %^CYAN%^enameled ceramic bathtub.  I would "+
    	"take many trips with hot %^BLUE%^water %^CYAN%^from the kitchen to fill this tub "+
    	"for the purpose of bathing.  Candles are placed at various points around the room to "+
	"light the room. Off to one side you notice a dressing table with a large oval "+
	"mirror.  Sitting on the table is a vase of fresh %^RED%^roses%^CYAN%^.  On the "+
	"other side of the room is a modesty screen for dressing and undressing for bathing."+
	"%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The gentle scent of roses tickles your nose.");
    set_listen("default","Sounds of the mountains winds buffeting the cottage can be heard.");
    set_items(([
    	({"bathtub","tub"}) : "\n%^RESET%^This is a rather large and expensive looking oval "+
		"tub is the dominant feature of the room.  On the side of the tub are oils "+
		"that can be added to bath water and are very fragrant.  Fresh towels and a "+
		"robe lay on one side of the tub ready for the next bather.\n",
	({"modesty screen","dressing screen","screen"}) : "\n%^RESET%^This is a dressing "+
		"screen makes it possible to get undressed for a bath, or dressed after a "+
		"bath, and retain your modesty.\n",
	({"dressing table","table"}) : "\n%^RESET%^The handsomely made dressing table is "+
		"made of a pure %^BOLD%^%^WHITE%^white %^RESET%^wood. It has tiny vines and "+
		"roses carved along the edges.  The oval mirror that sits atop the table lets "+
		"the user see their reflection so that they may complete their grooming "+
		"rituals.\n",
	({"candle","candles"}) : "\n%^RESET%^The candles will give the rom a soft gentle "+
		"light when lit.\n",
	({"bathrobe","robe"}) : "The bathrobe looks warm and inviting.\n",
	({"towels","towel"}) : "Soft fluffy towels are placed here to dry off with after a "+
		"bath.\n"
        ]));

    set_door("north door",LROOMS+"leauphall","south","brass key");
    set_open("north door",1);
    set_string("north door","open","The door swings open to the second floor hallway.\n");

    set_exits(([
	"south" : LROOMS+"leauphall"
    ]));
}