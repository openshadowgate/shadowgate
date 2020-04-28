//caustic eruption, based on resonating word, differs from SRD to be single target
#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void second_hit();
void last_hit();

void create(){
    ::create();
    set_author("odin");
    set_spell_name("caustic eruption");
    set_spell_level((["mage" : 7 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS caustic eruption on TARGET");
    set_damage_desc("acid");
    set_description("You conjure an eruption of acid around a chosen target, causing damage. On your turn in each of the next two rounds, your target takes additional acid damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^%^GREEN%^You give voice to a word of conjuration, sending a faint tremor through the air.");
   tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" gives voice to a word of conjuration, and you feel a faint tremor "
"touch the air around you.",caster);
   return "display";
}

void spell_effect(int prof){

   if (!present(target,environment(caster))) {
       tell_object(caster,"%^BOLD%^%^WHITE%^Your target is not in this area.");
       TO->remove();
       return;
   }

   tell_object(target,"%^BOLD%^%^GREEN%^Acid erupts and clings to your skin!%^RESET%^");
   tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+"'s skin burns as "+target->QS+" is engulfed in acid!%^RESET%^",target);

   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "acid");
   else {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "acid");
   }
   spell_successful();
   spell_kill(target,caster);
   if (!target) dest_effect();
   else call_out("second_hit",ROUND_LENGTH);
}

void second_hit() {
    define_base_damage(-1);
   if(!objectp(target)) {
       dest_effect();
       return;
   }
   tell_object(target,"%^BOLD%^%^GREEN%^Another surge of pain runs through you as the acid continues to burn through your limbs.%^RESET%^");
   tell_object(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" trembles as the acid continues to burn "+target->QP+" frame.%^RESET%^",target);
   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "acid");
   else {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "acid");
   }
   if (!target && objectp(TO)) {
       dest_effect();
       return;
   }
   call_out("last_hit", ROUND_LENGTH);
}

void last_hit() {
   define_base_damage(-3);
   if(!objectp(target)) {
       dest_effect();
       return;
   }
   tell_object(target,"%^BOLD%^%^GREEN%^Caustic acid continues to bubble on your skin, sending a wracking pain through you before it finally fades!%^RESET%^");
   tell_object(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" is shaken by a wracking pain, before finally the acid subsides.%^RESET%^",target);
   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "acid");
   else {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "acid");
   }
   dest_effect();
}

void dest_effect(){
    if (find_call_out("second_hit") != -1) remove_call_out("second_hit");
    if (find_call_out("last_hit") != -1) remove_call_out("last_hit");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
