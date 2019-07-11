//_berserker.c
//Updated by ~Circe~ 5/14/13 to match current code and standards
//Backup is _berserker.circe
#include <spell.h>
#include <daemons.h>
#include <magic.h>
#include <std.h>

inherit SPELL;

int mybonus;

void create() {
    ::create();
    set_spell_name("berserker");
    set_spell_level(([ "cleric" : 7 ]));
    set_spell_sphere("combat");
    set_spell_domain("war");
    set_syntax("cast CLASS berserker");
    set_description("This spell will fill the caster with the rage of "
       "war, causing him to berserk madly.  The strength of the caster's "
       "deity and a blessed speed result in blind fighting and reckless "
       "fearlessness. This spell does not work in conjunction with similar "
       "magical effects, such as rally, rage, haste, transformation, dance "
       "of a thousand cuts, or fell flight.\n\n"
       "%^RED%^Note: %^RESET%^Being berserk means that "
       "you are maddened with rage.  This is %^BOLD%^%^RED%^*not*%^RESET%^ "
       "a state in which you can calmly participate in a normal conversation, "
       "undertake delicate tasks, solve problems, or pretty much do anything "
       "other than shout obscenities and kill things.\n\n%^BOLD%^%^RED%^Please "
       "bear in mind that when you use the spell you are also expected to "
       "roleplay it.%^RESET%^");
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string() 
{
   return "%^BOLD%^%^RED%^"+caster->QCN+" beats "+caster->QP+" chest repeatedly, shouts and jumps about madly.";
}

int preSpell() {
    if ((int)CASTER->query_property("raged") || (int)CASTER->query_property("transformed") || (int)caster->query_property("dance-of-cuts")) {
        tell_object(caster,"You are already under the effect of a spell to aid you in combat.");
        return 0;
    }
    // this gives extra attacks so should not stack with haste/fell flight. Already does not activate if rally is up so that needs blocked too.
    if ((int)CASTER->query_property("hasted") || pointerp(CASTER->query_property("rally"))) {
        tell_object(caster,"Similar magic already affects you.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    
    tell_room(place,"%^BOLD%^%^CYAN%^The madness of war and the need for victory "
        "overwhelm "+caster->QCN+".%^RESET%^",caster);
    tell_object(caster, "%^BOLD%^%^CYAN%^The madness of war and the need for victory overwhelm you.%^RESET%^");

    mybonus = (int)caster->query_class_level("cleric")/8;
    caster->add_attack_bonus(mybonus);
    caster->add_damage_bonus(mybonus);
    caster->set_property("berserked",1);
    caster->set_property("raged",1);
    addSpellToCaster();
    call_out("dest_effect",clevel*10);
    call_out("berserk",ROUND_LENGTH);
    caster->set_property("spelled", ({TO}) );

}

void berserk(){
    if (!objectp(caster)) return;
    if(sizeof(caster->query_attackers())){
        if(!random(4)){
           tell_object(caster,"%^BOLD%^%^RED%^You berserk with a wild rage.");
           tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" berserks madly.",caster);
        }
        caster->execute_attack();
/*        if(sizeof(target->query_classes()) == 1){
           caster->execute_attack(); 
        } */
// no longer needed, SC is not really a thing anymore
    }

    if ((!caster->is_in_combat()) && (!random(10))){
        caster->do_damage("torso",random(2)+1);
        tell_object(caster,"%^BOLD%^%^RED%^You hurt yourself in your lust for battle and victory.");
    }
    call_out("berserk",ROUND_LENGTH);
}

void dest_effect() {
   if(objectp(caster)) {
      if(caster->query_property("berserked")){	
         tell_object(caster,"%^CYAN%^The rage leaves you.%^RESET%^");
         tell_room(environment(caster),"%^CYAN%^The rage of "+
            "war lifts from "+caster->QCN+".",caster);
         caster->add_attack_bonus(-1*mybonus);
         caster->add_damage_bonus(-1*mybonus);
         caster->remove_property("berserked");
         caster->remove_property("raged");
         caster->remove_property_value("spelled", ({TO}) );
         caster->use_stamina(25);
         remove_call_out("berserk");
      }
   }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
