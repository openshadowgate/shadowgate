//Ornsul npc coded by hades 12/31/20
#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "/d/islands/elf/elf.h"
inherit MONSTER;

int  round1;

void create() {
    ::create();

    round1 = 0;
    set_hd(50, 9);
    set_id(({"ornsul","elf","wild elf","druid"}));
    set_name("Ornsul");
    set_short("Ornsul, %^RESET%^%^GREEN%^Pr%^CYAN%^o%^GREEN%^tector of the W%^CYAN%^i%^GREEN%^lds");
    set_long("Ornsul is a green elf, or what others "+
    "would call a wild elf, and is just below normal "+
    "height for his kind. He has long corded muscle "+
    "stretching beneath the darkly tanned skin of a "+
    "deceptively lean body. His eyes are dark green, "+
    "the color of foliage in the shade of a tree, and"+
    " intense as if always watching and ready to spring"+
    " into action instantly. Eyes slightly slanted, large,"+
    " and almond shaped grace his darkly tanned face and "+
    "with his long, sharply pointed, ears put an end to any"+
    " argument that he is elf. High cheek bones and "+
    "features that are angular and sharp adds to the look of"+
    " alertness in his posture. Long black hair tumbles past "+
    "his shoulders and is braided, about as wide as a finger,"+
    " in front of both ears. Within both braids bits of bone "+
    "and wooden beads are blended and three crow flight "+
    "feathers have been woven tightly to the hair on the"+
    " back of his head like an upside down fan. His fingers"+
    " and hands are calloused from a life in the forest and "+
    "his long dark brown finger nails seem hardened to the"+
    " extent that they would be as effective as claws. His"+
    " hands look to be dirty, always, but on closer "+
    "examination you see an intricate black tattoo, on both"+
    "hands, resembling the tiny feathers of a bird covering"+
    " the backs of both hands down to his fingernails "+
    "and up to his elbows.");
    set_race("elf");
    set_gender("male");
    set_alignment(5);
    set_class("druid");
    set_class("primeval_champion");
    set_guild_level("druid",40);
    set_mlevel("druid",40);
    set_guild_level("primeval_champion",10);
    set_mlevel("primeval_champion",10);
    set_max_hp(3000);
    set_hp(3000);
    set_overall_ac(-10);
    set_stats("strength",22);
    set_stats("intelligence",13);
    set_stats("wisdom",30);
    set_stats("dexterity",23);
    set_stats("constitution",16);
    set_stats("charisma",11);
    set_property("full attacks",1);
    command("message in %^ORANGE%^pads in");
    command("message out %^ORANGE%^pads $D");
    command("speech whisper guardedly");
        set_property("cast and attack", 1);
    set_func_chance(80);
    set("aggresive","agg_fun");
    set_property("swarm",1);
    add_money("silver", random(300)+100);
    add_money("copper", random(30)+10);
    set_mob_magic_resistance("average");
        set_monster_feats(({
           "dodge",
           "evasion",
           "mobility",
           "scramble",
           "spell focus",
           "shapeshift",
           "tracklessstep",
           "venom immunity",
           "improved resistance",
           "increasted resistance",
           "resistance",
           "powerattack",
           "rush",
           "timeless body",
           "wild shape dragon",
           "mastery of fang and claw",
           "savage instincts i",
           "savage instincts ii",
           "savage instincts iii",
           "wild spellcraft",
           "natural fighting",
           "perfect predator",
           "death ward"
    }));       
     set_skill("perception",50);  
    set_emotes(1, ({"Ornsul bares his teeth angrily.",
    "Ornsul begins a deep growl.",
    "Ornsul narrows his eyes and backs away cautiously.",
    "Ornsul squats at a safe distance, catching it in his hands as it falls back down quickly.",
    "Ornsul narrows his eyes and watches warily.",
    "Onrsul nods curtly",
    "Ornsul squats at a safe distance",
    "Ornsul narrows his eyes and watches warily",
    "Ornsul grunts"}), 0);
    set_spells(({
    
	  "thorn spray",
	  "thorn body",
	  "sunburst",
	  "sunbeam",
	  "insect plague",
	  "flame strike",
	  "ball lightning",
	  "spike growth",
   }));
   set_spell_chance(100);
   command("speak elven");
   new("/d/retired/obj/orn_badge")->move(TO);
   force_me("wearall");

  }

int agg_fun() {
  string race;
  race = (string)TP->query_race();
  if (member_array(race, RACIST) == -1) return;
  if (TP->query_invis() && !TP->query_true_invis()) TP->set_invis(0);
    
  if (sizeof(TO->query_attackers()) < 1) force_me("say Raaa!  You no welcome here "+race+"!");
  force_me("kill "+TP->query_name());
}


//spells he uses animate plants, liveoak
void fodder(){
    if(!objectp(TO))return;
    if(!objectp(query_current_attacker())) { return ; }
    if(query_attackers()==({ })){        return;    } 

    switch (round1){
    case  0 :
      new("/cmds/spells/a/_animate_plants")->use_spell(TO, "summoning", 50, 100, "druid"); 
      
    break;
    
    case 1 :
      new("/cmds/spells/l/_liveoak")->use_spell(TO, "summoning", 50, 100, "druid"); 
    break;
    
    case 2 :
      new("/cmds/spells/r/_regenerate")->use_spell(TO, TO, 50, 100, "druid");
    break;
    case 3 :
      new("/cmds/spells/t/_thorn_body")->use_spell(TO, TO, 50, 100, "druid");
    break;
    }
      
      round1++;
       return;

}

void heart_beat(){

    ::heart_beat();
    if(!objectp(TO))return;
    if(!objectp(query_current_attacker())) { return ; }
    if(query_attackers()==({ })){ 
      round1 = 0;     
      return;   
     } 
    round ++;
    if (round1 < 5)
        fodder();
    return;
}
int die(){
  object ornsul;
  object *attackers;
  tell_room(ETO,"%^BOLD%^Looking angry ornsul lets out a roar as he transformed into an %^BLACK%^Obsidian dragon!");
  ornsul =     new("/d/retired/ornsul2");
  ornsul->move(ETO);
  ornsul->set("agressive",50);
  
  attackers = all_living(ETO);
  attackers = filter_array(attackers,"is_non_immortal_player",FILTERS_D);
  foreach(object ob in attackers){
    ornsul->kill_ob(ob);
  }

  this_object()->move("/d/shadowgate/void");
  return ::die();
}