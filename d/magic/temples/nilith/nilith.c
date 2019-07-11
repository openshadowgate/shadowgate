#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("nilith");
   set_name("%^ORANGE%^Temple of Nilith%^WHITE%^");
   set_short("%^ORANGE%^Temple of Nilith%^WHITE%^");
   set_long("%^ORANGE%^Temple of Nilith%^WHITE%^\n"
   "%^BOLD%^%^WHITE%^Towering vaulted ceilings adorned with murals draw your eyes "+
   "immediately upon entry, each arch of the ceiling a flying buttress of "+
   "%^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k "+
   "%^BOLD%^%^WHITE%^%^marble and inlaid with perfectly identical %^MAGENTA%^s%^BLUE%^p"+
   "%^CYAN%^i%^GREEN%^r%^ORANGE%^a%^RED%^l%^BOLD%^%^BLACK%^s %^BOLD%^%^WHITE%^%^of "+
   "silver and %^RED%^g%^BOLD%^e%^BOLD%^%^WHITE%^%^m%^BOLD%^s%^RESET%^%^GREEN%^t%^BOLD%^o"+
   "%^RESET%^%^BLUE%^n%^MAGENTA%^e%^BOLD%^s%^BOLD%^%^WHITE%^%^. Each mural shows a step "+
   "within the evolution of undead, with a single central mural showing a archlich, with its "+
   "parchment white skin and nigh bloodless expression placid. As you return your eyes to ground "+
   "level, mentally boggling over the upper arrangement, you are instantly brought into shock at "+
   "the lovely %^BOLD%^%^BLACK%^g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^BOLD%^%^WHITE%^%^and "+
   "%^BOLD%^%^BLACK%^black %^BOLD%^%^WHITE%^%^inlays of the floor, geometric and gem-riddled, the "+
   "pattern is intense and mesmerizing. Pews have been laid out on both sides of a central isle, "+
   "thirty in all, some having undead and living worshipers seated silently. At the apex of the "+
   "central isle is a sarcophagus. This incredible and immense detail, this stone burial dressing "+
   "possesses an image of a %^BOLD%^%^BLACK%^black-skinned %^BOLD%^%^WHITE%^%^and %^BOLD%^%^WHITE%^"+
   "white-haired %^BOLD%^%^WHITE%^%^woman of incredible beauty embossed upon its lid. Precious "+
   "stones are set in the base of the sarcophagus, and piles of %^BOLD%^c%^BOLD%^%^WHITE%^%^o"+
   "%^BOLD%^i%^BOLD%^%^WHITE%^%^n%^BOLD%^s %^BOLD%^%^WHITE%^%^are scattered at it's feet. There are "+
   "goblets of fine brass and plates of complex potions of unknown use. Behind the altar on the wall "+
   "is is a shield inscribed with a skeletal hand holding a calla lily. On an elegant, %^WHITE%^s"+
   "%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r %^BOLD%^%^WHITE%^%^scroll is engraved the charge "+
   "of Nilith.%^WHITE%^\n");
   set_smell("default","The scent of blood and decay assaults your senses");
   set_listen("default","You hear the faint sounds of distant battles");
   set_exits(([
  "out" : "/d/dagger/road/p8"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^ORANGE%^Seek immortal undeath at all costs. Mortals are born to serve the unliving gods of this realm, and to the elite, become them. Trample all who stand in your way. Ravage the lands and take all you desire. Avoid the path of light, for the eternal shadow of undeath is your only prize, and seek to undo the lives of others upon the battlefield, every fallen foe is a step on the path to your eternal stride in the world of undeath.%^RESET%^

CHARGE
   );
   return 1;
}
