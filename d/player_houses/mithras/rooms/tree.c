#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit VAULT;

int randecho, cello, shutters;
string flowers;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(BRANCHES);
    set_travel(LEDGE);
    set_name("Inside the tree");
    set_short("%^RESET%^%^ORANGE%^Ins%^GREEN%^i%^ORANGE%^de the t%^GREEN%^r%^ORANGE%^ee%^RESET%^");
    set_long((:TO,"long_desc":));
    set_smell("default","%^RESET%^%^ORANGE%^The clean, crisp air bears the %^BOLD%^%^WHITE%^sa%^CYAN%^lt%^WHITE%^y %^RESET%^%^ORANGE%^tang of the sea.%^RESET%^");
    set_listen("default",(:TO,"default_listen":));

    switch(random(4)) {
      case 0:
        flowers = "sunny %^YELLOW%^yellow %^RESET%^%^ORANGE%^lilies that spring out over a softer backdrop of pale %^MAGENTA%^lavender %^ORANGE%^and cor%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^l-"
"h%^BOLD%^%^MAGENTA%^u%^RESET%^%^ORANGE%^ed blossoms";
      break;
      case 1:
        flowers = "mixed gerberas in vivid shades of %^BOLD%^%^RED%^sc%^RESET%^%^RED%^ar%^BOLD%^let%^RESET%^%^ORANGE%^, %^MAGENTA%^pi%^BOLD%^n%^RESET%^%^MAGENTA%^k%^RESET%^%^ORANGE%^, och%^RED%^"
"r%^ORANGE%^e and %^YELLOW%^y%^WHITE%^e%^YELLOW%^llow%^RESET%^%^ORANGE%^";
      break;
      case 2:
        flowers = "cheerful g%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^de%^RESET%^%^ORANGE%^n sunflowers";
      break;
      default:
        flowers = "delicate clusters of tiny %^BOLD%^%^WHITE%^wh%^RESET%^it%^BOLD%^%^WHITE%^e roses%^RESET%^%^ORANGE%^";
      break;
    }

    set_items(([
      ({"walls","roof","floor"}) : (:TO,"walls_desc":),
      "rug" : "%^ORANGE%^A rug of %^GREEN%^r%^BOLD%^i%^RESET%^%^GREEN%^ch e%^CYAN%^m%^GREEN%^er%^BOLD%^a%^YELLOW%^l%^RESET%^%^GREEN%^d g%^BOLD%^re%^RESET%^%^GREEN%^en %^ORANGE%^covers most of "
"the free floor area.  It is incredibly soft underfoot, and %^RED%^th%^MAGENTA%^ic%^RED%^k %^ORANGE%^enough to sink your toes into.%^RESET%^",
      ({"bench","cupboards"}) : "%^ORANGE%^A long, smooth %^RESET%^wo%^BOLD%^%^BLACK%^o%^RESET%^den %^ORANGE%^benchtop follows the line of the rear wall.  Beneath it are several closed cupboard "
"doors, cleverly-fitted to the curve of the bench with simple polished handles.%^RESET%^",
      ({"table","vase","flowers"}) : "%^ORANGE%^A sturdy, four-legged table sits beneath the %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, set about with several chairs nearby.  Left to a "
"somewhat irregular shape that maintain many of the the whorls and curves of the original %^RESET%^wo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^, it bears a smooth surface but uneven edges.  A plain "
"glass vase stands in the centre of the table, filled with "+flowers+".%^RESET%^",
      ({"window","shutters"}) : (:TO,"window_desc":),
      "chairs" : "%^ORANGE%^Several chairs sit at and about the table, shaped from the same %^RESET%^p%^BOLD%^%^BLACK%^a%^RESET%^le bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d "
"%^ORANGE%^as the rest of the furniture.  Simple but sturdy, each has a curved back and a %^GREEN%^cu%^CYAN%^sh%^GREEN%^ion%^CYAN%^e%^GREEN%^d %^ORANGE%^seat for comfort.  A pair of more casual"
", backless stools sit by the bench.%^RESET%^",
      "couch" : "%^ORANGE%^A large, comfortable %^RED%^couch %^ORANGE%^takes up part of the wall on one side of the room.  Sizeable enough to sit several people, it bears soft %^GREEN%^cl"
"%^CYAN%^ot%^GREEN%^h-co%^CYAN%^ve%^GREEN%^red %^ORANGE%^cushions, and a %^RESET%^knit%^CYAN%^t%^RESET%^ed throw %^ORANGE%^draped over one arm.%^RESET%^",
      "stand" : (:TO,"stand_desc":),
      "cello" : (:TO,"cello_desc":),
      "lanterns" : (:TO,"lanterns_desc":),
      "paintings" : "%^ORANGE%^Two paintings have been placed in clear view upon the walls.  The first is a painting of a %^BLUE%^se%^RESET%^re%^BLUE%^ne lake%^RESET%^%^ORANGE%^, while the "
"second shows a young %^CYAN%^couple%^ORANGE%^.  While both seem to be %^WHITE%^m%^MAGENTA%^a%^WHITE%^s%^MAGENTA%^t%^WHITE%^er%^MAGENTA%^f%^WHITE%^ul%^ORANGE%^ works of art, the distinctly "
"differing style of each hints that the same artist did not paint both.%^RESET%^",
      ({"first painting","painting 1"}) : "%^BOLD%^%^BLUE%^From a mountaintop perspective, this painting shows a vast %^ORANGE%^canyon%^BOLD%^%^BLUE%^.  Where not too steep, the mountainside is "
"%^BOLD%^%^GREEN%^thickly forested with evergreens.  %^BOLD%^%^BLUE%^At the center however is a vast, %^RESET%^%^CYAN%^pl%^BLUE%^a%^WHITE%^c%^CYAN%^id lake%^BOLD%^%^BLUE%^.  Disturbances are "
"unevenly spread across the surface, as if the painter took care to notice that the wind was not evenly distributed.  Surrounding the lake is a half-crescent of %^RESET%^%^YELLOW%^yellow sand"
"%^BOLD%^%^BLUE%^, and the %^BOLD%^%^YELLOW%^sun%^WHITE%^l%^YELLOW%^ight %^BLUE%^is reflected from the water in small sparkles.  A tiny silver %^RESET%^%^WHITE%^M %^BOLD%^%^BLUE%^adorns the "
"lower right corner.%^RESET%^",
      ({"second painting","painting 2"}) : "%^RESET%^%^RED%^Fine brush strokes depict a %^MAGENTA%^slim %^RED%^girl with %^BOLD%^%^GREEN%^leaves %^RESET%^%^RED%^woven through her hair sitting "
"on a stone, near a hot spring.  Her gaze is locked on a slender male elf with %^BOLD%^%^BLACK%^short black hair %^RESET%^%^RED%^and %^BOLD%^%^WHITE%^s%^MAGENTA%^p%^WHITE%^ar%^MAGENTA%^k"
"%^WHITE%^ling %^RESET%^%^RED%^emerald eyes.  A deep fog permates most of the visual area, almost capturing the young %^BOLD%^l%^RESET%^%^RED%^o%^BOLD%^%^RED%^vers %^RESET%^%^RED%^in an "
"unrelenting embrace.  Water trickles off the males brow, but it is difficult to tell if is from perspiration or anticipation.  The painting is secured in a %^BOLD%^%^CYAN%^delicate %^RESET%^"
"%^RED%^silver frame with a small %^MAGENTA%^A %^RED%^in the left corner.%^RESET%^",
      "stairs" : "%^ORANGE%^A series of simple, smooth wooden stairs follow the curve of the wall, leading down through a small hole in the floor to a room below.%^RESET%^",
    ]));
    randecho = random(12);
    cello = 1;
    shutters = 0;
    set_search("walls",(:TO,"search_room":));
    set_exits(([
      "down" : ROOMS"workroom",
      "up" : ROOMS"upstairs",
      "out" : ROOMS"meadow",
    ]));
    set_invis_exits(({"up"}));
    set_door("inner door",ROOMS"upstairs","up","hasnokey","lock");
    set_locked("inner door",1);
    lock_difficulty("inner door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"lock"); // very simple syntax but no keyhole; not designed to be lockpicked.
    set_lock_description("inner door","lock","%^BOLD%^%^BLACK%^No handle or keyhole are visible upon the smooth wooden surface.%^RESET%^");
    set_door_description("inner door","%^RESET%^Only readily apparent when opened, this door seems to be part of the %^ORANGE%^t%^GREEN%^r%^ORANGE%^ee %^RESET%^itself, and vanishes almost "
"entirely from sight when shut.  Smooth %^ORANGE%^wooden %^RESET%^hinges allow it to open and close soundlessly, and its entire outer surface is of the same %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark as the walls.");
    set_string("door", "close", "The wooden door swings shut with only a faint click, and its outline merges with the wall to vanish from sight.");

    set_door("door",ROOMS"meadow","out","hasnokey","lock");
    set_locked("door",0);
    lock_difficulty("door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"lock"); // very simple syntax but no keyhole; not designed to be lockpicked.
    set_lock_description("door","lock","%^BOLD%^%^BLACK%^No handle or keyhole are visible upon the smooth wooden surface.%^RESET%^");
    set_door_description("door","%^RESET%^Only readily apparent when opened, this door seems to be part of the %^ORANGE%^t%^GREEN%^r%^ORANGE%^ee %^RESET%^itself, and vanishes almost entirely "
"from sight when shut.  Smooth %^ORANGE%^wooden %^RESET%^hinges allow it to open and close soundlessly, and its entire outer surface is of same %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark as the walls.");
}

void init() {
   string myname,myadj;
   ::init();
   add_action("window_func","draw");
   add_action("sense_it","sense");
   add_action("purge_it","purge");
   add_action("door_fun","trace");
   add_action("cello_func","retrieve");
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_invis()) return;
   if(sscanf((string)TP->query_short(),"%s, %s", myname, myadj) != 2)
     myadj = (string)TP->query_short();
   if(member_array(myadj,(string *)SAVE_D->query_array("mithras_tree")) == -1) {
     if((string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras")
       SAVE_D->set_value("mithras_tree",myadj);
   }
   if(userp(TP) && !present("eldathynwardxxx",TP)) new(OBJ"eldathynward")->move(TP);
}

string default_listen(string str) {
   if(shutters) return "%^RESET%^%^GREEN%^The closed shutters block out nearly all sound, save the faint, distant crash of the %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n%^RESET%^"
"%^GREEN%^.%^RESET%^";
   return "%^RESET%^%^GREEN%^The gentle whispering %^CYAN%^bre%^BOLD%^e%^RESET%^%^CYAN%^ze %^GREEN%^is accompanied by the distant crash of %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n "
"%^RESET%^%^GREEN%^waves.%^RESET%^";
}

string lanterns_short() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "A few softly %^YELLOW%^glow%^WHITE%^i%^YELLOW%^ng %^RESET%^%^ORANGE%^lanterns have been placed about the room, shedding soft illumination upon the two %^MAGENTA%^pa%^BLUE%^i"
"%^MAGENTA%^nt%^CYAN%^i%^MAGENTA%^n%^BLUE%^g%^MAGENTA%^s %^ORANGE%^that grace the walls nearby.";
   return "A few lanterns upon curved stands have been placed about the room, while two %^MAGENTA%^pa%^BLUE%^i%^MAGENTA%^nt%^CYAN%^i%^MAGENTA%^n%^BLUE%^g%^MAGENTA%^s %^ORANGE%^grace the walls "
"nearby.";
}

string cello_short() {
   if (cello)
     return "and a stand upon the floor next to it supports a %^RED%^cello%^ORANGE%^.";
   return "with an empty stand upon the floor next to it.";
}

string long_desc() {
   return("%^RESET%^%^ORANGE%^This room is of an uneven shape, neither square nor properly circular, with the smooth floor and tapering walls all formed of pale %^RESET%^s%^BOLD%^%^WHITE%^i"
"%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood that seems to have grown naturally into shape.  Simple, solid furnishings take "
"up some of the space here, but leave a sizeable clear area in the center of the room to walk about, where a thick %^GREEN%^gr%^CYAN%^ee%^GREEN%^n %^ORANGE%^rug lies underfoot.  A curved bench "
"follows the line of the rear wall as it runs part of its length, with cleverly-fitted cupboards beneath.  A sturdy table stands near the room's only %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow"
"%^ORANGE%^, set about with several cushioned wooden chairs.  Upon the opposite side of the room rests a comfortable looking %^GREEN%^cou%^CYAN%^c%^GREEN%^h%^ORANGE%^, "+cello_short()+"  "
+lanterns_short()+"  A set of simple wooden stairs lead along the line of the wall, down into another room below.%^RESET%^\n");
}

string walls_desc() {
   if((string)TP->query_name() == "marie" || (string)TP->query_name() == "mithras" || avatarp(TP)) 
     return "%^ORANGE%^The uneven shape of the room's walls is caused perhaps by the growth of the tree it resides in.  It seems impossible that the tree could've grown this precisely without "
"some kind of direction, though, for the floor is surprisingly flat underfoot.  Both it and the walls are of a pale %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g"
"%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood, smooth to the touch.  This room is likely partway up the tree, for while the base is likely the inside of the tree's "
"trunk, interwoven branches become apparent towards the top of the room, so closely interlocked that no %^RESET%^l%^BOLD%^i%^YELLOW%^g%^WHITE%^h%^RESET%^t %^ORANGE%^or %^CYAN%^w%^BLUE%^e%^CYAN%^"
"a%^BOLD%^t%^BLUE%^he%^RESET%^%^BLUE%^r %^ORANGE%^slips through, save where they have parted in one wall to form a single broad window.  Your inner connection to the tree itself leaves you "
"knowing that you could %^RESET%^sense trespassers%^ORANGE%^ that have been here, or %^RESET%^purge trespassers%^ORANGE%^ to soothe the tree of its recollections.%^RESET%^";
   return "%^ORANGE%^The uneven shape of the room's walls is caused perhaps by the growth of the tree it resides in.  It seems impossible that the tree could've grown this precisely without "
"some kind of direction, though, for the floor is surprisingly flat underfoot.  Both it and the walls are of a pale %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g"
"%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood, smooth to the touch.  This room is likely partway up the tree, for while the base is likely the inside of the tree's "
"trunk, interwoven branches become apparent towards the top of the room, so closely interlocked that no %^RESET%^l%^BOLD%^i%^YELLOW%^g%^WHITE%^h%^RESET%^t %^ORANGE%^or %^CYAN%^w%^BLUE%^e%^CYAN%^"
"a%^BOLD%^t%^BLUE%^he%^RESET%^%^BLUE%^r %^ORANGE%^slips through, save where they have parted in one wall to form a single broad window.%^RESET%^";
}

string window_desc() {
   object outside, tracker;
   string weather;
   if(shutters) {
     return ("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges lie closed against the outdoors and the weather "
"beyond.  You could %^RESET%^draw shutters open %^ORANGE%^to see outside.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter")
       return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards upon the dark of %^BLUE%^night"
"%^ORANGE%^, where tiny stars sparkle and gleam amidst the overhang of %^BOLD%^%^CYAN%^f%^WHITE%^ro%^CYAN%^st%^RESET%^%^ORANGE%^-chilled foliage.  You could %^RESET%^draw shutters closed "
"%^ORANGE%^to block out the night beyond.%^RESET%^");
     if (season(time()) == "autumn")
       return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards upon the dark of %^BLUE%^night"
"%^ORANGE%^, where tiny stars sparkle and gleam amidst the overhang of l%^RED%^ea%^ORANGE%^v%^YELLOW%^e%^RESET%^%^ORANGE%^s.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the "
"night beyond.%^RESET%^");
     if (season(time()) == "summer")
       return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards upon the dark of %^BLUE%^night"
"%^ORANGE%^, where luminous %^YELLOW%^fi%^GREEN%^r%^YELLOW%^ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ drift amidst the overhang of %^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^v"
"%^BOLD%^e%^RESET%^%^GREEN%^s%^ORANGE%^.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the night beyond.%^RESET%^");
     return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards upon the dark of %^BLUE%^night"
"%^ORANGE%^, where tiny stars sparkle and gleam amidst the overhang of %^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^s%^ORANGE%^.  You could %^RESET%^draw shutters closed "
"%^ORANGE%^to block out the night beyond.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "twilight")
     return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards, allowing the last rays of the day's "
"sunlight to cast long %^BLUE%^shadows %^ORANGE%^across the floor.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the sunset beyond.%^RESET%^");
   if ((string)EVENTS_D->query_time_of_day() == "dawn")
     return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards, letting in the %^BOLD%^%^YELLOW%^br"
"%^MAGENTA%^i%^YELLOW%^ll%^CYAN%^i%^WHITE%^a%^YELLOW%^nt %^RESET%^%^ORANGE%^light of dawn.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the sunrise beyond.%^RESET%^");
   outside = find_object_or_load(ROOMS"meadow");
   tracker = new(OBJ"strawberries");
   tracker->move(outside);
   weather = (string)WEATHER_D->Check_Weather(tracker);
   tracker->remove();
   if(strsrch(weather,"snow") != -1)
     return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards, where tiny %^RESET%^sn"
"%^BOLD%^%^WHITE%^ow%^RESET%^fla%^BOLD%^%^WHITE%^k%^RESET%^es %^ORANGE%^drift past the tree's overhanging branches.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the weather "
"beyond.%^RESET%^");
   if(strsrch(weather,"raining") != -1)
     return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards, where gentle %^BOLD%^%^BLUE%^r"
"%^RESET%^%^BLUE%^ai%^BOLD%^nf%^CYAN%^a%^WHITE%^l%^BLUE%^l %^RESET%^%^ORANGE%^drips from the tree's overhanging branches.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the "
"weather beyond.%^RESET%^");
   if(strsrch(weather,"cloudy") != -1)
     return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards, though the best of the day's "
"%^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^RESET%^%^ORANGE%^is shadowed as much by the tree's branches as by the cloudcover overhead.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out "
"the weather beyond.%^RESET%^");
   return("%^RESET%^%^ORANGE%^At one point within the wall lies an oval %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, shaped where the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l"
"%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^tree branches have grown apart.  Wooden shutters on simple hinges open outwards, allowing bright sunlight to spill "
"across the middle of the room and %^BOLD%^%^CYAN%^g%^WHITE%^l%^CYAN%^eam %^RESET%^%^ORANGE%^upon the bowl of crystalline water.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out "
"the sunlight beyond.%^RESET%^");
}

string stand_desc() {
   if (cello) {
     if((string)TP->query_name() == "marie" || (string)TP->query_name() == "mithras" || avatarp(TP)) 
       return ("%^ORANGE%^Next to the couch is a stand holding a %^RED%^cello%^ORANGE%^, its endpin resting against the floor to support it further yet.  The large, four-stringed instrument is "
"of simple craft, but has been polished to a rich finish.  A slender case upon the ground behind it likely holds a bow and other accessories.  You could %^RESET%^retrieve cello %^ORANGE%^if you "
"wanted to play it.%^RESET%^");
     return ("%^ORANGE%^Next to the couch is a stand holding a %^RED%^cello%^ORANGE%^, its endpin resting against the floor to support it further yet.  The large, four-stringed instrument is "
"of simple craft, but has been polished to a rich finish.  A slender case upon the ground behind it likely holds a bow and other accessories.%^RESET%^");
   }
   return("%^ORANGE%^Next to the couch is an empty stand.%^RESET%^");
}

string cello_desc() { return stand_desc(); }

string lanterns_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^ORANGE%^A few lanterns have been placed about the room, consisting of single small cages that have been carved with %^GREEN%^e%^CYAN%^le%^GREEN%^ga%^CYAN%^n%^GREEN%^t %^ORANGE%^"
"simplicity.  You can see no candle or oil within, leaving you to surmise that the soft %^YELLOW%^gl%^WHITE%^o%^YELLOW%^w%^RESET%^%^ORANGE%^ emitted by each is raised by some form of spellcraft"
".  Each is supported upon a curved stand of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^, matched with the rest of the room's "
"furnishings.%^RESET%^";
   return "%^ORANGE%^%^ORANGE%^A few lanterns have been placed about the room, consisting of single small cages that have been carved with %^GREEN%^e%^CYAN%^le%^GREEN%^ga%^CYAN%^n%^GREEN%^t "
"%^ORANGE%^simplicity.  You can see no candle or oil within.  Each is supported upon a curved stand of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o"
"%^RESET%^d%^ORANGE%^, matched with the rest of the room's furnishings.%^RESET%^";
}

void reset() {
   string weather;
   object tracker, outside;
   ::reset();
   if(sizeof(children(OBJ"cello")) < 2) { // one item is just base file loaded to memory. at least 2 items means someone is carrying one around, so don't reset if so.
     add_item("cello",(:TO,"cello_desc":));
     cello = 1;
   }

   switch(randecho) {
     case 0..1:
       if(shutters) { tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up outside, %^RESET%^rat%^BOLD%^%^BLACK%^t%^RESET%^li%^BOLD%^%^BLACK%^n%^RESET%^g "
"%^BOLD%^%^CYAN%^against the closed shutters.%^RESET%^"); break; }
       if (season(time()) == "winter") { tell_room(TO,"%^BOLD%^%^CYAN%^The chill wind picks up, shaking the brittle tree branches to send a cascade of "
"%^WHITE%^s%^RESET%^no%^BOLD%^wf%^RESET%^la%^BOLD%^ke%^RESET%^s %^BOLD%^%^CYAN%^tumbling past the open window.%^RESET%^"); break; }
       if (season(time()) == "autumn") { tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up, shaking the tree branches to send a cascade of %^RESET%^%^RED%^l"
"%^ORANGE%^ea%^RED%^ve%^ORANGE%^s %^BOLD%^%^CYAN%^tumbling past the open window.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up, shaking the tree branches to send a cascade of %^GREEN%^l%^RESET%^%^GREEN%^ea%^BOLD%^ve"
"%^RESET%^%^GREEN%^s %^BOLD%^%^CYAN%^tumbling past the open window.%^RESET%^");
     break;
     case 2..3:
       if(!shutters) {
         if ((string)EVENTS_D->query_time_of_day() == "night") {
           if (season(time()) == "summer") tell_room(TO,"%^RESET%^%^BLUE%^Fireflies drift slowly amidst the tree's branches, their %^GREEN%^lum"
"%^BOLD%^i%^RESET%^%^GREEN%^nesc%^BOLD%^e%^RESET%^%^GREEN%^nt gl%^BOLD%^o%^RESET%^%^GREEN%^w %^BLUE%^winking in and out of sight.%^RESET%^");
           else tell_room(TO,"%^BOLD%^%^BLACK%^A tiny, %^RESET%^gh%^BOLD%^%^BLACK%^os%^RESET%^t-p%^BOLD%^%^BLACK%^a%^RESET%^le %^BOLD%^%^BLACK%^moth "
"alights briefly on the edge of the window, before it rises again into the air and vanishes into the night.%^RESET%^");
           break;
         }
         outside = find_object_or_load(ROOMS"meadow");
         tracker = new(OBJ"strawberries");
         tracker->move(outside);
         weather = (string)WEATHER_D->Check_Weather(tracker);
         tracker->remove();
         if(strsrch(weather,"snow") != -1) { tell_room(TO,"%^BOLD%^%^WHITE%^Snowflakes drift down from the %^RESET%^cl%^BOLD%^%^BLACK%^o%^RESET%^ud"
"%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^WHITE%^sky above, settling upon the tree's gnarled branches just outside the window.%^RESET%^"); break; }
         if(strsrch(weather,"raining") != -1){ tell_room(TO,"%^BLUE%^The sound of falling %^BOLD%^r%^CYAN%^a%^BLUE%^in %^RESET%^%^BLUE%^fills the "
"air, even as the fresh smell it brings drifts in through the window.%^RESET%^"); break; }
         if(strsrch(weather,"mostly cloudy") != -1 || strsrch(weather,"very cloudy") != -1) {
           tell_room(TO,"%^BOLD%^%^BLUE%^An ominous %^RESET%^%^MAGENTA%^rum%^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLUE%^comes from the clouds "
"above, darkening the sky outside.%^RESET%^"); break; }
         if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BOLD%^%^BLACK%^Not even a single cloud interrupts the view from the window "
"of the clear night sky above, the distant stars %^RESET%^spa%^BOLD%^%^WHITE%^r%^RESET%^kli%^BOLD%^%^WHITE%^n%^RESET%^g %^BOLD%^%^BLACK%^brightly.%^RESET%^"); break; }
         if ((string)EVENTS_D->query_time_of_day() == "twilight") { tell_room(TO,"%^RESET%^%^ORANGE%^The setting sun casts lengthening %^BLUE%^shadows "
"%^ORANGE%^across the floor.%^RESET%^"); break; }
         if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^WHITE%^The light of the rising sun inches in across the floor, catching "
"on the bowl of crystal clear water to set it %^BOLD%^%^CYAN%^sp%^BLUE%^a%^CYAN%^rk%^BLUE%^l%^WHITE%^i%^CYAN%^ng%^RESET%^%^ORANGE%^.%^RESET%^"); break; }
         tell_room(TO,"%^BOLD%^%^WHITE%^Bright %^YELLOW%^sunl%^WHITE%^i%^YELLOW%^ght %^WHITE%^floods in through the open window, gleaming upon the surface of "
"the bowl of water, and you catch a second's glimpse of a reflected %^RESET%^%^RED%^r%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w"
"%^BOLD%^%^WHITE%^.%^RESET%^");
       }
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^RESET%^%^BLUE%^The soft lamplight wavers briefly, sending %^RESET%^sh"
"%^BOLD%^%^BLACK%^ad%^RESET%^ows %^BLUE%^flickering about the corners of the room.%^RESET%^"); break; }
       tell_room(TO,"%^GREEN%^Even with the shutters closed, they can't quite block out the faint, distant pounding of the %^BOLD%^%^BLUE%^o%^CYAN%^c"
"%^WHITE%^e%^BLUE%^a%^CYAN%^n%^RESET%^%^GREEN%^ against the cliffs far below.%^RESET%^");
     break;
     case 4..5:
       tell_room(TO,"%^BOLD%^%^WHITE%^Another wave breaks against the jagged cliffs far below, the %^BLUE%^r%^RESET%^%^BLUE%^o%^CYAN%^l%^RESET%^l"
"%^BOLD%^i%^CYAN%^n%^BLUE%^g %^WHITE%^ocean never quite allowing it to grow entirely silent here.%^RESET%^");
     break;
     case 6..7:
       if(shutters) { tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up outside, %^RESET%^rat%^BOLD%^%^BLACK%^t%^RESET%^li%^BOLD%^%^BLACK%^n%^RESET%^g "
"%^BOLD%^%^CYAN%^against the closed shutters.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^WHITE%^A brisk %^CYAN%^bre%^BLUE%^e%^CYAN%^ze %^WHITE%^carries the salty scent of the ocean, stirring the tree's branches "
"to a gentle swaying motion.%^RESET%^");
     break;
     case 8..9:
       if(shutters) {
         if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BLUE%^Somewhere distant, deep within the forest, the lone howl of a "
"%^BOLD%^%^BLACK%^wolf %^RESET%^%^BLUE%^breaks the night's serenity.%^RESET%^"); break; }
         tell_room(TO,"%^ORANGE%^A rustle can be heard amidst the branches outside as %^BOLD%^%^WHITE%^ch%^CYAN%^e%^WHITE%^erf%^MAGENTA%^u%^WHITE%^l "
"%^RESET%^%^ORANGE%^twittering fills the air.%^RESET%^"); break;
       }
       outside = find_object_or_load(ROOMS"meadow");
       tracker = new(OBJ"strawberries");
       tracker->move(outside);
       weather = (string)WEATHER_D->Check_Weather(tracker);
       tracker->remove();
       if(strsrch(weather,"snow") != -1) { tell_room(TO,"%^BOLD%^%^WHITE%^Snowflakes drift down from the %^RESET%^cl%^BOLD%^%^BLACK%^o%^RESET%^ud"
"%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^WHITE%^sky above, settling upon the tree's gnarled branches just outside the window.%^RESET%^"); break; }
       if(strsrch(weather,"raining") != -1){ tell_room(TO,"%^BLUE%^The sound of falling %^BOLD%^r%^CYAN%^a%^BLUE%^in %^RESET%^%^BLUE%^fills the "
"air, even as the fresh smell it brings drifts in through the window.%^RESET%^"); break; }
       if(strsrch(weather,"mostly cloudy") != -1 || strsrch(weather,"very cloudy") != -1) {
         tell_room(TO,"%^BOLD%^%^BLUE%^An ominous %^RESET%^%^MAGENTA%^rum%^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLUE%^comes from outside, "
"the sky darkened to a dull gray.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^BOLD%^%^BLACK%^Not even a single cloud interrupts the view from the window "
"of the clear night sky above, the distant stars %^RESET%^spa%^BOLD%^%^WHITE%^r%^RESET%^kli%^BOLD%^%^WHITE%^n%^RESET%^g %^BOLD%^%^BLACK%^brightly.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "twilight") { tell_room(TO,"%^RESET%^%^ORANGE%^The setting sun casts lengthening %^BLUE%^shadows "
"%^ORANGE%^across the floor.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^WHITE%^The light of the rising sun inches in across the floor, catching "
"on the bowl of crystal clear water to set it %^BOLD%^%^CYAN%^sp%^BLUE%^a%^CYAN%^rk%^BLUE%^l%^WHITE%^i%^CYAN%^ng%^RESET%^%^ORANGE%^.%^RESET%^"); break; }
       tell_room(TO,"%^BOLD%^%^WHITE%^Bright %^YELLOW%^sunl%^WHITE%^i%^YELLOW%^ght %^WHITE%^floods in through the open window, gleaming upon the surface of "
"the bowl of water, and you catch a second's glimpse of a reflected %^RESET%^%^RED%^r%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w"
"%^BOLD%^%^WHITE%^.%^RESET%^");
     break;
     default:
       if ((string)EVENTS_D->query_time_of_day() == "night") { tell_room(TO,"%^MAGENTA%^From somewhere high in the nearby trees carries the hoot of a lone "
"%^RESET%^o%^ORANGE%^w%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^.%^RESET%^"); break; }
       if ((string)EVENTS_D->query_time_of_day() == "dawn") { tell_room(TO,"%^BOLD%^%^BLUE%^A warbling chorus of birdsong greets the %^YELLOW%^d%^MAGENTA%^a"
"%^RED%^w%^YELLOW%^n%^BLUE%^, as the sun peeks over the horizon.%^RESET%^"); break; }
       if(shutters) { tell_room(TO,"%^ORANGE%^A rustle can be heard amidst the branches outside as %^BOLD%^%^WHITE%^ch%^CYAN%^e%^WHITE%^erf%^MAGENTA%^u%^WHITE%^l "
"%^RESET%^%^ORANGE%^twittering fills the air.%^RESET%^"); break; }
       tell_room(TO,"%^ORANGE%^A colorful flash of feathers darts through the branches outside as %^BOLD%^%^WHITE%^ch%^CYAN%^e%^WHITE%^erf%^MAGENTA%^u%^WHITE%^l "
"%^RESET%^%^ORANGE%^twittering fills the air.%^RESET%^");
     break;
   }
   randecho += roll_dice(2,2);
   randecho = randecho%12;
}

int window_func(string str) {
   if(!str) return 0;
   if(str == "shutters open") {
     if(!shutters) {
       tell_object(TP,"%^BOLD%^%^WHITE%^The shutters are already open.%^RESET%^");
       return 1;
     }
     if ((string)EVENTS_D->query_time_of_day() == "night") {
       tell_object(TP,"%^BOLD%^%^WHITE%^You push open the shutters, revealing the dark of night beyond.%^RESET%^");
       tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" pushes open the shutters, revealing the dark of night beyond.%^RESET%^",TP);
     }
     else {
       tell_object(TP,"%^BOLD%^%^WHITE%^You push open the shutters, and bright daylight spills into the room.%^RESET%^");
       tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" pushes open the shutters, and bright daylight spills into the room.%^RESET%^",TP);
     }
     shutters = 0;
     return 1;
   }
   if(str == "shutters closed") {
     if(shutters) {
       tell_object(TP,"%^BOLD%^%^WHITE%^The shutters are already closed.%^RESET%^");
       return 1;
     }
     if ((string)EVENTS_D->query_time_of_day() == "night") {
       tell_object(TP,"%^BOLD%^%^WHITE%^You reach out and pull the shutters closed, blocking out the night beyond.%^RESET%^");
       tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" reaches out and pulls the shutters closed, blocking out the night beyond.%^RESET%^",TP);
     }
     else {
       tell_object(TP,"%^BOLD%^%^WHITE%^You reach out and pull the shutters closed, blocking out the daylight and weather outside.%^RESET%^");
       tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" reaches out and pulls the shutters closed, blocking out the daylight and weather outside.%^RESET%^",TP);
     }
     shutters = 1;
     return 1;
   }
   return 0;
}

int cello_func(string str) {
   if(!str) return 0;
   if(str != "cello") return 0;
   if((string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras" && !avatarp(TP)) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You consider retrieving the cello, but think better of it and leave it in place.%^RESET%^");
     return 1;
   }
   if(!cello) {
     tell_object(TP,"%^BOLD%^%^WHITE%^The cello has already been taken.%^RESET%^");
     return 1;
   }
   remove_item("cello");
   tell_object(TP,"%^BOLD%^%^WHITE%^You step across to retrieve the cello.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" steps across to retrieve the cello.%^RESET%^",TP);
   new(OBJ"cello")->move(TO);
   cello = 0;
   return 1;
}

void reset_cello() {
   add_item("cello",(:TO,"cello_desc":));
   cello = 1;
}

int sense_it(string str) {
   string *observed, mymessage;
   int i;
   if(!str) return 0;
   if(str != "trespassers") return 0;
   if(!avatarp(TP) && (string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras") {
     tell_object(TP,"%^CYAN%^You try as you might to attune your senses to the tree, but you cannot sense any trespassers.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   observed = ({});
   observed += (string *)SAVE_D->query_array("mithras_tree");
   if(!sizeof(observed)) {
     tell_object(TP,"%^CYAN%^You grow still and attune yourself to the tree, but its peaceful nature tells you it has sensed noone here.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   mymessage = observed[i];
   for(i = 1;i<sizeof(observed);i++) {
     mymessage += ", ";
     mymessage += observed[i];
   }
   tell_object(TP,"%^CYAN%^You grow still and attune yourself to the tree, and you can sense those that have walked here. It has felt the presence of %^RESET%^"+mymessage+"%^CYAN%^.%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
   return 1;
}

int purge_it(string str) {
   if(!str) return 0;
   if(str != "trespassers") return 0;
   if(!avatarp(TP) && (string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras") {
     tell_object(TP,"%^CYAN%^You attune your senses to the tree, but nothing happens.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   if(!sizeof((string *)SAVE_D->query_array("mithras_tree"))) {
     tell_object(TP,"%^CYAN%^You attune your senses to the tree, but its peaceful nature tells you it has nothing to forget.%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^CYAN%^You attune your senses to the tree, soothing it until its recollections fade.%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+" closes "+TP->QP+" eyes and concentrates briefly.%^RESET%^",TP);
   SAVE_D->remove_array("mithras_tree");
   return 1;
}

int door_fun(string str) {
   object mainroom;
   if(!str) return 0;
   if(str != "outline") return 0;
   if(query_open("inner door")) return 0;
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" reaches out and marks a line with a finger along a section of the wall. "
"The outline of a door appears in the bark and it swings open.%^RESET%^",TP);
   tell_object(TP,"%^GREEN%^You trace the outline of the door upon the wall, and it swings open.%^RESET%^");
   set_open("inner door", 1);
   set_invis_exits(({}));
   mainroom = find_object_or_load(ROOMS"upstairs");
   mainroom->set_open("inner door",1);
   mainroom->set_invis_exits(({}));
   tell_room(mainroom,"You notice the inner door suddenly open from the other side.");
   return 1;
}

int CloseDoor(string str) {
   object mainroom;
   ::CloseDoor(str);
   if(str == "inner door") {
     set_invis_exits(({"up"}));
     mainroom = find_object_or_load(ROOMS"upstairs");
     mainroom->set_invis_exits(({"down"}));
     tell_room(mainroom,"The inner door is closed by someone on the other side.");
     return 1;
   }
   if(str == "door") {
     mainroom = find_object_or_load(ROOMS"meadow");
     mainroom->set_invis_exits(({"tree"}));
     return 1;
   }
   return 0;
}

int OpenDoor(string str) {
   object mainroom;
   ::OpenDoor(str);
   if(str == "door") {
     mainroom = find_object_or_load(ROOMS"meadow");
     mainroom->set_invis_exits(({}));
     return 1;
   }
   return 0;
}

int search_room(string str) {
   if (!str) return 0;
   if (str == "walls") {
     tell_object(TP,"%^BOLD%^%^WHITE%^A closer inspection of the smooth walls reveals a faint outline scored into "
"the wood, roughly the size of a second and slightly smaller doorway.%^RESET%^\n");
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