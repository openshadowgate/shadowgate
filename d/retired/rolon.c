#include <std.h>
#include "/d/islands/pirates/piratedefs.h"
inherit MONSTER;

void create() {
    object equip;
    ::create();
    set_id(({"rolon","human","Rolon","pirate"}));
    set_name("Rolon");
    set_short("%^BOLD%^%^BLACK%^Rolon %^BOLD%^%^RED%^Garrote%^BOLD%^%^BLACK%^, %^BOLD%^%^WHITE%^pirate extraordinaire%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Rolon appears to be a massive-sized human. He is wearing %^YELLOW%^flashy "
"clothing%^BLACK%^, including a %^BLUE%^luxurious coat %^BLACK%^lined with %^YELLOW%^gold piping%^BLACK%^. "
"This man appears to be a %^CYAN%^man of the seas %^BLACK%^somehow, due to the assorted jewelry adorning his "
"body, the eye patch that covers a %^RED%^gruesome scar %^BLACK%^over his right eye, and the sailor's trousers "
"that adorn his legs. A %^WHITE%^gleaming suit of chainmail %^BLACK%^is strapped across his torso, while, "
"lastly, a pair of dashing %^YELLOW%^boots made for a swashbuckler%^BLACK%^, with the initials %^RED%^RG"
"%^BLACK%^ inscribed on the side of each boot, cover his feet.%^RESET%^");
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_alignment(3);
    set_diety("bane");
    set_class("fighter");
    set_hd(26,10);
    set_guild_level("fighter",26);
    set_mlevel("fighter",26);
    set_max_hp(1000);
    set_hp(1000);
    set_exp(8000);
    set_overall_ac(0);
    set("aggressive",3);
    set_stats("strength",18);
    set_stats("intelligence",14);
    set_stats("wisdom",14);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set_stats("charisma",13);
    set_property("full attacks",1);
    set_wielding_limbs(({"left hand","right hand"}));
    command("message in %^RESET%^enters nimbly and nonchalantly.");
    command("message out %^RESET%^saunters $D %^RESET%^nonchalantly.");
    command("speech %^BOLD%^%^GREEN%^state with a %^MAGENTA%^swashbuckling tone%^RESET%^");
    equip = new(OBJ"boots");
      equip->set_property("monsterweapon",1);
      equip->move(TO);
      command("wear boots");
    equip = new("/d/deku/sanctuary/obj/lightningbolt");
      equip->set_property("monsterweapon",1);
      equip->move(TO);
      command("wield rapier");
    equip = new(OBJ"rapier");
      equip->set_property("monsterweapon",1);
      equip->move(TO);
      command("wield rapier");
    equip = new(OBJ"newcoat");
      if(!random(3)) equip->set_property("monsterweapon",1);
      equip->move(TO);
      command("wear coat");
    equip = new("/d/retired/obj/rolonchain");
      equip->move(TO);
      command("wear chain");
    equip = new("/d/dagger/Torm/obj/eyepatch");
      if(random(3)) equip->set_property("monsterweapon",1);
      equip->move(TO);
      command("wear eyepatch");
    equip = new("/d/dagger/Torm/obj/pantsc");
      if(random(3)) equip->set_property("monsterweapon",1);
      equip->move(TO);
      command("wear pants");
    set_funcs(({"slash","slash","rushem","flashem","flashem","shatterit","sunderit"}));
    set_func_chance(80);
    set_fighter_style("swashbuckler");
    set("aggresive","agg_fun");
    set_property("swarm",1);
    add_money("silver", random(300)+100);
    add_money("copper", random(30)+10);
    set_mob_magic_resistance("average");
	set_monster_feats(({
	   "ambidexterity",
	   "two weapon fighting",
	   "improved two weapon fighting",
	   "whirl",
	   "unassailable parry",
	   "toughness",
	   "improved toughness",
	   "damage resistance",
	   "regeneration",
	   "powerattack",
	   "shatter",
	   "sunder",
	   "rush",
    }));	
    set_emotes(1, ({"%^BOLD%^%^GREEN%^Rolon states with a %^BOLD%^%^MAGENTA%^swashbuckling tone:%^BOLD%^"
"%^GREEN%^ Arghh.%^RESET%^","%^BOLD%^%^GREEN%^Rolon %^RESET%^swears like a %^BOLD%^%^CYAN%^drunken sailor"
"%^RESET%^.","%^BOLD%^%^GREEN%^Rolon %^BOLD%^%^CYAN%^breathes %^RESET%^in nonchalantly and as he %^BOLD%^"
"%^CYAN%^exhales%^RESET%^, a %^BOLD%^%^CYAN%^stiff breeze of the sea %^RESET%^can be smelled in the %^BOLD%^"
"%^CYAN%^air%^RESET%^.","%^BOLD%^%^GREEN%^Rolon %^RESET%^flips a %^BOLD%^%^YELLOW%^golden coin %^RESET%^into "
"the %^BOLD%^%^CYAN%^air%^RESET%^, catching it in his hands as it falls back down quickly.%^RESET%^","%^BOLD%^"
"%^GREEN%^Rolon %^RESET%^begins to emit a %^BOLD%^%^GREEN%^bright green aura %^RESET%^momentarily for some "
"reason, before it slowly fades away.%^RESET%^" }), 0);
}

int agg_fun() {
    if (TP->query_invis() && !TP->query_true_invis()) TP->set_invis(0);
    if (sizeof(TO->query_attackers()) < 1) force_me("say En Garde!");
    force_me("kill "+TP->query_name());
}

void slash(object targ){
    tell_object(targ,"%^BOLD%^%^MAGENTA%^Rolon leaps forward in a riposte immediately following your attack, "
"giving you no chance to deflect the blow!%^RESET%^");
    tell_room(environment(targ),"%^BOLD%^%^BLUE%^Rolon leaps forward in a riposte immediately following "
+targ->QCN+"'s attack, giving "+targ->QO+" no chance to deflect the blow!%^RESET%^",targ);
    targ->do_damage("torso",random(15)+20);
}

void rushem(object targ){
    command("rush "+targ->query_cap_name());
}

void flashem(object targ){
    command("flash "+targ->query_cap_name());
}

void sunderit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sunder "+targ->query_name());
}

void shatterit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}