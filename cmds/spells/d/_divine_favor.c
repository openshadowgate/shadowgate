#include <priest.h>
#include <daemons.h>
inherit SPELL;

object feattracker1, feattracker2;

void create() {
    ::create();
    set_spell_name("divine favor");
    set_spell_level(([ "paladin" : 3, "inquisitor":1,]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS divine favor");
    set_description("Calling upon the strength of their patron, a holy knight can gain a bonus to attack and damage rolls.  This spell does not stack with fighter feats for bonus attack and damage rolls.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell(){
   if(member_array("weapon focus",(string*)caster->query_temporary_feats()) != -1 && member_array("weapon specialization",(string*)caster->query_temporary_feats()) != -1) {
      tell_object(CASTER,"You are already under the influence of a similar effect.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^CYAN%^"+caster->QCN+" clenches "+caster->QP+" fists and raises "+caster->QP+" eyes to the heavens.";
}

void spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^Heat floods through your body as the power of your god infuses you!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s body seems to take on a faint radiance!",caster);
    }
    if(member_array("weapon focus",(string*)caster->query_temporary_feats()) == -1) {
      caster->add_temporary_feat("weapon focus");
      feattracker1 = 1;
    }
    if(member_array("weapon specialization",(string*)caster->query_temporary_feats()) == -1) {
      caster->add_temporary_feat("weapon specialization");
      feattracker2 = 1;
    }
    spell_successful();
    addSpellToCaster();
    call_out("dest_effect",1000+((ROUND_LENGTH*5)*clevel));
}

void dest_effect() {
    if(objectp(CASTER)) {
      tell_object(caster,"%^BOLD%^%^CYAN%^The blazing inspiration of your deity fades from you.%^RESET%^");
      if(feattracker1 == 1) caster->remove_temporary_feat("weapon focus");
      if(feattracker2 == 1) caster->remove_temporary_feat("weapon specialization");
    }
     ::dest_effect();
    if(objectp(TO)) TO->remove();

}
