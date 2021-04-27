#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit WEAPONLESS;

void create() {
   ::create();
   set_name("pit fiend");
   set_id(({"devil","pit fiend","fiend"}));
   set_short("%^RESET%^%^RED%^a terrifying pit fiend%^RESET%^");
   set_long("%^RESET%^%^RED%^Before you rises the form of a creature from nightmare, a mighty devil twice the height "
"of a man. Massive batwings, large enough to wrap its entire %^BOLD%^%^RED%^crimson-scaled form%^RESET%^%^RED%^, rise "
"from its shoulders. %^BOLD%^%^BLACK%^Blackened horns %^RESET%^%^RED%^jut to either side of its ridged head, its eyes "
"glowing with ember-bright fury and its fanged maw opened in a snarl of hatred. %^BOLD%^%^RED%^Infernal flames %^RESET%^"
"%^RED%^wreathe its form, emanating a searing heat to any close by. Simply looking upon the creature renders a thrill "
"of fear down your spine.%^RESET%^");
   set_race("devil");
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
   set_max_hp(15000);
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
   set("aggressive",25);
}

void init() {
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
   add_action("no_cast","caress");
}

int no_cast(string str) {
   tell_object(TP,"%^BOLD%^%^BLUE%^The devil turns and affixes you with a horrifying stare, causing you to freeze in place!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLUE%^The devil affixes "+TP->QCN+" with a horrifying stare, causing "+TP->QO+" to freeze in place!%^RESET%^",TP);
   TP->set_paralyzed(25,"%^BOLD%^%^CYAN%^You're frozen in fear!");
   return 1;
}

void shriek(object target) {
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^GREEN%^The devil flings out a clawed fist and casts forth a wave of %^RED%^infernal flame%^GREEN%^ that sears through everything it touches!%^RESET%^");
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

   tell_room(ETO,"%^RESET%^%^CYAN%^A scaled foot comes down upon the ground as the devil invokes an aura of %^MAGENTA%^fear%^CYAN%^, and unnameable horrors race through your mind, tearing at your sanity!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->set_tripped(2,"%^YELLOW%^You're trying to shake the memory of the horrors from your mind!%^RESET%^",ROUND_LENGTH);
     vars[i]->do_damage("torso",150+random(50));
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
   tell_object(target,"%^BOLD%^%^RED%^The fiend lunges at you without warning, its speed incredible for a being of such size, and it bites deep into your skin!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^RED%^There is almost no pre-warning of the fiend's movements, when it suddenly darts forward with impossible speed to sink its teeth deep into "+target->QCN+"'s flesh!%^RESET%^",target);
   TO->set_property("magic",1);
   target->do_damage("torso",random(75)+150);
   TO->remove_property("magic");
   call_out("reburn",ROUND_LENGTH,target);
}

void reburn(object target) {
   if(!target || !objectp(target)) return;
   if(!objectp(TO)) return;
   tell_object(target,"%^BOLD%^%^GREEN%^The terrible poison of the fiend's bite races through your veins!%^RESET%^");
   tell_room(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" screams in agony as the fiend's terrible poison courses through "+target->QP+" veins!%^RESET%^",target);
   TO->set_property("magic",1);
   target->do_damage("torso",100+random(100));
   TO->remove_property("magic");
}

void undead(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   tell_room(ETO,"%^MAGENTA%^The fiend lashes out in a fury, its claws rending flesh and bone!%^RESET%^");
   for(i = 0;i<6;i++) {
     target = vars[random(sizeof(vars))];
     if(!objectp(target)) continue;
     if(!interactive(target)) continue;
     switch(random(4)) {
       case 0:
         tell_object(target,"%^RED%^A scaled hand catches you across the face!%^RESET%^");
       break;
       case 1:
         tell_object(target,"%^RED%^Talons lacerate your body!%^RESET%^");
       break;
       case 2:
         tell_object(target,"%^RED%^The fiend's claws sink deep into your flesh!%^RESET%^");
       break;
       default:
         tell_object(target,"%^RED%^Claws rend jagged wounds across your back!%^RESET%^");
       break;
     }
     target->do_damage("torso",random(25)+100);
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
   tell_object(target,"%^GREEN%^The devil stares straight at you, and your throat chokes closed in sudden horror under its gaze!%^RESET%^");
   tell_room(ETO,"%^GREEN%^The devil stares straight at "+target->QCN+", and "+target->QS+" seems to choke on "+target->QP+" breath!%^RESET%^",target);
   if(dustobj = present("choking-dust-obj",target)) dustobj->remove();
   new("/d/avatars/nienne/dragonlair/chokingdust")->move(target);
   target->do_damage("torso",random(100)+200);
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if((int)TO->query_hp() < (int)TO->query_max_hp()) TO->add_hp(random(60)+60);
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^%^RED%^The pit fiend stumbles and screams in denial, its scaled form blackened and broken. Its voice drips with pure hatred as it shrieks, %^BOLD%^%^GREEN%^'The Black Lord will not be so easily bested!'%^RESET%^");
//   message("info","%^BOLD%^%^CYAN%^A terrifying scream echoes in your ears suddenly, before it abruptly cuts off!%^RESET%^",users());
   tell_room(ETO,"%^BOLD%^%^BLACK%^A taloned fist rises as it makes a last attempt to purge its enemies with flame, but it fails to find a final vestige of strength and falls to the ground to lie motionless.%^RESET%^");
   ::die(TO);
}