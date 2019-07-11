//Based on Tongues - Cythera 6/05
#include <std.h>
#include <langs.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;
int theProf;

create() {
    ::create();
    set_spell_name("comprehend languages");
    set_spell_level(([ "cleric" : 3 ]));
    set_spell_sphere("divination");
    set_spell_domain("knowledge");
    set_syntax("cast CLASS comprehend languages on TARGET");
    set_description("This blessing allows the priest to call on the vast knowledge of their god.  The blessing comes in "
"the form of a greater understanding of languages");
    set_verbal_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell() 
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if(target->query_property("langed")) 
    {
        tell_object(caster,"%^BOLD%^Your target is already blessed with the knowledge of languages.");
        return 0;
    }
    return 1;
}

query_cast_string() 
{
    tell_object(caster,"%^YELLOW%^You begin to murmur a sagacious prayer.");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" begins to murmur a sagacious prayer.",caster);
    return "display";
}

void spell_effect(int prof) 
{
	int i;
	string what,arg;
	object ob;
	theProf = prof;

    tell_object(caster,"%^YELLOW%^You call to your god, seeking knowledge and wisdom.");
    tell_object(target,"%^YELLOW%^You feel knowledge upon you, filling your mind a "
        "greater understanding of languages.");

    spell_successful();    
    for (i =0;i<sizeof(ALL_LANGS);i++) {
      if(member_array(ALL_LANGS[i],OLD_LANGS) == -1) {
        target->add_lang_overload(ALL_LANGS[i],prof);
 	  target->set_property("langed",1);
	  target->set_property("spelled", ({TO}) );
      }
    }
    addSpellToCaster();
    caster->set_property("spelled",({TO}));
    call_out("dest_effect",clevel*16);
}

void dest_effect() {
    int i;
    if (objectp(target)) {
      for (i=0;i<sizeof(ALL_LANGS);i++) { 
        if(member_array(ALL_LANGS[i],OLD_LANGS) == -1) {
          target->subtract_lang_overload(ALL_LANGS[i],theProf);
	    target->remove_property("langed");
        }
      }
    }  
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}