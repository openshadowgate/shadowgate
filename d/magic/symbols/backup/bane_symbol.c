// /d/magic/symbols/bane_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^GREEN%^emerald%^RESET%^","%^BOLD%^%^RED%^ruby%^RESET%^","%^BOLD%^%^BLACK%^bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck sapphire%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^BLACK%^Bane%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","bane_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^GREEN%^              000%^BOLD%^XX%^RESET%^%^GREEN%^0 00%^BOLD%^X%^RESET%^%^GREEN%^000%^BOLD%^ XXX%^RESET%^%^GREEN%^000\n"+
"               00%^BOLD%^XX%^RESET%^%^GREEN%^0 00%^BOLD%^X%^RESET%^%^GREEN%^000 %^BOLD%^XX%^RESET%^%^GREEN%^000\n"+
"                0%^BOLD%^XX%^RESET%^%^GREEN%^0  0%^BOLD%^X%^RESET%^%^GREEN%^00  %^BOLD%^XX%^RESET%^%^GREEN%^00\n"+
"                00%^BOLD%^X%^RESET%^%^GREEN%^0  0%^BOLD%^X%^RESET%^%^GREEN%^0   %^BOLD%^XX%^RESET%^%^GREEN%^00\n"+
"                 0%^BOLD%^X%^RESET%^%^GREEN%^0  0%^BOLD%^X%^RESET%^%^GREEN%^0   %^BOLD%^XX%^RESET%^%^GREEN%^0\n"+
"               %^BOLD%^%^BLACK%^@@%^GREEN%^0%^BOLD%^X%^RESET%^%^GREEN%^0%^BOLD%^%^BLACK%^@@%^RESET%^%^GREEN%^0%^BOLD%^X%^RESET%^%^GREEN%^0%^BOLD%^%^BLACK%^@@%^GREEN%^ X%^RESET%^%^GREEN%^0\n"+
"              %^BOLD%^%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@\n"+
"   %^RESET%^%^GREEN%^   0     %^BOLD%^%^BLACK%^  @@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@\n"+
"      %^RESET%^%^GREEN%^000  %^BOLD%^%^BLACK%^   @@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@\n"+
"      %^GREEN%^X%^RESET%^%^GREEN%^00000   %^BOLD%^%^BLACK%^@@%^RESET%^%^GREEN%^0%^BOLD%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@@%^GREEN%^X%^BLACK%^@@@\n"+
"      %^GREEN%^XXXX%^RESET%^%^GREEN%^000000%^BOLD%^XXXX%^BLACK%^@@%^GREEN%^XX%^BLACK%^@@@%^GREEN%^XX%^BLACK%^@@@\n"+
" %^GREEN%^     XXXXXXXXXXXXXXXXXXXXXXX%^BLACK%^@@%^RESET%^%^GREEN%^0000000\n"+
"      00000000%^BOLD%^%^BLACK%^@@@@@@@%^GREEN%^XXXXXXXXXXXXXXXXX\n"+
"           %^BLACK%^  @@@@@@@@@%^GREEN%^XXXX%^RESET%^%^GREEN%^00000000%^BOLD%^XXXX\n"+
"            %^BLACK%^@@@@@%^RESET%^%^GREEN%^00000%^BOLD%^XX%^RESET%^%^GREEN%^0000%^BOLD%^%^BLACK%^@@@ %^RESET%^%^GREEN%^ 0000%^BOLD%^X\n"+
"            %^BLACK%^ @@@@@@%^RESET%^%^GREEN%^00000000%^BOLD%^%^BLACK%^@@@@  %^RESET%^%^GREEN%^   00\n"+
"              %^BOLD%^%^BLACK%^@@@@@@@@@@@@@@@@  %^RESET%^%^GREEN%^     0\n"+
"         %^BOLD%^%^BLACK%^      @@@@@@@@@@@@@@\n"+
"                @@@@@@@     \\\\\n"+
"               @@@@@@@@@@@@@@@\n"+
"              @@@@@@@@@@@    \\\\\n"+
"              @@@@@@@@@@@@@@@@@\n";
   set_long(""+ldesc+""+tmp+"");
}

