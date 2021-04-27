#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(BRANCHES);
   set_travel(LEDGE);
   set_name("A wooden platform");
   set_short("%^ORANGE%^A wooden platform%^RESET%^");
   set_smell("default","The scent of flowers fills the air.");
   set_listen("default","You can hear the quiet rustle of wind through the trees.");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
     ({"rail","railing"}) : (:TO,"railing_desc":),
     ({"floor","platform","balcony"}) : (:TO,"platform_desc":),
     "carvings" : "%^CYAN%^The slender railing is patterned with what look like intricate carvings, of "
"leaves and vines with a few small flowers scattered among them.  Upon a closer inspection, no cuts or "
"sharp edges are visible within the wood, as though the patterns had somehow grown this way.%^RESET%^",
     "mat" : "%^CYAN%^This simple mat has been woven from long reeds, dry and faded to a %^ORANGE%^soft "
"tan hue%^CYAN%^.  It is large enough to cover more than half of the floor.%^RESET%^",
     ({"stairs","steps"}) : "%^CYAN%^One set of small, %^ORANGE%^wooden steps%^CYAN%^ lead down from the "
"platform to the ground below, and another leads up into the branches above.%^RESET%^",
     ({"flowers","vines"}) : (:TO,"flowers_desc":),
     ({"lights","faerie lights"}) : (:TO,"lights_desc":)
   ]));
   set_exits(([
     "up" : ROOMS+"house2",
     "down" : ROOMS+"forest4"
   ]));
}

string railing_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night" && season(time()) == "winter") {
     return("%^CYAN%^A simple %^ORANGE%^wooden railing%^CYAN%^ runs around the length of the platform, "
"formed of the same wood as the platform itself.  Small, %^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie "
"lights along the edge of the railing illuminate the platform.  A fine layer of %^WHITE%^snow%^CYAN%^ "
"rests upon the railing.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("%^CYAN%^A simple %^ORANGE%^wooden railing%^CYAN%^ runs around the length of the platform, 
""formed of the same wood as the platform itself.  Small, %^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie 
""lights along the edge of the railing illuminate the platform.  A fine layer of %^WHITE%^snow%^CYAN%^ "
"rests upon the railing.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^A simple %^ORANGE%^wooden railing%^CYAN%^ runs around the length of the platform, 
formed of the same wood as the platform itself.  Small, %^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie 
lights along the edge of the railing illuminate the platform.%^RESET%^");
   }
   return("%^CYAN%^A simple %^ORANGE%^wooden railing%^CYAN%^ runs around the length of the platform, formed 
of the same wood as the platform itself.  It is patterned with what look like intricate 
carvings.%^RESET%^.");
}

string flowers_desc() {
   if (season(time()) == "winter") {
     return("%^CYAN%^Long, tangled vines drape their pa%^WHITE%^l%^CYAN%^e "
"fl%^WHITE%^o%^CYAN%^wers over the nearby branches and the railing, filling the air with their "
"%^MAGENTA%^gentle scent%^CYAN%^.  A layer of %^WHITE%^snow%^CYAN%^ rests upon them, weighing them down "
"a little.%^RESET%^");
   }
   return("%^CYAN%^Long, tangled vines drape their pa%^WHITE%^l%^CYAN%^e "
"fl%^WHITE%^o%^CYAN%^wers over the nearby branches and the railing, filling the air with their "
"%^MAGENTA%^gentle scent%^CYAN%^.%^RESET%^");
}

string platform_desc() {
   if (season(time()) == "winter") {
     return("%^CYAN%^The balcony is formed entirely from %^ORANGE%^smooth wood%^CYAN%^, of an identical "
"shade and texture to the tree supporting it.  Strong branches beneath the platform grow up and around it "
"to hold it securely in place, but in some spots it looks almost as though the platform has grown as part "
"of the tree itself.  A light sprinkling of %^WHITE%^snowflakes%^CYAN%^ is scattered across the surface "
"of the platform.%^RESET%^");
   }
   return("%^CYAN%^The balcony is formed entirely from %^ORANGE%^smooth wood%^CYAN%^, of an identical "
"shade and texture to the tree supporting it.  Strong branches beneath the platform grow up and around it "
"to hold it securely in place, but in some spots it looks almost as though the platform has grown as part "
"of the tree itself.%^RESET%^");
}

string lights_desc() {
   if((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^Small %^WHITE%^%^BOLD%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^YELLOW%^i%^WHITE%^ng "
"lig%^RESET%^%^WHITE%^h%^BOLD%^ts%^RESET%^%^CYAN%^ line the edges of the railing, shedding a little light "
"across the platform.%^RESET%^");
   }
   return("You do not notice that here.");
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^CYAN%^The steps lead up from the ground to this simple, roofless %^ORANGE%^wooden "
"balcony%^CYAN%^, which curves around the trunk almost as though it is part of the tree itself.  Several "
"sturdy boughs beneath it support its weight, growing up and around the platform as if it had always been "
"there.  The branches of nearby trees sway in the breeze, entangled with %^GREEN%^leafy vines%^CYAN%^ and "
"pa%^WHITE%^l%^CYAN%^e fl%^WHITE%^o%^CYAN%^wers that drape down from above.  The "
"platform itself is rather bare, with only a %^ORANGE%^plain woven mat%^CYAN%^ covering most of the "
"floor, and a slender wooden railing running around its edge.  A light sprinkling of %^WHITE%^snow "
"%^CYAN%^rests in a layer upon the railing and the platform itself.  Another set of stairs begins at the "
"far side of the balcony, travelling further up and around the tree's massive trunk and disappearing "
"among the branches above.%^RESET%^\n");
   }
   return("%^CYAN%^The steps lead up from the ground to this simple, roofless %^ORANGE%^wooden "
"balcony%^CYAN%^, which curves around the trunk almost as though it is part of the tree itself.  Several "
"sturdy boughs beneath it support its weight, growing up and around the platform as if it had always been "
"there.  The branches of nearby trees sway in the breeze, entangled with %^GREEN%^leafy vines%^CYAN%^ and "
"pa%^WHITE%^l%^CYAN%^e fl%^WHITE%^o%^CYAN%^wers that drape down from above.  The "
"platform itself is rather bare, with only a %^ORANGE%^plain woven mat%^CYAN%^ covering most of the "
"floor, and a slender wooden railing running around its edge.  Another set of stairs begins at the far "
"side of the balcony, travelling further up and around the tree's massive trunk and disappearing among "
"the branches above.%^RESET%^\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^CYAN%^The steps lead up from the ground to this simple, roofless %^ORANGE%^wooden "
"balcony%^CYAN%^, which curves around the trunk almost as though it is part of the tree itself.  Several "
"sturdy boughs beneath it support its weight, growing up and around the platform as if it had always been "
"there.  Others hang overhead, draped with %^GREEN%^vines%^CYAN%^ and pa%^WHITE%^l%^CYAN%^e "
"fl%^WHITE%^o%^CYAN%^wers that fill the %^BLACK%^%^BOLD%^night air%^RESET%^%^CYAN%^ with a "
"faint scent.  The platform itself is rather bare, with only a slender railing around its edge lit with "
"tiny %^WHITE%^%^BOLD%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^YELLOW%^i%^WHITE%^ng "
"lig%^RESET%^%^WHITE%^h%^BOLD%^ts%^RESET%^%^CYAN%^, and a %^ORANGE%^plain woven mat%^CYAN%^ covering most "
"of the floor.  A light sprinkling of %^WHITE%^snow%^CYAN%^ rests in a layer upon the railing and the "
"platform itself.  Another set of stairs begins at the far side of the balcony, travelling further up and "
"around the tree's massive trunk and disappearing into the %^BLACK%^%^BOLD%^shadows%^RESET%^%^CYAN%^ of "
"the branches above.%^RESET%^\n");
   }
   return("%^CYAN%^The steps lead up from the ground to this simple, roofless %^ORANGE%^wooden "
"balcony%^CYAN%^, which curves around the trunk almost as though it is part of the tree itself.  Several "
"sturdy boughs beneath it support its weight, growing up and around the platform as if it had always been "
"there.  Others hang overhead, draped with %^GREEN%^vines%^CYAN%^ and pa%^WHITE%^l%^CYAN%^e "
"fl%^WHITE%^o%^CYAN%^wers that fill the %^BLACK%^%^BOLD%^night air%^RESET%^%^CYAN%^ with a "
"faint scent.  The platform itself is rather bare, with only a slender railing around its edge lit with "
"tiny %^WHITE%^%^BOLD%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^YELLOW%^i%^WHITE%^ng "
"lig%^RESET%^%^WHITE%^h%^BOLD%^ts%^RESET%^%^CYAN%^, and a %^ORANGE%^plain woven mat%^CYAN%^ covering most "
"of the floor.  Another set of stairs begins at the far side of the balcony, travelling further up and "
"around the tree's massive trunk and disappearing into the %^BLACK%^%^BOLD%^shadows%^RESET%^%^CYAN%^ of "
"the branches above.%^RESET%^\n");
}
