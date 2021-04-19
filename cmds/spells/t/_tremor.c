#include <std.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("tremor");
    set_spell_level(([ "cleric" : 5, "inquisitor" : 2, "psion" : 5, "magus" : 3 ]));
    set_spell_sphere("combat");
    set_domains("destruction");
    set_syntax("cast CLASS tremor");
    set_damage_desc("bludgeoning, tripped for 1d2 rounds");
    set_description("This spell causes a great quake to shake the ground, doing some damage to the caster's enemies, and having a chance to knock them down to the ground. On a successful save causes half the damage and no tripped.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_save("reflex");
}

string query_cast_string(){
	tell_object(caster,"%^ORANGE%^A low rumble echoes around you, as "+
		"you begin the words of this prayer.");
	tell_room(place,"%^ORANGE%^A low rumble can be heard as "+caster->QCN+""+
		" begins the words to a prayer.",caster);
	return "display";
}

void spell_effect(int prof){
    object *inven;
    int i,damage;

    inven = target_selector();

    inven -= ({caster});

    tell_room(place,"%^YELLOW%^The ground suddenly lurches under "+
       "you as "+caster->QCN+" completes a spell!",caster);
    tell_object(caster,"%^YELLOW%^The ground shudders violently, "+
       "yielding to your command!");

    if(sizeof(inven)){
        for(i=0;i<sizeof(inven);i++){
            if(!objectp(inven[i])) { continue; }
            define_base_damage(0);
            if (!do_save(inven[i]) && inven[i]->set_tripped(roll_dice(1, 2), "You are struggling to stand!")) {
                tell_object(inven[i], "%^BOLD%^You are thrown to the " +
                            "ground by the force of the tremor!");
                tell_room(place, "%^BOLD%^" + inven[i]->QCN + " is thrown " +
                          "to the ground by the force of the quake!", inven[i]);
                damage = sdamage;
            }else {
                tell_object(inven[i], "%^ORANGE%^You stagger from the force of the tremor but "
                            "manage to maintain your footing!");
                tell_room(place, "%^ORANGE%^" + inven[i]->QCN + " staggers from the force of the "
                          "tremor but manages to maintain " + inven[i]->QP + " footing!");
                damage = sdamage / 2;
            }
            damage_targ(inven[i],inven[i]->return_target_limb(),damage,"bludgeoning");
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
