#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("spot");
    feat_desc("The Spot skill is used primarily to detect characters or creatures who are hiding. Typically, your Spot check is opposed by the stealth check of the creature trying not to be seen. Spot increases your ability to passively percieve, removing panalty to perception when making passice rolls.

A spot check might allow you to be come aware of magically invisible creatures around you, but you always suffer a penalty against these. Unlike other spot checks this one is rolled against target's spellcraft.

Spot, like passive perception, is entirely deterministic in this game and offers no chances. It either work or doesnot.

%^BOLD%^See also:%^RESET%^ status effects");
    permanent(1);
    allow_blind(1);
}

int allow_shifted() { return 1; }

void execute_feat() {
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
