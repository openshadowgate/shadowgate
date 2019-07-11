// /d/magic/symbols/talos_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^BLUE%^blue quartz%^RESET%^","%^YELLOW%^tchazar%^RESET%^","%^YELLOW%^pyrite%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^BLUE%^Talos%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","talos_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "                                %^RESET%^%^BLUE%^ @GS#K#QOS#@\n"+
"                                 Q(t((~//teS\n"+
"                                tQt^   @^%R\n"+
"                                KOtO   /(S\n"+
"                                @G/@  @/%@\n"+
" %^GREEN%^@%^BLUE%^                              #Ct7 (/3O\n"+
" %^GREEN%^7@O %^BLUE%^                          ^e7Q  B(C@\n"+
"  %^GREEN%^SQQ(%^BLUE%^                         @%(@  ((B\n"+
"  %^GREEN%^ROOsK@    %^BLUE%^                   Q(G  t~O   %^MAGENTA%^                           #R\n"+
" %^GREEN%^ @S%%(%G@  %^BLUE%^                  SC3@  /3C%^MAGENTA%^                           ^@GB\n"+
" %^GREEN%^ #eC(  ~tO#@   %^BLUE%^             /#7@  /7R   %^MAGENTA%^                      #Rs%(C\n"+
" %^GREEN%^ tG%(    /(GOR( %^BLUE%^            @et  G(66OQQR%^MAGENTA%^                  OKO3(//%@\n"+
"  %^GREEN%^ S37       ^(sQ#@   %^BLUE%^      /R6@   /7CG3S %^MAGENTA%^             S@eO7(/^(7@(%(\n"+
" %^GREEN%^  QC3       K/^/(GQ@@  %^BLUE%^    @O%3     ~ssS    %^MAGENTA%^     3BOSO%~~/^tSs /O73\n"+
" %^GREEN%^ ~GRGGO7     /@e(G6@  %^BLUE%^     K7~//^^t @OC      %^MAGENTA%^   @#s~// ~CQ     R(6O\n"+
"%^GREEN%^      ^e3/(  #C(CCR    %^BLUE%^    @@@@@@R/@@33   %^MAGENTA%^         RGsO        //~3#\n"+
"    %^GREEN%^ RQ7/@   //O@  %^BLUE%^             O%S~S@eGB  %^MAGENTA%^         @S(@     t(%tOK@\n"+
"%^GREEN%^  @eG%7/GQ~    7~~3s6Rt %^BLUE%^       /(s / CG@  %^MAGENTA%^           (RGO@   ^tS\n"+
"  %^GREEN%^   tROC(~^G@(   %//~3QB  %^BLUE%^    C(Ct7 @( %^MAGENTA%^     /O#@@#KSO%C%    # ~#\n"+
" %^GREEN%^          Q@O%~/   Bt%@  %^BLUE%^       Q3e@CR  %^MAGENTA%^    CK7(Q@@S/     Q@RC~(OR\n"+
" %^GREEN%^            /(~R  7(e(  %^BLUE%^        /7ROG   %^MAGENTA%^     @RtQ    (((3OeSeR@@@6\n"+
"  %^GREEN%^          @t//6# /Rts@   %^BLUE%^       OBO   %^MAGENTA%^      #RS7  6tS@@%\n"+
"           %^GREEN%^ tBBQs6(t%#sO%Q   %^BLUE%^     S7  %^MAGENTA%^      @K7~@   (7(@\n"+
"            %^GREEN%^      /S@#O376(OG   %^BLUE%^  6~ %^MAGENTA%^    ^@sC@s#@7//(t763R\n"+
"                     %^GREEN%^     3@@KR  %^BLUE%^ ^  %^MAGENTA%^  @OOC%%sSQ@@#%^\n";
   set_long(""+ldesc+""+tmp+"");
}
