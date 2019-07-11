#include <std.h>

inherit "/std/temple";

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("oghma");
   set_smell("default","The smell of wet ink is heavy in the air.");
   set_listen("default","Among the various discussions you can hear a variety of different melodies being played.");
   set_short("Temple of Oghma");
   set_long(
"%^YELLOW%^The Temple of Oghma%^RESET%^\n"+
"%^BOLD%^%^WHITE%^Much like his followers, the %^BOLD%^%^BLACK%^Lord of Knowledge's "+
"%^BOLD%^%^WHITE%^temple fills a need for a variety of people. This "+
"%^RESET%^grey%^BOLD%^%^WHITE%^ stone temple houses a well stocked library "+
"filled with the knowledge of the ages. Sages come here to "+
"read more from the wealth of information house here, "+
"while scribes work hard to copy the texts. Entertainers mull about "+
"the temple playing a variety of songs and melodies for all within "+
"this large structure, for Oghma is also the %^RESET%^%^MAGENTA%^Patron of Bards, "+
"the God of song, music and performance%^BOLD%^%^WHITE%^. With such an eclectic "+
"mix of followers the temple still retains a harmonious balance.  "+
"Tapestries devoted to each side of Oghma hang over the walls, each well "+
"crafted and very elaborate. A %^YELLOW%^gold velvet%^BOLD%^%^WHITE%^ rug leads "+
"to the %^BOLD%^%^CYAN%^crystal altar%^BOLD%^%^WHITE%^ of the Binder as violet "+
"drapes flank it.\n"+
"Written on a %^RESET%^parchment scroll%^BOLD%^%^WHITE%^ in the "+
"most elegant penmanship you have seen is the charge of Oghma. "+
"The scroll even features some very detailed illuminations.\n"
   );
   set_exits(([
      "out" : "/d/darkwood/tabor/room/math4",
   ]));
   set_items(([
      ({"altar","scroll"}) : "The charge of Oghma is written on the scroll.",
      "charge":"Maybe you should read it.",
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
"%^BOLD%^Oghma charges his followers with this message:%^RESET%^\n\n"+
"%^YELLOW%^"+
"Knowledge, particularly the raw knowledge of ideas, "+
"is supreme. An idea has no weight, but it can move "+
"mountains. The greatest gift of humankind, an idea "+
"outweighs anything made by mortal hands. Knowledge "+
"is power and must be used with care, but hiding it "+
"away from others is never a good thing. Stifle no "+
"new ideas, no matter how false or crazed they seem, "+
"rather, let them be heard and considered.  Never slay "+
"a singer, nor stand by as others do so. Spread knowledge "+
"wherever it is prudent to do so. Curb and deny falsehoods, "+
"rumors, and deceitful tales whenever you encounter them. "+
"Write or copy lore of great value at least once a year "+
"and give it away. Sponsor and teach bards, scribes and "+
"record keepers. Spread truth and knowledge so that all "+
"folk know more. Never deliver a message falsely or "+
"incompletely. Teach reading and writing to those who "+
"ask, if time permits, and charge no fee."+
"   Above all else, let knowledge flow, let the songs sing out, and you"+
" will know the Binder."
   );
   if((string)TP->query_diety() == "oghma" || avatarp(TP))
   write(
@EXTRA
============================================================================
%^BOLD%^As a follower of Oghma ...
%^RED%^  Allied deities are: %^RESET%^Mystra, Lathander, Sune, Auppenser, Grumbar
%^RED%^  enemy deities are: %^RESET%^Mask, Bane, Cyric, Talos, Malar

%^BOLD%^This is information only followers of Oghma should know.
EXTRA
   );
   return 1;
}
