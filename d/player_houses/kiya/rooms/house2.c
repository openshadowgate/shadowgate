#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(BRANCHES);
   set_travel(LEDGE);
   set_name("A simple room");
   set_short("%^ORANGE%^A simple room%^RESET%^");
   set_smell("default","The sharp, crisp scent of the forest fills the air.");
   set_listen("default","You can hear the quiet rustle of wind through the trees.");
   set_long("%^CYAN%^This room is large and spacious, and fully enclosed on all sides save for three "
"archways, through which the forest's %^GREEN%^upper canopy%^CYAN%^ can be seen.  From one archway "
"extends a bridge, and from another stairs travelling downward around the tree's trunk.  The walls and "
"floor are all formed from the same %^ORANGE%^wood%^CYAN%^ as the rest of the platform, very similar to "
"that of the tree in which it resides.  The walls are bare all around the room, except for a %^BLUE%^long "
"cloth%^CYAN%^ draped from two points on the wall.  In the centre of the room is a low-set table with a "
"wide, flat top, surrounded by several small wooden chairs.%^RESET%^\n");
   set("night long","%^CYAN%^This room is large and spacious, and fully enclosed on all sides save for "
"three archways, through which the %^BLACK%^%^BOLD%^darkened%^RESET%^%^CYAN%^ forest's upper levels can "
"be seen.  Small %^WHITE%^%^BOLD%^bright lights%^RESET%^%^CYAN%^ around each archway shed illumination "
"into the room, revealing a bridge extending from one archway, and stairs from another travelling "
"downward around the tree's trunk.  The walls and floor are all formed from the same "
"%^ORANGE%^wood%^CYAN%^ as the rest of the platform, very similar to that of the tree in which it "
"resides.  The walls are bare all around the room, except for a %^BLUE%^long cloth%^CYAN%^ draped from "
"two points on the wall.  In the centre of the room is a low-set table with a wide, flat top, surrounded "
"by several small wooden chairs.%^RESET%^\n");
   set_items(([
     ({"floor","platform"}) : "%^CYAN%^The floor is formed entirely from %^ORANGE%^smooth wood%^CYAN%^, "
"of an identical shade and texture to the tree supporting it.  Strong branches beneath the platform grow "
"up and around it to hold it securely in place, but in some spots it looks almost as though the platform "
"has grown as part of the tree itself.%^RESET%^",
     ({"archways","arches"}) : (:TO,"arches_desc":),
     "carvings" : "%^CYAN%^The three archways are patterned with what look like intricate carvings, of "
"leaves and vines with a few small flowers scattered among them.  Upon a closer inspection, no cuts or "
"sharp edges are visible within the wood, as though the patterns had somehow grown this way.%^RESET%^",
     "table" : "%^CYAN%^A low-set %^ORANGE%^wooden table%^CYAN%^ is in the centre of the room, that looks "
"to have grown through the floor itself.  From the slender base at floorlevel spreads the flat top of the "
"table, marked on its surface with countless concentric rings of the tree's growth.%^RESET%^",
     "chairs" : "%^CYAN%^Surrounding the low-set table are several small chairs.  Each has a solid "
"%^ORANGE%^wooden%^CYAN%^ frame, with some sort of soft woven forming the seat of the chair itself.  They "
"look quite comfortable to sit on.%^RESET%^",
     ({"third archway","third arch"}) : (:TO,"third_desc":),
     "bridge" : "%^CYAN%^A slender %^ORANGE%^wooden bridge%^CYAN%^ leads out through one archway, "
"disappearing from view between the branches of the forest.%^RESET%^",
     ({"stairs","steps"}) : "%^CYAN%^Through one archway, %^ORANGE%^wooden steps%^CYAN%^ are visible "
"leading down to a wooden platform below.%^RESET%^",
     ({"cloth","hammock"}) : "%^CYAN%^A long piece of woven cloth has been draped loosely but securely "
"between two niches in the wall, off to one side.  It is of some unknown substance with only slender, "
"%^BLUE%^dull blue%^CYAN%^ threads, but the tight intricate weave results in a very sturdy length of "
"cloth.  It could easily be used as a very comfortable hammock.%^RESET%^",
     ({"lights","faerie lights"}) : (:TO,"lights_desc":),
   ]));
   set_exits(([
     "down" : ROOMS+"house1",
     "up" : ROOMS+"house3",
     "bridge" : ROOMS+"bridge"
   ]));
}

string arches_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^These graceful %^ORANGE%^wooden arches%^CYAN%^ are formed of the same wood as the "
"rest of the tree.  There are three within the room, all of which offer a view of the "
"%^BLACK%^%^BOLD%^darkened%^RESET%^%^CYAN%^ forest outside.  Small, "
"%^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie lights illuminate the edges of each arch, shedding a "
"little light into the room itself.  From one archway extends a bridge, and from another stairs descend "
"down around the tree's trunk.  The third simply opens into the air, like a large window, onto stairs "
"that lead upwards out of sight..  Each archway is patterned with what look like intricate carvings.%^RESET%^");
   }
   return("%^CYAN%^These graceful %^ORANGE%^wooden arches%^CYAN%^ are formed of the same wood as the rest "
"of the tree.  There are three within the room, all of which offer a view of the %^GREEN%^forest's "
"canopy%^CYAN%^ outside.  From one archway extends a bridge, and from another stairs descend down around "
"the tree's trunk.  The third simply opens into the air, like a large window, onto stairs that lead "
"upwards out of sight.  Each archway is patterned with what look like intricate carvings.%^RESET%^");
}

string third_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^This archway opens into the air, giving clear view of the "
"%^BLACK%^%^BOLD%^shadow-shrouded%^RESET%^%^CYAN%^ forest outside.  It also allows a little visibility "
"further up the trunk of this great tree, where more %^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie "
"lights flicker between the branches above.  A small spiral staircase leads upwards between the tree's "
"branches.%^RESET%^");
   }
   return("%^CYAN%^This archway opens into the air, giving clear view of the forest outside.  It also "
"allows a little visibility further up the trunk of this great tree, where the underside of another "
"%^ORANGE%^wooden platform%^CYAN%^ can be partly-seen amongst the tree's topmost branches.  A small "
"spiral staircase leads upwards between the tree's branches.%^RESET%^");
}

string lights_desc() {
   if((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^Small %^WHITE%^%^BOLD%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^YELLOW%^i%^WHITE%^ng "
"lig%^RESET%^%^WHITE%^h%^BOLD%^ts%^RESET%^%^CYAN%^ line the edges of the arches, showing them apart from "
"the %^BLACK%^%^BOLD%^dark night%^RESET%^%^CYAN%^ beyond and shedding a little light into the "
"room.%^RESET%^");
   }
   return("You do not notice that here.");
}

void init() {
   ::init();
   add_action("lie_fun","lie");
   add_action("lie_fun","lay");
}

int lie_fun(string str) {
   if(!str) {
   notify_fail("Lie where?\n");
   return 0;
   }
   if(str != "hammock" && str != "in hammock" && str != "in the hammock") {
   notify_fail("You do not see that here.\n");
   return 0;
   }
   tell_object(TP,"%^ORANGE%^You climb into the comfortable hammock.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TPQCN+" climbs into the hammock and stretches out to relax.%^RESET%^",TP);
   TP->force_me("pose lying in the hammock");
   return 1;
}
