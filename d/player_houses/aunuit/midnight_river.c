//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

void create(){
   ::create();
   set_name("Midnight River");
   set_short("%^BOLD%^%^BLACK%^Midnight River%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Stretching eastward, the %^RESET%^%^ORANGE%^"
      "rough %^BOLD%^%^BLACK%^walls and ceiling coupled with the %^RESET%^refle"
      "%^BOLD%^%^WHITE%^c%^RESET%^tive %^BOLD%^%^BLACK%^m%^WHITE%^a%^BLACK%^"
      "rble panels that line the floor lend this hall the appearance of a "
      "%^RESET%^%^CYAN%^subterranean river%^BOLD%^%^BLACK%^. The natural stone "
      "is d%^RESET%^o%^BOLD%^%^BLACK%^tted with %^RESET%^pale %^BOLD%^%^BLACK%^"
      "fle%^WHITE%^c%^BLACK%^ks of sm%^WHITE%^o%^BLACK%^ky qu%^RESET%^a%^BOLD%^"
      "%^WHITE%^r%^BLACK%^tz and patches of %^CYAN%^flu%^GREEN%^o%^CYAN%^r"
      "%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^sc%^GREEN%^e%^CYAN%^nt l%^WHITE%^i"
      "%^CYAN%^ch%^GREEN%^e%^CYAN%^n%^BLACK%^. A narrow %^RESET%^alcove %^BOLD%^"
      "%^BLACK%^has been carved into the north wall and a decorative obs%^RESET%^"
      "i%^BOLD%^%^BLACK%^di%^WHITE%^a%^BLACK%^n vase is nestled within. To the "
      "east and west are archways that lead to much larger rooms.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^Cool and still the air is tinged with incense.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The solid stone surfaces and "
      "foreboding silence augments any external sounds.%^RESET%^");
   set_items(([
      "floor" : "Buffed until it reflects the features of the room like a "
         "mirror, the black marble floor lends this room a vast, void-like "
         "quality. It is as if one is taking uncertain steps on the "
         "surface of a black pool, never knowing when the bottom might recede.",
      ({"ceiling","walls"}) : "%^BOLD%^%^BLACK%^In stark contrast to the "
         "smooth, glo%^WHITE%^s%^RESET%^s%^BOLD%^%^BLACK%^y floor are the "
         "%^RESET%^%^ORANGE%^rough %^BOLD%^%^BLACK%^surfaces of the walls "
         "and vaulted ceiling. Sm%^RESET%^o%^BOLD%^%^BLACK%^ky qu%^RESET%^a"
         "%^BOLD%^%^WHITE%^r%^BLACK%^tz %^RESET%^cr%^BOLD%^%^BLACK%^y"
         "%^RESET%^st%^BOLD%^%^WHITE%^a%^RESET%^ls %^BOLD%^%^BLACK%^dot "
         "their dark rock like %^WHITE%^stars %^BLACK%^in the %^RESET%^"
         "%^BLUE%^midnight sky %^BOLD%^%^BLACK%^and patches of %^CYAN%^"
         "flu%^GREEN%^o%^CYAN%^r%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^sc"
         "%^GREEN%^e%^CYAN%^nt l%^WHITE%^i%^CYAN%^ch%^GREEN%^e%^CYAN%^n "
         "%^BLACK%^provide faint %^WHITE%^illumination%^BOLD%^%^BLACK%^.%^RESET%^",
      ({"alcove","vase"}) : "%^BOLD%^%^BLACK%^A narrow %^RESET%^alcove"
         "%^BOLD%^%^BLACK%^ has been carved into the northern wall. Resting "
         "within is an obs%^RESET%^i%^BOLD%^%^BLACK%^di%^WHITE%^a%^BLACK%^n "
         "vase that stands three feet tall. The detailed rendering of a hunt "
         "plays out across the vase's curved surface in vivid %^RESET%^"
         "%^ORANGE%^p%^MAGENTA%^a%^GREEN%^i%^RED%^n%^ORANGE%^t%^BOLD%^%^BLACK%^:\n\n"
         "%^BOLD%^%^BLUE%^~%^BLACK%^A party of %^RESET%^%^BLUE%^Dark elven "
         "%^BOLD%^%^BLACK%^hunters are mounted on powerfully built riding "
         "%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^z%^GREEN%^"
         "a%^ORANGE%^rds%^BOLD%^%^BLACK%^, both lightly armored for speed "
         "and stealth. They race through the %^RESET%^%^GREEN%^th%^ORANGE%^"
         "i%^GREEN%^ck f%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^r%^CYAN%^e"
         "%^GREEN%^st %^BOLD%^%^BLACK%^in the dead of %^RESET%^%^BLUE%^"
         "night%^BOLD%^%^BLACK%^, the %^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^"
         "e%^RESET%^%^GREEN%^rdant c%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^n"
         "%^CYAN%^o%^GREEN%^py %^BOLD%^%^BLACK%^highlighted in glittering "
         "%^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^CYAN%^e%^RESET%^r "
         "%^BOLD%^%^BLACK%^m%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^nl"
         "%^WHITE%^i%^BLACK%^ght. Winding through the forest, the hunters "
         "lay chase to a large %^RESET%^%^ORANGE%^stag%^BOLD%^%^BLACK%^. "
         "Carrying bows strung with obs%^RESET%^i%^BOLD%^%^BLACK%^di"
         "%^WHITE%^a%^BLACK%^n arr%^WHITE%^o%^BLACK%^ws, d%^RED%^a%^BLACK%^"
         "ggers, as well as other weapons suited for hunting the Dark elves "
         "pursue their prey as the moon traverses the dark sky. After "
         "chasing the buck for some time the hunters finally trap him at the "
         "base of a %^RESET%^%^CYAN%^wat%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^rf"
         "%^WHITE%^a%^CYAN%^ll%^BOLD%^%^BLACK%^, where the majestic animal "
         "is slain by the arrow of a tall lithe male wielding %^RESET%^"
         "%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^mson a%^BOLD%^%^RED%^x"
         "%^RESET%^%^RED%^es%^BOLD%^%^BLACK%^. The victor extracts the "
         "beast's still be%^RED%^a%^BLACK%^ting %^RED%^heart %^BLACK%^"
         "and raises the organ, tearing in to it. %^RED%^Bl%^RESET%^%^RED%^"
         "oo%^BOLD%^%^RED%^d %^BOLD%^%^BLACK%^pours freely down his ebon "
         "chin. The final scene depicts the hunters dancing round a brilliant "
         "fire, its %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^o"
         "%^RESET%^%^MAGENTA%^let f%^BOLD%^%^MAGENTA%^l%^WHITE%^a%^MAGENTA%^"
         "m%^RESET%^%^MAGENTA%^es %^BOLD%^%^BLACK%^licking at the sky. A "
         "masked Dark elf draped in fl%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^"
         "wing robes holds the severed %^RESET%^antlers %^BOLD%^%^BLACK%^"
         "above his head, preparing to cast them into the %^RESET%^%^MAGENTA%^"
         "magical inferno%^BOLD%^%^BLACK%^. High in the branches of the "
         "surrounding trees, several %^RED%^red%^BLACK%^-eyed ravens "
         "observe the ritual.%^BLUE%^~%^RESET%^"
   ]));
   set_exits(([
      "west" : ROOMS"shadow_vault",
      "east" : ROOMS"grotto"
   ]));
}