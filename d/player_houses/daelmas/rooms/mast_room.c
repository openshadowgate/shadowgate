//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
  	::create();
   set_name("Master bedroom");
   set_short("master bedroom");
   set_long(
   	"%^RESET%^"+
   	"This is by far the grandest room of the tower.  The walls are "+
   	"made of %^BOLD%^stunning white marble%^RESET%^, except for "+
   	"a huge, %^BOLD%^%^BLACK%^gray fireplace %^RESET%^against the "+
   	"southern wall.  The floor, also %^BOLD%^%^BLACK%^gray marble%^RESET%^, "+
   	"is almost entirely covered with a lavish %^RED%^crimson%^RESET%^ "+
   	"and %^YELLOW%^gold %^RESET%^rug. Nearing the northern wall, 3 "+
   	"carpeted steps lead up to a platform where a magnificent "+
   	"4-poster bed sits.  The %^ORANGE%^oak bed %^RESET%^is very large, "+
   	"concealed behind sheer %^RED%^crimson curtains%^RESET%^ that "+
   	"surround it entirely.  A %^BOLD%^%^RED%^satin crimson comforter %^RESET%^"+
   	"covers the bed, making it look very soft and inviting.  A large "+
   	"elaborate chest sits in front of the bed.  A huge wooden wardrobe "+
   	"leans against the east wall. It is beautifully crafted and "+
   	"the mirrored doors reflect flawlessly the entire bedroom. The "+
   	"walls are decorated with huge paintings, and lined with crystal "+
   	"figurines upon %^YELLOW%^golden %^RESET%^pedestals. Large exotic "+
   	"vases hold %^BOLD%^%^RED%^crimson %^RESET%^and %^BOLD%^white %^RESET%^"+
   	"roses, which fill the room with a pleasant scent. Three small windows "+
   	"allow light to enter the room, and small oil lamps built into the "+
   	"walls also provide ample lighting.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The room smells wonderfully of roses.");
   set_listen("default","You hear a faint breeze blowing outside.");
   set_items(([
		"fireplace" : "The fireplace is immense, and made from a stunning "+
			"white marble that seems to gleam.  The sides of the "+
			"fireplace are lined with gold, as is the mantle. Small "+
			"and exotic looking trinkets decorate the mantle, along "+
			"with an arrangement of fresh flowers, which sits in the "+
			"middle.\n",
		"bed" : "The bed is so large, it could easily sleep six people. "+
			"Sheer crimson curtains are draped around the entire bed, "+
			"and behind them is a crimson colored satin comforter and "+
			"two large matching pillows.  The bed looks incredibly soft "+
			"and you feel the urge to lay down.\n",
		"chest" : "This is a wooden chest lined with gold. There is a large "+
			"golden chest.\n",
		"wardrobe" : "This is a wooden wardrobe. On the sides, a pattern "+
			"of flowers has been delicately carved into the wood. The "+
			"doors of the wardrobe are large mirrors, which go from the "+
			"ground to the top, above your head.  You see your own "+
			"reflection as well as the rest of the room behind you.\n",
		"paintings" : "The pictures are of people and cities you do not "+
			"recognize. There are also pictures of the sea, and of large "+
			"forests.\n",
		({"figurine","figurines"}) : "Many of the figurines seem to be of "+
			"dragons, others elves, and others are artistic carvings.\n",
		({"vase","vases"}) : "The vases are deep shades of green, blue and "+
			"purple. The pattern of colors are lined with gold. Large, "+
			"fresh roses fill over the tops of the vases, and are quite "+
			"beautiful.\n"
	]));

   set_door("door",DROOMS+"land4","east","marble key");
   set_door_description("door","The door is made of magnificently polished oak.");
   set_string("door","open","You open the door onto the fourth landing.\n");

   set_exits(([
		"east" : DROOMS+"land4"
   ]));
}
void init() {
  	::init();
  	add_action("lay","lay");
  	add_action("open","open");
}
int lay(string str) {
   if(!str) {
     	tell_object(TP,"Lay on what?");
     	return 1;
   }
  	if(str == "on bed" || str == "bed"){
     	tell_object(TP,"%^BOLD%^%^CYAN%^As you sink into the down mattress and "+
     		"feel the warm, soft satin against your flesh, you "+
     		"have the overwhelming urge to close your eyes and "+
     		"take a nap.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" lies on the bed and "+
        	"relaxes deeply.\n%^RESET%^",TP);
		return 1;
 	}
}
int open(string str) {
   if(!str) {
     	tell_object(TP,"Open what?");
     	return 1;
   }
  	if(str == "chest"){
     	tell_object(TP,"%^BOLD%^As you fiddle around with the lock, a feeling of "+
     		"being watched overcomes "+
     		"you and you step back quickly.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" fiddles with the chest then backs "+
        	"away perplexed.\n%^RESET%^",TP);
		return 1;
  	}else if(str == "wardrobe"){
     	tell_object(TP,"%^BOLD%^%^MAGENTA%^The inside of the wardrobe is "+
     		"filled with clothing of many colors, ranging "+
     		"from %^RESET%^%^WHITE%^white %^BOLD%^%^MAGENTA%^to "+
			"%^WHITE%^silver%^MAGENTA%^, %^BLACK%^black%^MAGENTA%^ and "+
			"%^YELLOW%^gold%^MAGENTA%^.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" opens the "+
        	"wardrobe.\n%^RESET%^",TP);
		return 1;
	}
}