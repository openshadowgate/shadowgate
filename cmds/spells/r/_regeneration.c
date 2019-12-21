#include <std.h>
#include <clock.h>
inherit SPELL;

int duration, feattracker;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("regeneration");
    set_spell_level(([ "cleric" : 7, "bard" : 5, "druid" : 9, "oracle":7 ]));
    set_mystery("life");
    set_spell_sphere("healing");
    set_syntax("cast CLASS regeneration on TARGET");
    set_description("This spell will cause the target to continuously regenerate a small amount of health over a long "
"period of time.  It cannot be used on the same target more than once, and does not work in conjunction with the feat "
"of the same name.

%^BOLD%^%^RED%^See also:%^RESET%^ regeneration *feats");
    set_verbal_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^GREEN%^Motes of green light circle "+
		"around your head, growing in intensity as you chant.");
    tell_room(place,"%^BOLD%^%^GREEN%^Motes of green light circle around"+
		" "+caster->QCN+"'s head as "+caster->QS+" begins to chant.",caster);
    return "display";
}

int preSpell(){
    if(!objectp(target)) {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if(!userp(target)) {
        tell_object(caster,"This can only be cast on players.");
        return 0;
    }
    if(member_array("regeneration",(string*)target->query_temporary_feats()) != -1) {
        tell_object(caster,"That target is already regenerating and can not be effected more than once.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    duration = (clevel * HOUR)/10;
    if(duration > (HOUR * 5)) { duration = HOUR * 5; } // max duration of 5 game hours

    if(!present(target,place)) {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }
    if((string)TO->query_spell_type() == "potion")
      tell_object(caster,"%^GREEN%^As the potion warms your stomach, a gentle warmth spreads across your skin.%^RESET%^");
    else {
      if(caster == target) {
        tell_object(target,"%^GREEN%^%^BOLD%^You can feel a warmth spread "+
		    "over your body as the motes seeps into your skin.");
        tell_room(place,"%^BOLD%^%^GREEN%^The motes of light seep into"+
		    " "+caster->QCN+"'s skin.",caster);
      }
      else {
        tell_object(target,"%^BOLD%^%^GREEN%^You can feel a warmth spread over "+
		    "your body as the motes that circled "+caster->QCN+" seeps into your skin.");
        tell_room(place,"%^BOLD%^%^GREEN%^The motes of green light fly away from"+
		    " "+caster->QCN+"'s head and seep into "+target->QCN+"'s skin.",caster);
      }
    }
    target->set_property("spelled", ({TO}));

    if(member_array("regeneration",(string*)target->query_temporary_feats()) == -1) {
      target->add_temporary_feat("regeneration");
      feattracker = 1;
    }
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",duration);
}

void dest_effect() {
    if(objectp(target)) {
      tell_object(target,"%^GREEN%^You can feel the warmth leave your skin as the healing magic fades away.");
      if(feattracker == 1) target->remove_temporary_feat("regeneration");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
