#include <std.h>
#include <magic.h>
inherit SPELL;

object *mons = ({});

void create() {
    ::create();
    set_spell_name("mirror image");
    set_spell_level(([ "mage" : 2, "bard":2 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS mirror image");
    set_description("Several illusory duplicates of you pop into being, making it difficult for enemies to know which target to attack. The figments stay near you and disappear when struck.

%^BOLD%^%^RED%^N.B.%^RESET%^ Copies will have your name as their id. If you wish to be able to target yourself in combat, you should <recognize> yourself as something BUT your name.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^BOLD%^%^GREEN%^"+caster->QCN+" drops a mirror and steps onto it.";
}

int preSpell() {
    if (present(caster->query_name()+"illusion",place)) {
        tell_object(caster,"You can't create more illusions.");
        return 0;
    }
    return 1;
}

void spell_effect() {
    object ob;
    int i,max;
    max=4;
    tell_room(place,"%^GREEN%^Four copies of "+caster->QCN+"%^RESET%^%^GREEN%^ pop into being!%^RESET%^");
    for (i=0;i<max;i++) {
        ob = new("/d/magic/mon/illusion");
        ob->move(place);
        caster->add_protector(ob);
        ob->set_property("spelled", ({TO}) );
        ob->set_property("spell_creature", TO);
        ob->set_property("spell", TO);
        ob->set_property("minion", caster);
        ob->set_max_hp(clevel*18+30);
        ob->set_hp(clevel*18+30);
        ob->add_id(caster->query_true_name()+"_illusion");
        ob->set_race((string)caster->query_race());
        ob->set_gender((string)caster->query_gender());
        ob->set_short((string)caster->getWholeDescriptivePhrase());
        ob->set_long((string)caster->getWholeDescriptivePhrase() + " " +(string)caster->query_description());
        ob->set_overall_ac(-clevel);
        ob->set_exp(0);
        ob->add_id("summoned monster");
        ob->add_id(caster->query_name()+"illusion");
        mons += ({ob});
        caster->add_follower(ob);
        caster->add_protector(ob);
    }
    addSpellToCaster();
    call_out("dest_effect",clevel*ROUND_LENGTH);
}

void dest_effect() {
    int i;
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i]))
        {
            if(objectp(caster))
            {
                caster->remove_protector(mons[i]);
            }
            mons[i]->die();
        }
    }
    removeSpellFromCaster();
    ::dest_effect();
    if(objectp(TO))
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
    }
}
