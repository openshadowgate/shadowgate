#include <std.h>  
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int counter;
int flag;
object controller;

void create(){
    ::create();
    set_spell_name("animus blizzard");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS animus blizzard");
    set_description("This dark casting invokes a blizzard infused with negative energy in the area. The storms themselves pierce through flesh of casters enemies with fell cold, causing them to suffer greatly. Due to nature of this blizzard it can raise recently deceased creatures to the service of the caster, binding them temporarely to defend. Many faiths and cultures condemn this spell and alike powers as it serves caster's selfish, often evil, motives and frequent users of the spell are known to be inherently evil.

To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check your undead pool size use %^ORANGE%^<poolsize>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "bit of bone":2, "drop of blood":2, ]),
    ]));
    set_immunities( ({"cold"}) );
    set_save("fort");
    aoe_spell(1);
    evil_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(%^BLUE%^filled with horrid blizzard%^BLACK%^)%^RESET%^");
}

void spell_effect()
{
    tell_object(caster,"%^BLUE%^Briefly, you hear wails of the dead comming from behind the veil as you complete chanting, the the storm comes.%^RESET%^");
    tell_room(place,"%^BLUE%^Briefly, you hear horrid chorus of the dead as "+caster->QCN+" chants the spell, then the storm comes.%^RESET%^",caster);
    caster->set_property("spelled", ({TO}));
    counter = clevel;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack() 
{
    object *foes=({}),targ;
    int i;
    string limb;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }    

    if(!objectp(caster) || !objectp(place) || !present(caster,place)|| counter<0)
    {
        tell_object(caster,":"+counter);
        dest_effect();
        return;
    }

    message("info", "%^RESET%^%^BLUE%^Howling winds sweep across the place!", nearbyRoom(place,2));

    foes = all_living(place);
    foes = target_filter(foes);
    foes -= ({ caster });

    define_base_damage(0);
    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i])) continue;

        limb = targ->return_target_limb();
        if(do_save(targ,2)) {
          tell_object(targ,"%^BOLD%^%^BLUE%^You manage to endure some of the cold.");
          tell_room(place,"%^BLUE%^"+targ->QCN+" endures some of the cold.",({targ}));
          damage_targ(targ,limb,sdamage/2,"cold");
        }
        else {
          tell_object(targ,"%^BOLD%^%^BLUE%^Cold burns through your flesh!%^RESET%^");
          damage_targ(targ,limb,sdamage,"cold");
        }
    }

    if(present("undead_controller",caster)) {
        controller = present("undead_controller",caster);
    }
    else {
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }

    "/std/magic/raise_undead"->raise_ghosts(clevel, clevel/12, 3/2, caster, controller);

    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect()
{
    if(objectp(place))
        tell_object(place,"%^BOLD%^%^WHITE%^The wails and winds quiet down.");
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

