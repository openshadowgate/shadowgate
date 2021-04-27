#include <std.h>
inherit WEAPONLESS;

void create(){
  ::create();
  set_id(({"rabbit","bunny","fluffy rabbit","fluffy white rabbit","white rabbit"}));
  set_name("rabbit");
  set_short("%^BOLD%^%^WHITE%^A little fluffy white rabbit%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^This adorable albino bunny has %^RESET%^soft, fluffy white fur %^BOLD%^%^WHITE%^coating "
"its plump little body. Long floppy ears regularly threaten to obscure its %^MAGENTA%^deep pink eyes%^WHITE%^, below "
"which its little whiskered %^RESET%^%^MAGENTA%^nose %^BOLD%^%^WHITE%^constantly twitches. Its paws seem overly "
"%^RESET%^%^CYAN%^large %^BOLD%^%^WHITE%^for a creature of its size, yet it doesn't seem bothered by them. The little "
"fluffy tail behind it completes the cute creature, constantly %^RESET%^%^ORANGE%^bobbing %^BOLD%^%^WHITE%^as it moves "
"around.%^RESET%^");
  set_race("rabbit");
  set_body_type("quadruped");
  set_max_hp(40);
  set_hd(8,10);
  set_size(1);
  TO->force_me("message in hops in, its nose twitching.");
  TO->force_me("message out hops $D with its fluffy tail bobbing behind it.");
  set_attack_limbs(({"right hindleg","left hindleg","teeth"}));
  set_base_damage_type("piercing");
  set_attacks_num(1);
  set_damage(1,4);
  set_stats("strength",12);
  set_stats("dexterity",18);
  set_overall_ac(-2);
  set_property("knock unconscious",1);
}

void init() {
  ::init();
  add_action("lead_animal","lead");
  add_action("ditch_animal","unlead");
}

int lead_animal(string str) {
  if (TP->query_bound() || TP->query_unconscious() || TP->query_tripped()) {
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if (!str) return notify_fail("Lead what?\n");
  if (TO == present(str, ETP)) {
     notify_fail("");
     if ((string)TP->query_name() != "timothy") {
        write("The little bunny isn't yours to lead.");
        return 0;
     }
    TP->add_follower(TO);
    tell_object(TP,"The bunny is now following you.");
    tell_room(ETP, "The little bunny begins hopping along behind "+TPQCN+".", TP);
    return 1;
  }
  if(!present(str,ETP)) 
        return notify_fail("There is no "+str+" here.\n");
}

int ditch_animal(string str) {
  if (!str || !id(str)) return 0;
  if (member_array(TO,TP->query_followers()) == -1) 
     return notify_fail(QCN+" is not following you now.\n");
  TP->remove_follower(TO);
  tell_object(TP,"The bunny will no longer follow you.");
  tell_room(ETP,"The bunny seems to get bored of following "+TPQCN+" and begins sniffing around.", TP);
  return 1;
}
