// /d/magic/symbols/kelemvor_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^GREEN%^chalcedony%^RESET%^","%^BOLD%^%^BLACK%^hematite%^RESET%^","%^ORANGE%^ti%^YELLOW%^g%^RESET%^%^ORANGE%^er's e%^YELLOW%^y%^RESET%^%^ORANGE%^e%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^BLACK%^Kelemvor%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","kelemvor_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^YELLOW%^                   #####       %^WHITE%^%^ %(\n"+
"%^YELLOW%^               ###########  %^WHITE%^/(%S((@@@QSC^  %^YELLOW%^  #########\n"+
"             ###       ###%^WHITE%^@@%^YELLOW%^#%^WHITE%^@@%^YELLOW%^#%^WHITE%^@@%^YELLOW%^#%^WHITE%^@@@%^YELLOW%^#%^WHITE%^@@%^YELLOW%^########   ####\n"+
"        ##  ##           #%^WHITE%^@@%^YELLOW%^#%^WHITE%^R(%^YELLOW%^#%^WHITE%^@@%^YELLOW%^#%^WHITE%^@@%^YELLOW%^#%^WHITE%^@@%^YELLOW%^#######       ##\n"+
"        ####              %^WHITE%^/s(7 %e /3tOGC %^YELLOW%^               ##   ##\n"+
"         ##                %^WHITE%^/eO eO ~Q(G7/   %^YELLOW%^             ######\n"+
"      %^RESET%^   /\\    %^BOLD%^             /Q#@%(Ge #  %^YELLOW%^                   ##\n"+
"    %^RESET%^    / |\\  %^BOLD%^               6s@(BRe@S   %^RESET%^                 /|\\\n"+
"       /  | \\         %^BOLD%^       /R@Q@KG@%  %^RESET%^                 / | \\\n"+
"      /   |  \\              %^BOLD%^  C#6@@KSO %^RESET%^                 /  |  \\\n"+
"     /    |   \\             %^BOLD%^  t#@#@@R(  %^RESET%^               /   |   \\\n"+
"    /     |    \\             %^BOLD%^ /6OS(@6(   %^RESET%^             /    |    \\\n"+
"   /      |     \\            %^BOLD%^  S@@ e@/      %^RESET%^         /     |     \\\n"+
"  /       |      \\          %^BOLD%^   3@S 7@/     %^RESET%^         /      |      \\\n"+
" /        |       \\           %^BOLD%^ /#G (B~         %^RESET%^    /       |       \\\n"+
"/         |        \\         %^BOLD%^  ^GO /OG     %^RESET%^       /        |        \\\n"+
"%^YELLOW%^@@@@@@@@@@@@@@@@@@@@@      %^WHITE%^    /63  6s    %^RESET%^       /         |         \\\n"+
"%^YELLOW%^ @@@@@@@@@@@@@@@@@@@  %^WHITE%^         /((  6O      %^YELLOW%^     @@@@@@@@@@@@@@@@@@@@@\n"+
" %^YELLOW%^    @@@@@@@@@@@@         %^WHITE%^     %((  s(     %^YELLOW%^        @@@@@@@@@@@@@@@@@\n"+
"   %^YELLOW%^    @@@@@@@       %^WHITE%^          7(%  6/ %^YELLOW%^               @@@@@@@@@@@@\n"+
"  %^YELLOW%^        @           %^WHITE%^         7(7 (%   %^YELLOW%^                 @@@@@@\n"+
"                   %^WHITE%^            (~( (C     %^YELLOW%^                 @@\n"+
"%^WHITE%^                               ((( (C\n"+
"                               t%( (G\n"+
"                               (%% eK\n"+
"                               (77 SQ\n"+
"                               3%t O#\n"+
"                               7%OS66\n"+
"                               (7e%B7\n"+
"                               (6K~S7\n"+
"                               ^(%(\n"+
"                               %(\n";
   set_long(""+ldesc+""+tmp+"");
}

