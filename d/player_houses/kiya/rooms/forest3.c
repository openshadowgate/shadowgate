#include <std.h>
#include "../defs.h"
inherit INH+"forest";

void create() {
   ::create();
   set_property("fill waterskin",1);
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   add_item(({"mountains","walls","stone walls","mountainside"}),(:TO,"mountain_desc":));
   set_exits(([
     "northeast" : ROOMS+"forest1",
     "southeast" : ROOMS+"forest4"
   ]));
   new(OBJ+"pond")->move(TO);
}

string mountain_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^The %^WHITE%^snowcapped%^GREEN%^ peaks of the mountains rise again to the west, "
"barring any further passage that way.  Bubbling down from the mountainside is a small spring.%^RESET%^");
   }
   return ("%^GREEN%^The %^BLUE%^tall peaks%^GREEN%^ of the mountains rise again to the west, barring "
"any further passage that way.  Bubbling down from the mountainside is a small spring.%^RESET%^");
}

string long_desc() {
   if (season(time()) == "winter") {
     if(present("mirror",TO)->query_property("magic mirror")) {
       return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  The forest floor is coated in a thick layer of "
"%^WHITE%^snow%^GREEN%^, leaving it very hard to find a path through the trees.  Partway up the "
"mountainside to the west, a small mountain spring bubbles up between the rocks, pouring down into a "
"pool of %^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level, partially covered in a layer of %^CYAN%^%^BOLD%^i%^WHITE%^c"
"%^CYAN%^e%^RESET%^%^GREEN%^.  A %^CYAN%^gentle glowing aura%^GREEN%^ is present, shimmering upon the pond's "
"icy surface.  The thick forest continues to the east.%^RESET%^\n");
     }
     return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  The forest floor is coated in a thick layer of "
"%^WHITE%^snow%^GREEN%^, leaving it very hard to find a path through the trees.  Partway up the "
"mountainside to the west, a small mountain spring bubbles up between the rocks, pouring down into a "
"pool of %^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  The thick forest continues to the east.%^RESET%^\n");
   } 
   if (season(time()) == "autumn") {
     if(present("mirror",TO)->query_property("magic mirror")) {
       return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the leaf-covered "
"ground, leaving it very hard to find a path through the trees.  Partway up the mountainside to the west, "
"a small mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  A %^CYAN%^gentle glowing aura%^GREEN%^ is present, "
"shimmering upon the pond's rippling surface.  The thick forest continues to the east.%^RESET%^\n");
     }
     return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the leaf-covered "
"ground, leaving it very hard to find a path through the trees.  Partway up the mountainside to the west, "
"a small mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  The thick forest continues to the east.%^RESET%^\n");
   }
   if(present("mirror",TO)->query_property("magic mirror")) {
     return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of "
"the surrounding mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  "
"Their %^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the forest floor, "
"leaving it very hard to find a path through the trees.  Partway up the mountainside to the west, a small "
"mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  A %^CYAN%^gentle glowing aura%^GREEN%^ is present, "
"shimmering upon the pond's rippling surface.  The thick forest continues to the east.%^RESET%^\n");
   }
   return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of "
"the surrounding mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  "
"Their %^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the forest floor, "
"leaving it very hard to find a path through the trees.  Partway up the mountainside to the west, a small "
"mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  The thick forest continues to the east.%^RESET%^\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     if(present("mirror",TO)->query_property("magic mirror")) {
       return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  The forest floor is coated in a thick layer of %^WHITE%^snow%^GREEN%^, leaving "
"it very hard to find a path through the darkened forest.  Partway up the mountainside to the west, a "
"small mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level, partially covered in a layer of %^CYAN%^%^BOLD%^i%^WHITE%^c"
"%^CYAN%^e%^RESET%^%^GREEN%^.  A %^CYAN%^gentle glowing aura%^GREEN%^ is present, shimmering upon the pond's "
"icy surface.  The thick forest continues to the east.%^RESET%^\n");
     }
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  The forest floor is coated in a thick layer of %^WHITE%^snow%^GREEN%^, leaving "
"it very hard to find a path through the darkened forest.  Partway up the mountainside to the west, a "
"small mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level, partially covered in a layer of %^CYAN%^%^BOLD%^i%^WHITE%^"
"c%^CYAN%^e%^RESET%^%^GREEN%^.  The thick forest continues to the east.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     if(present("mirror",TO)->query_property("magic mirror")) {
       return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  All sorts of small shrubs thrive upon the leaf-covered ground, leaving it very "
"hard to find a path through the darkened forest.  Partway up the mountainside to the west, a small "
"mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  A %^CYAN%^gentle glowing aura%^GREEN%^ is present, "
"shimmering upon the pond's rippling surface.  The thick forest continues to the east.%^RESET%^\n");
     }
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  All sorts of small shrubs thrive upon the leaf-covered ground, leaving it very "
"hard to find a path through the darkened forest.  Partway up the mountainside to the west, a small "
"mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  The thick forest continues to the east.%^RESET%^\n");
   }
   if(present("mirror",TO)->query_property("magic mirror")) {
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  All sorts of small shrubs thrive upon the forest floor, leaving it very "
"hard to find a path through the darkened forest.  Partway up the mountainside to the west, a small "
"mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  A %^CYAN%^gentle glowing aura%^GREEN%^ is present, "
"shimmering upon the pond's rippling surface.  The thick forest continues to the east.%^RESET%^\n");
   }
   return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  All sorts of small shrubs thrive upon the forest floor, leaving it very "
"hard to find a path through the darkened forest.  Partway up the mountainside to the west, a small "
"mountain spring bubbles up between the rocks, pouring down into a pool of "
"%^BOLD%^%^BLUE%^c%^CYAN%^ry%^WHITE%^s%^CYAN%^ta%^BLUE%^l%^RESET%^%^GREEN%^-"
"%^BLUE%^%^BOLD%^c%^CYAN%^le%^WHITE%^a%^CYAN%^r %^WHITE%^wa%^CYAN%^te%^BLUE%^r%^RESET%^%^GREEN%^ which "
"has formed against the rocks at ground-level.  The thick forest continues to the east.%^RESET%^\n");
}

void init() {
  ::init();
  add_action("drink_fun","drink");
}

int drink_fun(string str) {
   if(!str) return 0;
   if(str == "water from pool" || str == "water from pond" || str == "water from spring") {
     if(!TP->add_quenched(20)) {
       return notify_fail("Your stomach is sloshing already!\n");
     }
     if (season(time()) == "winter") {
       tell_object(TP,"You drink some water from a hole in the ice-covered pool.");
       tell_room(TO,TPQCN+" leans over to drink some water from a hole in the ice-covered pool.",TP);
       return 1;
     }
     tell_object(TP,"You drink some water from the pool.");
     tell_room(TO,TPQCN+" drinks some water from the pool.",TP);
     return 1;
   }
   return notify_fail("Try drinking some water from the pool?\n");
}

void reset() {
   ::reset();
   switch(random(11)) {
     case 0:
     tell_room(TO,"%^CYAN%^Just below the water's surface appears a pair of glowing, "
"%^GREEN%^m%^BOLD%^os%^RESET%^%^GREEN%^s-%^BOLD%^gr%^RESET%^%^GREEN%^ee%^BOLD%^n%^RESET%^%^CYAN%^ eyes, "
"within the barely visible outline of a beautiful woman's face.  With a "
"%^BOLD%^r%^BOLD%^i%^WHITE%^p%^BLUE%^pl%^CYAN%^e%^RESET%^%^CYAN%^, they disappear again just as "
"quickly.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^CYAN%^A feminine form appears within the spring's "
"%^BOLD%^b%^BLUE%^ub%^CYAN%^b%^WHITE%^l%^BLUE%^in%^CYAN%^g%^RESET%^%^CYAN%^ waters, swirling together "
"with the sparkling waters to disappear within the pond.%^RESET%^");
     break;
     case 2:
     tell_room(TO,"%^CYAN%^A swirling eddy appears within the pond, rising to take the form of a "
"laughing, %^WHITE%^translucent%^CYAN%^ female who beckons to you with a slender hand.  A mischevious "
"grin shows across her %^BOLD%^%^BLUE%^w%^CYAN%^at%^BLUE%^er%^CYAN%^y%^RESET%^%^CYAN%^ features as she "
"slips back into the pond again, merging with the water.%^RESET%^");
     break;
     case 3..4:
     tell_room(TO,"%^CYAN%^A soft breeze stirs the %^GREEN%^reeds%^CYAN%^ into motion, sending "
"%^BOLD%^r%^BOLD%^i%^WHITE%^p%^BLUE%^pl%^CYAN%^e%^BLUE%^s%^RESET%^%^CYAN%^ across the pond's clear "
"surface.%^RESET%^");
     break;
     case 5..6:
     tell_room(TO,"%^CYAN%^A "
"%^WHITE%^%^BOLD%^sp%^CYAN%^a%^WHITE%^rk%^YELLOW%^l%^WHITE%^e%^RESET%^%^CYAN%^ of light catches your eye, "
"reflected from the translucent wings of a dragonfly as it flashes across the pond, vanishing among the "
"%^GREEN%^reeds%^CYAN%^.%^RESET%^");
     break;
     case 7..8:
     tell_room(TO,"%^CYAN%^A small, "
"%^MAGENTA%^br%^BLUE%^ig%^BOLD%^ht%^CYAN%^-f%^GREEN%^ea%^YELLOW%^th%^RESET%^%^ORANGE%^er%^RED%^%^BOLD%^ed "
"%^RESET%^%^CYAN%^bird alights on a branch overhead, filling the air with its cheerful song.%^RESET%^");
     break;
     case 9..10:
     if (season(time()) == "winter") {
       tell_room(TO,"%^CYAN%^The branches overhead sway in the breeze, as a few %^WHITE%^snowflakes "
"%^CYAN%^drift down and land upon the pool, disappearing into the water.%^RESET%^");
     }
     else {
     tell_room(TO,"%^CYAN%^The branches overhead sway in the breeze, dropping "
"%^GREEN%^l%^ORANGE%^e%^GREEN%^av%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^ to flutter down onto the pond, "
"sending %^BOLD%^r%^BOLD%^i%^WHITE%^p%^BLUE%^pl%^CYAN%^e%^BLUE%^s%^RESET%^%^CYAN%^ across its clear "
"surface.%^RESET%^");
     }
     break;
   }
}
