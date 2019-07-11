#include <std.h>
#include <langs.h>
#include <daemons.h>
inherit SPELL;

int theProf;

void create() {
    ::create();
    set_spell_name("tongues");
    set_spell_level(([ "mage" : 3, "bard" : 2, "psion" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS tongues on TARGET");
    set_description("This will give the target the ability to understand, both read and write any language. This should not change the ability to teach the language.");
    set_verbal_comp();
    set_components(([
      "mage" : ([ "clay model ziggurat" : 1, ]),
    ]));
	set_helpful_spell(1);
    set_target_required(1);
}

string query_cast_string() {
   return caster->QCN+" starts to mouth out syllables.\n";
}

void spell_effect(int prof) {
    int i;
    string what, arg;
    object ob;

    theProf = prof;
    tell_object(caster,"%^BOLD%^You start to cast tongues.");
    tell_object(target,"%^BOLD%^You start to feel knowledge enter your mind that you lacked before.");
    spell_successful();

    for (i =0;i<sizeof(ALL_LANGS);i++) {
      if(member_array(ALL_LANGS[i],OLD_LANGS) == -1) target->add_lang_overload(ALL_LANGS[i],prof);
    }
    addSpellToCaster();
    spell_successful();
    caster->set_property("spelled",({TO}));
    call_out("dest_effect",clevel*16);
}

void dest_effect() {
    int i;
    if (objectp(target)) {
      for (i =0;i<sizeof(ALL_LANGS);i++) {
        if(member_array(ALL_LANGS[i],OLD_LANGS) == -1) target->subtract_lang_overload(ALL_LANGS[i],theProf);
      }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void do_spell_blowup(int prof){ MAGIC_D->fizzile(TO); }
