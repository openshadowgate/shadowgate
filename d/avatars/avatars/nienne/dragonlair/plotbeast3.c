#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();

   set_name("shadowy serpent");
   set_id(({"shadowy serpent","serpent"}));
   set_short("%^RESET%^%^BLUE%^shadowy serpent");
   set_long("%^CYAN%^This dark, shadowy form appears to be a large serpentine beast of some kind, with wings of gloom that spread far above its lean frame. Multiple legs along its sinuous body allow it to move with startling speed, with a long tail that follows and moves like an independent creature. Its head lifts to reveal %^BOLD%^%^WHITE%^glowing%^RESET%^%^CYAN%^ eyes, and a breath of icy mist parts its fanged maw.");
   set_body_type("snake");
   set_alignment(5);
   add_limb("upper left claw","",0,0,0);
   add_limb("middle left claw","",0,0,0);
   add_limb("lower left claw","",0,0,0);
   add_limb("upper right claw","",0,0,0);
   add_limb("middle right claw","",0,0,0);
   add_limb("lower left claw","",0,0,0);
   set_attack_limbs(({"upper right claw","middle right claw","lower right claw","upper left claw","lower left claw","middle left claw","mouth"}));
   set_attacks_num(7);
   set_damage(2,8);
   set_hd(35+random(15),9);
   set_hp(query_hd()*25);
   set_hit_funcs((["mouth":(:TO,"mouth":)]));
   set_mob_magic_resistance("average");
   set_overall_ac(-25);
   set_race("serpent");
   set_gender("neuter");
   set_exp(400*query_hd());
   set_new_exp(35,"boss");
   set_max_level(36);
   set_property("no web",1);
   set("aggressive",25);
   set_property("no tripped",1);
   set_property("no paralyzed",1);
      set_monster_feats(({
          "damage resistance",
          "regeneration",
          "parry",
        "knockdown",
         "powerattack",
         "daze",
        "dodge",
        "expertise",
        "disarm",
   }));
   set_func_chance(55);
    set_funcs(({"knockdownit","dazeit","disarmit"}));
}


void knockdownit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
   TO->continue_attack();
}

void dazeit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("daze "+targ->query_name());
   TO->continue_attack();
}

void disarmit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("disarm "+targ->query_name());
   TO->continue_attack();
}

int mouth(object targ){
   int i,j;
   object *attack = query_attackers();

   set_property("magic",1);
   j=sizeof(attack);
   tell_room(ETO,"%^BOLD%^%^WHITE%^The serpent rears back and opens its maw, unleashing a blast of hazy fog that chills you to the bone!");
   for (i=0;i<j;i++) {
      if(!objectp(attack[i])||attack[i]->query_true_invis()) continue;
      attack[i]->do_damage("torso",roll_dice(4,12));

   }
   return random(10);
}

void die(object ob){
   object ob3;
   tell_room(ETO,"%^BOLD%^%^CYAN%^A low hiss comes from the serpent as mist froths from its maw, and it dissipates into air!%^RESET%^");
   TO->move("/d/shadowgate/void");
   TO->remove();
}