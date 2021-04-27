//tower_lounge.c - Entry point for Stefano's tower.  Coded by Circe 9/27/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;
int uses;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A formal lounge");
        set_short("A formal lounge");
        set_long("%^MAGENTA%^You are in a square room near the top of the tower.  "+
           "A %^GREEN%^deep green carpet%^MAGENTA%^ covers most of the floor, and the "+
           "%^RESET%^grey stone walls%^MAGENTA%^ are lined with shelves of books.  There "+
           "are several comfortable chairs, and a small reading table. A couple of "+
           "arrowslits let in a little light and breeze, but there are also hidden "+
           "%^BOLD%^%^YELLOW%^upli%^BOLD%^%^WHITE%^gh%^BOLD%^%^YELLOW%^ters%^RESET%^%^MAGENTA%^ "+
           "positioned behind the bookshelves, and the room is kept at a comfortable "+
           "temperature by means unseen. A stairwell leading down to the lower levels of "+
           "the tower is covered by a %^RESET%^heavy stone slab%^MAGENTA%^. Beside this is "+
           "a small drinks bar, attended by a smartly dressed halfling butler."+
           "\n");
        set_smell("default","The room is pleasantly scented with the smell of fresh pine.");
        set_listen("default","It is quiet.");
        set_items(([
            ({"arrowslit", "arrowslits"}) : "The narrow opening fans outward through the "+
               "thick stone wall to make a roomy niche from which it would be possible to "+
               "fire arrows or spells in a wide arc without exposing oneself to return fire.  "+
               "Looking outwards, you can gaze past the stream at the back of the tower to the "+
               "mountains beyond. You can also see a country cottage nearby.", 
           "stairwell" : "The heavy stone slab over the stairwell has an iron ring in it "+
               "that could be used to lift it... but it looks very heavy.", 
		"books" : "The books here are relatively few in number, but appear to have "+
               "been selected for quality. All deal with magic and the mysteries of the Weave.  "+
               "There is a copy of %^BOLD%^%^CYAN%^Elminster's Arcana Fabulosum%^RESET%^, "+
               "and one of %^BOLD%^%^BLACK%^Webster's D%^RESET%^%^RED%^em%^BOLD%^%^RED%^o"+
               "%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^log%^BOLD%^%^BLACK%^i"+
               "%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^a%^RESET%^. They are neatly ordered, and "+
               "the shelves are clean. The books themselves have the look of regular, but careful use.",
		"carpet" : "The carpet is a %^GREEN%^rich deep green%^RESET%^ in colour, and "+
               "plush and comfortable to walk on. There is a noticeable absence of trodden-in "+
               "mud and dirt, even round the doorway.",
		"table" : "A low, round polished wood table with three legs. It looks suitable "+
               "for resting books or drinks on while studying. At the moment, the only thing "+
               "on it is a bowl of %^ORANGE%^pine scented woodchips%^RESET%^ keeping the room "+
               "pleasantly fragranced.",
            "slab" : "The heavy stone slab over the stairwell has an iron "+
               "ring in it that could be used to lift it... but it looks very heavy."
        ]));
        set_exits(([
           "out" : SHOUSE"ledge",
   ]));
        set_door("door",SHOUSE"ledge","out",0);
        set_door_description("door", "A simple stone door, opening to the outside of the tower");
      set_search("default","A strange protrusion under the table catches your eye.");
      set_search("table","Concealed under the table is a small button that looks like it could be pressed.");
   uses = random(5)+6;
}

void reset(){
   ::reset();
   if(!present("periot")){
      new(MON"stef_periot")->move(TO);
   }
}

void init(){
   ::init();
   add_action("ask","ask");
   add_action("order","order");
   add_action("sit","sit");
   add_action("lift","lift");
   add_action("press","press");
   add_action("close_em","close");
}

int ask(string str){
   if(!present("periot")){
      tell_object(TP,"The butler does not seem to be here.");
      return 1;
   }
   if(str != "periot" && str != "drinks" && str != "Periot" && str != "halfling" && str != "butler"){
      tell_object(TP,"Try asking the butler what he'll serve you.");
   return 1;
   }
   tell_object(TP,"Periot shows you an ivory card engraved with the drink choices.  You may order:\n"+
      "       %^YELLOW%^Old Deku Brandy%^RESET%^\n"+
      "       %^GREEN%^Sorcerer's Brew%^RESET%^\n"+
      "       %^YELLOW%^Conjuror's Concoction%^RESET%^\n"+
      "       Glass of %^BOLD%^%^CYAN%^pure water%^RESET%^");
   tell_room(ETP,""+TPQCN+" examines the card carried by Periot.",TP);
   return 1;
}

int order(string str){
   string mname=TP->query_name();
   if(!present("periot")){
      tell_object(TP,"The butler does not seem to be here.");
      return 1;
   }
   if(!str){
      tell_object(TP,"Periot looks pained that he does not know what drink to serve you.");
      return 1;
   }
//   if((wizardp(TP)) || (mname == "stefano")){
   if(avatarp(TP) || member_array(mname,PGUESTS) != -1 || member_array(mname,POWNERS) != -1){
      if(uses == 0){
         tell_object(TP,"Periot shame-facedly admits that you are out of drinks.");
         tell_room(ETP,"Periot looks quite embarrassed as he whispers something to "+TPQCN+".",TP);
         return 1;
      }
      if(str == "brandy" || str == "deku brandy" || str == "Old Deku Brandy" || str == "old deku brandy"){
         tell_object(TP,"Periot nods discreetly to you in acknowledgement, pours your Old Deku Brandy, "+
            "then brings it over to you on a silver tray.");
         tell_room(ETP,"Periot nods discreetly to "+TPQCN+" and brings "+TP->query_objective()+" "+
            "a drink on a silver tray.",TP);
         new(OBJ"stef_brandy")->move(TO);
         TP->force_me("get drink");
         uses = uses - 1;
         return 1;
      }
      if(str == "sorcerer's brew" || str == "brew" || str == "Sorcerer's brew"){
         tell_object(TP,"Periot nods discreetly to you in acknowledgement, pours your Sorcerer's brew, "+
            "then brings it over to you on a silver tray.");
         tell_room(ETP,"Periot nods discreetly to "+TPQCN+" and brings "+TP->query_objective()+" "+
            "a drink on a silver tray.",TP);
         new(OBJ"stef_sorcerer")->move(TO);
         TP->force_me("get drink");
         uses = uses - 1;
         return 1;
      }
      if(str == "conjuror's concoction" || str == "concoction" || str == "Conjuror's concoction"){
         tell_object(TP,"Periot nods discreetly to you in acknowledgement, pours your Conjuror's concoction, "+
            "then brings it over to you on a silver tray.");
         tell_room(ETP,"Periot nods discreetly to "+TPQCN+" and brings "+TP->query_objective()+" "+
            "a drink on a silver tray.",TP);
         new(OBJ"stef_conjuror")->move(TO);
         TP->force_me("get drink");
         uses = uses - 1;
         return 1;
      }
      if(str == "water" || str == "glass of water" || str == "pure water"){
         tell_object(TP,"Periot nods discreetly to you in acknowledgement, pours your glass of water, "+
            "then brings it over to you on a silver tray.");
         tell_room(ETP,"Periot nods discreetly to "+TPQCN+" and brings "+TP->query_objective()+" "+
            "a drink on a silver tray.",TP);
         new(OBJ"stef_water")->move(TO);
         TP->force_me("get drink");
         uses = uses - 1;
         return 1;
      }
   }
   tell_object(TP,"The butler refuses to take orders from anyone but his master's guests.");
   return 1;
}

int sit(string str){
   if(str != "chair"){
      tell_object(TP,"Where would you like to sit?  A chair, maybe?");
      return 1;
   }
   tell_object(TP,"You ease yourself into one of the padded armchairs and notice "+
      "that, while comfortable, this chair has been designed to support you in an "+
      "upright posture which discourages any drowziness or lack of attention.");
   tell_room(ETP,""+TPQCN+" takes a seat in one of the padded armchairs.",TP);
   TP->force_me("pose seated in a padded armchair");
   return 1;
}

int lift(string str){
   if(str != "slab"){
      tell_object(TP,"What are you trying to lift?");
      return 1;
   }
   tell_object(TP,"You grasp the iron ring and heave, but damn this thing is heavy.");
   tell_room(ETP,""+TPQCN+"'s face turns red as "+TP->query_subjective()+" pulls on "+
      "the iron ring, but the slab does not move.",TP);
   return 1;
}

int press(string str){
   if(str != "button"){
      tell_object(TP,"Why would you want to press that?");
      return 1;
   }
   if(member_array("stairway",ETP->query_exits()) != -1) {
      tell_object(TP,"You press the button, and the slab in the wall slides shut, hiding the stairway.");
   tell_room(ETP,""+TPQCN+" reaches beneath the table and the stone slab slides shut, "+
      "hiding the stairway.",TP);
   remove_item("stairway");
   remove_exit("stairway");
   add_item("slab","The heavy stone slab over the stairwell has an iron "+
      "ring in it that could be used to lift it... but it looks very heavy.");
   return 1;
   }
   tell_object(TP,"You press the button, and you hear a small click.  You could probably open the slab.");
   tell_room(ETP,""+TPQCN+" reaches beneath the table and presses a button.",TP);
   add_exit(SHOUSE"lab","stairway");
   set_door("slab",SHOUSE"lab","stairway",0);
   set_door_description("slab", "The massive slab can cover the stairwell leading down into the tower.");
   add_item("stairs","The stone stairs look sturdy and lead down.");
   return 1;
}

int close_em(string str){
   if(!str){
      tell_object(TP,"Close what?");
      return 1;
   }
   if(str == "slab"){
      tell_object(TP,"The slab slides closed, hiding the exit below once again.");
      tell_room(ETP,"The heavy slab closes with a leaden slam behind "+TPQCN+", hiding the stairwell.",TP);
      remove_exit("stairway");
      tell_room("/d/player_houses/stefano/lab","The slab over the stairway swings shut.");
      "/d/player_houses/stefano/lab"->remove_exit("up");
      return 1;
   }
   return 0;
}