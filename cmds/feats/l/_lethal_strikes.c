#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MeleeAccuracy");
    feat_name("lethal strikes");
    feat_desc("This feat represents your ability to strike in a much more lethal manner. This feat only works when wielding normal or small sized weapons. When using normal weapons the feat increases the critical threat range and the critical multiplier by 1. When using small weapons the feat increase the critical threat range and the critical multiplier by 2. If mixing normal and small weapons, the critical threat range and critical multiplier will only be increased by 1. \n\nA small weapon that normally does 1d8 extra critical damage on a dice roll of 18-20 will do 3d8 extra critical damage on a dice roll of 16-20. A normal weapon would do 2d8 damage on a dice roll of 17-20.");
    permanent(1);
    //set_obsolete(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }

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
