//bedroom.c - Stefano's bedroom.  Coded by Circe 9/20/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("%^BOLD%^%^BLACK%^A very st%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ange bedroom");
        set_short("%^BOLD%^%^BLACK%^A very st%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ange bedroom");
        set_long("%^BOLD%^%^BLACK%^This room %^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^s bigger "+
           "than it would appear from the ou%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^side, and there is "+
           "%^RESET%^%^GREEN%^m%^BOLD%^%^BLACK%^ag%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^c in "+
           "evidence everywhere. Walls, f%^RESET%^RED%^l%^BOLD%^%^BLACK%^oor and ceiling are black "+
           "and the %^BOLD%^%^BLACK%^only ill%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^mination comes from "+
           "thousands of tiny, many%^RESET%^%^CYAN%^-%^BOLD%^%^BLACK%^colored  %^RESET%^%^BLUE%^f"+
           "%^CYAN%^a%^GREEN%^e%^MAGENTA%^r%^RED%^i%^BLUE%^e %^BLUE%^l%^CYAN%^i%^GREEN%^g"+
           "%^MAGENTA%^h%^RED%^t%^BLUE%^s %^BOLD%^%^BLACK%^that surround the room on all "+
           "s%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^des, seeming to expand away from the "+
           "%^BOLD%^%^BLACK%^blackness o%^RESET%^%^MAGENTA%^f%^BOLD%^%^BLACK%^ walls, floor "+
           "and ceiling to give the ill%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^sion of unending "+
           "%^BOLD%^%^BLACK%^space. In the %^RESET%^%^BLUE%^m%^BOLD%^%^BLACK%^iddle of the "+
           "room, the bed consists of a mat%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^ress on a base.  "+
           "%^BOLD%^%^BLACK%^It has no legs, but simply f%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^oats "+
           "10 inches or so from the floor. In the %^BOLD%^%^BLACK%^corner of the "+
           "ro%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^m, a sparkling %^BOLD%^%^CYAN%^crystal "+
           "fountain%^BOLD%^%^BLACK%^ springs from nowh%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^re to "+
           "%^BOLD%^%^BLACK%^provide washing facilitie%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^. The "+
           "cascading dro%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^s of water simply vanish "+
           "%^BOLD%^%^BLACK%^before they h%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^t the floor. A soapdish "+
           "and a pair of thi%^RESET%^%^CYAN%^c%^BOLD%^%^BLACK%^k, warm towels hang "+
           "%^BOLD%^%^BLACK%^suspended in the air on %^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^ither "+
           "side of the fountain. At the north end of %^BOLD%^%^BLACK%^the room, a "+
           "r%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ctangle of the %^RESET%^%^BLUE%^f%^CYAN%^a"+
           "%^GREEN%^e%^MAGENTA%^r%^RED%^i%^BLUE%^e %^BLUE%^l%^CYAN%^i%^GREEN%^g%^MAGENTA%^h"+
           "%^RED%^t%^BLUE%^s %^BOLD%^%^BLACK%^forms the outline of a cupboard %^BOLD%^%^BLACK%^door.  "+
           "A s%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^milar rectangle at the east end of th"+
           "%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^ room indicates the %^BOLD%^%^BLACK%^position of the "+
           "door back %^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^ut onto the landing. A carved, high backed "+
           "%^BOLD%^%^BLACK%^wood%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^n chair sits near the outline of "+
           "the %^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^upboard door."+
           "\n");
        set_smell("default","The air smells of magic and Art.");
        set_listen("default","It is silent and still as the void.");

        set_items(([
           ({"wardrobe","cupboard"}) : "A free standing wardrobe with hanging space for clothes, shelves, rails, "+
              "drawers and a small mirror on the inside of one of the doors.",
           "mirror" : "You are just as beautiful as the last time you checked.",
           "window" : "The window is made of leaded glass that gives a clear view of the gardens beyond.",
           "bed" : "%^BOLD%^%^BLACK%^The sheets and pillowcases are made from black "+
              "sat%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^n and the mattress is firm but comfortable.  "+
              "The base of the bed, which floats free above the floor without support, sways very "+
              "slightly with any movement on top of it, with an effect like a swing suspended in treacle.",
           ({"lights", "faerie lights"})  :"%^BOLD%^%^BLACK%^The tw%^RESET%^"+
              "%^MAGENTA%^i%^BOLD%^%^BLACK%^nkl%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^"+
              "ng motes o%^RESET%^%^GREEN%^f%^BOLD%^%^BLACK%^ light gl%^RESET%^i"+
              "%^BOLD%^%^BLACK%^tter ag%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^inst "+
              "the blackne%^RESET%^%^BLUE%^s%^BOLD%^%^BLACK%^s of t%^RESET%^%^RED%^h"+
              "%^BOLD%^%^BLACK%^e walls, floor and ce%^RESET%^%^CYAN%^i"+
              "%^BOLD%^%^BLACK%^ling of the roo%^RESET%^%^MAGENTA%^m%^BOLD%^"+
              "%^BLACK%^. Althou%^RESET%^%^GREEN%^g%^BOLD%^%^BLACK%^h you can "+
              "%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^ee where th%^RESET%^%^CYAN%^e "+
              "%^BOLD%^%^BLACK%^edges of the r%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^om "+
              "are, the l%^RESET%^i%^BOLD%^%^BLACK%^ghts seem %^RESET%^%^BLUE%^t"+
              "%^BOLD%^%^BLACK%^o disapp%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^ar away "+
              "into %^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n endles%^RESET%^%^CYAN%^s"+
              "%^BOLD%^%^BLACK%^ space populat%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^d "+
              "by thousands of %^RESET%^%^BLUE%^c%^CYAN%^o%^MAGENTA%^l%^RED%^o%^ORANGE%^u"+
              "%^RESET%^r%^ORANGE%^e%^RED%^d%^MAGENTA%^ s%^CYAN%^t%^BLUE%^a%^CYAN%^r"+
              "%^MAGENTA%^s%^BOLD%^%^BLACK%^. This effect %^RESET%^%^ORANGE%^i%^BOLD%^"+
              "%^BLACK%^s enhanc%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^d by some of "+
              "%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^he lights wh%^RESET%^%^MAGENTA%^i"+
              "%^BOLD%^%^BLACK%^ch float free w%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^thin "+
              "the r%^RESET%^o%^BOLD%^%^BLACK%^om itself.",
          ({"walls","floor","ceiling"}) : "%^BOLD%^%^BLACK%^The walls, floor and ceiling are a "+
             "little hard to make out with the peculiar effect of the %^RESET%^%^BLUE%^f%^CYAN%^a"+
             "%^GREEN%^e%^MAGENTA%^r%^RED%^i%^BLUE%^e %^BLUE%^l%^CYAN%^i%^GREEN%^g%^MAGENTA%^h"+
             "%^RED%^t%^BLUE%^s %^BOLD%^%^BLACK%^that seem to live within them or even beyond them.",
          "fountain" : "%^BOLD%^%^BLACK%^The water of the %^BOLD%^%^CYAN%^crystal "+
             "fountain%^BOLD%^%^BLACK%^ springs out of nothingness about three feet "+
             "above the floor and rises to a height of five feet or so before arching "+
             "gracefully over in all directions and %^BOLD%^%^BLUE%^c%^CYAN%^as"+
             "%^WHITE%^c%^CYAN%^ad%^BLUE%^ing %^BLACK%^back down towards the floor.  "+
             "About four inches above the level of the floor, the water simply "+
             "disappears again. The water is pleasantly warm, and the soapdish "+
             "and towels hanging, seemingly in thin air, either side of the "+
             "%^BOLD%^%^BLUE%^fountain%^BOLD%^%^BLACK%^ give an indication of its purpose.%^RESET%^",
          ({"soapdish","soap","soap dish","dish"}) : "The soap dish is slender, with a silver finish, "+
             "and holds a bar of ivory coloured soap.",
          ({"towel","towels"}) : "%^BOLD%^%^WHITE%^The towels are thick, warm, white, fluffy and inviting.",
        ]));
        set_exits(([
           "out" : SHOUSE"landing"
    ]));
        set_door("bedroom door",SHOUSE"landing","out",0);
        set_door_description("bedroom door", "A solid oak door.");
        set_search("bed","A thorough search over, under and around the bed fails "+
           "to reveal any means by which it is supported. You do find a small "+
           "drawer in the base of the bed with a chamber pot in it, however.  "+
           "At least, when the drawer is all the way open, there is a chamber "+
           "pot in it.  When you close it again, however, you could almost swear "+
           "the chamber pot winks out of existence before the drawer is fully closed.");
}

void init(){
   ::init();
   add_action("wash","wash");
   add_action("use_towel","use");
   add_action("use_towel","take");
}

int wash(string str){
   if(str != "fountain" && str != "in fountain" && str != "in the fountain"){
      tell_object(TP,"You might want to wash in the fountain.");
      return 1;
   }
   else{
      tell_object(TP,"Taking the soap from the small silver dish floating in the air, "+
         "you wash carefully in the warm water of the fountain. The soap is of the highest "+
         "quality and the lather rich, soft and creamy.");
      tell_room(ETP,""+TPQCN+" washes in the strange fountain.",TP);
      return 1;
   }
}

int use_towel(string str){
   if(str != "towel" && str != "towels"){
      tell_object(TP,"What are you trying to use?");
      return 1;
   }
   else{
      tell_object(TP,"As you reach towards the towels, both lift easily from "+
         "where they hang in the air and wrap themselves softly around you, "+
         "warming and drying you all at once. Once you are done drying, the towels "+
         "simply re-hang themselves in the air.");
      tell_room(ETP,"As "+TPQCN+" reaches for the towels, both lift to the air and "+
         "wrap themselves around "+TP->query_objective()+"!  Afterward, they drift "+
         "quickly back to their spots and grow still.",TP);
      return 1;
   }
}

/*(invisible) There is an unseen guardian here.
The unseen guardian will stand in protection of Stefano any time he is in here. He will otherwise not ever attack, but will attempt to get to the Laboratory in the tower and record the name of anyone entering the bedroom when Stefano is not here. He will also respond to Raphaels cries if he is attacked, - From Stefano's notes.  The guardian may be added later.
*/