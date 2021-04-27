#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit WEAPONLESS;

int rath, active;
object *fighterz;

void create() {
   ::create();
   set_name("Zirrathyrria");
   set_id(({ "zirrathyrria","dragon","shadow dragon","ancient dragon","ancient shadow dragon"}));
   set_short("%^RESET%^%^MAGENTA%^Zirrathyrria, an ancient shadow dragon%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This male specimen is deceptive upon the eye, at once appearing of massive size and "
"yet not.  Of course, the myriad shadows enshrouding his already hazy form make it impossible to tell exactly where his "
"tail or wingspan end, and makes it hard to distinguish his movements before they happen.  His head and neck are more "
"angular and ridged than many other draconic species, with a series of back-swept spines that run from his brow ridges "
"all the way along his neck to her shoulders.  Narrow eyes that gleam with a sharp intellect lie beneath that spined, "
"bony brow-ridge, and lower again opens a fanged maw in a rictus grin, filled with sharp teeth and exhaling writhing "
"tendrils of shadow.  Above him sweeps what may be a massive span of wings, impossible to be sure as the leathery hide "
"and scales are translucent and lost easily to sight in the dark.  Certainly from anything but close range, the beast "
"seems nothing more than a forboding, shifting mass of shadow...%^RESET%^");
   set_race("dragon");
   set_gender("male");
   set_body_type("dragon");
   set_alignment(9);
   set_size(4);
   set_exp(100000);
   add_limb("teeth","head",0,0,0);
   set_attack_limbs( ({"teeth","left foreclaw","right foreclaw"}) );
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_damage(3,10);
   set_hd(50,12);
   set_class("fighter");
   set_mlevel("fighter",50);
   set_guild_level("fighter",50);
   set_class("cleric");
   set_mlevel("cleric",50);
   set_guild_level("cleric",50);
   set_max_hp(10000);
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
   set_funcs(({"earthtomud","earthtomud","teeth_fun","teeth_fun","breath_fun","breath_fun","claws_fun","claws_fun"}));
   set_func_chance(85);
   set_property("swarm",1);
   rath = 0;
   active = 0;
}

void init() {
   string whoami;
   ::init();
   add_action("no_cast","toss");
   add_action("no_cast","throw");
   add_action("no_cast","caress");
   whoami=TP->query_name();
   if(!TP->query_true_invis()) {
     TO->add_attacker(TP);
     TP->add_attacker(TO);
   }
}

int no_cast(string str) {
   tell_object(TP,"%^BOLD%^%^BLUE%^The dragon's spined maw swings towards you through a haze of shadow, and the beast "
"lashes out with a foreleg to knock you sprawling before you can get close enough for that!%^RESET%^");
   TP->set_paralyzed(25,"%^BOLD%^%^CYAN%^You're still trying to get to your feet!");
   return 1;
}

void breath_fun(object target) {
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^GREEN%^The dragon lifts its head, and unleashes a chilling breath like %^BOLD%^%^BLACK%^"
"roi%^RESET%^li%^BOLD%^%^BLACK%^ng %^RESET%^%^GREEN%^smoke that washes over you!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   TO->set_property("magic",1);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     tell_object(vars[i],"%^BOLD%^%^GREEN%^You're momentarily choked by the writhing shadows as you feel a horrific "
"tugging at your soul that nearly brings you to your knees!  Yet when it passes, you find you can still stand and your "
"strength is still your own...%^RESET%^");
     vars[i]->do_damage("torso",150+random(50));
   }
   TO->remove_property("magic");
   return;
}

void earthtomud(object target){
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^ORANGE%^The dragon moves with unexpected %^GREEN%^s%^BOLD%^p%^RESET%^%^GREEN%^eed %^ORANGE%^"
"for such a large beast, swinging its tail in a wide arc that knocks you from your feet!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal",FILTERS_D);
   for(i=0;i<sizeof(vars);i++){
     if(vars[i] == TO) continue;
     if((string)vars[i]->query_is_mount()) continue; //dun kill the poor knights' horses
     vars[i]->set_tripped(4,"%^YELLOW%^You're trying to pick yourself back up!%^RESET%^",ROUND_LENGTH);
     vars[i]->do_damage("torso",50+random(50));
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
   tell_object(target,"%^BOLD%^%^RED%^There is no warning of the dragon's movements, shrouded as they are by %^BOLD%^"
"%^BLACK%^shad%^RESET%^ow%^BOLD%^%^BLACK%^s%^RED%^, and suddenly it lashes out with a wing to knock you into the nearest "
"stone wall, hitting with an impact that jars you from head to toe!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^RED%^There is no warning of the dragon's movements, shrouded as they are by %^BOLD%^"
"%^BLACK%^shad%^RESET%^ow%^BOLD%^%^BLACK%^s%^RED%^, and suddenly it lashes out with a wing to knock "+target->QCN+" into "
"the nearest stone wall, hitting with an impact that seems to leave "+target->QO+" momentarily shaken!%^RESET%^",target);
   TO->set_property("magic",1);
   target->do_damage("torso",random(75)+150);
   TO->remove_property("magic");
}

void claws_fun(object target) {
   object *vars;
   int i;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   tell_room(ETO,"%^MAGENTA%^The shadows themselves leap forward at a sweeping motion of the dragon's spined maw, "
"sh%^BOLD%^r%^RESET%^%^MAGENTA%^iek%^BOLD%^i%^RESET%^%^MAGENTA%^ng like the damned and racing around the cavern like "
"living creatures, ripping through anything they come into contact with!%^RESET%^");
   for(i = 0;i<6;i++) {
     target = vars[random(sizeof(vars))];
     if(!objectp(target)) continue;
     if(!interactive(target)) continue;
     switch(random(4)) {
       case 0:
         tell_object(target,"%^RED%^A shadow rends you horribly with its claws!%^RESET%^");
       break;
       case 1:
         tell_object(target,"%^RED%^A patch of darkness sweeps past you, tearing your flesh to shreds!%^RESET%^");
       break;
       case 2:
         tell_object(target,"%^RED%^Shadows rake you with vicious claws that coalesc as if from nothing!%^RESET%^");
       break;
       default:
         tell_object(target,"%^RED%^Shadowy, razor-sharp fangs pierce your skin!%^RESET%^");
       break;
     }
     target->do_damage("torso",random(25)+50);
   }
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if((int)TO->query_hp() < (int)TO->query_max_hp()) TO->add_hp(random(60)+60);
}

void die(object ob){
   object lewt;
   int i;
   tell_room(ETO,"%^ORANGE%^A %^BOLD%^%^BLACK%^sh%^WHITE%^r%^YELLOW%^i%^BLACK%^ek %^RED%^of agony goes up from around the "
"cavern, as if coming from each shadowed corner at once.  The dragon's head rolls back, whisps of roiling smoke hissing "
"from between its teeth as it stumbles, once, and then crashes to the floor with an %^RED%^i%^BOLD%^m%^RESET%^%^RED%^pact "
"%^ORANGE%^that shakes the cavern walls.%^RESET%^");
   tell_room(ETO,"%^RED%^A second or two passes, and the body suddenly becomes insubstancial, dissipating like %^BLUE%^"
"smoke %^RED%^into the air and vanishing before your eyes.%^RESET%^");
   tell_room(ETO,"%^MAGENTA%^The dissipating shadows unveil a small pile of treasure near the distant end of the cavern, "
"previously hidden by the darkness.%^RESET%^");
   lewt = new("/std/obj/coins");
   lewt->add_money("gold",random(9999)+9999);
   lewt->move(ETO);
   for(i=0;i<7;i++) { new("/d/underdark/lower/dragon/obj/gemstone")->move(ETO); }
   for(i=0;i<2;i++) { new("/d/underdark/lower/dragon/obj/statue")->move(ETO); }
   new("/d/underdark/lower/dragon/obj/painting")->move(ETO);
   new("/d/avatars/nienne/dragontome")->move(ETO);
   new("/d/avatars/nienne/moonorb")->move(ETO);
   new("/d/avatars/nienne/invisring")->move(ETO);
   new("/d/avatars/nienne/messmedallion")->move(ETO);
   new("/d/avatars/nienne/tymoraanklet")->move(ETO);
   new("/d/avatars/nienne/spellorb")->move(ETO);
   TO->remove();
}