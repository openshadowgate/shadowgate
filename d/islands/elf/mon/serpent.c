#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("translucent serpent");
  setenv("MIN", "$N floats in.");
  setenv("MOUT", "$N float off to the $D.");
  set_id(({"serpent","translucent serpent","dragon"}));
  set_short("%^RESET%^%^GREEN%^tra%^BOLD%^n%^RESET%^%^GREEN%^slucent se%^BOLD%^r%^RESET%^%^GREEN%^pent%^RESET%^");
  set_long("This gold serpent is about seven feet in length."+
  "  It looks like a smaller version of a green dragon.   It's"+
  " ethereal nature allows one to see right through it.  The"+
  " creature looks fearsome.");
  set_hd(45,5);
  set_max_hp(200);
  set_hp(200);
  set_gender("female");
  set_race("serpent");
  set_body_type("dragon");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_property("weapon resistance",1);
  set_attacks_num(1);
  set_damage(2,8);
  set_attack_limbs( ({"teeth","tail","left foreclaw","right foreclaw"}) );
  set_base_damage_type("slashing");
  set_base_damage_type("slashing"); 
  set_property("knock unconscious",1);
}
