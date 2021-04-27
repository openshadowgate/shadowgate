// Aura of Radiance - selunite variant of aura of healing. For plot item. Nienne, 03/08.
#include <priest.h>
inherit SPELL;

int my_repeats;
string * my_party;
int first_execute = 0;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("aura of healing");
    set_spell_level(7);
    set_spell_type("priest");
    set_spell_sphere("healing");
    set_verbal_comp();
    set_somatic_comp();
    set_property("magic",1);
}

string query_cast_string() {
    return "%^CYAN%^"+YOU+" focusses upon the orb, beseeching the aid of Selune!%^RESET%^";
}

void spell_effect(int prof) {
  int clevel,rnd,i,spell_level;
  object * obarr;
  //  ::spell_effect(prof);
  clevel = CLEVEL;
  obarr = PARTY_D->query_party_members(caster->query_party());
  my_party = ({});
  // for (i=0;i<sizeof(obarr);i++) my_party += ({obarr[i]->query_true_name()});
  if (pointerp(obarr))
  my_party = obarr->query_true_name();
  //tell_object(query_caster(),identify(my_party));
  //  write(identify(obarr));
  if (!sizeof(my_party)) my_party = ({ CASTER });
  tell_room(environment(caster),"%^CYAN%^A gentle %^BOLD%^%^WHITE%^radiance %^RESET%^%^CYAN%^grows around "+caster->query_cap_name()+"!",({ caster }) );
  tell_object(caster,"%^CYAN%^A gentle %^BOLD%^%^WHITE%^radiance %^RESET%^%^CYAN%^grows around you!");

  addSpellToCaster();
  spell_successful();
  execute_attack();
//  environment(CASTER)->addObjectToCombatCycle(TO,1);
}

void execute_attack() {
  int clevel, rnd, spell_level;
  int loop;
  object cast, targ, place;

  if (!first_execute) {
    first_execute++;
    ::execute_attack();
    return;
  }
  cast = CASTER;
  clevel = CLEVEL;
  place = environment(CASTER);
  //  tell_object(CASTER,identify(place));
  loop = sizeof(my_party);
  tell_room(environment(cast),"%^BOLD%^%^CYAN%^A pulse of soft light radiates out from "+cast->query_cap_name()+"!",({ cast }) );
  tell_object(cast,"%^BOLD%^%^CYAN%^A pulse of soft light radiates out from your body!");
  while(loop) {
    //    if (find_player("garrett"))
    //      tell_object(find_player("garrett"),identify(my_party[loop]) );
    targ = present( my_party[--loop], place);
    //    if (find_player("garrett"))
    //      tell_object(find_player("garrett"),identify(cast));
    if (!objectp(targ))
      continue;
    if (cast != targ)
      tell_object(cast,"%^CYAN%^The gentle touch of Selune invigorates "+targ->query_cap_name()+"!");
    tell_object(targ,"%^CYAN%^The magical energy adds a bit of strength to you.");
    if (targ->query_property("berserked")) {
      tell_object(environment(cast),"The berserker rage fights off the healing.");
    } else {
      rnd = (int)CLEVEL / 6;
      rnd = roll_dice(rnd,8) + rnd;
      targ->do_damage(targ->query_random_limb(),-1*rnd);
    }
  }
  if (++my_repeats > ((int) CLEVEL / 5) )
    dest_effect();
  else
    place->addObjectToCombatCycle(TO,1);
}

void dest_effect() {
    ::dest_effect();
    tell_room(environment(caster),"%^BOLD%^%^CYAN%^The brilliant aura fades again.");
    TO->remove();
}

int help(string str) {
    write(
@PATOR
Spell  : Aura of Radiance
Level  : 7th Level
Sphere : Healing
Deity  : All
Syntax : chant aura of radiance

This spell invokes Selune's healing aid upon party members.

The amount and length of the spell are dependent on the 
strength of the caster.  The party members must remain 
with the caster to receive the effect.

PATOR
);
    return 1;
}
