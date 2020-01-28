#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("DivineSpellcraft");
    feat_name("third divine domain");
    feat_prereq("Cleric L1");
    feat_desc("This feat conveys a high level of favor in which a cleric is held by their patron. It allows for those rare cases where a priest is permitted to wield any and all specialty spells their deity offers.");
    permanent(1);
}
int allow_shifted()
{
    return 1;
}
int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("cleric") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}
void execute_feat()
{
    ::execute_feat();
    dest_effect();
}
void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}
void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}
void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
