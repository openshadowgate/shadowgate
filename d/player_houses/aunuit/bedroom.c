//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

int vanity_searched;
int armoire_searched;

void create(){
   ::create();
   vanity_searched = 0;
   armoire_searched = 0;
  set_name("Lovers' Reprieve");
   set_short("%^BOLD%^%^BLACK%^Lovers' Reprieve%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Richly decorated with fine, expensive "
      "materials this bedroom belongs to someone with exquisite "
      "taste. The eye is immediately drawn to the center of the "
      "room where a canopy bed rests %^RESET%^%^BLUE%^shrouded "
      "%^BOLD%^%^BLACK%^in mystery. At the foot of the bed is a "
      "well-built %^RESET%^%^ORANGE%^darkwood bench %^BOLD%^%^BLACK%^"
      "with clawed feet and a sp%^WHITE%^i%^BLACK%^d%^RED%^e%^BLACK%^"
      "r%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lk c%^BLACK%^u%^WHITE%^"
      "sh%^RESET%^i%^BOLD%^%^RED%^o%^WHITE%^n%^BLACK%^. A shaggy "
      "%^WHITE%^white f%^RESET%^u%^BOLD%^%^WHITE%^r area rug "
      "%^BLACK%^protects the gl%^RESET%^a%^BOLD%^%^WHITE%^s%^BLACK%^"
      "sy bla%^RESET%^c%^BOLD%^%^BLACK%^k st%^WHITE%^o%^BLACK%^ne "
      "floor and also provides a comfortable place to lie in front "
      "of the %^RESET%^%^MAGENTA%^f%^BOLD%^%^MAGENTA%^i%^RESET%^"
      "%^MAGENTA%^rep%^BOLD%^%^MAGENTA%^l%^WHITE%^a%^MAGENTA%^c"
      "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^. %^RESET%^%^MAGENTA%^"
      "V%^BOLD%^%^MAGENTA%^i%^WHITE%^o%^RESET%^%^MAGENTA%^l%^BOLD%^"
      "%^MAGENTA%^e%^RESET%^%^MAGENTA%^t f%^BOLD%^%^MAGENTA%^l%^WHITE%^"
      "a%^MAGENTA%^m%^RESET%^%^MAGENTA%^es %^BOLD%^%^BLACK%^undulate "
      "within the hollow depths of the hearth in the western wall. "
      "Next to the fireplace is an overstuffed %^WHITE%^a%^BLACK%^r"
      "%^WHITE%^mc%^RESET%^h%^BOLD%^%^RED%^a%^WHITE%^ir %^BLACK%^also "
      "upholstered in luxurious %^WHITE%^s%^RED%^i%^RESET%^l%^BOLD%^"
      "%^WHITE%^k%^BLACK%^. Beside the chair is a unique table holding "
      "a %^RESET%^sil%^BOLD%^%^BLACK%^v%^RESET%^er pl%^BOLD%^%^BLACK%^"
      "a%^RESET%^tter %^BOLD%^%^BLACK%^piled with a selection of "
      "%^RESET%^%^MAGENTA%^fr%^RED%^u%^BOLD%^%^MAGENTA%^i%^RESET%^"
      "%^MAGENTA%^ts %^BOLD%^%^BLACK%^and %^ORANGE%^che%^RESET%^"
      "%^ORANGE%^e%^BOLD%^%^ORANGE%^s%^WHITE%^e%^ORANGE%^s %^BLACK%^"
      "as well as a %^RESET%^pitcher %^BOLD%^%^BLACK%^of %^CYAN%^w"
      "%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ter %^BLACK%^and two spare "
      "%^WHITE%^glasses%^BLACK%^. Hanging over the hearth is a "
      "framed c%^RESET%^h%^BOLD%^%^WHITE%^a%^BLACK%^rc%^RESET%^o"
      "%^BOLD%^%^WHITE%^a%^BLACK%^l drawing picturing a pair of "
      "unlikely %^RESET%^%^RED%^lovers%^BOLD%^%^BLACK%^. The "
      "northeastern side of the bedroom is reserved for dressing. "
      "An ornate %^RESET%^%^ORANGE%^vanity %^BOLD%^%^BLACK%^is "
      "piled with %^RESET%^%^MAGENTA%^feminine necessities %^BOLD%^"
      "%^BLACK%^and equipped with an oval-shaped %^WHITE%^m"
      "%^RESET%^i%^BOLD%^%^CYAN%^r%^WHITE%^r%^RESET%^o%^BOLD%^"
      "%^WHITE%^r %^BLACK%^for primping and preening.  Next to "
      "the dressing table is a matching %^RESET%^%^ORANGE%^armoire"
      "%^BOLD%^%^BLACK%^. Behind the bed hangs a thick %^RESET%^"
      "%^RED%^tapestry %^BOLD%^%^BLACK%^bearing the sacred symbol "
      "of the %^RESET%^%^BLUE%^Masked God of the Night%^BOLD%^"
      "%^BLACK%^.  A r%^CYAN%^u%^BLACK%^n%^RESET%^%^CYAN%^e%^BOLD%^"
      "%^BLACK%^-inscr%^CYAN%^i%^BLACK%^b%^RESET%^%^CYAN%^e%^BOLD%^"
      "%^BLACK%^d s%^CYAN%^e%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^l "
      "exits to the south.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^The faint scent of a heady perfume lingers in the air.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^Within this room there is no sound but that which you make.%^RESET%^");
   set_items(([
      "bed" : "%^BOLD%^%^BLACK%^A spacious four poster bed dominates "
         "the center of the room. It is crafted from rich %^RESET%^"
         "%^ORANGE%^darkwood %^BOLD%^%^BLACK%^and rests on squat "
         "claw foot risers. Miniature dragons crown the peaks of the "
         "posters, their slender tails curled around the thick posts. "
         "Ga%^RESET%^u%^BOLD%^%^BLACK%^zy bla%^RESET%^c%^BOLD%^%^BLACK%^k "
         "curtains have been draped over the wooden rods and cascade "
         "down in fl%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^i%^BOLD%^"
         "%^BLACK%^ng layers that completely obscure the interior of "
         "the bed. A sturdy headboard and footboard feature detailed "
         "%^RESET%^%^ORANGE%^carvings %^BOLD%^%^BLACK%^of dragons gliding "
         "through a cl%^RESET%^o%^BOLD%^%^WHITE%^u%^BLACK%^dy s%^RESET%^k"
         "%^BOLD%^%^BLACK%^y. Beneath the bed is a %^WHITE%^white fur "
         "rug %^BLACK%^that is meant to protect the floor from the "
         "weight of the furniture.%^RESET%^",
      "bench" : "%^BOLD%^%^BLACK%^This well-built %^RESET%^%^ORANGE%^"
         "bench %^BOLD%^%^BLACK%^rests at the foot of the %^RESET%^"
         "%^BLUE%^shrouded bed%^BOLD%^%^BLACK%^. Slender legs with "
         "clawed feet support the well-balanced piece. The plush "
         "cushion that spans its seat is upholstered with thick-spun "
         "sp%^WHITE%^i%^BLACK%^der%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^"
         "lk%^BLACK%^. The %^WHITE%^w%^RESET%^e%^BOLD%^%^WHITE%^b "
         "%^BLACK%^pattern of the %^WHITE%^s%^RED%^i%^WHITE%^lk "
         "%^BLACK%^is as intricate and myriad in design as one woven "
         "by an actual sp%^RED%^i%^BLACK%^der. A soft %^WHITE%^glow "
         "%^BLACK%^surrounds the cushion itself as %^WHITE%^l%^RESET%^"
         "i%^BOLD%^%^WHITE%^ght tr%^RESET%^a%^BOLD%^%^WHITE%^ils "
         "%^BOLD%^%^BLACK%^course through the s%^WHITE%^i%^BLACK%^l"
         "%^CYAN%^v%^RESET%^e%^BOLD%^%^BLACK%^ry material, providing "
         "a stunning %^WHITE%^highlighting %^BLACK%^effect. Delicate "
         "%^RESET%^%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^ms%^BOLD%^"
         "%^RED%^o%^RESET%^%^RED%^n fr%^BOLD%^%^RED%^i%^RESET%^%^RED%^"
         "nge %^BOLD%^%^BLACK%^borders the cushion, weighed down by "
         "tiny %^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RED%^i"
         "%^MAGENTA%^e%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^.%^RESET%^",
      ({"armchair","chair"}) : "%^BOLD%^%^BLACK%^A high-backed armchair "
         "sits on the left side of the hearth, tilted toward the "
         "%^RESET%^%^MAGENTA%^f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^"
         "re %^BOLD%^%^BLACK%^so its occupant can enjoy the %^MAGENTA%^"
         "v%^WHITE%^i%^MAGENTA%^br%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^nt "
         "fl%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^m%^WHITE%^e%^MAGENTA%^s"
         "%^RESET%^. The thick comfortable cushions are upholstered with "
         "thick-spun sp%^RED%^i%^BLACK%^der%^WHITE%^s%^RESET%^i%^BOLD%^"
         "%^WHITE%^lk%^BLACK%^. The %^WHITE%^w%^RESET%^e%^BOLD%^%^WHITE%^b "
         "%^BLACK%^pattern of the %^WHITE%^s%^RED%^i%^WHITE%^lk %^BLACK%^is "
         "as intricate and myriad in design as one woven by an actual "
         "sp%^RED%^i%^BLACK%^der. A soft %^WHITE%^glow %^BLACK%^surrounds "
         "the cushion itself as %^WHITE%^l%^RESET%^i%^BOLD%^%^WHITE%^ght "
         "tr%^RESET%^a%^BOLD%^%^WHITE%^ils %^BOLD%^%^BLACK%^course through "
         "the s%^WHITE%^i%^BLACK%^l%^CYAN%^v%^RESET%^e%^BOLD%^%^BLACK%^ry "
         "material, providing a stunning %^WHITE%^highlighting "
         "%^BLACK%^effect. Delicate %^RESET%^%^RED%^cr%^BOLD%^%^RED%^i"
         "%^RESET%^%^RED%^ms%^BOLD%^%^RED%^o%^RESET%^%^RED%^n fr%^BOLD%^"
         "%^RED%^i%^RESET%^%^RED%^nge %^BOLD%^%^BLACK%^borders the cushion, "
         "weighed down by tiny %^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b"
         "%^RED%^i%^MAGENTA%^e%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^.%^RESET%^",
      ({"table","platter","fruit","cheese","cheeses","pitcher","glasses"}) :
         "%^BOLD%^%^BLACK%^Unlike the other pieces of furniture in "
         "the room this table is not crafted from wood. Instead it is "
         "shaped like an %^WHITE%^hourglass %^BLACK%^and made entirely "
         "from v%^RED%^o%^BLACK%^lcan%^RESET%^i%^BOLD%^%^BLACK%^c "
         "gl%^WHITE%^a%^RESET%^s%^BOLD%^%^BLACK%^s. Resting on its "
         "r%^RESET%^e%^BOLD%^%^BLACK%^fle%^WHITE%^c%^BLACK%^tive surface "
         "is a %^RESET%^sil%^BOLD%^%^BLACK%^v%^RESET%^er pl%^BOLD%^%^BLACK%^"
         "a%^RESET%^tter %^BOLD%^%^BLACK%^piled with %^RESET%^%^MAGENTA%^"
         "gr%^BOLD%^%^GREEN%^a%^RESET%^%^MAGENTA%^pes%^BOLD%^%^BLACK%^, "
         "%^RED%^str%^ORANGE%^a%^RED%^wb%^RESET%^%^RED%^e%^BOLD%^%^RED%^"
         "rries%^BLACK%^, %^ORANGE%^m%^RED%^a%^ORANGE%^ngo sl%^RESET%^"
         "%^MAGENTA%^i%^BOLD%^%^ORANGE%^ces %^BLACK%^as well as an "
         "assortment of fine %^ORANGE%^ch%^WHITE%^ee%^ORANGE%^s%^WHITE%^"
         "e%^ORANGE%^s%^BLACK%^. Also sharing the platter is a "
         "%^RESET%^crystal pitcher %^BOLD%^%^BLACK%^of %^CYAN%^w"
         "%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ter %^BLACK%^and two "
         "fluted %^WHITE%^glasses%^BLACK%^. Should you choose, you "
         "could <enjoy food> or <enjoy water>%^RESET%^",
      "hearth" : "%^BOLD%^%^BLACK%^A significant amount of st"
         "%^RESET%^o%^BOLD%^%^BLACK%^ne has been displaced to create "
         "this deep, broad h%^WHITE%^e%^RESET%^a%^BOLD%^%^BLACK%^rth. "
         "The r%^RESET%^o%^ORANGE%^u%^BOLD%^%^BLACK%^gh natural "
         "st%^WHITE%^o%^BLACK%^ne interior is%^WHITE%^ highlighted "
         "%^BLACK%^by bright %^MAGENTA%^v%^WHITE%^i%^RESET%^%^MAGENTA%^o"
         "%^BOLD%^%^MAGENTA%^let fl%^WHITE%^a%^MAGENTA%^m%^RESET%^"
         "%^MAGENTA%^e%^BOLD%^%^MAGENTA%^s%^BLACK%^. Pale %^WHITE%^cr"
         "%^RESET%^y%^BOLD%^%^CYAN%^s%^WHITE%^tals gl%^RESET%^i%^BOLD%^"
         "%^WHITE%^tt%^CYAN%^e%^WHITE%^r %^BLACK%^on the hearth floor, "
         "the %^RESET%^%^MAGENTA%^f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^"
         "re%^BOLD%^%^BLACK%^ li%^MAGENTA%^c%^BLACK%^king across them "
         "without causing damage to the precious %^WHITE%^g%^CYAN%^e"
         "%^WHITE%^ms%^BLACK%^.%^RESET%^",
      ({"vanity","mirror"}) : "%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^"
         "vanity %^BOLD%^%^BLACK%^itself is a dainty thing with a raised "
         "pattern of delicate %^RESET%^%^GREEN%^le%^CYAN%^a%^BOLD%^%^GREEN%^"
         "v%^RESET%^%^GREEN%^es %^BOLD%^%^BLACK%^running along its seams as "
         "well as around its slender legs. The vanity sees frequent use "
         "as indicated by a sizable collection of %^WHITE%^g%^RESET%^l"
         "%^BOLD%^%^CYAN%^a%^RESET%^s%^BOLD%^%^WHITE%^s j%^RESET%^a%^BOLD%^"
         "%^WHITE%^rs %^BLACK%^and %^RESET%^metal containers %^BOLD%^%^BLACK%^"
         "that house %^WHITE%^pale powders%^BLACK%^, %^MAGENTA%^ro%^RED%^u"
         "%^MAGENTA%^ges%^BLACK%^, %^RESET%^%^ORANGE%^perfumes%^BOLD%^"
         "%^BLACK%^, %^ORANGE%^creams %^BLACK%^and %^RESET%^%^RED%^w%^MAGENTA%^"
         "a%^RED%^xy l%^BOLD%^%^RED%^i%^RESET%^%^RED%^p p%^BOLD%^%^MAGENTA%^a"
         "%^RESET%^%^RED%^ints%^BOLD%^%^BLACK%^ in all the colors of the "
         "%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^ORANGE%^i%^GREEN%^n%^BLUE%^"
         "b%^MAGENTA%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^BLACK%^. There are "
         "several narrow rectangular drawers with %^WHITE%^o%^CYAN%^v"
         "%^WHITE%^al%^BLACK%^-cut %^WHITE%^d%^RESET%^i%^BOLD%^%^CYAN%^a"
         "%^RESET%^m%^BOLD%^%^WHITE%^onds %^BLACK%^for knobs. Some of the "
         "small drawers are ajar, revealing an impressive collection of "
         "exquisite %^CYAN%^jew%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^lry "
         "%^BLACK%^and %^WHITE%^coiffure accessories%^BLACK%^. An oval-"
         "shaped %^WHITE%^m%^CYAN%^i%^RESET%^r%^BOLD%^%^WHITE%^r%^RESET%^o"
         "%^BOLD%^%^WHITE%^r%^BLACK%^, also wreathed in realistic-looking "
         "leaves and %^RED%^r%^RESET%^%^RED%^o%^BOLD%^%^MAGENTA%^s%^RED%^e "
         "b%^MAGENTA%^u%^RED%^ds%^BLACK%^, crowns the vanity. A dainty "
         "%^RESET%^%^ORANGE%^darkwood chair %^BOLD%^%^BLACK%^sits in front "
         "of the vanity, the round seat %^WHITE%^c%^RED%^u%^WHITE%^sh"
         "%^RESET%^i%^BOLD%^%^BLACK%^o%^WHITE%^n %^BLACK%^upholstered "
         "with thick-spun spider%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lk"
         "%^BLACK%^. The %^WHITE%^w%^RESET%^e%^BOLD%^%^WHITE%^b %^BLACK%^"
         "pattern of the %^WHITE%^s%^RED%^i%^WHITE%^lk %^BLACK%^is as "
         "intricate and myriad in design as one woven by an actual "
         "sp%^RED%^i%^BLACK%^der. A soft %^WHITE%^glow %^BLACK%^surrounds "
         "the cushion itself as %^WHITE%^l%^RESET%^i%^BOLD%^%^WHITE%^ght "
         "tr%^RESET%^a%^BOLD%^%^WHITE%^ils %^BOLD%^%^BLACK%^course through "
         "the s%^WHITE%^i%^BLACK%^l%^CYAN%^v%^RESET%^e%^BOLD%^%^BLACK%^ry "
         "material, providing a stunning %^WHITE%^highlighting "
         "%^BLACK%^effect.%^RESET%^",
      "armoire" : "%^BOLD%^%^BLACK%^A tall %^RESET%^%^ORANGE%^armoire "
         "%^BOLD%^%^BLACK%^stands next to the delicate, %^RESET%^%^MAGENTA%^"
         "f%^RED%^e%^MAGENTA%^minine %^BOLD%^%^BLACK%^vanity. Built from the "
         "same polished %^RESET%^%^ORANGE%^darkwood %^BOLD%^%^BLACK%^it is "
         "adorned with carvings similar to that of the bed, armchair and "
         "bench; the doors picture two powerfully built sh%^RESET%^a%^BOLD%^"
         "%^BLACK%^d%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w dragons, mirror "
         "images of one another, rearing as if they are about to clash in "
         "%^RESET%^%^RED%^battle%^BOLD%^%^BLACK%^. An impressive amount of "
         "detail has been rendered in the carved figures of four smaller "
         "dragons perched on the four corners of the armoire. Large "
         "%^WHITE%^egg%^BLACK%^-shaped knobs cut from %^WHITE%^d%^RESET%^i"
         "%^BOLD%^%^CYAN%^a%^RESET%^m%^BOLD%^%^WHITE%^onds %^BLACK%^adorn "
         "the doors and must have cost no small %^ORANGE%^fortune%^BLACK%^.%^RESET%^",
      "tapestry" : "%^BOLD%^%^WHITE%^A tapestry of finely woven fabric "
         "displays a %^BOLD%^%^BLACK%^black half-mask %^RESET%^on a field "
         "of %^RESET%^pale gr%^BOLD%^%^BLACK%^e%^RESET%^y%^BOLD%^%^WHITE%^. "
         "A bright %^RESET%^%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^ms"
         "%^BOLD%^%^RED%^o%^RESET%^%^RED%^n bord%^BOLD%^%^RED%^e%^RESET%^"
         "%^RED%^r %^BOLD%^%^WHITE%^frames the perimeter of the tapestry, "
         "emboldening the symbol of the %^BLACK%^Masked God of Night%^WHITE%^. "
         "The tapestry hangs against the wall behind the bed, secured by thick "
         "%^BLACK%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^CYAN%^v%^WHITE%^e%^BLACK%^r "
         "c%^CYAN%^o%^BLACK%^rds %^WHITE%^that are tied to the edge of the "
         "ceiling via %^RESET%^adamatium hooks%^BOLD%^%^BLACK%^.%^RESET%^",
      ({"drawing","picture"}) : "%^BOLD%^%^WHITE%^A s%^RESET%^o%^BOLD%^"
         "%^WHITE%^ft %^BLACK%^ch%^RESET%^a%^BOLD%^%^BLACK%^rc%^WHITE%^o"
         "%^RESET%^a%^BOLD%^%^BLACK%^l p%^WHITE%^e%^BLACK%^n%^RESET%^c%^BOLD%^"
         "%^BLACK%^il %^WHITE%^was used to create this %^RESET%^%^RED%^all"
         "%^MAGENTA%^u%^RED%^ring dr%^RED%^a%^MAGENTA%^wing %^BOLD%^%^WHITE%^"
         "of a pair of unlikely %^RED%^l%^RESET%^%^RED%^o%^BOLD%^%^RED%^vers"
         "%^WHITE%^. The %^MAGENTA%^female %^WHITE%^is a pale %^RESET%^"
         "%^GREEN%^f%^CYAN%^e%^GREEN%^y %^BOLD%^%^WHITE%^creature and the "
         "artist has artfully applied %^BLACK%^shadow %^WHITE%^and subtle "
         "%^BLACK%^shading %^WHITE%^to showcase her %^RESET%^fair complexion "
         "%^BOLD%^%^WHITE%^and still capture the details of her flesh. "
         "Completely nude she is a tall, %^RESET%^pale-h%^BOLD%^%^ORANGE%^"
         "a%^WHITE%^i%^RESET%^red %^BOLD%^%^WHITE%^beauty with angular "
         "features, sm%^RED%^o%^WHITE%^ldering %^RED%^c%^RESET%^%^RED%^a"
         "%^BOLD%^%^RED%^t%^WHITE%^-like %^RED%^e%^RESET%^%^MAGENTA%^y"
         "%^RED%^e%^BOLD%^%^RED%^s %^WHITE%^and the sort of %^RESET%^"
         "%^RED%^sens%^BOLD%^%^RED%^u%^RESET%^%^RED%^al cur%^BOLD%^"
         "%^RED%^v%^RESET%^%^RED%^es %^BOLD%^%^WHITE%^usually "
         "attributed to a %^BLACK%^succubus%^WHITE%^. She stands with "
         "her shapely leg draped over the hip of her partner; a "
         "massive, powerfully built male %^BLACK%^Dark elf%^WHITE%^. "
         "A long %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^l%^BOLD%^%^CYAN%^v"
         "%^RESET%^ery br%^BOLD%^%^BLACK%^a%^CYAN%^i%^RESET%^d %^BOLD%^"
         "%^WHITE%^trails down between his broad shoulders.  His "
         "impressive form is fully concealed by %^BLACK%^blackened chain "
         "%^WHITE%^and the artist has captured every detail, even using "
         "%^RESET%^%^BLUE%^negative space %^BOLD%^%^WHITE%^to create "
         "a %^CYAN%^gleam %^WHITE%^on the %^RESET%^met%^BOLD%^%^CYAN%^a"
         "%^RESET%^l l%^BOLD%^%^BLACK%^i%^RESET%^nks %^BOLD%^%^WHITE%^"
         "and also to highlight the darkling's magisterial %^BLACK%^"
         "visage%^WHITE%^. He cradles his %^RESET%^ghostly lover "
         "%^BOLD%^%^WHITE%^in gauntleted hands, looming over her despite "
         "her own considerable height. The only color used in the drawing "
         "is very faint and has only been applied to their eyes - "
         "a pale %^MAGENTA%^rose color %^WHITE%^for the female's and "
         "a soft %^CYAN%^azure %^WHITE%^for the male's - and they gaze "
         "at one another, %^RED%^l%^RESET%^%^RED%^u%^BOLD%^%^RED%^st"
         "%^WHITE%^ and %^RESET%^%^ORANGE%^affection %^BOLD%^%^WHITE%^"
         "evident in those eyes.%^RESET%^",
      "ceiling" : "%^BOLD%^%^BLACK%^Adhering to the curve of the "
         "ceiling this %^CYAN%^gl%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ss "
         "p%^WHITE%^a%^CYAN%^nel%^BLACK%^ is located at the apex of the "
         "ceiling and has a diameter of about four feet. A faint "
         "%^CYAN%^a%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^ra %^BLACK%^"
         "emanates from the thick glass. Beyond the clear dome is "
         "a gorgeous vista; a deep %^BLUE%^n%^RESET%^%^BLUE%^a%^BOLD%^"
         "%^BLUE%^vy bl%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^e sky "
         "%^BLACK%^filled with %^WHITE%^t%^RESET%^w%^BOLD%^%^ORANGE%^"
         "i%^RESET%^n%^BOLD%^%^ORANGE%^kl%^CYAN%^i%^WHITE%^ng "
         "s%^CYAN%^t%^ORANGE%^a%^WHITE%^rs%^BLACK%^. For some reason, "
         "no matter what angle one peers through the skylight, the "
         "m%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^n is nowhere "
         "to be found.%^RESET%^"
   ]));
   set_exits(([
      "south" : ROOMS"chamber_of_reckoning",
      "east" : ROOMS"bathroom"
   ]));
   set_door("seal","/d/player_houses/aunuit/chamber_of_reckoning","south",0);
   set_door_description("seal","%^BOLD%^%^BLACK%^Nearly six feet in diameter "
         "this inlaid circular %^RESET%^adamatium ring %^BOLD%^"
         "%^BLACK%^occupies a majority of the southern wall. The "
         "metal has an ethereal, %^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^"
         "z%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e h%^BOLD%^%^CYAN%^u"
         "%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^and is without visible "
         "streaks or folds, its forging truly a work of master "
         "craftsmanship. Et%^CYAN%^c%^BLACK%^hed into the surface of "
         "the metal itself, which is about two feet wide, is an "
         "intricate l%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ne design; "
         "dr%^CYAN%^a%^BLACK%^g%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^ns "
         "curled round one another, their m%^RESET%^%^CYAN%^o%^BOLD%^"
         "%^CYAN%^u%^BLACK%^ths consuming the ta%^CYAN%^i%^BLACK%^l "
         "of the next in an %^RESET%^%^CYAN%^infinite%^BOLD%^%^BLACK%^ "
         "d%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^n%^CYAN%^c%^BLACK%^e.%^RESET%^");

         set_search("armoire", (:TO, "search_armoire":) );
         set_search("vanity", (:TO, "search_vanity":) );
}

void init(){
   ::init();
   add_action("enjoy_em","enjoy");
}

int enjoy_em(string str){
   if(!str){
      tell_object(TP,"Would you like to <enjoy food> or <enjoy water>?");
      return 1;
   }
   if(str == "food" || str == "fruit" || str == "cheese"){
      if(!TP->add_stuffed(25)) {
        write("You are way too full for that!\n");
        return 1;
      }
      tell_object(TP,"%^BOLD%^%^BLACK%^You partake of the succulent %^RESET%^"
         "%^MAGENTA%^fr%^RED%^u%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^t %^BOLD%^"
         "%^BLACK%^and flavorful %^ORANGE%^che%^RESET%^%^ORANGE%^e%^BOLD%^"
         "%^ORANGE%^s%^WHITE%^e%^ORANGE%^s %^BLACK%^and are surprised by how "
         "filling they are!%^RESET%^");
      tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" partakes of the succulent "
         "%^RESET%^%^MAGENTA%^fr%^RED%^u%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^t "
         "%^BOLD%^%^BLACK%^and flavorful %^ORANGE%^che%^RESET%^%^ORANGE%^e"
         "%^BOLD%^%^ORANGE%^s%^WHITE%^e%^ORANGE%^s%^BLACK%^.%^RESET%^",TP);
      return 1;
   }
   if(str == "water" || str == "glass of water"){
      if(!TP->add_quenched(100)){
         write("Your stomach is sloshing already!\n");
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^BLACK%^You tilt the %^RESET%^pitcher %^BOLD%^"
         "%^BLACK%^and fill one of the glasses. You drink deeply of the "
         "%^CYAN%^w%^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^ter%^BLACK%^, surprised "
         "at how %^CYAN%^cool %^BLACK%^it is!%^RESET%^");
      tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" tilts the %^RESET%^pitcher "
         "%^BOLD%^%^BLACK%^and fills one of the glasses before drinking deeply%^BLACK%^.%^RESET%^",TP);
      return 1;
   }
   tell_object(TP,"Would you like to <enjoy food> or <enjoy water>?");
   return 1;
}

void reset()
{
  ::reset();
  vanity_searched = 0;
  armoire_searched = 0;
}

int search_armoire()
{
  object ob;
  int i;
  if (!objectp(TO)){return 0;}
  if (armoire_searched>0) {
    tell_object(TP,"You don't find anything in the armoire this time.");
    tell_room(TO, TPQCN + " searches through the armoire but doesn't seem"
                  +" to find anything of interest",TP);
    return 0;
  }
  ob = new("/d/player_houses/silesse/obj/ryzan");
  ob->move(TO);
  if (objectp(ob)){
    tell_object(TP,"You find a "+ ob->query_short() + " in the armoire!");
    tell_room(TO,TPQCN + " pulls a  "+ ob->query_short() + " out from the armoire!",TP);
  }
  armoire_searched++;
}

int search_vanity()
{
  object ob;
  int i;
  if (!objectp(TO)){return 0;}
  if (armoire_searched>0) {
    tell_object(TP,"You don't find anything in the vanity this time.");
    tell_room(TO, TPQCN + " searches through the vanity but doesn't seem"
                  +" to find anything of interest",TP);
    return 0;
  }
  ob = new("/d/player_houses/silesse/obj/aunuit");
  ob->move(TO);
  if (objectp(ob)){
    tell_object(TP,"You find a "+ ob->query_short() + " in the vanity!");
    tell_room(TO,TPQCN + " pulls a  "+ ob->query_short() + " out from the vanity!",TP);
  }
  armoire_searched++;
}
