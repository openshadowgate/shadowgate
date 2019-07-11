#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
object cont, myweapon;

void create() {
    ::create();
    set_spell_name("empower weapon");
    set_spell_level(([ "psywarrior" : 5 ]));
    set_syntax("cast CLASS empower weapon on <weapon> as <power name> | <arguments to the power>");
    set_description("NOTE: This power may only be cast into a weapon and "
       "will not function without that weapon in your "
       "inventory. Also, the weapon can store only helpful powers, not those "
       "used for attacks. If you find that a particular power cannot be used "
       "when you think it should be, please bug report it.\n\nThis power allows "
       "the psionic character to hold a power in reserve "
       "to be called upon at a later time by typing <release>.  If the power reserved "
       "normally requires a target, that target will automatically be the manifester.  "
       "If you need to add arguments to the reserved power, you must add them at the "
       "time of manifesting empower weapon.\n\nexample of usage: manifest empower "
       "weapon on sword as dimension door | home\n\nNOTE: "
       "You do need the | symbol if the power requires arguments such as a location.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_casting_time(2);
}

int preSpell() {
   string spell, weapon, args;
   if(!ARG){
     tell_object(caster,"Please see the help file for information on how to cast this power.");
     return 0;
   }
   if(sscanf(ARG,"%s as %s | %s",weapon,spell,args) != 3 && sscanf(ARG,"%s as %s",weapon,spell) != 2) {
      tell_object(caster,"You must specify at least a weapon and a power to use Empower Weapon. Please see the help file for syntax.");
      return 0;
   }
   if(!myweapon = present(weapon,caster)){
      tell_object(caster,"You do not see any "+weapon+" here!");
      return 0;
   }
   if(!myweapon->is_weapon()){
      tell_object(caster,"That "+weapon+" is not a weapon!");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {
   string spell, args, *comp_names, orgSpell, newtype, weapon, *mastered;
   int x, spellProf;
   object spellObj;
  
   if (!ARG) {
      dest_effect();
      return;
   }

   if(sscanf(ARG,"%s as %s | %s",weapon,spell,args) != 3){
      args = 0;
      if(sscanf(ARG,"%s as %s",weapon,spell) != 2) {
         tell_object(caster,"You must specify at least a weapon and a power "
            "to use Empower Weapon. Please see the help file for syntax.");
         dest_effect();
         return;
      }
   }
   if(!myweapon = present(weapon,caster)){
      tell_object(caster,"You don't see any "+weapon+" here!");
      dest_effect();
      return;
   }
   if(!myweapon->is_weapon()){
      tell_object(caster,"That "+weapon+" is not a weapon!");
      dest_effect();
      return;
   }
   mastered = ({});
   mastered = caster->query_mastered_spells();
   if(FEATS_D->usable_feat(caster,"expanded knowledge 1")){
      mastered += ({caster->query("expanded_knowledge_1")});
   }
   if(FEATS_D->usable_feat(caster,"expanded knowledge 2")){
      mastered += ({caster->query("expanded_knowledge_2")});
   }
   if(FEATS_D->usable_feat(caster,"expanded knowledge 3")){
      mastered += ({caster->query("expanded_knowledge_3")});
   }
   if(member_array(spell,mastered) == -1){
      tell_object(caster,"You do not know any power called "+spell+"!");
      dest_effect();
      return;
   }

   orgSpell = spell;
   spell = replace_string(spell," ","_");
   spell = "/cmds/spells/"+spell[0..0]+"/_"+spell;
   if (!file_exists(spell+".c")) {
      tell_object(caster,"That power does not exist.");
      dest_effect();
      return;
   }

   if (spell->query_spell_level(spell_type) > 4) {
      tell_object(caster,"That power's might is too great to be held by this one.");
      dest_effect();
      return;
   }

   if(!spell->query_helpful()){
      tell_object(caster,"Only helpful powers can be stored in your weapon!");
      dest_effect();
      return;
   }

   if (stringp(args) && !spell->query_arg_needed()) {
      args = 0;
   }
   newtype = spell_type;

   if (spell->query_components(newtype)) comp_names = keys(spell->query_components(newtype));
   for (x=0;x<sizeof(comp_names);x++) {
      if ((int)present("compx",caster)->query_comp(comp_names[x]) == 0) {
         tell_player(caster, "You do not have the required components to cast this spell!\n");
         dest_effect();
         return;
      }
   }
   for (x=0;x<sizeof(comp_names);x++) {
      if (!components) break;
         present("compx", caster)->use_comp(comp_names[x],components[comp_names[x]]);
   }
   if (present("remotexoli",caster)) {
      present("remotexoli",caster)->remove(0);
   }
   spellObj = new(spell);
   spellObj->set_caster(caster);
   spellProf = spellObj->calculate_prof_state();
   cont = new("/d/magic/obj/empowerer");
  
   cont->set_prof((prof+spellProf)/2);
   cont->set_spell(spell);
   cont->set_args(args);
   cont->set_myweapon(myweapon);
   cont->move(caster);
   myweapon->set_property("empowered_weapon",1);
   tell_room(place,"%^BOLD%^%^BLUE%^As "+caster->QCN+" concentrates on "
      ""+caster->QP+" "+weapon+", it pulses with light before fading "
      "once more.%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^BLUE%^As you concentrate on your "+weapon+", "
      "it pulses with light before fading once more.%^RESET%^");
   tell_object(caster,"Type <release> to activate.");
   set_heart_beat(15);
   addSpellToCaster();
   spell_successful();
   caster->set_property("spelled",({TO}));
}

void dest_effect(){
  if (objectp(cont)) {
    tell_room(environment(caster),"%^BOLD%^%^CYAN%^There is the "+
       "crackling sound of static before all is quiet.");
    cont->remove(0);
  }
  if (!objectp(caster)) {
     if(objectp(TO)) TO->remove();
     return;
  }
  if(objectp(myweapon)){
     myweapon->remove_property("empowered_weapon");
  }
  caster->remove_property_value("spelled", ({TO}) );
  removeSpellFromCaster();
  ::dest_effect();
  if(objectp(TO)) TO->remove();
}

void heart_beat() {
  if (!objectp(cont))
    TO->dest_effect();
}
