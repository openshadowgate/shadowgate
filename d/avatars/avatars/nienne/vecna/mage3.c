#include <std.h>
inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("cultist");
   set_id(({"cult mage","cultist","mage"}));
   set_short("Cult mage");
   set_long("This relatively short man seems more mature in years. His jet-black "
"hair is close-cropped in a stern fashion that suits the grim set of his features "
"and the steely blue of his eyes. He wears flowing wizard regalia that reaches the "
"ground and carries a matching staff.");
   set_race("human");
   set_gender("male");
   set_hd(13,6);
   set_class("mage");
   set_mlevel("mage",13);
   set_guild_level("mage",13);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(348);
   set_hp(348);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no bows",1);
   set_size(2);
   set("aggressive",30);
   set_exp(170);
   set_stats("strength",14);
   set_stats("intelligence",18);
   set_stats("constitution",13);
   set_stats("wisdom",15);
   set_stats("dexterity",16);
   set_stats("charisma",17);
   ob = new("/d/common/obj/rand/randrobe");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   ob = new("/d/deku/sanctuary/obj/wizardhat");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   force_me("wearall");
   force_me("wear hat");
   set_spells(({
      "lower resistance", "magic missile", "dispel magic", "magic missile"
   }));
   set_spell_chance(100);
   set_max_level(23);
   set_property("knock unconscious",1);
}

