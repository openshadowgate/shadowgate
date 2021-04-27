#include <std.h>
inherit MONSTER;

void create() {
   object ob;
   ::create();
   set_name("cultist");
   set_id(({"cult mage","cultist","mage","leader","cult leader"}));
   set_short("Cult leader");
   set_long("This haughty-featured man carries himself with an air of authority. His "
"dark eyes gleam with an intensity of purpose, and his long blonde hair is tied back "
"at the nape of his neck. His green velvet robes are finely trimmed with coppery "
"thread, and he carries an amulet which bears a stylised symbol of a hand holding an "
"eyeball.");
   set_race("human");
   set_gender("male");
   set_hd(20,6);
   set_class("mage");
   set_mlevel("mage",20);
   set_guild_level("mage",20);
   add_search_path("/cmds/wizard");
   set_alignment(3);
   set_max_hp(589);
   set_hp(589);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_property("no bows",1);
   set_size(2);
   set("aggressive",30);
   set_exp(300);
   set_stats("strength",12);
   set_stats("intelligence",18);
   set_stats("constitution",12);
   set_stats("wisdom",14);
   set_stats("dexterity",17);
   set_stats("charisma",17);
   ob = new("/d/deku/sanctuary/obj/serpentcoat");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   ob = new("/d/deku/sanctuary/obj/wizardhat");
   ob->move(TO);
   ob->set_property("monsterweapon", 1);
   ob = new("/d/avatars/nienne/vecna/vecnasymbol");
   ob->move(TO);
   force_me("wearall");
   force_me("wear hat");
   set_spells(({
      "powerword stun",
      "hideous laughter",
      "ray of enfeeblment",
      "hold person",
      "greater shout"
   }));
   set_spell_chance(70);
   set_max_level(23);
   set_property("knock unconscious",1);
}
