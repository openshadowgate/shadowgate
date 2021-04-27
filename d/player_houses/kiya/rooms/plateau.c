#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

int picked;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
   set_name("Grassy plateau");
   set_short("%^GREEN%^%^BOLD%^Grassy plateau%^RESET%^");
   set_smell("default","You smell the sharp, clear mountain air.");
   set_listen("default","It is very quiet and peaceful here.");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
     "bridge" : (:TO,"bridge_desc":),
     "beach" : (:TO,"beach_desc":),
     "mountains" : (:TO,"mountain_desc":),
     ({"field","corn field","cornfield"}) : (:TO,"field_desc":),
     ({"ocean","sea"}) : (:TO,"ocean_desc":),
     "shrine" : (:TO,"shrine_desc":),
     ({"flowers","moonflowers","moon flowers"}) : (:TO,"flowers_desc":)
   ]));
   set_exits(([
     "bridge" : ROOMS+"bridge"
   ]));
}

string bridge_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^A slender, %^WHITE%^snow-covered %^ORANGE%^wooden bridge%^GREEN%^ leads away from "
"the mountainside, disappearing from view between the branches of the forest.%^RESET%^");
   }
   return("%^GREEN%^A %^ORANGE%^slender wooden bridge%^GREEN%^ leads away from the mountainside, "
"disappearing from view between the branches of the forest.%^RESET%^");
}

string beach_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Past the mountains to the northwest, you can see the "
"%^ORANGE%^pa%^YELLOW%^l%^RESET%^%^ORANGE%^e s%^YELLOW%^a%^RESET%^%^ORANGE%^nds%^GREEN%^ of a "
"%^WHITE%^moonlit%^GREEN%^ beach, and the lights of a large city beyond that.%^RESET%^");
   }
   return("%^GREEN%^Past the mountains to the northwest, you can see the "
"%^ORANGE%^pa%^YELLOW%^l%^RESET%^%^ORANGE%^e s%^YELLOW%^a%^RESET%^%^ORANGE%^nds%^GREEN%^ of a beach, and "
"the walls of a large city beyond that.%^RESET%^");
}

string mountain_desc() {
   if (season(time()) == "winter" && (string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Tall, %^WHITE%^snow-capped%^GREEN%^ mountains fill the entire view to the south, "
"with nothing visible beyond them.  A few more %^BLACK%^%^BOLD%^shadowswept%^RESET%^%^GREEN%^ peaks are "
"scattered to the east and west.  Past them to the west is a broad, %^WHITE%^snow-covered%^GREEN%^ field, "
"and to the east the %^WHITE%^moonlight%^GREEN%^ reflects off the broad expanse of "
"%^BLUE%^%^BOLD%^oc%^CYAN%^e%^WHITE%^a%^BLUE%^n%^RESET%^%^GREEN%^.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("%^GREEN%^Tall, %^WHITE%^snow-capped%^GREEN%^ mountains fill the entire view to the south, "
"with nothing visible beyond them.  A few more rocky peaks are scattered to the east and west.  Past them "
"to the west is a broad, %^WHITE%^snow-covered%^GREEN%^ field, and to the east the sunlight reflects off "
"the broad expanse of %^BLUE%^%^BOLD%^oc%^CYAN%^e%^WHITE%^a%^BLUE%^n%^RESET%^%^GREEN%^.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Tall, mountains%^GREEN%^ fill the entire view to the south, with nothing visible "
"beyond them.  A few more %^BLACK%^%^BOLD%^shadowswept%^RESET%^%^GREEN%^ peaks are scattered to the east "
"and west.  Past them to the west is a broad "
"%^YELLOW%^c%^RESET%^%^ORANGE%^or%^BOLD%^nf%^RESET%^%^ORANGE%^ie%^BOLD%^l%^RESET%^%^ORANGE%^d%^GREEN%^, "
"and to the east the %^WHITE%^moonlight%^GREEN%^ reflects off the broad expanse of "
"%^BLUE%^%^BOLD%^oc%^CYAN%^e%^WHITE%^a%^BLUE%^n%^RESET%^%^GREEN%^.%^RESET%^");
   }
   return("%^BLUE%^Tall mountains%^GREEN%^ fill the entire view to the south, with nothing visible beyond "
"them.  A few more rocky peaks are scattered to the east and west.  Past them to the west is a broad "
"%^YELLOW%^c%^RESET%^%^ORANGE%^or%^BOLD%^nf%^RESET%^%^ORANGE%^ie%^BOLD%^l%^RESET%^%^ORANGE%^d%^GREEN%^, "
"and to the east the sunlight reflects off the broad expanse of "
"%^BLUE%^%^BOLD%^oc%^CYAN%^e%^WHITE%^a%^BLUE%^n%^RESET%^%^GREEN%^.%^RESET%^");
}

string field_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^To the west, past a scattering of %^WHITE%^snow-capped%^GREEN%^ mountain peaks, is "
"a broad, %^WHITE%^snow-covered%^GREEN%^ field.%^RESET%^");
   }
   return("%^GREEN%^To the west, past a scattering of tall mountain peaks, is a broad "
"%^YELLOW%^c%^RESET%^%^ORANGE%^or%^BOLD%^nf%^RESET%^%^ORANGE%^ie%^BOLD%^l%^RESET%^%^ORANGE%^d%^GREEN%^"
".%^RESET%^");
}

string ocean_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Beyond the mountains to the east the ocean is visible, "
"%^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^mm%^BOLD%^e%^RESET%^%^WHITE%^ri%^BOLD%^n%^RESET%^%^WHITE%^g "
"%^GREEN%^faintly in the moon's light.%^RESET%^");
   }
   return("%^GREEN%^Beyond the mountains to the east the ocean is visible, "
"%^BOLD%^%^BLUE%^sp%^CYAN%^a%^WHITE%^r%^BLUE%^kl%^CYAN%^i%^BLUE%^ng%^RESET%^%^GREEN%^ in the "
"sunlight.%^RESET%^");
}

string shrine_desc() {
   if (season(time()) == "winter" && (string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^This shrine is maybe a little over a foot in height, crafted from contrasting "
"stone and covered in a layer of %^WHITE%^snow%^GREEN%^.  A small image has been carved from "
"%^WHITE%^milky-white moonstone%^GREEN%^ that sparkles in the moonlight, of a beautiful woman with long "
"tresses and clad in a flowing gown.  Set within the %^BLACK%^%^BOLD%^dusky granite "
"backdrop%^RESET%^%^GREEN%^ behind the figure of the woman, is a pattern of seven tiny stars, carved of "
"identical %^WHITE%^moonstone%^GREEN%^.  A delicate, %^WHITE%^snow-covered%^GREEN%^ climbing vine trails "
"over the rocks that shelter the shrine, draped with soft-smelling %^BOLD%^%^WHITE%^white "
"blossoms%^RESET%^%^GREEN%^.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("%^GREEN%^This shrine is maybe a little over a foot in height, crafted from contrasting "
"stone and covered in a layer of %^WHITE%^snow%^GREEN%^.  A small image has been carved from "
"%^WHITE%^milky-white moonstone%^GREEN%^, of a beautiful woman with long tresses and clad in a flowing "
"gown.  Set within the %^BLACK%^%^BOLD%^dusky granite backdrop%^RESET%^%^GREEN%^ behind the figure of the "
"woman, is a pattern of seven tiny stars, carved of identical %^WHITE%^moonstone%^GREEN%^.  A delicate, "
"%^WHITE%^snow-covered%^GREEN%^ climbing vine trails over the rocks that shelter the shrine, but the "
"plant's blossoms are closed.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^This shrine is maybe a little over a foot in height, crafted from contrasting "
"stone.  A small image has been carved from %^WHITE%^milky-white moonstone%^GREEN%^ that sparkles in the "
"moonlight, of a beautiful woman with long tresses and clad in a flowing gown.  Set within the "
"%^BLACK%^%^BOLD%^dusky granite backdrop%^RESET%^%^GREEN%^ behind the figure of the woman, is a pattern "
"of seven tiny stars, carved of identical %^WHITE%^moonstone%^GREEN%^.  A delicate climbing vine trails "
"over the rocks that shelter the shrine, draped with soft-smelling %^BOLD%^%^WHITE%^white "
"blossoms%^RESET%^%^GREEN%^.%^RESET%^");
   }
   return("%^GREEN%^This shrine is maybe a little over a foot in height, crafted from contrasting "
"stone.  A small image has been carved from %^WHITE%^milky-white moonstone%^GREEN%^, of a beautiful woman "
"with long tresses and clad in a flowing gown.  Set within the %^BLACK%^%^BOLD%^dusky granite "
"backdrop%^RESET%^%^GREEN%^ behind the figure of the woman, is a pattern of seven tiny stars, carved of "
"identical %^WHITE%^moonstone%^GREEN%^.  A delicate climbing vine trails over the rocks that shelter the "
"shrine, but the plant's blossoms are closed.%^RESET%^");
}

string flowers_desc() {
   if (season(time()) == "winter" && (string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^A delicate, %^WHITE%^snow-covered%^GREEN%^ climbing vine trails over the rocks that "
"shelter the little shrine.  The plant's %^WHITE%^white blossoms%^GREEN%^ are open, releasing a soft, "
"%^MAGENTA%^relaxing%^GREEN%^ scent into the air around you.%^RESET%^");
   }
   if (season(time()) == "winter") {
   return("%^GREEN%^A delicate, %^WHITE%^snow-covered%^GREEN%^ climbing vine trails over the rocks that "
"shelter the little shrine.  The plant's %^WHITE%^white blossoms%^GREEN%^ are closed.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^A delicate climbing vine trails over the rocks that shelter the little shrine.  The "
"plant's %^WHITE%^white blossoms%^GREEN%^ are open, releasing a soft, %^MAGENTA%^relaxing%^GREEN%^ scent "
"into the air around you.%^RESET%^");
   }
   return("%^GREEN%^A delicate climbing vine trails over the rocks that shelter the little shrine.  The "
"plant's %^WHITE%^white blossoms%^GREEN%^ are closed.%^RESET%^");
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^This large, open plateau is covered in a thick layer of %^WHITE%^snow%^GREEN%^, and "
"surrounded by sharp mountainside drops on every side.  To the west, a %^ORANGE%^slender wooden "
"bridge%^GREEN%^ leads back through the dense branches of a small forest within the mountain peaks, which "
"extend as far as the eye can see to the south.  Past the western peaks is a broad field in the distance. "
" Eastward are a few more %^WHITE%^snow-capped%^GREEN%^ mountains, past which is visible the "
"%^BOLD%^%^BLUE%^sp%^CYAN%^a%^WHITE%^r%^BLUE%^kle%^RESET%^%^GREEN%^ of the sun's light as it is reflected "
"by the waves of the ocean.  At the far northern edge of the plateau, surrounded and sheltered by a "
"formation of natural rocks, is a small %^WHITE%^snow-covered shrine%^GREEN%^.%^RESET%^\n");
   }
   return("%^GREEN%^This large, open plateau is covered in %^BOLD%^lush grass%^RESET%^%^GREEN%^, and "
"surrounded by sharp mountainside drops on every side.  To the west, a %^ORANGE%^slender wooden "
"bridge%^GREEN%^ leads back through the dense branches of a small forest within the mountain peaks, which "
"extend as far as the eye can see to the south.  Past the western peaks is a broad field in the distance. "
" Eastward are a few more mountains, past which is visible the "
"%^BOLD%^%^BLUE%^sp%^CYAN%^a%^WHITE%^r%^BLUE%^kle%^RESET%^%^GREEN%^ of the sun's light as it is reflected "
"by the waves of the ocean.  At the far northern edge of the plateau, surrounded and sheltered by a "
"formation of natural rocks, is a small %^WHITE%^shrine%^GREEN%^.%^RESET%^\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^This large, open plateau is covered in a thick layer of %^WHITE%^snow%^GREEN%^, and "
"surrounded by sharp mountainside drops on every side.  To the west, a %^ORANGE%^slender wooden "
"bridge%^GREEN%^ leads back into the %^BLACK%^%^BOLD%^shadows%^RESET%^%^GREEN%^ among the branches of a "
"small forest within the mountain peaks, which extend as far as the eye can see to the south.  Past the "
"western peaks is a broad field in the distance.  Eastward are more %^WHITE%^snow-capped%^GREEN%^ "
"mountains, past which is visible the %^WHITE%^%^BOLD%^pale sheen%^RESET%^%^GREEN%^ of the moon's light "
"as it is reflected by the waves of the ocean.  At the far northern edge of the plateau, surrounded and "
"sheltered by a formation of natural rocks, is a small %^WHITE%^snow-covered shrine%^GREEN%^.%^RESET%^\n");
   }
   return("%^GREEN%^This large, open plateau is covered in %^BOLD%^lush grass%^RESET%^%^GREEN%^, and "
"surrounded by sharp mountainside drops on every side.  To the west, a %^ORANGE%^slender wooden "
"bridge%^GREEN%^ leads back into the %^BLACK%^%^BOLD%^shadows%^RESET%^%^GREEN%^ among the branches of a "
"small forest within the mountain peaks, which extend as far as the eye can see to the south.  Past the "
"western peaks is a broad field in the distance.  Eastward are more mountains, past which is visible the "
"%^WHITE%^%^BOLD%^pale sheen%^RESET%^%^GREEN%^ of the moon's light as it is reflected by the waves of the "
"ocean.  At the far northern edge of the plateau, surrounded and sheltered by a formation of natural "
"rocks, is a small %^WHITE%^shrine%^GREEN%^.%^RESET%^\n");
}

void reset() {
   ::reset();
   picked = random(2)+1;
   if (TO->query_property("blessed")) TO->remove_property("blessed");
   TO->set_property("blessed","selune");
}

void init(){
   ::init();
   add_action("pick_fun","pick");
}

int pick_fun(string str){
   if(!str) {
   notify_fail("Pick what?\n");
   return 0;
   }
   if(str != "flowers" && str != "moonflowers") {
   notify_fail("You do not see that here.\n");
   return 0;
   }
   if(picked == 0) {               
   notify_fail("The blossoms have already been picked.\n");
   return 0;
   }
   tell_object(TP,"You pick a small bunch of the white flowers.");
   tell_room(ETP,""+TPQCN+" picks a small bunch of the white flowers.",TP);
   new(OBJ+"flowers")->move(TP);
   picked = picked -1;
   return 1;
}
