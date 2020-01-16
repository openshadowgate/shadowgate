#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit MONSTER;

object caster;
object spell;

void create()
{
    ::create();
    set_name("invisibility alarm sign");
    set_id(({"inv_alarm_999"}));

    set_property("no detect",1);

    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
}

void setup(object invoker, object invspell)
{
    caster = invoker;
    spell - invspell;
    call_out("alarm_observe",ROUND_LENGTH);
}

void alarm_observe()
{
    if(!objectp(caster))
    {
        if(objectp(query_property("spell")))
        {
            query_property("spell")->dest_effect();
            return;
        }
        remove_call_out("alarm_observe");
        TO->remove();
    }
    else
    {
        object *livings;
        int clevel = query_property("spell")->query_clevel();

        livings = all_living(ETO);
        livings -= ({TO});
        livings -= ({caster});
        livings -= caster->query_followers();
        livings = filter_array(livings, "is_non_immortal",FILTERS_D);
        livings = filter_array(livings, (:$1->query_invis()||$1->query_hidden():));
        livings = filter_array(livings, (:$1->query_skill("spellcraft") < $2 * 7 / 4:), clevel);
        livings = filter_array(livings, (:$1->query_skill("stealth") < $2 * 7 / 4:), clevel);
        if (objectp(caster))
            if (sizeof(livings)) {
                tell_room(caster, "%^CYAN%^An invisibility alarm set in " + ENV(TO)->query_short() + " had been set off.%^RESET%^");
                remove_alarm();
            }
    }
    call_out("alarm_observe",ROUND_LENGTH);
}

int die()
{
    remove_hound();
}

void remove_alarm()
{
    remove_call_out("alarm_observe");
    if(objectp(caster) &&
       objectp(ETO))
    {
        tell_object(caster,"%^CYAN%^You concentration releases as alarm in "+ETO->query_short()+" fades.%^RESET%^");
        if(objectp(spell))
            spell->dest_effect();
    }
    destruct(TO);
}
