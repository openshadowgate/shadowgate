#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create() 
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("MagusArcana");
    feat_name("arcane pool");
    feat_prereq("Magus L1");
    feat_classes("magus");
    feat_desc("The Shieldwall feat allows you to fight defensively using your shield to help deflect attacks and avoid incoming damage. The more defensively that you fight with your shield, the fewer melee attacks that you will get. You may increase your defensive ability with your shield until you have only one melee attack remaining. Using shieldwall defensively will also reduce the power of your spells. Using shieldwall defensively when you have the counter feat will also increase the damage of your attacks.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
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
    remove_feat(this_object());
    return;
}