#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string element;

void create()
{
    ::create();
    set_spell_name("orb of the void");
    set_spell_level(([ "mage" : 8,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS orb of the void on TARGET");
    set_description("This spells represents necromancer's ability to channel negative energies. You will open a huge rip in fabric of the reality near your target and it will release burst of pure negative energy, directed at your enemies near it.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
}


string query_cast_string()
{
    tell_object(caster,"%^RED%^You dip silver pin into blood, and throw it into direction of "+target->QCN+", chanting rapidly.%^RESET%^");
    tell_room(place,"%^RED%^"+caster->QCN+" disp silver pin into vial of blood and throws it into direction of "+target->QCN+", chanting rapidly.%^RESET%^",caster);
    return "display";
}


void spell_effect(int prof)
{
    object *foes = ({}), foe;
    string YOU, HIM, tmp = "";
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    YOU = caster->QCN;
    HIM = target->QCN;

    spell_successful();

    if(!living(caster))
        foes = all_living(environment(target));
    else
        foes = caster->query_attackers();

    foes -= ({ target});
    foes = target_filter(foes);

    element = "fire";
    tell_room(place,"%^BOLD%^%^BLUE%^Silver pin makes a black rip in the air, and fell energy tendrils furiously rips from it!");

    damage_targ(target, "torso", sdamage,"negative energy");

    for(i=0;i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }
        tell_room(environment(foes[i]),"%^BLUE%^"+foes[i]->QCN+" barely dodges fell energy tendrill!",foes[i]);
        tell_object(foes[i],"%^BLUE%^You barely dodge fell energy tendril!");
        damage_targ(foes[i], "torso", sdamage / 2, "negative energy");
    }
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
