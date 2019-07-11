// /d/magic/symbols/akadi_symbol.c
//updated by Circe 4/10/05

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^CYAN%^turquoise%^RESET%^","%^BOLD%^%^WHITE%^clear quartz%^RESET%^","%^BOLD%^%^BLUE%^sapphire%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^BOLD%^%^CYAN%^Akadi%^RESET%^";

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
   tmp = "%^BLUE%^QG(/SKQGSQQSKSSSQQQQQQeSSRQSQK#K####RRRQQ##@#KRRB@@#\n"+
"e~S6OSeGSSSSS##KeeeSQQQSSQQQ####R#RR##R#KK#Q######SR@\n"+
"RQSGGGOOGOGQ#B@R#KKeeSOOeSQQKQKQQKQKSK##QSK##QQK##3C#^\n"+
" @QQGGOOOSQ##R#@#R#KS@R7%^BOLD%^%^WHITE%^()%^RESET%^%^BLUE%^Q@QQQQSQ#KQ#RR#QKQ#GGOGeS#S@\n"+
" (#BSGGeSKR@#####QK@%^BOLD%^%^WHITE%^((((((()%^RESET%^%^BLUE%^~@7~%^BOLD%^%^WHITE%^()%^RESET%^%^BLUE%^@RBRB@RK#Q##QQQSSKR@\n"+
"  RRQQS#B@@@@BB#RB@O%^BOLD%^%^WHITE%^(((((((() (((()%^RESET%^%^BLUE%^~@B@@BBRRRRR##KSQRR\n"+
"  @#QQ#BRR@@R@%^BOLD%^%^WHITE%^((((((()(((((((((((((()(()%^RESET%^%^BLUE%^@BBB#@#R@B#R#C\n"+
"  @K##RRB#R@R%^BOLD%^%^WHITE%^((((((()(((((((((((((((  (()%^RESET%^%^BLUE%^R@KO@@B@BRR#\n"+
"  @RRR@RRR@@K%^BOLD%^%^WHITE%^(((((((((((((((((((((((((((((((() %^RESET%^%^BLUE%^@BRR##\n"+
"  @B@@BRRR#@%^BOLD%^%^WHITE%^(((((((((((((((((((((((((((((((((()%^RESET%^%^BLUE%^S@R#R#\n"+
"  @@RB@QR@%^BOLD%^%^WHITE%^((((((((((((((((((((((((((((((((((((%^RESET%^%^BLUE%^@#S#QR#\n"+
"  @K###BRR#BRR%^BOLD%^%^WHITE%^(((((((((((((    (((((((((((%^RESET%^%^BLUE%^RB@R#QQQ##R/\n"+
"  %#BBR###B#Q#RB@@@%^BOLD%^%^WHITE%^(((((()%^RESET%^%^BLUE%^R#RR#R#R#%^BOLD%^%^WHITE%^((()%^RESET%^%^BLUE%^@@@B@@@#KQSSSR3\n"+
"   @BB#R###eeQQ###RR#KR##RBBBB#B#QSQQRB@@@BRRRQQQSeKKB\n"+
"   @@@###KeQSGGQ###QQKK####BRBRRBSeS#QQR@RRRSSSSSeGeQ#\n"+
"    R#R##KOeeGQeGSSGOGesSGGQS#RR#QSeQQQQKQKR#KeSSSSSQ(R\n"+
"    RBRKQSQGGeSeGQSQQSSeeSGOGOSQSSe#QK##K#Q#QQGQS##e(%KG\n"+
"     Ge63CQ#K#QR#SK#QQ#RR#QGeeSOeSKQeQQ#G#KKe#KR#RKG63##\n"+
"      (@@@@@@@@@@@@#RSG%~%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}