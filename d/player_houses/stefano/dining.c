//dining_room.c - Stefano's dining room.  Coded by Circe 9/20/03
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
        set_name("Dining Room");
        set_short("Dining Room");
        set_long("A long rosewood table takes pride of place in this room. Matching "+
           "chairs are drawn up at each of the place settings. The walls are panelled "+
           "in red oak and a number of tasteful paintings are hung about as decoration.  "+
           "Above the table is a %^BOLD%^%^WHITE%^crystal chandelier%^RESET%^, its facets "+
           "glittering brightly and showering the table in light."+
           "\n");
        set_smell("default","The warm smells of cooked food linger here");
        set_listen("default","The panelled walls deaden most of the sounds from outside");
        set_items(([
            ({"setting","settings"}) : "Each place is set with a bewildering array of "+
               "highly polished %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lverware%^RESET%^.  "+
               "There are also elegant %^ORANGE%^wine glasses%^RESET%^ and carefully folded "+
               "%^GREEN%^soft linen napkins.%^RESET%^",
            ({"chair", "chairs"}) : "The chairs are formal, high backed dining chairs. They are "+
               "padded with %^GREEN%^green leather%^RESET%^ on the seats and on the backs and "+
               "look comfortable despite the formality.",
           "table" : "The top of the table is varnished, the wood throwing back the glittering "+
               "lights of the %^BOLD%^%^WHITE%^chandelier%^RESET%^. The place settings are precisely "+
               "laid out, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lverware%^RESET%^ gleaming brightly.", 
           "chandelier" : "The %^BOLD%^%^WHITE%^crystal chandelier %^BOLD%^%^WHITE%^s%^RESET%^p"+
               "%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^k%^RESET%^l%^BOLD%^%^WHITE%^e%^RESET%^s "+
               "with reflected lights, making a dazzing display and lighting the whole room at the "+
               "same time. Strangely, there is no apparent source for the light - no matter how closely "+
               "you search among the glittering facets of crystal, all the shining lights you see appear "+
               "to be reflections and refractions.",
           "paintings" : "There are four large, %^BOLD%^%^YELLOW%^gold framed%^RESET%^ oil "+
               "paintings hanging on the walls as decoration.",
           "painting 1" : "%^BOLD%^%^GREEN%^A landscape scene of a %^RESET%^squat grey "+
               "tower%^BOLD%^%^GREEN%^ standing in amongst beautiful, exotic gardens in "+
               "front of a %^BOLD%^%^CYAN%^crystal blue stream%^RESET%^.",
           "painting 2" : "A painting of the city of Shadow from an apparently impossible "+
               "aerial viewpoint.  The blunted diamond shape of the city is clear to see, "+
               "and the streets appear to be teeming with people and bustling with "+
               "commercial activity.  A small pair of scales sits in the bottom left "+
               "hand corner, above the legend, 'Per Justicum Ordinare'.",
           "painting 3" : "A portrait of a male human who appears to be in his early "+
               "thirties, sitting in front of a workbench covered with a miscellany of "+
               "magical paraphernalia.  A pair of bright, unblinking hazel eyes peer "+
               "out from under his somewhat unkempt fringe of black hair.  The rest "+
               "of his features are well proportioned and symmetrical.  His skin "+
               "is clear, if a little pale.  He has high cheekbones and there is "+
               "something almost noble about the fine line of his jaw, but his face "+
               "looks somewhat drawn and tired.  The lines of his face speak of "+
               "experiences beyond his years. There is a faint scar on his chin.",
           "painting 4" : "A painting of a tall, willowy half-elf with her back "+
               "turned.  She is cradling something in her arms.  This picure is "+
               "very dark and faded, with most of the detail obscured.  There are "+
               "some scorch marks around the frame."
        ]));
        set_exits(([
           "out" : SHOUSE"cottagemain",
   ]));
        set_door("door",SHOUSE"cottagemain","out",0);
        set_door_description("door", "A simple wooden door.");

}

void init() {
   ::init();
   add_action("sit","sit");
}

int sit(string str){
   if(str != "chair" && str != "table"){
      tell_object(TP,"You might want to sit in a chair or at the table.");
      return 1;
   }
   else{
      tell_object(TP,"You draw up a chair at the dining table.");
      tell_room(ETP,""+TPQCN+" draws up a chair and takes a place at the table.",TP);
      TP->force_me("pose sitting at the dining table");
      return 1;
   }
}
