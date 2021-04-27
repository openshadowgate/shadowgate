#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit "/std/pier";

int strawberries, randecho;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(HEAVY_FOREST);
    set_travel(GAME_TRACK);
    set_name("An open meadow");
    set_short("%^RESET%^%^GREEN%^An o%^BOLD%^p%^RESET%^%^GREEN%^en mea%^BOLD%^d%^RESET%^%^GREEN%^ow%^RESET%^");
    set_long((:TO,"long_desc":));
    set("night long",(:TO,"night_desc":));
    set_smell("default","%^RESET%^%^ORANGE%^The clean, crisp air bears the %^BOLD%^%^WHITE%^sa%^CYAN%^lt%^WHITE%^y %^RESET%^%^ORANGE%^tang of the sea.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^The waves of the %^CYAN%^o%^RESET%^c%^BOLD%^e%^CYAN%^a%^BLUE%^n %^RESET%^%^GREEN%^crash against the %^BOLD%^%^BLACK%^r%^RESET%^o"
"%^BOLD%^%^BLACK%^cky cl%^RESET%^%^ORANGE%^if%^BOLD%^%^BLACK%^f %^RESET%^%^GREEN%^far below.%^RESET%^");

    set_items(([
      ({"path","trees","forest"}) : (:TO,"forest_desc":),
      "shadows" : (:TO,"shadows_desc":),
      ({"meadow","grass"}) : (:TO,"grass_desc":),
      "snow" : (:TO,"snow_desc":),
      ({"shrubs","plants"}) : (:TO,"shrubs_desc":),
      ({"flowers","wildflowers"}) : (:TO,"flowers_desc":),
      ({"outcropping","cliff","lip","stone"}) : (:TO,"cliff_desc":),
      ({"ocean","sea","waves"}) : (:TO,"ocean_desc":),
      ({"tree","willow","weeping willow","branches","foliage"}) : (:TO,"tree_desc":),
      "brook" : (:TO,"brook_desc":),
      "frost" : (:TO,"frost_desc":),
    ]));
    randecho = random(12);
    strawberries = roll_dice(2,4);
    set_search("tree",(:TO,"search_room":));
    set_search("willow",(:TO,"search_room":));
    set_search("cliff",(:TO,"search_room":));
    set_search("ledge",(:TO,"search_room":));
    set_exits(([
      "west" : ROOMS"path3",
      "tree" : ROOMS"tree",
    ]));
    set_invis_exits(({"tree"}));
    set_door("door",ROOMS"tree","tree","hasnokey","lock");
    set_locked("door",1);
    lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"lock"); // very simple syntax but no keyhole; not designed to be lockpicked.
    set_lock_description("door","lock","%^BOLD%^%^BLACK%^No handle or keyhole are visible within the gnarled bark.%^RESET%^");
    set_door_description("door","%^RESET%^Only readily apparent when opened, this door seems to be part of the %^ORANGE%^t%^GREEN%^r%^ORANGE%^ee %^RESET%^itself, and vanishes almost entirely "
"from sight when shut.  Smooth %^ORANGE%^wooden %^RESET%^hinges allow it to open and close soundlessly, and its entire outer surface is covered with the same gnarled, %^BOLD%^%^WHITE%^s"
"%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark as the rest of the willow.");
    set_string("door", "close", "The wooden door swings shut with only a faint click, and its outline merges with the tree's bark to vanish from sight.");
    set_water_body("brook");
    set_fish(([ "spotted sunfish": 3, "golden perch": 4, "whitetail minnow": 2, "brown trout": 6 ]));
}

void init() {
   ::init();
   add_action("pick_fun","pick");
   add_action("ledge_fun","descend");
   add_action("door_fun","press");
   if(userp(TP) && !present("eldathynwardxxx",TP)) new(OBJ"eldathynward")->move(TP);
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^RESET%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^breaches the threshold of the forest here, leading out from amidst the thick-set trees into a "
"%^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^RESET%^.  A thick blanket of %^BOLD%^%^WHITE%^snow %^RESET%^covers the ground, leaving only the most resilient of %^GREEN%^p%^ORANGE%^l%^GREEN%^ants "
"%^RESET%^to force their way through.  At the distant side of the clearing, an outcropping of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e %^RESET%^emerges "
"from beneath the powdery white, jutting out high above the surging %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^below.  Within the center of the clearing rises a weeping "
"willow of massive size, impossibly old and twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^branches claw towards "
"the sky and reach out over the cliff's edge, trailing a veil of withered foliage turned bone-white with %^BOLD%^%^CYAN%^f%^WHITE%^ro%^CYAN%^st%^RESET%^.  A solid layer of ice coats the tiny "
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^that meanders from amidst the forest trees, a faint trickle of water only apparent as it passes over the jagged "
"precipice and into the sea.  The entire area posesses an %^CYAN%^an%^GREEN%^ci%^CYAN%^ent bea%^BOLD%^u%^RESET%^%^CYAN%^ty%^RESET%^, untouched by civilization.\n");
   }
   if (season(time()) == "autumn") {
     return("%^RESET%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^breaches the threshold of the forest here, leading out from amidst the thick-set trees into a "
"%^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^RESET%^.  Soft, thick %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^cushions your feet, dotted here and there with small %^GREEN%^s%^ORANGE%^h"
"%^GREEN%^rubs %^RESET%^and patches of %^YELLOW%^wi%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^.  At the distant side of the clearing the "
"grass grows thin, fading to a %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e lip %^RESET%^that juts out high above the surging %^BOLD%^%^BLUE%^o%^CYAN%^c"
"%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^below.  Within the center of the clearing rises a weeping willow of massive size, impossibly old and twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^branches claw towards the sky and reach out over the cliff's edge, trailing a veil of %^ORANGE%^f%^RED%^l"
"%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^RESET%^foliage.  A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k "
"%^RESET%^meanders from amidst the forest trees, bubbling over earth and stone to tumble finally over the jagged precipice and into the sea.  The entire area posesses an %^CYAN%^an%^GREEN%^ci"
"%^CYAN%^ent bea%^BOLD%^u%^RESET%^%^CYAN%^ty%^RESET%^, untouched by civilization.\n");
   }
   return("%^RESET%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^breaches the threshold of the forest here, leading out from amidst the thick-set trees into a "
"%^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^RESET%^.  Soft, thick %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^cushions your feet, dotted here and there with small %^GREEN%^s%^ORANGE%^h"
"%^GREEN%^rubs %^RESET%^and patches of %^YELLOW%^wi%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^.  At the distant side of the clearing the "
"grass grows thin, fading to a %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e lip %^RESET%^that juts out high above the surging %^BOLD%^%^BLUE%^o%^CYAN%^c"
"%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^below.  Within the center of the clearing rises a weeping willow of massive size, impossibly old and twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^branches claw towards the sky and reach out over the cliff's edge, trailing a veil of %^GREEN%^ve%^BOLD%^rd"
"%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^t %^RESET%^foliage.  A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^meanders from amidst the forest trees, "
"bubbling over earth and stone to tumble finally over the jagged precipice and into the sea.  The entire area posesses an %^CYAN%^an%^GREEN%^ci%^CYAN%^ent bea%^BOLD%^u%^RESET%^%^CYAN%^ty"
"%^RESET%^, untouched by civilization.\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^RESET%^%^BLUE%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^breaches the threshold of the forest here, leading out from the shadows of the thick-set "
"trees into a %^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^BLUE%^.  %^BOLD%^%^WHITE%^M%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^ spills across the thick blanket of "
"%^BOLD%^%^WHITE%^snow %^RESET%^%^BLUE%^covering the ground, leaving only the most resilient of %^GREEN%^p%^ORANGE%^l%^GREEN%^ants %^BLUE%^to force their way through.  At the distant side of "
"the clearing, an outcropping of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^emerges from beneath the powdery white, jutting out high above "
"the surging %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^%^BLUE%^below.  Within the center of the clearing rises a weeping willow of massive size, impossibly old and "
"twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^branches claw towards the dark sky and reach out over "
"the cliff's edge, trailing a veil of withered foliage turned bone-white with %^BOLD%^%^CYAN%^f%^WHITE%^ro%^CYAN%^st%^RESET%^%^BLUE%^.  A solid layer of ice coats the tiny %^BOLD%^%^BLUE%^b"
"%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^%^BLUE%^that meanders from amidst the forest trees, a faint trickle of water only apparent as it passes over the jagged precipice and "
"into the sea.  The entire area posesses an %^CYAN%^an%^GREEN%^ci%^CYAN%^ent bea%^BOLD%^u%^RESET%^%^CYAN%^ty%^BLUE%^, untouched by civilization.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     return("%^RESET%^%^BLUE%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^breaches the threshold of the forest here, leading out from the shadows of the thick-set "
"trees into a %^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^BLUE%^.  %^BOLD%^%^WHITE%^M%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^ spills across the soft, thick "
"%^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^%^BLUE%^that cushions your feet, dotted here and there with small %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs %^BLUE%^and patches of "
"%^YELLOW%^wi%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^%^BLUE%^.  At the distant side of the clearing the grass grows thin, fading to a "
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e lip %^RESET%^%^BLUE%^that juts out high above the surging %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n "
"%^RESET%^%^BLUE%^below.  Within the center of the clearing rises a weeping willow of massive size, impossibly old and twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v"
"%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^branches claw towards the dark sky and reach out over the cliff's edge, trailing a veil of %^ORANGE%^f%^RED%^l%^ORANGE%^a"
"%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^BLUE%^foliage.  A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^%^BLUE%^"
"meanders from amidst the forest trees, bubbling over earth and stone to tumble finally over the jagged precipice and into the sea.  The entire area posesses an %^CYAN%^an%^GREEN%^ci%^CYAN%^ent "
"bea%^BOLD%^u%^RESET%^%^CYAN%^ty%^BLUE%^, untouched by civilization.%^RESET%^\n");
   }
   if (season(time()) == "summer") {
     return("%^RESET%^%^BLUE%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^breaches the threshold of the forest here, leading out from the shadows of the thick-set "
"trees into a %^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^BLUE%^.  %^BOLD%^%^WHITE%^M%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^ spills across the soft, thick "
"%^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^%^BLUE%^that cushions your feet, dotted here and there with small %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs %^BLUE%^and patches of "
"%^YELLOW%^wi%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^%^BLUE%^.  At the distant side of the clearing the grass grows thin, fading to a "
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e lip %^RESET%^%^BLUE%^that juts out high above the surging %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n "
"%^RESET%^%^BLUE%^below.  Within the center of the clearing rises a weeping willow of massive size, impossibly old and twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v"
"%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^branches claw towards the dark sky and reach out over the cliff's edge, trailing a veil of %^GREEN%^ve%^BOLD%^rd%^RESET%^"
"%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage.  A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^%^BLUE%^meanders from amidst the forest trees, bubbling "
"over earth and stone to tumble finally over the jagged precipice and into the sea.  Tiny dots of light wink between the leaves and dance across the ground, resolving themselves as countless "
"%^YELLOW%^fi%^GREEN%^r%^YELLOW%^ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^BLUE%^.  The entire area posesses an %^CYAN%^an%^GREEN%^ci%^CYAN%^ent bea%^BOLD%^u%^RESET%^%^CYAN%^ty"
"%^BLUE%^, untouched by civilization.%^RESET%^\n");
   }
   return("%^RESET%^%^BLUE%^The %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^breaches the threshold of the forest here, leading out from the shadows of the thick-set "
"trees into a %^MAGENTA%^m%^RED%^e%^MAGENTA%^adow%^BLUE%^.  %^BOLD%^%^WHITE%^M%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^ spills across the soft, thick "
"%^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^%^BLUE%^that cushions your feet, dotted here and there with small %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs %^BLUE%^and patches of "
"%^YELLOW%^wi%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^%^BLUE%^.  At the distant side of the clearing the grass grows thin, fading to a "
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e lip %^RESET%^%^BLUE%^that juts out high above the surging %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a"
"%^CYAN%^n %^RESET%^%^BLUE%^below.  Within the center of the clearing rises a weeping willow of massive size, impossibly old and twisted as its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^branches claw towards the dark sky and reach out over the cliff's edge, trailing a veil of %^GREEN%^ve%^BOLD%^rd"
"%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage.  A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^%^BLUE%^meanders from amidst the forest trees, "
"bubbling over earth and stone to tumble finally over the jagged precipice and into the sea.  The entire area posesses an %^CYAN%^an%^GREEN%^ci%^CYAN%^ent bea%^BOLD%^u%^RESET%^%^CYAN%^ty%^BLUE%^"
", untouched by civilization.%^RESET%^\n");
}

string forest_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^RESET%^%^BLUE%^Shadows dance among the thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^%^BLUE%^that borders this meadow on all sides save to the east, where "
"the %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag%^BOLD%^%^BLACK%^ged %^RESET%^%^BLUE%^cliff's edge drops abruptly away to meet the raging sea far below.  Bare, grasping branches and tangled "
"undergrowth make passage difficult, save where a faint %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^winds away through the trees to the west.  Moonlight gleams on the "
"thick pall of %^BOLD%^%^WHITE%^s%^RESET%^no%^BOLD%^%^WHITE%^w %^RESET%^%^BLUE%^that lies across the brittle branches and sparse foliage that still remains.%^RESET%^");
     }
     if (season(time()) == "autumn") {
       return("%^RESET%^%^BLUE%^Shadows dance among the thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^%^BLUE%^that borders this meadow on all sides save to the east, where "
"the %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag%^BOLD%^%^BLACK%^ged %^RESET%^%^BLUE%^cliff's edge drops abruptly away to meet the raging sea far below.  Dense foliage and undergrowth, painted "
"with haphazard splashes of %^ORANGE%^go%^YELLOW%^l%^RESET%^%^ORANGE%^d %^RESET%^%^BLUE%^and %^RED%^sc%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^le%^RESET%^%^RED%^t %^BLUE%^by the fading season, blot "
"out what meagre moonlight falls from above and make passage difficult, save where a faint %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^winds away through the trees to "
"the west.%^RESET%^");
     }
     if (season(time()) == "summer") {
       return("%^RESET%^%^BLUE%^Shadows dance among the thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^%^BLUE%^that borders this meadow on all sides save to the east, where "
"the %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag%^BOLD%^%^BLACK%^ged %^RESET%^%^BLUE%^cliff's edge drops abruptly away to meet the raging sea far below.  Dense foliage and undergrowth blot out "
"what meagre moonlight falls from above and make passage difficult, save where a faint %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^winds away through the trees to the "
"west.  Glowing %^YELLOW%^fi%^GREEN%^r%^YELLOW%^ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^BLUE%^ add cheery dots of light to the eaves of the darkened forest.%^RESET%^");
     }
     return("%^RESET%^%^BLUE%^Shadows dance among the thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^%^BLUE%^that borders this meadow on all sides save to the east, where the "
"%^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag%^BOLD%^%^BLACK%^ged %^RESET%^%^BLUE%^cliff's edge drops abruptly away to meet the raging sea far below.  Dense foliage and undergrowth blot out what "
"meagre moonlight falls from above and make passage difficult, save where a faint %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^winds away through the trees to the "
"west.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("Thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^borders this meadow on all sides save to the east, where the %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag"
"%^BOLD%^%^BLACK%^ged %^RESET%^cliff's edge drops abruptly away to meet the raging sea far below.  Bare, grasping branches and tangled undergrowth make passage difficult, save where a faint "
"%^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^winds away through the trees to the west.  A thick pall of %^BOLD%^%^WHITE%^s%^RESET%^no%^BOLD%^%^WHITE%^w %^RESET%^lies "
"across the brittle branches and sparse foliage that still remains.");
   }
   if (season(time()) == "autumn") {
     return("Thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^borders this meadow on all sides save to the east, where the %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag"
"%^BOLD%^%^BLACK%^ged %^RESET%^cliff's edge drops abruptly away to meet the raging sea far below.  Dense foliage and undergrowth, painted with haphazard splashes of %^ORANGE%^go%^YELLOW%^l"
"%^RESET%^%^ORANGE%^d %^RESET%^and %^RED%^sc%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^le%^RESET%^%^RED%^t %^RESET%^by the fading season, blot out most of the daylight and make passage difficult, save "
"where a faint %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^winds away through the trees to the west.");
   }
   return("Thick %^GREEN%^f%^BOLD%^or%^RESET%^%^GREEN%^es%^BOLD%^t %^RESET%^borders this meadow on all sides save to the east, where the %^BOLD%^%^BLACK%^j%^RESET%^%^ORANGE%^ag"
"%^BOLD%^%^BLACK%^ged %^RESET%^cliff's edge drops abruptly away to meet the raging sea far below.  Dense foliage and undergrowth blot out most of the daylight and make passage difficult, save "
"where a faint %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^winds away through the trees to the west.");
}

string shadows_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return forest_desc();
   }
   return("You do not notice that here.");
}

string grass_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^RESET%^%^BLUE%^Not even a single front of %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^%^BLUE%^can be seen from beneath the thick carpet of %^BOLD%^%^WHITE%^s"
"%^RESET%^n%^BOLD%^%^WHITE%^ow %^RESET%^%^BLUE%^that lies across the meadow.  Only the hardiest of %^GREEN%^plan%^ORANGE%^t%^GREEN%^s %^BLUE%^force their way up through this frosty "
"layer.%^RESET%^");
     }
     return("%^RESET%^%^BLUE%^Thick, soft %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^%^BLUE%^carpets the meadow, the longer blades and seed heads waving gently in the breeze.  "
"Colorful %^YELLOW%^wi%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^%^BLUE%^ dot the emerald expanse with no apparent order or tending, "
"sprouting alongside the occasional small %^GREEN%^shr%^ORANGE%^u%^GREEN%^b%^BLUE%^ or creeping groundcover.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("Not even a single front of %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^can be seen from beneath the thick carpet of %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^WHITE%^ow "
"%^RESET%^that lies across the meadow.  Only the hardiest of %^GREEN%^plan%^ORANGE%^t%^GREEN%^s %^RESET%^force their way up through this frosty layer.");
   }
   return("Thick, soft %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^carpets the meadow, the longer blades and seed heads waving gently in the breeze.  Colorful %^YELLOW%^wi"
"%^WHITE%^l%^MAGENTA%^d%^RED%^f%^RESET%^%^RED%^l%^MAGENTA%^o%^CYAN%^we%^BOLD%^r%^BLUE%^s%^RESET%^ dot the emerald expanse with no apparent order or tending, sprouting alongside the occasional "
"small %^GREEN%^shr%^ORANGE%^u%^GREEN%^b%^RESET%^ or creeping groundcover.");
}

string snow_desc() {
   if (season(time()) == "winter") {
     if ((string)EVENTS_D->query_time_of_day() == "night") {
       return("%^RESET%^%^BLUE%^Soft %^BOLD%^%^WHITE%^m%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^gleams upon the layer of snow that lies across every "
"surface, catching on the brittle tree-branches and spread like a white blanket across the ground.  Only the most resilient of %^GREEN%^pl%^ORANGE%^a%^GREEN%^nts %^BLUE%^have overcome the "
"struggle to rear their stubborn leaves and limbs through it.%^RESET%^");
     }
     return("A soft layer of %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^WHITE%^ow %^RESET%^lies across every surface, catching on the brittle tree-branches and spread like a white blanket across "
"the ground.  Only the most resilient of %^GREEN%^pl%^ORANGE%^a%^GREEN%^nts %^RESET%^have overcome the struggle to rear their stubborn leaves and limbs through it.");
   }
   return("You do not notice that here.");
}

string shrubs_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^RESET%^%^BLUE%^The thick blanket of %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w %^RESET%^%^BLUE%^conceals all but the hardiest of %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs"
"%^BLUE%^ that have forced their way up through the frosty layer, or taken shelter beneath the shadowed eaves of the bordering forest.  You can even see a few %^BOLD%^%^RED%^st%^RESET%^"
"%^RED%^r%^MAGENTA%^a%^BOLD%^%^RED%^w%^MAGENTA%^b%^RED%^e%^RESET%^%^RED%^rr%^BOLD%^y %^RESET%^%^BLUE%^bushes among them, with fruit you could pick.%^RESET%^");
     }
     return("%^RESET%^%^BLUE%^Small %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs %^BLUE%^and patches of creeping groundcover dot the meadow amidst the colorful riot of %^BOLD%^%^BLUE%^f%^CYAN%^l"
"%^WHITE%^o%^MAGENTA%^w%^RED%^e%^RESET%^%^ORANGE%^r%^YELLOW%^s%^RESET%^%^BLUE%^, and skulk beneath the shadowed eaves of the bordering forest.  You can even see a few %^BOLD%^%^RED%^st"
"%^RESET%^%^RED%^r%^MAGENTA%^a%^BOLD%^%^RED%^w%^MAGENTA%^b%^RED%^e%^RESET%^%^RED%^rr%^BOLD%^y %^RESET%^%^BLUE%^bushes among them, with fruit you could pick.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("The thick blanket of %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w %^RESET%^conceals all but the hardiest of %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs%^RESET%^ that have forced their "
"way up through the frosty layer, or taken shelter beneath the shadowed eaves of the bordering forest.  You can even see a few %^BOLD%^%^RED%^st%^RESET%^%^RED%^r%^MAGENTA%^a%^BOLD%^%^RED%^w"
"%^MAGENTA%^b%^RED%^e%^RESET%^%^RED%^rr%^BOLD%^y %^RESET%^bushes among them, with fruit you could pick.");
   }
   return("Small %^GREEN%^s%^ORANGE%^h%^GREEN%^rubs %^RESET%^and patches of creeping groundcover dot the meadow amidst the colorful riot of %^BOLD%^%^BLUE%^f%^CYAN%^l%^WHITE%^o%^MAGENTA%^w"
"%^RED%^e%^RESET%^%^ORANGE%^r%^YELLOW%^s%^RESET%^, and skulk beneath the shadowed eaves of the bordering forest.  You can even see a few %^BOLD%^%^RED%^st%^RESET%^%^RED%^r%^MAGENTA%^a"
"%^BOLD%^%^RED%^w%^MAGENTA%^b%^RED%^e%^RESET%^%^RED%^rr%^BOLD%^y %^RESET%^bushes among them, with fruit you could pick.");
}

string flowers_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("You do not notice that here.");
     }
     return("%^RESET%^%^BLUE%^A myriad of flowers dot the meadow, spreading a riot of color across the emerald expanse of grass.  Sprigs of %^BOLD%^%^WHITE%^da%^RESET%^i%^BOLD%^%^WHITE%^si"
"%^RESET%^e%^BOLD%^%^WHITE%^s %^RESET%^%^BLUE%^and %^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^lets %^BLUE%^tangle amidst bunches of sunny %^YELLOW%^ragwort %^RESET%^%^RESET%^%^BLUE%^and tiny "
"%^BOLD%^%^BLUE%^co%^CYAN%^r%^BLUE%^nfl%^RESET%^%^BLUE%^ow%^BOLD%^ers%^RESET%^%^BLUE%^.  Spikes of %^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^av%^BLUE%^en%^MAGENTA%^de%^BOLD%^r %^RESET%^"
"%^BLUE%^rise in whorls to lift their faint perfume into the air, mingled with the scent of %^RED%^w%^BOLD%^i%^MAGENTA%^l%^RED%^d %^RESET%^%^MAGENTA%^r%^BOLD%^o%^WHITE%^s%^RED%^e%^RESET%^"
"%^RED%^s %^BLUE%^that unfurl their many-layered blossoms beneath the shelter of the nearby trees.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("You do not notice that here.");
   }
   return("A myriad of flowers dot the meadow, spreading a riot of color across the emerald expanse of grass.  Sprigs of %^BOLD%^%^WHITE%^da%^RESET%^i%^BOLD%^%^WHITE%^si%^RESET%^e"
"%^BOLD%^%^WHITE%^s %^RESET%^and %^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^lets %^RESET%^tangle amidst bunches of sunny %^YELLOW%^ragwort %^RESET%^and tiny %^BOLD%^%^BLUE%^co%^CYAN%^r"
"%^BLUE%^nfl%^RESET%^%^BLUE%^ow%^BOLD%^ers%^RESET%^.  Spikes of %^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^av%^BLUE%^en%^MAGENTA%^de%^BOLD%^r %^RESET%^rise in whorls to lift their faint perfume "
"into the air, mingled with the scent of %^RED%^w%^BOLD%^i%^MAGENTA%^l%^RED%^d %^RESET%^%^MAGENTA%^r%^BOLD%^o%^WHITE%^s%^RED%^e%^RESET%^%^RED%^s %^RESET%^that unfurl their many-layered "
"blossoms beneath the shelter of the nearby trees.");
}

string cliff_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^RESET%^%^BLUE%^At the distant side of the clearing, an outcropping of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^emerges "
"from beneath the blanket of %^BOLD%^%^WHITE%^snow%^RESET%^%^BLUE%^.  The jagged precipice looms stark in the %^BOLD%^%^WHITE%^m%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht"
"%^RESET%^%^BLUE%^, high above the surging waves of the %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^%^BLUE%^below.%^RESET%^");
     }
     return("%^RESET%^%^BLUE%^At the distant side of the clearing, the soft %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^%^BLUE%^draws back to reveal an outcropping of "
"%^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^.  The jagged precipice looms stark in the %^BOLD%^%^WHITE%^m%^RESET%^oo%^BOLD%^%^WHITE%^nl"
"%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^, high above the surging waves of the %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^%^BLUE%^below.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("At the distant side of the clearing, an outcropping of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e %^RESET%^emerges from beneath the blanket of "
"%^BOLD%^%^WHITE%^snow%^RESET%^.  The jagged precipice looms high above the surging waves of the %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n %^RESET%^below.");
   }
   return("At the distant side of the clearing, the soft %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN%^as%^BOLD%^s %^RESET%^draws back to reveal an outcropping of %^BOLD%^%^BLACK%^g%^RESET%^r"
"%^BOLD%^%^BLACK%^ey st%^RESET%^on%^BOLD%^%^BLACK%^e%^RESET%^.  The jagged precipice looms high above the surging waves of the %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n "
"%^RESET%^below.");
}

string ocean_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^RESET%^%^BLUE%^The pale %^BOLD%^%^WHITE%^m%^RESET%^oo%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht%^RESET%^%^BLUE%^ catches upon the white-capped waves of the ocean that "
"stretch to the eastern horizon as far as the eye can see.  The waters surge %^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^e%^RESET%^n%^BOLD%^t%^CYAN%^l%^RESET%^%^CYAN%^e"
"%^BLUE%^s%^BOLD%^s%^WHITE%^l%^RESET%^%^CYAN%^y%^BLUE%^, thrown into a cloud of foam and spray against the base of the cliff, far below the %^BOLD%^%^BLACK%^ru%^RESET%^%^ORANGE%^g"
"%^BOLD%^%^BLACK%^ged %^RESET%^%^BLUE%^stone outcrop.%^RESET%^");
   }
   return("%^YELLOW%^Su%^WHITE%^n%^YELLOW%^li%^WHITE%^gh%^YELLOW%^t %^RESET%^catches, jewel-bright, upon the white-capped waves of the ocean that stretch to the eastern horizon as far as the "
"eye can see.  The waters surge %^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^e%^RESET%^n%^BOLD%^t%^CYAN%^l%^RESET%^%^CYAN%^e%^BLUE%^s%^BOLD%^s%^WHITE%^l%^RESET%^"
"%^CYAN%^y%^RESET%^, thrown into a cloud of foam and spray against the base of the cliff, far below the %^BOLD%^%^BLACK%^ru%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^ged %^RESET%^stone "
"outcrop.%^RESET%^");
}

string tree_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^RESET%^%^BLUE%^A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led "
"%^BLUE%^fingers grasping for purchase within the earth.  Moonlight casts its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y "
"%^RESET%^%^BLUE%^bark into stark relief, warped by countless years and aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something "
"failed to stop its growth, but instead leans out over the cliff's edge, trailing a veil of withered foliage from its twisted limbs, turned bone-white with %^BOLD%^%^CYAN%^f%^WHITE%^ro"
"%^CYAN%^st%^RESET%^%^BLUE%^.%^RESET%^");
     }
     if (season(time()) == "autumn") {
       return("%^RESET%^%^BLUE%^A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led "
"%^BLUE%^fingers grasping for purchase within the earth.  Moonlight casts its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y "
"%^RESET%^%^BLUE%^bark into stark relief, warped by countless years and aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something "
"failed to stop its growth, but instead leans out over the cliff's edge, trailing a veil of %^ORANGE%^f%^RED%^l%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u"
"%^RESET%^%^RED%^e%^ORANGE%^d %^BLUE%^foliage from its twisted limbs.%^RESET%^");
     }
     if (season(time()) == "summer") {
       return("%^RESET%^%^BLUE%^A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led "
"%^BLUE%^fingers grasping for purchase within the earth.  Moonlight casts its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y "
"%^RESET%^%^BLUE%^bark into stark relief, warped by countless years and aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something "
"failed to stop its growth, but instead leans out over the cliff's edge, trailing a veil of %^GREEN%^ve%^BOLD%^rd%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage from its "
"twisted limbs.  Tiny %^YELLOW%^fi%^GREEN%^r%^YELLOW%^ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^BLUE%^ drift among the leaves, winking in and out of sight.%^RESET%^");
     }
     return("%^RESET%^%^BLUE%^A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led "
"%^BLUE%^fingers grasping for purchase within the earth.  Moonlight casts its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y "
"%^RESET%^%^BLUE%^bark into stark relief, warped by countless years and aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something "
"failed to stop its growth, but instead leans out over the cliff's edge, trailing a veil of %^GREEN%^ve%^BOLD%^rd%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage from its "
"twisted limbs.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led %^RESET%^fingers grasping "
"for purchase within the earth.  Its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark has been warped by countless years, "
"aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something failed to stop its growth, but instead leans out over the cliff's edge, "
"trailing a veil of withered foliage from its twisted limbs, turned bone-white with %^BOLD%^%^CYAN%^f%^WHITE%^ro%^CYAN%^st%^RESET%^.");
   }
   if (season(time()) == "autumn") {
     return("A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led %^RESET%^fingers grasping "
"for purchase within the earth.  Its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark has been warped by countless years, "
"aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something failed to stop its growth, but instead leans out over the cliff's edge, "
"trailing a veil of %^ORANGE%^f%^RED%^l%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^RESET%^foliage from its twisted limbs.");
   }
   return("A weeping willow of impossible size rises from the center of the glade, its roots snaking out like %^ORANGE%^gn%^BOLD%^%^BLACK%^ar%^RESET%^%^ORANGE%^led %^RESET%^fingers grasping "
"for purchase within the earth.  Its %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark has been warped by countless years, "
"aged as if in refusal to succumb to the windy climate.  The toughened tree stands not quite straight, as if something failed to stop its growth, but instead leans out over the cliff's edge, "
"trailing a veil of %^GREEN%^ve%^BOLD%^rd%^RESET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^t %^RESET%^foliage from its twisted limbs.");
}

string brook_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^RESET%^%^BLUE%^A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^%^BLUE%^emerges from the line of the forest, meandering its way across the meadow"
".  At less than two feet wide it is only narrow, and could be easily leaped across.  A solid layer of %^BOLD%^%^WHITE%^i%^CYAN%^c%^WHITE%^e %^RESET%^%^BLUE%^coats its length all the way to the "
"cliff's edge, where a trickle of water still tumbles forth into the ocean below.%^RESET%^");
     }
     return("%^RESET%^%^BLUE%^A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^%^BLUE%^emerges from the line of the forest, meandering its way across the meadow "
"to finally tumble down over the rocky overhang and into the ocean.  At less than two feet wide it is only narrow, and could be easily leaped across.  The water chuckles across earth and stone"
", as %^BOLD%^%^WHITE%^sp%^YELLOW%^a%^WHITE%^rkl%^YELLOW%^i%^WHITE%^ng %^RESET%^%^BLUE%^fish dart beneath its clear surface.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^emerges from the line of the forest, meandering its way across the meadow.  At less than two feet "
"wide it is only narrow, and could be easily leaped across.  A solid layer of %^BOLD%^%^WHITE%^i%^CYAN%^c%^WHITE%^e %^RESET%^coats its length all the way to the cliff's edge, where a trickle "
"of water still tumbles forth into the ocean below.");
   }
   return("A tiny %^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^r%^BOLD%^o%^CYAN%^o%^BLUE%^k %^RESET%^emerges from the line of the forest, meandering its way across the meadow to finally tumble down over "
"the rocky overhang and into the ocean.  At less than two feet wide it is only narrow, and could be easily leaped across.  The water chuckles across earth and stone, as %^BOLD%^%^WHITE%^sp"
"%^YELLOW%^a%^WHITE%^rkl%^YELLOW%^i%^WHITE%^ng %^RESET%^fish dart beneath its clear surface.");
}

string frost_desc() {
   if (season(time()) == "winter") {
     return tree_desc();
   }
   return("You do not notice that here.");
}

void reset() {
   string weather;
   object weatherobj;
   ::reset();
   switch(randecho) {
     case 0..1:
       if (season(time()) == "winter") { tell_room(TO,"%^BOLD%^%^CYAN%^The chill wind picks up, shaking the brittle tree branches to send a cascade of "
"%^WHITE%^s%^RESET%^no%^BOLD%^wf%^RESET%^la%^BOLD%^ke%^RESET%^s %^BOLD%^%^CYAN%^tumbling to the ground.%^RESET%^"); break; }
       if (season(time()) == "autumn") { tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up, shaking the tree branches to send a cascade of %^RESET%^%^RED%^l"
"%^ORANGE%^ea%^RED%^ve%^ORANGE%^s %^BOLD%^%^CYAN%^tumbling to the ground.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up, shaking the tree branches to send a cascade of %^GREEN%^l%^RESET%^%^GREEN%^ea%^BOLD%^ve"
"%^RESET%^%^GREEN%^s %^BOLD%^%^CYAN%^tumbling to the ground.%^RESET%^");
     break;
     case 2:
       tell_room(TO,"%^BOLD%^%^WHITE%^Another wave breaks against the jagged cliffs far below, the %^BLUE%^r%^RESET%^%^BLUE%^o%^CYAN%^l%^RESET%^l"
"%^BOLD%^i%^CYAN%^n%^BLUE%^g %^WHITE%^ocean never quite allowing it to grow entirely silent here.%^RESET%^");
     break;
     case 3..4:
       tell_room(TO,"%^BOLD%^%^WHITE%^A brisk %^CYAN%^bre%^BLUE%^e%^CYAN%^ze %^WHITE%^carries the salty scent of the ocean, stirring the trees to a gentle "
"swaying motion.%^RESET%^");
     break;
     case 5:
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BLUE%^Somewhere distant, deep within the forest, the lone howl of a "
"%^BOLD%^%^BLACK%^wolf %^RESET%^%^BLUE%^breaks the night's serenity.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^BLUE%^A warbling chorus of birdsong greets the %^YELLOW%^d%^MAGENTA%^a"
"%^RED%^w%^YELLOW%^n%^BLUE%^, as the sun peeks over the horizon.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^GREEN%^At the edge of the meadow, a tiny %^RESET%^%^ORANGE%^bunny %^BOLD%^%^GREEN%^lifts its head and peers about, its ears "
"flicking nervously as it wriggles its nose. Something startles it, and just as suddenly it darts away.%^RESET%^");
     break;
     case 6..7:
       if ((string)EVENTS_D->query_time_of_day() == "night") {
         if (season(time()) == "summer") tell_room(TO,"%^RESET%^%^BLUE%^Fireflies drift slowly through the grass and amidst the trees, their %^GREEN%^lum"
"%^BOLD%^i%^RESET%^%^GREEN%^nesc%^BOLD%^e%^RESET%^%^GREEN%^nt gl%^BOLD%^o%^RESET%^%^GREEN%^w %^BLUE%^winking in and out of sight.%^RESET%^");
         else tell_room(TO,"%^BOLD%^%^BLACK%^A cloud of %^RESET%^gho%^BOLD%^%^BLACK%^st%^RESET%^ly-w%^BOLD%^%^BLACK%^h%^RESET%^ite "
"%^BOLD%^%^BLACK%^moths rise from the grass, whirling upwards before they scatter to all directions and disappear into the night.%^RESET%^");
       }
       else tell_room(TO,"%^RESET%^%^GREEN%^A butterfly meanders from one flower to the next, spreading its %^ORANGE%^r%^YELLOW%^a%^GREEN%^i%^CYAN%^n"
"%^BLUE%^b%^RESET%^%^MAGENTA%^o%^RED%^w %^GREEN%^wings as it drifts through the air.%^RESET%^");
     break;
     case 8..9:
       weatherobj = new(OBJ"strawberries");
       weatherobj->move(TO);
       weather = (string)WEATHER_D->Check_Weather(weatherobj);
       weatherobj->remove();
       if(strsrch(weather,"snow") != -1) { tell_room(TO,"%^BOLD%^%^WHITE%^Snowflakes drift down from the %^RESET%^cl%^BOLD%^%^BLACK%^o%^RESET%^ud"
"%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^WHITE%^sky above, settling on your head and shoulders.%^RESET%^"); break; }
       if(strsrch(weather,"raining") != -1){ tell_room(TO,"%^BLUE%^The falling %^BOLD%^r%^CYAN%^a%^BLUE%^in %^RESET%^%^BLUE%^soaks into your clothes "
"and hair.%^RESET%^"); break; }
       if(strsrch(weather,"mostly cloudy") != -1 || strsrch(weather,"very cloudy") != -1) {
         tell_room(TO,"%^BOLD%^%^BLUE%^An ominous %^RESET%^%^MAGENTA%^rum%^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLUE%^comes from the clouds "
"above, hinting at worse weather yet to come.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BOLD%^%^BLACK%^Not even a single cloud interrupts the view of the clear night "
"sky above, the distant stars %^RESET%^spa%^BOLD%^%^WHITE%^r%^RESET%^kli%^BOLD%^%^WHITE%^n%^RESET%^g %^BOLD%^%^BLACK%^brightly.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "twilight") { tell_room(TO,"%^RESET%^%^ORANGE%^The setting sun casts lengthening %^BLUE%^shadows "
"%^ORANGE%^across the meadow, as it disappears over the treetops.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^WHITE%^The light of the rising sun sparkles %^YELLOW%^br"
"%^MAGENTA%^i%^YELLOW%^ghtly %^WHITE%^upon the white-capped waves of the ocean.%^RESET%^"); break; }
       tell_room(TO,"%^YELLOW%^The sun shines brightly in the clear sky, %^RESET%^%^RED%^wa%^ORANGE%^rm%^RED%^ing %^YELLOW%^your skin.%^RESET%^");
     break;
     default:
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^MAGENTA%^From somewhere high in the nearby trees carries the hoot of a lone "
"%^RESET%^o%^ORANGE%^w%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^BLUE%^A warbling chorus of birdsong greets the %^YELLOW%^d%^MAGENTA%^a"
"%^RED%^w%^YELLOW%^n%^BLUE%^, as the sun peeks over the horizon.%^RESET%^"); break; }
       tell_room(TO,"%^ORANGE%^A colorful flash of feathers darts through the branches above as %^BOLD%^%^WHITE%^ch%^CYAN%^e%^WHITE%^erf%^MAGENTA%^u%^WHITE%^l "
"%^RESET%^%^ORANGE%^twittering fills the air.%^RESET%^");
     break;
   }
   randecho += roll_dice(2,2);
   randecho = randecho%12;
}

int pick_fun(string str) {
   object ob;
   if(str == "strawberries") {
     if(!strawberries) {
       notify_fail("It looks like the ripe strawberries have already been picked.\n");
       return 0;
     }
     tell_object(TP,"You pick a few plump strawberries from a nearby bush.");
     tell_room(ETP,""+TPQCN+" picks a few plump strawberries from a nearby bush.",TP);
     ob = new(OBJ"strawberries");
     ob->move(TO);
     strawberries--;
     return 1;
   }
   return 0;
}

int ledge_fun(string str) {
   if (str) return 0;
   if(!TP->query_invis()) tell_room(ETP,"%^CYAN%^"+TP->QCN+" carefully steps around one of the more prominent outcroppings of stone at the cliff's edge, and disappears from sight.%^RESET%^",TP);
   tell_object(TP,"%^CYAN%^You step around an outcropping of stone, placing your feet carefully as you descend to the ledge below.%^RESET%^");
   TP->move_player(ROOMS+"ledge");
   return 1;
}

int door_fun(string str) {
   object mainroom;
   if(!str) return 0;
   if(str != "door") return 0;
   if(query_open("door")) return 0;
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" reaches out to place hands against the tree's silvery bark. "
"The outline of a door appears and it swings open.%^RESET%^",TP);
   tell_object(TP,"%^GREEN%^You press gently upon the door, and it swings open.%^RESET%^");
   set_open("door", 1);
   set_invis_exits(({}));
   mainroom = find_object_or_load(ROOMS"tree");
   mainroom->set_open("door",1);
   tell_room(mainroom,"You notice the door suddenly open from the other side.");
   return 1;
}

int CloseDoor(string str) {
   object mainroom;
   ::CloseDoor(str);
   if(str == "door") {
     set_invis_exits(({"tree"}));
     mainroom = find_object_or_load(ROOMS"tree");
     mainroom->set_invis_exits(({"up"}));
     return 1;
   }
   return 0;
}

int search_room(string str) {
   if (!str) return 0;
   if (str == "tree" || str == "willow") {
     tell_object(TP,"%^BOLD%^%^WHITE%^A closer inspection of the tree's aged, gnarled bark reveals a faint outline scored into "
"the wood, roughly the size of a doorway.%^RESET%^\n");
     return 1;
   }
   if (str == "cliff" || str == "ledge") {
     tell_object(TP,"%^BOLD%^%^WHITE%^Amongst the rocks at the edge of the outcropping, you find one spot where you think you "
"could carefully descend down the side of the cliff to a ledge below.%^RESET%^\n");
     return 1;
   }
   return 0;
}

void trigger_eldathyn_ward() {
   object *combatants, destroom, MyWard;
   int i, flag, MyFlag;
   string *mayberooms, *mayberooms2, pickedroom;

   combatants = all_living(TO);
   if(!sizeof(combatants)) return;

   mayberooms = get_dir(BASE);
   mayberooms2 = ({});
   for (i=0;i<sizeof(mayberooms);i++) { mayberooms2 += ({BASE + mayberooms[i]}); }
   mayberooms2 -= NOTROOMS;
   pickedroom = mayberooms2[random(sizeof(mayberooms2))];
   destroom = new(pickedroom);

   for(i = 0;i< sizeof(combatants); i++) {
     if(!objectp(combatants[i])) continue;
     MyWard = present("eldathynwardxxx", combatants[i]);
     MyFlag = 0;
     if(objectp(MyWard)) MyFlag = (int)MyWard->is_combatant();

     if(sizeof(combatants[i]->query_attackers()) || MyFlag) {
       if(!flag) flag = 1;
       tell_object(combatants[i],"%^BOLD%^%^CYAN%^The air s%^RESET%^%^CYAN%^hi%^BOLD%^mm%^RESET%^%^CYAN%^er%^BOLD%^s around you, "
"and suddenly you find yourself elsewhere!%^RESET%^");
       combatants[i]->move(pickedroom);
     }
   }

   if(flag)
     tell_room(TO,"%^BOLD%^%^CYAN%^The air s%^RESET%^%^CYAN%^hi%^BOLD%^mm%^RESET%^%^CYAN%^er%^BOLD%^s around those striking out, "
"and suddenly they are gone!%^RESET%^");
}