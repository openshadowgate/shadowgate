#include <std.h>
inherit MONSTER;

int timer;

void create(){
  object ob;
  ::create();
  set_name("elfshadow");
  set_id(({"elf","shadow","shadowy silhouette","elfshadow","shadowy elven silhouette","elven silhouette"}));
  set_short("%^RESET%^%^BLUE%^shadowy elven silhouette%^RESET%^");
  set_long("%^RESET%^Before you drifts a shadow, humanoid in form and difficult to focus upon.  Enough "
"features are noticable in the slender build and pointed ears that the creature must be elven, though colors "
"and details are impossible to discern.  Obvious, however, is the razor-sharp blade in its hand and the poised "
"stance, ready to fight.");
  set_hd(35,10);
  set_max_hp(700);
  set_hp(700);
  set_race("elf");
  set_body_type("humanoid");
  set_overall_ac(-25);
  set_exp(1);
  set_property("magic",1);
  set_property("spell resistance",50);
  set_property("damage resistance",15);
  set_attacks_num(3);
  set_property("knock unconscious",1);
  ob = new("/d/common/obj/weapon/longsword");
  ob->move(TO);
  ob->set_property("enchantment",4);
  ob->set_property("monsterweapon",1);
  command("wield sword");
  setenv("MIN", "$N drifts in.");
  setenv("MOUT", "$N drifts silently $D.");
  timer = roll_dice(4,6);
}

void heart_beat() {
  ::heart_beat();
  if(!timer) TO->die();
  timer--;
}

void die(object ob) {
  if(!objectp(TO)) return;
  tell_room(ETO,"%^RESET%^%^BLUE%^The shadowy silhouette disperses into nothing!%^RESET%^");
  present("sword",TO)->remove();
  TO->remove();
}
