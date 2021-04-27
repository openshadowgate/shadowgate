//Coded by Diego//

#include <std.h>
#include "../daelmas.h"
inherit VAULT;

void blasting(object tp, int num);

void create(){
	::create();
   set_name("Garden");
   set_short("garden");
   set_long(
   	"%^GREEN%^"+
   	"Sitting on the edge of the cliff before you is a large "+
   	"and magnificent tower, made entirely of %^BOLD%^%^WHITE%^fine "+
   	"white marble%^RESET%^%^GREEN%^.  Upon closer inspection, "+
   	"you can make out decorative and intricate patterns that have "+
   	"been carved with the utmost precision into the towering "+
   	"walls, which casts a long shadow over you and the surrounding "+
   	"area. A path of circular %^BOLD%^%^WHITE%^white "+
   	"stones %^RESET%^%^GREEN%^leads to the tower, ending at "+
   	"a %^ORANGE%^large wooden door %^GREEN%^with a "+
   	"%^BOLD%^%^YELLOW%^golden knocker%^RESET%^%^GREEN%^, or trailing "+
   	"off into the garden. The garden enclosing you is filled with a "+
   	"variety of flowers and plants that grow around the entire "+
   	"structure.  Small %^BOLD%^%^MAGENTA%^violets %^RESET%^%^GREEN%^line "+
   	"the path, and beyond those grow %^MAGENTA%^dark purple "+
   	"%^GREEN%^and %^BOLD%^%^BLUE%^blue irises%^RESET%^%^GREEN%^, "+
   	"%^BLUE%^forget-me-nots%^GREEN%^, %^MAGENTA%^lavender %^GREEN%^and "+
		"%^BOLD%^%^MAGENTA%^lilacs%^RESET%^%^GREEN%^. The beautiful shades of "+
		"%^BOLD%^%^MAGENTA%^violet %^RESET%^%^GREEN%^and %^BOLD%^%^BLUE%^blue "+
		"%^RESET%^%^GREEN%^fade into deep shades of %^RED%^red %^GREEN%^and "+
		"%^BOLD%^%^RED%^crimson morning glories%^RESET%^%^GREEN%^, "+
		"%^YELLOW%^tulips %^GREEN%^and %^BOLD%^%^WHITE%^carnations"+
		"%^RESET%^%^GREEN%^. Deeper into the garden are flowers, "+
		"both common and exotic, of bright %^BOLD%^%^YELLOW%^"+
		"o%^RED%^r%^YELLOW%^a%^RED%^n%^YELLOW%^g%^RED%^e%^YELLOW%^s"+
		"%^RESET%^%^GREEN%^, %^BOLD%^%^WHITE%^white%^RESET%^%^GREEN%^, "+
		"%^YELLOW%^yellow %^RESET%^%^GREEN%^and every other color imaginable.  "+
		"The wall enclosing the garden is covered with %^RED%^roses "+
		"%^GREEN%^of every shade. Throughout the garden are marble statues "+
		"of magical creatures, and you can hear the sounds of %^CYAN%^water "+
		"%^GREEN%^splashing from a fountain somewhere deep within.  \n%^RESET%^"
   );
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
   set_property("indoors",0);
   set_property("light",2);
   set_smell("default","A wonderful, relaxing aroma of flowers fills the air.");
   set_listen("default","You hear the faint splashing of a fountain and leaves "+
   	"rustling in a slight breeze.");
   set_items(([
   	"tower" : "The tower is rather impressive and large. It reaches "+
   		"towards the sky, and casts a shadow all around it. The "+
   		"sides of the tower are finely carved out of white marble.\n",
   	"garden" : "Flowers and plants surround you, along with wonderful "+
   		"scents. Butterflies flutter among the flowers.\n"
	]));

   set_door("large door",DROOMS+"foyer","north","marble key");
   set_locked("large door",1,"lock");
   lock_difficulty("large door", "/daemon/player_housing"->get_phouse_lock_dc("common"),"lock");
   (DROOMS+"foyer")->set_locked("large door",1,"lock");
   set_door_description("large door","The door is very large and made of polished oak.");
   set_string("large door","open","You open the door into the foyer.\n");

  	set_door("iron gates",DROOMS+"twall","southeast","marble key");
   set_door_description("iron gates","The gate is made of blackened "+
   	"iron bars crossing over each other.");
   set_string("iron gates","open","The gates groan loudly as they "+
   	"open westward.\n");

   set_exits(([
		"north" : DROOMS+"foyer",
		"southeast" : DROOMS+"twall"
	]));

   set_climb_exits((["climb":({DROOMS+"balc",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall several feet to land crashing "+
   	"painfully into the garden!%^RESET%^\n");

	set_trap_functions(({"north"}),({"blast_em"}),({"north"}));
}
void init() {
  	::init();
  	add_action("disarm_em","trace");
}
int disarm_em(string str) {
   if(!str) {
     	tell_object(TP,"%^BOLD%^%^CYAN%^Trace what?");
     	return 1;
   }
  	if(str == "pattern"){
     	tell_object(TP,"%^BOLD%^You reach out and trace an "+
     		"arcane pattern on the door frame to toggle the trap "+
     		"just inside the door.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" reaches out and "+
        	"traces an arcane pattern on the door frame.\n%^RESET%^",TP);
   	toggle_trap("north");
		return 1;
   }
}
int blast_em(){
	tell_object(TP,"%^BOLD%^%^YELLOW%^You step through the door "+
		"and feel a tile in the floor sink under your weight.\n");
  	TP->force_me("emote looks suddenly concerned.");
	blasting(TP,0);
	return 1;
}
void blasting(object tp,int num){
   switch(num){
   	case(0):
   		tell_object(TP,"%^YELLOW%^Energy crackles and forms in the "+
      		"threshold of the door.\n");
         tell_room(ETP,"%^YELLOW%^Energy crackles and builds up in the "+
        		"door of the tower.\n",TP);
     		TP->set_paralyzed(5000,"%^BOLD%^%^RED%^You can't do that right now!");
        	break;
     	case(1):
     		tell_object(TP,"%^YELLOW%^Your hair stands on end as the "+
         	"charge builds.\n");
         tell_room(ETP,"%^YELLOW%^"+TPQCN+" starts to convulse "+
         	"erratically.\n",TP);
         break;
      case(2):
      	tell_object(TP,"%^YELLOW%^Suddenly the building energy "+
         	"reaches critical mass and explodes with a tremendous "+
				"%^BOLD%^%^RED%^BANG%^YELLOW%^ throwing you back the "+
				"way you came!!!\n");
			tell_room(ETP,"%^BOLD%^%^RED%^"+
				"The energy suddenly explodes with a "+
				"loud %^YELLOW%^BANG %^RED%^"+
				"sending "+TPQCN+" flying back the "+
				"way "+TP->query_subjective()+" came!\n",TP);
         TP->move(DROOMS+"dp0");
         TP->set_paralyzed(0);
			TP->do_damage("torso",roll_dice(4,10)+20);
			TP->add_attacker(TO);
			TP->continue_attack();
         break;
   	case(3):
   		tell_object(TP,"%^YELLOW%^You tumble in the air for a long "+
         	"distance landing hard just outside the gates of the tower.\n");
        	tell_room(ETP,"%^CYAN%^"+TPQCN+" tumbles into the room "+
         	"landing in a dishevelled heap! \n",TP);
			return;
 	}
   num++;
   call_out("blasting",0,tp,num);
   return;
}
void reset(){
        ::reset();
        if(!trapped("north"))toggle_trap("north");
}
