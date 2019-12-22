//A few changes by ~Circe~ 5/11/08 to bring it more in line with other 8th level spells.
// replaced hellball for the mages as top evocation school spell. N, 10/15.
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("sunburst");
    set_spell_level(([ "cleric" : 8, "druid" : 8, "mage" : 8,"oracle":8 ]));
    set_mystery(({"heavens","solar"}));
    set_spell_sphere("invocation_evocation");
    set_spell_domain("sun");
    set_syntax("cast CLASS sunburst");
    set_damage_desc("untyped, 1.25 times more to undead");
    set_description("This spell will send the light of the sun radiating out in a circle from the caster.  Any enemies caught in the area will suffer damage from the pure light of the sun.  Undead creatures suffer more damage than normal ones, and those creatures who fail their save are blinded by the light.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(1);
    set_components(([
      "mage" : ([ "sunstone" : 1, ]),
    ]));
}

string query_cast_string(){
	tell_object(caster,"%^YELLOW%^You can feel a warmth spreading through"+
		" your body as you chant.");
	tell_room(place,"%^YELLOW%^A warm glow surrounds "+caster->QCN+" as "+
		""+caster->QS+" begins to chant.",caster);
	return "display";
}

void spell_effect(int prof){
    object *attackers;
    int i,dmg;
    attackers = caster->query_attackers();
    attackers = target_filter(attackers);

    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^The area is whitewashed with the brilliant light of the sun, but nothing else happens.");
        dest_effect();
        return;
    }
    tell_room(place,"%^BOLD%^The area is washed white with the brilliant light of the sun!%^RESET%^");
    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) continue;

        if(attackers[i]->is_vampire())
            dmg = sdamage * 2;
        else if((string)attackers[i]->query_race() == "undead" || attackers[i]->query_property("undead"))
            dmg = sdamage * 5/4;
        else
            dmg = sdamage;

        if(do_save(attackers[i],0)) {
          if(evade_splash(attackers[i])) continue;
          dmg = sdamage/2;
        }
        else {
            tell_object(attackers[i],"%^BOLD%^The light burns your eyes, blinding you!%^RESET%^");
            attackers[i]->set_temporary_blinded(1);
        }
        tell_object(attackers[i],"%^YELLOW%^The sunlight burns as it strikes you, scorching your skin!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),dmg,"untyped");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
