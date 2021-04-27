#include <std.h>
inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("cultist");
   set_id(({"cult mage","cultist","magess","mage"}));
   set_short("Cult magess");
   set_long("This cultist is a tall, elegant woman with dark russet hair and "
"emerald eyes. She looks only young, with smooth pale skin and particularly "
"attractive features. She is garbed in long flowing robes, while a pointed "
"wizard's hat sits atop her head.");
   set_race("human");
   set_gender("female");
   set_hd(14,6);
   set_class("mage");
   set_mlevel("mage",14);
   set_guild_level("mage",14);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(460);
   set_hp(460);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no bows",1);
   set_size(2);
   set("aggressive",30);
   set_exp(300);
   set_stats("strength",14);
   set_stats("intelligence",18);
   set_stats("constitution",13);
   set_stats("wisdom",16);
   set_stats("dexterity",15);
   set_stats("charisma",20);
   ob = new("/d/common/obj/rand/randrobe");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   ob = new("/d/deku/sanctuary/obj/wizardhat");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   force_me("wearall");
   force_me("wear hat");
   set_spells(({
      "lightning orb",
      "scorcher",
      "prismatic spray",
      "hideous laughter"
   }));
   set_spell_chance(70);
   set_max_level(23);
   set_property("knock unconscious",1);
}
