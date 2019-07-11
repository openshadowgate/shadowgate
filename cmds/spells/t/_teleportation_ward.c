#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <spell.h>
inherit SPELL;

object room;
int oldstrength;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("teleportation ward");
    set_spell_level(([ "cleric" : 8 ]));
    set_spell_sphere("abjuration");
    set_spell_domain("protection");
    set_syntax("cast CLASS teleportation ward");
    set_description("This spell creates a magical dome around the area that prevents all teleportation magic into and out "
"of the area.  The magic will last for a short time, or until the caster leaves the area or it is dispelled.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void heart_beat() {
    if(!objectp(TO)) { return; }
    if(!objectp(caster)) { return; }
    if(!objectp(room)) { return; }
    if(!present(caster,room)) {
        tell_room(room,"%^BOLD%^%^BLUE%^The magical field of protection fades away when "+caster->QCN+" "
            "leaves the area.",caster);
        tell_object(caster,"%^BOLD%^%^BLUE%^Your magical field of protection fades away as you leave.");
        dest_effect();
        return;
    }
}

int preSpell() {
    if(place->query_property("no teleport")) {
        tell_object(caster,"This room is already protected against teleportation.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^BLUE%^A translucent blue dome begins to form"+
        " over you as you pray.");
    tell_room(place,"%^BOLD%^%^BLUE%^A translucent blue dome begins to"+
        " form in the air over "+caster->QCN+" as "+caster->QP+" "+
        "begins to pray.",caster);
	return "display";
}

void spell_effect(int prof){
    int duration,strength,bonus,fail;

    room = environment(caster);
    bonus = caster->query_stats("wisdom");
    bonus = bonus - 10;
    strength = CLEVEL + bonus + random(6) + 5;  //adding 5 as base strength to all ward effects so they might work sometimes. N, 6/11.

    oldstrength = (int)room->query_property("teleport proof");
    if(oldstrength > strength) {
       tell_object(caster,"There is a greater magic already protecting this room!");
       return 1;
    }
    room->remove_property("teleport proof");
    room->set_property("teleport proof",strength);

    tell_room(room,"%^BLUE%^%^BOLD%^The translucent blue dome above "+caster->QCN+" solidifies a moment "
        "before it winks out of existance, encasing the area in a protective field!",caster);
    tell_object(caster,"%^BOLD%^%^BLUE%^The translucent blue dome above you solidifies a moment before it "
        "winks out of existance, encasing the area in a protective field!");
    addSpellToCaster();
    spell_successful();
    room->set_property("spelled",({TO}));
    duration = 30 * (int)CLEVEL;
    if(duration > 900 && !avatarp(caster)) duration = 900;
    call_out("dest_effect",duration);
}

void dest_effect() {

    if(objectp(room)) 
    {
       tell_room(room,"The magical field of protection shimmers and then dissipates.");
       room->remove_property("teleport proof");
       if(oldstrength) room->set_property("teleport proof",oldstrength);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}