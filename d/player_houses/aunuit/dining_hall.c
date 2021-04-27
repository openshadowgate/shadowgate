
//Coded by ~Circe~ 7/24/13
//menu added by Tsera 06/19/14

#include <std.h>

#include "aunuit.h"

inherit AUNUIT;


void init() {
    ::init();
    add_action("read", "read");
}



void create(){
   ::create();

   set_name("Dining Hall");
   set_short("%^BOLD%^%^BLACK%^Dining Hall%^RESET%^");

   set_long("%^BOLD%^%^BLACK%^This spacious dining hall has all "
      "the trappings of a decadent inn. The floor is a beautiful, "
      "bla%^RESET%^c%^BOLD%^%^BLACK%^k m%^WHITE%^a%^BLACK%^rbl"
      "%^RESET%^e %^BOLD%^%^BLACK%^that has been buffed to a "
      "%^WHITE%^m%^RESET%^i%^BOLD%^%^WHITE%^r%^BLACK%^r%^RESET%^o"
      "%^BOLD%^%^WHITE%^r%^BLACK%^-like %^WHITE%^sheen %^BLACK%^and "
      "the walls are lined with rich, %^RESET%^%^ORANGE%^darkwood "
      "paneling%^BOLD%^%^BLACK%^. Large %^WHITE%^scr%^RESET%^i"
      "%^BOLD%^%^WHITE%^ms%^RESET%^h%^BOLD%^%^ORANGE%^a%^BOLD%^"
      "%^WHITE%^w p%^RESET%^i%^BOLD%^%^WHITE%^ll%^ORANGE%^a%^WHITE%^rs "
      "%^BLACK%^brace the arched ceiling, also composed of dragon "
      "%^WHITE%^b%^ORANGE%^o%^WHITE%^ne%^BLACK%^. The main floor of "
      "the hall is a lounge complete with ample seating as well as "
      "various forms of entertainment. Nestled in the northwestern "
      "corner of the room is a pie-shaped %^RESET%^%^MAGENTA%^stage "
      "%^BOLD%^%^BLACK%^surrounded by %^RESET%^%^ORANGE%^circular "
      "tables%^BOLD%^%^BLACK%^. The eastern wall houses the bar and "
      "kitchen. A deep %^RESET%^hearth %^BOLD%^%^BLACK%^has been "
      "constructed in the southwestern corner of the room, a pair "
      "of over-stuffed %^RESET%^grey velvet chairs %^BOLD%^%^BLACK%^"
      "facing it. The southern quarter of the chamber is dominated "
      "by a raised marble %^RESET%^dais%^BOLD%^%^BLACK%^. There rests "
      "a long %^RESET%^%^ORANGE%^table %^BOLD%^%^BLACK%^where a pair "
      "of exotic high backed seats overlook the hall. An arched "
      "doorway leads to a hall to the east.%^RESET%^\n");

   set_smell("default","%^RESET%^%^CYAN%^The savory scents of delicious food and potent liquor fills the air.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^Heated conversation, laughter and whispers transpire between the various guests present.%^RESET%^");

   set_items(([
      "menu" : "%^RESET%^%^CYAN%^There are menus here that can be read.",
      ({"walls","wall","panels","paneling"}) : "%^BOLD%^%^BLACK%^The "
         "walls are lined with rich %^RESET%^%^ORANGE%^darkwood paneling "
         "%^BOLD%^%^BLACK%^ that insulate the room, keeping it at a "
         "comfortable temperature and reducing reverberation.%^RESET%^.",
      "dais" : "%^BOLD%^%^BLACK%^A semi-circular dais dominates the "
         "southern quarter of the room. From its heights, the entire "
         "lounge can be observed. A long %^RESET%^%^ORANGE%^darkwood table "
         "%^BOLD%^%^BLACK%^with detailed %^RESET%^drac%^BOLD%^%^BLACK%^o"
         "%^RESET%^nic e%^ORANGE%^f%^BOLD%^%^BLACK%^f%^RESET%^ig%^BOLD%^"
         "%^BLACK%^i%^RESET%^es %^BOLD%^%^BLACK%^acting as its legs stands "
         "here with two massive seats set behind it. One seat is composed of "
         "on%^RESET%^y%^BOLD%^%^BLACK%^x and the other the finest polished "
         "%^WHITE%^i%^RESET%^v%^BOLD%^%^ORANGE%^o%^RESET%^r%^BOLD%^%^WHITE%^y"
         "%^BLACK%^. Both are works of %^RESET%^%^MAGENTA%^high art %^BOLD%^"
         "%^BLACK%^with twisted s%^WHITE%^p%^BLACK%^i%^RESET%^r%^BOLD%^"
         "%^ORANGE%^e%^BLACK%^s rising from their high backs. Judging from "
         "its location at the head of the room and the opulence displayed "
         "there, the dais is reserved for people of great %^RESET%^"
         "%^ORANGE%^prestige%^BOLD%^%^BLACK%^.%^RESET%^",
      "bar" : "%^BOLD%^%^BLACK%^The bar's %^RESET%^%^ORANGE%^shelves "
         "%^BOLD%^%^BLACK%^are filled to the brim with %^WHITE%^bottles "
         "%^BLACK%^of all shapes, sizes and %^RESET%^%^ORANGE%^c%^BOLD%^"
         "%^ORANGE%^o%^RESET%^%^ORANGE%^l%^RED%^o%^ORANGE%^rs%^BOLD%^%^BLACK%^. "
         "%^WHITE%^White leather bar stools %^BLACK%^surround the reflective "
         "%^RESET%^%^ORANGE%^wooden bar top%^BOLD%^%^BLACK%^. Behind the bar, "
         "there is a doorway concealed by strands of %^RESET%^%^RED%^r%^BOLD%^"
         "%^RED%^u%^RESET%^%^RED%^by be%^BOLD%^%^RED%^a%^RESET%^%^RED%^ds"
         "%^BOLD%^%^BLACK%^. Servers hurry in and out through the doorway, "
         "when they emerge carrying platters of delicious smelling "
         "%^RESET%^%^MAGENTA%^food%^BOLD%^%^BLACK%^.%^RESET%^",
         "hearth" : "%^RESET%^Slate gr%^BOLD%^%^BLACK%^e%^RESET%^y st%^ORANGE%^"
         "o%^WHITE%^ne and %^BOLD%^%^BLACK%^mortar %^RESET%^comprise this "
         "deep h%^BOLD%^%^WHITE%^e%^BLACK%^a%^RESET%^rth. Rather than a fire "
         "there are numerous lit %^BOLD%^%^WHITE%^c%^ORANGE%^a%^WHITE%^ndles "
         "b%^ORANGE%^u%^WHITE%^rning %^RESET%^on the m%^ORANGE%^a%^WHITE%^ntl"
         "%^BOLD%^%^BLACK%^e %^RESET%^and within. Their %^BOLD%^%^WHITE%^white "
         "wax %^RESET%^drips down the br%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^c"
         "%^WHITE%^ks and %^BOLD%^%^WHITE%^congeals %^RESET%^in the belly of the "
         "f%^BOLD%^%^WHITE%^i%^RESET%^repl%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^c"
         "%^RESET%^e. A couple cozy-looking arm chairs upholstered in %^BOLD%^"
         "%^BLACK%^grey velvet %^RESET%^face the h%^ORANGE%^e%^BOLD%^%^BLACK%^"
         "a%^RESET%^rth. A circular %^ORANGE%^table %^WHITE%^is shared between them.%^RESET%^",
      "stage" : "%^RESET%^%^ORANGE%^A small pie-shaped wooden stage has been "
         "erected in the southwestern corner of the lounge.%^RESET%^",
      "ceiling" : "%^BOLD%^%^WHITE%^Made from the same material as the pillars "
         "the arched ceiling is composed of pale dr%^RESET%^a%^BOLD%^%^WHITE%^"
         "gon bone scr%^RESET%^i%^BOLD%^%^WHITE%^msh%^ORANGE%^a%^WHITE%^w. It "
         "has been treated so that its color is a pristine i%^RESET%^v%^BOLD%^"
         "%^ORANGE%^o%^RESET%^r%^BOLD%^%^WHITE%^y and there is no residual "
         "%^MAGENTA%^tissue %^WHITE%^but the natural texture remains, the bone "
         "like thick w%^BLACK%^e%^WHITE%^bb%^RESET%^i%^BOLD%^%^WHITE%^ng in some "
         "places and completely s%^ORANGE%^o%^WHITE%^lid in others.%^RESET%^"
   ]));
   set_exits(([
      "east" : ROOMS"west_wing"
   ]));
}

void reset() {
  ::reset();
   if(!present("enkahut"))
      find_object_or_load("/d/player_houses/aunuit/staff/enkahut.c")->move(TO);
}

int read(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
    write("%^BOLD%^%^CYAN%^The following items are being served.");
   
   
    write("  %^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~\n");
   write("%^BOLD%^%^RED%^           Appetizers\n");
    write("\t%^BOLD%^%^BLACK%^Food for %^RESET%^%^MAGENTA%^T%^BOLD%^%^MAGENTA%^h%^WHITE%^o%^MAGENTA%^u%^RESET%^%^MAGENTA%^ght%^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Bounty of the %^BLUE%^Deep%^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Finger %^CYAN%^L%^GREEN%^i%^CYAN%^ch%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^n %^BLACK%^Good%^RESET%^\n");
    write("  %^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~\n");
write("%^BOLD%^%^BLUE%^             Entrees\n");
    write("\t%^BOLD%^%^BLACK%^Wrong or %^RED%^R%^RESET%^%^RED%^o%^BOLD%^%^RED%^the%^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Rolling in the %^BLUE%^D%^CYAN%^e%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^p%^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Sp%^RED%^i%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^r%^RED%^ki%^RESET%^%^RED%^s%^BOLD%^%^RED%^s%^RESET%^%^RED%^e%^BOLD%^%^RED%^r %^BLACK%^Surprise%^RESET%^\n");
    write("  %^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~\n");
   write("%^BOLD%^%^WHITE%^            Desserts\n");
   write("\t%^RESET%^%^RED%^Bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^dy %^BOLD%^%^BLACK%^Good Pudding%^RESET%^");
    write("\t%^RESET%^%^ORANGE%^Cr%^RED%^u%^RESET%^%^ORANGE%^nchy %^BOLD%^%^BLACK%^Cave Delight%^RESET%^ ");
    write("\t%^BOLD%^%^BLACK%^Eye of the %^RESET%^%^MAGENTA%^Beh%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^ld%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r%^RESET%^\n");
    write("  %^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~\n");
   write("%^RESET%^%^CYAN%^             Drinks\n");
    write("\t%^RESET%^%^CYAN%^S%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^mple and cl%^BOLD%^%^WHITE%^e%^CYAN%^a%^RESET%^%^CYAN%^n%^RESET%^");
   write("\t%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^zi %^RESET%^%^ORANGE%^Tea%^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Black w%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ne%^RESET%^");
    write("\t%^BOLD%^%^WHITE%^M%^RESET%^o%^BOLD%^%^WHITE%^ther's M%^RESET%^i%^BOLD%^%^WHITE%^lk%^RESET%^");
    write("\t%^RESET%^%^BLUE%^Deep %^BOLD%^%^BLACK%^Aby%^RESET%^%^BLUE%^s%^WHITE%^s%^BOLD%^%^BLACK%^al %^RESET%^%^BLUE%^Ale %^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Drow %^RESET%^%^CYAN%^A%^BOLD%^%^CYAN%^z%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ne%^RESET%^");
    write("\t%^BOLD%^%^BLACK%^Sp%^RED%^i%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^r%^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^RESET%^\n");
    write("  %^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~"
"%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*"
"%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~%^BOLD%^%^WHITE%^*%^RESET%^%^BLUE%^~\n");
   
    write("<order dish_name> will get you the food or drink.");
    return 1;
}
