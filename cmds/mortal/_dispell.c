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
        int allflag;
        object spell;
        string sname;

        if (regexp(str, "all")) {
            allflag = 1;
        }

        sname = str;

        if (allflag && sscanf(str, "all %s", sname) != 1) {
            write("%^BOLD%^%^CYAN%^You must provide the spell name.");
        }

        foreach(spell in spells)
        {
            if (objectp(spell)) {
                if (spell->query_spell_name() == sname) {
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

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument, this command will list all spells you have casted and that are currently active. The list will update as spells go up and down. It won't list, however, spells someone casted on you.

If you provide optional %^ORANGE%^%^ULINE%^NUM%^RESET%^ argument or a %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^, you'll cancel that spell's effect. Note, after you do so the list will be renewed. Keyword all will dispell all spells, if followed by %^ORANGE%^%^ULINE%^SPELL%^RESET%^ %^ORANGE%^%^ULINE%^NAME%^RESET%^ it will dispell all spells with that name.

%^CYAN%^SEE ALSO%^RESET%^

cast, prepare, buff, bonuses

"
        );
    return 1;
}
