#include <std.h>

inherit DAEMON;

int help();

int cmd_dispell(string str)
{
    object* spells;

    TP->clear_targeted_spells();

    spells = TP->query_property("dispellable spells");
    spells = filter_array(spells, (: objectp($1) :));

    if (!pointerp(spells)) {
        message("info", "%^BOLD%^%^WHITE%^You have nothing listed as effecting you.", TP);
        return 1;
    }

    if (!strlen(str)) {
        int i;
        message("info", "%^RESET%^%^BOLD%^%^BLUE%^--==%^RESET%^%^BOLD%^%^CYAN%^< %^RESET%^%^BOLD%^Spells you maintain %^RESET%^%^BOLD%^%^CYAN%^>%^RESET%^%^BOLD%^%^BLUE%^==--%^RESET%^", TP);
        for (i = 0; i < sizeof(spells); i++) {
            if (objectp(spells[i])) {
                message("info", "%^BOLD%^%^BLUE%^" + sprintf("%2d", i) + ".%^BOLD%^GREEN%^ " + spells[i]->querySpellDisplay(), TP);
            }
        }
        return 1;
    }

    if (regexp(str, "^[0-9]+")) {
        if (objectp(spells[atoi(str)])) {
            write("BOLD%^%^CYAN%^You dispell " + spells[atoi(str)]->querySpellDisplay());
            spells[atoi(str)]->dest_effect();
        } else {
            write("%^BOLD%^%^CYAN%^No spell under this unmber.");
        }
        return 1;
    }

    if (str == "all") {
        object spell;
        foreach(spell in spells) {
            if (objectp(spell)) {
                write("%^BOLD%^%^CYAN%^You dispell " + spell->querySpellDisplay());
                spell->dest_effect();
            }
        }
        return 1;
    }

    {
        int allflag, tflag;
        object spell, target;
        string sname;
        string tname, targ;

        if (regexp(str, "all")) {
            allflag = 1;
        }

        if (regexp(str, " on ")) {
            tflag = 1;
        }


        sname = str;

        if (allflag && !tflag && sscanf(str, "all %s", sname) != 1) {
            write("%^BOLD%^%^CYAN%^You must provide the spell name.");
            return;
        }

        if (tflag && allflag && sscanf(str, "all on %s", tname) != 1) {
            write("%^BOLD%^%^CYAN%^You must provide the target.");
            return;
        }

        if (tflag && !allflag && sscanf(str, "%s on %s", sname, tname) != 2) {
            write("%^BOLD%^%^CYAN%^You must provide both spell name and target.");
            return;
        }

        foreach(spell in spells)
        {
            if (objectp(spell)) {

                if (sizeof(tname)) {
                    if (objectp(target = spell->query_target_object())) {
                        targ = lower_case(target->getParsableName());
                    } else {
                        targ = "";
                    }

                    if (objectp(present(tname, TP))) {
                        targ = tname;
                    }
                }

                if (spell->query_spell_name() == sname ||
                    tname = targ) {
                    write("%^BOLD%^%^CYAN%^You dispell " + spell->querySpellDisplay());
                    spell->dest_effect();
                    if (!allflag) {
                        break;
                    }
                }
            }
        }
        return 1;

    }


}

int
help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

dispell - display and manage active spells

%^CYAN%^SYNOPSIS%^RESET%^

dispell
dispell [%^ORANGE%^%^ULINE%^NUM%^RESET%^]
dispell [all] [%^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^]
dispell all|%^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^ on %^ORANGE%^%^ULINE%^TARGET_NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument, this command will list all spells you have casted and that are currently active. The list will update as spells go up and down. It won't list, however, spells someone casted on you.

Provide %^ORANGE%^%^ULINE%^NUM%^RESET%^ as an argument and spell on that list under that %^ORANGE%^%^ULINE%^NUM%^RESET%^ will be dispelled. Note that list numbering will be renewed after that.

Provide %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ and you will cancel effects of first spell with that name.

Provide keyword all and you will dispell all spells. If you follow keyword 'all' by %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^, you will dispell all spells with that %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^

Provide keyword all or %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ followed by %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ and you will dispell all effects caused by %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ on said %^ORANGE%^%^ULINE%^TARGET%^RESET%^. %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ can use any of target's valid ids.

%^CYAN%^SEE ALSO%^RESET%^

cast, prepare, buff, bonuses

"
        );
    return 1;
}
