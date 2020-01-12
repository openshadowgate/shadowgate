#include <std.h>
#include <daemons.h>

inherit FEAT;

#define FEAT_CMD "/cmds/mortal/_feats"

int cmd_expanded_knowledge_1(string args)
{
    int ret;

    if(TP->query("expanded_knowledge_change")>time()-60*60*24*3)
    {
        write("%^BOLD%^%^BLACK%^Too soon, once per three days, go away.");
        return 1;
    }

    if(FEAT_CMD->expanded_knowledge_power(args,TP,"expanded knowledge 1","normal"))
        TP->set("expanded_knowledge_change",time());

    return 1;
}

void create() {
    ::create();
    feat_type("permanent");
    feat_category("Psionics");
    feat_name("expanded knowledge 1");
    feat_prereq("Psywarrior L11, Psion L1");
    feat_syntax("expanded_knowledge_1 SPELLNAME");
    feat_desc("This feat allows a psionic character to master an additional power of any level up to one less than he can cast. The selected power may be from any psionic power list, even those normally reserved for a specific discipline.");
    permanent(1);
    psionic(1);
    set_required_for(({"expanded knowledge 2","expanded knowledge 3","spell power","improved spell power","greater spell power","hardenedminions","magic arsenal"}));
    set_replaces_feat("spellmastery");
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }
    if(ob->query_class_level("psywarrior") < 11 && ob->query_class_level("psion") < 1) {
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
