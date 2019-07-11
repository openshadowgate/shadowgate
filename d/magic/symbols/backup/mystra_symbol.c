// /d/magic/symbols/mystra_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^BLUE%^star sapphire%^RESET%^","%^BOLD%^%^BLUE%^b%^WHITE%^e%^BLUE%^l%^WHITE%^i%^BLUE%^j%^WHITE%^u%^BLUE%^r%^WHITE%^i%^BLUE%^l%^RESET%^","%^RED%^r%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^RESET%^%^CYAN%^b%^BOLD%^%^BLUE%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^ tourmaline%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^BLUE%^Mystra%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","mystra_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^BOLD%^%^MAGENTA%^                    (GR@@RRQs%/\n"+
"               ~@RQR@@@QSS66R@@#e#R/\n"+
"            @#R@C                (7@QQS\n"+
"          R#@            %^WHITE%^|%^MAGENTA%^          %CRGR\n"+
"        G#B#            %^CYAN%^\\%^WHITE%^|%^CYAN%^/%^MAGENTA%^            %@#C\n"+
"       @S@t           %^WHITE%^-------%^MAGENTA%^           (GBB\n"+
"      RQQ               %^CYAN%^/%^WHITE%^|%^CYAN%^\\%^MAGENTA%^             ~/@#/\n"+
"    te@%                 %^WHITE%^|%^MAGENTA%^                 ~KGQ\n"+
"    R@t       %^WHITE%^|%^RED%^          6(    %^WHITE%^       | %^MAGENTA%^    tBS%\n"+
"   RBC       %^CYAN%^\\%^WHITE%^|%^CYAN%^/%^RED%^         s@t^    %^CYAN%^    \\%^WHITE%^|%^CYAN%^/  %^MAGENTA%^    @Q^\n"+
"  %GQ/     %^WHITE%^------- %^RED%^      CBsR~  %^WHITE%^   ------- %^MAGENTA%^   (##\n"+
"  K@/        %^CYAN%^/%^WHITE%^|%^CYAN%^\\ %^RED%^       eR@#@      %^CYAN%^  /%^WHITE%^|%^CYAN%^\\  %^MAGENTA%^     G6(\n"+
" OG%          %^WHITE%^|%^RED%^         @BR@@      %^WHITE%^   |  %^MAGENTA%^      (QK\n"+
" @#                   %^RED%^S#@@#O %^MAGENTA%^                   Rs\n"+
" RB       %^WHITE%^|%^RED%^         B@@BB@/             %^WHITE%^ | %^MAGENTA%^     #%\n"+
" KK    %^CYAN%^  \\%^WHITE%^|%^CYAN%^/%^RED%^      @B@K @Kt              %^CYAN%^\\%^WHITE%^|%^CYAN%^/ %^MAGENTA%^    R%\n"+
" RR    %^WHITE%^-------    %^RED%^@O@S@ @#B/    %^WHITE%^      -------  %^MAGENTA%^ K6\n"+
" @@      %^CYAN%^/%^WHITE%^|%^CYAN%^\\ %^RED%^      @@~O#RCtBe          %^CYAN%^ /%^WHITE%^|%^CYAN%^\\ %^MAGENTA%^    RG\n"+
" RQ       %^WHITE%^|          %^RED%^Q@S K@R/@ee         %^WHITE%^|  %^MAGENTA%^    RQ\n"+
" ^e6         %^WHITE%^  |    %^RED%^  @#B  #R# (ee         %^MAGENTA%^    (77\n"+
"  eK          %^CYAN%^\\%^WHITE%^|%^CYAN%^/ %^RED%^  @##R^@R##  e#    %^WHITE%^| %^MAGENTA%^        SS\n"+
"   @R       %^WHITE%^------- %^RED%^@#R@(@RR#/^RK%  %^CYAN%^\\%^WHITE%^|%^CYAN%^/%^MAGENTA%^       G6\n"+
"   ^sS        %^CYAN%^/%^WHITE%^|%^CYAN%^\\  %^RED%^#R/@K@@K~ RK#( %^WHITE%^-------   %^MAGENTA%^ s%t\n"+
"    %ss       %^WHITE%^ |   %^RED%^eG%@B@SRS RKeKQ %^CYAN%^ /%^WHITE%^|%^CYAN%^\\%^MAGENTA%^    tte\n"+
"     ^s#       %^RED%^ eG# RRRO#R# RR#S     %^WHITE%^|%^MAGENTA%^     G%/\n"+
"       KS%   %^RED%^e6QeK RR#O@#Q@ @#Q %^MAGENTA%^         ((K\n"+
"        sQB^%^RED%^#6SeG/#QRQ QQGQ %RKs %^MAGENTA%^       G((\n"+
"          RO6%^RED%^OGQ# SQQ# SQeG  O#K@     %^MAGENTA%^C%7\n"+
"            6@%SR %^RED%^#SS# eGOOC  7OGO%^MAGENTA%^677G\n"+
"                ^eSO3OK#S3%3GGOGKt\n"+
"                       ~7%%(\n";
   set_long(""+ldesc+""+tmp+"");
}
