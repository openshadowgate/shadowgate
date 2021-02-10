#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;
int prevlight;


void create()
{
    ::create();
    set_spell_name("celestial brilliance");
    set_spell_level(([ "innate" : 7 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate celestial brilliance");
    set_damage_desc("AOE Divine damage over time, 25% more damage vs undead");
    set_description("You channel energy directly from the celestial realms, unleashing a torrent of divine energy into the area and creating a celestial dawn. The room becomes brighter and all enemies take divine damage over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^%^BLUE%^(%^BOLD%^%^WHITE%^engulfed in white light%^RESET%^%^BLUE%^)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^RESET%^%^WHITE%^As "+caster->QCN+" voices a few syllables, the place becomes extremely bright.");
    return "display";
}

void spell_effect(int prof)
{
    tell_room(place,"%^BOLD%^%^WHITE%^Brilliant divine energy brightens the area!");
    prevlight=place->query_light();
    if(prevlight<1)
        place->set_light(1);
    counter = clevel * 2;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *foes=({}),targ;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(place) || !present(caster,place)|| counter<0)
    {
        dest_effect();
        return;
    }

    message("info", "%^BOLD%^%^WHITE%^The incandescent brightness fills the area!%^RESET%^", place);
    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(0);//reroll each turn
    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i]))
            continue;
        if(!do_save(foes[i],0))
        {
            "/std/effect/status/dazzled"->apply_effect(foes[i],1);
        }
        tell_object(targ,"%^BOLD%^%^WHITE%^The brightness threatens to dazzle you!");
        
        if(foes[i]->is_undead())
            sdamage = (sdamage * 5) / 4;
        damage_targ(targ,targ->return_target_limb(),sdamage,"divine");
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place))
    {
        place->set_light(prevlight);
        tell_object(place,"%^BOLD%^%^BLUE%^The brightness recedes, and the place becomes a bit cooler.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
