#include <magic.h>
#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void create() {
    ::create();
    set_spell_name("astral projection");
    set_spell_level((["oracle":9, "mage":9 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS spiritual ally");
    set_mystery("ancestor");
    set_description("Call to one of your ancestors to aid you in combat. This spirit will have a chosen weapon of your deity and will obey all your commands.

This is a greater summons, and cannot be used simultaneously with other greater summons.
To remove ally use %^ORANGE%^<dismiss ally>%^RESET%^
To command ally use %^ORANGE%^<command ally to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost ally to follow use %^ORANGE%^<command ally to follow>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("has_elemental")) {
        tell_object(caster, "Your concentration is already upon a distant location!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    object ob, thing;
    int bonus, power;

    tell_object(caster, "%^CYAN%^%^BOLD%^As you complete the spell a humanoid being descends to stand in your protection.%^RESET%^");

    ob = new("/d/magic/mon/astral_projection.c");
    ob->set_alignment(caster->query_alignment());
    ob->setup_servant(caster, clevel);

    control = new("/d/magic/obj/holder");
    control->set_caster(caster);
    control->move(caster);
    control->set_elemental(ob);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );

    caster->add_follower(ob);

    ob->move(environment(caster));

    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    ob->set_race(caster->query_visual_race());
    ob->set_gender((string)caster->query_gender());
    ob->set_short(cm(strip_colors(caster->getWholeDescriptivePhrase())));
    ob->set_long(cm(strip_colors(caster->getWholeDescriptivePhrase() + " " +(string)caster->query_description())));

    addSpellToCaster();

    return;
}

void dest_effect()
{
    object sword;

    if (objectp(control)) {
        if (objectp(sword = control->query_mon())) {
            sword->remove();
            destruct(control);
        }
    }
    if (objectp(caster)) {
        tell_object(caster,"%^BOLD%^Your concentration on places afar fades.");
        caster->remove_property("has_elemental");
    }
    ::dest_effect();
    if (objectp(TO))
        TO->remove();
}

string cm(string str)
{
    return CRAYON_D->color_string(str,"grey");
}
