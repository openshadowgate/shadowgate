// An abandoned temple
// Thorn@ShadowGate
// 001205
// Rufus' Player House
// entry.c (was entry2)
// Was entry2 and apparently Thorn just hadn't put it in game yet.  Rather than
// work through everything to debug creating a secret entrance and blocking off
// the door, I added difficulty to the locks and a few other minor changes and
// made this the new entry (entry2.notused is before the changes) *Styx*  4/5/02

#include <std.h>

inherit VAULT;

void create() {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_name("An abandoned temple");
  set_short("%^BOLD%^An abandoned temple%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This room is dark, even if you have enough light to "+ 
  "look around. From what you can tell, this is an %^RESET%^ancient temple "+ 
  "%^BOLD%^%^BLACK%^of some sort, probably used by ancient peoples who inhabited "+ 
  "the Echoes Mountains area. There are dusty stone pillars which bear "+ 
  "%^RESET%^%^MAGENTA%^runes %^BOLD%^%^BLACK%^engraved in an unknown ancient "+ 
  "language. In the center of the floor is a raised %^RESET%^starburst "+ 
  "%^BOLD%^%^BLACK%^in the floor, made of darkest obsidian, but cracked, as "+ 
  "though it was hit by a giant stone which has since disappeared. Though "+ 
  "everything seems harmless, there is a quivering in the air which feels "+ 
  "like a distant memory of %^RESET%^%^RED%^evil %^BOLD%^%^BLACK%^calling "+ 
  "from some sort of prison that it can never escape from.\n\nThere is a "+ 
  "great %^RESET%^iron door %^BOLD%^%^BLACK%^set in the south wall that "+ 
  "bears a %^MAGENTA%^s%^RESET%^%^MAGENTA%^i%^BOLD%^gil %^BLACK%^that almost "+ 
  "seems to %^MAGENTA%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^w %^BLACK%^faintly in "+ 
  "time with the quiverings in the air.%^RESET%^\n");
  set_smell("default", "The smell of parchment and leather pervades the room.");
  set_listen("default", "There is the sound of a fire crackling.");
  set_items(([
    "starburst" : "It looks like a broken symbol of a dark sun.",
    "sigil" : "This is a complex and obviously magical symbol.  You "
              "realize that this sign was put here by a power that you "
              "cannot even imagine and it will still be here long "
              "after you are dead and gone.",
  ]));
  set_exits(([
      "north" : "/d/player_houses/rufus/cfloor",
      "south" : "/d/player_houses/rufus/hall",
  ]));
  set_door("iron door","/d/player_houses/rufus/hall","south","rufus house key");
  set_door_description("iron door", "This door is made of cold, black iron and "
      "is probably as heavy as a city gate.  You do notice, however, that the "
      "hinges are remarkably preserved, and would work perfectly "
      "if you could somehow get the door to unlock.");
  add_lock("iron door","rufus house key","vault lock",
           "This is a huge locking mechanism which is similar to that "+
           "of some bank safes you have seen.");
  add_lock("iron door","rufus house key","sigil lock",
           "This is a symbol, obviously magical, which glows a greenish "+
           "color and seems to float above the door where it illuminates "+
           "what appears to be a mundane, if complex-looking, locking "+
           "mechanism.");
  set_open("iron door",0);
  set_locked("iron door",1,"lock");
  set_locked("iron door",1,"sigil lock");
  set_locked("iron door",1,"vault lock");
   lock_difficulty("iron door", "/daemon/player_housing"->get_phouse_lock_dc("legendary"),"sigil lock");
   lock_difficulty("iron door", "/daemon/player_housing"->get_phouse_lock_dc("legendary"),"vault lock");
//  "/d/player_houses/rufus/hall"->set_locked("iron door",1,"sigil lock");
//  "/d/player_houses/rufus/hall"->set_locked("iron door",1,"vault lock");

  "/d/player_houses/rufus/hall"->set_open("iron door",0);
	set_trap_functions(
	   ({  "iron door", "iron door", "south"}),
	   ({ "lock_traps","lock_traps", "portal_trap"}),
      ({ "pick", "pick", "south"})
	);
     set_property("random traps","high");
}

void reset(){
  ::reset();  
}

void init() {
  ::init();
  add_action("snap", "snap");
}

int snap(string str) {
  object ob;
  object other;
  
  if(str != "twice") return 0;
  if( (string)TP->query_name() != "rufus" && 
      (string)TP->query_name() != "stefano" && !avatarp(TP) )
     return 0;
  other = find_object_or_load("/d/player_houses/rufus/hall");
  if(!query_locked("iron door")) {
    tell_room(TO,
      TP->query_cap_name()+" snaps "+TP->query_possessive()+
	  " fingers twice and you hear a bolt crash home!",
      ({ TP }));
    tell_room(other,
      "You hear a bolt crash home on the iron door!",
      ({ TP }));
    write("You snap your fingers twice and the iron door locks itself with a crash!");
    TO->set_open("iron door",0);
    TO->set_locked("iron door",1,"lock");
    TO->set_locked("iron door",1,"sigil lock");
    TO->set_locked("iron door",1,"vault lock");
    other->set_open("iron door",0);
    other->set_locked("iron door",1);
	return 1;
  } 
  tell_room(TO,
    TP->query_cap_name()+" snaps "+TP->query_possessive()+
	" fingers twice and you hear a bolt creak as the iron door unlocks itself!",
    ({ TP }));
    tell_room(other,
      "You hear a mechanism creak as the iron door unlocks!",
      ({ TP }));
  write("You snap your fingers twice and the iron door unlocks itself!");
  TO->set_locked("iron door",0,"lock");
  TO->set_locked("iron door",0,"sigil lock");
  TO->set_locked("iron door",0,"vault lock");
  other->set_locked("iron door",0);
//  other->set_locked("iron door",0,"sigil lock");
//  other->set_locked("iron door",0,"vault lock");
  return 1;
}

int lock_traps(string str){
    int poison;
    object me = TP;
    switch(str){
    case "vault lock":
        toggle_trap("iron door","pick","vault lock");
        poison = roll_dice(5,50);
	    TP->add_poisoning(poison);
	    TP->setPoisoner(TO);
	    tell_object(TP,"You feel a sharp prick in your hand as you work the lock.");
	    TP->force_me("emote pulls "+TP->query_possessive()+
	                 " hand back in pain and shakes it slightly.");
	    broadcast_area("/d/player_houses/rufus","%^MAGENTA%^BOLD%^From out of nowhere, you hear a loud gong sound....\n");
        break;
    case "sigil lock":
        toggle_trap("iron door","pick","sigil lock");
        tell_room(TO,"%^GREEN%^BOLD%^A bright green light pulses from the sigil as "+TPQCN+
	                 " tampers with it.\n", TP);
       tell_object(TP,"%^GREEN%^BOLD%^A bright green light pulses from the sigil as you"+
	                 " tamper with it.\n");
       tell_room(TO,"%^BLACK%^BOLD%^Suddenly, the beams of the broken black sunburst in "+
	                 "the center of the sanctuary come to life, slither around "+
	          TP->query_possessive()+" ankles and jerk "+TP->query_objective()+
	                 " to the floor, hard!\n",
	                 TP);
	    tell_object(TP,"%^BLACK%^BOLD%^Suddenly, the beams of the broken black sunburst in "+
	                 "the center of\nthe sanctuary come to life, slithering around "+
	                 "your ankles, and\njerking you down to the ground!\n");
//for some reason the broadcast area doesn't seem to be working Styx 4/5/02
	   broadcast_area("/d/player_houses/rufus", "%^CYAN%^There is a loud crack, "
	     "almost like thunder but more distinct and local nearby.");
	   tell_room("/d/player_houses/rufus/hall", "%^CYAN%^There is a loud crack, "
	     "almost like thunder but more distinct and local nearby.");
	    if(TP->query_stats("dexterity") > random(17)+8) {
		    TP->force_me("emote shakes "+TP->query_possessive()+
		                 " head slowly and moans in pain.");
		    tell_object(TP,"%^YELLOW%^You have fallen hard, but manage to keep yourself "+
		                 "from knocking your head on the floor.\n");
	    }
		else {
		    TP->force_me("emote moans and "+TP->query_possessive()+" eyes "+
		                 "roll up into "+TP->query_possessive()+
		                 " head as "+TP->query_subjective()+" passes out.");
		    tell_object(TP,"%^RED%^BOLD%^The hard fall has caused you to hit your "+
		                 "head on the floor and the world goes %^BLACK%^black"+
		                 "%^RED%^.\n");
			if(!avatarp(TP)) TP->set_unconscious(random(9)+1);
			else write("Luckily, you can't be knocked out for real.");
		}
          tell_object(TP,"%^BOLD%^%^BLACK%^The tangible rays of the "+
             "black sun have wrapped all around your body!");	    
	    TP->set_bound(100);
        break;
    }
    return 1;
}

void portal_trap(){
    tell_object(TP,"Your vision fills with a dim blue light as you pass "+
                   "through the open doorway, but it appears to be completely "+
                   "harmless.");
    TP->move_player("/d/shadow/room/mountain/cave02");
}
