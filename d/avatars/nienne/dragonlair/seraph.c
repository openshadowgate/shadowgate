#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("Seraph");
   set_id(({ "seraph","demon","Seraph","seraph of madness"}));
   set_short("%^RESET%^%^MAGENTA%^Seraph of Madness%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This creature is beyond words or imagination, something straight from nightmare.  Its "
"horned head sports four eyes, each black as night, above a fanged maw filled with rows of sharp teeth.  Leathery skin of "
"a blood-red shade coats its hide, leading down to a muscular frame with spikes and barbs protruding from each joint, "
"like a caricature of some horrific suit of spiked armor.  Vicious claws gleam at the end of hands and feet, sharp "
"enough to rend flesh from bone with ease.  Around the monster drift the ghosts and spirits of the damned, at times "
"visible with silently screaming faces and claws reaching out to rend the life from any foolish enough to approach"
".%^RESET%^");
   set_race("demon");
   set_gender("neuter");
   set_body_type("humanoid");
   set_alignment(9);
   set_size(4);
   set_exp(100000);
   add_limb("teeth","head",0,0,0);
   add_limb("left talons","left hand",0,0,0);
   add_limb("right talons","right hand",0,0,0);
   set_attack_limbs( ({"teeth","left talons","right talons"}) );
   set_attacks_num(6);
   set_base_damage_type("slashing");
   set_damage(3,10);
   set_hd(50,12);
   set_class("fighter");
   set_mlevel("fighter",50);
   set_guild_level("fighter",50);
   set_class("cleric");
   set_mlevel("cleric",50);
   set_guild_level("cleric",50);
   set_max_hp(12000);
   set_hp(query_max_hp());
   set_property("weapon resistance",4);
   set_property("damage resistance",10);
   set_property("no animate", 1);
   set_property("no death", 1);
   set_property("no steal", 1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_property("no dominate", 1);
   set_property("no bows", 1);
   set_property("no knockdown", 1);
   set_property("no tripped", 1);
   set_property("no web", 1);
   set_overall_ac(-27);
   set_funcs(({"shriek","shriek","teeth_fun","teeth_fun","illusions","illusions","undead","undead","silencedust","silencedust"}));
   set_func_chance(85);
   set_property("swarm",1);
}

void init() {
   object *present;
   int i;
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
   add_action("no_cast","caress");
   present = all_living(ETO);
   if(sizeof(present)) {
     for(i = 0;i<sizeof(present);i++) {
       if(!present[i]->query_true_invis()) {
         TO->add_attacker(present[i]);
         present[i]->add_attacker(TO);
       }
     }
   }
}

int no_cast(string str) {
   tell_object(TP,"%^BOLD%^%^BLUE%^The Seraph seems to sense your intent, flinging out a taloned hand that casts you "
"flying through the air, to hit the ground with bruising impact!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLUE%^The Seraph seems to sense "+TP->QCN+"'s intent, flinging out a taloned hand that casts "
+TP->QO+" flying through the air, to hit the ground with bruising impact!%^RESET%^",TP);
   TP->set_paralyzed(25,"%^BOLD%^%^CYAN%^You're still trying to get to your feet!");
   return 1;
}

void shriek(object target) {
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^GREEN%^The Seraph throws back its head and lets out an ear-splitting %^BOLD%^%^CYAN%^sh"
"%^GREEN%^r%^CYAN%^i%^YELLOW%^e%^CYAN%^k%^RESET%^%^GREEN%^, and all thoughts are swept from your mind except the agony "
"of the sound!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   TO->set_property("magic",1);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->do_damage("torso",200+random(50));
   }
   TO->remove_property("magic");
   return;
}

void illusions(object target){
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^CYAN%^A swing of the Seraph's clawed hand through the air casts such terrifying illusions "
"before you that you can't help but stagger back and avert your eyes in %^RED%^horror%^CYAN%^!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->set_tripped(4,"%^YELLOW%^You're trying to shake free of the illusions!%^RESET%^",ROUND_LENGTH);
     vars[i]->do_damage("torso",100+random(50));
   }
}

void teeth_fun(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   target = vars[random(sizeof(vars))];
   if(!objectp(target)) return;
   if(!interactive(target)) return;
   tell_object(target,"%^BOLD%^%^RED%^The Seraph darts forward with shocking speed and snatches you from the ground, its "
"talons tearing into your chest and throat as it lifts you high and then tosses you aside!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^RED%^There is no warning of the dragon's movements, shrouded as they are by %^BOLD%^"
"%^BLACK%^shad%^RESET%^ow%^BOLD%^%^BLACK%^s%^RED%^, and suddenly it lashes out with a wing to knock "+target->QCN+" into "
"the nearest stone wall, hitting with an impact that seems to leave "+target->QO+" momentarily shaken!%^RESET%^",target);
   TO->set_property("magic",1);
   target->do_damage("torso",random(75)+250);
   TO->remove_property("magic");
}

void undead(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   tell_room(ETO,"%^MAGENTA%^A great %^BLUE%^wail %^MAGENTA%^goes up around you as the Seraph raises his hands, calling "
"upon the spirits of the damned to aid him!%^RESET%^");
   for(i = 0;i<6;i++) {
     target = vars[random(sizeof(vars))];
     if(!objectp(target)) continue;
     if(!interactive(target)) continue;
     switch(random(4)) {
       case 0:
         tell_object(target,"%^RED%^A howling spirit shrieks past you, slashing at you with spectral talons!%^RESET%^");
       break;
       case 1:
         tell_object(target,"%^RED%^Spirits race past you, lashing out at everything within reach!%^RESET%^");
       break;
       case 2:
         tell_object(target,"%^RED%^The nearest spirit lunges towards you with claws outstretched, tearing into your skin "
"like paper!%^RESET%^");
       break;
       default:
         tell_object(target,"%^RED%^A spirit of the damned tears through you, sending chills through you from head to "
"toe!%^RESET%^");
       break;
     }
     target->do_damage("torso",random(25)+50);
   }
}

void silencedust(object target) {
   object *vars, dustobj;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   target = vars[random(sizeof(vars))];
   if(!objectp(target)) return;
   if(!interactive(target)) return;
   tell_object(target,"%^GREEN%^The Seraph looks straight at you, and you feel his maddened gaze boring into you.  Your "
"throat suddenly closes up and you can't breathe!%^RESET%^");
   tell_room(ETO,"%^GREEN%^The Seraph looks straight at "+target->QCN+", who suddenly starts choking and clawing at "
+target->QP+" throat!%^RESET%^",target);
   if(dustobj = present("choking-dust-obj",target)) dustobj->remove();
   new("/d/avatars/nienne/dragonlair/chokingdust")->move(target);
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if((int)TO->query_hp() < (int)TO->query_max_hp()) TO->add_hp(random(60)+60);
}

void die(object ob){
   tell_room(ETO,"%^ORANGE%^The Seraph shudders and falls to his knees with an impact that shakes the earth around you.  "
"He reaches up clawed hands to the whorling sky above, screaming %^YELLOW%^'Master, do not fail me now!'%^RESET%^"
"%^ORANGE%^  His black blood pools out upon the earth, hissing wherever it touches.%^RESET%^");
   message("info","%^BOLD%^%^RED%^A %^YELLOW%^sh%^WHITE%^r%^YELLOW%^iek %^RED%^of utter damnation goes up around you, "
"%^CYAN%^chill%^WHITE%^i%^CYAN%^ng %^RED%^you to the bone, before it is cut off abruptly into silence!%^RESET%^",users());
   tell_room(ETO,"%^MAGENTA%^Finally, the last of his strength gone, he falls to the ground and is completely "
"motionless.%^RESET%^");
   ::die(TO);
}