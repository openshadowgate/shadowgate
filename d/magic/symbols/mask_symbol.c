// /d/magic/symbols/mask_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^BLACK%^smoky quartz%^RESET%^","%^BOLD%^%^BLACK%^gray onyx%^RESET%^","%^BOLD%^%^BLACK%^gray chalcedony%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^BOLD%^%^BLACK%^Mask%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","mask_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "                    %^BOLD%^%^BLACK%^K^  %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^OR\n"+
"                 OeCC# %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^6O\n"+
"            SQ@KC6    %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^@O3(\n"+
"           @373%       %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^@7@s\n"+
"        @G(6633        %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^QC@@\n"+
"        O@(6%7%       %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^OO7O#\n"+
"        QOOQ%K%Cs7//%^RESET%^%^RED%^/%^BOLD%^%^BLACK%^6BO#@\n"+
"         %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^#e@@@@@(@3OROO/\n"+
"   %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^RR6Ct6@^ ^       C##QO7\n"+
" %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^eQeGeQQ#BB@7       CGRR##%((\n"+
" %^RESET%^%^RED%^/%^BOLD%^%^BLACK%^%S@%KG%G6@          RSQ#e%tRtC\n"+
"%^RESET%^%^RED%^|%^BOLD%^%^BLACK%^S%6S#(76s             QG@((3C76\n"+
"%^RESET%^%^RED%^|%^BOLD%^%^BLACK%^QQ%SRe@(67@          @~CsCC%t6%\n"+
"%^RESET%^%^RED%^|%^BOLD%^%^BLACK%^3S7QKG%^RESET%^%^RED%^#6%%^BOLD%^%^BLACK%^%%C%/@K@@t((63t%%OC#3%\n"+
"%^RESET%^%^RED%^|%^BOLD%^%^BLACK%^ROCKQe%^RESET%^%^RED%^7  %^RED%^%s%^BOLD%^%^BLACK%^%C7%7%6s%t%^RESET%^%^RED%^3t((%^BOLD%^%^BLACK%^OG@GC(\n"+
" %^RESET%^%^RED%^|%^BOLD%^%^BLACK%^OCQQ@%^%^RESET%^RED%^#    %^RED%^G%^BOLD%^%^BLACK%^s((7(73%%^RESET%^%^RED%^C    %^RED%^6%^BOLD%^%^BLACK%^Ces7\n"+
" %^RESET%^%^RED%^|%^BOLD%^%^BLACK%^RCSO@Q%^RESET%^%^RED%^6    %^RED%^S%^BOLD%^%^BLACK%^SC7C%%%^RESET%^%^RED%^G    %^RED%^O%^BOLD%^%^BLACK%^OeSs%\n"+
" %^RESET%^%^RED%^|%^BOLD%^%^BLACK%^R%eQ@KQ%^RESET%^%^RED%^6   %^RED%^B%^BOLD%^%^BLACK%^O%73%%^RESET%^%^RED%^6    %^RED%^e%^BOLD%^%^BLACK%^OOQGG/\n"+
"  %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^(GKReR3%^RESET%^%^RED%^%%s%^BOLD%^%^BLACK%^#3737(%%^RESET%^%^RED%^C %^RED%^OO%^BOLD%^%^BLACK%^CCGOsG\n"+
"    %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^ORQ#6sO%%67%%%%C%^RESET%^%^RED%^3%^BOLD%^%^BLACK%^%%3OsOC/\n"+
"    %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^%RQ#ssO6Cs%(t%%337%CO3O6\n"+
"     %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^eKR3GOss6C777t7336GGOG\n"+
"     %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^SS#sO6GCsC%73%%7%3Gs%\n"+
"     %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^sSRO6O6O6ss%C63C6sQe%\n"+
"      %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^BeOOsOGG66CC63C6CR\n"+
"        %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^OsOOOOGOO6CC6CC\n"+
"          %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^6OG66COs3636\n"+
"           %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^eOGOGss6%s\n"+
"             %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^OssCssR\n"+
"              %^RESET%^%^RED%^\\%^BOLD%^%^BLACK%^(s6@\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}
