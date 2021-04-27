#include <std.h> 
#include "../defs.h" 
inherit VAULT; 

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create(){ 
   ::create(); 
   set_property("light",1); 
   set_property("indoors",1); 
   set_terrain(STONE_BUILDING); 
   set_travel(PAVED_ROAD); 
   set_name("Private Lounge"); 
   set_short("%^RESET%^%^RED%^Private Lounge%^RESET%^"); 
   set_long("%^RESET%^This room is obviously for smaller, more "
"intimate gatherings. Comfortable %^BOLD%^%^WHITE%^chairs%^RESET%^ "
"covered in soft %^BOLD%^%^RED%^c%^RESET%^%^RED%^ri%^BOLD%^%^RED%^"
"ms%^RESET%^%^RED%^o%^BOLD%^%^RED%^n%^RESET%^ suede are placed "
"around the room, along with a %^BOLD%^%^BLACK%^leather sofa"
"%^RESET%^. Small %^BOLD%^%^BLACK%^ebony tables%^RESET%^ are "
"strategically placed so that there is always one an arms length "
"away. A fully-stocked %^RESET%^%^MAGENTA%^bar%^RESET%^ takes up "
"the length of one wall. Oil lamps burn within small alcoves carved "
"into the walls, providing plenty of %^BOLD%^%^WHITE%^light%^RESET%^ "
"to the space. A %^RESET%^%^RED%^fireplace%^RESET%^ also provides "
"some light and warmth. The floor is bare and black. The walls are "
"also black and mostly bare, except for two which have been painted "
"with a massive %^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d "
"d%^BOLD%^%^RED%^r%^RESET%^%^RED%^ag%^BOLD%^%^RED%^o%^RESET%^%^RED%^"
"n%^RESET%^ mural.%^RESET%^");

   set_smell("default","%^RESET%^%^RED%^It smells like liquor, with an "
"underlying scent of blood.%^RESET%^"); 
   set_listen("default","%^RESET%^%^MAGENTA%^Light music drifts in from "
"outside.%^RESET%^"); 

   set_items(([ 
({"chairs"}):"%^RESET%^Plush and soft, the chairs look rather "
"comfortable. They are situated around the room to make conversation "
"simple and pleasant.%^RESET%^",

({"sofa"}):"%^RESET%^While not large, this %^BOLD%^%^BLACK%^black"
"%^RESET%^ leather sectional sofa could comfortably accommodate "
"three people. It looks quite cozy and inviting.%^RESET%^",

({"tables"}):"%^RESET%^Cylindrical end tables are placed around the "
"room so that there is always somewhere to put a drink. They look a "
"lot like logs due to their shape, but they are quite smooth and made "
"from %^BOLD%^%^BLACK%^p%^RESET%^o%^BOLD%^%^BLACK%^lis%^BOLD%^"
"%^WHITE%^h%^RESET%^e%^BOLD%^%^BLACK%^d ebony%^RESET%^. The surface "
"is encircled with a pattern of %^RESET%^%^RED%^c%^BOLD%^%^RED%^r"
"%^RESET%^%^RED%^im%^BOLD%^%^RED%^so%^RESET%^%^RED%^n fl%^BOLD%^"
"%^RED%^a%^RESET%^%^RED%^me%^BOLD%^%^RED%^s%^RESET%^. ",

({"bar"}):"%^RESET%^A couple leather, %^RESET%^%^RED%^red%^RESET%^ "
"chairs line the %^BOLD%^%^BLACK%^ebony%^RESET%^ bar. Painted onto "
"the surface of the bar is a %^BOLD%^%^BLACK%^stormy sky%^RESET%^. "
"The violent, %^BOLD%^%^BLACK%^grey clouds%^RESET%^ are highlighted "
"with %^BOLD%^%^WHITE%^silver light%^RESET%^ from bolts of "
"%^RESET%^lightning%^RESET%^ that streak through the %^BOLD%^%^BLACK%^"
"dark sky%^RESET%^. Glasses neatly hang from racks behind the bar, "
"and a %^BOLD%^%^WHITE%^s%^RESET%^ha%^BOLD%^%^WHITE%^tte%^RESET%^r"
"e%^BOLD%^%^WHITE%^d %^BOLD%^%^BLACK%^m%^BOLD%^%^WHITE%^irr%^BOLD%^"
"%^BLACK%^o%^BOLD%^%^WHITE%^r%^RESET%^ reflects the bottles of "
"%^CYAN%^liquor%^RESET%^ placed on shelves lining the wall. There is "
"no bartender here, so guests are made to get their own drinks."
"%^RESET%^ ",

({"lamps","alcoves"}):"%^RESET%^These are simple %^BOLD%^%^WHITE%^oil "
"lamps%^RESET%^ that burn with a bright light. Small knobs can be "
"turned to brighten or dim the flame, according to the preference of "
"the guests. They sit in small alcoves carved into the %^BOLD%^"
"%^BLACK%^black%^RESET%^ walls.",

({"floor"}):"%^RESET%^It is cold, hard and %^BOLD%^%^BLACK%^black"
"%^RESET%^. There appears to be some c%^BOLD%^%^BLACK%^r%^RESET%^"
"a%^BOLD%^%^BLACK%^ck%^RESET%^s along its surface, as if someone "
"pounded it with a hammer.%^RESET%^",

({"fireplace"}):"%^RESET%^A semi-circle of roughly cut %^RESET%^"
"%^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^by%^RESET%^ and %^RESET%^"
"%^MAGENTA%^a%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^eth%^BOLD%^"
"%^MAGENTA%^ys%^RESET%^%^MAGENTA%^t%^RESET%^ gems line this large "
"fireplace, which takes up the better portion of a wall. A %^BOLD%^"
"%^BLACK%^metal screen%^RESET%^ covers the hearth, and is worked "
"into the design of an %^BOLD%^%^WHITE%^intricate %^BOLD%^%^BLACK%^"
"spider%^BOLD%^%^WHITE%^ web%^RESET%^. An %^BOLD%^%^BLACK%^onyx "
"spider%^RESET%^ waits in the corner with s%^BOLD%^pa%^RESET%^rkli"
"%^BOLD%^n%^RESET%^g %^RESET%^%^RED%^r%^BOLD%^%^RED%^u%^RESET%^"
"%^RED%^by ey%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^RESET%^.",

({"mural"}):"%^RESET%^The %^RESET%^%^RED%^red %^BOLD%^%^BLACK%^"
"silhouette%^RESET%^ of a massive %^RESET%^%^RED%^dragon%^RESET%^ "
"snakes along the length of two walls. The dragons sleek body flares "
"out at twisting angles as if it is consumed by %^RESET%^%^RED%^"
"flames%^RESET%^. %^RESET%^%^RED%^R%^BOLD%^%^RED%^u%^RESET%^%^RED%^"
"b%^BOLD%^%^RED%^y o%^RESET%^%^RED%^r%^BOLD%^%^RED%^b%^RESET%^%^RED%^"
"s%^RESET%^ burn in the eye sockets. Large wings scrape at the "
"ceiling, and massive claws cut toward the floor. Despite its lack "
"of detail, the painting is exquisite.%^RESET%^",

({"liquor"}):"%^RESET%^Bottles of whiskey, vodka, rum and tequila line the "
"shelves. Clean glasses wait to be filled nearby, tempting you to %^BOLD%^pour "
"%^RESET%^a drink.",

({"doorframe","door"}):"%^RESET%^The doorframe encircling the portal northwards "+
"is jagged and brightly painted to look as if %^BOLD%^%^RED%^f%^RESET%^%^RED%^l"+
"%^ORANGE%^a%^MAGENTA%^m%^RED%^e%^BOLD%^s %^RESET%^are licking across its surface.",
   ])); 
    set_exits(([ 
"north":ROOMS"bsb1", 
   ])); 
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

void init() {
   ::init();
   add_action("pour_me","pour");
   add_action("peer_fun","peer");
}

int pour_me(string str) {
   object mydrink;
   if(!str) return 0;
   switch(str) {
     case "tequila":
     mydrink = new("std/drink");
     mydrink->set_name("tequila");
     mydrink->set_short("a shot glass rimmed with salt");
     mydrink->set_long("%^BOLD%^%^WHITE%^This crystal clear %^RESET%^tequila %^BOLD%^%^WHITE%^is served in a %^RESET%^%^RED%^red shot glass %^BOLD%^%^WHITE%^rimmed with salt, and served with a slice of %^YELLOW%^lemon%^WHITE%^.%^RESET%^");
     mydrink->set_strength(35);
     mydrink->set_id( ({ "tequila", "drink" }) );
     break;

     case "whiskey":
     mydrink = new("std/drink");
     mydrink->set_name("whiskey");
     mydrink->set_short("a shot of golden liquid");
     mydrink->set_long("%^BOLD%^%^WHITE%^Served in a %^RESET%^%^RED%^red shot glass%^BOLD%^%^WHITE%^, the 18-year whiskey is a deep, %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n %^WHITE%^hue, and it smells quite strong.%^RESET%^");
     mydrink->set_strength(30);
     mydrink->set_id( ({ "whiskey", "drink" }) );
     break;

     case "rum":
     mydrink = new("std/drink");
     mydrink->set_name("rum");
     mydrink->set_short("a shot of amber liquid");
     mydrink->set_long("%^BOLD%^%^WHITE%^This shot of rum is a deep, dark %^YELLOW%^a%^RESET%^%^ORANGE%^mb%^YELLOW%^e%^RESET%^%^ORANGE%^r %^BOLD%^%^WHITE%^hue and it smells slightly %^YELLOW%^nutty %^WHITE%^with an underlying hint of wood and toffee. It is served in a %^RESET%^%^RED%^red shot glass%^BOLD%^%^WHITE%^.%^RESET%^");
     mydrink->set_strength(25);
     mydrink->set_id( ({ "rum", "drink" }) );
     break;

     case "vodka":
     mydrink = new("std/drink");
     mydrink->set_name("vodka");
     mydrink->set_short("a shot of clear liquid");
     mydrink->set_long("%^BOLD%^%^WHITE%^The %^RESET%^clear vodka %^BOLD%^%^WHITE%^is served in a %^RESET%^%^RED%^red shot glass %^BOLD%^%^WHITE%^with a twist of %^YELLOW%^lemon%^WHITE%^.%^RESET%^");
     mydrink->set_strength(30);
     mydrink->set_id( ({ "vodka", "drink" }) );
     break;

     default: return 0; break;
   }
   mydrink->set_type("alcoholic");
   mydrink->set_weight(0);
   mydrink->set_value(0);
   mydrink->set_destroy();
   mydrink->set_my_mess("You slam down the shot of "+mydrink->query_name()+"!");
   mydrink->set_your_mess("slams down the "+mydrink->query_name()+"!");
   mydrink->move(TP);
   tell_object(TP,"You pour yourself some alcohol.");
   tell_room(TO,""+TP->QCN+" pours a shotglass of alcohol.",TP);
   return 1;
}

int peer_fun(string str){
   string mystring, mystring2;
   if(TP->query_true_invis()) return 0;
   if(!str) return 0;
   if(sscanf(str,"%s %s", mystring, mystring2) != 2) mystring = str;
   if(mystring != "north" && mystring != "n") return 0;
   tell_object(TP,"%^RESET%^%^RED%^The bright %^RED%^f%^RESET%^%^RED%^l"
"%^ORANGE%^a%^MAGENTA%^m%^RED%^e%^BOLD%^s %^RESET%^%^RED%^licking the "
"doorframe make it too difficult to see what lies beyond.%^RESET%^");
   return 1;
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   tell_object(TP,"%^RESET%^%^RED%^The flames encircling the doorframe "+
"%^BOLD%^%^RED%^glow%^RESET%^%^RED%^ as you pass through.");
   tell_room(TO,"%^RESET%^%^RED%^The flames encircling the doorframe "+
"%^BOLD%^%^RED%^glow%^RESET%^%^RED%^ as "+TP->QCN+" passes through.",TP);
   return 1;
}
