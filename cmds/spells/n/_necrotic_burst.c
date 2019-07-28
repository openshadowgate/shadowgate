#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string element;

void create() 
{
    ::create();
    set_spell_name("necrotic burst");
    set_spell_level(([ "mage" : 3,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS necrotic burst on TARGET");
    set_description("This spells represents necromancer's ability to channel negative energies. You will open a Small rip in fabric of the reality near your target and it will release burst of negative energy, directed at your enemies near it.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : (["drop of blood":1, "silver pin":1  ]), ]));
    set_save("reflex");
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

    if(do_save(target)) 
    {
        damage_targ(target, "torso", to_int(sdamage / 2),"negative energy");
    }
    else 
    {
        damage_targ(target, "torso", sdamage,"negative energy");
    }
    
    for(i=0;i<sizeof(foes);i++)
    {
        define_base_damage(0); //lazy re-roll
        if(!objectp(foes[i])) { continue; }
        if(!do_save(foes[i]))
        {
            tell_room(environment(foes[i]),"%^BLUE%^The fell tendrils caress "+foes[i]->QCN+"!",foes[i]);
            tell_object(foes[i],"%^BLUE%^The fell tendril caresses you!");
            damage_targ(foes[i], "torso", sdamage, "negative energy");
        }
        else
        {
            tell_room(environment(foes[i]),"%^BLUE%^"+foes[i]->QCN+" barely dodges fell energy tendrill!",foes[i]);
            tell_object(foes[i],"%^BLUE%^You barely dodge fell energy tendril!");
            damage_targ(foes[i], "torso", sdamage / 2, "negative energy");
        }
    }
    dest_effect();
}


void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
