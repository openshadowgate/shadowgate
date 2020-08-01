#include <std.h>
#include "../elf.h"
inherit MONSTER;

create (){
create ();
set_name("Captain Rev");
set_id( ({"rev","undead","captian rev","noble","decayed noble"}) );
set_short("Decayed Noble");
set_long("This is an undead person who is wearing "+
"tattered rags from a bygone era.  Bit of flesh are"+
" partly detached and waver in the water. "+
"  It's eye glow red with hatred.  Unlike some"+
" of the other undead this one has the remains of"+
" fancier clothing.  He might have been someone "+
"important when he was still alive.");
set_gender("male");
set_hd(40,10);
set_hp(750+random(3000));
set("race", "undead");
set_body_type("human");
set_property("swarm",1);
set_class("barbarian");
set_mlevel("barbarian",46);
    level = 46;
set_guild_level("barbarian",46);
set_max_level(47);
set_property("full attacks",1);
set_overall_ac(-35);
set_size(2);
set_stats("strength", 25);
set_stats("intelligence", 6);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set_alignment(4);
set_attacks_num(6);
set_hp(query_max_hp());
set_wielding_limbs( ({"left hand","right hand"}) );
add_money("copper", 200 + random(140));
set_resistance("negative energy",10);
set_resistance("positive energy",-10);
set_resistance_percent("slashing", 70);
set_resistance_percent("bludgeoning", 70);
set_mob_magic_resistance("average");
set_monster_feats(({
    "rage",
    "mobility",
    "mighty rage",
    "dodge",
    "greater rage",
    "spell reflection",
    "mobility",
      })); 
void init(){
    ::init();
    if(!query_property("raged"))
        force_me("rage");
    return;
}
void heart_beat(){
    object rev;
    ::heart_beat();
    if(!objectp(TO))return;
    if(!objectp(query_current_attacker())) { return ; }
    if(query_attackers()==({ })) return;
   
    if(!present("revenant", ETO)){
    force_me("say To me men!  Your war doesn't end until I say so!");
    tell_room(ETO,"%^BOLD%^%^BLACK%^A nearby dead body rises and attacks!");
    rev = new(MON"rev");
	rev->move(ETO);
	TO->add_protector(rev);
	TO->add_follower(rev);
    }
    return;
}
void sweep(object targ){
  object * critters;
  critters = query_attackers();
    if(!objectp(TO))return;
    if(!objectp(query_current_attacker())) { return ; }
    if(query_attackers()==({ })) return;
  tell_room(ETO,"%^RED%^The dead captain lets out a %^BLUE%^drowning%^RED%^ gurgle!");
  foreach(object ob in critters){
      tell_object(ob, "%^BLUE%^The noise makes you feel like you are drowning!." );
      ob->cause_typed_damage(ob, ob->return_target_limb(),random(200),"mental");
  }
}
