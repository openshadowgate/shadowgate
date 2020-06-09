#include <std.h>
inherit DAEMON;

#define BLASTTYPES (({ "frightful", "glacial", "brimstone", "lifedrinker", "vitriolic", "beshadowed", "binding", "utterdark" }))

int cmd_blasttype(string str)
{
    string spellname, masteredspells;
    if (!TP->is_class("warlock")) {
        return 0;
    }
    if (!str) {
        if (TP->query("warlock_blast_type")) {
            TP->delete("warlock_blast_type");
        }
        tell_object(TP, "%^BOLD%^%^WHITE%^You will now cast your eldritch blast with no essence applied.%^RESET%^");
        return 1;
    }
    if (member_array(str, BLASTTYPES) == -1) {
        tell_object(TP, "%^BOLD%^%^WHITE%^That is not a valid eldritch essence.%^RESET%^");
        return 1;
    }
    spellname = str + " blast";
    masteredspells = ({});
    masteredspells += TP->query_mastered_spells("warlock");
    if (!sizeof(masteredspells)) {
        tell_object(TP, "%^BOLD%^%^WHITE%^You don't know any essences!%^RESET%^");
        return 1;
    }
    if (member_array(spellname, masteredspells) == -1) {
        tell_object(TP, "%^BOLD%^%^WHITE%^You haven't learned that eldritch essence yet.%^RESET%^");
        return 1;
    }
    TP->set("warlock_blast_type", str);
    tell_object(TP, "%^BOLD%^%^WHITE%^You have set your eldritch essence to " + spellname + ".%^RESET%^");
    return 1;
}

int help()
{
    write("
%^CYAN%^NAME%^RESET%^

blasttype - change warlock blast essence

%^CYAN%^SYNTAX%^RESET%^

blasttype [TYPE]

%^CYAN%^DESCRIPTION%^RESET%^

This command will set your eldritch blast essence to the specified type. If no argument is given, you will cast without an essence applied. You may only apply an essence that you have learned.

%^CYAN%^SEE ALSO%^RESET%^

cast, warlock, spells, master
");
    return 1;
}
