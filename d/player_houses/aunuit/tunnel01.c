//Ryzan and Aunuit's House
//Coded by ~Circe~ 5/3/13

#include <std.h>
#include "aunuit.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(BUILT_TUNNEL);
   set_name("Foreboding Tunnel");
   set_short("%^BOLD%^%^BLACK%^Foreboding Tunnel%^RESET%^");
   set_light(2);
   set_indoors(1);
   set_long("%^BOLD%^%^BLACK%^A cavernous tunnel has been borne into "
      "the %^RESET%^%^ORANGE%^e%^RED%^a%^GREEN%^r%^ORANGE%^th "
      "%^BOLD%^%^BLACK%^descending at an angle subtle enough to "
      "allow foot traffic to pass in each direction without much "
      "effort. The passageway is large enough for an %^RESET%^"
      "%^RED%^army %^BOLD%^%^BLACK%^to march through it, both its "
      "height and width nearing a hundred feet. The surface of the "
      "tunnel is composed of a p%^RESET%^i%^BOLD%^%^BLACK%^tch-"
      "bl%^RESET%^a%^BOLD%^%^BLACK%^ck smooth, gl%^WHITE%^o%^BLACK%^"
      "ssy dr%^RED%^a%^BLACK%^gon glass or obs%^WHITE%^i%^BLACK%^d"
      "%^WHITE%^i%^RESET%^a%^BOLD%^%^BLACK%^n as it is better "
      "known. It must have required an incredible amount of %^RED%^"
      "h%^ORANGE%^e%^RESET%^%^RED%^a%^BOLD%^%^RED%^t %^BLACK%^and "
      "%^RESET%^%^ORANGE%^pressure %^BOLD%^%^BLACK%^to burrow "
      "through the b%^RESET%^e%^BOLD%^%^BLACK%^d%^WHITE%^r%^RESET%^"
      "%^ORANGE%^o%^WHITE%^c%^BOLD%^%^BLACK%^k to create this "
      "structure. %^WHITE%^S%^CYAN%^c%^WHITE%^on%^RESET%^c%^BOLD%^"
      "%^BLACK%^e%^WHITE%^s %^BLACK%^have been mounted to the wall "
      "and vibrant %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^"
      "o%^MAGENTA%^l%^RESET%^%^MAGENTA%^et f%^BOLD%^%^MAGENTA%^a"
      "%^WHITE%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^ie f%^BOLD%^%^MAGENTA%^"
      "i%^RESET%^%^MAGENTA%^re %^BOLD%^%^BLACK%^undulates within "
      "casting %^MAGENTA%^eerie %^BLACK%^sh%^WHITE%^a%^BLACK%^d%^RESET%^"
      "o%^BOLD%^%^BLACK%^ws across the reflect%^WHITE%^i%^BLACK%^ve "
      "surfaces of the stone.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^The cool air is tinged with a faint metallic scent.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The tunnel is as silent as a tomb.%^RESET%^");
   set_items(([
      ({"sconce","sconces"}) : "%^BOLD%^%^BLACK%^Every twenty feet "
         "triangular ad%^RESET%^a%^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^"
         "%^BLACK%^nt%^WHITE%^i%^BLACK%^te sc%^RESET%^o%^BOLD%^"
         "%^BLACK%^n%^WHITE%^c%^BLACK%^es have been mounted to the "
         "wall. Vivid %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i"
         "%^WHITE%^o%^MAGENTA%^l%^RESET%^%^MAGENTA%^et f%^BOLD%^"
         "%^MAGENTA%^a%^WHITE%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^ie "
         "f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^re %^BOLD%^"
         "%^BLACK%^fli%^MAGENTA%^c%^BLACK%^kers within, casting "
         "%^MAGENTA%^eerie %^BLACK%^sh%^WHITE%^a%^BLACK%^d%^RESET%^"
         "o%^BOLD%^%^BLACK%^ws across the surfaces of the tunnel.%^RESET%^",
      ({"obsidian","dragon glass","walls","floor","ceiling"}) : "%^BOLD%^"
         "%^BLACK%^As bla%^RESET%^c%^BOLD%^%^BLACK%^k as p%^WHITE%^i"
         "%^BLACK%^tch and fl%^RESET%^a%^BOLD%^%^BLACK%^wl%^WHITE%^e"
         "%^RESET%^s%^BOLD%^%^BLACK%^s to the touch this st%^RESET%^o"
         "%^BOLD%^%^BLACK%^ne has a gl%^RESET%^o%^BOLD%^%^WHITE%^s"
         "%^BLACK%^sy sh%^WHITE%^e%^RESET%^e%^BOLD%^%^BLACK%^n akin "
         "to that of a %^MAGENTA%^g%^RESET%^%^MAGENTA%^e%^BOLD%^"
         "%^MAGENTA%^mst%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^ne"
         "%^BLACK%^. It has been created from a massive explosion "
         "of %^RED%^h%^RESET%^%^RED%^e%^BOLD%^%^ORANGE%^a%^RED%^t "
         "%^BLACK%^and %^RESET%^%^ORANGE%^pressure%^BOLD%^%^BLACK%^, "
         "the r%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ck having c"
         "%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^led so quickly "
         "afterward that the pattern of the sto%^RESET%^n%^BOLD%^"
         "%^BLACK%^e resembles a rapidly %^CYAN%^fl%^RESET%^%^CYAN%^"
         "o%^BOLD%^%^CYAN%^w%^WHITE%^i%^CYAN%^ng r%^RESET%^%^CYAN%^i"
         "%^GREEN%^v%^BOLD%^%^CYAN%^er%^BLACK%^, its surface sw"
         "%^WHITE%^e%^BLACK%^lling and e%^WHITE%^b%^RESET%^b%^BOLD%^"
         "%^BLACK%^ing. The entirety of the tunnel is forged from this "
         "exquisite sto%^RESET%^n%^BOLD%^%^BLACK%^e.%^RESET%^\n",
   ]));
   set_exits(([
      "west" : ROOMS"shadow15",
      "southeast" : ROOMS"tunnel02"
   ]));
}