// /d/magic/symbols/kossuth_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^RED%^ruby%^RESET%^","%^YELLOW%^fire%^RESET%^%^RED%^ opal%^RESET%^","%^BOLD%^%^RED%^flamedance%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^RED%^Kossuth%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","kossuth_holy_symbol",jewelry,gem+" "+jewelry}));
   set_name(gem+" "+jewelry);
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   string ldesc,tmp;
   ::init();
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
   tmp = "%^BOLD%^%^RED%^                /Q/\n"+
"                 #@RC\n"+
"                 /B@R#@~\n"+
"                 ~@@BRR#R\n"+
"                 @@@RR#B#R\n"+
"                S@@@RRRRRR@\n"+
"               S@@@BRRRRRRR#\n"+
"             ^@@@@BRRRRRRB#RO    B\n"+
"            Q@@@BRB#RRRRR@RR@    #@\n"+
"          B@BB@RRBBBKG#RRRRR@   @@@R\n"+
"         @@RRRRRRB@QSQRRRBRB/  @BRR@\n"+
"       @R@BRBBRRB#SQS@RRRRQ^/S@@RRRR%\n"+
"      @@RRBBRRRRQeSSQRRRRRBR@R@BRBRB@\n"+
"     B@RRBRRRRRSSQ#6RBRRRRRRRRRRRRRR@\n"+
"    C@RRRRRRRBBeQC%^YELLOW%^/%^RED%^6#BRRRRRBBRRRRRRRB(\n"+
"    @RRRRRR#B@SG%^YELLOW%^///%^RED%^SGRRRRRBBQ#RR#RBRB%\n"+
"    @RBRRRRR@QQ%^YELLOW%^////%^RED%^QSS#BBRQeSS@@SBBR@%\n"+
"   ^@R@RRRRR@SC%^YELLOW%^////%^RED%^GSSSK6GQSQKBQQBRR@(\n"+
"    BRRRRRRRBS%^YELLOW%^//////%^RED%^GKG#7%^YELLOW%^/%^RED%^QSSeGS@RRR@\n"+
"    @RBRRRRR@t%^YELLOW%^////////%^RED%^~%^YELLOW%^///%^RED%^CGSSS#@RRB#\n"+
"    KBRRRRRRB%^YELLOW%^/////////////%^RED%^eSSQSRR#@B\n"+
"     R@RRRRR@7%^YELLOW%^////////////%^RED%^QQGSBRRRB@\n"+
"     ##RR@#RR@~%^YELLOW%^/~////////%^RED%^%Se#BRRB@@\n"+
"      RRRBR#@R@%^YELLOW%^////////~%^RED%^QSQRRRRB@@\n"+
"        e##RRRRRB@@RQQKRBRBRRB@@\n"+
"          eR@@RRRRRBRRRRRRR@@@R\n"+
"          RRBRRRRR#RRRRRB@@O\n"+
"             tB@@@@#R#RB@/\n"+
"                 %@BB@G\n"+
"                    K%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
}
