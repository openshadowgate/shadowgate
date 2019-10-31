#include <std.h>
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("disjunction");
    set_spell_level(([ "mage" : 5, "cleric" : 5 ]));
    set_spell_sphere("abjuration");
    set_syntax(
"cast CLASS disjunction on OBJECT");
    set_description("This spell disconnects beneficial magic from an object and allows it to float freely, forever lost in the weave. Object must be present in caster's inventory.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^BOLD%^%^MAGENTA%^"+caster->QCN+" utters a short %^GREEN%^r%^CYAN%^h%^GREEN%^ym%^CYAN%^e %^MAGENTA%^under "+caster->QP+" breath.";
}

int preSpell() {
   if(!arg) {
       tell_object(caster, "You must specify what to deenchant.");
       return 0;
   }
   return 1;
}

void spell_effect(int prof)
{
    object ob;
    int enchantment;

    ob = present(arg,caster);
    if (!objectp(ob))
    {
        tell_object(caster,"That object is not present.");
        dest_effect();
        return;
    }

    enchantment = ob->query_property("enchantment");
    if(enchantment<1)
    {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You cannot unravel magic of this object further.%^RESET%^");
        dest_effect();
        return;
    }

    ob->remove_property("enchantment");
    ob->set_property("enchantment",--enchantment);
    tell_object(caster,"%^BOLD%^%^MAGENTA%^As you spell syllables enchantment on "+ob->query_short()+"%^BOLD%^%^MAGENTA%^ becomes weaker.%^RESET%^");
    tell_room(room,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" voices a few syllables over "+ob->query_short()+".%^RESET%^");

    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
