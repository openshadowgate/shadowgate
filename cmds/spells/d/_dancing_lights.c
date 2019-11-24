#include <spell.h>
#include <magic.h>
#include <std.h>

inherit SPELL;
object ob;

void create() {
    ::create();
    set_spell_name("dancing lights");
    set_spell_level(([ "bard" : 1, "mage" : 1, "druid":1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS dancing lights");
    set_description("This will create a small gathering of swirling lights, which will illuminate your way.");
	set_helpful_spell(1);
}

string query_cast_string() {
    return "%^YELLOW%^"+CASTER->QCN+" swirls "+CASTER->QP+" fingers in the air.";
}

void spell_effect(int prof) {
    int level;

    tell_object(caster, "%^BOLD%^%^WHITE%^Gleaming trails of l%^CYAN%^i%^WHITE%^gh%^YELLOW%^t %^WHITE%^spring into existance, following the motion of your fingertips!");
    tell_room(place, "%^BOLD%^%^WHITE%^Gleaming trails of l%^CYAN%^i%^WHITE%^gh%^YELLOW%^t %^WHITE%^spring into existance, following the motion of "+caster->QCN+"'s fingertips!",caster);

    if(level > 20) level = 20;
    ob = new("/d/magic/obj/dancinglights");
    call_out("dest_effect", 1800 + (level * 10));
    ob->set_property("spell", TO);
    ob->set_property("spelled", ({TO}) );
    ob->move(caster);
    spell_successful();
}

void dest_effect() {
    if (find_call_out("dest_effect") != -1) remove_call_out("dest_effect");
    tell_room(place,"%^BOLD%^%^WHITE%^The bright lights suddenly snuff out, and the room grows a little darker.");
    if(objectp(ob)) ob->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
