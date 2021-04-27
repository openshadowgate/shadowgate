#include <std.h>

inherit "/d/magic/symbols/shar_symbol.c";

void set_holy_symbol2(string spell,string spellname) {
    int spell_level;

    if (!spells) spells = ([]);
    if (!spellname) {
        tell_player(TP,"Give it a bloody name ya noob");
        return 1;
    }
    if (spell) {
        if (file_exists(spell)) {
            spell_level=spell->query_spell_level();
            if (!spell_level) return;
            if (!spell) return;
            spells[spellname] = spell_level;
            return 1;
        }
        return 0;
    }
    return 0;
}
