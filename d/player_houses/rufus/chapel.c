// A Chapel of Kelemvor
// Thorn@ShadowGate
// 001205
// Rufus' Player House
// chapel.c

#include <std.h>

inherit "/std/temple";

void create(){
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_light(1);
  set_indoors(1);
  set_temple("kelemvor");
  set_smell("default", "Damp stone and burning torches are the only smells in here.");
  set_listen("default", "It is very still.");
  set_short("A Chapel");
  set_long("%^BOLD%^%^BLACK%^The walls in this room are cold stone and are "+
  "lit only by the dim, flickering light of "+ 
  "%^RESET%^%^RED%^t%^BOLD%^o%^RESET%^%^RED%^r%^ORANGE%^ch%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^. "+ 
  "On the east wall hangs a square black banner with the sign of a "+ 
  "%^WHITE%^b%^RESET%^o%^BOLD%^ne ha%^RESET%^n%^BOLD%^d %^BLACK%^holding "+ 
  "a %^WHITE%^sc%^RESET%^a%^BOLD%^le %^BLACK%^embroidered in "+ 
  "%^WHITE%^s%^RESET%^ilve%^BOLD%^r t%^RESET%^hrea%^BOLD%^d%^BLACK%^. "+ 
  "Right below the wall hanging is a %^RESET%^%^ORANGE%^wooden rail "+ 
  "%^BOLD%^%^BLACK%^with a black kneeling cushion. In the center of the "+ 
  "room is a stone lectern facing the banner. The banner supports a large "+ 
  "%^MAGENTA%^book %^BLACK%^and an %^RESET%^%^MAGENTA%^ankh %^BOLD%^%^BLACK%^is "+ 
  "carved into it on all four sides of the supporting pillar.\n\nLooking up, "+ 
  "you see %^RESET%^large letters %^BOLD%^%^BLACK%^carved into the walls "+ 
  "that ring the ceiling. Strangely, you find that you can read these letters, "+ 
  "even if you are illiterate. At first glance, it appears to be a message. "+ 
  "You can probably read the message.\n%^RESET%^");
  set_exits(([
      "west" : "/d/player_houses/rufus/hall",
  ]));
  set_items(([
    "wall" : "You see Kelemvor's charge to his followers on the wall.",
    "message" : "Maybe you should read it.",
  ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "message") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^SO SPEAKS THE LORD OF DEATH.  THE WISE ONE WILL HARKEN TO THESE
WORDS!
%^BLACK%^
Death is but part of life; fear it not, evade it not, and view it 
not as evil. To fear death delivers you into the hands of those who 
can bring death down upon you. Die with dignity, neither raging nor 
seeking to embrace undeath. Do honor to the dead, for their strivings 
in life brought the realm to where it is now, and to forget them is 
to forget also where we are now - and why.
CHARGE
   );
   if((string)TP->query_diety() == "kelemvor")
   write(
@EXTRA
%^BOLD%^BLACK%^===%^GREEN%^o0o%^BLACK%^^BLACK%^===%^GREEN%^o0o%^BLACK%^^BLACK%^===%^GREEN%^o0o%^BLACK%^^BLACK%^===%^GREEN%^o0o%^BLACK%^======%^RESET%^
%^YELLOW%^allied deities are: %^RESET%^Mystra
%^RED%^  enemy deities are: %^RESET%^Cyric
%^BOLD%^BLACK%^===%^GREEN%^o0o%^BLACK%^^BLACK%^===%^GREEN%^o0o%^BLACK%^^BLACK%^===%^GREEN%^o0o%^BLACK%^^BLACK%^===%^GREEN%^o0o%^BLACK%^======%^RESET%^
EXTRA
   );
   return 1;
}


