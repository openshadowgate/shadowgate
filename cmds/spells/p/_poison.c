#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#define POISONS ({ "wyvern_poison", "shadow_essence", "purple_worm_poison", "large_scorpion_venom", "giant_wasp_poison", "deathblade" }
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
    object poison;

    if(do_save(target,-4))
    {
        tell_object(caster,"%^GREEN%^"+target->QCN+"seems to be %^BOLD%^unaffected%^RESET%^%^GREEN%^ by your poisoning attemp!");
        TO->remove();
        return;
    }
    poison = new(PDIR+POISONS[random(sizeof(POISONS))]+".c");
    if(!objectp(poison))
    {
        tell_object(caster,"Something seems to be wrong with your poison.");
        TO->remove();
        return;
    }
    
}


