#include <std.h>
#include "../elf.h"
inherit MONSTER;

create (){
::create ();
set_name("revenant");
set_id( ({"revenant","undead","fish eaten undead"}) );
set_short("Fish eaten undead");
set_long("This is an undead person who is wearing "+
"tattered rags from a bygone era.  Bit of flesh are"+
" partly detached and waver in the water. "+
"  It's eye glow red with hatred.");
set_gender("male");
set_hd(35,10);
set_hp(750+random(1000));
set("race", "undead");
set_body_type("human");
set_property("swarm",1);
set_class("barbarian");
set_mlevel("barbarian",46);
    level = 46;
set_guild_level("barbarian",46);
set_max_level(47);
set_property("full attacks",1);
set_overall_ac(-28);
set_size(2);
set_stats("strength", 19);
set_stats("intelligence", 6);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set("aggressive", 25);
set_alignment(4);
set_emotes(10,({
    "Revenant says: All dead.",
    "A small fish chews on Revenants flesh",
    "Revenant says: We were a proud kingdom once.",
    "Revenant says: The only good elf is a dead one.",
    "Revenant says: It is all those elves fault.",
    "Revenant says: They sunk our lands into the sea.",
    "Revenant sasy: Everyone I knew died that day.",
    "The Revenant seems to sob.",
    "The Revenant makes a strange noise almost like singing.",
    "The Revenant says: so much death.",
    "Revenant says: The elves killed us all, women, children, elderly.",
    "Revenant says: Kill them all!  Kill all the elves!",
    "The Revenant mumbles something about mountains of dead.",
    "The Revenant's eyes open wide!",
     "Revenant says: I had a child once...",
     "Revenant says: This hatred, it won't let me pass."
}),0);
set_hp(query_max_hp());
set_func_chance(40);
set_wielding_limbs( ({"left hand","right hand"}) );
add_money("gold", 20 + random(140));
set_resistance("negative energy",10);
set_resistance("positive energy",-10);
set_resistance_percent("slashing", 50);
set_resistance_percent("bludgeoning", 50);
set_monster_feats(({
    "rage",
    "mobility",
    "mighty rage",
    "dodge",
    "greater rage",
    "spell reflection",
      })); 
set_property("water breather", 1);
new(obj+"weed_cloak")->move(TO);
force_me("wearall");
}

void init(){
    ::init();
    force_me("rage");
}