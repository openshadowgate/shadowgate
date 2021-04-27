//bathhouse.c - Stefano proves to be a lady's man.  Coded by Circe 9/20/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",3);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("A steamy bath house");
        set_short("A steamy bath house");
        set_long("The inside of the bath house is brightly lit, and "+
           "clad in %^BOLD%^%^WHITE%^brilliant white m%^BOLD%^%^BLACK%^a"+
           "%^RESET%^r%^BOLD%^%^WHITE%^ble%^RESET%^, polished to a fine "+
           "finish.  Four small %^BLUE%^warm water fountains%^RESET%^ give "+
           "bathers the opportunity to clean themselves with the pine-scented "+
           "soap provided before climbing into the %^BOLD%^%^WHITE%^large "+
           "%^BOLD%^%^BLUE%^sunken %^BOLD%^%^WHITE%^bath%^RESET%^ which takes "+
           "prominence in the center of the room.  The %^BOLD%^%^RED%^heat%^RESET%^ "+
           "of the water is controlled by a discreet%^BOLD%^%^YELLOW%^ brass "+
           "lever%^RESET%^ at the eastern side of the room.  Usually it is "+
           "very hot, and the %^BOLD%^%^WHITE%^steam %^RESET%^swirls in thick "+
           "eddies through the room.  %^BOLD%^%^GREEN%^Exotic plants%^RESET%^ "+
           "adorn the walls of the room in a curious star pattern, and a small "+
           "raised platform in the centre of the bath contains a further display "+
           "of %^BOLD%^%^BLUE%^br%^BOLD%^%^CYAN%^ig%^BOLD%^%^YELLOW%^ht"+
           "%^BOLD%^%^WHITE%^l%^BOLD%^%^MAGENTA%^y c%^BOLD%^%^WHITE%^o"+
           "%^BOLD%^%^YELLOW%^lo%^BOLD%^%^CYAN%^ur%^BOLD%^%^BLUE%^ed "+
           "%^RESET%^flowers.  At the far end of the room, a refreshing "+
           "%^BOLD%^%^CYAN%^waterfall%^RESET%^ of %^BOLD%^%^BLUE%^warm water%^RESET%^ "+
           "spills from the ceiling allowing bathers a final rinse before drying.  "+
           "Sluices down the sides of the room carry the water away and outside.  "+
           "A comfortable, %^BOLD%^%^BLACK%^padded couch%^RESET%^ is positioned "+
           "near the shower, with a rack of fragrant %^YELLOW%^massage oils%^RESET%^ "+
           "alongside.  Soft, %^BOLD%^%^WHITE%^clean white towels%^RESET%^ are "+
           "available in ample supply.\n");
        set_smell("default","A variety of acrid, pungent smells assualt your nostrils.");
        set_listen("default","You can hear a quiet sound of wood sliding over stone.");
        set_items(([
           ({"fountain","fountains"}) : "The fountains spring up from four separate "+
              "holes in the floor, and each rises to a height of just three feet or so.  "+
              "A low stool is positioned by each fountain, and you could sit on one while "+
              "you wash in the fountain.",
		"handle" : "The cupboard at the end of the workbench has a round "+
              "%^BOLD%^%^YELLOW%^brass handle%^RESET%^ on the door, somewhat different to all "+
              "the other cupboards in the room.",
		"bath" : "The bath is a large, softly curving shape, not quite a rectangle and "+
              "not quite an oval, but something in between that is quite aesthetic and pleasing "+
              "to the eye. The water is clean and clear, and ranges in depth between about three "+
              "and five feet. The raised platform in the middle holds fragrant, exotic blooms.  "+
              "There is a set of steep steps you can descend to get into the bath.",
		"lever" : "The simple brass lever is positioned to allow you to adjust the "+
              "temperature of the bath from inside or from out.",
		({"plants","flowers"}) : "The various exotic plants all have a %^BOLD%^%^GREEN%^lush%^RESET%^, "+
              "%^GREEN%^green thick-leaved%^RESET%^ look to them, and the flowers burst into "+
              "the room in bold shades of %^BOLD%^%^WHITE%^white%^RESET%^, "+
              "%^BOLD%^%^MAGENTA%^magenta%^RESET%^ and %^BOLD%^%^CYAN%^blue%^RESET%^. They have "+
              "been arranged in hanging baskets around the room, in a curious seven pointed star shape.",
		"platform" : "The raised platform in the middle of the bath is adorned with "+
              "even more of the %^GREEN%^lush exotic plants%^RESET%^. They all look well tended "+
              "and cared for, and the colours are %^BOLD%^%^BLUE%^sp%^BOLD%^%^CYAN%^ec"+
              "%^BOLD%^%^YELLOW%^t%^BOLD%^%^MAGENTA%^a%^BOLD%^%^YELLOW%^c%^BOLD%^%^CYAN%^ul"+
              "%^BOLD%^BLUE%^ar%^RESET%^.",
		"waterfall" : "Warm water spills continuously from an opening about ten feet up "+
              "in the wall, gathers in a small depression in the floor, and then runs away down "+
              "one of the sluices at the side of the room. It looks perfect to rinse in after your bath.",
            "couch" : "A comfortable, %^BOLD%^%^BLACK%^black leather massage couch%^RESET%^, "+
              "with a %^BOLD%^%^WHITE%^soft white towel%^RESET%^ thrown over the top.",
		({"rack","racks","oil","oils"}) : "The small bottles of fragrant "+
              "oils are clearly labelled.  While they would be "+
              "tricky to apply to yourself, you could easily use:\n"+
              "\n"+
              "            %^MAGENTA%^Jasmine%^RESET%^\n"+
              "            %^YELLOW%^Saffron%^RESET%^\n"+
              "            %^BOLD%^%^WHITE%^White musk%^RESET%^\n"+
              "            %^YELLOW%^Sandalwood%^RESET%^\n"+
              "            %^GREEN%^Sage%^RESET%^\n"+
              "            or %^BOLD%^%^RED%^Orange Blossom%^RESET%^\n"+
              "\n"+
              "on another person if you wish.",
        ]));
        set_exits(([
           "out" : SHOUSE"garden2"
   ]));
  	  set_door("building door",SHOUSE"garden2","out",0);
        set_door_description("building door", "A squared stone door. You can see some of the steam from the bath seeping out through the cracks.");
}

void init(){
   ::init();
   add_action("wash","wash");
   add_action("enter","enter");
   add_action("leave","leave");
   add_action("turn","turn");
   add_action("rinse","rinse");
   add_action("oil","oil");
}

int wash(string str){
string long;
   if(str != "in fountain" && str != "in the fountain"){
      tell_object(TP,"You can either wash in the fountain or enter the bath.");
      return 1;
   }
   else{
      tell_object(TP,"Sitting on the low stool, you take up a bar of the pine scented "+
         "soap and lather each of your limbs and torso in turn with the rich, creamy suds, "+
         "rinsing off in the fountain. At the end of it, you feel much refreshed (and "+
         "probably smell better than you did before).");
      tell_room(ETP,""+TPQCN+" sits on a low stool and bathes "+TP->query_possessive()+" arms "+
         "and torso with rich lather.",TP);
      long = TP->query_long();
      TP->set("long",capitalize(nominative(TP))+" has a pleasant, pine-scented fragrance.");
      return 1;
   }
}

int enter(string str){
   if(str != "bath") {
      tell_object(TP,"How do you think you're going to enter that?  Try the bath.");
      return 1;
   }
   else{
      tell_object(TP,"You climb carefully down the steps into the hot bath. It's a "+
        "bit of a shock at first, but soon the heat of the water works its way through "+
        "you, relaxing tired limbs and unknotting weary muscles.  The whole experience "+
        "is one of pure, unadorned luxury.");
      tell_room(ETP,""+TPQCN+" descends the steps into the bath.",TP);
      return 1;
   }
}

int leave(string str){
   if(str != "bath"){
      tell_object(TP,"Where are you trying to go?  You could try leaving the bath.");
      return 1;
   }
   else{
      tell_object(TP,"You pull your way out of the bath feeling relaxed and radiant, "+
         "your skin still glowing from the heat. A final rinse would be perfect to close "+
         "the pores of your skin and set you on your way.");
      tell_room(ETP,""+TPQCN+" slowly climbs the steps and leaves the bath.",TP);
      return 1;
   }
}

int turn(string str){
   if(!str){
      tell_object(TP,"Turn it hot or cold?");
      return 1;
   }
   if(str == "hot"){
      tell_object(TP,"You turn the lever, and the temperature of the bath slowly rises.");
      tell_room(ETP,""+TPQCN+" turns the lever, and steam begins to rise from the bath.",TP);
      return 1;
   }
   if(str == "cold"){
      tell_object(TP,"You turn the lever, and the temperature of the bath slowly drops.");
      tell_room(ETP,""+TPQCN+" turns the lever, and the bath seems to grow cooler.",TP);
      return 1;
   }
   else{
      tell_object(TP,"You can't turn that!");
      return 1;
   }
}

int rinse(string str) {
   if(str != "in waterfall" && str != "under waterfall"){
      tell_object(TP,"You can't rinse there.  Maybe you meant the waterfall?");
      return 1;
   }
   else{
      tell_object(TP,"The %^CYAN%^warm water%^RESET%^ cascades down around you, "+
         "refreshing and invigorating your whole body. It feels as if the beating "+
         "flow is massaging your neck and shoulders, and every last trace of dirt, "+
         "sweat or soap is simply washed away.");
      tell_room(ETP,""+TPQCN+" steps under the waterfall and rinses.",TP);
      return 1;
   }
}

int oil(string str) {
   string name,which,long;
   object who;
   if(!str){
      tell_object(TP,"Try oil <person> with <type>.");
      return 1;
   }
   if(sscanf(str, "%s with %s", name, which) != 2){
      tell_object(TP,"Try oil <person> with <type>.");
      return 1;
   }
      if(!present(TP->realName(name))) {
         tell_object(TP, capitalize(name)+" does not seem to be here.");
         return 1;
      }
      who = find_player(TP->realName(name));
      if(!objectp(who)) { 
         tell_object(TP, capitalize(name)+" does not seem to be here.");
         return 1;
      };
      switch(which){
         case "jasmine": tell_object(TP,"Slipping the cork from the bottle, you apply "+
                          "a little of the fragranced oil onto your hands and begin to gently "+
                          "apply it to "+who->query_cap_name()+"'s skin.");
                          tell_object(who,""+TPQCN+" applies a little oil to "+TP->query_possessive()+" "+
                          "hands and begins to rub it gently into your skin. A soft "+
                          "%^MAGENTA%^jasmine aroma%^RESET%^ reaches you as the warm oil begins its "+
                          "relaxing, tonifying work.");
                          tell_room(ETP,""+TPQCN+" uncorks a bottle and applies oil "+
                          "to "+who->query_cap_name()+".",({TP,who}));
                          long = who->query_long();
                          who->set("long",capitalize(nominative(who))+" is wearing "+
                             "%^MAGENTA%^an enticing jasmine fragrance%^RESET%^.");
                          break;
         case "saffron": tell_object(TP,"Slipping the cork from the bottle, you apply a little "+
                         "of the fragranced oil onto your hands and begin to gently apply it "+
                         "to "+who->query_cap_name()+"'s skin.");
                          tell_object(who,""+TPQCN+" applies a little oil to "+TP->query_possessive()+" "+
                          "hands and begins to rub it gently into your skin. An exotic "+
                          "%^YELLOW%^saffron fragrance%^RESET%^ reaches you as the warm oil begins its "+
                          "relaxing, tonifying work.");
                          tell_room(ETP,""+TPQCN+" uncorks a bottle and applies oil "+
                          "to "+who->query_cap_name()+".",({TP,who}));
                          long = who->query_long();
                          who->set("long",capitalize(nominative(who))+" is wearing "+
                             "%^YELLOW%^an exotic aroma of saffron%^RESET%^.");
                          break;
         case "musk": tell_object(TP,"Slipping the cork from the bottle, you apply a little "+
                         "of the fragranced oil onto your hands and begin to gently apply it "+
                         "to "+who->query_cap_name()+"'s skin.");
                          tell_object(who,""+TPQCN+" applies a little oil to "+TP->query_possessive()+" "+
                          "hands and begins to rub it gently into your skin. A heady, sensual aroma of "+
                          "%^BOLD%^%^WHITE%^white musk%^RESET%^ reaches you as the warm oil begins its "+
                          "relaxing, tonifying work.");
                          tell_room(ETP,""+TPQCN+" uncorks a bottle and applies oil "+
                          "to "+who->query_cap_name()+".",({TP,who}));
                          long = who->query_long();
                          who->set("long",capitalize(nominative(who))+" is wearing "+
                             "%^BOLD%^%^WHITE%^a heady, sensual aroma of white musk%^RESET%^.");
                          break;
         case "sandalwood": tell_object(TP,"Slipping the cork from the bottle, you apply a little "+
                         "of the fragranced oil onto your hands and begin to gently apply it "+
                         "to "+who->query_cap_name()+"'s skin.");
                          tell_object(who,""+TPQCN+" applies a little oil to "+TP->query_possessive()+" "+
                          "hands and begins to rub it gently into your skin. A warm fragrance of "+
                          "%^YELLOW%^sandalwood%^RESET%^ reaches you as the warm oil begins its "+
                          "relaxing, tonifying work.");
                          tell_room(ETP,""+TPQCN+" uncorks a bottle and applies oil "+
                          "to "+who->query_cap_name()+".",({TP,who}));
                          long = who->query_long();
                          who->set("long",capitalize(nominative(who))+" is wearing "+
                             "%^YELLOW%^a warm aroma of sandalwood%^RESET%^.");
                          break;
         case "sage": tell_object(TP,"Slipping the cork from the bottle, you apply a little "+
                         "of the fragranced oil onto your hands and begin to gently apply it "+
                         "to "+who->query_cap_name()+"'s skin.");
                          tell_object(who,""+TPQCN+" applies a little oil to "+TP->query_possessive()+" "+
                          "hands and begins to rub it gently into your skin. A clean-smelling "+
                          "%^GREEN%^aroma of sage%^RESET%^ reaches you as the warm oil begins its "+
                          "relaxing, tonifying work.");
                          tell_room(ETP,""+TPQCN+" uncorks a bottle and applies oil "+
                          "to "+who->query_cap_name()+".",({TP,who}));
                          long = who->query_long();
                          who->set("long",capitalize(nominative(who))+" is wearing "+
                             "%^YELLOW%^a clean smelling aroma of sage%^RESET%^.");
                          break;
         case "orange": tell_object(TP,"Slipping the cork from the bottle, you apply a little "+
                         "of the fragranced oil onto your hands and begin to gently apply it "+
                         "to "+who->query_cap_name()+"'s skin.");
                          tell_object(who,""+TPQCN+" applies a little oil to "+TP->query_possessive()+" "+
                          "hands and begins to rub it gently into your skin. A citrus tang of "+
                          "%^BOLD%^%^RED%^orange blossom%^RESET%^ reaches you as the warm oil begins its "+
                          "relaxing, tonifying work.");
                          tell_room(ETP,""+TPQCN+" uncorks a bottle and applies oil "+
                          "to "+who->query_cap_name()+".",({TP,who}));
                          long = who->query_long();
                          who->set("long",capitalize(nominative(who))+" is wearing "+
                             "%^BOLD%^%^RED%^a tangy sent of orange blossom%^RESET%^.");
                          break;
      }
     return 1;
}