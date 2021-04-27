#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

int randecho, litfire;
string firedesc, firedescnight;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(ROCKY);
    set_travel(LEDGE);
    set_name("Beneath the stone overhang");
    set_short("%^BOLD%^%^BLACK%^Bene%^RESET%^a%^BOLD%^%^BLACK%^th the stone ov%^RESET%^e%^BOLD%^%^BLACK%^rhang%^RESET%^");
    set_long((:TO,"long_desc":));
    set("night long",(:TO,"night_desc":));
    set_smell("default",(:TO,"default_smell":));
    set_listen("default",(:TO,"default_listen":));

    set_items(([
      ({"cliff","ledge","rock","formation"}) : (:TO,"cliff_desc":),
      ({"stairs","staircase"}) : (:TO,"stairs_desc":),
      ({"stones","circle","fire circle","fire","campfire","camp fire"}) : (:TO,"fire_desc":),
      ({"woodpile","wood","firewood"}) : (:TO,"wood_desc":),
      ({"bucket","pail","water"}) : (:TO,"bucket_desc":),
      ({"rings","steel rings","hammock","depression"}) : (:TO,"hammock_desc":),
      ({"ocean","waves"}) : (:TO,"ocean_desc":),
    ]));
    randecho = random(12);
    litfire = 0;
    firedesc = "creating a small fire circle with %^BOLD%^%^BLACK%^bla%^RESET%^c%^BOLD%^%^BLACK%^ken%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^inside";
    firedescnight = "creating a small fire circle with %^BOLD%^%^BLACK%^bla%^RESET%^c%^BOLD%^%^BLACK%^ken%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^BLUE%^inside";
    set_exits(([
      "ascend" : ROOMS"meadow",
    ]));
}

void init() {
   object myfire;
   ::init();
   add_action("light_fire","light");
   add_action("douse_fire","douse");
   if(litfire && !present("smokescreen-obj",TO)) new(OBJ+"smokescreen")->move(TO);
   myfire = present("smokescreen-obj",TO);
   if(!litfire && objectp(myfire)) myfire->remove();
   return 1;
}

string default_smell(string str) {
   if(litfire) return "%^RESET%^%^ORANGE%^The air carries the smell of %^BOLD%^%^BLACK%^bur%^RESET%^%^RED%^ni%^BOLD%^%^BLACK%^ng %^RESET%^%^ORANGE%^wood, clouding "
"the %^BOLD%^%^WHITE%^f%^CYAN%^re%^WHITE%^sh %^RESET%^%^ORANGE%^sea air.%^RESET%^";
   return "%^RESET%^%^ORANGE%^Faint traces of %^BOLD%^%^BLACK%^smoke %^RESET%^%^ORANGE%^still linger here, though most of the smell has been swept away by the "
"%^BOLD%^%^WHITE%^f%^CYAN%^re%^WHITE%^sh %^RESET%^%^ORANGE%^sea air.%^RESET%^";
}

string default_listen(string str) {
   if(litfire) return "%^RESET%^%^GREEN%^The %^BOLD%^%^RED%^f%^YELLOW%^i%^WHITE%^r%^RED%^e%^RESET%^%^GREEN%^ crackles in accompaniment to the pounding of "
"%^CYAN%^w%^RESET%^a%^BOLD%^v%^CYAN%^e%^BLUE%^s %^RESET%^%^GREEN%^far below.%^RESET%^";
   return "%^RESET%^%^GREEN%^The waves of the %^CYAN%^o%^RESET%^c%^BOLD%^e%^CYAN%^a%^BLUE%^n %^RESET%^%^GREEN%^crash against the %^BOLD%^%^BLACK%^r%^RESET%^o"
"%^BOLD%^%^BLACK%^cky cl%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^f %^RESET%^%^GREEN%^far below.%^RESET%^";
}

string long_desc() {
   return("A small section of the %^BOLD%^%^BLACK%^cl%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^f %^RESET%^here seems to have fallen of its own accord over time, into a series of stones which would "
"function well as stairs.  They lead down from the %^GREEN%^g%^BOLD%^ra%^RESET%^%^GREEN%^s%^CYAN%^s%^GREEN%^y %^RESET%^meadow above to grant access to this hidden ledge.  At the bottom of the "
"stairs, the natural formation of the rock provides both a sheltering roof overhang, and a steady ledge upon which to stand and move about.  A perimeter of stones has been arranged here, "
+firedesc+", while a small %^ORANGE%^woodpile %^RESET%^sits further back, along with a bucket of water.  Further into the stone depression of the cliff face, two steel rings have been fixed "
"into the stone, and a %^MAGENTA%^ha%^CYAN%^m%^GREEN%^m%^MAGENTA%^o%^CYAN%^c%^MAGENTA%^k %^RESET%^hangs from them.  Looking out over the lip of the stone ledge reveals the spread of the "
"%^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^far below, its waves surging and crashing against the %^BOLD%^%^WHITE%^j%^YELLOW%^a%^WHITE%^g%^RED%^g%^YELLOW%^e%^WHITE%^d "
"%^RESET%^rocks at the base of the cliff.%^RESET%^\n");
}

string night_desc() {
   return("%^RESET%^%^BLUE%^A small section of the %^BOLD%^%^BLACK%^cl%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^f %^RESET%^%^BLUE%^here seems to have fallen of its own accord over time, into a "
"series of stones which would function well as stairs.  They lead down from the %^GREEN%^g%^BOLD%^ra%^RESET%^%^GREEN%^s%^CYAN%^s%^GREEN%^y %^BLUE%^meadow above to grant access to this hidden "
"ledge.  At the bottom of the stairs, the natural formation of the rock provides both a sheltering roof overhang, and a steady ledge upon which to stand and move about.  A perimeter of stones "
"has been arranged here, "+firedescnight+", while a small %^ORANGE%^woodpile %^BLUE%^sits further back, along with a bucket of water.  Further into the stone depression of the cliff face, two "
"steel rings have been fixed into the stone, and a %^MAGENTA%^ha%^CYAN%^m%^GREEN%^m%^MAGENTA%^o%^CYAN%^c%^MAGENTA%^k %^BLUE%^hangs from them.  Looking out over the lip of the stone ledge "
"reveals the spread of the %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^%^BLUE%^far below, its waves surging and crashing against the %^BOLD%^%^WHITE%^j%^YELLOW%^a%^WHITE%^g"
"%^RED%^g%^YELLOW%^e%^WHITE%^d %^RESET%^%^BLUE%^rocks at the base of the cliff.%^RESET%^\n");
}

string cliff_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^BLUE%^A ledge here has been cut, seemingly by nothing but natural forces, into the %^BOLD%^%^BLACK%^r%^RESET%^ug%^BOLD%^%^BLACK%^ged %^RESET%^%^BLUE%^stone face of the cliff "
"itself.  Flat enough to stand upon and walk around with ease, it bears rough-cut steps leading up and away from one side to the %^GREEN%^g%^BOLD%^ra%^RESET%^%^GREEN%^s%^CYAN%^s%^GREEN%^y "
"%^BLUE%^meadow above.  Rocky ridges and overhangs shelter the ledge from the worst of the weather coming in off the %^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^c%^BLUE%^e%^BOLD%^%^CYAN%^a%^BLUE%^n"
"%^RESET%^%^BLUE%^ beyond, which stretches uninterrupted as far as the eye can see to the eastern horizon.%^RESET%^";
   return "A ledge here has been cut, seemingly by nothing but natural forces, into the %^BOLD%^%^BLACK%^r%^RESET%^ug%^BOLD%^%^BLACK%^ged %^RESET%^stone face of the cliff itself.  Flat enough "
"to stand upon and walk around with ease, it bears rough-cut steps leading up and away from one side to the %^GREEN%^g%^BOLD%^ra%^RESET%^%^GREEN%^s%^CYAN%^s%^GREEN%^y %^RESET%^meadow above.  "
"Rocky ridges and overhangs shelter the ledge from the worst of the weather coming in off the %^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^c%^BLUE%^e%^BOLD%^%^CYAN%^a%^BLUE%^n%^RESET%^ beyond, which "
"stretches uninterrupted as far as the eye can see to the eastern horizon.";
}

string stairs_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^BLUE%^A section of the %^BOLD%^%^BLACK%^cl%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^f %^RESET%^%^BLUE%^seems to have been shaped naturally by wind and weather into what would pass "
"for a stone staircase, for it is clearly still too rough to be formed by any deliberate design.  The length and width of the stones are rugged and uneven, and it would be wise to step "
"carefully.  They lead down from the %^GREEN%^g%^BOLD%^ra%^RESET%^%^GREEN%^s%^CYAN%^s%^GREEN%^y %^BLUE%^meadow above, to this sheltered ledge overlooking the %^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^c"
"%^BLUE%^e%^BOLD%^%^CYAN%^a%^BLUE%^n%^RESET%^%^BLUE%^.%^RESET%^";
   return "A section of the %^BOLD%^%^BLACK%^cl%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^f %^RESET%^seems to have been shaped naturally by wind and weather into what would pass for a stone "
"staircase, for it is clearly still too rough to be formed by any deliberate design.  The length and width of the stones are rugged and uneven, and it would be wise to step carefully.  They "
"lead down from the %^GREEN%^g%^BOLD%^ra%^RESET%^%^GREEN%^s%^CYAN%^s%^GREEN%^y %^RESET%^meadow above, to this sheltered ledge overlooking the %^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^c%^BLUE%^e"
"%^BOLD%^%^CYAN%^a%^BLUE%^n%^RESET%^.";
}

string fire_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (litfire)
       return "%^RESET%^%^BLUE%^Prominently within the center of the ledge lies a ring of %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^nes%^RESET%^%^BLUE%^, uneven of size and shape.  They "
"encircle a %^RED%^b%^BOLD%^l%^RESET%^%^RED%^az%^YELLOW%^i%^RED%^n%^RESET%^%^RED%^g %^BLUE%^fire which has been built up within the center, and is sheltered enough by the outcroppings of stone "
"that it remains burning merrily without interference from the wind and weather.  Nearby sits a small %^ORANGE%^woodpile%^BLUE%^, well stocked for future use, and a pail of %^BOLD%^%^BLUE%^wa"
"%^CYAN%^te%^BLUE%^r %^RESET%^%^BLUE%^by which you could douse the flames.%^RESET%^";
     return "%^RESET%^%^BLUE%^Prominently within the center of the ledge lies a ring of %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^nes%^RESET%^%^BLUE%^, uneven of size and shape.  They "
"enclose a blackened fire circle, still set about with a few %^BOLD%^%^BLACK%^c%^RED%^h%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rr%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d %^RESET%^%^BLUE%^remnants as "
"evidence of the last that was set here.  Nearby sits a well-stocked %^ORANGE%^woodpile%^BLUE%^, from which you could easily try to light a fire.  A pail of %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^"
"r %^RESET%^%^BLUE%^sits beside it, to be used to put out the fire once finished.%^RESET%^";
   }
   if (litfire)
     return "Prominently within the center of the ledge lies a ring of %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^nes%^RESET%^, uneven of size and shape.  They encircle a %^RED%^b%^BOLD%^l"
"%^RESET%^%^RED%^az%^YELLOW%^i%^RED%^n%^RESET%^%^RED%^g %^RESET%^fire which has been built up within the center, and is sheltered enough by the outcroppings of stone that it remains burning "
"merrily without interference from the wind and weather.  Nearby sits a small %^ORANGE%^woodpile%^RESET%^, well stocked for future use, and a pail of %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^r "
"%^RESET%^by which you could douse the flames.";
   return "Prominently within the center of the ledge lies a ring of %^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^nes%^RESET%^, uneven of size and shape.  They enclose a blackened fire circle"
", still set about with a few %^BOLD%^%^BLACK%^c%^RED%^h%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rr%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d %^RESET%^remnants as evidence of the last that was set here.  "
"Nearby sits a well-stocked %^ORANGE%^woodpile%^RESET%^, from which you could easily try to light a fire.  A pail of %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^r %^RESET%^sits beside it, to be used "
"to put out the fire once finished.";
}

string wood_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^BLUE%^A %^ORANGE%^woodpile%^BLUE%^ of fallen branches, small but well-stocked, sits in the shelter of several rocks, a short distance from the fire circle.  It would save a great "
"deal of effort, rather than searching the %^GREEN%^fo%^BOLD%^r%^RESET%^%^GREEN%^est %^BLUE%^above for dry wood.  A pail of %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^r %^RESET%^%^BLUE%^sits beside "
"it, ready to put out a blaze if needed.%^RESET%^";
   return "A %^ORANGE%^woodpile%^RESET%^ of fallen branches, small but well-stocked, sits in the shelter of several rocks, a short distance from the fire circle.  It would save a great deal of "
"trouble, rather than searching the %^GREEN%^fo%^BOLD%^r%^RESET%^%^GREEN%^est %^RESET%^above for dry wood.  A pail of %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^r %^RESET%^sits beside it, ready to put "
"out a blaze if needed.";
}

string bucket_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^BLUE%^A pail filled with %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^r %^RESET%^%^BLUE%^sits a short way off, for use to douse a fire.  A small stack of %^ORANGE%^firewood %^BLUE%^has "
"been stacked beside it, to spare the immediate effort of gathering dry wood.%^RESET%^";
   return "A pail filled with %^BOLD%^%^BLUE%^wa%^CYAN%^te%^BLUE%^r %^RESET%^sits a short way off, for use to douse a fire.  A small stack of %^ORANGE%^firewood %^RESET%^has "
"been stacked beside it, to spare the immediate effort of gathering dry wood.";
}

string hammock_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^BLUE%^A sizeable depression further back into the ledge provides space enough for a comfortable hammock, which has been slung from a pair of %^BOLD%^%^BLACK%^ste%^WHITE%^e"
"%^BLACK%^l %^RESET%^%^BLUE%^rings embedded within the stone itself.  The hammock consists of a %^MAGENTA%^c%^CYAN%^o%^MAGENTA%^l%^GREEN%^o%^MAGENTA%^rf%^CYAN%^u%^MAGENTA%^l %^BLUE%^woven "
"length of canvas, supported by more sturdy rope netting that has been interwoven to easily support the weight of one or more occupants.  It would certainly provide a relaxing place to enjoy "
"the %^CYAN%^tra%^GREEN%^nq%^CYAN%^uil%^GREEN%^i%^CYAN%^ty %^BLUE%^of this hidden ledge.%^RESET%^";
   return "A sizeable depression further back into the ledge provides space enough for a comfortable hammock, which has been slung from a pair of %^BOLD%^%^BLACK%^ste%^WHITE%^e%^BLACK%^l "
"%^RESET%^rings embedded within the stone itself.  The hammock consists of a %^MAGENTA%^c%^CYAN%^o%^MAGENTA%^l%^GREEN%^o%^MAGENTA%^rf%^CYAN%^u%^MAGENTA%^l %^RESET%^woven length of canvas, "
"supported by more sturdy rope netting that has been interwoven to easily support the weight of one or more occupants.  It would certainly provide a relaxing place to enjoy the %^CYAN%^tra"
"%^GREEN%^nq%^CYAN%^uil%^GREEN%^i%^CYAN%^ty %^RESET%^of this hidden ledge.";
}

string ocean_desc() {
   object outside, tracker;
   string weather;
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^BLUE%^The %^BOLD%^%^BLUE%^s%^CYAN%^u%^WHITE%^r%^RESET%^%^CYAN%^g%^RESET%^i%^BOLD%^%^CYAN%^n%^BLUE%^g %^RESET%^%^BLUE%^waters of the ocean stretch from the base of the cliff to "
"the far eastern horizon, gleaming %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r %^RESET%^%^BLUE%^under the moonlight.  Looking over the lip of the ledge, you can "
"see where the waves crash and break against the %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BLACK%^g%^RED%^g%^WHITE%^e%^BLACK%^d %^RESET%^%^BLUE%^rocks at the base of the cliff.%^RESET%^";
   outside = find_object_or_load(ROOMS"meadow");
   tracker = new(OBJ"strawberries");
   tracker->move(outside);
   weather = (string)WEATHER_D->Check_Weather(tracker);
   tracker->remove();
   if(strsrch(weather,"snow") != -1)
     return "The %^BOLD%^%^BLUE%^s%^CYAN%^u%^WHITE%^r%^RESET%^%^CYAN%^g%^RESET%^i%^BOLD%^%^CYAN%^n%^BLUE%^g %^RESET%^waters of the ocean stretch from the base of the cliff to the far eastern "
"horizon, though they fade to a blur beyond the %^BOLD%^%^WHITE%^ve%^RESET%^i%^BOLD%^%^WHITE%^l %^RESET%^of falling snow.  Looking over the lip of the ledge, you can see where the waves crash "
"and break against the %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BLACK%^g%^RED%^g%^WHITE%^e%^BLACK%^d %^RESET%^rocks at the base of the cliff.";
   if(strsrch(weather,"raining") != -1)
     return "The %^BOLD%^%^BLUE%^s%^CYAN%^u%^WHITE%^r%^RESET%^%^CYAN%^g%^RESET%^i%^BOLD%^%^CYAN%^n%^BLUE%^g %^RESET%^waters of the ocean stretch from the base of the cliff to the far eastern "
"horizon, though they grow %^CYAN%^cl%^BLUE%^o%^CYAN%^u%^RESET%^de%^CYAN%^d %^RESET%^and hazy beyond a wall of falling rain.  Looking over the lip of the ledge, you can see where the waves "
"crash and break against the %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BLACK%^g%^RED%^g%^WHITE%^e%^BLACK%^d %^RESET%^rocks at the base of the cliff.";
   if(strsrch(weather,"mostly cloudy") != -1 || strsrch(weather,"very cloudy") != -1)
     return "The %^BOLD%^%^BLUE%^s%^CYAN%^u%^WHITE%^r%^RESET%^%^CYAN%^g%^RESET%^i%^BOLD%^%^CYAN%^n%^BLUE%^g %^RESET%^waters of the ocean stretch from the base of the cliff to the far eastern "
"horizon, muted to dull gray by the %^BOLD%^%^BLACK%^lo%^RESET%^om%^BOLD%^%^BLACK%^ing %^RESET%^cloudcover above.  Looking over the lip of the ledge, you can see where the waves crash and break "
"against the %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BLACK%^g%^RED%^g%^WHITE%^e%^BLACK%^d %^RESET%^rocks at the base of the cliff.";
   return "The %^BOLD%^%^BLUE%^s%^CYAN%^u%^WHITE%^r%^RESET%^%^CYAN%^g%^RESET%^i%^BOLD%^%^CYAN%^n%^BLUE%^g %^RESET%^waters of the ocean stretch from the base of the cliff to the far eastern "
"horizon, %^YELLOW%^je%^BLUE%^w%^YELLOW%^el-b%^WHITE%^r%^CYAN%^i%^YELLOW%^ght %^RESET%^as they catch and reflect the sunlight.  Looking over the lip of the ledge, you can see where the waves "
"crash and break against the %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BLACK%^g%^RED%^g%^WHITE%^e%^BLACK%^d %^RESET%^rocks at the base of the cliff.";
}

int light_fire(string str) {
   if(!str) return 0;
   if(str != "fire") return 0;
   if(litfire) {
     tell_object(TP,"%^BOLD%^%^WHITE%^There is already a fire burning within the circle.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You add a few pieces of wood and tinder to the circle, and spark a light to the fire.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" adds a few pieces of wood and tinder to the circle, and sparks a light to the fire.%^RESET%^",TP);
   litfire = 1;
   firedesc = "where a cozy %^RED%^ca%^BOLD%^m%^RESET%^%^RED%^pf%^YELLOW%^i%^WHITE%^r%^RESET%^%^RED%^e %^RESET%^blazes brightly";
   firedescnight = "where a cozy %^RED%^ca%^BOLD%^m%^RESET%^%^RED%^pf%^YELLOW%^i%^WHITE%^r%^RESET%^%^RED%^e %^RESET%^%^BLUE%^blazes brightly";
   call_out("blaze",roll_dice(2,8));
   if(!present("smokescreen-obj",TO)) new(OBJ+"smokescreen")->move(TO);
   return 1;
}

void blaze() {
   if(!objectp(TO)) return;
   if(!litfire) return;
   tell_room(TO,"%^RED%^The fire takes hold of the dry wood and begins to %^BOLD%^bla%^YELLOW%^z%^RED%^e %^RESET%^%^RED%^and crackle merrily.%^RESET%^");
}

int douse_fire(string str) {
   object myfire, *scryspell;
   if(!str) return 0;
   if(str != "fire") return 0;
   if(!litfire) {
     tell_object(TP,"%^BOLD%^%^WHITE%^There is no fire within the circle, only blackened remains of the last.%^RESET%^");
     return 1;
   }
   myfire = present("smokescreen-obj",TO);
   if(myfire->query_property("magic mirror")) {
     scryspell = ({});
     scryspell += myfire->query_property("spelled");
     if(sizeof(scryspell)) scryspell[0]->dest_effect();
   }
   if(objectp(myfire)) myfire->remove();
   tell_object(TP,"%^BOLD%^%^WHITE%^You lift the nearby bucket of water to douse the fire, and thick smoke billows up as the flames go out.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" lifts the nearby bucket of water to douse the fire, and thick smoke billows up as the flames go out.%^RESET%^",TP);
   litfire = 0;
   firedesc = "creating a small fire circle with %^BOLD%^%^BLACK%^bla%^RESET%^c%^BOLD%^%^BLACK%^ken%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^inside";
   firedescnight = "creating a small fire circle with %^BOLD%^%^BLACK%^bla%^RESET%^c%^BOLD%^%^BLACK%^ken%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^BLUE%^inside";
   return 1;
}

void reset() {
   string weather;
   object tracker, outside;
   ::reset();
   switch(randecho) {
     case 0..1:
       if(litfire) { tell_room(TO,"%^BOLD%^%^CYAN%^A cool, fresh breeze rolls in from the ocean, toying with the lazy tendril of %^BOLD%^%^BLACK%^sm%^RESET%^ok"
"%^BOLD%^%^BLACK%^e %^CYAN%^rising from the fire and scattering it to all directions.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^CYAN%^A cool, fresh breeze rolls in from the ocean, chasing away the last hints of %^BOLD%^%^BLACK%^sm%^RESET%^ok%^BOLD%^%^BLACK%^e "
"%^CYAN%^from the alcove's last fire.%^RESET%^");
     break;
     case 2..3:
         if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BLUE%^Somewhere distant, deep within the forest above, the lone howl of a "
"%^BOLD%^%^BLACK%^wolf %^RESET%^%^BLUE%^breaks the night's serenity.%^RESET%^"); break; }
         tell_room(TO,"%^ORANGE%^A chorus of %^BOLD%^%^WHITE%^ch%^CYAN%^e%^WHITE%^erf%^MAGENTA%^u%^WHITE%^l %^RESET%^%^ORANGE%^twittering drifts down from the "
"meadow above.%^RESET%^");
     break;
     case 4..5:
       tell_room(TO,"%^BOLD%^%^CYAN%^Another wave breaks against the %^BOLD%^%^BLACK%^j%^YELLOW%^a%^BLACK%^g%^RED%^g%^WHITE%^e%^BLACK%^d %^CYAN%^cliffs "
"far below, a frequent but uneven rhythm that is oddly soothing to the senses.%^RESET%^");
     break;
     case 6..7:
       if(litfire) { tell_room(TO,"%^BOLD%^%^WHITE%^A strong wind picks up off the ocean, and though the %^BLACK%^ro%^RESET%^%^ORANGE%^ck%^BOLD%^%^BLACK%^y "
"%^WHITE%^outcroppings shield the ledge from the worst of it, the lit fire is still cast to %^RESET%^%^RED%^fl%^BOLD%^i%^WHITE%^c%^RESET%^%^RED%^ke%^YELLOW%^r"
"%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g %^BOLD%^%^WHITE%^wildly.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^WHITE%^A strong wind picks up off the ocean, though the %^BLACK%^ro%^RESET%^%^ORANGE%^ck%^BOLD%^%^BLACK%^y %^WHITE%^outcroppings "
"shield the ledge from the worst of its force.%^RESET%^");
     break;
     case 8..9:
       outside = find_object_or_load(ROOMS"meadow");
       tracker = new(OBJ"strawberries");
       tracker->move(outside);
       weather = (string)WEATHER_D->Check_Weather(tracker);
       tracker->remove();
       if(strsrch(weather,"snow") != -1) { tell_room(TO,"%^BOLD%^%^WHITE%^Snowflakes drift down from the %^RESET%^cl%^BOLD%^%^BLACK%^o%^RESET%^ud"
"%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^WHITE%^sky above, casting a white veil over the distant ocean.%^RESET%^"); break; }
       if(strsrch(weather,"raining") != -1){ tell_room(TO,"%^BLUE%^The sound of falling %^BOLD%^r%^CYAN%^a%^BLUE%^in %^RESET%^%^BLUE%^fills the "
"air, even as the fresh smell it brings drifts up to the ledge on the breeze.%^RESET%^"); break; }
       if(strsrch(weather,"mostly cloudy") != -1 || strsrch(weather,"very cloudy") != -1) {
         tell_room(TO,"%^BOLD%^%^BLUE%^An ominous %^RESET%^%^MAGENTA%^rum%^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLUE%^comes from the clouds "
"above, darkening the sky beyond the ledge.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BOLD%^%^BLACK%^Not even a single cloud interrupts the view from the ledge "
"of the clear night sky above, the distant stars %^RESET%^spa%^BOLD%^%^WHITE%^r%^RESET%^kli%^BOLD%^%^WHITE%^n%^RESET%^g %^BOLD%^%^BLACK%^brightly.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "twilight") { tell_room(TO,"%^RESET%^%^ORANGE%^The setting sun casts lengthening %^BLUE%^shadows "
"%^ORANGE%^across the stone ledge that fade into its darkened corners.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^WHITE%^The %^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^WHITE%^of the rising "
"sun inches in across the stone floor, slowly drawing back as the shining orb lifts higher into the sky.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^WHITE%^Bright %^YELLOW%^sunl%^WHITE%^i%^YELLOW%^ght %^WHITE%^floods in across the stone ledge, warming the cold stone to a "
"pleasantly comfortable temperature.%^RESET%^");
     break;
     default:
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^MAGENTA%^From somewhere far above in the forest trees carries the distant hoot of a "
"lone %^RESET%^o%^ORANGE%^w%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^BLUE%^A warbling chorus of birdsong from the meadow above greets the "
"%^YELLOW%^d%^MAGENTA%^a%^RED%^w%^YELLOW%^n%^BLUE%^, as the sun peeks over the horizon.%^RESET%^"); break; }
       tell_room(TO,"%^ORANGE%^A chorus of %^BOLD%^%^WHITE%^ch%^CYAN%^e%^WHITE%^erf%^MAGENTA%^u%^WHITE%^l %^RESET%^%^ORANGE%^twittering drifts down from the "
"meadow above.%^RESET%^");
     break;
   }
   randecho += roll_dice(2,2);
   randecho = randecho%12;
}