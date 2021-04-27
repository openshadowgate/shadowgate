//Based on Muln for Ryzan and Aunuit's guardians
//~Circe~ 8/6/13

#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

int done, i;
object *others;
void burn();

void create(){
   ::create();
   set_id(({"dragon","sentinel","draconian sentinel","guardian","draconian construct","construct"}));
   set_name("draconian construct");
   set_short("%^BOLD%^%^BLACK%^drac%^RED%^o%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^an construct%^RESET%^");
   set_long("%^RESET%^Constructed entirely of %^BOLD%^%^BLACK%^"
      "adam%^WHITE%^a%^BLACK%^nt%^RESET%^i%^BOLD%^%^BLACK%^te "
      "%^RESET%^this dragon is a %^RED%^fe%^BOLD%^%^RED%^a"
      "%^RESET%^%^RED%^rs%^BOLD%^%^RED%^o%^RESET%^%^RED%^me "
      "%^RESET%^sight to behold. The g%^BOLD%^%^BLACK%^l%^WHITE%^"
      "o%^BLACK%^s%^RESET%^sy s%^BOLD%^%^WHITE%^c%^RESET%^al"
      "%^BOLD%^%^BLACK%^e%^RESET%^s along its neck rise, producing "
      "%^BOLD%^%^CYAN%^b%^WHITE%^i%^CYAN%^ll%^RESET%^%^CYAN%^o"
      "%^BOLD%^%^WHITE%^w%^CYAN%^ing %^RESET%^streams of s%^BOLD%^"
      "%^BLACK%^t%^WHITE%^e%^RESET%^am. Its narrowed eyes and "
      "gullet emit a %^RED%^f%^BOLD%^%^RED%^i%^ORANGE%^e%^RESET%^"
      "%^RED%^ry l%^BOLD%^%^RED%^i%^RESET%^%^RED%^ght %^RESET%^as "
      "%^RED%^heat %^WHITE%^builds within its belly. C%^BOLD%^"
      "%^BLACK%^u%^RESET%^rved %^BOLD%^%^BLACK%^horns %^RESET%^jut "
      "from its head and could be used for %^ORANGE%^battering "
      "%^WHITE%^or %^BOLD%^%^RED%^impaling%^RESET%^. Its claws are "
      "as dangerous-looking as ra%^BOLD%^%^RED%^z%^RESET%^or-sh"
      "%^BOLD%^%^BLACK%^a%^RESET%^rp scimitars and its scales "
      "themselves look as if they could %^BOLD%^%^RED%^r%^RESET%^"
      "%^RED%^e%^BOLD%^%^RED%^nd %^RESET%^flesh at even the slightest "
      "touch. Its long tail is surprisingly quick and agile despite "
      "being made of %^BOLD%^%^BLACK%^metal%^RESET%^, darting back and "
      "forth and sweeping the ground. Even though this beast is a "
      "construct great detail has gone into its crafting giving it a "
      "very %^GREEN%^org%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^n%^CYAN%^"
      "i%^GREEN%^c%^WHITE%^ presence.%^RESET%^");
    set_race("construct");
    set_body_type("dragon");
    set_gender("neuter");
    set_alignment(3);
    set_size(3);
    set_class("mage");
    set_class("cleric");
    set_hd(35+(random(11)),4);
    set_mlevel("mage",query_hd());
    set_mlevel("cleric",query_hd());
    set_hp((query_hd() * 50) + random(query_hd()));
    set_guild_level("mage",query_hd());
    set_guild_level("cleric",query_hd());
    set_attack_bonus(10);
    set_mob_magic_resistance("average");
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("no rush",1);
//    set_property("strength","shadow");
    set_property("swarm",1);
    set_property("no bows",1);
    set_property("no steal",1);
    set_stats("strength",23);
    set_stats("dexterity",18);
    set_exp(60000);
    set_overall_ac(-13);
    set_spells(({
	"darkbolt",
	"vampiric touch",
	"gust of wind",
    }));
    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({"right foreclaw","left foreclaw","tail","mouth"}));
    set_hit_funcs((["tail":(:TO,"tail_attack":),"right foreclaw":(:TO,"wing_attack":),"left foreclaw":(:TO,"wing_attack":)]));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(2,8);
    set_funcs(({"breath"}));
    set_func_chance(102);
    set_spell_chance(30);
    set("aggressive",1);
}

int tail_attack(object targ){
   object *enemies;
   enemies = all_living(ETO);
   enemies = filter_array(enemies,"is_non_immortal",FILTERS_D);
   if(!random(4)){
      tell_room(ETO,"%^RESET%^The %^BOLD%^%^BLACK%^drac%^RED%^o"
         "%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^an construct%^RESET%^ "
         "rears and begins beating its heavy wings, creating a "
         "powerful %^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^nd "
         "%^RESET%^that %^BOLD%^%^BLACK%^buffets %^RESET%^its enemies!");
      for(i=0;i<sizeof(enemies);i++){
         if(!objectp(enemies[i])) continue;
         if(!objectp(TO)) continue;
         if((string)enemies[i]->query_name() == "draconian construct") continue;
         tell_object(enemies[i],"%^BOLD%^%^CYAN%^You are blown about by the wind!%^RESET%^");
         enemies[i]->do_damage(enemies[i]->return_target_limb(),roll_dice(4,18));
      }
   }
   return roll_dice(3,12);
}

int wing_attack(object targ){
   object *enemies;
   enemies = all_living(ETO);
   enemies = filter_array(enemies,"is_non_immortal",FILTERS_D);
   if(!random(3)){
      tell_room(ETO,"%^BOLD%^%^BLACK%^With a gleeful %^WHITE%^screech"
         "%^BLACK%^, the drac%^RED%^o%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^an "
         "construct turns its body, swinging its ra%^RED%^z%^WHITE%^o%^BLACK%^"
         "r-sharp tail across the floor %^RESET%^%^ORANGE%^sweeping %^BOLD%^"
         "%^BLACK%^aside all in its path!%^RESET%^");
      for(i=0;i<sizeof(enemies);i++){
         if(!objectp(enemies[i])) continue;
         if(!objectp(TO)) continue;
         if((string)enemies[i]->query_name() == "draconian construct") continue;
         if(!SAVING_THROW_D->do_save(enemies[i],0,"reflex")){
            tell_object(enemies[i],"%^BOLD%^%^WHITE%^You are knocked to the ground!%^RESET%^");
            tell_room(ETO,"%^BOLD%^%^WHITE%^"+enemies[i]+" is knocked to the ground!%^RESET%^",enemies[i]);
            enemies[i]->set_tripped(1,"You are struggling to stand!");
            enemies[i]->do_damage(enemies[i]->return_target_limb(),roll_dice(3,25));
         }
      }
   }
   return roll_dice(4,25);
}

void breath(object targ){
   others = all_living(ETO);
   others = filter_array(others,"is_non_immortal",FILTERS_D);
   for(i=0;i<sizeof(others);i++){
      others[i]->remove_property("hit");
   }
   set_func_chance(20);
   tell_room(ETO,"%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^drac%^RED%^o"
      "%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^an construct%^RESET%^%^RED%^ "
      "opens its fanged maw, h%^BOLD%^%^RED%^e%^ORANGE%^a%^RESET%^%^RED%^t "
      "building within its %^WHITE%^m%^BOLD%^%^BLACK%^e%^RESET%^tal "
      "%^RED%^belly causing %^WHITE%^steam %^RED%^to vent from between "
      "its sharp scales. The beast thrusts its head forward and emits "
      "a terrible blast of %^RED%^f%^BOLD%^%^RED%^l%^ORANGE%^a%^RED%^m"
      "%^RESET%^%^RED%^e!%^RESET%^");

    if(!SAVING_THROW_D->do_save(targ,0,"reflex")){
	tell_object(targ,"%^BOLD%^%^RED%^The fire engulfs you completely!");
	tell_room(ETO,"%^BOLD%^%^RED%^The fire engulfs "+targ->QCN+" completely!",targ);
	set_property("magic",1);
	targ->do_damage(targ->return_target_limb(),roll_dice(24,8));
	remove_property("magic");
	targ->set_property("hit",1);
	burn();
	return 1;
    }
    tell_object(targ,"%^RESET%^%^ORANGE%^Rolling away, you manage to avoid the worst of the flames!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^ORANGE%^"+targ->QCN+" rolls out of the way and is only slightly burned!%^RESET%^",targ);
    set_property("magic",1);
    targ->do_damage(targ->return_target_limb(),roll_dice(24,8)/2);
    remove_property("magic");
    targ->set_property("hit",1);
    burn();
    return 1;
}

void burn(){
   tell_room(ETO,"%^YELLOW%^The %^RED%^fi%^YELLOW%^r%^RED%^e %^YELLOW%^quickly spreads across the room!%^RESET%^");
   for(i=0;i<sizeof(others);i++){
      if(others[i] == TO) continue;
      if(others[i]->query_property("hit",1)) continue;
      if((string)others[i]->query_name() == "draconian construct") continue;
      if(!SAVING_THROW_D->do_save(others[i],0,"reflex")){
         tell_object(others[i],"%^BOLD%^%^RED%^The flames slams into you full force!%^RESET%^");
         tell_room(ETO,"%^BOLD%^%^RED%^"+others[i]->QCN+" is caught full force by the flames!%^RESET%^",others[i]);
         set_property("magic",1);
         others[i]->do_damage(others[i]->return_target_limb(),roll_dice(12,8));
         remove_property("magic");
         others[i]->kill_ob(TO,1);
       } else {
         tell_object(others[i],"%^RESET%^%^ORANGE%^The flames barely graze you!%^RESET%^");
         tell_room(ETO,"%^RESET%^%^ORANGE%^"+others[i]->QCN+" is barely grazed by the flames!%^RESET%^",others[i]);
         set_property("magic",1);
         others[i]->do_damage(others[i]->return_target_limb(),roll_dice(12,8)/2);
         remove_property("magic");
         others[i]->kill_ob(TO,1);
      }
   }
   return 1;
}

void heart_beat(){
  if (!objectp(TO)) return;
    ::heart_beat();
    if(present("summoned monster") || present("snake")){
	if(!done){
	new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,query_level(),100,"mage");
	done = 1;
	call_out("check_me",30);
	}
    }
   if (!objectp(TO)) return;
    if(TO->query_hp() < TO->query_max_hp()){
	TO->add_hp(10+random(10));
    }
    if((string *)TO->query_attackers() == ({})){
	set_func_chance(102);
    }
}

void check_me(){
    done = 0;
}

void reset(){
    ::reset();
    set_func_chance(102);
}

void set_paralyzed(string message, int time){return 1;}
