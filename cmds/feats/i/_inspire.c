#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

#define INSPIRATION "/cmds/feats/obj/inspiration"

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Performance");
    feat_name("inspire");
    feat_syntax("inspire nothing|courage|competence|greatness|heroics");
    feat_prereq("Bard L1");
    feat_classes("bard");
    feat_desc("This feats gives you access to songs of inspiration. These songs affect every ally present and grant them various bonuses. These songs, hovewer, can be disharmonized with a countersong. To see what inspiration grants which effect refer to their feat help files. With <inspire nothing> command you can cease your current songs.");
    set_target_required(0);
    allow_blind(1);
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
    if (ob->query_class_level("bard") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_inspire(string args)
{
    object feat;
    if (!objectp(TP)) {
        dest_effect();
        return 0;
    }

    if (member_array(args, INSPIRATION->query_inspiration_types()) == -1) {
        tell_object(TP,"%^BOLD%^CYAN%^That is not a valid inspiration!");
        dest_effect();
        return 1;
    }

    if(!FEATS_D->usable_feat(TP,"inspire " + args))
    {
        tell_object(TP,"%^BOLD%^%^CYAN%^You don't have a feat required to use this inspiration.");
        dest_effect();
        return 0;
    }

    feat = new(base_name(TO));
    feat->setup_feat(TP, args);
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^MAGENTA%^You m%^WHITE%^u%^MAGENTA%^se preparing the m%^BOLD%^e%^WHITE%^l%^MAGENTA%^o%^WHITE%^d%^MAGENTA%^y%^RESET%^%^MAGENTA%^.%^WHITE%^");
    caster->use_stamina(roll_dice(1, 6));
    caster->set_property("using instant feat", 1);
}

void execute_attack()
{
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    ::execute_attack();

    INSPIRATION->setup_inspiration(caster, flevel);

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
