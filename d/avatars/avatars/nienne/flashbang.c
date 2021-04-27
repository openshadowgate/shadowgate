#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create() {
   ::create();
   set_name("%^YELLOW%^flashbang%^RESET%^");
   set_id(({"gnomish flashbang","flashbang","sphere","mechanical sphere","small sphere","small mechanical sphere"}));
   set_short("%^YELLOW%^Gnomish Flashbang%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^small mechanical sphere%^RESET%^");
   set_long("%^YELLOW%^This odd little mechanical device is smooth and spherical, about the size of a large "
"egg.  It is made of a strange sort of metal like none you've ever seen, with a swirling pattern of %^RESET%^"
"%^WHITE%^pale%^YELLOW%^ and %^BLACK%^dark %^YELLOW%^over its surface.  It's uncharacteristically heavy for "
"its size, and rattles a little when moved.  At six opposite points around its surface are small, flat metal "
"buttons that are particularly hard to depress - it would probably take quite a force to push them in.%^RESET%^");
   set_weight(1);
}

void init() {
   ::init();
   add_action("toss_fun","toss");
}

void flash_fun(object ob2 ,int att2, int dam2) {
   if(!objectp(ob2)) return;
   ob2->add_attack_bonus(att2);
   ob2->add_damage_bonus(dam2);
}

int toss_fun(string str) {
   object *inven,ob;
   int i,att,dam;
   if(!str || str != "sphere") return notify_fail("Toss what?\n");
   if (TP->query_bound() || TP->query_unconscious()) {
     TP->send_paralyzed_message("info",TP);
     return 1;
   }
   if(TP->query_paralyzed()) return notify_fail(TP->query_paralyze_message()+"\n");
   inven = all_living(ETP);
   tell_object(TP,"%^WHITE%^%^BOLD%^You throw the sphere forcefully at the ground before you, and turn away "
"just before it %^YELLOW%^explodes %^WHITE%^in a blinding flash of light!");
   tell_room(ETP,"WHITE%^%^BOLD%^"+TPQCN+" throws a small sphere forcefully at the ground, and turns away just "
"as it %^YELLOW%^explodes %^WHITE%^in a blinding flash of light!%^RESET%^",TP);

   for(i=0;i<sizeof(inven);i++) {
     ob = inven[i];
     if(!ob->query_true_invis() && ob != TP) {
       ob->set_temporary_blinded(random(6)+6);
       att = random(4)+4;
       dam = random(4)+2;
       ob->add_attack_bonus(-att);
       ob->add_damage_bonus(-dam);
       call_out("flash_fun",20,ob,att,dam);
     }
   }
   TO->move("/realms/nienne/oldworkroom");
   return 1;
}
