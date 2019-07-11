#include <std.h>
inherit "/std/temple";

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(0);
   set_temple("shaundakul");
   set_smell("default","The crisp scents of the forest is carried in on the winds.");
   set_listen("default","The wind whistles through the stone pillars.");
   set_short("%^MAGENTA%^Temple of Shaundakul%^RESET%^");
   set_long("%^MAGENTA%^The Temple of Shaundakul\n%^RESET%^"+
      "%^BOLD%^%^WHITE%^Nestled in a small grove lays the ancient open air temple of"+
      " %^RESET%^%^MAGENTA%^Shaundakul%^BOLD%^%^WHITE%^.  Surrounded by a ring of dense"+
      " trees, the grassy hill that makes up the temple rises upwards to the sky.  "+
      "On top of the hill a weathered and ancient %^BOLD%^%^BLACK%^granite throne"+
      "%^BOLD%^%^WHITE%^ rests.  The high back massive throne has been carved with an"+
      " intricate wind like %^RESET%^%^CYAN%^r%^MAGENTA%^i%^BOLD%^%^BLACK%^p%^RESET%^"+
      "%^CYAN%^p%^MAGENTA%^l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^s%^RESET%^%^BOLD%^%^WHITE%^"+
      " that radiates outwards from an image of an upright left hand.  Before the "+
      "throne a %^RESET%^weathered%^BOLD%^%^WHITE%^ dais has been constructed out of "+
      "granite slabs.  Carved deep into the stone is the charge of Shaundakul for all "+
      "to read.  Three pillars of %^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^"+
      "n%^RESET%^e%^BOLD%^%^WHITE%^ rise upwards to the sky.  Each pillar is pierced with"+
      " holes which allows the wind to whistle through.%^RESET%^"
   );
   set_exits(([
      "out":"/d/shadow/room/kildare/rooms/roads/eroad06"
   ]));
   set_items(([
     "dais":"%^CYAN%^The weathered dais is flecked with moss.  Carved "+
		"into the surface of the slab is the charge of Shaundakul.%^RESET%^",
      "charge":"%^MAGENTA%^Maybe you should read it.%^RESET%^",
      "throne":"%^RESET%^The tall and ancient throne is common for each "+
		"shrine or temple devoted to Shaundakul.  The throne is built "+
		"at each temple so that as Shaundakul travels the lands he will"+
		" always find a seat to rest on.  The faithful typically cover the"+
		" seat of the throne with offerings to The Helping Hand.%^RESET%^",
	"pillars":"%^BOLD%^%^BLACK%^Three weather beaten pillars rise up to the sky."+
		"  Each pillar is pierced with numerous holes from various angles to "+
		"allow the wind to freely blow through creating a variety of whistles.",
	"trees":"%^GREEN%^A dense forest surrounds three quarters of the temple, "+
		"giving it a feeling of privacy.  At one time it looks as if the temple"+
		" might have been more accessible to travelers.",
   ]));
}

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
