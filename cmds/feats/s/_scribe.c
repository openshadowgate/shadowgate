#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("instant");
    feat_category("ArcaneSpellcraft");
    feat_name("scribe");
    feat_syntax("scribe SPELL_NAME [as level SPELL_LEVEL]");
    feat_prereq("Bard, Cleric, Druid, Inquisitor, Mage, Paladin, Ranger, Sorcerer, Oracle, Cypher");
    feat_desc("This feat allows a character to use their knowledge of the arcane to scribe simple scrolls of spells they already know. Such scrolls are only good for a single use. You must have an empty parchment sheet in your inventory for scribe to work. It has to be parchment, other writing materials won't do.

SPELL_NAME
  The spell you wish the scroll to cast when it is used.

SPELL_LEVEL
  Optinal scroll power you can specify. By default scroll will be scribed with maximum power available.

%^BOLD%^N.B.%^RESET%^ Multiclassing characters will use currently %^ULINE%^posed%^RESET%^ class for this feat. Use <pose> to switch it.");
    set_target_required(0);
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("mage") &&
        !ob->is_class("sorcerer") &&
        !ob->is_class("cleric") &&
        !ob->is_class("bard") &&
        !ob->is_class("inquisitor") &&
        !ob->is_class("oracle") &&
        !ob->is_class("ranger") &&
        !ob->is_class("cypher") &&
        !ob->is_class("paladin") &&
        !ob->is_class("druid")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_scribe(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    if (!stringp(str)) {
        str = "";
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object ob, tp;
    int level, number;
    int spell_clevel;
    string tmp, str, levelstring;
    ::execute_feat();

    if (!arg) {
        return help();
    }

    if (regexp(arg, "[ a-z]+ [0-9]")) {
        if (sscanf(arg, "%s as level %d", str, spell_clevel) != 2) {
            help();
            return 1;
        }
    } else if (regexp(arg, "[ a-z]+")) {
        if (sscanf(arg, "%s", str) != 1) {
            help();
            return 1;
        }
    } else {
        help();
        return 1;
    }

    tmp = MAGIC_D->get_spell_file_name(str);
    if (!objectp(find_object_or_load(tmp))) {
        tell_object(caster, "You don't know a spell named " + str + "."); return 1;
    }

    level = tmp->query_spell_level(TP->query_class());

    if (!FEATS_D->usable_feat(caster, "clone scroll") || (FEATS_D->usable_feat(caster, "clone scroll")  && (!present(str, caster) || !present(str, caster)->is_scroll()))) {
        if (MAGIC_D->is_mastering_class(TP->query_class()) && member_array(str, TP->query_mastered_spells(TP->query_class())) == -1) {
            tell_object(caster, "You don't have that spell mastered with your posed class.\n");
            return 1;
        }

        if (!(caster->query_memorized(TP->query_class(), str))) {
            tell_object(caster, "That spell isn't in your memory.\n");
            return 1;
        }
    }

    if (!spell_clevel) {
        spell_clevel = TP->query_guild_level(TP->query_class()) + TP->query_property("empowered");
    } else {
        if (spell_clevel > TP->query_guild_level(TP->query_class()) + TP->query_property("empowered")) {
            tell_object(caster, "%^BOLD%^%^RED%^You can't scribe spell with power so great. Maximum level available to you now is %^CYAN%^" + (TP->query_guild_level(TP->query_class()) + TP->query_property("empowered")) + "%^RED%^. \n");
            return 1;
        }
    }

    ob = present("parchment11", caster);
    if (!objectp(ob = present("parchment11", caster))) {
        tell_object(caster, "You don't have any parchment!");
        return 1;
    }

    tell_room(environment(caster), "%^BOLD%^" + caster->QCN + " sits and begins to scribe a spell onto some parchment.", caster);
    tell_object(caster, "%^BOLD%^You sit and start to scribe " + str + " onto the parchment.");

    call_out("scribe", ROUND_LENGTH, str, spell_clevel, caster, ob);

    return;
}

void cancel(object ob, string spell){
    if (!objectp(ob)) {
        return;
    }
    ob->remove();
    write("You interrupt your scribing.");
    tell_room(environment(caster),""+caster->QCN+" interrupts "+caster->QP+" attempt to scribe a new scroll.",caster);
    caster->remove_paralyzed();
    remove_call_out("scribe");
}

void scribe(string spell, int spell_clevel, object tp, object paper)
{
    object scroll, compbag;
    string tmp, * comp_names;
    int x;

    if (!objectp(paper)) {
        return 0;
    }
    if (!objectp(tp)) {
        return 0;
    }

    tell_object(tp, "%^BOLD%^You finish scribing " + spell + ".");
    tell_room(environment(tp), "%^BOLD%^" + tp->query_cap_name() + " finishes " + tp->QP + " scribing.", tp);
    scroll = new("/d/magic/scroll");
    scroll->set_spell_name(spell);
    scroll->set_passed((string)tp->query_name());
    scroll->set_clevel(spell_clevel);
    scroll->move(environment(tp));
    paper->remove();
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
