//berries.c - for Shrydelhi's meadow.  Coded by Circe 9/12/03
inherit "/std/food.c";

#include <std.h>
#include "/d/player_houses/shrydelhi/shry.h"

void create(){
   ::create();
  set_name("berries");
  set_id(({"berries","berry","mixed berries","food"}));
  set_strength(5);
  set_weight(1);
  set_short("%^BOLD%^%^RED%^A handful of m%^RESET%^%^RED%^ix%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^berries%^RESET%^");
  set_destroy();
  set_long("A small handful of juicy berries.  They vary in shade from deep red "+
      "to light pink to nearly black.  There are several different kinds here, including "+
      "raspberries, blackberries, and strawberries.");
   set_my_mess("The berries are juicy and delicious.");
   set_your_mess("eats a handful of berries and dribbles a little juice.");
  }
