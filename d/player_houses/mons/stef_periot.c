//stef_periot.c - Halfling butler for Stefano's house.  Coded by Circe 9/27/03
#include <std.h>
#include "/d/player_houses/stefano/stefano.h"
inherit MONSTER;

void create(){
   ::create();
   set_name("periot");
   set_id(({"periot","halfling butler","periot the halfling butler","butler"}));
   set_short("Periot, the halfling butler");
   set_long("Periot is a svelte, dapper halfling, dressed elegantly in "+
      "%^BOLD%^%^BLACK%^black formal attire%^RESET%^%^CYAN%^. His trousers "+
      "are sharply pressed and his jacket has long tails cut at the back. His "+
      "face is earnest and attentive, and his demeanour radiates an unflappable "+
      "calm.  His %^ORANGE%^brown eyes%^RESET%^%^CYAN%^ look into the middle "+
      "distance, taking everything in without appearing to be looking at anything "+
      "in particular. He is clean shaven, and his %^ORANGE%^short brown hair"+
      "%^RESET%^%^CYAN%^ is impeccably brushed and combed. He carries a "+
      "%^BOLD%^%^WHITE%^white towel%^RESET%^%^CYAN%^ over one forearm, and "+
      "stands next to the bar, ready to serve drinks if required.  To see what "+
      "drinks he has available, simply ask him."
   );
   set_gender("male");
   set_race("halfling");
   set_hd(15,5);
   set_alignment(3);
   set_size(1);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-6);
   set_class("fighter");
   set_mlevel("fighter",15);
   set_level(15);
   set_stats("wisdom",12);
   set_stats("strength",12);
   set_stats("constitution",12);
   set_stats("intelligence",14);
   set_stats("charisma",14);
   set_stats("dexterity",18);
   set_exp(1000);
   set("aggressive",0);
}
