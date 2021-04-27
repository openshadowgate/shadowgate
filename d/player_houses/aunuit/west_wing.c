//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

void create(){
   ::create();
   set_name("West wing");
   set_short("%^BOLD%^%^BLACK%^West wing%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The rich%^RESET%^%^ORANGE%^ darkwood "
      "panels %^BOLD%^%^BLACK%^that make up the walls here reach up "
      "to an %^WHITE%^arched ceiling %^BLACK%^braced in dragon bone "
      "%^WHITE%^sc%^RESET%^r%^BOLD%^%^ORANGE%^i%^RESET%^m%^BOLD%^%^WHITE%^"
      "sh%^RESET%^a%^BOLD%^%^WHITE%^w%^BLACK%^. Both to the north and "
      "to the south a set of stairs leads to a landing that houses a "
      "door to a %^RESET%^%^MAGENTA%^guest room%^BOLD%^%^BLACK%^. Long "
      "%^RESET%^%^RED%^tapestries %^BOLD%^%^BLACK%^hang from the upper "
      "portions of the walls bearing stylized symbols. Tall %^WHITE%^vases "
      "%^BLACK%^are placed strategically along the edges of the main walkway, "
      "their large %^WHITE%^lum%^MAGENTA%^i%^WHITE%^n%^RESET%^o%^BOLD%^%^ORANGE%^u"
      "%^WHITE%^s %^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^ORANGE%^o%^RESET%^"
      "%^MAGENTA%^r%^BOLD%^%^MAGENTA%^a %^BLACK%^providing the only %^WHITE%^light "
      "%^BLACK%^in the passage. The gl%^WHITE%^o%^BLACK%^ssy black marble of the "
      "floor stretches out like a pool of %^RESET%^%^BLUE%^darkness %^BOLD%^"
      "%^BLACK%^under foot. At the west end of the hall a large archway leads "
      "to what appears to be a massive dining area. To the east another leads "
      "to the common room of the palace.%^RESET%^\n");
   set_listen("default","%^BOLD%^%^BLACK%^Any sounds such as footsteps on the marble "
      "or even a soft cough are muted by the wood paneling on the walls.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^The heady scent of the beautiful "
      "phosphorescent flowers fills the hallway.%^RESET%^");
   set_items(([
      "ceiling" : "%^BOLD%^%^WHITE%^Made from the same material as the pillars, "
         "the arched ceiling is composed of pale dr%^RESET%^a%^BOLD%^%^WHITE%^"
         "gon bone scr%^RESET%^i%^BOLD%^%^WHITE%^msh%^ORANGE%^a%^WHITE%^w. "
         "It has been treated so that its color is a pristine i%^RESET%^v%^BOLD%^"
         "%^ORANGE%^o%^RESET%^r%^BOLD%^%^WHITE%^y and there is no residual "
         "%^MAGENTA%^tissue %^WHITE%^but the natural texture remains, the bone "
         "like thick w%^BLACK%^e%^WHITE%^bb%^RESET%^i%^BOLD%^%^WHITE%^ng in some "
         "places and completely s%^ORANGE%^o%^WHITE%^lid in others.%^RESET%^",
      ({"walls","wall","panels","paneling"}) : "%^BOLD%^%^BLACK%^The walls are "
         "lined with rich %^RESET%^%^ORANGE%^darkwood panels %^BOLD%^%^BLACK%^"
         "that insulate the room, keeping it at a comfortable temperature and "
         "reducing reverberation.%^RESET%^",
      ({"vases","vase","flora","flowers"}) : "%^BOLD%^%^BLACK%^Standing about "
         "three feet in height, these delicate %^WHITE%^white porcelain %^BLACK%^"
         "vases hold beautiful flowers. The petals of the flowers display a "
         "brilliant array of shapes and %^RESET%^%^RED%^h%^ORANGE%^u%^GREEN%^e"
         "%^BOLD%^%^BLUE%^s%^BLACK%^, from a star-shaped, %^RESET%^%^MAGENTA%^deep "
         "purple fl%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^wer %^BOLD%^%^BLACK%^with "
         "gl%^WHITE%^o%^BLACK%^wing %^WHITE%^white flecks %^BLACK%^to a %^ORANGE%^"
         "yell%^RESET%^%^ORANGE%^o%^BOLD%^%^ORANGE%^w %^BLACK%^bell-shaped %^RESET%^"
         "%^ORANGE%^bulb %^BOLD%^%^BLACK%^with %^RESET%^%^ORANGE%^t%^BOLD%^%^ORANGE%^i"
         "%^BLACK%^g%^RESET%^%^ORANGE%^e%^BOLD%^%^ORANGE%^r%^BLACK%^-s%^RESET%^"
         "%^ORANGE%^t%^BOLD%^%^ORANGE%^r%^BLACK%^i%^RESET%^%^ORANGE%^p%^BOLD%^"
         "%^ORANGE%^e%^BLACK%^s. All are %^MAGENTA%^exotic%^BLACK%^, gorgeous "
         "and %^WHITE%^luminescent%^BLACK%^.%^RESET%^",
      "floor" : "%^BOLD%^%^BLACK%^The floor is black marble buffed to a m%^WHITE%^"
         "i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^o%^BLACK%^r-like %^WHITE%^sheen%^BLACK%^.%^RESET%^",
      ({"tapestries","tapestry"}) : "%^RESET%^%^RED%^At the center of the hall, "
         "two %^BOLD%^%^RED%^tapestries %^RESET%^%^RED%^hang against the walls across "
         "from one another. Both bear symbols set against a field of cr%^BOLD%^"
         "%^RED%^i%^RESET%^%^RED%^ms%^BOLD%^%^RED%^o%^RESET%^%^RED%^n. One depicts "
         "a %^BOLD%^%^BLACK%^black dragon %^RESET%^%^RED%^rising from a mass of "
         "writhing %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^"
         "%^BLACK%^w %^RESET%^%^RED%^and the other a simple but elegant %^BOLD%^"
         "%^BLACK%^black mask%^RESET%^%^RED%^.%^RESET%^"
   ]));
   set_exits(([
      "west" : ROOMS"dining_hall",
      "north" : ROOMS"guest_room_1",
      "south" : ROOMS"guest_room_2",
      "east" : ROOMS"maw"
   ]));
   set_door("darkwood door","/d/player_houses/aunuit/guest_room_1","north",0);
   set_door_description("darkwood door","%^RESET%^%^ORANGE%^This is a simple but "
      "sturdy darkwood door bearing a small oval shaped %^BOLD%^%^BLACK%^adamatium "
      "knob%^RESET%^%^ORANGE%^.%^RESET%^");
   set_door("ashwood door","/d/player_houses/aunuit/guest_room_2","south",0);
   set_door_description("ashwood door","%^RESET%^This is a simple but "
      "sturdy door made from ashwood bearing a small oval %^BOLD%^"
      "%^BLACK%^adamatium knob%^RESET%^.");
}