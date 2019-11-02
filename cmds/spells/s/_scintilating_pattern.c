#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("scintilating pattern");
    set_spell_level(([ "mage" : 8 ]));
    set_spell_sphere("illusion");
    set_sorc_bloodlines(({"accursed"}));
    set_syntax("cast CLASS scintilating pattern");
    set_damage_desc("mass confusion");
    set_description("This casting summons forward illusionary patter that briefly captivates and confuses enemies.");
    splash_spell(1);
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = caster->query_attackers();
    attackers = target_filter(attackers);

    tell_room(place,"%^MAGENTA%^%^BOLD%^Spirals of scintilating patterns appear in the air!%^RESET%^");
    if(!sizeof(attackers)){
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i]))
            continue;
        if(attackers[i]->query_level()<clevel)
        {
            tell_room(place,"%^MAGENTA%^Spirals capitvate "+attackers[i]+"!");
            "/std/magic/confusion"->confuse(caster,attackers[i]);
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
