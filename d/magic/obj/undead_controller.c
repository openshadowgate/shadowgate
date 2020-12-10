#include <std.h>
inherit OBJECT;

//#define UNDEAD_MINIONS ({ "skeleton", "graveknight", "skelemage", "skelehorses", "vampire_spawn", "vampire_knight", });

object caster, * mons = ({});
int count;

void save_me(string file)
{
    return 1;
}

void create()
{
    ::create();
    set_name("device");
    set("id", ({ "undead_controller" }));
    set("short", "");
    set("long", "");
    set_weight(0);
}

int move(mixed dest)
{
    if (ETO && objectp(ETO)) {
        if (interactive(ETO)) {
            return 0;
        }
    }
    ::move(dest);
    set_heart_beat(10);
}

set_caster(object ob)
{
    if (objectp(ob)) {
        caster = ob;
    }else {
        remove();
    }
}

object* query_mons()
{
    return mons;
}

object query_caster()
{
    return caster;
}

void add_monster(object obj)
{
    if (!objectp(obj)) {
        return;
    }
    mons += ({ obj });
}

int clean_mons()
{
    object* temp = ({});
    int i;
    int poolsize, * my_undead, skeletons, graveknights, skelemages, skelehorses, v_spawn, v_knight; //consider using a mapping instead


    for (i = 0; i < sizeof(mons); i++) {
        if (!objectp(mons[i])) {
            continue;
        }
        temp += ({ mons[i] });
        poolsize += (int)mons[i]->query_property("raised");
        skeletons += (int)mons[i]->query_property("raised skeleton");
        graveknights += (int)mons[i]->query_property("raised graveknight");
        skelemages += (int)mons[i]->query_property("raised skelemage");
        skelehorses += (int)mons[i]->query_property("raised skelehorses");
        v_spawn += (int)mons[i]->query_property("raised vampire_spawn");
        v_knight += (int)mons[i]->query_property("raised vampire_knight");
    }
    if (!sizeof(temp)) {
        if (objectp(TO)) {
            TO->remove();
        }
        return 1;
    }

    caster->remove_property("raised");
    caster->set_property("raised", poolsize);
    caster->remove_property("raised skeleton");
    caster->set_property("raised skeleton", skeletons);
    caster->remove_property("raised graveknight");
    caster->set_property("raised graveknight", graveknights);
    caster->remove_property("raised skelemage");
    caster->set_property("raised skelemage", skelemages);
    caster->remove_property("raised skelehorses");
    caster->set_property("raised skelehorses", skelehorses);
    caster->remove_property("raised vampire_spawn");
    caster->set_property("raised vampire_spawn", v_spawn);
    caster->remove_property("raised vampire_knight");
    caster->set_property("raised vampire_knight", v_knight);

    mons = temp;
    return 0;
}

void heart_beat()
{
    if (!objectp(caster)) {
        remove();
    }
    clean_mons();
}

void remove()
{
    int i;
    for (i = 0; i < sizeof(mons); i++) {
        if (objectp(mons[i])) {
            mons[i]->die();
        }
    }
    if (objectp(caster)) {
        caster->remove_property("raised");
        caster->remove_property("raised skeleton");
        caster->remove_property("raised graveknight");
        caster->remove_property("raised skelemage");
        caster->remove_property("raised skelehorse");
        caster->remove_property("raised vampire_spawn");
        caster->remove_property("raised vampire_knight");
    }
    return ::remove();
}

void init()
{
    ::init();
    add_action("cmd", "command");
    add_action("dismiss", "dismiss");
    add_action("poolsize", "poolsize");
}

int poolsize(string str)
{
    int pool, skeleton, graveknight, skelemage, horses, v_spawn, v_knight;
    string b_msg;

    clean_mons();
    pool = (int)caster->query_property("raised") + (int)caster->query_property("raised skelehorse");
    skeleton = (int)caster->query_property("raised skeleton");
    graveknight = (int)caster->query_property("raised graveknight");
    skelemage = (int)caster->query_property("raised skelemage");
    horses = (int)caster->query_property("raised skelehorse");
    v_spawn = (int)caster->query_property("raised vampire_spawn");
    v_knight = (int)caster->query_property("raised vampire_knight");
    if (pool) {
        tell_object(caster, "%^BOLD%^%^BLACK%^YOUR UNDEAD POOL IS FILLED WITH %^WHITE%^" + pool + "%^BLACK%^ UNDEAD.%^RESET%^");
        if (skeleton) {
            tell_object(caster, "%^BOLD%^%^BLACK%^YOU HAVE POWER OVER %^WHITE%^" + skeleton + "%^BLACK%^ UNDEAD CHAMPIONS.%^RESET%^");
        }
        if (graveknight) {
            tell_object(caster, "%^BOLD%^%^BLACK%^YOU HAVE POWER OVER %^WHITE%^" + graveknight + "%^BLACK%^ UNDEAD GRAVEKNIGHTS.%^RESET%^");
        }
        if (skelemage) {
            tell_object(caster, "%^BOLD%^%^BLACK%^YOU HAVE POWER OVER %^WHITE%^" + skelemage + "%^BLACK%^ UNDEAD MAGES.%^RESET%^");
        }
        if (horses) {
            tell_object(caster, "%^BOLD%^%^BLACK%^YOU HAVE POWER OVER %^WHITE%^" + horses + "%^BLACK%^ UNDEAD HORSES.%^RESET%^");
        }
        if (v_spawn) {
            tell_object(caster, "%^BOLD%^%^BLACK%^YOU HAVE POWER OVER %^WHITE%^" + v_spawn + "%^BLACK%^ VAMPIRE SPAWNS.%^RESET%^");
        }
        if (v_knight) {
            tell_object(caster, "%^BOLD%^%^BLACK%^YOU HAVE POWER OVER %^WHITE%^" + v_knight + "%^BLACK%^ VAMPIRE KNIGHTS.%^RESET%^");
        }
    }else {
        tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^THERE IS NO DEAD THAT FOLLOWS %^BLACK%^Y%^BLACK%^O%^BLACK%^U%^RESET%^");
    }

    return 1;
}

int cmd(string str)
{
    object ob;
    string what, who, what2, holder;
    int i, flag;

    if (clean_mons()) {
        return 0;
    }

    if (!str) {
        return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^PROVIDE YOUR DEMANDS%^RESET%^%^RESET%^");
    }

    if (sscanf(str, "%s to %s", who, what) != 2) {
        return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^YOU MUST TELL WHAT TO DO%^RESET%^%^RESET%^");
    }

    if (who != "undead") {
        return 0;
    }

    if (what[0..3] == "kill") {
        flag = 1;
        if (sscanf(what, "kill %s", who) == 1) {
            if (ob = present(who, environment(caster))) {
                if (!caster->ok_to_kill(ob)) {
                    return notify_fail("%^RESET%^%^BOLD%^%^BLACK%^KILLING THAT IS ABOVE YOU%^RESET%^%^RESET%^");
                }
            }
        }
    }

    if (what == "follow") {
        flag = 1;
        for (i = 0; i < sizeof(mons); i++) {
            if (!objectp(mons[i])) {
                continue;
            }
            if (!present(mons[i], environment(caster))) {
                continue;
            }
            caster->add_follower(mons[i]);
            tell_object(caster, "%^BOLD%^%^BLACK%^YOUR " + mons[i]->query_short() + "%^BOLD%^%^BLACK%^ OBEYS TO FOLLOW.%^RESET%^");
        }
        return 1;
    }

    for (i = 0; i < sizeof(mons); i++) {
        if (mons[i]->query_property("raised skelehorse")) {
            continue;
        }
        if (!mons[i]->force_me(what)) {
            continue;
        }
    }
    return 1;
}

int dismiss(string str)
{
    int i;

    if (!str || str != "undead") {
        return 0;
    }
    tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^THE SOULS %^BLACK%^R%^BLACK%^E%^BLACK%^J%^BLACK%^O%^BLACK%^I%^BLACK%^C%^BLACK%^E%^BLACK%^ IN %^BLACK%^F%^BLACK%^R%^BLACK%^E%^BLACK%^E%^BLACK%^D%^BLACK%^O%^BLACK%^M%^RESET%^");
    tell_room(environment(caster), "%^BOLD%^%^GREEN%^The undead creature crumble to dust!%^", ({ caster }));
    remove();
    return 1;
}
