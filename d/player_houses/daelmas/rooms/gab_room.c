//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void create(){
 	::create();
   set_name("Lady's room");
   set_short("Lady's room");
   set_long(
   	"%^RESET%^"+
   	"The walls of this room are %^BOLD%^ivory-white%^RESET%^ "+
   	"with lean pillars placed against them supporting the low, "+
   	"slightly domed and decorated, ceiling above your head. Carved "+
   	"into the white ceiling are many images, some appear as serene "+
   	"depictions of forest life, while others form, in contrast, "+
   	"twisted images of torture and anguish.  A large %^YELLOW%^gold "+
   	"%^RESET%^and %^BOLD%^%^CYAN%^crystal %^RESET%^chandelier hangs "+
   	"from the ceiling. Below it, the floor is a pattern "+
   	"of %^BOLD%^%^BLACK%^black %^RESET%^and %^BOLD%^%^BLACK%^gray "+
   	"stones %^RESET%^that spiral out from the center, creating the "+
   	"image of a whip with nine-strands. Beyond that, the floor raises "+
   	"a step and is covered with thick, %^RED%^crimson colored "+
   	"carpet%^RESET%^. A window of stained glass is set into the wall, "+
   	"allowing light to shine through the colored panels. In front of "+
   	"the window is a small %^BOLD%^%^BLACK%^black wooden desk %^RESET%^with "+
   	"many drawers. A delicately carved chair and loveseat sit off to "+
   	"the side, near the wall that is covered with a large mirror.  In "+
   	"it reflects the opposite wall, which is nearly plain except "+
   	"for a %^YELLOW%^golden plaque%^RESET%^. Fresh "+
   	"%^BOLD%^white roses%^RESET%^, lined with "+
   	"%^BOLD%^%^MAGENTA%^purple%^RESET%^, fill the larges vases around "+
   	"the room, and other plants sit against the walls and hang from "+
   	"the ceiling.\n"
   );
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","You smell the fresh scent of roses.");
   set_listen("default","It feels cold in here, and the silence is overwhelming.");
   set_items(([
		"ceiling" : "The ceiling is low, and curves in slightly "+
			"towards the middle. Carved into the white marble are "+
			"many images, some looking very peaceful, while others "+
			"are nearly hideous and contorted.\n",
		"floor" : "The stones are flat and sparkle faintly. You "+
			"recognize the pattern displayed here.\n",
		"window" : "The window is full of color, depicting a crucified "+
			"and badly injured man. Around him stands figures in long "+
			"robes, wielding whips and other weapons.\n",
		"desk" : "The desk is carved from wood and polished black. It "+
			"is completely bare, and the drawers are locked.",
		"plaque" : "The plaque is made of gold, with silver script that "+
			"appears to be in Elven."
	]));

   set_door("western door",DROOMS+"land3","east","marble key");
   set_door_description("western door","The door is polished and made from oak.");
   set_string("western door","open","You open the door onto the landing.\n");

   set_exits(([
		"east" : DROOMS+"land3"
   ]));
}
void init() {
  	::init();
  	add_action("read","read");
}
int read(string str) {
  	if(!str) {
        	tell_object(TP,"Read what?");
        	return 1;
   }
  	if(str == "plaque"){
   	if(TP->query_lang("elven") < 1) {
      	tell_object(ETO,"The inscription is written in a language "+
      		"you do not know.");
         return 1;
     	}
      if(TP->query_lang("elven") < 75) {
      	tell_object(ETO,"The inscription is written in elven, but you "+
         	"do not know the language well enough to read what it says.");
         	return 1;
      }
     	write("%^BOLD%^%^WHITE%^"+
			"Kindness is the best companion to hurt and increases "+
			"the intensity of suffering. Let mercy of sudden abstinence "+
			"from causing pain and of  providing unlooked for healing "+
			"come over you seldom, but at whim, so as  to make folk "+
			"hope and increase the Mystery of Loviatar's Mercy. "+
			"Unswerving cruelty will turn all folk against you. Act "+
			"alluring, and give pain and torment to those who enjoy "+
			"it as well as to those who deserve it most or would be "+
			"most hurt by it. The lash, fire, and cold are the three "+
			"pains that never fail the devout. Spread my teachings "+
			"whenever punishment is meted out. Pain tests all, but "+
			"gives strength of spirit to the hardy and the true. "+
			"There is no true punishment if the punisher knows no "+
			"discipline.\nWherever a whip is, there am I.\n"+
			"Fear me - and yet long for me."+
			"%^RESET%^");
     	return 1;
  	}
}