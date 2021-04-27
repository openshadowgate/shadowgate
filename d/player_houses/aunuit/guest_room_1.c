//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

void create(){
   ::create();
   set_name("Guest room");
   set_short("%^BOLD%^%^BLACK%^Guest room%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Richly decorated with fine, "
      "expensive materials this bedroom belongs to someone "
      "with exquisite taste. A spacious %^RESET%^%^ORANGE%^"
      "canopy bed %^BOLD%^%^BLACK%^dominates the center of "
      "the room; layers of %^RESET%^%^MAGENTA%^m%^RED%^a"
      "%^BOLD%^%^MAGENTA%^u%^RESET%^%^RED%^v%^MAGENTA%^e "
      "%^BOLD%^%^BLACK%^curtains shroud the bed in %^RESET%^"
      "%^MAGENTA%^mystery%^BOLD%^%^BLACK%^. The walls and "
      "ceiling are lined with rich, %^RESET%^%^ORANGE%^darkwood "
      "paneling%^BOLD%^%^BLACK%^ and the floor is beautiful "
      "bla%^RESET%^c%^BOLD%^%^BLACK%^k m%^WHITE%^a%^BLACK%^rbl"
      "%^RESET%^e %^BOLD%^%^BLACK%^that has been buffed to a "
      "%^WHITE%^m%^RESET%^i%^BOLD%^%^WHITE%^r%^BLACK%^r%^RESET%^o"
      "%^BOLD%^%^WHITE%^r%^BLACK%^-like sheen. %^RESET%^%^RED%^"
      "F%^BOLD%^%^ORANGE%^i%^RED%^r%^RESET%^%^RED%^e %^BOLD%^"
      "%^BLACK%^cr%^RED%^a%^BLACK%^ckles in the hearth against "
      "the western wall. For warmth and comfort a shaggy "
      "%^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^te rug %^BLACK%^"
      "covers much of the floor. Pushed against the eastern "
      "wall is a tall %^RESET%^%^ORANGE%^armoire%^BOLD%^%^BLACK%^, "
      "a full-length %^WHITE%^m%^CYAN%^i%^RESET%^r%^BOLD%^%^WHITE%^r"
      "%^RESET%^o%^BOLD%^%^WHITE%^r %^BLACK%^stands beside it. At "
      "the foot of the bed is a sturdy %^RESET%^%^ORANGE%^bench "
      "%^BOLD%^%^BLACK%^covered by a %^RESET%^%^MAGENTA%^m%^RED%^a"
      "%^BOLD%^%^MAGENTA%^u%^RESET%^%^RED%^v%^MAGENTA%^e %^BOLD%^"
      "%^BLACK%^velvet cushion.%^RESET%^\n");
   set_listen("default","%^BOLD%^%^BLACK%^Except for the occasional crackle from the fireplace, the room is quiet.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^The faint scent of a heady perfume mingles with the rich smell of wood burning wood.%^RESET%^");
   set_items(([
      "bench" : "%^BOLD%^%^BLACK%^This well-built %^RESET%^%^ORANGE%^"
         "bench %^BOLD%^%^BLACK%^rests at the foot of the %^RESET%^"
         "%^MAGENTA%^shrouded %^BOLD%^%^BLACK%^bed. Slender legs with "
         "clawed feet support the well-balanced piece. Delicate "
         "%^RESET%^%^MAGENTA%^m%^RED%^a%^BOLD%^%^MAGENTA%^u%^RESET%^"
         "%^RED%^v%^MAGENTA%^e fr%^BOLD%^%^MAGENTA%^i%^RESET%^"
         "%^MAGENTA%^nge %^BOLD%^%^BLACK%^borders the comfortable "
         "%^RESET%^%^MAGENTA%^cushion%^BOLD%^%^BLACK%^, weighed down "
         "by tiny %^RED%^rub%^RESET%^%^RED%^i%^BOLD%^%^RED%^es%^BLACK%^.%^RESET%^",
      "bed" : "%^BOLD%^%^BLACK%^A spacious four poster bed is the "
         "focal point of the room. It is crafted from rich, %^RESET%^"
         "%^ORANGE%^darkwood %^BOLD%^%^BLACK%^and rests on squat claw "
         "foot risers. Miniature dragons crown the peaks of the posters, "
         "their slender tails curled around the thick posts. Gauzy "
         "%^RESET%^%^MAGENTA%^m%^RED%^a%^BOLD%^%^MAGENTA%^u%^RESET%^"
         "%^RED%^v%^MAGENTA%^e %^BOLD%^%^BLACK%^curtains have been "
         "draped over the wooden rods and cascade down in %^RESET%^"
         "%^MAGENTA%^fl%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^w%^RED%^"
         "i%^MAGENTA%^ng %^BOLD%^%^BLACK%^layers that completely obscure "
         "the interior of the bed. A sturdy headboard and footboard feature "
         "detailed carvings of dragons gliding through a cl%^WHITE%^o"
         "%^RESET%^u%^BOLD%^%^BLACK%^dy sky. Beneath the bed is a shaggy "
         "%^WHITE%^white fur rug %^BLACK%^that is meant to protect the "
         "floor from %^RESET%^scuffing%^BOLD%^%^BLACK%^.%^RESET%^",
      "floor" : "%^BOLD%^%^BLACK%^The floor is black marble buffed to a "
         "m%^WHITE%^i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^o%^BLACK%^r-"
         "like %^WHITE%^sheen%^BLACK%^.%^RESET%^",
      ({"ceiling","walls","wall","panels","paneling"}) : "%^BOLD%^%^BLACK%^"
         "The walls and ceiling are lined with rich %^RESET%^%^ORANGE%^"
         "darkwood paneling %^BOLD%^%^BLACK%^ that insulate the room, "
         "keeping it at a comfortable temperature and reducing reverberation.%^RESET%^",
      "mirror" : "%^RESET%^Bordered by a study %^ORANGE%^darkwood frame "
         "%^WHITE%^this floor-length %^BOLD%^%^WHITE%^m%^CYAN%^i%^RESET%^r"
         "%^BOLD%^%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^r %^RESET%^allows "
         "the guest to view themselves from head to toe. The %^ORANGE%^polished "
         "frame%^WHITE%^ depicts roiling %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^"
         "%^BLACK%^d%^WHITE%^o%^BLACK%^w fl%^RESET%^o%^BOLD%^%^BLACK%^wing %^RESET%^over "
         "and through itself in an endless storm of %^BLUE%^darkness%^WHITE%^.%^RESET%^",
      "armoire" : "%^BOLD%^%^BLACK%^Against the eastern wall is a tall armoire built "
         "from the same polished %^RESET%^%^ORANGE%^darkwood %^BOLD%^%^BLACK%^as "
         "the rest of the furniture. It is adorned with carvings similar to that "
         "of the bed and bench; the doors picture two powerfully built s%^WHITE%^"
         "h%^RESET%^a%^BOLD%^%^WHITE%^d%^BLACK%^ow dragons, %^WHITE%^m%^CYAN%^i"
         "%^WHITE%^r%^RESET%^r%^BOLD%^%^WHITE%^o%^RESET%^r %^BOLD%^%^BLACK%^"
         "images of one another, rearing as if they are about to clash in "
         "%^RESET%^%^RED%^battle%^BOLD%^%^BLACK%^. An impressive amount of "
         "detail has been rendered in the carved figures of four smaller "
         "dragons perched on the four corners of the armoire. Small oval "
         "%^RESET%^adamantium knobs %^BOLD%^%^BLACK%^adorn the doors.%^RESET%^"
   ]));
   set_exits(([
      "south" : ROOMS"west_wing"
   ]));
   set_door("darkwood door","/d/player_houses/aunuit/west_wing","south",0);
   set_door_description("darkwood door","%^RESET%^%^ORANGE%^This is a simple but "
      "sturdy darkwood door bearing a small oval shaped %^BOLD%^%^BLACK%^adamatium "
      "knob%^RESET%^%^ORANGE%^.%^RESET%^");
}