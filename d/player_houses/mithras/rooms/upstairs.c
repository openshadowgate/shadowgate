// Aerdrian Harp based on Aeolian Harp, http://www.youtube.com/watch?v=M8ThB4uCYp4 & http://www.youtube.com/watch?v=qESQa8UHCTw
#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit VAULT;

int randecho, harp, shutters;
string harpdesc;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(BRANCHES);
    set_travel(LEDGE);
    set_name("A simple bedroom");
    set_short("%^RESET%^%^ORANGE%^A si%^GREEN%^m%^ORANGE%^ple bedr%^GREEN%^o%^ORANGE%^om%^RESET%^");
    set_long((:TO,"long_desc":));
    set_smell("default","%^RESET%^%^ORANGE%^The clean, crisp air bears the %^BOLD%^%^WHITE%^sa%^CYAN%^lt%^WHITE%^y %^RESET%^%^ORANGE%^tang of the sea.%^RESET%^");
    set_listen("default",(:TO,"default_listen":));
    set_listen("shell",(:TO,"shell_fun":));
    set_listen("conch",(:TO,"shell_fun":));
    set_listen("conch shell",(:TO,"shell_fun":));

    set_items(([
      ({"walls","roof","floor"}) : (:TO,"walls_desc":),
      ({"window","shutters"}) : (:TO,"window_desc":),
      ({"harp","box"}) : (:TO,"harp_desc":),
      ({"alcove","bowl","shrine"}) : (:TO,"shrine_desc":),
      "tub" : "%^ORANGE%^The opposite side of the room to the bed is taken up by a large tub, again seemingly grown of the tree's wood itself.  It looks more than deep enough for comfort and "
"set partly back into the wall itself, with the lip raised far enough to prevent water escaping.  A small ledge sits to one side, able to hold a few personal effects.  Upon a rung beside it "
"hang several towels, including one of %^BOLD%^%^RED%^s%^RESET%^%^RED%^o%^BOLD%^%^RED%^ft red co%^RESET%^%^RED%^t%^BOLD%^ton%^RESET%^%^ORANGE%^.  While it has been fitted with taps and a drain"
", to permit water to come and go, you can't imagine where they lead inside a tree.  Perhaps some kind of minor enchantment?%^RESET%^",
      "rug" : "%^ORANGE%^A rug of %^GREEN%^r%^BOLD%^i%^RESET%^%^GREEN%^ch e%^CYAN%^m%^GREEN%^er%^BOLD%^a%^YELLOW%^l%^RESET%^%^GREEN%^d g%^BOLD%^re%^RESET%^%^GREEN%^en %^ORANGE%^covers most of "
"the free floor area.  It is incredibly soft underfoot, and %^RED%^th%^MAGENTA%^ic%^RED%^k %^ORANGE%^enough to sink your toes into.%^RESET%^",
      "bed" : "%^ORANGE%^To one side of the room lies a bed, its frame cut from %^RESET%^pa%^BOLD%^%^BLACK%^l%^RESET%^e bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^.  "
"While not particularly decadent, it would easily sleep several people upon the comfortable matress it bears.  Soft sheets have been dyed the same pale %^GREEN%^gr%^CYAN%^ee%^GREEN%^n "
"%^ORANGE%^as the slips of the pillows, while a thick quilt lies folded at the foot of the bed, ready for use in %^BOLD%^%^WHITE%^col%^CYAN%^d%^WHITE%^er %^RESET%^%^ORANGE%^weather.%^RESET%^",
      ({"table","bedside table"}) : "%^ORANGE%^The small bedside table is carved of the same %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d"
"%^ORANGE%^ as the rest of the room's furniture.  Upon it sit what look to be someone's personal possessions, mostly mundane items, though they also include a %^RESET%^c%^ORANGE%^o%^BOLD%^"
"%^WHITE%^n%^RESET%^%^ORANGE%^c%^RESET%^h s%^BOLD%^%^WHITE%^h%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l%^RESET%^%^ORANGE%^ a jar of %^RED%^p%^MAGENTA%^a%^GREEN%^i%^CYAN%^n%^YELLOW%^t%^RESET%^"
"%^MAGENTA%^e%^BOLD%^%^BLUE%^d %^RESET%^%^ORANGE%^sand, and an oddly decorated %^BOLD%^%^BLUE%^j%^GREEN%^u%^RESET%^%^CYAN%^m%^BOLD%^b%^RESET%^%^GREEN%^l%^BLUE%^e %^ORANGE%^of feathers, leaves "
"and water droplets.%^RESET%^",
      "chest" : (:TO,"chest_desc":),
      ({"jar","jar of sand","sand"}) : "%^ORANGE%^This narrow jar is perfectly clear, revealing the painted sand inside.  Layers of %^BOLD%^%^GREEN%^light green%^RESET%^%^ORANGE%^, %^BOLD%^"
"%^CYAN%^turquoise%^RESET%^%^ORANGE%^ and %^BOLD%^%^BLUE%^blue sand %^RESET%^%^ORANGE%^alternate at different thicknesses with bands of %^BOLD%^%^BLACK%^black sand%^RESET%^%^ORANGE%^.  The "
"varying bands of sand look %^CYAN%^windswept%^ORANGE%^, echoing the landscape of the beach.%^RESET%^",
      ({"conch","shell","conch shell"}) : "%^ORANGE%^This attractive shell is fairly large at nearly five inches in length and is rolled like the typical %^RESET%^c%^ORANGE%^o%^BOLD%^%^WHITE%^n"
"%^RESET%^%^ORANGE%^c%^RESET%^h %^ORANGE%^with one end pointed and spiked.  The roll fans out into even more small spikes that help keep it sitting flat.  The outer part of the shell is a "
"darker o%^YELLOW%^r%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^ge in color with the spikes ending in a deep brown, while the inside of the shell is smooth in texture and a lighter shade "
"of %^MAGENTA%^c%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^MAGENTA%^l%^RESET%^%^ORANGE%^.  It is said that if you listen to these shells, one can hear the sounds of the "
"ocean.%^RESET%^",
      ({"jumble","feathers","leaves","droplets","water droplets"}) : "%^ORANGE%^You can't even begin to imagine the purpose of this odd jumble.  A twig and several stiff, %^BOLD%^%^GREEN%^b"
"%^RESET%^%^GREEN%^r%^CYAN%^i%^BOLD%^t%^RESET%^%^GREEN%^t%^BOLD%^l%^RESET%^%^GREEN%^e %^ORANGE%^leaves have been bound around two droplets of %^BOLD%^%^CYAN%^wat%^WHITE%^e%^CYAN%^r %^RESET%^"
"%^ORANGE%^that never seem to lose their shape.  Thin leather straps hold them in place along with two feathers, one %^BLUE%^dark blue %^ORANGE%^and the other one strangely %^CYAN%^azure"
"%^ORANGE%^.%^RESET%^",
      "lanterns" : (:TO,"lantern_desc":),
      "paintings" : "%^ORANGE%^Two paintings have been placed in clear view upon the walls, one at either side of the bed.  The first is of a scene of %^RESET%^m%^BOLD%^%^BLACK%^i%^WHITE%^s"
"%^RESET%^t%^ORANGE%^, and is of such finesse that it could only be a master's work.  The second is much more simple, depicting several figures in what appears to be a %^BOLD%^%^WHITE%^c"
"%^YELLOW%^h%^WHITE%^i%^MAGENTA%^l%^WHITE%^d's %^RESET%^%^ORANGE%^hand.%^RESET%^",
      ({"first painting","painting 1"}) : "%^RESET%^Painted in only shades of %^BOLD%^g%^BLACK%^r%^RESET%^e%^BOLD%^y %^RESET%^on a white, coarse canvas, this image shows a strangely painted "
"image of misty scene.  A p%^BOLD%^oo%^RESET%^l is surrounded only by hints of a sto%^BOLD%^%^BLACK%^n%^RESET%^y shore, hemmed to narrow proportions.  Rising from the water, ten%^BOLD%^dr"
"%^RESET%^ils of steam dissipate as if they never existed, and caressed by the stillness is a %^BOLD%^woman%^RESET%^.  She floats, arms spread in a grey garment, her arms drawn far to the sides"
", as if to reach for the walls of the pool.  The womans garment is long, flowing, and though fitted to form, finds a free expression with the water.  Caressing her head is a dark ha%^BOLD%^"
"%^BLACK%^l%^RESET%^o of %^BOLD%^%^BLACK%^black hair%^RESET%^, passing through the water as if one with the substance.  The woman's expression is truly peaceful, graced with a hint of a smile "
"upon slightly parted lips.  Somehow, the artist has presented a beautiful scene with only two shades on what is at points a raw canvas.  And yet, you wonder if the woman is truly there, "
"embraced by the steam.  The only color on the canvas is a tiny, fine brushed message: '%^BOLD%^%^RED%^M - for M.%^RESET%^'",
      ({"second painting","painting 2"}) : "%^ORANGE%^This second painting is as like to the first as chalk and cheese, bearing none of the elegance or masterful artistry.  Instead, it bears a "
"%^BOLD%^%^WHITE%^si%^YELLOW%^m%^MAGENTA%^p%^WHITE%^lic%^CYAN%^i%^WHITE%^ty %^RESET%^%^ORANGE%^of design that is likely the work of a child.  Four figures are roughly daubed onto the canvas "
"upon a field of %^BOLD%^%^GREEN%^green%^RESET%^%^ORANGE%^.  The first two are taller than the others and both have %^BOLD%^%^BLACK%^dark hair%^RESET%^%^ORANGE%^, one clad in an emerald dress "
"and the other in a dark coat.  In the centre stands a third figure with her arms spread wide, her %^YELLOW%^sho%^WHITE%^r%^YELLOW%^t bl%^WHITE%^o%^YELLOW%^nde ha%^WHITE%^i%^YELLOW%^r %^RESET%^"
"%^ORANGE%^askew about her face.  All three are smiling, though the fourth figure seems much more somber, again of dark hair and sitting off to the side.  In her lap has been brushed some kind "
"of small, four legged animal, but oddly enough the creature has been added in bright %^BOLD%^%^MAGENTA%^pi%^RESET%^%^MAGENTA%^n%^BOLD%^k%^RESET%^%^ORANGE%^ paint.%^RESET%^",
    ]));
    randecho = random(12);
    shutters = 0;
    harp = 1;
    harpdesc = "what appears to be a harp, carved of %^BOLD%^%^WHITE%^sn%^RESET%^ow%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^weirwood";
    set_search("walls",(:TO,"search_room":));
    set_exits(([
      "down" : ROOMS"tree",
    ]));
    set_invis_exits(({"down"}));
    set_property("blessed",({"sune","istishia","eldath"}));
    set_door("inner door",ROOMS"tree","down","hasnokey","lock");
    set_locked("inner door",1);
    lock_difficulty("inner door", "/daemon/player_housing"->get_phouse_lock_dc("epic"),"lock"); // very simple syntax but no keyhole; not designed to be lockpicked.
    set_lock_description("inner door","lock","%^BOLD%^%^BLACK%^No handle or keyhole are visible upon the smooth wooden surface.%^RESET%^");
    set_door_description("inner door","%^RESET%^Only readily apparent when opened, this door seems to be part of the %^ORANGE%^t%^GREEN%^r%^ORANGE%^ee %^RESET%^itself, and vanishes almost "
"entirely from sight when shut.  Smooth %^ORANGE%^wooden %^RESET%^hinges allow it to open and close soundlessly, and its entire outer surface is of the same %^BOLD%^%^WHITE%^s%^RESET%^i"
"%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^bark as the walls.");
    set_string("door", "close", "The wooden door swings shut with only a faint click, and its outline merges with the wall to vanish from sight.");
}

void init() {
   string myname,myadj;
   ::init();
   add_action("cover_harp","cover");
   add_action("uncover_harp","uncover");
   add_action("window_func","draw");
   add_action("robe_func","retrieve");
   add_action("sense_it","sense");
   add_action("purge_it","purge");
   add_action("door_fun","trace");
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
   if(harp) return "%^RESET%^%^GREEN%^As the %^CYAN%^bre%^BOLD%^e%^RESET%^%^CYAN%^ze %^GREEN%^rises, a faint %^MAGENTA%^m%^RED%^el%^MAGENTA%^o%^RED%^d%^MAGENTA%^y %^GREEN%^drifts from the harp "
"by the window.%^RESET%^";
   return "%^RESET%^%^GREEN%^The gentle whispering %^CYAN%^bre%^BOLD%^e%^RESET%^%^CYAN%^ze %^GREEN%^is accompanied by the distant crash of %^BOLD%^%^BLUE%^o%^CYAN%^c%^WHITE%^e%^BLUE%^a%^CYAN%^n "
"%^RESET%^%^GREEN%^waves.%^RESET%^";
}

string shell_fun(string str){
   return "%^RESET%^%^CYAN%^You lift the %^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l %^RESET%^%^CYAN%^from the bedside table and hold it to "
"your ear, and the sounds of the %^RESET%^o%^CYAN%^c%^BOLD%^e%^BLUE%^a%^WHITE%^n %^RESET%^%^CYAN%^whisper from within its depths, echoing those of the distantly "
"crashing waves outside.%^RESET%^";
}

string lanterns_short() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "A pair of softly %^YELLOW%^glow%^WHITE%^i%^YELLOW%^ng %^RESET%^%^ORANGE%^lanterns are supported by curved stands, shedding soft illumination upon the two %^MAGENTA%^pa%^BLUE%^i"
"%^MAGENTA%^nt%^CYAN%^i%^MAGENTA%^n%^BLUE%^g%^MAGENTA%^s %^ORANGE%^that grace the walls near the bed.";
   return "A pair of lanterns upon curved stands sit close to the bed, while two %^MAGENTA%^pa%^BLUE%^i%^MAGENTA%^nt%^CYAN%^i%^MAGENTA%^n%^BLUE%^g%^MAGENTA%^s %^ORANGE%^grace the walls nearby.";
}

string long_desc() {
   return("%^RESET%^%^ORANGE%^This room is of an uneven shape, neither square nor properly circular, with the smooth floor and tapering walls all formed of pale %^RESET%^s%^BOLD%^%^WHITE%^i"
"%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood that seems to have grown naturally into shape.  Upon one wall, the wood has "
"parted to allow a single space that would serve as a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, set with hinged shutters to close out poor weather.  Upon a ledge beneath the "
"window lies "+harpdesc+".  Within the wall directly opposite the window is an indented alcove, where a simple carved bowl rests, surrounded by %^RED%^fl%^MAGENTA%^o%^BOLD%^w%^RESET%^%^RED%^e"
"%^BOLD%^r%^RESET%^%^RED%^s %^ORANGE%^and %^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^s%^ORANGE%^.  A soft %^GREEN%^gr%^CYAN%^ee%^GREEN%^n %^ORANGE%^rug takes up a "
"considerable portion of the clear floor, past which stands a simple bed of %^RESET%^pa%^BOLD%^%^BLACK%^l%^RESET%^e bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^.  "
"Beside it sits a small table, while a large chest lies at its feet.  "+lanterns_short()+"  The opposite side of the room is taken up by a large tub, again apparently grown from the tree's wood "
"itself.%^RESET%^\n");
}

string walls_desc() {
   if((string)TP->query_name() == "marie" || (string)TP->query_name() == "mithras" || avatarp(TP)) 
     return "%^ORANGE%^The uneven shape of the room's walls is caused perhaps by the growth of the tree it resides in.  It seems impossible that the tree could've grown this precisely without "
"some kind of direction, though, for the floor is surprisingly flat underfoot.  Both it and the walls are of a pale %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g"
"%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood, smooth to the touch.  It seems that this room is likely high up in the tree, for while the base is likely the inside of "
"the tree's trunk, interwoven branches become apparent towards the top of the room, so closely interlocked that no %^RESET%^l%^BOLD%^i%^YELLOW%^g%^WHITE%^h%^RESET%^t %^ORANGE%^or %^CYAN%^w"
"%^BLUE%^e%^CYAN%^a%^BOLD%^t%^BLUE%^he%^RESET%^%^BLUE%^r %^ORANGE%^slips through, save where they have parted in the eastern wall to form a single broad window.  There is what appears to be a "
"circular vent at the very peak of the tapered roof above, but even it bears a hood to keep out the rain.  Your inner connection to the tree itself leaves you knowing that you could %^RESET%^"
"sense trespassers%^ORANGE%^ that have been here, or %^RESET%^purge trespassers%^ORANGE%^ to soothe the tree of its recollections.%^RESET%^";
   return "%^ORANGE%^The uneven shape of the room's walls is caused perhaps by the growth of the tree it resides in.  It seems impossible that the tree could've grown this precisely without "
"some kind of direction, though, for the floor is surprisingly flat underfoot.  Both it and the walls are of a pale %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^r-g"
"%^BOLD%^%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^wood, smooth to the touch.  It seems that this room is likely high up in the tree, for while the base is likely the inside of "
"the tree's trunk, interwoven branches become apparent towards the top of the room, so closely interlocked that no %^RESET%^l%^BOLD%^i%^YELLOW%^g%^WHITE%^h%^RESET%^t %^ORANGE%^or %^CYAN%^w"
"%^BLUE%^e%^CYAN%^a%^BOLD%^t%^BLUE%^he%^RESET%^%^BLUE%^r %^ORANGE%^slips through, save where they have parted in the eastern wall to form a single broad window.  There is what appears to be a "
"circular vent at the very peak of the tapered roof above, but even it bears a hood to keep out the rain.%^RESET%^";
}

string window_desc() {
   object outside, tracker;
   string weather;
   if(shutters) {
     return ("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges lie closed against the "
"outdoors and the weather beyond.  You could %^RESET%^draw shutters open %^ORANGE%^to see outside.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter")
       return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards upon the "
"dark of %^BLUE%^night%^ORANGE%^, where tiny stars sparkle and gleam amidst the overhang of %^BOLD%^%^CYAN%^f%^WHITE%^ro%^CYAN%^st%^RESET%^%^ORANGE%^-chilled foliage.  You could %^RESET%^draw "
"shutters closed %^ORANGE%^to block out the night beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
     if (season(time()) == "autumn")
       return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards upon the "
"dark of %^BLUE%^night%^ORANGE%^, where tiny stars sparkle and gleam amidst the overhang of l%^RED%^ea%^ORANGE%^v%^YELLOW%^e%^RESET%^%^ORANGE%^s.  You could %^RESET%^draw shutters closed "
"%^ORANGE%^to block out the night beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
     if (season(time()) == "summer")
       return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards upon the "
"dark of %^BLUE%^night%^ORANGE%^, where luminous %^YELLOW%^fi%^GREEN%^r%^YELLOW%^ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^ORANGE%^ drift amidst the overhang of %^GREEN%^l%^BOLD%^ea"
"%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^s%^ORANGE%^.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the night beyond.  Upon the ledge beneath the window lies "
+harpdesc+".%^RESET%^");
     return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards upon the "
"dark of %^BLUE%^night%^ORANGE%^, where tiny stars sparkle and gleam amidst the overhang of %^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^s%^ORANGE%^.  You could %^RESET%^"
"draw shutters closed %^ORANGE%^to block out the night beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "twilight")
     return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards, allowing "
"the last rays of the day's sunlight to cast long %^BLUE%^shadows %^ORANGE%^across the floor.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the sunset beyond.  Upon the ledge "
"beneath the window lies "+harpdesc+".%^RESET%^");
   if ((string)EVENTS_D->query_time_of_day() == "dawn")
     return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards, letting in "
"the %^BOLD%^%^YELLOW%^br%^MAGENTA%^i%^YELLOW%^ll%^CYAN%^i%^WHITE%^a%^YELLOW%^nt %^RESET%^%^ORANGE%^light of dawn.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out the sunrise "
"beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
   outside = find_object_or_load(ROOMS"meadow");
   tracker = new(OBJ"strawberries");
   tracker->move(outside);
   weather = (string)WEATHER_D->Check_Weather(tracker);
   tracker->remove();
   if(strsrch(weather,"snow") != -1)
     return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards, where tiny "
"%^RESET%^sn%^BOLD%^%^WHITE%^ow%^RESET%^fla%^BOLD%^%^WHITE%^k%^RESET%^es %^ORANGE%^drift past the tree's overhanging branches.  You could %^RESET%^draw shutters closed %^ORANGE%^to block out "
"the weather beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
   if(strsrch(weather,"raining") != -1)
     return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards, where "
"gentle %^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^ai%^BOLD%^nf%^CYAN%^a%^WHITE%^l%^BLUE%^l %^RESET%^%^ORANGE%^drips from the tree's overhanging branches.  You could %^RESET%^draw shutters closed "
"%^ORANGE%^to block out the weather beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
   if(strsrch(weather,"cloudy") != -1)
     return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards, though the "
"best of the day's %^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^RESET%^%^ORANGE%^is shadowed as much by the tree's branches as by the cloudcover overhead.  You could %^RESET%^draw shutters closed "
"%^ORANGE%^to block out the weather beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
   return("%^RESET%^%^ORANGE%^Within the room's eastern wall, the %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^y %^RESET%^%^ORANGE%^"
"tree branches have grown apart to allow for a broad %^CYAN%^win%^BOLD%^d%^RESET%^%^CYAN%^ow%^ORANGE%^, forming a roughly oval shape.  Wooden shutters on simple hinges open outwards, allowing "
"bright sunlight to spill across the middle of the room and %^BOLD%^%^CYAN%^g%^WHITE%^l%^CYAN%^eam %^RESET%^%^ORANGE%^upon the bowl of crystalline water.  You could %^RESET%^draw shutters "
"closed %^ORANGE%^to block out the sunlight beyond.  Upon the ledge beneath the window lies "+harpdesc+".%^RESET%^");
}

string harp_desc() {
   if(harp) {
     if ((int)TP->query_skill("academics") > 25 || (string)TP->query_race() == "elf") {
       return ("%^RESET%^%^ORANGE%^A closer inspection reveals this carved piece to be an exotic instrument.  Shaped from %^BOLD%^%^WHITE%^sn%^RESET%^ow%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^"
"weirwood, it consists of a single flat platform base with small, ornately turned feet.  From this level foundation rise equally ornate carvings of twin %^CYAN%^b%^BOLD%^i%^RESET%^%^CYAN%^rds "
"%^ORANGE%^in flight, one at either end, their pale wings flared and every feather marked out in flawless detail.  Between them run a score of %^BOLD%^%^WHITE%^g%^RESET%^le%^BOLD%^%^BLACK%^am"
"%^RESET%^in%^BOLD%^%^WHITE%^g %^RESET%^%^ORANGE%^strings, each of varied lengths for their placement along the avian outlines.  Even more startling than the craftsmanship, however, is that "
"this instrument seems to play itself, a series of %^MAGENTA%^g%^RED%^en%^MAGENTA%^tle %^ORANGE%^notes and chords rising from the strings whenever the breeze picks up by the open window.  A "
"half-casing of the same %^BOLD%^%^WHITE%^w%^RESET%^hi%^BOLD%^%^WHITE%^te %^RESET%^%^ORANGE%^wierwood rests beside the harp, etched with matching carvings of tiny birds in flight, which could "
"be used to cover the instrument to silence it.  This could only be an %^CYAN%^Ae%^BOLD%^r%^RESET%^%^CYAN%^dri%^BOLD%^a%^RESET%^%^CYAN%^n Ha%^BOLD%^r%^RESET%^%^CYAN%^p%^ORANGE%^, an ancient "
"style of elven instrument dedicated to the Winged Mother, Aerdrie Faenya.%^RESET%^");
     }
     return("%^RESET%^%^ORANGE%^A closer inspection reveals this carved piece to be an exotic instrument.  Shaped from %^BOLD%^%^WHITE%^sn%^RESET%^ow%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^"
"weirwood, it consists of a single flat platform base with small, ornately turned feet.  From this level foundation rise equally ornate carvings of twin %^CYAN%^b%^BOLD%^i%^RESET%^%^CYAN%^rds "
"%^ORANGE%^in flight, one at either end, their pale wings flared and every feather marked out in flawless detail.  Between them run a score of %^BOLD%^%^WHITE%^g%^RESET%^le%^BOLD%^%^BLACK%^am"
"%^RESET%^in%^BOLD%^%^WHITE%^g %^RESET%^%^ORANGE%^strings, each of varied lengths for their placement along the avian outlines.  Even more startling than the craftsmanship, however, is that "
"this instrument seems to play itself, a series of %^MAGENTA%^g%^RED%^en%^MAGENTA%^tle %^ORANGE%^notes and chords rising from the strings whenever the breeze picks up by the open window.  A "
"half-casing of the same %^BOLD%^%^WHITE%^w%^RESET%^hi%^BOLD%^%^WHITE%^te %^RESET%^%^ORANGE%^wierwood rests beside the harp, etched with matching carvings of tiny birds in flight, which could "
"be used to cover the instrument to silence it.%^RESET%^");
   }
   return("%^RESET%^%^ORANGE%^This box of %^BOLD%^%^WHITE%^sn%^RESET%^ow%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^weirwood is simple but elegant, carved with images of tiny %^CYAN%^b%^BOLD%^i"
"%^RESET%^%^CYAN%^rds %^ORANGE%^across its pale surface.  It consists of a single flat platform base with small, ornately turned feet, and a half-casing that serves as a lid to cover whatever "
"lies within.  It could easily be lifted to %^RESET%^uncover %^ORANGE%^its contents.%^RESET%^");
}

string shrine_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^ORANGE%^A small alcove appears to have grown back into the wall that lies directly opposite the window.  It seems situated so that it would catch the %^BOLD%^%^WHITE%^M%^RESET%^oo"
"%^BOLD%^%^WHITE%^nl%^RESET%^ig%^BOLD%^%^WHITE%^ht %^RESET%^%^ORANGE%^when the window lay open.   Within it rests a plain, flat wooden bowl filled with %^CYAN%^cr%^BOLD%^y%^WHITE%^s%^CYAN%^t"
"%^RESET%^%^CYAN%^al-c%^BOLD%^l%^WHITE%^e%^CYAN%^a%^RESET%^%^CYAN%^r %^ORANGE%^water, upon which float several %^RED%^r%^MAGENTA%^o%^BOLD%^s%^RESET%^%^RED%^e %^ORANGE%^petals.  Around the bowl "
"lie a scattering of fresh %^RED%^cr%^BOLD%^i%^RESET%^%^RED%^mson %^ORANGE%^rose blossoms, and a few %^GREEN%^fe%^BOLD%^r%^RESET%^%^GREEN%^n f%^BOLD%^r%^YELLOW%^o%^RESET%^%^GREEN%^n%^BOLD%^d"
"%^RESET%^%^GREEN%^s%^ORANGE%^.  Its purpose doesn't seem readily apparent, perhaps simply a decoration, or a dedication of some kind?%^RESET%^";
   return "%^ORANGE%^A small alcove appears to have grown back into the wall that lies directly opposite the window.  It seems situated so that it would catch the %^YELLOW%^su%^WHITE%^n"
"%^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^RESET%^%^ORANGE%^when the window lay open.   Within it rests a plain, flat wooden bowl filled with %^CYAN%^cr%^BOLD%^y%^WHITE%^s%^CYAN%^t%^RESET%^%^CYAN%^al"
"-c%^BOLD%^l%^WHITE%^e%^CYAN%^a%^RESET%^%^CYAN%^r %^ORANGE%^water, upon which float several %^RED%^r%^MAGENTA%^o%^BOLD%^s%^RESET%^%^RED%^e %^ORANGE%^petals.  Around the bowl lie a scattering of "
"fresh %^RED%^cr%^BOLD%^i%^RESET%^%^RED%^mson %^ORANGE%^rose blossoms, and a few %^GREEN%^fe%^BOLD%^r%^RESET%^%^GREEN%^n f%^BOLD%^r%^YELLOW%^o%^RESET%^%^GREEN%^n%^BOLD%^d%^RESET%^%^GREEN%^s"
"%^ORANGE%^.  Its purpose doesn't seem readily apparent, perhaps simply a decoration, or a dedication of some kind?%^RESET%^";
}

string chest_desc() {
   if((string)TP->query_name() == "marie" || (string)TP->query_name() == "mithras" || avatarp(TP)) 
     return "%^ORANGE%^A large, unmarked chest of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^ rests at the foot of the bed, "
"likely used to store clothing and other such day to day items.  If you had a suitable magerobe, you could %^RESET%^retrieve robe with itemname%^ORANGE%^ to obtain one made of green wool "
"instead, or %^RESET%^retrieve coat with itemname%^ORANGE%^ for an overcoat of black leather.%^RESET%^";
     return "%^ORANGE%^A large, unmarked chest of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^ rests at the foot of the bed, "
"likely used to store clothing and other such day to day items.%^RESET%^";
}

string lantern_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return "%^ORANGE%^Twin lanterns stand a short distance away from the foot of the bed, one at either side.  Consisting of single small cages, they are carved with %^GREEN%^e%^CYAN%^le"
"%^GREEN%^ga%^CYAN%^n%^GREEN%^t %^ORANGE%^simplicity, though no candle or oil lies within, leaving you to surmise that the soft %^YELLOW%^gl%^WHITE%^o%^YELLOW%^w%^RESET%^%^ORANGE%^ emitted by "
"each is raised by some form of spellcraft.  Each is supported upon a curved stand of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d"
"%^ORANGE%^, matched with the rest of the room's furnishings.%^RESET%^";
   return "%^ORANGE%^Twin lanterns stand a short distance away from the foot of the bed, one at either side.  Consisting of single small cages, they are carved with %^GREEN%^e%^CYAN%^le"
"%^GREEN%^ga%^CYAN%^n%^GREEN%^t %^ORANGE%^simplicity, though no candle or oil lies within.  Each is supported upon a curved stand of %^RESET%^g%^BOLD%^%^BLACK%^r%^RESET%^ay bi%^BOLD%^%^BLACK%^rc"
"%^RESET%^hwo%^BOLD%^%^BLACK%^o%^RESET%^d%^ORANGE%^, matched with the rest of the room's furnishings.%^RESET%^";
}

void reset() {
   string weather;
   object tracker, outside;
   ::reset();
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
       if(shutters || !harp) { tell_room(TO,"%^BOLD%^%^WHITE%^Another wave breaks against the jagged cliffs far below, the %^BLUE%^r%^RESET%^%^BLUE%^o"
"%^CYAN%^l%^RESET%^l%^BOLD%^i%^CYAN%^n%^BLUE%^g %^WHITE%^ocean never quite allowing it to grow entirely silent here.%^RESET%^"); break; }
       tell_room(TO,"%^GREEN%^A gust of wind picks a series of single, %^CYAN%^de%^BOLD%^l%^RESET%^%^CYAN%^ica%^BOLD%^t%^RESET%^%^CYAN%^e %^GREEN%^notes "
"from the harp that hum gently forth into the air.%^RESET%^");
     break;
     case 6..7:
       if(shutters) { tell_room(TO,"%^BOLD%^%^CYAN%^The wind picks up outside, %^RESET%^rat%^BOLD%^%^BLACK%^t%^RESET%^li%^BOLD%^%^BLACK%^n%^RESET%^g "
"%^BOLD%^%^CYAN%^against the closed shutters.%^RESET%^"); break; }
       if(harp) { tell_room(TO,"%^BOLD%^%^WHITE%^A brisk %^CYAN%^bre%^BLUE%^e%^CYAN%^ze %^WHITE%^carries the salty scent of the ocean, stirring a gentle "
"series of %^RESET%^%^MAGENTA%^cho%^BOLD%^r%^RESET%^%^MAGENTA%^ds %^BOLD%^%^WHITE%^from the harp.%^RESET%^"); break; }
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

int cover_harp(string str) {
   if (!str) return 0;
   if (str != "harp") return 0;
   if(!harp) {
     tell_object(TP,"%^BOLD%^%^WHITE%^The harp is already covered.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You lift the harp's casing and set it carefully over the instrument, which grows silent.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" lifts the harp's casing and sets it carefully over the instrument, which grows silent.%^RESET%^",TP);
   harp = 0;
   harpdesc = "a covered box of %^BOLD%^%^WHITE%^sn%^RESET%^ow%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^weirwood";
   return 1;
}

int uncover_harp(string str) {
   if (!str) return 0;
   if (str != "harp" && str != "box") return 0;
   if(harp) {
     tell_object(TP,"%^BOLD%^%^WHITE%^The harp is already uncovered.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You lift the casing from atop the box to reveal a many-stringed instrument, much like a harp.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" lifts the casing from atop the box to reveal a many-stringed instrument, much like a harp.%^RESET%^",TP);
   harp = 1;
   harpdesc = "what appears to be a harp, carved of %^BOLD%^%^WHITE%^sn%^RESET%^ow%^BOLD%^%^WHITE%^y %^RESET%^%^ORANGE%^weirwood";
   call_out("humming",roll_dice(2,8));
   return 1;
}

void humming() {
   if(!objectp(TO)) return;
   if(!harp) return;
   tell_room(TO,"%^BOLD%^%^CYAN%^A series of soft notes rise from the harpstrings as the %^RESET%^%^CYAN%^bre%^BOLD%^e%^RESET%^%^CYAN%^ze %^BOLD%^picks up by the window.%^RESET%^");
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

int robe_func(string str) {
   object swapobj;
   int myenchant, mycarry;
   string *mylimbs, mytype;

   if(!str) return 0;
   if((string)TP->query_name() != "marie" && (string)TP->query_name() != "mithras" && !avatarp(TP)) return 0;
   if(sscanf(str,"%s with %s", mytype, str) != 2) return 0;
   if(mytype != "robe" && mytype != "coat") return 0;

   swapobj = present(str,TP);
   if(!objectp(swapobj)) {
     tell_object(TP,"You don't have a "+str+"!");
     return 1;
   }
   if((string)swapobj->query_type() != "clothing") {
     tell_object(TP,"That is not a garment.");
     return 1;
   }
   if((int)swapobj->query_size() != 2) {
     tell_object(TP,"That garment is the wrong size.");
     return 1;
   }
   mycarry = (int)swapobj->query_max_internal_encumbrance();
   if(!mycarry) {
     tell_object(TP,"That is just a mundane robe, not a magerobe.");
     return 1;
   }
   mylimbs = ({});
   mylimbs += swapobj->query_limbs();
   if(member_array("torso",mylimbs) == -1) {
     tell_object(TP,"You can't wear that garment as a robe.");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^WHITE%^You forgo the "+str+" to retrieve a new garment.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" retrieves a simple garment from the chest.%^RESET%^",TP);
   myenchant = (int)swapobj->query_property("enchantment");
   swapobj->remove();
   if(mytype == "robe") swapobj = new(OBJ"robe");
   else swapobj = new(OBJ"coat");
   while((int)swapobj->query_property("enchantment") != myenchant) {
     swapobj->remove_property("enchantment");
     swapobj->set_property("enchantment",myenchant);
   }
   swapobj->set_max_internal_encumbrance(mycarry);
   swapobj->move(TO);
   return 1;
}

int is_temple() { return 1; } // to prevent blessings of other gods here.

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

int search_room(string str) {
   if (!str) return 0;
   if (str == "walls") {
     tell_object(TP,"%^BOLD%^%^WHITE%^A closer inspection of the smooth walls reveals a faint outline scored into "
"the wood, roughly the size of a doorway.%^RESET%^\n");
     return 1;
   }
   return 0;
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
   mainroom = find_object_or_load(ROOMS"tree");
   mainroom->set_open("inner door",1);
   mainroom->set_invis_exits(({}));
   tell_room(mainroom,"You notice the inner door suddenly open from the other side.");
   return 1;
}

int CloseDoor(string str) {
   object mainroom;
   ::CloseDoor(str);
   if(str == "inner door") {
     set_invis_exits(({"down"}));
     mainroom = find_object_or_load(ROOMS"tree");
     mainroom->set_invis_exits(({"up"}));
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