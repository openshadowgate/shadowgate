#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create() {
  ::create();
  set_spell_name("greater teleport");
  set_spell_level(([ "mage" : 7 ]));
  set_spell_sphere("conjuration_summoning");
  set_syntax("cast CLASS greater teleport on LOCATION");
  set_description("This greater version of teleport allow mage to travel to her destination, without change to arrive off target, bringing all her followers with her.

%^BOLD%^%^RED%^See also:%^RESET%^ recall, remember, unremember");
  set_verbal_comp();
  set_somatic_comp();
  set_arg_needed();
  set_helpful_spell(1);
  set_peace_needed(1);
}

string query_cast_string() {
  tell_room(place,"%^CYAN%^"+caster->QCN+" raises hand up in the air, blue light forms in it.%^RESET%^",caster);
  return "display";
}

void spell_effect(int prof) {
  object *party, *presentparty, *followers, endplace;
  int i, healed;
    
  spell_successful();

  if (!objectp(caster)) {
    dest_effect();
    return;
  }
  if (caster->query_ghost())
  {
    dest_effect();
    return;
  }

  if (sizeof(caster->query_attackers()))
  {
    tell_object(caster,"Combat distracts you from your spell!");
    tell_room(place,caster->QCN+" is distracted by combat, spell fails.");
    dest_effect();
    return;
  }
    
  presentparty = ({});
  if(!sizeof(presentparty)) 
  { 
    followers = caster->query_followers();
    if(sizeof(followers))
    {
      for(i=0;i<sizeof(followers);i++)
      {
        if(!objectp(followers[i]))
          continue;
        if(!present(followers[i],environment(TP)))
          continue;
        presentparty += ({followers[i]});
      }
    }
    tell_object(caster,"%^CYAN%^You open your hand, blinding light forces you to close eyes, and when you open them you appear somewhere else.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+" disappears in a flash of blinding light!%^RESET%^", caster);
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" engulfs "+caster->QP+" companions into blinding light!%^RESET%^", presentparty);
    if(!(endplace="/std/magic/teleport"->teleport_object(caster,caster,arg,clevel)))
    {
      tell_object(caster,"You sense something blocking your "+
                  "passage and lose concentration on your power.");
      tell_room(place,caster->QCN+" "+
                "looks startled.",caster);
      dest_effect();
      return;
    }
    tell_room(endplace,"%^BOLD%^%^WHITE%^A bright light flashes in your vicinity.%^RESET%^",caster);
    presentparty -= ({ caster });

    followers = caster->query_followers();
    if(sizeof(followers))
    {
      presentparty += followers;
      for(i=0;i<sizeof(followers);i++)
      {
        if(!objectp(followers[i])) 
        {
          presentparty -= ({followers[i]});
          continue;
        }            
        if(member_array(followers[i],presentparty) != -1)
          continue;
      }
    }
    presentparty->move_player(endplace);
    map_array(presentparty,(:caster->add_follower($1):));
  }
  dest_effect();
}

void dest_effect() {
  ::dest_effect();
  if(objectp(TO)) TO->remove();
}

