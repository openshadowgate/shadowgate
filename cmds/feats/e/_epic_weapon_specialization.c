#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("WeaponMastery");
    feat_name("epic weapon specialization");
    feat_prereq("Epic Weapon Focus, Greater Weapon Specialization");
    feat_desc("This feat, available only as a class skill to trained fighters, further increases the damage of all attacks with weapons further by +2.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"greater weapon specialization")) {
        dest_effect();
        return 0;
    }
    if(!FEATS_D->has_feat(ob,"epic weapon focus")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
