// /d/magic/symbols/anhur_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^RED%^ruby%^RESET%^","%^YELLOW%^yellow topaz%^RESET%^","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hi%^CYAN%^r%^BLUE%^e%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^BOLD%^%^RED%^Anhur%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","anhur_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^BOLD%^%^BLUE%^                         /(GOs#####@K####esOG((\n"
"                    ~sS#@@@QS66%^RED%^ssssssssss%^BLUE%^66CQB@@@K6/\n"
"               /O6@@@KC%^RED%^ssssssssssssssssssssssss%^BLUE%^R@C6G(^\n"
"            (s#@R%^RED%^sssssssssssssssssssssssssssss%^BLUE%^666s##@@@Q6G\n"
"          OS@#%^RED%^sssssssssssssssssssssssssssssssssssssssss%^BLUE%^6#@@KG\n"
"        O@@C%^RED%^sssssssssssssssssssssssssssssssssssssssssssssss%^BLUE%^6@@O/\n"
"      (@@%^RED%^sssssssssssssssssssssssssss%^BLUE%^666OGGGGGG6666%^RED%^ssssssss%^BLUE%^66GG@@#3\n"
"     ^#@6%^RED%^ssssssssssssssssssss%^BLUE%^6O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BR6sOOO\n"
"     ^##%^RED%^sssssssssssssssss%^BLUE%^6G@@@@@@RB%^RED%^ssss%^BLUE%^RR@@@@@@@@@@@@@@@@@@@OC\n"
"      O@e%^RED%^sssssssssssssss%^BLUE%^@@@-- t@C%^RED%^sssssssss%^BLUE%^6s@@@@@@@@@@@@@@@@@@@Os\n"
"    %^RESET%^%^ORANGE%^O@t   %^BOLD%^%^BLUE%^@@ROOO66Os@@@B@  %^BLACK%^@@%^BLUE%^ @@%^RED%^sssssssssssss%^BLUE%^#@@@@@@@@@@@@@@@@@@@OC\n"
"%^RESET%^%^ORANGE%^  GR@    @@    %^BOLD%^%^BLUE%^^#6666%^RED%^sss%^BLUE%^6@@--@#6%^RED%^ssssssssssssss%^BLUE%^@@@@@@@@@@@@@@@@@@@@@KC\n"
"%^RESET%^%^ORANGE%^ s@       #      %^BOLD%^%^BLUE%^ @%^RED%^ssssssss%^BLUE%^66%^RED%^ssssssssssssssssss%^BLUE%^@@@@@@@@@@@@@@@@@@@@@@s\n"
"%^RESET%^%^ORANGE%^GR             %^BOLD%^%^BLUE%^ @K%^RED%^ssssssssssssssssssssssssssss%^BLUE%^Q@@@@@@@@@@@@@@@@@@@@@@@#G\n"
"%^RESET%^%^ORANGE%^6@               %^BOLD%^%^BLUE%^ /tR%^RED%^ssssssssssssssssssssssss%^BLUE%^Q@@@@@@@@@@@@@@@@@@@@@@@@@@3\n"
"%^RESET%^%^ORANGE%^6@                    %^BOLD%^%^BLUE%^K%^RED%^sssssssssssssssssss%^BLUE%^C#@@@@@@@@@@@@@@@@@@@@@@@@@@@@Q/\n"
"%^RESET%^%^ORANGE%^OB           (@(   7@  %^BOLD%^%^BLUE%^#%^RED%^sssssssssssss%^BLUE%^6#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@6\n"
" %^RESET%^%^ORANGE%^O7      Q6           %^BOLD%^%^BLUE%^(6%^RED%^sssssssssssssssss%^BLUE%^6QR@@@@@@@@@@@@@@@@@@@@@@@O/~~^\n"
"%^RESET%^%^ORANGE%^ /R%  /@@777@@@@QC   %^BOLD%^%^BLUE%^C#G%^RED%^ssssssssssssssssssssss%^BLUE%^66Q@@@@@@@@@@@@@@@@@@@6\n"
" %^RESET%^%^ORANGE%^ CKS/@3(GGG((    %^BOLD%^%^WHITE%^e@/////%^BOLD%^%^BLUE%^#Q6%^RED%^sssssssssssssssssssssss%^BLUE%^OB@@@@@@@@@@@@@@@@~\n"
" %^RESET%^%^ORANGE%^   G@@            %^BOLD%^%^WHITE%^6@///////%^BOLD%^%^BLUE%^@%^RED%^sssssssssssssssssssssssss%^BLUE%^6@@@@@@@@@@@@@@O\n"
"  %^RESET%^%^ORANGE%^    G             %^BOLD%^%^WHITE%^K////////%^BOLD%^%^BLUE%^BR6%^RED%^ssssssssssssssssssssssss%^BLUE%^O@@@@@@@@@@@@O\n"
"  %^WHITE%^                 6@/////////%^BOLD%^%^BLUE%^@@%^RED%^ssssssssssssssssssssssssss%^BLUE%^@@@@@@@@@@@G\n"
"  %^WHITE%^                6@~/////////%^BOLD%^%^BLUE%^@@6%^RED%^sssssssssssssssssssssssss%^BLUE%^G@@@@@@@@@G\n"
"  %^WHITE%^              OOB///////////%^BOLD%^%^BLUE%^@@%^RED%^ssssssssssssssssssssssssss%^BLUE%^6@@@@@@@@s\n"
"   %^WHITE%^           s#@///////////%^BOLD%^%^BLUE%^@s6%^RED%^sssssssssssssssssssssssssss%^BLUE%^G@@@@@@ss\n"
"   %^WHITE%^        CG@///////////////%^BOLD%^%^BLUE%^O@G%^RED%^ssssssssssssssssssssssssss%^BLUE%^@@@@@Os\n"
"   %^WHITE%^        O@@////////////////%^BOLD%^%^BLUE%^@@@6%^RED%^sssssssssssssssssssss%^BLUE%^6R@@@#s\n"
"   %^WHITE%^          7sR@Q////////////%^BOLD%^%^BLUE%^(@@@6%^RED%^ssssssssssssssssss%^BLUE%^S@@@@6~\n"
"    %^WHITE%^             Oe@@SQ////////%^BOLD%^%^BLUE%^@@@Q%^RED%^ssssssssssss%^BLUE%^66R@@@#s(^\n"
"     %^WHITE%^                (sOe@@@@%^BOLD%^%^BLUE%^QG@@@@####R@@@@@@@@G6s/\n"
"                            //Oss6666666ssOG//%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}
