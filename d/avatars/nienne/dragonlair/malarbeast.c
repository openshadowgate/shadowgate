#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("monstrous beast");
   set_id(({"monstrous beast","beast"}));
   set_short("%^RESET%^%^RED%^monstrous ravening beast%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This creature is beyond words or imagination, something straight from nightmare.  "
"As big as a house, its four-horned head sports blazing ember eyes, above a fanged maw filled with rows of sharp teeth"
".  Thick fur of a blood-red shade coats its lean hide, marked with sable stripes down to the tip of its lashing tail.  "
"Vicious claws gleam at the end of each paw, sharp enough to rend flesh from bone with ease.  The thick, musky scent of "
"the beast is almost enough to make your head spin.%^RESET%^");
   set_race("beast");
   set_gender("neuter");
   set_body_type("quadruped");
   set_alignment(9);
   set_size(4);
   set_exp(100000);
   add_limb("teeth","head",0,0,0);
   add_limb("left talons","left foreleg",0,0,0);
   add_limb("right talons","right foreleg",0,0,0);
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
   set_max_hp(13000);
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
   set_overall_ac(-32);
   set_funcs(({"shriek","shriek","teeth_fun","teeth_fun","illusions","illusions","undead","undead","silencedust"}));
   set_func_chance(85);
   set_property("swarm",1);
   new("/d/avatars/nienne/huntdomain")->move(TO);
   set("aggressive",25);
}

void init() {
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
   add_action("no_cast","caress");
}

int no_cast(string str) {
   tell_object(TP,"%^BOLD%^%^BLUE%^The beast seems to sense your intent, lashing out with a mighty paw that casts you "
"flying through the air, to hit the ground with bruising impact!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLUE%^The beast seems to sense "+TP->QCN+"'s intent, lashing out with a mighty paw that casts "
+TP->QO+" flying through the air, to hit the ground with bruising impact!%^RESET%^",TP);
   TP->set_paralyzed(25,"%^BOLD%^%^CYAN%^You're still trying to get to your feet!");
   return 1;
}

void shriek(object target) {
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^GREEN%^The beast throws back its head and lets out an ear-splitting %^BOLD%^%^CYAN%^sh"
"%^GREEN%^r%^CYAN%^i%^YELLOW%^e%^CYAN%^k%^RESET%^%^GREEN%^, and all thoughts are swept from your mind except the agony "
"of the sound!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   TO->set_property("magic",1);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->do_damage("torso",150+random(50));
   }
   TO->remove_property("magic");
   return;
}

void illusions(object target){
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^CYAN%^The beast's massive paw comes down upon the ground with an almighty thump, and the "
"ground beneath you rocks like the waves of the ocean! You are thrown from your feet!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->set_tripped(2,"%^YELLOW%^You're trying to get back up!%^RESET%^",ROUND_LENGTH);
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
   tell_object(target,"%^BOLD%^%^RED%^The beast darts forward with shocking speed and snatches you from the ground, its "
"talons tearing into your chest and throat as it lifts you high and then tosses you aside!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^RED%^There is no pre-warning of the beast's movements, when it suddenly darts forward with "
"impossible speed to snatch "+target->QCN+" from the ground, its talons tearing into "+target->QP+" chest and throat as "
"it lifts "+target->QO+" high, and then tosses "+target->QO+" aside!%^RESET%^",target);
   TO->set_property("magic",1);
   target->do_damage("torso",random(75)+200);
   TO->remove_property("magic");
}

void undead(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   tell_room(ETO,"%^MAGENTA%^A %^BLUE%^howl %^MAGENTA%^goes up from the beast as it throws back its head, calling upon "
"the creatures of the forest to aid it!%^RESET%^");
   for(i = 0;i<6;i++) {
     target = vars[random(sizeof(vars))];
     if(!objectp(target)) continue;
     if(!interactive(target)) continue;
     switch(random(4)) {
       case 0:
         tell_object(target,"%^RED%^A wolf lunges from the undergrowth to snap at you!%^RESET%^");
       break;
       case 1:
         tell_object(target,"%^RED%^A serpent rears up from the grass and lashes out at you with fangs bared!%^RESET%^");
       break;
       case 2:
         tell_object(target,"%^RED%^An answering shriek comes from above as a hawk swoops past, slashing at you with claws outstretched!%^RESET%^");
       break;
       default:
         tell_object(target,"%^RED%^Tiny insects swarm around you, biting mercilessly at any exposed flesh they can find!%^RESET%^");
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
   tell_object(target,"%^GREEN%^The beast lunges at you and slams you back, knocking the wind from your lungs!%^RESET%^");
   tell_room(ETO,"%^GREEN%^The beast lunges at "+target->QCN+" and slams "+target->QO+" back, and "+target->QS+" gasps as the air is knocked from "+target->QP+" lungs!%^RESET%^",target);
   if(dustobj = present("choking-dust-obj",target)) dustobj->remove();
   new("/d/avatars/nienne/dragonlair/chokingdust")->move(target);
   target->do_damage("torso",random(100)+150);
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if((int)TO->query_hp() < (int)TO->query_max_hp()) TO->add_hp(random(60)+60);
}

void die(object ob){
   tell_room(ETO,"%^ORANGE%^The beast lets out a thunderous roar of agony, %^RESET%^bleeding %^ORANGE%^from countless injuries as it staggers and falls to its "
"knees. Its lips part, fangs bared in a last feral snarl of denial.%^RESET%^");
   message("info","%^BOLD%^%^RED%^A earth-shaking %^YELLOW%^ro%^WHITE%^a%^YELLOW%^r %^RED%^of denial echoes from somewhere distant!%^RESET%^",users());
   tell_room(ETO,"%^MAGENTA%^Finally, the last of its strength gone, it falls to the ground and moves no more.%^RESET%^");
   ::die(TO);
}