// /d/magic/symbols/malar_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^ORANGE%^ti%^YELLOW%^g%^RESET%^%^ORANGE%^er's e%^YELLOW%^y%^RESET%^%^ORANGE%^e%^RESET%^","%^GREEN%^bl%^RED%^oo%^GREEN%^dstone%^RESET%^","%^YELLOW%^sanidine%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^BOLD%^%^RED%^Malar%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","malar_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^RESET%^%^RED%^               #@\n"+
"                ##@\n"+
"                @@##\n"+
"                 @@#@@\n"+
"                  @#@#@\n"+
"      @#@#@#@#@   @@@@\n"+
"          @@@@@@^ C#@@@\n"+
"            ^@@@#@ @@@@@\n"+
"  /C@@@@C^    @@@@@@@@@#@\n"+
"     C@@@@@/@@ @@@@@@@@@@@@\n"+
"         @@@@@@ @@@@@@@@@@#\n"+
"  @         @@@@ @@@@@#@@C\n"+
"  @@          #@@@@@@@@@@@@\n"+
" @@@           @@ @@@@@@@@@\n"+
" #@@          @@@@ @@@@@@@@#\n"+
" #@@#        @@@@@ @@@@@@@@##\n"+
" @@@@@            @@@@@@@@@@@\n"+
" ##@@@@@@@@@@@@@@@@@@@@@@@@@@e\n"+
" #@@@@@@@@@@@@@@@@@@@@#@@@@ eR\n"+
"  @@@@@@@@@@@@@@@@@@@@@@@@@\n"+
"  #@@@@@@@@@@@@@@@@@@@@@@@@\n"+
"  @@@@@@@@@@@@@@@@@@@@@@@@#\n"+
"  @@#^   @@@@@@@@@@@@@@@@@#\n"+
"  C#     @@@@@@@@@@@@#@@@@R\n"+
"         @@@@@@@@@@@@@ @@R\n"+
"         @@@@@@@@@@@@@R #\n"+
"        #@@@@@@@@@@@@@#e\n"+
"       #@@@@@@@@@@@@@@@@\n"+
"      e@@@#@@@@@@@@@@@@@G\n"+
"       @@@@@@@@@@@@@@@@@@G\n"+
"      e@@@@@@@@@@@@@@@@@@@G\n"+
"      @@@@@@@@@@@@@@@@@@@@#\n"+
"     @#@@@@@@@@@@@@@@@@@@@@e\n"+
"    e@@@@@@@@@@@@@@@@#C^//C#R\n"+
"    #@@@@@@@#@#%\n"+
"    @@@@@@@#e\n"+
"   @#@##@\n"+
"   ##^\n";
   set_long(""+ldesc+""+tmp+"");
}
 
