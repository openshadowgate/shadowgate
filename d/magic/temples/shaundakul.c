//updated by ~Circe~ 7/13/19 following the god changes
#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(0);
//   set_temple("shaundakul");
   set_smell("default","The crisp scents of the forest is carried in on the winds.");
   set_listen("default","The wind whistles through the stone pillars.");
   set_short("%^MAGENTA%^An abandoned temple%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Nestled in a small grove lays an ancient open air temple in ruins.  "
      "Surrounded by a ring of dense %^GREEN%^trees%^WHITE%^, a grassy hill rises "
      "upwards to the %^CYAN%^sky%^WHITE%^.  "
      "On top of the hill, a weathered and ancient %^BOLD%^%^BLACK%^granite throne"
      "%^BOLD%^%^WHITE%^ rests.  The high back massive throne has been carved with"
      " intricate wind-like %^RESET%^%^CYAN%^r%^MAGENTA%^i%^BOLD%^%^BLACK%^p%^RESET%^"
      "%^CYAN%^p%^MAGENTA%^l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s%^RESET%^%^BOLD%^%^WHITE%^"
      " that radiate outwards from an unrecognizable image.  Before the "
      "throne is a ring of concave earth where it seems something once stood.  "
      "Three crumbling pillars of %^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^"
      "n%^RESET%^e%^BOLD%^%^WHITE%^ rise upwards to the sky.  Each pillar is pierced with"
      " holes which allows the wind to whistle through.\n%^RESET%^"
   );
   set_exits(([
      "out":"/d/shadow/room/kildare/rooms/roads/eroad06"
   ]));
   set_items(([
     ({"ring","earth","concave earth","concave ring"}) : "A slightly irregular dip in "
        "the ground indicates that something large once dominated the top of the hill, "
        "but all that reminds are slabs of granite strewn here and there.",
     "throne":"%^RESET%^The tall and ancient throne stands stoically against the sky.  "
        "Whatever purpose it might have had, those secrets have been lost to the wind.",
	"pillars":"%^BOLD%^%^BLACK%^Three weather-beaten pillars rise up to the sky."
		"  Each pillar is pierced with numerous holes from various angles to "
		"allow the wind to freely blow through, creating a variety of whistles.",
	"trees":"%^GREEN%^A dense forest surrounds three-quarters of the abandoned temple, "
		"giving it a feeling of privacy.  At one time it looks as if the temple"
		" might have been more accessible to travelers.",
   ]));
}
/*
void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^%^Shaundakul charges his followers with this message:%^RESET%^
%^MAGENTA%^
Spread the teachings of the Helping Hand by example. Work to promote
him among traders, especially trailblazers who seek out new lands and
new opportunities. Unearth and resanctify ancient shrines of Shaundakul.
Ride the wind, and let it take you wherever it blows. Aid those in need,
and trust in the Helping Hand. Seek out the riches of the earth and sea.
Journey to distant horizons. Be the first to see the rising sun, the 
mountain peaks, the lush valleys. Let your footsteps fall where none have 
tread.%^RESET%^
CHARGE
   );
   if((string)TP->query_diety() == "shaundakul" || avatarp(TP))
   write(
@EXTRA
============================================================================
%^BOLD%^As a follower of Shaundakul ...
%^RED%^  allied deities are: %^RESET%^Akadi, Tymora, Mielikki, Selune
%^RED%^  enemy deities are: %^RESET%^Beshaba, Shar, Talos

%^BOLD%^This is information only followers of Shaundakul should know.
EXTRA
   );
   return 1;
}
*/