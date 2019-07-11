// /d/magic/symbols/tyr_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^WHITE%^n%^BLUE%^e%^WHITE%^lv%^BLUE%^i%^WHITE%^ne%^RESET%^","%^MAGENTA%^amethyst%^RESET%^","%^BOLD%^%^BLACK%^hematite%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^YELLOW%^Tyr%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","tyr_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^BOLD%^%^BLUE%^                            ~/\n"+
"         %eC              (//%^YELLOW%^#%^BLUE%^//%              7S%\n"+
"         SSeGO6%7t(~((~((~//%^YELLOW%^###%^BLUE%^//~((tt(~(((C6OGeS@\n"+
"         SSeGOO6CC%^YELLOW%^#######################%^BLUE%^CC6sOGeSK\n"+
"        %SSeGOO6CC%^YELLOW%^/\\%^BLUE%^tt(((~SS%^YELLOW%^###%^BLUE%^Ss~(((tt%^YELLOW%^/\\%^BLUE%^CC6sOGeSQ7\n"+
"        %QSeGOO6%^YELLOW%^/%^BLUE%^%%%%%^YELLOW%^\\%^BLUE%^(((~sSS%^YELLOW%^#%^BLUE%^SSO~(((%^YELLOW%^/%^BLUE%^%%%%%^YELLOW%^\\%^BLUE%^6sOGeSQS\n"+
"        R@@BROO%^YELLOW%^########%^BLUE%^%t(sSS%^YELLOW%^#%^BLUE%^SSG%3C%^YELLOW%^########%^BLUE%^ORR@@@@\n"+
"        B@@BROOQS%^YELLOW%^####%^BLUE%^C3%t(sS%^YELLOW%^###%^BLUE%^SG%%C6s%^YELLOW%^####%^BLUE%^QOORR@@@@\n"+
"        B@@BROOQSeGO6C3%t(s%^YELLOW%^#####%^BLUE%^G%%C6sOGSQQOORR@@@@\n"+
"        Q@@BROOQSeGO6C%^RESET%^XXXXXXXXXXXXXXX%^BOLD%^%^BLUE%^sOGSQQOORR@@@@\n"+
"        6@@BROOQSeGO6C%^RESET%^XXXXXXXXXXXXXXX%^BOLD%^%^BLUE%^sOGSQQOORR@@@Q\n"+
"        7@@BROOQSeGO6C%^RESET%^XXXXXXXXXXXXXXX%^BOLD%^%^BLUE%^sOGSQQOORR@@@~\n"+
"         @@BROOQSeGO6C3%t(s%^BLACK%^-----%^BLUE%^G%%C6sOGSQQOORR@@R\n"+
"         R@BROOQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOORR@@@\n"+
"         ^@BROOQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOORR@@\n"+
"          GBROOQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOORR@@\n"+
"           BROOQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOORRR\n"+
"           SROOQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOOR@6\n"+
"            OOOQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOOR@\n"+
"             6OQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQOO@\n"+
"              GQSeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQO@\n"+
"               #QeGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGSQQ@\n"+
"                3SGO6C3%t(s%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOGS@~\n"+
"                  OO6C3%t(6%^RESET%^%^ORANGE%^/////%^BOLD%^%^BLUE%^G%%C6sOS@\n"+
"                   %sC3%t((~/~((7%%C6s@\n"+
"                     @3%t((~/~((7%%CK@\n"+
"                       @7((~/~((7%@Q\n"+
"                         et~/~(7@(\n"+
"                           /@3@\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}
