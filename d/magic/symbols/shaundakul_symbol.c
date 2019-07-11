// /d/magic/symbols/shaundakul_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^BOLD%^%^BLUE%^blue amethyst%^RESET%^","%^MAGENTA%^purple jasper%^RESET%^","%^BOLD%^%^BLACK%^lodestone%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
int isset;
string GOD = "%^RESET%^%^CYAN%^Shaundakul%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","helm_holy_symbol",jewelry,gem+" "+jewelry}));
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
   tmp = "%^MAGENTA%^                              @\n"+
"                            @   @\n"+
"         @\n"+
"                           @       %^BOLD%^%^WHITE%^@@ @%^RESET%^\n"+
"       %^MAGENTA%^@    @ R               %^BOLD%^%^WHITE%^@@@ B%^RESET%^\n"+
"           %^MAGENTA%^@    @  @       @  %^BOLD%^%^WHITE%^R  @@    @ B%^RESET%^\n"+
"       %^MAGENTA%^@      @           @  %^BOLD%^%^WHITE%^B    @    @  @%^RESET%^  %^CYAN%^                    @\n"+
"         %^MAGENTA%^@  @       @   @    %^BOLD%^%^WHITE%^@    @    @   @%^RESET%^  %^CYAN%^                 @   @\n"+
"                          %^BOLD%^%^WHITE%^@@@R    @    @   R%^RESET%^      %^CYAN%^            @\n"+
"    %^CYAN%^@ @                  %^BOLD%^%^WHITE%^@   @    @    @   @%^RESET%^     %^CYAN%^       @       @  @\n"+
"              %^CYAN%^    @      %^BOLD%^%^WHITE%^R   @    @    @   @%^RESET%^\n"+
"      %^CYAN%^ R                 %^BOLD%^%^WHITE%^@   @    @    @   @@%^RESET%^  %^CYAN%^             @     @\n"+
"                        %^BOLD%^%^WHITE%^BB   @    @    @   @B%^RESET%^ %^CYAN%^              B   @\n"+
"    %^CYAN%^  @R@ @             %^BOLD%^%^WHITE%^@@   @    @    @   @@%^RESET%^  %^CYAN%^                @\n"+
"  %^CYAN%^ @ @     @       @B   %^BOLD%^%^WHITE%^@    @    @    @   @R @ @%^RESET%^\n"+
" %^CYAN%^ @ R        @          %^BOLD%^%^WHITE%^@    B   @@    @   @B @ @%^RESET%^              %^CYAN%^B\n"+
"    %^CYAN%^                @   %^BOLD%^%^WHITE%^@   @B              B@@ @%^RESET%^\n"+
" %^CYAN%^  @         @          %^BOLD%^%^WHITE%^B                   @@  @%^RESET%^   %^MAGENTA%^    @@   \n"+
"     %^CYAN%^ @      @ B   @    %^BOLD%^%^WHITE%^@                   @@  @%^RESET%^ %^MAGENTA%^     @\n"+
"      %^CYAN%^         @ @      %^BOLD%^%^WHITE%^B                       @%^RESET%^    %^MAGENTA%^   @ %^CYAN%^       @\n"+
"    %^CYAN%^@ @                 %^BOLD%^%^WHITE%^B                       @%^RESET%^        %^MAGENTA%^ @%^CYAN%^     @\n"+
"        %^CYAN%^     @          %^BOLD%^%^WHITE%^@                       @%^RESET%^  %^MAGENTA%^      @%^CYAN%^      @ @\n"+
"    %^CYAN%^ @ @@               %^BOLD%^%^WHITE%^@                      @@%^RESET%^\n"+
"   %^CYAN%^ @       @           %^BOLD%^%^WHITE%^@                      @%^RESET%^   %^MAGENTA%^  @ %^CYAN%^        @\n"+
"               %^CYAN%^@@       %^BOLD%^%^WHITE%^@                      @%^RESET%^   %^MAGENTA%^@\n"+
"                         %^BOLD%^%^WHITE%^@                    @%^RESET%^\n"+
"          %^MAGENTA%^ @ @           %^BOLD%^%^WHITE%^@                   @%^RESET%^   %^MAGENTA%^  B  %^CYAN%^       @\n"+
"     %^MAGENTA%^    @     @   @      %^BOLD%^%^WHITE%^@                 R%^RESET%^            %^CYAN%^B\n"+
"       %^MAGENTA%^              @     %^BOLD%^%^WHITE%^@               @%^RESET%^     %^MAGENTA%^@ @ %^CYAN%^  @@\n"+
"      %^MAGENTA%^  @      @  B  @ B    %^BOLD%^%^WHITE%^@             @%^RESET%^    %^MAGENTA%^@   @\n"+
"      %^MAGENTA%^  @         @ @  @    %^BOLD%^%^WHITE%^@             @%^RESET%^ %^MAGENTA%^B           %^CYAN%^@  @\n"+
"        %^MAGENTA%^             @      %^BOLD%^%^WHITE%^@             @%^RESET%^                    %^CYAN%^B\n"+
"     %^MAGENTA%^    @  @        @      %^BOLD%^%^WHITE%^@             @%^RESET%^         %^CYAN%^ @\n"+
"        %^MAGENTA%^      @            %^BOLD%^%^WHITE%^@@             @%^RESET%^  %^CYAN%^                B B\n"+
"           %^MAGENTA%^   @                                       %^CYAN%^ @     @%^RESET%^\n";
   set_long(""+ldesc+""+tmp+"");
   isset = 1;
}
