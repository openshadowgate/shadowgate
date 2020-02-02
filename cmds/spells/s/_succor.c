#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>

inherit "/cmds/spells/t/_teleport";

void create(){
    ::create();
    set_spell_name("succor");
    set_spell_level(([ "cleric" : 9,"inquisitor":4 ]));
    set_spell_sphere("alteration");
    set_domains(({}));
    set_syntax("cast CLASS succor to DESTINATION");
    set_description("The succor spell will transport the priest to a location that he or she has remembered from the "
"'remembered location' list. To remember a new location, use 'remember here as <location>', to see a list of all "
"remembered locations, use 'recall locations'. This spell must be cast while at peace.

%^BOLD%^%^RED%^See also%^RESET%^: remember, unremember, recall");
    set_verbal_comp();
    set_arg_needed();
    set_peace_needed(1);
	set_helpful_spell(1);
}

string query_cast_string(){
    tell_object(caster,"%^MAGENTA%^You begin to whisper a quiet prayer.  "+
		"With each word of the prayer, you feel yourself growing lighter"+
		" and lighter.");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" begins to whisper a quiet prayer."+
                " With each word from "+caster->QP+" prayer, "+caster->QP+" voice grows fainter.",caster);
    return "display";
}
