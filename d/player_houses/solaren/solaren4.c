// In the courtyard
// Thorn@ShadowGate
// 001027
// Solaren's Player House
// solaren4.c
// modified to become a mage guild tower ala Sherlock & Stefano by *Styx* 4/21/03

#include <std.h>
#include "../defines.h"

inherit VAULT;

// int locked;

void create() {
  ::create();
   set_name("Courtyard");
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
  set_property("light", 2);
  set_short("%^BOLD%^In the courtyard%^RESET%^");
  set_long(
@THORN
%^BOLD%^In the courtyard%^RESET%^
%^RESET%^%^CYAN%^You are now standing in a courtyard filled with some utility buildings and dominated by the tower in the center of the walled enclosure. The %^MAGENTA%^tower%^CYAN%^ itself rises high above the main courtyard, nearly 100 feet tall and made out of a highly polished stone that reflects the surrounding terrain, changing colors with the setting sun. About a quarter of this height is unchanged rock, shaped little by human hands, providing support and structure to the tower's great height. You can enter the tower here through a pair of great midnight blue double doors. A large %^MAGENTA%^statu%^BOLD%^%^MAGENTA%^e%^RESET%^%^CYAN%^ of a human stands in the centre of the courtyard. You may exit the courtyard through the %^MAGENTA%^g%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^te.%^RESET%^

THORN
  );
  set_smell("default", "You can vaguely smell a hint of salts of the sea on the breeze.");
  set_listen("default", "It is quiet.");
  set_items(([
    "cliffs" : "You hear but not see the ocean below the great granite cliffs nearby.",
    "tower" : "Made of a reflecting material, it rises high above the walls and seems to change colors in the sun.",
    "statue" : "The statue, made of the same material as the tower, is of a human in mage garments holding open a large tome with its right arm and gliding its left hand over the page.  The face appears full of concentration, the lips captured in a timeless murmur.  At its base is a crest.",
    "crest" : "The crest takes the form of an orb containing a scroll lying across an open spell book.  Words are clearly written around the edges but are blurred and cannot be made out.",
  ]));
  set_exits(([
      "exit" : "/d/player_houses/solaren/solaren3",
      "tower" : "/d/player_houses/solaren/solaren5",
  ]));
  set_door("gates","/d/player_houses/solaren/solaren3","exit");
  set_locked("gates",1);
  set_door_description("gates", "The gates look thin and fragile but on closer inspection they appear very strong and robust, as if from some magical force.");
  "/d/player_houses/solaren/solaren3"->set_locked("gates",1);
  set_door("double doors","/d/player_houses/solaren/solaren5","tower");
  set_door_description("double doors", "%^BLUE%^The midnight blue oak doors look solid.  The lock looks disabled.");
}

