#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^CYAN%^aquamarine%^RESET%^","%^BOLD%^%^BLUE%^blue topaz%^RESET%^","%^CYAN%^la%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^is %^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^az%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^li%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^CYAN%^Auppenser%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","auppenser_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^ORANGE%^::::::::::%^CYAN%^@#OS#@S@@@#####SSS#O77%^ORANGE%^:::::::::::::::::::::::::::\n"+
"%^ORANGE%^::::::%^CYAN%^#@@@@@@@(%^ORANGE%^:::::::::%^CYAN%^@#@S###S##%^ORANGE%^:::::::::::::::::::::::::\n"+
"%^ORANGE%^:::%^CYAN%^S####@%^ORANGE%^:::::::::::::::::::::%^CYAN%^@@S###OO(///:/:(%^ORANGE%^:::::::::::::\n"+
"%^ORANGE%^:%^CYAN%^S@@@%^ORANGE%^:::::::::::::::::::::::::::::%^CYAN%^/#@#@##CSC(O7(((%^ORANGE%^:::::::::\n"+
"%^CYAN%^S#@%^ORANGE%^::::::::::::::::::::::::::::::::::::%^CYAN%^(@@@@@####SS#S#C%^ORANGE%^::::\n"+
"%^CYAN%^7OO%^ORANGE%^:::::::::::%^CYAN%^7OCOCCOS(%^ORANGE%^:::::::::::::::::::::::::%^CYAN%^7O@@@@@@@&&\n"+
"%^CYAN%^O##%^ORANGE%^::::::%^CYAN%^(((/(COOOSSOCC7((/7(%^ORANGE%^::::::::::::::::::::::::%^CYAN%^C(S@@%^ORANGE%^:\n"+
"%^CYAN%^O#@%^ORANGE%^:::%^CYAN%^@SO#S@SSOOC77(77COOO@C(/((S%^ORANGE%^::::::::::::::::::::%^CYAN%^COS%^ORANGE%^:::\n"+
"%^CYAN%^OSOOOO##@@%^ORANGE%^::%^BOLD%^%^CYAN%^#####S#@###OS#%^RESET%^%^ORANGE%^::%^CYAN%^#O##O:(:(C77%^ORANGE%^:::::::::::%^CYAN%^@C(%^ORANGE%^:::::\n"+
"%^CYAN%^(OCOOS#%^ORANGE%^::::::%^BOLD%^%^CYAN%^####@###@#@@%^RESET%^%^ORANGE%^:::::::%^CYAN%^CC#@SSCCCO((7OCOOOOS#%^ORANGE%^::::::\n"+
"%^CYAN%^(###SSS#S(%^ORANGE%^:::::%^BOLD%^%^CYAN%^7SO#OS##%^RESET%^%^ORANGE%^:::::%^CYAN%^#S##@@@#@#@@#SS@##O###%^ORANGE%^:::::::::\n"+
"%^ORANGE%^::::::::%^CYAN%^@##OC7%^ORANGE%^:::::::::%^CYAN%^//(OO##@%^ORANGE%^::::::::::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::%^CYAN%^7#@@@@@@@#@##SS7#%^ORANGE%^:::::::::::::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::::::%^CYAN%^C(S7####O@@#@O%^ORANGE%^::::::::::::::::::::::::::::::\n"+
"%^ORANGE%^::::::::::::::%^CYAN%^CSO@##%^ORANGE%^:::%^CYAN%^SS##@C%^ORANGE%^::::::::::::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::::%^CYAN%^7@##@##%^ORANGE%^:::%^CYAN%^C#####(%^ORANGE%^:::::::::::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::%^CYAN%^OOOO@@##@%^ORANGE%^::::%^CYAN%^#S#@##7%^ORANGE%^::::::::::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::%^CYAN%^(O#OO###@%^ORANGE%^::::::%^CYAN%^#S##@S(%^ORANGE%^::::::::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::::%^CYAN%^@@#####%^ORANGE%^::::::::%^CYAN%^(7## /%^ORANGE%^:::::::::::::::::::::::::\n"+
"%^ORANGE%^::::::::::::::%^CYAN%^##S##@%^ORANGE%^:::::::::%^CYAN%^/OO@C((/:%^ORANGE%^:::::::::::::::::::::\n"+
"%^ORANGE%^:::::::::::::::%^CYAN%^C#O#%^ORANGE%^::::::::::::%^CYAN%^(#@##SO@%^ORANGE%^:::::::::::%^CYAN%^(O#/7%^ORANGE%^::::\n"+
"%^ORANGE%^:::::::::::::::%^CYAN%^S#S#%^ORANGE%^:::::::::::::::%^CYAN%^@S#@SS7O%^ORANGE%^::::::::%^CYAN%^COC#S#%^ORANGE%^:::\n"+
"%^ORANGE%^:::::::::::::::%^CYAN%^CS7%^ORANGE%^::::::::::::::::::::%^CYAN%^@S###77C77SCSSS@@%^ORANGE%^::::\n"+
"%^ORANGE%^:::::::::::::::::::::::::::::::::::::::::::%^CYAN%^S#SOSSCS#/%^ORANGE%^::::::%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
}

