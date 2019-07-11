//Temple of Ryorik - created by Kassius 10/18
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(4);
   set_indoors(0);
   set_temple("ryorik");
   set_name("Shrine of Ryorik");
   set_short("%^RESET%^%^CYAN%^Shrine of Ryorik%^RESET%^");
   set_long("%^RESET%^%^%^CYAN%^Shrine of Ryorik%^RESET%^\n"
"%^BOLD%^%^WHITE%^A vast swath of land opens here, a fr%^CYAN%^i%^WHITE%^g%^CYAN%^i%^WHITE%^d t%^CYAN%^u%^WHITE%^n%^CYAN%^d%^WHITE%^r%"+
"^CYAN%^a %^WHITE%^at the northernmost point is a %^RESET%^%^CYAN%^blur %^BOLD%^%^WHITE%^through the %^RESET%^%^CYAN%^e%^BOLD%^n%^RESE"+
"T%^%^CYAN%^d%^BOLD%^l%^RESET%^%^CYAN%^e%^BOLD%^ss %^WHITE%^s%^CYAN%^n%^WHITE%^o%^CYAN%^w%^WHITE%^-s%^CYAN%^t%^WHITE%^or%^CYAN%^m%^WHI"+
"TE%^s. Directly to the south is the complete opposite, %^RED%^mirages %^WHITE%^and %^RESET%^%^ORANGE%^oasis %^BOLD%^%^WHITE%^blend to"+
"gether in the %^RESET%^%^RED%^grueling heat %^BOLD%^%^WHITE%^of a %^RESET%^%^ORANGE%^desert%^BOLD%^%^WHITE%^. A %^RESET%^rocky, shore"+
"line %^BOLD%^travels the eastern edge of the land, which seems to border a massive %^RESET%^%^CYAN%^o%^BOLD%^c%^BLUE%^e%^RESET%^%^BLU"+
"E%^a%^CYAN%^n%^BOLD%^%^WHITE%^, waves clashing against it as a constant %^RESET%^%^MAGENTA%^breeze %^BOLD%^%^WHITE%^flows from the ea"+
"st towards the %^BLACK%^mountainous %^WHITE%^west. A %^MAGENTA%^breathtaking %^WHITE%^mountain range standfast on the western border "+
"with their %^CYAN%^s%^WHITE%^no%^CYAN%^w%^WHITE%^-c%^CYAN%^o%^WHITE%^ve%^CYAN%^r%^WHITE%^e%^CYAN%^d %^WHITE%^p%^CYAN%^e%^WHITE%^a%^CY"+
"AN%^ks %^WHITE%^dipping into %^RESET%^%^ORANGE%^rich valleys %^BOLD%^%^WHITE%^that fade quickly from view. The four unique areas bein"+
"g so close together cause many %^BLACK%^n%^GREEN%^a%^BLACK%^t%^GREEN%^u%^BLACK%^r%^GREEN%^a%^BLACK%^l p%^GREEN%^h%^BLACK%^e%^GREEN%^n"+
"%^BLACK%^o%^GREEN%^m%^BLACK%^e%^GREEN%^n%^BLACK%^a %^WHITE%^that %^RESET%^%^CYAN%^ebb %^BOLD%^%^WHITE%^and %^CYAN%^flow%^WHITE%^, dan"+
"cing around each other, no element ever gaining the upper hand. The direct center of the land sits an altar that shifts from a %^RESE"+
"T%^mammoth granite rock %^BOLD%^hewn from the %^BLACK%^bones %^WHITE%^of the %^RESET%^%^ORANGE%^world %^BOLD%^%^WHITE%^to a %^RESET%^"+
"%^RED%^molten pillar %^BOLD%^%^WHITE%^of %^RED%^fire %^WHITE%^and %^RED%^m%^ORANGE%^a%^RED%^gm%^ORANGE%^a %^WHITE%^only to be sucked "+
"up into a vast %^BLACK%^m%^BLUE%^a%^BLACK%^e%^BLUE%^l%^BLACK%^s%^BLUE%^t%^BLACK%^r%^BLUE%^o%^BLACK%^m %^WHITE%^of %^RESET%^%^CYAN%^wa"+
"ter %^BOLD%^%^WHITE%^and %^CYAN%^ice%^WHITE%^. The only constant is a glowing image of a %^CYAN%^scimitar %^WHITE%^suspended above th"+
"e altar and the %^BLACK%^b%^GREEN%^re%^BLACK%^ath%^GREEN%^l%^BLACK%^e%^GREEN%^ss %^BLACK%^s%^GREEN%^i%^BLACK%^l%^GREEN%^e%^BLACK%^n%^"+
"GREEN%^ce %^WHITE%^that envelops the immediate area around it.");
   set_smell("default","The air is filled with natural scents that mingle with fresh water and a hint of the seas.");
   set_listen("default","The commotion and noise of the natural disasters fades as you approach the altar.");
   set_exits(([
      "out": "/d/dagger/Torm/road/path50",
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
%^BOLD%^Ryorik charges his followers with this message:%^RESET%^%^CYAN%^
Feel the freedom of the natural world. Run free like the wind, obey your own moral code as devoutly as the stone. Care little for taming the elements, but do not exploit elements in a way that would harm or alter their natural state. Help others see that the storms are not to be bound and tamed, but to be unleashed, shared and respected. Let those who would manipulate and abuse them feel the fiery or icy touchy of true elemental power. Fear not natural, elemental destruction as it is the basis for growth and life.
CHARGE
   );
   return 1;
}

