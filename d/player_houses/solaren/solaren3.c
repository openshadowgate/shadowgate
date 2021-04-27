// At the summit of the mountain
// Thorn@ShadowGate
// 001023
// Solaren's Player House
// solaren3.c
// modified to become a mage guild tower ala Sherlock & Stefano by *Styx* 4/21/03

#include <std.h>
#include "../defines.h"

inherit VAULT;

void create() {
  ::create();
   set_name("Before the walls");
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
  set_property("light", 2);
  set_short("%^YELLOW%^Before the tower walls%^RESET%^");
  set_long("%^YELLOW%^Before the tower walls%^RESET%^\n"
"Having reached the summit of the mountain, you can see the structure at "
"the top.  You stand in front of a smooth %^BOLD%^%^BLACK%^black stone "
"wall %^RESET%^that surrounds "
"a %^BOLD%^%^BLACK%^tall dark tower%^RESET%^.  Within the wall itself sit "
"%^BOLD%^white, paper thin, gates%^RESET%^.  The silence of the tower "
"appears to battle with the sounds of the forest, the walls being the "
"point at which the two meet.  To the side of the gates, attached to the "
"wall, is a %^YELLOW%^sign%^RESET%^.  From this gate the narrow path "
"descends down the mountain to the Dagger Sea road."
   ); 

/* was this
@THORN
%^YELLOW%^At the summit of the mountain%^RESET%^
%^CYAN%^Having reached the summit of the mountain, you can see the structures at
the top.  Surrounding the tower is a high stone wall which rambles along
the natural contours of the rock.  At one point, you notice a large
door, gatehouse and portcullis leading within the Tower grounds.  At
this gate is where the narrow path begins its descent down the mountain
and to to Dagger Sea road.  
THORN
  );
*/
  set_smell("default", "You can vaguely smell the salts of the sea on the cool breeze.");
  set_listen("default", "The muted sound of the waves float across the distance to your ears.");
  set_items(([
    "cliffs" : "You hear but not see the ocean below the great granite cliffs nearby.",
    "sea" : "You can hear the sea pounding the roots of the hills in the distance.",
    "tower" : "Made of a reflecting material, it rises high above the walls and seems to show tinges of various colors in the sun.",
    "path" : "Very narrow, this path seems to wind its way northwest down the mountain and into the hills.",
    "walls" : "The walls are smooth, as if melted into place.  The wall is at least 20 feet high with metal spikes protruding from the top at regular intervals.",
    "sign" : "As you look at the sign, writing on it forms a language you understand.\n"
	"  '%^YELLOW%^All may enter the Courtyard and Assembly of the Tower.\n"
	"  Do not bring malice with you.\n"
	"  Enter with a purpose, this is not a place for lingerers.\n"
	"  Here and in the Assembly, the rules of the Tower apply, including "
	"no fighting or thieving, whomever is there.\n"
	"  Any fighting will result you being hunted you down, and the overseers "
	"of the tower are more than capable of this - the Courtyard and Assembly "
	"is watched at all times.\n  You have been warned.%^RESET%^'",
  ]));
  set_exits(([
      "enter" : "/d/player_houses/solaren/solaren4",
      "northwest" : "/d/player_houses/solaren/solaren2",
  ]));
  set_door("gates","/d/player_houses/solaren/solaren4","enter","solaren house key");
  set_locked("gates",1);
  set_door_description("gates", "At first glance the gates look thin and fragile but on closer inspection they appear very strong and robust, as if from some magical force.");
  "/d/player_houses/solaren/solaren4"->set_locked("gates",1);
}

void reset(){
  ::reset();  
}

void init(){
  ::init();  
  add_action("snap", "snap");
}

int snap(string str) {
  object ob;
  object other;
  
  if(str != "twice") return 0;
//  if(((string)TP->query_name() != "solaren") && !avatarp(TP))  changing to check members
  if(member_array(TP->query_name(), MAGE_MEMBERS) == -1 && !avatarp(TP))
    return 0;
  other = find_object_or_load("/d/player_houses/solaren/solaren4");
  if(!query_locked("gates")) {
    tell_room(TO, TP->query_cap_name()+" snaps "+TP->query_possessive()+
	  " fingers twice and you hear a bolt slam home!", ({ TP }));
    tell_room(other, "You hear a bolt slam home on the gates!", ({ TP }));
    write("You snap your fingers twice and the gates lock!");
    TO->set_open("gates",0);
    TO->set_locked("gates",1);
    other->set_locked("gates",1);
    other->set_open("gates",0);
	return 1;
  } 
  tell_room(TO,
    TP->query_cap_name()+" snaps "+TP->query_possessive()+
	" fingers twice and you hear a bolt drop as the gates unlock!",
    ({ TP }));
    tell_room(other, "You hear a bolt drop as the gates unlock!", ({ TP }));
  write("You snap your fingers twice and the gates unlock!");
  TO->set_locked("gates",0);
  other->set_locked("gates",0);
  return 1;
}
