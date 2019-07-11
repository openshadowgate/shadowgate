#include <priest.h>
inherit SPELL;

int feattracker;

void create() {
    ::create();
    set_spell_name("reddopsi");
    set_spell_level(([ "psion" : 7 ]));
    set_spell_sphere("abjuration");
    set_discipline("kineticist");
    set_syntax("cast CLASS reddopsi");
    set_description("Talented kineticists can manipulate the area around "
       "them, turning aside spells. While they cannot stop area of effect "
       "spells are those that produce splash damage, they can prevent spells "
       "and powers that directly target them from landing. This spell does "
       "not stack with the 'reflection' or 'spell reflection' feats.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell(){
   if(member_array("spell reflection",(string*)caster->query_temporary_feats()) != -1) {
      tell_object(CASTER,"You are already under the influence of such an effect.");
      return 0;
   }
   return 1;
}

string query_cast_string() {
    return "%^RESET%^%^CYAN%^"+caster->QCN+" closes "+caster->QP+" eyes and focuses in silence.%^RESET%^";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    if (interactive(caster)) {
      tell_object(caster, "%^RESET%^%^MAGENTA%^You close your eyes, inhaling deeply "
         "as you bring into being a %^CYAN%^rune of protection%^MAGENTA%^. A faint "
         "hint of %^ORANGE%^saffron %^MAGENTA%^hangs in the air before being "
         "subsumed by the fragrance of %^BOLD%^%^CYAN%^ozone%^RESET%^%^MAGENTA%^.%^RESET%^");
    }
    tell_room(place,"%^RESET%^%^MAGENTA%^You smell %^ORANGE%^saffron %^MAGENTA%^followed "
       "by a strong scent of %^BOLD%^%^CYAN%^ozone%^RESET%^%^MAGENTA%^ as a %^CYAN%^rune "
       "%^MAGENTA%^appears by sweeps and loops in the air before "+caster->QCN+"!%^RESET%^",caster);
    if(member_array("spell reflection",(string*)caster->query_temporary_feats()) == -1) {
      caster->add_temporary_feat("spell reflection");
      feattracker = 1;
    }
    call_out("dest_effect", 1800 + (clevel * 10));
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    int i;

    if(objectp(CASTER)) {
      tell_object(caster,"%^MAGENTA%^You feel the protective spell ward fade from you.%^RESET%^");
      if(feattracker == 1) caster->remove_temporary_feat("spell reflection");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
