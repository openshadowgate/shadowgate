#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("apprentice");
   set_id(({"apprentice","mage","mage apprentice","cultist"}));
   set_short("Mage apprentice");
   set_long("This young male seems relatively inexperienced, though his eyes glow with a fervor "
"of loyalty to the cultists' cause. He appears only young, perhaps in his early to mid twenties. "
"He wears simple robes and no expensive ornamentations of note.");
   set_race("human");
   set_gender("male");
   set_hd(10,6);
   set_class("mage");
   set_guild_level("mage",10);
   set_alignment(3);
   set_max_hp(189);
   set_hp(189);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_size(2);
   set("aggressive",30);
   set_exp(150);
   set_stats("strength",15);
   set_stats("intelligence",16);
   set_stats("constitution",14);
   set_stats("wisdom",12);
   set_stats("dexterity",13);
   set_stats("charisma",11);
   set_spells(({
      "fireball",
      "lightning bolt",
      "cone of cold",
      "scorcher",
   }));
   set_spell_chance(40);
   set_max_level(23);
   set_property("knock unconscious",1);
}
