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
   set_name("Slender wooden bridge");
   set_short("%^ORANGE%^Slender wooden bridge%^RESET%^");
   set_smell("default","The sharp, crisp scent of the forest fills the air.");
   set_listen("default","You can hear the quiet rustle of wind through the trees.");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
     ({"walkway","bridge"}) : (:TO,"bridge_desc":),
     ({"branches","leaves"}) : (:TO,"leaves_desc":),
     ({"lights","faerie lights"}) : (:TO,"lights_desc":),
     ({"ground","forest floor"}) : "%^GREEN%^The forest floor is so far below that you can't even see it "
"from up here!%^RESET%^",
   ]));
   set_exits(([
     "house" : ROOMS+"house2",
     "plateau" : ROOMS+"plateau"
   ]));
}

string leaves_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^Sturdy, %^WHITE%^snow-coated%^GREEN%^ branches from nearby trees surround and "
"shelter the walkway on all sides, with a few glimpses of the sky between the leaves.%^RESET%^");
   }
   return("%^GREEN%^Strong, sturdy branches from nearby trees surround and shelter the walkway on all "
"sides, with a few glimpses of the sky between the leaves.%^RESET%^");
}

string bridge_desc() {
   if (season(time()) == "winter" && (string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^This slender %^ORANGE%^wooden bridge%^GREEN%^ is perhaps two feet wide, with no "
"railings on either side.  Only small, %^WHITE%^%^BOLD%^sparkling%^RESET%^%^GREEN%^ faerie lights along "
"its edges show the walkway up from the %^BLACK%^%^BOLD%^darkness%^RESET%^%^GREEN%^ around it.  A light "
"coating of %^WHITE%^snow%^GREEN%^ rests upon the walkway itself, and covers the branches nearby.  The "
"bridge extends from between the trees and surrounding branches to a %^WHITE%^snow-covered%^GREEN%^ "
"plateau%^RESET%^%^GREEN%^ at the top of the nearby mountainside.%^RESET%^");
   }
   if (season(time()) == "winter") {
     return("%^GREEN%^This slender %^ORANGE%^wooden bridge%^GREEN%^ is perhaps two feet wide, with no "
"railings on either side.  A light coating of %^WHITE%^snow%^GREEN%^ rests upon the walkway itself, and "
"covers the branches nearby.  The bridge extends from between the trees and surrounding branches to a "
"%^WHITE%^snow-covered plateau%^GREEN%^ at the top of the nearby mountainside.%^RESET%^");
   }
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^This slender %^ORANGE%^wooden bridge%^GREEN%^ is perhaps two feet wide, with no "
"railings on either side.  Only small, %^WHITE%^%^BOLD%^sparkling%^RESET%^%^GREEN%^ faerie lights along "
"its edges show the walkway up from the %^BLACK%^%^BOLD%^darkness%^RESET%^%^GREEN%^ around it.  It "
"extends from between the trees and surrounding branches to a %^BOLD%^grassy plateau%^RESET%^%^GREEN%^ at "
"the top of the nearby mountainside.%^RESET%^");
   }
   return("%^GREEN%^This slender %^ORANGE%^wooden bridge%^GREEN%^ is perhaps two feet wide, with no "
"railings on either side.  It extends from between the trees and surrounding branches to a %^BOLD%^grassy "
"plateau%^RESET%^%^GREEN%^ at the top of the nearby mountainside.%^RESET%^");
}

string lights_desc() {
   if((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^GREEN%^Small %^WHITE%^%^BOLD%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^YELLOW%^i%^WHITE%^ng "
"lig%^RESET%^%^WHITE%^h%^BOLD%^ts%^RESET%^%^GREEN%^ line the edges of the walkway, giving it visibility "
"in the %^BLACK%^%^BOLD%^darkness%^RESET%^%^GREEN%^ of the night.%^RESET%^");
   }
   return("You do not notice that here.");
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^From the enclosed archway opens this %^ORANGE%^wooden walkway%^GREEN%^, stretching "
"in a span easily a few hundred feet above the ground, in the forest's upper canopy.  It has no railings "
"on either side, making a walk along it seem more than a little precarious.  Branches from the trees "
"nearby surrounded the walkway on all sides, only clearing to %^CYAN%^%^BOLD%^ope%^WHITE%^n "
"s%^CYAN%^ky%^RESET%^%^GREEN%^ near the far end of the bridge, where it reaches a %^BOLD%^grassy "
"plateau%^RESET%^%^GREEN%^ at the top of the mountainside.%^RESET%^\n");
   }
   return("%^GREEN%^From the enclosed archway opens this %^ORANGE%^wooden walkway%^GREEN%^, stretching "
"in a span easily a few hundred feet above the ground, in the forest's upper canopy.  It has no railings "
"on either side, making a walk along it seem more than a little precarious.  Branches from the trees "
"nearby surrounded the walkway on all sides, only clearing to %^CYAN%^%^BOLD%^ope%^WHITE%^n "
"s%^CYAN%^ky%^RESET%^%^GREEN%^ near the far end of the bridge, where it reaches a %^BOLD%^grassy "
"plateau%^RESET%^%^GREEN%^ at the top of the mountainside.%^RESET%^\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^From the enclosed archway opens this %^ORANGE%^wooden walkway%^GREEN%^, stretching "
"in a span easily a few hundred feet above the ground, in the forest's upper canopy.  Small, "
"%^WHITE%^%^BOLD%^bright%^RESET%^%^GREEN%^ faerie lights line the edges of the walkway, but it has no "
"railings on either side, making a walk along it seem more than a little precarious.  Branches from the "
"trees nearby surrounded the walkway on all sides, only clearing to show the "
"%^WHITE%^st%^BOLD%^a%^RESET%^%^WHITE%^r-sp%^BOLD%^e%^RESET%^%^WHITE%^ckled %^BLACK%^%^BOLD%^night "
"sky%^RESET%^%^GREEN%^ near the far end of the bridge, where it reaches a %^BOLD%^grassy "
"plateau%^RESET%^%^GREEN%^ at the top of the mountainside.%^RESET%^\n");
   }
   return("%^GREEN%^From the enclosed archway opens this %^ORANGE%^wooden walkway%^GREEN%^, stretching in "
"a span easily a few hundred feet above the ground, in the forest's upper canopy.  Small, "
"%^WHITE%^%^BOLD%^bright%^RESET%^%^GREEN%^ faerie lights line the edges of the walkway, but it has no "
"railings on either side, making a walk along it seem more than a little precarious.  Branches from the "
"trees nearby surrounded the walkway on all sides, only clearing to show the "
"%^WHITE%^st%^BOLD%^a%^RESET%^%^WHITE%^r-sp%^BOLD%^e%^RESET%^%^WHITE%^ckled %^BLACK%^%^BOLD%^night "
"sky%^RESET%^%^GREEN%^ near the far end of the bridge, where it reaches a %^BOLD%^grassy "
"plateau%^RESET%^%^GREEN%^ at the top of the mountainside.%^RESET%^\n");
}
