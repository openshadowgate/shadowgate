// customised reverse alter self variant for plot use. N, 1/14.
#include <priest.h>
inherit SPELL;

void create() {
    	::create();     
    	set_spell_name("alter self feyri");
      set_spell_level(([ "mage": 2 ]));
    	set_spell_sphere("transmutation");
    	set_syntax("cast <classname> alter self feyri");
    	set_description("Help file goes hyar.");
    	set_verbal_comp();
    	set_somatic_comp();
	set_peace_needed(1);
      set_helpful_spell(1);
}

int preSpell(){
      object shape;
      if(objectp(shape = caster->query_property("shapeshifted")) || objectp(shape = caster->query_property("altered"))) {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
      }
      return 1;
}

string query_cast_string() {
	return "%^BOLD%^%^WHITE%^"+YOU+" closes "+MINE+" eyes and concentrates deeply.";
}

void spell_effect(int prof) {
      if (!objectp(caster)){
        TO->remove();
        return;
      }
      new("/std/races/shapeshifted_races/spell_alter_self_feyriplot.c")->init_shape(caster,""); 
      spell_successful();
      addSpellToCaster();
}

void dest_effect() {
      object shape;
	if(objectp(caster)) {
        if(objectp(shape = caster->query_property("altered"))) shape->reverse_shape(caster);
	}
    	::dest_effect();
    	if(objectp(TO)) TO->remove();
}
