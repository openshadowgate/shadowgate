// darkness
#include <spell.h>
#include <magic.h>
#include <std.h>

inherit SPELL;
object ob;

void create() {
    ::create();
    set_spell_name("darkness");
    set_spell_level(([ "mage" : 2, "bard" : 2, "cleric" : 2, "monk" : 3, "assassin": 2, "paladin":2]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS darkness on TARGET");
    set_description("This will create a globe of darkness, which will overcome normal light sources. You can cast it on "
"an object or player which it will follow, instead of the caster.");
    set_verbal_comp();
    set_non_living_ok(1);
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^YELLOW%^"+CASTER->QCN+" closes "+
    CASTER->QP+" eyes and reaches out "+
    CASTER->QP+" hands, gathering in energy.";
}

void spell_effect(int prof) {
    int level; 

    level = clevel;
    if (interactive(caster)) {
        //if (level > 20) level = 20;

        tell_object(caster, "You create a darkness around you.");
        tell_room(place, caster->QCN+" causes the room to darken.", ({caster, target}) );
        if ( interactive(target) && !( caster == target ) )
            tell_object(target, caster->QCN+" touches you and light disappears.\n");
    } else {
        //level = (( 11 - level ) * 2 );

        tell_room(place, caster->QCN+ " causes the room to darken.",caster);
    }  
    if(level > 20) level = 20;
    ob = new("/cmds/priest/obj/dark");
    call_out("dest_effect", 1800 + (level * 10));
    ob->set_property("spell", TO);
    ob->set_property("spelled", ({TO}) );

    if (!target)
        ob->move((TP));
    else
        ob->move((target));
    spell_successful();
}

void dest_effect() {
    if (find_call_out("dest_effect") != -1)
        remove_call_out("dest_effect");
    tell_room(place,"%^YELLOW%^The room is suddenly brighter.");
    if(objectp(ob)) ob->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
