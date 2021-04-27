//shry_fairy.c - Sprite for Shrydelhi's dining room.  Coded by Circe 9/13/03
#include <std.h>
#include "/d/player_houses/shrydelhi/shry.h"
inherit NPC;

void create()
{
   ::create();
   set_name("sprite");
   set_id(({"sprite","fairy","faerie","barkeep","fae","monster"}));
   set_short("A winged sprite");
   set_long(
      "%^RESET%^%^CYAN%^A delicate little creature flits about behind the "+
      "bar, with a child like face and wide, innocent "+
      "%^BLUE%^b%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^u%^BLUE%^e %^RESET%^%^CYAN%^eyes. "+
      "Her long %^RESET%^silver hair %^RESET%^%^CYAN%^flows to her mid-back, and "+
      "her tiny figure is concealed behind a %^RESET%^silver garment "+
      "%^RESET%^%^CYAN%^that flows down about her tiny feet.  Her delicate wings "+
      "have small %^BOLD%^%^CYAN%^blue veining %^RESET%^%^CYAN%^running through "+
      "them, and they seem to never stop fluttering."
      );
   set_gender("female");
   set_race("sprite");
   set_body_type("kender");
   set_hd(10,4);
   set_max_level(20);
   set_size(1);
   set_alignment(4);
   set_overall_ac(6);
   set_max_hp(random(50)+50);
   set_hp(query_max_hp());
   set_class("fighter");
   set_mlevel("fighter",10);
   set_level(15);
   set_stats("intelligence",16);
   set_stats("dexterity",20);
   set_exp(1500);
   set_wielding_limbs(({"left hand","right hand"}));
}   
