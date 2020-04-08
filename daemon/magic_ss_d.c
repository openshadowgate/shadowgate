#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

// This def is not yet needed for anything
#define MAGIC_SS_D_SAVE "/daemon/save/magic_ss_d"

mapping class_spells;
#include <class_spells.h>

void create()
{
    ::create();
}

string *query_class_special_spells(string mclass, string special)
{
    if (!mapp(class_spell_storage)) {
        return ({});
    }

    if (!arrayp(class_spell_storage[mclass][special])) {
        return ({});
    } else {
        return class_spell_storage[mclass][special];
    }
}
