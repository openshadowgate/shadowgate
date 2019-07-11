#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("RangedCombat");
    feat_name("point blank shot");
    feat_desc("Point blank shot allows for projectile weaponsto be fired even in close-quarters combat. Characters without this feat donot have the aptitude to use a ranged weapon in melee combat except as abludgeoning tool.");
    permanent(1);
    set_required_for(({"manyshot","deadeye","precise shot","shot on the run"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob) {
    string myname;
    if(!objectp(ob)) return 0;
    myname = (string)ob->query_name();
    return ::prerequisites(ob);
}

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

