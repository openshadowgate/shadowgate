// Offensive Summoning

#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
inherit SPELL;

#define DELAY 300 //5min delay between uses

void create() {
    ::create();
    set_spell_name("offensive summoning");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_spell_domain("war");
    set_syntax("cast CLASS offensive summoning on TARGET");
    set_description("This spell gives the caster a chance of summoning to him- or herself someone who has recently done "
"an unredressed wrong to the caster. There is also a chance of the caster being summoned to the target, if the spell is "
"not successful. Once this spell is used, the caster must rest for a short while before attempting its use again.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_save("fort");
}

int preSpell() {
    if(place->is_temple()) {
      tell_object(caster,"Powerful wards prevent your spell from being cast!");
      return 0;
    }
    if((int)caster->query_property("spell summon time")+DELAY > time()){
      tell_object(caster,"You cannot summon anyone to you again so quickly.");
      return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BLUE%^Closing your eyes, you begin to murmur the words to a prayer.");
    tell_room(place,"%^BLUE%^"+caster->QCN+" closes "+
        ""+caster->QP+" eyes as "+caster->QS+" begins to murmur the words to a prayer.",caster);
	return "display";
}

void spell_effect(int prof) {
    int i, matches;
    string real;
    object targ;
    mapping map;
    string *map_keys;

    if (!objectp(caster))     {
        dest_effect();
        return;
    }
    arg = lower_case(arg);
    if(caster->isKnown(arg)) { real = arg; }
    else { real = (string)caster->realNameVsProfile(arg); }

    targ = find_player(real);

    tell_object(caster,"%^BOLD%^%^BLUE%^You have found "+targ->QCN+"!");
    call_out("do_summon",6,targ);
}

void do_summon(object target) {
    object *party,endplace;
    int i,success,fail,targlevel,mylevel;
    int mypower,startpower,endpower,bonus;

    if (!objectp(caster) || !objectp(target)) {
        dest_effect();
        return;
    }
    if (!objectp(environment(caster)) || !objectp(environment(target))) {
        tell_object(caster,"The summoning has failed.");
        dest_effect();
        return;
    }
    if ((int)environment(caster)->query_property("no teleport") || (int)environment(target)->query_property("no teleport")) {
        tell_object(caster,"Something interferes with your summoning, and the spell fails.");
        dest_effect();
        return;
    }
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport
//but not foolproof
   endplace = environment(target);
   if(endplace &&
      (endplace->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !endplace->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = endplace->query_property("teleport proof");
      bonus = caster->query_stats("wisdom");
      bonus = bonus -10;
      mypower = CLEVEL + bonus + random(6) + 5;
      if((mypower < startpower) || (mypower < endpower)){
        tell_object(caster,"Something interferes with your summoning, and the spell fails.");
        dest_effect();
        return;
      }
   }
   caster->set_property("spell summon time",time());
   success = 0;
//changed the below after talks with Tsera about the way this
//spell always finds the target. ~Circe~ 6/11/08
    targlevel = target->query_highest_level();
    mylevel = caster->query_highest_level();
    if(targlevel < mylevel)
    {
        success = 1;
    }
    else if(targlevel > (mylevel+random(6))){ //changed this from < to > - this way if you're trying to summon someone higher level than you, there is at least a chance of you going to them
        if(!do_save(target,0)) {
            success = 1;
        }else{
            success = 0;
        }
    }else{
        if(!do_save(target,0)) {
            success = 1;
        }else{
            fail = 1;
        }
    }
    if(fail){
        tell_object(target,"%^CYAN%^You feel a strange tugging at "+
           "your soul before it ceases.%^RESET%^");
        tell_object(caster,"%^CYAN%^Your attempts to summon "+
           ""+target->QCN+" seem to have failed.%^RESET%^",target);
        dest_effect();
        return;
    }
    if (success) {
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" has summoned you for revenge!");
        tell_object(caster,"%^BOLD%^%^CYAN%^You have summoned "+target->QCN+" for revenge!");
        target->move_player(environment(caster));
        spell_kill(target, caster);
        dest_effect();
        return;
    }
    else {
        tell_object(target,"%^BOLD%^%^BLUE%^You have resisted "+caster->QCN+"'s attempt to summon you for revenge!");
        tell_object(caster,"%^BOLD%^%^BLUE%^"+target->QCN+" has resisted your summons!");
	    tell_object(target,"%^BOLD%^"+caster->QCN+" appears near you!");
            tell_object(caster,"%^BOLD%^You are transported to another place!");
        caster->move_player(environment(target));
        spell_kill(target, caster);
        dest_effect();
        return;
    }
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
