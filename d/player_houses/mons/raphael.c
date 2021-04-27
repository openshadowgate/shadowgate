//raphael.c - The footman for Stefano's cottage.  Coded by Circe 9/27/03
#include <std.h>
#include "/d/player_houses/stefano/stefano.h"
inherit MONSTER;

void create(){
   ::create();
   set_name("raphael");
   set_id(({"raphael","raphael the footman","footman","guard"}));
   set_short("Raphael the footman");
   set_long("Raphael is a well-groomed male human dressed in smart "+
      "%^BOLD%^%^BLACK%^black hose%^RESET%^%^CYAN%^ and a %^BLUE%^dark blue jacket"+
      "%^RESET%^%^CYAN%^ and waistcoat.  His fashionable shoes are polished to a "+
      "fine sheen, and the brass buttons of hie waistcoat gleam.  He is clean shaven "+
      "and quite presentable, if not handsome. His dark hair is cropped short and "+
      "kept tidy. His eyes are blue, and his normal expression is calm and ordered.  "+
      "He hovers attentively by the door, ready to carry out instructions.");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(15,5);
   set_alignment(3);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-6);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_level(15);
   set_stats("wisdom",12);
   set_stats("strength",16);
   set_stats("constitution",16);
   set_stats("intelligence",18);
   set_stats("charisma",14);
   set_stats("dexterity",12);
   set_exp(1000);
   set("aggressive",0);
}
