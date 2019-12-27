#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

void create(){
  ::create();

    set_name("unseen servant");
    set_id(({"servant","unseen servant","humanoid","whispy humanoid"}));
    set_short("%^CYAN%^a whispy humanoid%^RESET%^");
    set_long("%^CYAN%^You barely see an outline of humanoid figure.%^RESET%^");
    set_hd(4,1);
    set_hp(query_hd()*8);
    set_stats("strength",20);
    set_stats("intelligence",8);
    set_stats("dexterity",20);
    set_race("servant");
    add_limb("torso","torso",50,0,2);
    set_attack_limbs(({"torso"}));
    set_damage(2,10);
    set_attacks_num(0);
    set_nat_weapon_type("bludgeon");
    set_gender("other");
    set_invis();
    set_overall_ac(4);

    set_alignment(5);

    command("message floats in.");
    command("message floats $D.");
}

void setup_servant(object caster, int clevel)
{
    int level;
    if(!objectp(caster)) { return; }

    cast = caster;

    level = clevel;

    set_guild_level("fighter",clevel);
    set_level(clevel);
    set_hd(clevel,4);
    set_max_hp(clevel*4+100);
    set_hp(query_max_hp());
    set_overall_ac(10-clevel);
}

void die(object obj)
{
    cast->remove_property("unseen_servant");
    ::die(obj);
    return;
}
