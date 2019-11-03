// Entangle
#include <std.h>
#include <daemons.h>

inherit SPELL;

object room,*inven;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("entangle");
    set_spell_level(([ "cleric" : 1, "ranger" : 1,"druid" : 1,"mage":1 ]));
    set_spell_sphere("conjuration_summoning");
    set_spell_domain("plant");
    set_syntax("cast CLASS entangle");
    set_description("This spell causes the foliage and insects to come alive in the area around the caster.  They will "
"attempt to impede the movement of all creatures in the area.  Those creatures that pass a strength check will have their "
"movement effected less than those who do not.  This spell can only be used outside.");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell()
{
    if(place->query_property("indoors"))
    {
        tell_object(caster,"You can only use this spell outdoors.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^GREEN%^Kneeling, you press your hand to the"+
        " ground as you begin to whisper your prayer.");
    tell_room(place,"%^GREEN%^Kneeling, "+caster->QCN+" presses "+
        ""+caster->QP+" hand to the ground as "+caster->QS+" begins"+
        " to whisper.",caster);
    return "display";
}

void spell_effect(int prof)
{
    int i;

    inven = all_living(environment(caster));
    inven -= ({caster});
    inven = filter_array(inven,"is_non_immortal",FILTERS_D);
    inven = target_filter(inven);

    if(!sizeof(inven))
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^The plants hear your call, but find "
           	"no creatures to impede.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^The vegetation in the areas comes"+
	    " to life, growing wildly.");
    for(i=0;i<sizeof(inven);i++)
    {
        if(!objectp(inven[i])) { continue; }
        if(random((int)inven[i]->query_stats("strength") + 1) < roll_dice(1,20))
        {
		    tell_object(inven[i],"%^BOLD%^%^GREEN%^The vegetation comes alive,"+
			    " swarming all over you and making it almost impossible to move!");
		    inven[i]->set_property("added short",({ "%^GREEN%^( entangled )%^RESET%^%^CYAN%^"}));
            inven[i]->set_disable((clevel/2),inven[i]);
            continue;
        }
        tell_object(inven[i],"%^GREEN%^The vegetation comes alive, making it very"+
			" hard to move.");
        inven[i]->set_disable((clevel/4),inven[i]);
        inven[i]->set_property("added short",({ "%^GREEN%^( entangled )%^RESET%^%^CYAN%^"}));
    }
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",clevel);
}

void execute_attack()
{
    int i;
    ::execute_attack();
    if(!objectp(room)) { return; }
    if(sizeof(inven))
    {
        for(i=0;i<sizeof(inven);i++)
        {
            if(!objectp(inven[i])) { continue; }
            if(!present(inven[i],room))
            {
                inven[i]->remove_property_value("added short",({ "%^GREEN%^( entangled )%^RESET%^%^CYAN%^"}));
            }
        }
    }
}

void dest_effect()
{
    int i;
    tell_room(place,"%^GREEN%^The vegeation in the area shrinks as all returns to normal.");
    for(i=0;i<sizeof(inven);i++)
    {
        if(!objectp(inven[i])) { continue; }
        inven[i]->remove_property_value("added short",({ "%^GREEN%^( entangled )%^RESET%^%^CYAN%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
