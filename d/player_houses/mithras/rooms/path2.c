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
    set_name("Deep within the forest");
    set_short("%^RESET%^%^ORANGE%^Deep within the f%^GREEN%^o%^ORANGE%^rest%^RESET%^");
    set_long((:TO,"long_desc":));
    set("night long",(:TO,"night_desc":));
    set_smell("default","%^RESET%^%^ORANGE%^The air is %^CYAN%^cl%^GREEN%^ea%^CYAN%^n %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^c%^CYAN%^r%^WHITE%^isp%^RESET%^%^ORANGE%^.%^RESET%^");
    set_listen("default","%^RESET%^%^GREEN%^Silence holds here, save for the whisper of the %^CYAN%^w%^BOLD%^i%^BLUE%^n%^RESET%^%^CYAN%^d %^GREEN%^through the trees.%^RESET%^");

    set_items(([
      ({"forest","trees","vines","branches","foliage"}) : (:TO,"forest_desc":),
      ({"ground","shrubs","path"}) : (:TO,"ground_desc":),
      "shadows" : (:TO,"shadows_desc":),
      "snow" : (:TO,"snow_desc":),
    ]));
    set_search("trees","You take a moment, searching out a path through the trees.  You think perhaps you could continue on to the northeast.");
    set_search("forest","You take a moment, searching out a path through the trees.  You think perhaps you could continue on to the northeast.");
    set_exits(([
      "west" : ROOMS"path1",
      "northeast" : ROOMS"path3",
    ]));
    set_invis_exits(({"northeast"}));
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^RESET%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^RESET%^, with ancient trees looming up on all sides.  Their branches "
"entangle overhead, supporting %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w-l%^RESET%^ad%^BOLD%^%^WHITE%^en %^RESET%^foliage and tangled vines so densely grown that they block out the sky "
"save for an occasional %^BOLD%^%^CYAN%^gl%^RESET%^%^CYAN%^i%^BOLD%^m%^WHITE%^p%^RESET%^s%^BOLD%^%^CYAN%^e %^RESET%^here and there.  A layer of shrubs and fallen branches lie partly buried "
"beneath a blanket of %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^WHITE%^ow%^RESET%^, though with some careful consideration you can pick your way among them.  There seems no true %^ORANGE%^p%^RESET%^"
"a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^or passage here, making it difficult at times to travel or even discern directions, save from where you've just stepped.\n");
   }
   if (season(time()) == "autumn") {
     return("%^RESET%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^RESET%^, with ancient trees looming up on all sides.  Their branches "
"entangle overhead, supporting %^ORANGE%^f%^RED%^l%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^RESET%^foliage and tangled vines so densely "
"grown that they block out the sky save for an occasional %^BOLD%^%^CYAN%^gl%^RESET%^%^CYAN%^i%^BOLD%^m%^WHITE%^p%^RESET%^s%^BOLD%^%^CYAN%^e %^RESET%^here and there.  A layer of shrubs and "
"fallen branches clutter the ground, though with some careful consideration you can pick your way among them, dead leaves %^ORANGE%^c%^RED%^r%^BOLD%^a%^RESET%^%^ORANGE%^c%^RED%^k%^ORANGE%^l"
"%^YELLOW%^i%^WHITE%^n%^RESET%^%^ORANGE%^g %^RESET%^underfoot as you walk.  There seems no true %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^or passage here, making it "
"difficult at times to travel or even discern directions, save from where you've just stepped.\n");
   }
   return("%^RESET%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^RESET%^, with ancient trees looming up on all sides.  Their branches "
"entangle overhead, supporting %^GREEN%^v%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^d%^YELLOW%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^RESET%^foliage and tangled vines so densely grown that they "
"block out the sky save for an occasional %^BOLD%^%^CYAN%^gl%^RESET%^%^CYAN%^i%^BOLD%^m%^WHITE%^p%^RESET%^s%^BOLD%^%^CYAN%^e %^RESET%^here and there.  A layer of shrubs and fallen branches "
"clutter the ground, though with some careful consideration you can pick your way among them, dead leaves %^ORANGE%^c%^RED%^r%^BOLD%^a%^RESET%^%^ORANGE%^c%^RED%^k%^ORANGE%^l%^YELLOW%^i%^WHITE%^n"
"%^RESET%^%^ORANGE%^g %^RESET%^underfoot as you walk.  There seems no true %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^RESET%^or passage here, making it difficult at times to "
"travel or even discern directions, save from where you've just stepped.\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^RESET%^%^BLUE%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^BLUE%^, shadows dancing amidst the ancient trees that loom up "
"on all sides.  Their branches entangle overhead, supporting %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w-l%^RESET%^ad%^BOLD%^%^WHITE%^en %^RESET%^%^BLUE%^foliage and tangled vines so "
"densely grown that they block out the sky save for an occasional %^BOLD%^%^BLACK%^gl%^RESET%^i%^BOLD%^%^BLACK%^m%^RESET%^ps%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^here and there.  A layer of "
"shrubs and fallen branches lie partly buried beneath a blanket of %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^WHITE%^ow%^RESET%^%^BLUE%^, though with some careful consideration you can pick your "
"way among them.  There seems no true %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^or passage here, making it difficult at times to travel or even discern directions, "
"save from where you've just stepped.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     return("%^RESET%^%^BLUE%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^BLUE%^, shadows dancing amidst the ancient trees that loom up "
"on all sides.  Their branches entangle overhead, supporting %^ORANGE%^f%^RED%^l%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^BLUE%^foliage "
"and tangled vines so densely grown that they block out the sky save for an occasional %^BOLD%^%^BLACK%^gl%^RESET%^i%^BOLD%^%^BLACK%^m%^RESET%^ps%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^here and "
"there.  A layer of shrubs and fallen branches clutter the ground, though with some careful consideration you can pick your way among them, dead leaves %^ORANGE%^c%^RED%^r%^BOLD%^a%^RESET%^"
"%^ORANGE%^c%^RED%^k%^ORANGE%^l%^YELLOW%^i%^WHITE%^n%^RESET%^%^ORANGE%^g %^BLUE%^underfoot as you walk.  There seems no true %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^"
"or passage here, making it difficult at times to travel or even discern directions, save from where you've just stepped.%^RESET%^\n");
   }
   if (season(time()) == "summer") {
     return("%^RESET%^%^BLUE%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^BLUE%^, shadows dancing amidst the ancient trees that loom up "
"on all sides.  Their branches entangle overhead, supporting %^GREEN%^v%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^d%^YELLOW%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage and tangled vines so "
"densely grown that they block out the sky save for an occasional %^BOLD%^%^BLACK%^gl%^RESET%^i%^BOLD%^%^BLACK%^m%^RESET%^ps%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^here and there.  A layer of "
"shrubs and fallen branches clutter the ground, though with some careful consideration you can pick your way among them, dead leaves %^ORANGE%^c%^RED%^r%^BOLD%^a%^RESET%^%^ORANGE%^c%^RED%^k"
"%^ORANGE%^l%^YELLOW%^i%^WHITE%^n%^RESET%^%^ORANGE%^g %^BLUE%^underfoot as you walk.  Dots of light drift through the canopy above, resolving themselves as tiny %^YELLOW%^fi%^GREEN%^r%^YELLOW%^"
"ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^BLUE%^.  There seems no true %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^or passage here, making it difficult at "
"times to travel or even discern directions, save from where you've just stepped.%^RESET%^\n");
   }
   return("%^RESET%^%^BLUE%^You stand within the middle of a thick %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^BLUE%^, shadows dancing amidst the ancient trees that loom up "
"on all sides.  Their branches entangle overhead, supporting %^GREEN%^v%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^d%^YELLOW%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage and tangled vines so "
"densely grown that they block out the sky save for an occasional %^BOLD%^%^BLACK%^gl%^RESET%^i%^BOLD%^%^BLACK%^m%^RESET%^ps%^BOLD%^%^BLACK%^e %^RESET%^%^BLUE%^here and there.  A layer of "
"shrubs and fallen branches clutter the ground, though with some careful consideration you can pick your way among them, dead leaves %^ORANGE%^c%^RED%^r%^BOLD%^a%^RESET%^%^ORANGE%^c%^RED%^k"
"%^ORANGE%^l%^YELLOW%^i%^WHITE%^n%^RESET%^%^ORANGE%^g %^BLUE%^underfoot as you walk.  There seems no true %^ORANGE%^p%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h %^BLUE%^or passage here, "
"making it difficult at times to travel or even discern directions, save from where you've just stepped.%^RESET%^\n");
}

string forest_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^BLUE%^Shadows drift amidst the ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^BLUE%^that loom up to either side of you, their enmeshed branches blocking out the dark sky "
"above.  Vines drape and tangle over their %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w-l%^RESET%^ad%^BOLD%^%^WHITE%^en %^RESET%^%^BLUE%^foliage, so densely grown that sometimes you have to "
"lift or push obstructions aside just to continue on your way.%^RESET%^");
     }
     if (season(time()) == "autumn") {
       return("%^BLUE%^Shadows drift amidst the ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^BLUE%^that loom up to either side of you, their enmeshed branches blocking out the dark sky "
"above.  Vines drape and tangle over their %^ORANGE%^f%^RED%^l%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^BLUE%^foliage, so densely grown "
"that sometimes you have to lift or push obstructions aside just to continue on your way.%^RESET%^");
     }
     if (season(time()) == "summer") {
       return("%^BLUE%^Shadows drift amidst the ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^BLUE%^that loom up to either side of you, their enmeshed branches blocking out the dark sky "
"above.  %^YELLOW%^Fi%^GREEN%^r%^YELLOW%^ef%^WHITE%^l%^YELLOW%^i%^GREEN%^e%^YELLOW%^s%^RESET%^%^BLUE%^drift and wink lazily upon grass and leaf, tiny pinpricks of light against the backdrop of "
"night.  Vines drape and tangle over their %^GREEN%^v%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^d%^YELLOW%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage, so densely grown that sometimes you "
"have to lift or push obstructions aside just to continue on your way.%^RESET%^");
     }
     return("%^BLUE%^Shadows drift amidst the ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^BLUE%^that loom up to either side of you, their enmeshed branches blocking out the dark sky "
"above.  Vines drape and tangle over their %^GREEN%^v%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^d%^YELLOW%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^BLUE%^foliage, so densely grown that sometimes you "
"have to lift or push obstructions aside just to continue on your way.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("Ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^RESET%^loom up to either side of you, their enmeshed branches blocking out the sky above.  Vines drape and tangle over their "
"%^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w-l%^RESET%^ad%^BOLD%^%^WHITE%^en %^RESET%^foliage, so densely grown that sometimes you have to lift or push obstructions aside just to continue "
"on your way.");
   }
   if (season(time()) == "autumn") {
     return("Ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^RESET%^loom up to either side of you, their enmeshed branches blocking out the sky above.  Vines drape and tangle over their "
"%^ORANGE%^f%^RED%^l%^ORANGE%^a%^BOLD%^m%^YELLOW%^e%^RESET%^%^ORANGE%^-h%^BOLD%^%^RED%^u%^RESET%^%^RED%^e%^ORANGE%^d %^RESET%^foliage, so densely grown that sometimes you have to lift or push "
"obstructions aside just to continue on your way.");
   }
   return("Ancient %^GREEN%^tre%^BOLD%^e%^RESET%^%^GREEN%^s %^RESET%^loom up to either side of you, their enmeshed branches blocking out the sky above.  Vines drape and tangle over their "
"%^GREEN%^v%^BOLD%^e%^RESET%^%^CYAN%^r%^GREEN%^d%^YELLOW%^a%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t %^RESET%^foliage, so densely grown that sometimes you have to lift or push obstructions aside "
"just to continue on your way.");
}

string ground_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     if (season(time()) == "winter") {
       return("%^BLUE%^Recently fallen branches and leaf-litter are strewn across the blanket of %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^WHITE%^ow %^RESET%^%^RESET%^%^BLUE%^that covers the "
"ground.  A few shrubs still struggle to grow up through the layer of white, leaving few gaps between the thick %^GREEN%^und%^BOLD%^e%^RESET%^%^GREEN%^rgro%^BOLD%^w%^RESET%^%^GREEN%^th%^BLUE%^ "
"to place your feet.  There are a few spots, though, that you can find to tread carefully amidst the trees and overhanging vines.%^RESET%^");
     }
     return("%^BLUE%^Branches and leaf-litter clutter the ground in the few gaps between the thick %^GREEN%^und%^BOLD%^e%^RESET%^%^GREEN%^rgro%^BOLD%^w%^RESET%^%^GREEN%^th%^BLUE%^, making "
"passage here difficult.  There are a few spots, though, that you can find to place your feet and tread carefully amidst the trees and overhanging vines.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("Recently fallen branches and leaf-litter are strewn across the blanket of %^BOLD%^%^WHITE%^s%^RESET%^n%^BOLD%^%^WHITE%^ow %^RESET%^that covers the ground.  A few shrubs still "
"struggle to grow up through the layer of white, leaving few gaps between the thick %^GREEN%^und%^BOLD%^e%^RESET%^%^GREEN%^rgro%^BOLD%^w%^RESET%^%^GREEN%^th%^RESET%^ to place your feet.  There "
"are a few spots, though, that you can find to tread carefully amidst the trees and overhanging vines.");
   }
   return("Branches and leaf-litter clutter the ground in the few gaps between the thick %^GREEN%^und%^BOLD%^e%^RESET%^%^GREEN%^rgro%^BOLD%^w%^RESET%^%^GREEN%^th%^RESET%^, making passage here "
"difficult.  There are a few spots, though, that you can find to place your feet and tread carefully amidst the trees and overhanging vines.");
}

string shadows_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return forest_desc();
   }
   return("You do not notice that here.");
}

string snow_desc() {
   if (season(time()) == "winter") {
     if ((string)EVENTS_D->query_time_of_day() == "night")
       return ("%^BLUE%^A thick layer of %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w %^RESET%^%^BLUE%^weighs down the branches around you, and lies in a thick blanket across the ground, "
"leeching the color from the %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^BLUE%^ as it buries everything in a layer of white powder.%^RESET%^");
     return ("A thick layer of %^BOLD%^%^WHITE%^sn%^RESET%^o%^BOLD%^%^WHITE%^w %^RESET%^weighs down the branches around you, and lies in a thick blanket across the ground, leeching the color "
"from the %^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^re%^ORANGE%^s%^GREEN%^t%^RESET%^ as it buries everything in a layer of white powder.");
   }
   return("You do not notice that here.");
}