// /d/magic/symbols/auril_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^WHITE%^sn%^BLACK%^o%^WHITE%^wfl%^BLACK%^a%^WHITE%^k%^BLACK%^e%^WHITE%^ obsidian%^RESET%^","%^BOLD%^%^WHITE%^diamond%^RESET%^","%^BOLD%^%^WHITE%^clear calcite%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^BOLD%^%^CYAN%^Auril%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","auril_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^BOLD%^%^CYAN%^                  /%^RESET%^%^CYAN%^=%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^                //%^RESET%^%^CYAN%^===%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^               /%^RESET%^%^CYAN%^======%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^              /%^RESET%^%^CYAN%^========%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^             /%^RESET%^%^CYAN%^==========%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^           /%^RESET%^%^CYAN%^=============%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^          /%^RESET%^%^CYAN%^================%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^         /%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^RR R@%^RESET%^%^CYAN%^==%^BOLD%^%^WHITE%^SRR @R%^RESET%^%^CYAN%^==%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^       //%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^RR#R#%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^#B#RR%^RESET%^%^CYAN%^===%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^      /%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^RRRRRRQ%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^BRR##B6%^RESET%^%^CYAN%^==%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^     /%^RESET%^%^CYAN%^======%^BOLD%^%^WHITE%^CR@RR@%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^B##R@R@%^RESET%^%^CYAN%^===%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^    /%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^B%^RESET%^%^CYAN%^=====%^BOLD%^%^WHITE%^RR@%^RESET%^%^CYAN%^==%^BOLD%^%^WHITE%^RRB3%^RESET%^%^CYAN%^========%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^  //%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^S#B%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^~##%^RESET%^%^CYAN%^==%^BOLD%^%^WHITE%^KR@%^RESET%^%^CYAN%^=====%^BOLD%^%^WHITE%^#%^RESET%^%^CYAN%^====%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^ /%^RESET%^%^CYAN%^======%^BOLD%^%^WHITE%^Q@RR%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^RRRRR@%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^eB@3%^RESET%^%^CYAN%^====%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^/%^RESET%^%^CYAN%^======%^BOLD%^%^WHITE%^B#RRRRRRRRRRRRRRRRRRRRR#O%^RESET%^%^CYAN%^===%^BOLD%^\\\n"+
"%^BOLD%^%^CYAN%^ \\%^RESET%^%^CYAN%^======%^BOLD%^%^WHITE%^##RRBRRRRRRRRRRRRRRRRBRO%^RESET%^%^CYAN%^===%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^  \\%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^@R@%^RESET%^%^CYAN%^=====%^BOLD%^%^WHITE%^@RRRRO%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^RRG^%^RESET%^%^CYAN%^=====%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^    \\%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^C%^RESET%^%^CYAN%^=====%^BOLD%^%^WHITE%^BBR%^RESET%^%^CYAN%^=%^BOLD%^%^WHITE%^BR#/%^RESET%^%^CYAN%^====%^BOLD%^%^WHITE%^@RQ%^RESET%^%^CYAN%^===%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^     \\%^RESET%^%^CYAN%^========%^BOLD%^%^WHITE%^RR@e%^RESET%^%^CYAN%^==%^BOLD%^%^WHITE%^RRR%^RESET%^%^CYAN%^=====%^BOLD%^%^WHITE%^6%^RESET%^%^CYAN%^==%^BOLD%^//\n"+
"%^BOLD%^%^CYAN%^      \\%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^@B#@BR#%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^@RR#%^RESET%^%^CYAN%^======%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^       \\%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^#RRBR%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^@RRRB%^RESET%^%^CYAN%^=====%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^         \\%^RESET%^%^CYAN%^=%^BOLD%^%^WHITE%^tRR@RR%^RESET%^%^CYAN%^===%^BOLD%^%^WHITE%^##RRR%^RESET%^%^CYAN%^===%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^          \\ %^BOLD%^%^WHITE%^RR%^RESET%^%^CYAN%^=%^BOLD%^%^WHITE%^@B%^RESET%^%^CYAN%^==%^BOLD%^%^WHITE%^SBCt#R@%^RESET%^%^CYAN%^=%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^           \\%^RESET%^%^CYAN%^==============%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^             \\%^RESET%^%^CYAN%^===========%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^              \\%^RESET%^%^CYAN%^========%^BOLD%^//\n"+
"%^BOLD%^%^CYAN%^               \\%^RESET%^%^CYAN%^======%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^                \\%^RESET%^%^CYAN%^====%^BOLD%^/\n"+
"%^BOLD%^%^CYAN%^                  \\%^RESET%^%^CYAN%^-%^BOLD%^/\n
%^RESET%^";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}

