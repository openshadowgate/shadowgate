#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int theProf;

void create() {
    ::create();
    set_spell_name("tongues");
    set_spell_level(([ "mage" : 3, "bard" : 2, "psion" : 2, "inquisitor": 2, "cleric":3]));
    set_spell_sphere("alteration");
    set_domains("knowledge");
    set_mystery("lore");
    set_syntax("cast CLASS tongues on TARGET");
    set_description("This will give the target the ability to understand, any mortal language. You will be able to speak the way you'll be understood by any being. This will not alter you knowledge and won't allow you to teach or write in languages you don't know.");
    set_verbal_comp();
	set_helpful_spell(1);
    set_target_required(1);
}

int preSpell()
{
    if(target->query_property("verstandnis"))
    {
        tell_object(caster,"The target is already under the influence of similar magic");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
   return caster->QCN+" starts to mouth out syllables.\n";
}

void spell_effect(int prof) {
    int i;
    string what, arg;
    object ob;

    tell_object(caster,"%^BOLD%^You imbue "+target->QCN+" with knowledge to understand all tongues.");
    tell_object(target,"%^BOLD%^You start to feel knowledge enter your mind that you lacked before.");

    target->set_property("verstandnis",1);

    addSpellToCaster();
    spell_successful();
    caster->set_property("spelled",({TO}));
    call_out("dest_effect",(clevel*5*ROUND_LENGTH));
}

void dest_effect() {
    int i;
    if (objectp(target)) {
        target->set_property("verstandnis",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void do_spell_blowup(int prof){ MAGIC_D->fizzile(TO); }
