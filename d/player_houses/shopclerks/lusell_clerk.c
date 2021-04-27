#include <std.h>
#include "/d/player_houses/defines.h"

#define MAX_ITEMS 8
#define LUSELLH "/d/player_houses/lusell/rooms/"
inherit "/std/vendor_pstore";

void create() {
  object ob;
  ::create();
   set_id(({"ceruta","ceruta sol", "lady","woman","clerk"}));
   set_name("Ceruta Sol");
   set_short("Ceruta Sol, a lady draped with a red robe");
   set_long("%^BOLD%^%^WHITE%^This lady sits behind the counter and tends to the shop.  While she doesn't appear old, her skin is leathery and her hands are gnarled and bony.  She is wearing a %^RED%^bright red%^BOLD%^%^WHITE%^ robe with a flame embroidered on the front.  She is barefooted and her feet dirty and grimy.  She reaches into her pockets now and again, pulling out receipts and cloth bits to place them on the counter.");
   set_hd(18,2);
   set("aggressive", 0);
   set_gender("female");
   set_alignment(3);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_overall_ac(0);
   set_stats("strength",15);
   set_stats("dexterity",13);
   set_stats("wisdom",19);
   set_stats("intelligence",18);
   set_stats("constitution",15);
   set_stats("charisma",18);
   set_max_hp(150+random(21));
   set_hp(query_max_hp());
   set_exp(query_max_hp() * 10);
   set_shop(LUSELLH+"shop");
   new(PHOBJ+"lusell_shop_key")->move(TO);
   command("wear ring");
   ob = new("/d/common/obj/armour/robe");
     ob->set_short("%^RED%^A bright red robe%^RESET%^");
     ob->set_long("%^RED%^This robe is made from a bright red cloth.  It was sewn several layers thick by an obviously experience tailor and is kept remarkably clean.  An image of an intense and out of control flame has been embroidered onto the front of it in a contrasting %^YELLOW%^dull yellow%^RESET%^%^RED%^ thread.%^RESET%^");
     ob->move(TO);
   command("wear robe");
}
