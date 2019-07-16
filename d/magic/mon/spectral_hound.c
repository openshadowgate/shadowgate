#include <std.h>
#include <magic.h>
inherit WEAPONLESS;

object caster;

void create(){
  ::create();
  set_name("spectral_hound");
  set_id(({"hound","spectral hound","faithful hound"}));
  set_short("%^RESET%^%^CYAN%^Spectral hound%^RESET%^");
  set_long("%^RESET%^%^CYAN%^This hound appears to be translucent, but otherwise normal dog. Its eyes are faithfully watching the place. ");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_gender("male");
  set_race("dog");
  set_body_type("quadruped");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_property("magic resistance",99);
  set_attacks_num(1);
  set_damage(1,3);
  set_invis();
  set_property("no detect",1);
  set_attack_limbs(({"torso"}));
  set_nat_weapon_type("slashing");
  set_property("knock unconscious",1);
}

void setup(invoker,clevel)
{
    caster = invoker;
    set_max_hp(clevel*30);
    set_hp(clevel*30);
    set_damage(clevel,2);
    call_out("be_doggy",ROUND_LENGTH);
}

void bark()
{
    
}

void be_doggy()
{
    
}

void remove_hound()
{
    if(objectp(caster) &&
       objectp(ETO))
    {
        tell_object(caster,"%^CYAN%^You concentration releases as your hound fades%^RESET%^");
    }
    destruct(TO);
}


