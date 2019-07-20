#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#define POISONS ({ "wyvern_poison", "shadow_essence", "purple_worm_poison", "large_scorpion_venom", "giant_wasp_poison", "deathblade" })
#define PDIR "/d/common/obj/poisons/base/"

void create() {
    ::create();
    set_spell_name("poison");
    set_spell_level(([ "cleric" : 4, "druid" : 3, "blackguard" : 4 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS poison on TARGET");
    set_description("Blep");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect(){
    string poisonf;

    if(!objectp(caster) || !objectp(target))
    {
        dest_effect();
        return;
    }
    if(do_save(target,-4))
    {
        tell_object(caster,"%^GREEN%^"+target->QCN+"seems to be %^BOLD%^unaffected%^RESET%^%^GREEN%^ by your poisoning attemp!");
        TO->remove();
        return;
    }
    poisonf = PDIR+POISONS[random(sizeof(POISONS))];
    POISON_D->ApplyPoison(caster,poisonf,caster,"injury");
    dest_effect();
    return;
}

void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}

