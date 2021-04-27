#include <std.h>
inherit WEAPONLESS;
inherit SPELL;
void create(){
  ::create();
set_name("A shadowy creature");
  setenv("MIN", "$N forms in the room.");
  setenv("MOUT", "$N breaks apart and disappears as it heads $D.");
set_id(({"shadow","shadowy creature","creature","summoned monster","smon"}));
set_short("%^BOLD%^%^BLACK%^A shadowy creature%^RESET%^");
set_long("%^BOLD%^%^BLACK%^It is difficult to discern exactly what this creature is as it constantly shifts and changes form, moving in and out of the darkness with a swift ease that is unlike anything else known to these lands.  Dark eyes %^MAGENTA%^glow %^BLACK%^from within the depths of the shadows that form this being, and while it takes on a slightly humanoid form, there is no mistaking the elongated claws that twist their way out of the darkness.");
set_hd(35,2);
set_missChance(100);


set_max_hp(25);
  set_race("shadow");
  set_gender("male");
  set_body_type("humanoid");
set_ac(0);
set_exp(1);
set_property("magic",1);
  set_property("magic",1);
set_attacks_num(1);
   set_damage(3,3);
  add_limb("left claws","left hand",0,0,0);
  add_limb(" right claws","right hand",0,0,0);
  set_attack_limbs(({"right claws", "left claws"}));
  set_base_damage_type("slashing");
set_property("knock unconscious",1);
}
