#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("ArcaneSpellcraft");
    feat_name("spell knowledge");
    feat_prereq("Sorcerer L21 or Oracle L21");
    feat_desc("This feat allows a caser to master an additional two spells of any level, above what the class would normally allow");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("sorcerer") < 21 ||
        ob->query_class_level("oracle") < 21) {
        dest_effect();
        return 0;
    }
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
