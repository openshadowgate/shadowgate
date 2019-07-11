// /d/magic/symbols/istishia_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^BLUE%^water opal%^RESET%^","piece of %^ORANGE%^c%^BOLD%^%^MAGENTA%^o%^RESET%^%^BOLD%^r%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^l%^RESET%^","%^BOLD%^%^CYAN%^aquamarine%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem, jewelry, metal;
int isset;
string GOD = "%^CYAN%^Istishia%^RESET%^";

void create(){
   string ldesc,tmp;
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","istishia_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^BLUE%^                           @@@@@@@@@@@@@@@@@@@@@\n"+
"                       @@@%^WHITE%^7777777777777777777%^BLUE%^OOO@@@\n"+
"                    @@@%^WHITE%^77777777777777777777777%^BLUE%^OOOOO@@@\n"+
"                 @@@%^WHITE%^7777777777777777777777777777%^BLUE%^OOOOOOO@@\n"+
"                @%^CYAN%^R%^WHITE%^7777777777777777777777777777777%^BLUE%^OOOOOOOO@@\n"+
"              @@%^CYAN%^RRRRRRRRRR%^WHITE%^777777777777777777777777%^BLUE%^OOOOOOOOO@@\n"+
"            @@%^CYAN%^RRRRRRBRRRRRRR%^WHITE%^7777777777777777777777%^BLUE%^OOOOOOOOOOO@@\n"+
"           @@%^CYAN%^RRRRRBRRRRRRRRRRRRRR%^WHITE%^777777777777777777%^BLUE%^OOOOOOOOOOO@@\n"+
"         @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^777777777777777%^BLUE%^OOOOOOOOOOOOO@\n"+
"        @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^77777777777777%^BLUE%^OOOOOOOOOOOO@@\n"+
"       @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^777777777777%^BLUE%^OOOOOOOOOOOOO@@\n"+
"      @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^777777777777%^BLUE%^OOOOOOOOOOOOO@@\n"+
"      @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^777777777%^BLUE%^OOOOOOOOOOOOOO@\n"+
"     @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^7777777%^BLUE%^OOOOOOOOOOOOOOO@\n"+
"     @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^777777%^BLUE%^OOOOOOOOOOOOOOO@@\n"+
"    @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^77777%^BLUE%^OOOOOOOOOOOOOOOO@\n"+
"    @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRBBRRRRRRRRR%^WHITE%^7777%^BLUE%^OOOOOOOOOOOOOOOO@\n"+
"   @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^WHITE%^777%^BLUE%^OOOOOOOOOOOOOOOOO@\n"+
"   @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCC%^WHITE%^777%^BLUE%^OOOOOOOOOOOOOOOOO@\n"+
"   @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCOOOOOOOOOOO@\n"+
"   @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCOOOOOOOOO@\n"+
"   @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCOOOOOOOO@\n"+
"   @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCCOOOOOOOO@\n"+
"   @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOOOOO@\n"+
"    @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOOOO@\n"+
"    @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOOO@\n"+
"    @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOO@@\n"+
"     @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^CCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOO@@\n"+
"      @%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O@@\n"+
"      @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^%%%%%%%%%%%%%%%%%%%%%%%%%%%O@\n"+
"      @@@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^%%%%%%%%%%%%%%%%%%%%%%%%@@\n"+
"        @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^%%%%%%%%%%%%%%%%%%%%@@\n"+
"         @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRBBBBBB%^BLUE%^%%%%%%%%%%%%%%%%@@\n"+
"          @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^@@\n"+
"           @@@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRBBBBBBBBBBRBR%^BLUE%^@@\n"+
"             @@%^CYAN%^RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR%^BLUE%^@@\n"+
"              @@@%^CYAN%^RBBBBRRRRRBRRRRRRBBBBBBBRRRBBBBBBBBBBRBB%^BLUE%^@@@\n"+
"                 @@%^CYAN%^RRBBRRRRRRRRRBBBBBBBBBBBBBBBBBBRRRRR%^BLUE%^@@@\n"+
"                   @@@%^CYAN%^RRBRRRRRBBBBBBRRBBBBBBBBBRRRRRR%^BLUE%^@@\n"+
"                     @@@@%^CYAN%^RRRRRRBBRBBBBBBRBRRRRRRR%^BLUE%^@@@@\n"+
"                          @@@@@%^CYAN%^RRRRRRRRRRRRB%^BLUE%^@@@@@\n"+
"                               @@@@@@@@@@@@%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}
