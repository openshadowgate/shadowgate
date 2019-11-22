#include <priest.h>
#include <daemons.h>
inherit SPELL;


void create()
{
    ::create();
    set_spell_name("replay tracks");
    set_spell_level(([ "druid" : 5, "inquisitor" : 4, "psion" : 5, "ranger" : 2 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS replay trakcs");
    set_description("This spell allows you to reconstruct past events that occurred in your current location based on the tracks and other signs left behind. To see what has happened here use <track> command while the spell is active. Ability to discern tracks will depend on your power.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect()
{
    string * tracks;
    string track;
    string who, what, whereto;
    int counter = clevel/8+1;
    tracks = place->query_tracks();

    tell_object(caster,"%^RED%^You %^RED%^k%^GREEN%^n%^RED%^eel,%^RED%^ touching the ground with your hand.
%^RED%^Images of %^RED%^the %^RED%^e%^GREEN%^v%^RED%^ent%^GREEN%^s %^GREEN%^p%^GREEN%^a%^RED%^s%^GREEN%^t%^RED%^ appear in your mind.");
    tell_room(place,"%^RED%^"+caster->QCN+" kneels and touches the ground with "+caster->QP+" hand.%^RESET%^",caster);

    foreach(track in tracks)
    {
        if(!track)
            break;
        sscanf(track,"%s&%s&%s", who, what, whereto);
        switch (what) {
        case "appeared":
            tell_object(caster, "%^GREEN%^"+capitalize(article(who))+" "+who+" appeared here.");
            break;
        case "entered":
            tell_object(caster, "%^GREEN%^"+capitalize(article(who))+" "+who+" entered this room from "+whereto+".");
            break;
        case "left":
            tell_object(caster, "%^GREEN%^"+capitalize(article(who))+" "+who+" left this room headed "+whereto+".");
            break;
        }

        if(counter<0)
            break;
        counter--;
    }

    tell_object(caster,"%^RED%^You don't see further than that.%^RESET%^");

    spell_successful();
}
