#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit INH+"forest";

void create() {
   ::create();
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   add_item(({"mountains","walls","stone walls","mountainside"}),(:TO,"mountain_desc":));
   add_item(({"oak tree","stairs"}),"%^GREEN%^Looking closer, you can see small %^ORANGE%^wooden "
"stairs%^GREEN%^ that blend in nearly perfectly with the tree's trunk itself.  They run up around the "
"trunk of this great oak and disappear from sight amongst the branches above.%^RESET%^");
   set_exits(([
     "northwest" : ROOMS+"forest3",
     "northeast" : ROOMS+"forest2",
     "stairs" : ROOMS+"house1"
   ]));
   set_pre_exit_functions(({"stairs"}),({"GoThroughDoor"}));
   set_search("default",(:TO,"search_fun":));
}

string mountain_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^The %^WHITE%^snowcapped%^GREEN%^ peaks of the mountains rise again to the south, "
"barring any further passage that way.%^RESET%^");
   }
   return ("%^GREEN%^The %^BLUE%^tall peaks%^GREEN%^ of the mountains rise again to the south, barring "
"any further passage that way.%^RESET%^");
}

string tree_desc() {
   if (season(time()) == "winter" && (string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Most of these trees are several hundred feet tall, towering above you, with their "
"thick branches coated in %^WHITE%^snow%^GREEN%^.  They must be incredibly old to have grown so "
"large.  At a careful look, you can see an occasional faint sparkle of "
"%^WHITE%^%^BOLD%^t%^RESET%^%^WHITE%^i%^BOLD%^ny "
"l%^YELLOW%^i%^WHITE%^gh%^RESET%^%^WHITE%^t%^BOLD%^s%^RESET%^%^GREEN%^ between the branches, far up the "
"trunk of one particularly tall oak tree.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("%^GREEN%^Most of these trees are several hundred feet tall, towering above you, with their "
"thick branches coated in %^WHITE%^snow%^GREEN%^.  They must be incredibly old to have grown so "
"large.  At a second glance, you can see what looks like a small %^ORANGE%^wooden platform%^GREEN%^, "
"partway up a particularly tall oak tree.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Most of these trees are several hundred feet tall, towering above you.  They must "
"be incredibly old to have grown so large.  At a careful look, you can see an occasional faint sparkle of "
"%^WHITE%^%^BOLD%^t%^RESET%^%^WHITE%^i%^BOLD%^ny "
"l%^YELLOW%^i%^WHITE%^gh%^RESET%^%^WHITE%^t%^BOLD%^s%^RESET%^%^GREEN%^ between the branches, far up the "
"trunk of one particularly tall oak tree.%^RESET%^");
   }
   return("%^GREEN%^Most of these trees are several hundred feet tall, towering above you.  They must be "
"incredibly old to have grown so large.  At a second glance, you can see what looks like a small "
"%^ORANGE%^wooden platform%^GREEN%^, partway up a particularly tall oak tree.%^RESET%^");
}

string long_desc() {
   if (season(time()) == "winter") {
   return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  The forest floor is coated in a thick layer of "
"%^WHITE%^snow%^GREEN%^, leaving it very hard to find a path through the trees.  The mountainside rises "
"again behind the trees to the south, blocking any further passage, and the forest continues to the "
"north.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the leaf-covered "
"ground, leaving it very hard to find a path through the trees.  The mountainside rises again behind the "
"trees to the south, blocking any further passage, and the forest continues to the north.%^RESET%^\n");
   }
   return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the surrounding "
"mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  Their "
"%^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the forest floor, "
"leaving it very hard to find a path through the trees.  The mountainside rises again behind the trees to "
"the south, blocking any further passage, and the forest continues to the north.%^RESET%^\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  The forest floor is coated in a thick layer of %^WHITE%^snow%^GREEN%^, leaving "
"it very hard to find a path through the darkened forest.  The mountainside rises again behind the trees "
"to the south, blocking any further passage, and the forest continues to the north.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  All sorts of small shrubs thrive upon the leaf-covered ground, leaving it very "
"hard to find a path through the darkened forest.  The mountainside rises again behind the trees to the "
"south, blocking any further passage, and the forest continues to the north.%^RESET%^\n");
   }
   return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the trees in this "
"dense, ancient forest, which has grown hidden within this small clearing in the surrounding mountains.  "
"The trees stretch hundreds of feet above, with their branches and leaves intertwined by a myriad of "
"%^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even the "
"%^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above are "
"hard to see at times.  All sorts of small shrubs thrive upon the forest floor, leaving it very "
"hard to find a path through the darkened forest.  The mountainside rises again behind the trees to the "
"south, blocking any further passage, and the forest continues to the north.%^RESET%^\n");
}

int GoThroughDoor() {
     tell_object(TP,"%^CYAN%^You carefully climb the %^ORANGE%^stairs%^CYAN%^ up into the oak "
"tree.%^RESET%^");
     if (!TP->query_invis())
       tell_room(ETP,"%^CYAN%^"+TP->QCN+" carefully climbs the %^ORANGE%^stairs%^CYAN%^ up into the oak "
"tree.%^RESET%^",TP);
     return 1;
}

int search_fun() {
   if((string)EVENTS_D->query_time_of_day() == "night") {
     tell_object(TP,"%^GREEN%^High above, among the branches of a great oak tree, you can see the sparkle "
"of %^WHITE%^%^BOLD%^t%^RESET%^%^WHITE%^i%^BOLD%^ny "
"l%^YELLOW%^i%^WHITE%^gh%^RESET%^%^WHITE%^t%^BOLD%^s%^RESET%^%^GREEN%^.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^GREEN%^High above, among the branches of a great oak tree, glimpses of a "
"%^ORANGE%^wooden platform%^GREEN%^ can be seen.%^RESET%^");
   return 1;
}

void reset() {
   ::reset();
   switch(random(11)) {
     case 0..1:
     tell_room(TO,"%^CYAN%^A small, "
"%^MAGENTA%^br%^BLUE%^ig%^BOLD%^ht%^CYAN%^-f%^GREEN%^ea%^YELLOW%^th%^RESET%^%^ORANGE%^er%^RED%^%^BOLD%^ed "
"%^RESET%^%^CYAN%^bird alights on a branch overhead, filling the air with its cheerful song.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^CYAN%^A light mountain breeze brushes through the trees, filling the air with the "
"%^MAGENTA%^soft%^CYAN%^ scent of flowers.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^CYAN%^For a few seconds you can catch glimpses of a %^WHITE%^translucent%^CYAN%^ "
"woman's figure, with %^WHITE%^%^BOLD%^shi%^CYAN%^m%^WHITE%^mer%^YELLOW%^i%^WHITE%^ng%^RESET%^%^CYAN%^ "
"wings and %^BOLD%^w%^WHITE%^in%^CYAN%^ds%^WHITE%^we%^CYAN%^pt%^RESET%^%^CYAN%^ hair, fluttering in among "
"the trees, before she disappears from sight.%^RESET%^");
     break;
     case 5:
     tell_room(TO,"%^CYAN%^The wind brushes past your face, almost like the %^ORANGE%^caress%^CYAN%^ of "
"a soft hand, as you catch a second's glimpse out of the corner of your eye, of a winged feminine "
"figure.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^CYAN%^Tiny butterflies flutter through the "
"%^ORANGE%^br%^GREEN%^a%^ORANGE%^nc%^GREEN%^%^BOLD%^h%^RESET%^%^ORANGE%^es%^CYAN%^ above, in an elaborate "
"dance among the %^MAGENTA%^pale flowers%^CYAN%^.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^CYAN%^The sound of "
"%^GREEN%^l%^ORANGE%^e%^GREEN%^av%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^ rustling comes from above, in the "
"wake of some small, unseen forest creature.%^RESET%^");
     break;
     case 9..10:
     if (season(time()) == "winter") {
       tell_room(TO,"%^CYAN%^The branches overhead sway in the breeze, as a few %^WHITE%^snowflakes "
"%^CYAN%^drift down to join the ground's %^WHITE%^snowy%^CYAN%^ carpet.%^RESET%^");
     }
     else {
       tell_room(TO,"%^CYAN%^The branches overhead sway in the breeze, dropping "
"%^GREEN%^l%^ORANGE%^e%^GREEN%^av%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^ to flutter down through the air "
"around you, and rest upon the forest floor.%^RESET%^");
     }
     break;
   }
}
