// /d/magic/symbols/silvanus_symbol.c
//updated by Circe 4/7/13

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^RESET%^%^ORANGE%^ti%^YELLOW%^g%^RESET%^%^ORANGE%^ers e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^e%^RESET%^","%^RESET%^%^GREEN%^ja%^BOLD%^d%^RESET%^%^GREEN%^e%^RESET%^","%^BOLD%^%^GREEN%^emer%^WHITE%^a%^GREEN%^ld%^RESET%^"})
#define METALS ({"%^BOLD%^%^YELLOW%^gold","%^RESET%^%^ORANGE%^cop%^GREEN%^p%^ORANGE%^er","%^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^ver"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^RESET%^%^GREEN%^Silvanus%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","silvanus_holy_symbol",jewelry,gem+" "+jewelry}));
   set_name(gem+" "+jewelry);
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   string ldesc,tmp;
   ::init();
   if(isset) return;
   switch(jewelry){
      case "ring": ldesc = "Fashioned from "+metal+"%^RESET%^, this "+
         "ring looks solid and strong.  The band is polished smooth, "+
         "a simple but effective design.  A well-cut "+gem+" is mounted into "+
         "the center of the band.  Within the "+gem+" the holy symbol of "+
         ""+GOD+" has been carved.  A sacred aura almost seems to "+
         "radiate around the ring.\n";
         set_short(""+metal+" ring%^RESET%^");
         add_id("ring");
         set_limbs(({"right hand"}));
         break;
      case "bracelet": ldesc = "Fashioned from "+metal+"%^RESET%^, "+
         "this bracelet looks solid and strong.  The cuff bracelet "+
         "is polished smooth, a simple but effective design.  A "+
         "well-cut "+gem+" is mounted into the center of the bracelet.  "+
         "Within the "+gem+" the holy symbol of "+GOD+" has been "+
         "carved.  A sacred aura almost seems to radiate around "+
         "the bracelet.\n";
         set_short(""+metal+" bracelet%^RESET%^");
         add_id("bracelet");
         set_limbs(({"right arm"}));
         break;
      case "amulet": ldesc = "Fashioned from "+metal+"%^RESET%^, "+
         "this amulet hangs from a chain and looks solid and "+
         "strong.  The amulet is polished smooth, a simple but "+
         "effective design.  A well-cut "+gem+" is mounted into the center "+
         "of the amulet.  Within the "+gem+" the holy symbol of "+
         ""+GOD+" has been carved.  A sacred aura almost seems "+
         "to radiate around the amulet.\n";
         set_short(""+metal+" amulet%^RESET%^");
         add_id("amulet");
         set_limbs(({"neck"}));
         break;
      default: break;
   }
   tmp = "\n%^RESET%^%^GREEN%^                       ,,,8OZ$Z  \n"       
"                      8Z$$7Z8Z7$        \n"
"                     ?Z$7ZZ?$I7         \n"
"                     ZOZ$I??IZ7         \n"
"                8DO7$$IOZOI$ZO$7$OO,    \n"
"               ZD$O$7$IZ8%^ORANGE%^+%^GREEN%^I$$8ZIZ$OO    \n"
"               $OZZOOZZO$%^ORANGE%^+%^GREEN%^77$OO$O$ZZ$   \n"
"               O7$7OZOZO$%^ORANGE%^+%^GREEN%^?7ZZ$7O$$7    \n"
"         O88$  DZII7OO$Z%^ORANGE%^+%^GREEN%^I$77$$8ZZ$     \n"
"        8O$OOZZ+Z$$?ZZO$%^ORANGE%^+%^GREEN%^O$778$O7I      \n"
"       ,OZOZZ$O?O77IZOO$%^ORANGE%^+%^GREEN%^77O8ZZ7   ,,,  \n"
"        8ZOD8IOO$$$ZO$DZ%^ORANGE%^+%^GREEN%^7I7OZ$O7O87ZI$ \n"
"         8OZOZ$7OOZOOZ?%^ORANGE%^+%^GREEN%^I$ZZZO77$O$$Z?ZI\n"
"         ,O$$$8Z$$ZO88$%^ORANGE%^+%^GREEN%^ZZ7$8Z$OZO7ZZ$$ \n"
" 7OOZO,   :8ZZZ$$7$OOIZ%^ORANGE%^+%^GREEN%^ZOZZO88$Z$$OOO  \n"
"$Z7OO$IO$,,7ODZ877IZO$O%^ORANGE%^+%^GREEN%^OOZ7ZZOO8Z$$?   \n"
"OOOO8O$OZZOZ$O7D$$Z8$Z%^ORANGE%^+%^GREEN%^8$ZOZ$$7Z7      \n"
"Z$Z$OD$OO8DDO77$OZO$O%^ORANGE%^+%^GREEN%^O$OZZ7I,          \n"
" 88ZO778ZZZZZZ7O$NZZZ%^ORANGE%^+%^GREEN%^ZDOOO77?:,,,:,    \n"
"  OOZZ8ZO8$ZZZZ88O$7Z%^ORANGE%^+%^GREEN%^8OOO7$I7ZZZOOII7  \n"
"    =ODOO8ZZZZZZDO7$%^ORANGE%^+%^GREEN%^OZOO$7OOZZZ$7$ZI$I \n"
"      ,ODO87OIZO8Z7$%^ORANGE%^+%^GREEN%^O8OOZ$ZZ$$I7ZI7777=\n"
"        ,8DZ$7O8D$ZZ%^ORANGE%^+%^GREEN%^OZ$8OO$I$$8ZO7I?I= \n"
" ZOZZ$~   ~O$Z788D$%^ORANGE%^+%^GREEN%^Z7III7$?7Z$ZOZZ7I,  \n"
"OO7OZZ$Z$Z :ZZZ8Z7O%^ORANGE%^+%^GREEN%^OO?               \n"
"~OZZODOOOZZZ7OZDOZ$%^ORANGE%^+%^GREEN%^ZO$7$Z$$,           \n"
" ,ZOZZ$OO7ZZO$$87Z%^ORANGE%^+%^GREEN%^Z78ZOO87$ZZ$         \n"
"    ~$ZZ$ZZOOZZ$Z8%^ORANGE%^+%^GREEN%^IZIZZ$77Z8OOZ        \n"
"       OO8ZO8ODOZ%^ORANGE%^+%^GREEN%^ZZOZ$77$$OOZZ7        \n"
"     =7$Z$ZZZODZZ%^ORANGE%^+%^GREEN%^ZZ$,,,77++=           \n"
"     $I$OZON$ZZ78%^ORANGE%^+%^GREEN%^ZO$,                  \n"
"     ,OZZIZZ77O7%^ORANGE%^+%^GREEN%^OZZOOOO                \n"
"       =7OZ$ZOOO%^ORANGE%^+%^GREEN%^ZZ$DZOOZ               \n"
"        ,=OZZD8%^ORANGE%^+%^GREEN%^7Z$7OZO,                \n"
"          ,$$O%^ORANGE%^+%^GREEN%^77,                      \n"
"%^ORANGE%^           =8:,                         \n"
"           Z,                           \n"
"          :O                            \n"
"          $~                            \n"
"         =8                             \n"
"        ,$?                             \n"
"         :%^RESET%^ \n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}