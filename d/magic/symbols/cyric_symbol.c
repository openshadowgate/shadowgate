// /d/magic/symbols/cyric_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^MAGENTA%^purple jasper%^RESET%^","%^BOLD%^%^BLACK%^black agate%^RESET%^","%^ORANGE%^tomb jade%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^RESET%^%^MAGENTA%^Cyric%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","cyric_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^MAGENTA%^                                    t\n"+
"                                    C\n"+
"        /                           G\n"+
"        ~(                          S         /\n"+
"          eG           ~7/         ^#        ^s/               //\n"+
"           /C           Ce         sO^       ~R/              t/\n"+
"            7#t         C@         #O/       (B7           ^CS\n"+
"            /eK(        s@         #O/       %#O          ^6B(\n"+
"              %RSC/     sQS~^  C^ ~QGt //   ~K#C        ~#SC^\n"+
"                BeQs^   ^GSSSG^7( OQeO C% (RS#O       (B#K\n"+
"                tKQSQ^ ~t7##QQ37O 3#eQ^K(tBQSQ/ ~ ^ ^%K#e^\n"+
"                 (eQKSS/^O eK#KR#%GeSSSeBRQ#S %O^ ^RR##t      /^\n"+
"                   R##e#K~QG#SQRSRSQSSGGGeG@/s#^CQRR#O       6/\n"+
"        ^~t(    ~3t 7QKKQ@R#eKS#B@@R#@RRGGGS#QBR#QKS(     ^ Q#\n"+
"        tRRet^    tS/6##KR#QS##           SKKSQQ#BQ( tt    (#O\n"+
"           3OQ%((%/~seRK#KQ@@@ %^BOLD%^%^WHITE%^##########   %^RESET%^%^MAGENTA%^@#B#@GC@%^//(t##e\n"+
"        ^   GQOs3CGeOSSS#QR@  %^BOLD%^%^WHITE%^#############  %^RESET%^%^MAGENTA%^#BSeR@KRRRR##RO/\n"+
"            ^eGQQ#OOGQSeQ#@ %^BOLD%^%^WHITE%^################  %^RESET%^%^MAGENTA%^RQR#sBQSQQSRCt\n"+
"            /tKsCQK@SGQG#@ %^BOLD%^%^WHITE%^################## %^RESET%^%^MAGENTA%^@@Q#SOsOR(/\n"+
"        ^  /(((^(sQBSOOeR %^BOLD%^%^WHITE%^################### %^RESET%^%^MAGENTA%^@@B###RRQ(\n"+
"  /Q#COQQGOGGOGGsGeK#QeKB %^BOLD%^%^WHITE%^###    #####    ### %^RESET%^%^MAGENTA%^@@RR##OCs6O6sSeQQK###RB@BRG~\n"+
" ^   ^3CCKRQQSeQOOQSQSK#R %^BOLD%^%^WHITE%^##     #####     ## %^RESET%^%^MAGENTA%^@@KQQ#SGOC6%%C7%GQO7(3eC~\n"+
"             ^t#@#Q#Q#Q#  %^BOLD%^%^WHITE%^##    ###  ##    ##   %^RESET%^%^MAGENTA%^#eOK@@%~ ^/^\n"+
"            ~6Ct3%e#QS# %^BOLD%^%^WHITE%^###########  ########## %^RESET%^%^MAGENTA%^RROS##@@OQ\n"+
"             //^(6GK6KS %^BOLD%^%^WHITE%^##########   ########## %^RESET%^%^MAGENTA%^#G##OQ#Q(/\n"+
"              (OsO6ssGO@ %^BOLD%^%^WHITE%^ ###################  %^RESET%^%^MAGENTA%^BK#SKQQSQ#O\n"+
"            /3C3S63e@66QK#    %^BOLD%^%^WHITE%^ ##########    %^RESET%^%^MAGENTA%^##Q#R7   GOeee/\n"+
"            6(7S/ 3C%S3CsK#SK@@  %^BOLD%^%^WHITE%^||||||  %^RESET%^%^MAGENTA%^@BRRSKSQSCKG   /SeG(\n"+
"         //%(%3/^336/O%3sSSQ#@@@        @@B#QSK#S#% @O   /G#O\n"+
"        /(((   (~/ G%C%tOSOG#e#B@@@#@@@@@#SCOO#KQe#S  ^    /GQ(\n"+
"                 C63C6sG(eKQOOQOGCOeOQS#GGSG%(%/O#QSG%\n"+
"                %eCt3GQ~CQ%KCGOeeGsCs#QBOGSet s(/%@#6S/\n"+
"              /Q6OCG3/ 6( OOs6sBe~OGOGKeCGSGR/ s/  7eGG6/\n"+
"          ^  (GsOe7  ^   O%sOO%s7^OO67~O^sCQeG3 /    ^GG#~\n"+
"            G3GS(      sOCeOQ/ e^^6Os/^(/ ^/QOGG        sGS~\n"+
"           ^sOQ(      %GGGSO  ^(  %GO/ /    /eGQ/      ^ 7QO~\n"+
"          76O(        Qes/        %GC^        ~%Q          (Qe\n"+
"         6CG          #O^         (sO          ^Q            ^(^\n"+
"        ~Qs(          GC          /OO           #             O~\n"+
"       %6^            /%           SO           ~              /C/\n"+
"      ^~                           sG                             ^\n"+
"                                   (e\n"+
"                                   /#\n"+
"                                    #\n"+
"                                    /%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}
