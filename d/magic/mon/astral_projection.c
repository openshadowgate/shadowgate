#include <magic.h>
#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;

string cm(string str)
{
    return CRAYON_D->color_string(str,"very black");
}

void create(){
  ::create();

    set_name("astral projection");
    set_id(({"projection","astral projection",}));

    set_nat_weapon_type("slashing");
    set_gender("other");
    set_overall_ac(4);
    set_invis(1);
    set_hidden(1);

    set_alignment(5);

    command("message walks in");
    command("message walks $D");
}

void setup_projection(object caster, int clevel)
{
    int level;

    if(!objectp(caster))
        return;

    cast = caster;
    level = clevel;

    set_id(TO->query_id()+caster->query_id());
    set_race(caster->query_race());
    set_gender(caster->query_gender());

    set_stats("strength",caster->query_stats("strength"));
    set_stats("dexterity",caster->query_stats("dexterity"));
    set_stats("constitution",caster->query_stats("constitution"));
    set_stats("intelligence",caster->query_stats("intelligence"));
    set_stats("wisdom",caster->query_stats("wisdom"));
    set_stats("charisma",caster->query_stats("charisma"));

    set_max_hp(caster->query_max_hp());
    set_hp(query_max_hp());

    set_short(cm(strip_colors(caster->getWholeDescriptivePhrase())));
    set_long("%^BOLD%^%^BLACK%^"+strip_colors(caster->getWholeDescriptivePhrase() + " " +(string)caster->query_description())+"%^RESET%^");

    set_guild_level("fighter",clevel);
    set_level(clevel);
    set_hd(clevel,8);
    set_max_hp(clevel*16+100);
    set_hp(query_max_hp());
    set_overall_ac(4-clevel);
    set_attacks_num(clevel/10+1);
}

void die(object obj)
{
    cast->remove_property("has_elemental");
    TO->remove();
    ::die(obj);
    return;
}
