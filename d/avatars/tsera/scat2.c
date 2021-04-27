#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
   set_name("%^BOLD%^%^BLACK%^A small black cat");
  setenv("MIN", "$N forms in the room.");
  setenv("MOUT", "$N breaks apart and disappears as it heads $D.");
set_id(({"shadow","shadowy creature","cat","demon","creature","summoned monster","smon"}));
set_short("%^BOLD%^%^BLACK%^A small black cat with %^GREEN%^m%^MAGENTA%^i%^GREEN%^sma%^MAGENTA%^t%^GREEN%^ch%^MAGENTA%^e%^GREEN%^d eyes%^RESET%^");
set_long("%^BOLD%^%^BLACK%^This is a small black cat with jet black fur.  It has one %^GREEN%^green eye %^BLACK%^and one %^MAGENTA%^violet eye. %^BOLD%^%^BLACK%^It appears calm, but something about it is just not quite right.  The shadows about it seem to coalesce and move, as if it had the power to move in and out of existence at a whim.");
   set_hd(40,2);
   set_max_hp(5000);
   set_hp(5000);
  set_race("shadow");
  set_gender("male");
  set_body_type("humanoid");
   set_ac(35);
   set_property("full attacks",1);
   set_exp(550000);
set_mob_magic_resistance("average");
set("agressive",5);
  set_property("magic",1);
   set_class("psion");
set_mlevel("psion",35);
set_guild_level("psion",35);
   set_spell_chance(35);
   set_spells(({"timeless body","timeless body","timeless body","wall of ectoplasm","breath of the black dragon","ultrablast","ultrablast","creation"}));
   set_damage(3,3);
   set_attacks_num(8);
      set_func_chance(75);
   set_funcs(({"sattack","kickass","sform","kickass","sattack"}));
  add_limb("left claws","left hand",0,0,0);
  add_limb(" right claws","right hand",0,0,0);
  set_attack_limbs(({"right claws", "left claws"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}
void sattack(object target) {
    tell_room(ETO,"%^BOLD%^%^BLACK%^The cats %^GREEN%^green eye %^BLACK%^begins to %^GREEN%^glow %^BLACK%^as it extends its %^WHITE%^claws %^BLACK%^and leaps at "+target->query_cap_name()+" and tears at "+target->query_possessive()+" chest",target);
tell_object(target, "%^BOLD%^%^BLACK%^The cats %^GREEN%^green eye %^BLACK%^begins to %^GREEN%^glow%^BLACK%^as it extends its claws and leaps at you, tearing at your chest!%^RESET%^");
target->do_damage("torso",roll_dice(3,10));
}

void kickass(object target) {
tell_room(ETO,"%^BOLD%^%^BLACK%^The cat levies a %^MAGENTA%^m%^GREEN%^i%^MAGENTA%^s%^GREEN%^m%^MAGENTA%^a%^GREEN%^tc%^MAGENTA%^h%^GREEN%^e%^MAGENTA%^d %^BLACK%^gaze at "+target->query_cap_name()+"%^BOLD%^%^BLACK%^, rendering "+target->query_objective()+" completely helpless.%^RESET%^",target);
tell_object(target, "%^BOLD%^%^BLACK%^The cat levies a %^MAGENTA%^m%^GREEN%^i%^MAGENTA%^s%^GREEN%^m%^MAGENTA%^a%^GREEN%^tc%^MAGENTA%^h%^GREEN%^e%^MAGENTA%^d %^BLACK%^gaze at you, causing you to freeze completely by the sheer force of its will!%^RESET%^");
   target->set_paralyzed(30,"%^BOLD%^%^MAGENTA%^You can still feel the cats gaze upon you!");  
}
void sform(object target) {
   object ob;
tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The cat meows and the shadows begin to swirl and take on a humanoid form!");
ob=new("/d/avatars/tsera/smon.c");
ob->move(environment(target));
}
void die(object ob) {
   tell_room(ETO,"%^BOLD%^%^BLACK%^The cat fades into the shadows and disappears!%^RESET%^");
TO->move("/d/shadowgate/void");
:: die(ob);
}
