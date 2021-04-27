//Coded by Diego//

#include <std.h>
#include "../lea.h"
inherit VAULT;

void create(){
    ::create();
    set_short("Balcony");
    set_long(
    	"%^CYAN%^"+
    	"Stepping out onto the balcony the %^BOLD%^wind%^RESET%^ %^CYAN%^blows creating "+
    	"gentle breezes that refresh and invigorate you.  The view of the Dagger mountains "+
    	"is simply breathtaking.  Over in the corner of the balcony is a "+
	"%^ORANGE%^wooden%^CYAN%^ table with four chairs placed around it.  In each corner "+
	"of the balcony there are poles holding lanterns to provide %^YELLOW%^light%^RESET%^ "+
	"%^CYAN%^when it gets dark. \n"+
	"%^RESET%^"
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","Clean, fresh mountain air greats your senses.");
    set_listen("default","You hear the sounds of the wind whispering over the landscape.");
    set_items(([
      ({"table","chairs","chair"}) : "\n%^RESET%^This small %^ORANGE%^wooden%^RESET%^ "+
        	"table and chairs provides you a comfortable place to relax and enjoy the "+
        	"view.  The chairs are cushioned with pillows to make them more comfortable.  "+
		"Upon the table you notice a tray with a carafe of%^BOLD%^%^MAGENTA%^ "+
		"Feywine %^RESET%^and several wine glasses.  You, also, notice a plate "+
		"with %^YELLOW%^cheeses %^RESET%^and breads and a bowl containing several "+
		"different types of %^BOLD%^%^GREEN%^fruits%^RESET%^.\n",
	({"tray","carafe","glasses","wine"}) : "\n%^RESET%^You see a pitcher holding what "+
		"appears to be %^BOLD%^%^MAGENTA%^Feywine%^RESET%^.  The accompanying aroma of "+
		"the wine is very pleasant.  The tray appears to be lacquered %^ORANGE%^wood "+
		"%^RESET%^and  also holds six beautifully etched glasses.\n",
	({"plate","cheese","cheeses","bread","breads"}) : "\n%^RESET%^This%^BOLD%^%^WHITE%^ "+
		"ivory %^RESET%^colored plate contains a variety of %^YELLOW%^cheeses "+
		"%^RESET%^and %^WHITE%^breads %^RESET%^imported from different cities of the "+
		"realm.\n",
	({"bowl","fruit"}) : "\n%^RESET%^A clay bowl is filled with ripe, luscious "+
		"%^BOLD%^%^GREEN%^fruits %^RESET%^of many different varieties.  The breezes "+
		"carry to mouth watering aroma of the many %^BOLD%^%^GREEN%^fruits%^RESET%^ "+
		"to your nose.\n",
	"mountains" : "\n%^RESET%^The panoramic view unfolds before you.  The balcony is "+
		"situated on the east side of the cottage to provide for a magnificent view "+
		"of the %^BOLD%^%^YELLOW%^sun %^RESET%^setting over the%^BOLD%^%^BLACK%^ "+
		"Dagger %^RESET%^Mountains.  The way the %^BOLD%^%^BLACK%^shadows %^RESET%^"+
		"will play over the landscape at sunset will be nothing less than stunning.\n"
        ]));

    set_door("glass doors",LROOMS+"leastudy","east","brass key");
    set_door_description("glass doors","%^RESET%^The large %^BOLD%^%^CYAN%^glass "+
		"%^RESET%^double doors seem to take up the entire back wall.  They give you "+
		"an excellent view of the Dagger Mountains.  You can see a balcony on the "+
		"otherside of the doors.\n");
    set_string("glass doors","open","The door swings open to the study.\n");


    set_exits(([
	"east" : LROOMS+"leastudy"
    ]));
}