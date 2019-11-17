#include <std.h>
#include <daemons.h>
#include <dirs.h>
inherit FEAT;

int FLAG;
string * JUDGEMENT_TYPES;

void create() {
    ::create();
    feat_type("premanent");
    feat_category("Inquisition");
    feat_name("slayer");
    feat_syntax("slayer JUDGEMENT");
    feat_prereq("Inquisitor L17");
    feat_desc("");
    permanent(1);
    allow_tripped(1);
}

int cmd_slayer(string args)
{
    int cancastflag;
    string * myclasses, myclass;

    if(TP->query("slayer_change") > time() - 60*60*24)
    {
        write("%^BOLD%^%^WHITE%^You can change your slayer judgement only once in a day.");
        return 1;
    }
    JUDGEMENT_TYPES = "/cmds/feats/obj/judgement"->query_judgement_types();

    if(member_array(args,JUDGEMENT_TYPES)==-1)
    {
        write("%^BOLD%^%^RED%^No such judgement.%^RESET%^");
        return 1;
    }

    TP->set("slayer_change",time());
    TP->set("slayer_judgement",args);
    write("%^BOLD%^%^RED%^Done. Your slayer judgement is set to %^WHITE%^"+args+"%^RED%^.%^RESET%^");

    return 1;
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("inquisitor") < 17)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
