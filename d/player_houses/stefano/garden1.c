//garden1.c - First room of Stefano's house - coded by Circe 9/13/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(GRASSLANDS);
        set_travel(FOOT_PATH);
        set_name("A gated garden");
        set_short("A gated garden");
        set_long(
            "%^BOLD%^%^GREEN%^Inside the %^BOLD%^%^BLACK%^black iron fence%^BOLD%^%^GREEN%^, "+
            "the gardens are pleasant and neatly ordered.  The tropical flair of the jungle has "+
            "been brought within the iron fence, and elaborate %^RED%^f%^MAGENTA%^l%^BLUE%^o"+
            "%^CYAN%^w%^GREEN%^e%^YELLOW%^r %^RED%^b%^MAGENTA%^e%^BLUE%^d%^CYAN%^s %^GREEN%^"+
            "are spaced neatly around the lawn with a %^RESET%^%^YELLOW%^gravel path"+
            "%^BOLD%^%^GREEN%^ winding its way between them. A %^RESET%^squat, grey stone tower"+
            "%^BOLD%^%^GREEN%^ stands beside a %^BOLD%^%^CYAN%^lively stream%^BOLD%^%^GREEN%^.  "+
            "At the rear of the tower, a large %^RESET%^%^YELLOW%^wooden wheel%^BOLD%^%^GREEN%^ "+
            "can be seen turning in the %^BOLD%^%^CYAN%^fl%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^w"+
            "%^BOLD%^%^BLUE%^i%^CYAN%^ng %^RESET%^%^CYAN%^w%^BOLD%^%^WHITE%^a%^BOLD%^%^BLUE%^t"+
            "%^RESET%^%^CYAN%^er%^BOLD%^%^GREEN%^. A couple of smaller buildings can be seen off "+
            "to the east, with a %^RESET%^wisp of smoke%^BOLD%^%^GREEN%^ rising from the chimney "+
            "stack of one of them."+
            "\n"
        );
        set_smell("default","You can smell the sweet perfume of the %^BOLD%^%^BLUE%^f%^WHITE%^l%^MAGENTA%^o%^WHITE%^w%^BLUE%^e%^WHITE%^r%^MAGENTA%^s%^RESET%^%^ORANGE%^, and the scent of the %^BOLD%^%^GREEN%^fresh cut grass%^RESET%^.");
        set_listen("default","You can hear the babble of the stream flowing by and the creak of the slowly turning water wheel.");

        set_items(([
           "lawns" : "The lawns are neatly maintained and kept quite short.",
           "fence" : "The twisted %^BOLD%^%^BLACK%^black iron lattice%^RESET%^ has been wrought "+
              "into complex, eye watering patterns. Sometimes there seem to be pictures in it, "+
              "sometimes symbols, but it is hard to focus your eyes and concentrate on any one spot. "+
              "In the gaps between the iron itself, you can see that the air shimmers with a "+
              "%^CYAN%^faint blue haze%^RESET%^. About half way along the fence, you can see a gate.",
           "tower" : "The tower is square, about 30 feet high, and nearly as wide as it is tall. It is "+
              "made from rough stone blocks that have been expertly worked to form solid walls without "+
              "any obvious mortar or other binding. As you step up for a closer look, you feel a slight "+
              "chill as a number of small air currents take up around you. There are a number of narrow "+
              "arrowslits, but none at ground level. The only door is about 20 feet up. There are no steps.",
           "walls" : "The rough stone looks to have been chosen more for strength than aesthetic appeal, "+
              "but the light grey color is not displeasing against the background greens of the "+
              "%^BOLD%^%^GREEN%^pleasant gardens%^RESET%^, and the blue  of the %^BOLD%^%^CYAN%^ "+
              "op%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^n sky%^RESET%^.",
		"ledge" : "A small ledge, about two feet wide sticks out incongruously in the open air "+
              "beneath the door. It has something on it, possibly a doormat.",
	      "doormat" : "You can't see that from here.",
            "door" : "There seems to be a door on a small ledge halfway up the side of the tower.  "+
              "There does not seem to be any ready way up.",
            ({"flowers","flower beds","beds"}) : "The well-maintained flower beds are filled with "+
               "exotic flowers of all types.  %^BOLD%^%^RED%^Bright snapdragons %^RESET%^stand alongside "+
               "%^BOLD%^%^CYAN%^mul%^GREEN%^ti%^YELLOW%^col%^RED%^or%^MAGENTA%^ed %^BLUE%^lil%^WHITE%^ie%^BLUE%^s"+
               "%^RESET%^.  %^BOLD%^%^GREEN%^Birds %^YELLOW%^of %^MAGENTA%^par%^YELLOW%^a%^MAGENTA%^dise "+
               "%^RESET%^stand tall among the other flowers, their bold colors proudly displayed.",
            ({"wheel", "water wheel"}) : "%^ORANGE%^A large wooden water wheel "+
               "turns slowly in the %^BOLD%^%^BLUE%^stream%^RESET%^.",
            "stream" : "The %^BOLD%^%^BLUE%^f%^BOLD%^%^WHITE%^l%^BOLD%^%^BLUE%^owing "+
               "str%^BOLD%^%^CYAN%^ea%^BOLD%^%^BLUE%^m%^RESET%^ bubbles along, its "+
               "%^BOLD%^%^WHITE%^crystal clear water%^RESET%^ glittering in the light.  "+
               "%^BOLD%^%^GREEN%^lush vegetation%^RESET%^ grows on the far bank, "+
               "and the %^ORANGE%^large water wheel%^RESET%^ attached to the tower "+
               "creaks quietly as it turns with the momentum of the water.",
            "buildings" : "There are two more buildings off to the west.  One "+
               "looks like a cozy country cottage. The other is a simple square "+
               "structure whose design gives not hint of its purpose."
        ]));
        set_exits(([
           "west" : SHOUSE"garden2",
//           "gate" : SHOUSE"stefano_entry",
           "gate" : "/d/attaya/tunnels/rooms/stefano_entry"
   ]));
      set_climb_exits(([
         "climb":({SHOUSE"ledge",20,3,100})
      ]));
        set_door("gate",SHOUSE"stefano_entry","east","rune_key");
        set_door_description("gate", "The gate looks solid, and the same subtle twists of iron "+
           "play tricks with your eyes here as in the fence. It is difficult to make out the "+
           "exact shapes contained within the lattice. There is a heavy lock in the gate. From "+
           "this side, though, you can open the gate quite easily.");
        set_search("default","You can't find a way up the tower, unless you can climb or levitate.");
}
void init() {
   ::init();
   add_action("levitate","levitate");
}

int levitate(string str) {
   if(!str){
      if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("psywarrior") || TP->is_class("psion") || TP->query_property("flying")) {
         tell_object(TP,"As you set your mind to the task of lifting your body upwards, "+
            "the air currents eddying around the tower suddenly come together and lift you "+
            "easily to the ledge in front of the door.");
         tell_room(ETP,""+TPQCN+" frowns in concentration and takes a deep breath, then begins "+
            "to rise into the air and lands safely on the ledge in front of the door!",TP);
         TP->move(SHOUSE"ledge");
         TP->force_me("look");
         return 1;
      }
      else{
         tell_object(TP,"Scowling with concentration, you set your mind to try to lift your body, "+
            "and give a little hop to help it get the idea. Sadly, nothing happens and you drop "+
            "back to the floor feeling slightly foolish.");
         tell_room(ETP,""+TPQCN+" scowls deeply and hops a few times with "+TP->query_possessive()+" "+
            "eyes set on the ledge, then stops and glances around with a slight blush.",TP);
         return 1;
      }
   }
   else{
      tell_object(TP,"You can't levitate that!");
      return 1;
   }
}
