/**
 * @file
 * @brief feats command
 */

/*
 * Some of functions in this file have an external use.
 */

//updated to include Psionics category for psions/psywarriors
//~Circe~ 9/3/15
#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <new_exp_table.h>
#include <schoolspells.h>
#include <feats.h>
#include <skills.h>
#include <class_types.h>

inherit DAEMON;

int help(string str);

int free;

int calculate_feat_cost(object ob)
{
    int level, exp;
    if (!objectp(ob)) {
        return 0;
    }

    if (free) {
        return 0;
    }

    if (ob->query("free_feats")) {
        return 0;
    }
    level = ob->query_highest_level();
    if (level == 1) {
        return 0;
    }
    if (!avatarp(ob)) {
        exp = exp_for_level(level) * 3 / 4;
        return exp;
    }
    return 0;
}

int remove_spell_mastery_spell(string str, object ob, string feat, string mytype)
{
    int num, level, okclasslvl, i, amt;
    object spell;
    string file, * okclasses, * myclasses, tmp;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }

    okclasses = ({});
    myclasses = ob->query_classes();
    if (!sizeof(myclasses)) {
        tell_object(ob, "Your classes are broken! Contact a wiz!");
        free = 0;
        return 1;
    }

    tmp = "/cmds/spells/" + str[0..0] + "/_" + replace_string(str, " ", "_") + ".c";
    if (!file_exists(tmp)) {
        tell_object(ob, "The spell " + str + " does not exist!");
        free = 0;
        return 1;
    }

    spell = new(tmp);
    for (i = 0; i < sizeof(myclasses); i++) {
        if ((int)spell->query_spell_level(myclasses[i]) > 0 && (int)spell->query_spell_level(myclasses[i]) < 3) {
            okclasses += ({ myclasses[i] }); // classes that allow it as a L1-2 spell only
            if (myclasses[i] == "bard" ||
                myclasses[i] == "inquisitor" ||
                myclasses[i] == "oracle" ||
                myclasses[i] == "sorcerer") {
                num++;
            }
        }
    }

    if (!sizeof(okclasses)) {
        tell_object(ob, "You do not have a class that can cast " + str + " at a suitable level.");
        free = 0;
        return 1;
    }

    for (i = 0; i < sizeof(okclasses); i++) {
        if ((int)ob->can_memorize(okclasses[i], str) == MEM_OK || (int)ob->can_memorize(okclasses[i], str) == TOO_MANY) {
            num++;
        }
    }

    if (!num) {
        tell_object(ob, "You can not cast the spell " + str + ".  Aborting...");
        free = 0;
        return 1;
    }

    tell_object(ob, "%^YELLOW%^Setting your SpellMastery spell to %^BLUE%^" + str + "%^YELLOW%^ upon removal of greater spell mastery feat.%^RESET%^");
    amt = calculate_feat_cost(ob);
    if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to remove the feat " +
                    feat + "?  It will cost you %^MAGENTA%^" + amt + "%^YELLOW%^ exp.%^RESET%^");
    }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to remove the feat " +
                    feat + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + amt + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
    }else {
        tell_object(ob, "%^YELLOW%^Are you sure you want to remove the feat " +
                    feat + "?");
    }
    tell_object(ob, "Enter <yes> to remove the feat, anything else to abort.");
    input_to("confirm_remove", ob, feat, str);
    return 1;
}

int spell_mastery_spell(string str, object ob, string feat, string mytype)
{
    int num, level, okclasslvl, i, amt;
    object spell;
    string file, * okclasses, * myclasses, tmp;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }

    okclasses = ({});
    myclasses = ob->query_classes();
    if (!sizeof(myclasses)) {
        tell_object(ob, "Your classes are broken! Contact a wiz!");
        free = 0;
        return 1;
    }

    tmp = "/cmds/spells/" + str[0..0] + "/_" + replace_string(str, " ", "_") + ".c";
    if (!file_exists(tmp)) {
        tell_object(ob, "The spell " + str + " does not exist!");
        free = 0;
        return 1;
    }

    spell = new(tmp);
    for (i = 0; i < sizeof(myclasses); i++) {
        if (feat != "spellmastery") {
            continue;
        }
        if (myclasses[i] == "warlock") {
            continue;
        }                                          // let's avert the warlocks taking this by mistake!
        // check for - greater than L0; either less than L3, or less than L6 for a mage either taking archmage & has spellmastery, or taking spellmastery & has archmage

        level = spell->query_spell_level(myclasses[i]);
        if (level < 1) {
            continue;
        }
        if (level > 5) {
            continue;
        }
        if (level < 3) {
            okclasses += ({ myclasses[i] });
            if (myclasses[i] == "bard" ||
                myclasses[i] == "inquisitor" ||
                myclasses[i] == "oracle" ||
                myclasses[i] == "sorcerer") {
                num++;
            }
            continue;
        }
        if (myclasses[i] != "mage" && myclasses[i] != "archmage") {
            continue;
        }
        if (level < 6) {
            if (FEATS_D->usable_feat(ob, "archmage") || FEATS_D->usable_feat(ob, "greater spell mastery")) {
                okclasses += ({ "mage" }); // want this to be mage, not archmage
                continue;
            }
        }
    }

    if (!sizeof(okclasses)) {
        tell_object(ob, "You do not have a class that can cast " + str + " at a suitable level.");
        free = 0;
        spell->remove();
        return 1;
    }

    for (i = 0; i < sizeof(okclasses); i++) {
        if ((int)ob->can_memorize(okclasses[i], str) == MEM_OK || (int)ob->can_memorize(okclasses[i], str) == TOO_MANY) {
            num++;
        }
    }

    if (!num) {
        tell_object(ob, "You can not cast the spell " + str + ".  Aborting...");
        free = 0;
        spell->remove();
        return 1;
    }
    amt = calculate_feat_cost(ob);
    switch (mytype) {
    case "sorc":
        tell_object(ob, "%^YELLOW%^Setting your SpellMastery spell to %^BLUE%^" + str + "%^YELLOW%^ with a free magic feat.%^RESET%^");
        break;

    default:
        tell_object(ob, "%^YELLOW%^Setting your SpellMastery spell to %^BLUE%^" + str + "%^YELLOW%^.%^RESET%^");
        break;
    }
    if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cost you %^MAGENTA%^" + amt + "%^YELLOW%^ exp.%^RESET%^");
    }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + amt + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
    }else {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?");
    }
    tell_object(ob, "Enter <yes> to add the feat, anything else to abort.");
    switch (mytype) {
    case "sorc":
        input_to("confirm_add_magic", ob, feat, str);
        spell->remove();
        return 1;

    default:
        input_to("confirm_add", ob, feat, str);
        spell->remove();
        return 1;
    }
    spell->remove();
    return 1;
}

int skill_focus_setting(string str, object ob, string feat)
{
    int myflag, i, amt;
    string* myclasses, * myclassskills, file;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }
    if (!stringp(str)) {
        return 0;
    }

    if (member_array(str, CORE_SKILLS) == -1) {
        tell_object(ob, "%^YELLOW%^The %^BLUE%^" + str + " %^YELLOW%^ skill does not exist, or is not a valid choice for this feat.%^RESET%^");
        tell_object(ob, "Aborting...");
        return 1;
    }
    myclasses = ob->query_classes();
    for (i = 0; i < sizeof(myclasses); i++) {
        file = DIR_CLASSES + "/" + myclasses[i] + ".c";
        if (file_exists(file)) {
            myclassskills = (string*)file->class_skills();
            if (member_array(str, myclassskills) != -1) {
                tell_object(ob, "%^RED%^Warning:%^YELLOW%^ you already have %^BLUE%^" + str + " %^YELLOW%^as a class skill from one or more of your existing classes.%^RESET%^");
            }
        }
    }
    amt = calculate_feat_cost(ob);
    tell_object(ob, "%^YELLOW%^Setting your Skill Focus feat to %^BLUE%^" + str + "%^YELLOW%^.%^RESET%^");
    if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cost you %^MAGENTA%^" + amt + "%^YELLOW%^ exp.%^RESET%^");
    }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && amt > 0) {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?  It will cause you to incur a character improvement tax of " +
                    "%^MAGENTA%^" + amt + "%^YELLOW%^.  This tax will reduce all future " +
                    "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
    }else {
        tell_object(ob, "%^YELLOW%^Are you sure you want to add the feat " +
                    feat + "?");
    }
    tell_object(ob, "Enter <yes> to add the feat, anything else to abort.");
    input_to("confirm_add", ob, feat, str);
    return 1;
}

int confirm_add(string str, object ob, string feat, string extradata)
{
    int price;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(TP, "Aborting...");
        free = 0;
        return 1;
    }

    price = calculate_feat_cost(ob);
    if ((int)TP->query("free_feats")) {
        TP->set("free_feats", ((int)TP->query("free_feats") - 1));
    }

    if (feat == "spellmastery" || feat == "archmage" || feat == "greater spell mastery") {
        ob->set("spellmastery_spell", extradata);
    }
    if (feat == "skill focus") {
        ob->set("skill_focus", extradata);
    }
    FEATS_D->add_my_feat(ob, "other", feat);
    //moved this down - otherwise feats that require a specific level will
    //never get added if the exp cost would cause you to lose a level - Saide
    if (!avatarp(TP)) {
        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0) {
            ob->add_exp(price * -1);
            ob->resetLevelForExp(0);
            tell_object(ob, "Subtracting " + price + " experience points.");
            log_file("added_feats", "" + ob->QCN + " added " + feat + " on " + ctime(time()) + " for " + price + " exp\n");
        }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1) {
            if ((int)ob->set_XP_tax(price, 0, "improvement") == -1) {
                tell_object(ob, "Currently your character improvement tax is above the maximum allowed. " +
                            "You must first reduce it before you can add this feat.");
                return 1;
            }
            if (price > 0) {
                tell_object(ob, "Incuring character improvement tax of " + price + ". All future experience gained will be " +
                            "reduced by 50% until it is repaid.");
            }
            log_file("added_feats", "" + ob->QCN + " added " + feat + " on " + ctime(time()) + " for a character improvement tax of " + price + ".\n");
        }
    }
    tell_object(ob, "%^YELLOW%^Congratulations, you have successfully added "
                "the feat %^BLUE%^" + feat + "%^YELLOW%^!%^RESET%^");
    free = 0;
    return 1;
}

int confirm_add_bonus(string str, object ob, string feat)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(TP, "Aborting...");
        return 1;
    }

    FEATS_D->add_my_feat(ob, "bonus", feat);
    log_file("added_feats", "" + ob->QCN + " added combat bonus feat " + feat + " on " + ctime(time()) + ".\n");
    tell_object(ob, "%^YELLOW%^Congratulations, you have successfully added "
                "the bonus combat feat %^BLUE%^" + feat + "%^YELLOW%^!%^RESET%^");
    return 1;
}

int confirm_add_magic(string str, object ob, string feat, string extradata)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(TP, "Aborting...");
        free = 0;
        return 1;
    }
    if (feat == "spellmastery") {
        ob->set("spellmastery_spell", extradata);
    }
    FEATS_D->add_my_feat(ob, "magic", feat);
    log_file("added_feats", "" + ob->QCN + " added magic bonus feat " + feat + " on " + ctime(time()) + ".\n");
    tell_object(ob, "%^YELLOW%^Congratulations, you have successfully added "
                "the bonus magic feat %^BLUE%^" + feat + "%^YELLOW%^!%^RESET%^");
    free = 0;
    return 1;
}

int confirm_add_hybrid(string str, object ob, string feat, string extradata)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(TP, "Aborting...");
        free = 0;
        return 1;
    }
    if (feat == "spellmastery") {
        ob->set("spellmastery_spell", extradata);
    }
    FEATS_D->add_my_feat(ob, "hybrid", feat);
    log_file("added_feats", "" + ob->QCN + " added hybrid bonus feat " + feat + " on " + ctime(time()) + ".\n");
    tell_object(ob, "%^YELLOW%^Congratulations, you have successfully added "
                "the bonus hybrid feat %^BLUE%^" + feat + "%^YELLOW%^!%^RESET%^");
    free = 0;
    return 1;
}

int confirm_remove(string str, object ob, string feat, string extradata)
{
    int price, i;
    string* myspells, * schoolspells;

    if (!objectp(ob)) {
        return 0;
    }
    if (!stringp(feat)) {
        return 0;
    }

    if (str != "yes") {
        tell_object(ob, "Aborting...");
        return 1;
    }
    if ((feat == "archmage" && extradata != "") || (feat == "greater spell mastery" && extradata != "")) {
        ob->set("spellmastery_spell", extradata);
    }                                                                                                                                                // has to be reset to L1-2 if they have it.
    if (feat == "spellmastery") {
        ob->delete("spellmastery_spell");
    }
    if (feat == "skill focus") {
        ob->delete("skill_focus");
    }

    price = calculate_feat_cost(ob) / 8;
    if (!avatarp(TP)) {
        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0) {
            ob->add_exp(price * -1);
            ob->resetLevelForExp(0);
            tell_object(ob, "Subtracting " + price + " experience points.");
            log_file("removed_feats", "" + ob->QCN + " removed " + feat + " on " + ctime(time()) + " for " + price + " exp\n");
        }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1) {
            if ((int)ob->set_XP_tax(price, 0, "improvement") == -1) {
                tell_object(ob, "Currently your character improvement tax is above the maximum allowed. " +
                            "You must first reduce it before you can remove this feat.");
                return 1;
            }
            if (price > 0) {
                tell_object(ob, "Incuring character improvement tax of " + price + ". All future experience gained will be " +
                            "reduced by 50% until it is repaid.");
            }
            log_file("removed_feats", "" + ob->QCN + " removed " + feat + " on " + ctime(time()) + " for a character improvement tax of " + price + ".\n");
        }
    }
    if ((int)ob->query("free_feats")) {
        ob->set("free_feats", ((int)TP->query("free_feats") - 1));
    }
    FEATS_D->remove_my_feat(ob, feat);
    tell_object(ob, "%^YELLOW%^You have successfully removed the feat "
                "%^MAGENTA%^" + feat + ".%^RESET%^");
    return 1;
}

int cmd_feats(string str)
{
    object ob;
    string* info = ({}), tmp, feat, * required, * my_required = ({}), * my_tmp_feats = ({}), category, * subset = ({}), * feats = ({}), * melee_retool = ({});
    int i, j, MAX_ALLOWED, BONUS_ALLOWED, num_feats, allowed, num_bonus, bonus, my_lev, * featkeys;
    mapping classfeats, otherfeats, bonus_feats;

    find_object_or_load(FEATS_D);
    FEATS_D->update_usable(TP);

    if (!stringp(str)) {
//        FEATS_D->display_feats(TP,TP);
        tell_object(TP, "See <help feats> for syntax.");
        return 1;
    }

    str = lower_case(str);

    if (avatarp(TP) && objectp(ob = find_player(str))) {
        FEATS_D->display_feats(TP, ob);
        return 1;
    }

    if (!TP->query("new_class_type")) {
        return 1;
    }

    free = 0;

    info = explode(str, " ");

    switch (info[0]) {
    case "list":
        info -= ({ info[0] });
        if (!sizeof(info)) {
            FEATS_D->display_feats(TP, TP);
            return 1;
        }
        switch (info[0]) {
        case "spellcraft":
            FEATS_D->display_feats(TP, TP, "magic");
            return 1;

        case "martial":
            FEATS_D->display_feats(TP, TP, "melee");
            return 1;

        case "hybrid":
            FEATS_D->display_feats(TP, TP, "hybrid");
            return 1;

        case "general":
            FEATS_D->display_feats(TP, TP, "general");
            return 1;

        case "epic":
            if (!high_mortalp(TP) && !avatarp(TP) && CONFIG_D->check_config("HM") == 0) {
                FEATS_D->display_feats(TP, TP);
            }else {
                FEATS_D->display_feats(TP, TP, "epic");
            }
            return 1;

        default:
            FEATS_D->display_feats(TP, TP);
            return 1;
        }
        FEATS_D->display_feats(TP, TP);
        return 1;

    case "wipe":
        if (avatarp(TP)) {
            tell_object(TP, "Clearing feats for " + TP->query_true_name() + ".");
            TP->clear_feats();
            return 1;
        }else {
            if (!TP->query("free_feat_wipe")) {
                TP->set("free_feat_wipe", 1);
                TP->clear_feats();
                num_feats = ((int)TP->query_level() / 3) + 1;
                TP->set("free_feats", num_feats);
                if (!avatarp(TP)) {
                    tell_object(TP, "%^BOLD%^%^RED%^You have been given a feat wipe. Please reallocate your feats before going back out.%^RESET%^");
                }
                TP->force_me("feats fix");
            } else {
                tell_object(TP, "You already used your free feats wipe. Contact staff to get another one.");
            }
            return 1;
        }
        return 0;

    case "fix":
        required = TP->query_classes();
        if (!sizeof(required)) {
            return 1;
        }

        // first pickup current "other" feats that were bought
        otherfeats = TP->query_other_feats();
        featkeys = keys(otherfeats);
        num_feats = TP->query("free_feats");
        feats = ({});
        for (i = 0; i < sizeof(featkeys); i++) {
            feats += otherfeats[featkeys[i]];
        }

        //for fighter bonus feats - Saide
        otherfeats = TP->query_bonus_feats();
        featkeys = keys(otherfeats);
        for (i = 0; i < sizeof(featkeys); i++) {
            feats += otherfeats[featkeys[i]];
        }

        // now run addition of any missing class feats; remove from bought
        // feats first if they already did

        for (bonus = 0; bonus < sizeof(required); bonus++) {
            category = "/std/class/" + required[bonus] + ".c";
            if (!file_exists(category)) {
                continue;
            }
            tmp = (string)TP->query_combat_spec(required[bonus]);         // new combat spec code, N 1/14.
            classfeats = category->class_featmap(tmp);
            if (!mapp(classfeats)) {
                continue;
            }
            featkeys = keys(classfeats);
            if (sizeof(featkeys)) {
                for (i = 0; i < sizeof(featkeys); i++) {
                    if ((int)TP->query_class_level(required[bonus]) < featkeys[i]) {
                        continue;
                    }
                    subset = classfeats[featkeys[i]];
                    for (j = 0; j < sizeof(subset); j++) {
                        my_lev = ((int)TP->query_level()) - (int)TP->query_class_level(required[bonus]) + featkeys[i];
                        if (!my_lev) {
                            my_lev = 1;
                        }

                        if (member_array(subset[j], feats) != -1) { // if they have this as a bought feat, revoke
                            if ((string)FEATS_D->get_feat_type(TP, subset[j]) != "bonus") {
                                num_feats++;
                            }
                            FEATS_D->remove_my_feat(TP, subset[j], 1);
                            tell_object(TP, "%^YELLOW%^Moving feat %^BLUE%^" +
                                        subset[j] + "%^YELLOW%^ to class feats.");
                        }

                        if (!FEATS_D->has_feat(TP, subset[j])) {
                            tell_object(TP, "Adding " + required[bonus] + " class levelling feat: " +
                                        subset[j] + " at " + my_lev + ".");
                            FEATS_D->add_feat(TP, "class", subset[j], my_lev);
                        }
                    }
                }
                TP->set("free_feats", num_feats);
            }
        }
        return 1;

    case "check":
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }

        my_tmp_feats = (string*)TP->query_temporary_feats();
        TP->clear_temporary_feats();

        if (FEATS_D->can_use_feat(TP, tmp)) {
            tell_object(TP, "%^YELLOW%^Congratulations, you meet all of the requirements for "
                        "the feat " + tmp + ".%^RESET%^");
        }else {
            tell_object(TP, "%^RED%^You do not meet all of the requirements for the "
                        "feat " + tmp + ", please check the help file for the individual feats "
                        "for more information.%^RESET%^");
        }

        TP->set_temporary_feats(my_tmp_feats);
        return 1;

    case "allowed":
        MAX_ALLOWED = ((int)TP->query_highest_level() / 3) + 1;
        num_feats = (int)TP->query_other_feats_gained();
        allowed = MAX_ALLOWED - num_feats;
        if (allowed < 0) {
            allowed = 0;
        }
        subset = TP->query_classes();
        if (!sizeof(subset)) {
            tell_object(TP, "%^RED%^There is an error in the settings of your classes. Please notify a wiz with this error message.%^RESET%^");
            return 1;
        }

        tell_object(TP, "%^WHITE%^You are allowed %^BOLD%^%^BLUE%^" + MAX_ALLOWED + "%^RESET%^ "
                    "feats. You have used %^BOLD%^%^BLUE%^" + num_feats + " %^RESET%^and you now have "
                    "%^BOLD%^%^BLUE%^" + allowed + "%^RESET%^ left.%^RESET%^");

// combat feat allocation here
        BONUS_ALLOWED = 0;
        for (i = 0; i < sizeof(subset); i++) {
            if (member_array(subset[i], CASTERCLASSES) != -1) {
                continue;                                           // caster classes get no bonus melee feats!
            }
            if (member_array(subset[i], HYBRID) != -1) {
                continue;                                    // neither do hybrids!
            }
            if (subset[i] == "fighter") {
                j = (((int)TP->query_class_level(subset[i]) + 1) / 2) + 1;
            }else if (subset[i] == "paladin") {
                j = (((int)TP->query_class_level(subset[i]) + 4) / 5);
            }else {
                j = (((int)TP->query_class_level(subset[i]) - 16) / 5);
            }

            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }
        num_bonus = (int)TP->query_bonus_feats_gained();
        bonus = BONUS_ALLOWED - num_bonus;

        if (BONUS_ALLOWED) {
            tell_object(TP, "You have %^BOLD%^%^BLUE%^" + BONUS_ALLOWED + "%^RESET%^ free martial "
                        "bonus feats. You have used %^BOLD%^%^BLUE%^" + num_bonus + " %^RESET%^and you now have "
                        "%^BOLD%^%^BLUE%^" + bonus + "%^RESET%^ left.%^RESET%^");
        }

// magic feat allocation here
        BONUS_ALLOWED = 0;
        for (i = 0; i < sizeof(subset); i++) {
            if (member_array(subset[i], MELEECLASSES) != -1) {
// melee classes get no bonus caster feats!
                continue;
            }
            if (member_array(subset[i], HYBRID) != -1) {
// neither do hybrids!
                continue;
            }
            if (subset[i] == "psion" ||
                subset[i] == "sorcerer" ||
                subset[i] == "mage" ||
                subset[i] == "oracle") {
                j = (((int)TP->query_class_level(subset[i]) + 4) / 5);                                                                                   // psions/sorcs @ L1 & every 5 levels thereafter
            }else {
                j = (((int)TP->query_class_level(subset[i]) - 16) / 5);          // caster classes @ L21 & every 5 levels thereafter
            }
            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }
        num_bonus = (int)TP->query_magic_feats_gained();
        bonus = BONUS_ALLOWED - num_bonus;

        if (BONUS_ALLOWED) {
            tell_object(TP, "You have %^BOLD%^%^BLUE%^" + BONUS_ALLOWED + "%^RESET%^ free spellcraft "
                        "bonus feats. You have used %^BOLD%^%^BLUE%^" + num_bonus + " %^RESET%^and you now have "
                        "%^BOLD%^%^BLUE%^" + bonus + "%^RESET%^ left.%^RESET%^");
        }

// hybrid feat allocation here
        BONUS_ALLOWED = 0;
        for (i = 0; i < sizeof(subset); i++) {
            if (member_array(subset[i], MELEECLASSES) != -1) {
                continue;
            }
            if (member_array(subset[i], CASTERCLASSES) != -1) {
                continue;
            }
            if (subset[i] == "psywarrior") {
                j = ((int)TP->query_class_level(subset[i]) / 3) + 1;
            } else {
                j = (((int)TP->query_class_level(subset[i]) - 16) / 5);
            }
            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }
        num_bonus = (int)TP->query_hybrid_feats_gained();
        bonus = BONUS_ALLOWED - num_bonus;

        if (BONUS_ALLOWED) {
            tell_object(TP, "You have %^BOLD%^%^BLUE%^" + BONUS_ALLOWED + "%^RESET%^ free hybrid "
                        "bonus feats. You have used %^BOLD%^%^BLUE%^" + num_bonus + " %^RESET%^and you now have "
                        "%^BOLD%^%^BLUE%^" + bonus + "%^RESET%^ left.%^RESET%^");
        }

// free-cost feat allocation here
        if (TP->query("free_feats")) {
            tell_object(TP, "%^BOLD%^%^CYAN%^You currently have %^BLUE%^" + TP->query("free_feats") + "%^BOLD%^%^CYAN%^ free-cost feats.");
        }
        FEATS_D->display_feats(TP, TP, "allowed");
        return 1;

    case "add":
//        info -= ({ info[0] });
//        if(!sizeof(info))
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }

        tmp = replace_string(tmp, "_", " ");

//        if(sizeof(info)) { tmp = implode(info," "); }

        MAX_ALLOWED = ((int)TP->query_highest_level() / 3) + 1;
        num_feats = (int)TP->query_other_feats_gained();
        if (num_feats >= MAX_ALLOWED) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add "
                        "any more feats at your current level.%^RESET%^");
            return 1;
        }
        if (FEATS_D->has_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You already have that "
                        "feat.");
            return 1;
        }
        if (TP->query("negative level")) {
            tell_object(TP, "You have a negative level and must have it removed before " +
                        "you can add any feats!");
            return 1;
        }
        if (intp("/daemon/user_d.c"->get_scaled_level(TP))) {
            tell_object(TP, "You have scaled your level down and must revert it back to " +
                        "normal before you can add any feats!");
            return 1;
        }

        if ((string)FEATS_D->get_category(tmp) == "EpicFeats") {
            if (!high_mortalp(TP) && CONFIG_D->check_config("HM") == 0) {
                tell_object(TP, "%^RESET%^%^BOLD%^You must be a high "
                            "mortal to buy an epic feat.%^RESET%^");
                return 1;
            }
            if ((int)TP->query_epic_feats_gained() > 0) {
                tell_object(TP, "%^RESET%^%^BOLD%^You have already bought "
                            "an epic feat. You can only have one at a time.%^RESET%^");
                return 1;
            }
        }

        my_tmp_feats = (string*)TP->query_temporary_feats();
        TP->clear_temporary_feats();

        if (!FEATS_D->can_gain_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add the "
                        "feat " + tmp + ", please make sure you meet all of the "
                        "requirements.%^RESET%^");
            TP->set_temporary_feats(my_tmp_feats);
            return 1;
        }

        TP->set_temporary_feats(my_tmp_feats);

        if (tmp == "spellmastery") {
            if (FEATS_D->has_feat(TP, "archmage") || FEATS_D->has_feat(TP, "greater spell master")) {
                tell_object(TP, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                            "select a spell that you are currently able to cast that is up to "
                            "level 5.  You can pick any spell of levels 1 through 5 that you "
                            "are able to cast.%^RESET%^");
            }else {
                tell_object(TP, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                            "select a spell that you are currently able to cast that is level 1 "
                            "or level 2.  You can pick any spell of level 1 or level 2 that you "
                            "are able to cast.%^RESET%^");
            }
            tell_object(TP, "Please type the name of the spell that you would like "
                        "your spellmastery feat to use.");
            input_to("spell_mastery_spell", TP, tmp, "normal");
            return 1;
        }
        if ((tmp == "archmage" || tmp == "greater spell mastery") && FEATS_D->has_feat(TP, "spellmastery")) {
            tell_object(TP, "%^YELLOW%^In order to gain the archmage feat, you must "
                        "re-confirm your spellmastery spell by selecting any up to level 5.  "
                        "You can pick any spell of levels 1 through 5 that you are able to "
                        "cast.%^RESET%^");
            tell_object(TP, "Please type the name of the spell that you would like "
                        "your spellmastery feat to use.");
            input_to("spell_mastery_spell", TP, tmp, "normal");
            return 1;
        }
        if (tmp == "skill focus") {
            tell_object(TP, "%^YELLOW%^In order to gain the skill focus feat, you must "
                        "select a skill that you wish to learn as a class-skill.  You can pick "
                        "any skill that isn't already class-based.%^RESET%^");
            tell_object(TP, "Please type the name of the skill that you would like "
                        "your skill focus feat to use.");
            input_to("skill_focus_setting", TP, tmp);
            return 1;
        }

        // allow_shifted()

        for (i = 0; i < sizeof(SHIFTING_CLASSES); i++) {
            if (TP->is_class(SHIFTING_CLASSES[i])) {
                if (!("/cmds/feats/" + tmp[0..0] + "/_" + replace_string(tmp, " ", "_") + ".c")->allow_shifted()) {
                    tell_object(TP, "%^RED%^The feat " + tmp + " can not be used while you are shapeshifed, but "
                                "it will still work as normal while you are in your regular form.");
                    break;
                }
            }
        }
        i = calculate_feat_cost(TP);
        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && i > 0) {
            tell_object(TP, "%^YELLOW%^Are you sure you want to add the feat " + tmp + "?  It will "
                        "cost you %^MAGENTA%^" + i + " %^YELLOW%^exp.%^RESET%^");
        }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && i > 0) {
            tell_object(TP, "%^YELLOW%^Are you sure you want to add the feat " + tmp + "?  It will "
                        "cause you to incur a character improvement tax of %^MAGENTA%^" + i + "%^YELLOW%^.  " +
                        "This tax will cause all future experience gained to be reduced by %^RED%^50%%^YELLOW%^" +
                        " until it is repaid.%^RESET%^");
        }else {
            tell_object(TP, "%^YELLOW%^Are you sure you want to add the feat " + tmp + "?");
        }
        tell_object(TP, "Enter <yes> to add the feat, anything else to abort.");
        input_to("confirm_add", TP, tmp, "");
        return 1;

    case "martial":
//        info -= ({ info[0] });
//	  if(!sizeof(info))
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }
//        if(sizeof(info)) { tmp = implode(info," "); }

        subset = TP->query_classes();
        if (!sizeof(subset)) {
            tell_object(TP, "%^RED%^There is an error in the settings of your classes. Please notify a wiz with this error message.%^RESET%^");
            return 1;
        }

        BONUS_ALLOWED = 0;
        for (i = 0; i < sizeof(subset); i++) {
            if (member_array(subset[i], CASTERCLASSES) != -1) {
                continue;                                           // caster classes get no bonus melee feats!
            }
            if (member_array(subset[i], HYBRID) != -1) {
                continue;                                    // neither do hybrids!
            }
            if (subset[i] == "fighter") {
                j = (((int)TP->query_class_level(subset[i]) + 1) / 2) + 1;
            }else if (subset[i] == "paladin") {
                j = (((int)TP->query_class_level(subset[i]) + 4) / 5);
            }else {
                j = (((int)TP->query_class_level(subset[i]) - 16) / 5);
            }

            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }

        num_bonus = (int)TP->query_bonus_feats_gained();
        if (num_bonus >= BONUS_ALLOWED) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add "
                        "any more bonus combat feats at your current level.%^RESET%^");
            return 1;
        }
        if (FEATS_D->has_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You already have that "
                        "feat.");
            return 1;
        }
        if (TP->query("negative level")) {
            tell_object(TP, "You have a negative level and must have it removed before " +
                        "you can add any feats!");
            return 1;
        }
        if (intp("/daemon/user_d.c"->get_scaled_level(TP))) {
            tell_object(TP, "You have scaled your level down and must revert it back to " +
                        "normal before you can add any feats!");
            return 1;
        }
        if ((string)FEATS_D->get_category(tmp) == "EpicFeats") {
            tell_object(TP, "%^RESET%^%^BOLD%^You can't buy epic feats "
                        "with class bonus slots.%^RESET%^");
            return 1;
        }

        my_tmp_feats = (string*)TP->query_temporary_feats();
        TP->clear_temporary_feats();

        if (!FEATS_D->can_gain_bonus_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add the "
                        "feat " + tmp + ", please make sure you meet all of the "
                        "requirements.%^RESET%^");
            TP->set_temporary_feats(my_tmp_feats);
            return 1;
        }

        TP->set_temporary_feats(my_tmp_feats);

        category = FEATS_D->get_category(tmp);
        if (member_array(category, MELEEFEATS) == -1) {
            tell_object(TP, "%^YELLOW%^The %^BLUE%^" + tmp + " %^YELLOW%^ feat is not a combat feat.%^RESET%^");
            tell_object(TP, "Aborting...");
            return 1;
        }
        tell_object(TP, "%^YELLOW%^Are you sure you want to add the feat " + tmp + " as one of "
                    "your free bonus combat feats?  It will cost nothing to add, but you will have "
                    "to spend exp to remove it later if you change your mind.%^RESET%^");
        tell_object(TP, "Enter <yes> to add the feat, anything else to abort.");
        input_to("confirm_add_bonus", TP, tmp);
        return 1;

    case "spellcraft":
//        info -= ({ info[0] });
//	  if(!sizeof(info))
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }
//        if(sizeof(info)) { tmp = implode(info," "); }

        subset = TP->query_classes();
        if (!sizeof(subset)) {
            tell_object(TP, "%^RED%^There is an error in the settings of your classes. Please notify a wiz with this error message.%^RESET%^");
            return 1;
        }

        BONUS_ALLOWED = 0;
        for (i = 0; i < sizeof(subset); i++) {
            if (member_array(subset[i], MELEECLASSES) != -1) {
                continue;                                                      // melee classes get no bonus caster feats!
            }
            if (member_array(subset[i], HYBRID) != -1) {
                continue;                                                // neither do hybrids!
            }
            if (subset[i] == "psion" ||
                subset[i] == "sorcerer" ||
                subset[i] == "mage" ||
                subset[i] == "oracle") {
                j = (((int)TP->query_class_level(subset[i]) + 4) / 5);                                                                                   // psions/sorcs @ L1 & every 5 levels thereafter
            }else {
                j = (((int)TP->query_class_level(subset[i]) - 16) / 5);          // caster classes @ L21 & every 5 levels thereafter
            }
            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }
        //changing this to use "magic" feats instead of bonus - Saide
        num_bonus = (int)TP->query_magic_feats_gained();
        //num_bonus   = (int)TP->query_bonus_feats_gained();
        if (num_bonus >= BONUS_ALLOWED) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add "
                        "any more bonus magic feats at your current level.%^RESET%^");
            return 1;
        }
        if (FEATS_D->has_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You already have that "
                        "feat.");
            return 1;
        }
        if (TP->query("negative level")) {
            tell_object(TP, "You have a negative level and must have it removed before " +
                        "you can add any feats!");
            return 1;
        }
        if (intp("/daemon/user_d.c"->get_scaled_level(TP))) {
            tell_object(TP, "You have scaled your level down and must revert it back to " +
                        "normal before you can add any feats!");
            return 1;
        }
        if ((string)FEATS_D->get_category(tmp) == "EpicFeats") {
            tell_object(TP, "%^RESET%^%^BOLD%^You can't buy epic feats "
                        "with class bonus slots.%^RESET%^");
            return 1;
        }

        my_tmp_feats = (string*)TP->query_temporary_feats();
        TP->clear_temporary_feats();

        if (!FEATS_D->can_gain_magic_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add the "
                        "feat " + tmp + ", please make sure you meet all of the "
                        "requirements.%^RESET%^");
            TP->set_temporary_feats(my_tmp_feats);
            return 1;
        }

        TP->set_temporary_feats(my_tmp_feats);

        category = FEATS_D->get_category(tmp);
        if (member_array(category, SPELLFEATS) == -1) {
            tell_object(TP, "%^YELLOW%^The %^BLUE%^" + tmp + " %^YELLOW%^ feat is not a magic feat.%^RESET%^");
            tell_object(TP, "Aborting...");
            return 1;
        }

        free = 1;  // special tracking for spellmastery since it can be added as spellcraft free feat

        if (tmp == "spellmastery") {
            if (FEATS_D->has_feat(TP, "archmage") || FEATS_D->has_feat(TP, "greater spell mastery")) {
                tell_object(TP, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                            "select a spell that you are currently able to cast that is up to "
                            "level 5.  You can pick any spell of levels 1 through 5 that you "
                            "are able to cast.%^RESET%^");
            }else {
                tell_object(TP, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                            "select a spell that you are currently able to cast that is level 1 "
                            "or level 2.  You can pick any spell of level 1 or level 2 that you "
                            "are able to cast.%^RESET%^");
            }
            tell_object(TP, "Please type the name of the spell that you would like "
                        "your spellmastery feat to use.");
            input_to("spell_mastery_spell", TP, tmp, "sorc");
            return 1;
        }
        tell_object(TP, "%^YELLOW%^Are you sure you want to add the feat " + tmp + " as one of "
                    "your free bonus magic feats?  It will cost nothing to add, but you will have "
                    "to spend exp to remove it later if you change your mind.%^RESET%^");
        tell_object(TP, "Enter <yes> to add the feat, anything else to abort.");
        input_to("confirm_add_magic", TP, tmp, "");
        return 1;

    case "hybrid":
//        info -= ({ info[0] });
//	  if(!sizeof(info))
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }
//        if(sizeof(info)) { tmp = implode(info," "); }

        subset = TP->query_classes();
        if (!sizeof(subset)) {
            tell_object(TP, "%^RED%^There is an error in the settings of your classes. Please notify a wiz with this error message.%^RESET%^");
            return 1;
        }

        BONUS_ALLOWED = 0;
        for (i = 0; i < sizeof(subset); i++) {
            if (member_array(subset[i], MELEECLASSES) != -1) {
                continue;
            }
            if (member_array(subset[i], CASTERCLASSES) != -1) {
                continue;
            }
            if (subset[i] == "psywarrior") {
                j = ((int)TP->query_class_level(subset[i]) / 3) + 1;
            } else {
                j = (((int)TP->query_class_level(subset[i]) - 16) / 5);
            }
            if (j < 0) {
                j = 0;
            }
            BONUS_ALLOWED += j;
        }

        num_bonus = (int)TP->query_hybrid_feats_gained();
        if (num_bonus >= BONUS_ALLOWED) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add "
                        "any more bonus hybrid feats at your current level.%^RESET%^");
            return 1;
        }
        if (FEATS_D->has_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You already have that "
                        "feat.");
            return 1;
        }
        if (TP->query("negative level")) {
            tell_object(TP, "You have a negative level and must have it removed before " +
                        "you can add any feats!");
            return 1;
        }
        if (intp("/daemon/user_d.c"->get_scaled_level(TP))) {
            tell_object(TP, "You have scaled your level down and must revert it back to " +
                        "normal before you can add any feats!");
            return 1;
        }
        if ((string)FEATS_D->get_category(tmp) == "EpicFeats") {
            tell_object(TP, "%^RESET%^%^BOLD%^You can't buy epic feats "
                        "with class bonus slots.%^RESET%^");
            return 1;
        }

        my_tmp_feats = (string*)TP->query_temporary_feats();
        TP->clear_temporary_feats();

        if (!FEATS_D->can_gain_hybrid_feat(TP, tmp)) {
            tell_object(TP, "%^RESET%^%^BOLD%^You are not able to add the "
                        "feat " + tmp + ", please make sure you meet all of the "
                        "requirements.%^RESET%^");
            TP->set_temporary_feats(my_tmp_feats);
            return 1;
        }

        TP->set_temporary_feats(my_tmp_feats);

        category = FEATS_D->get_category(tmp);
        if (member_array(category, SPELLFEATS) == -1 && member_array(category, MELEEFEATS) == -1) {
            tell_object(TP, "%^YELLOW%^The %^BLUE%^" + tmp + " %^YELLOW%^ feat is not a hybrid feat.%^RESET%^");
            tell_object(TP, "Aborting...");
            return 1;
        }

        free = 1;  // special tracking for spellmastery since it can be added as spellcraft free feat

        if (tmp == "spellmastery") {
            if (FEATS_D->has_feat(TP, "archmage") || FEATS_D->has_feat(TP, "greater spell mastery")) {
                tell_object(TP, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                            "select a spell that you are currently able to cast that is up to "
                            "level 5.  You can pick any spell of levels 1 through 5 that you "
                            "are able to cast.%^RESET%^");
            }else {
                tell_object(TP, "%^YELLOW%^In order to gain the spellmastery feat, you must "
                            "select a spell that you are currently able to cast that is level 1 "
                            "or level 2.  You can pick any spell of level 1 or level 2 that you "
                            "are able to cast.%^RESET%^");
            }
            tell_object(TP, "Please type the name of the spell that you would like "
                        "your spellmastery feat to use.");
            input_to("spell_mastery_spell", TP, tmp, "sorc");
            return 1;
        }
        tell_object(TP, "%^YELLOW%^Are you sure you want to add the feat " + tmp + " as one of "
                    "your free bonus hybrid feats?  It will cost nothing to add, but you will have "
                    "to spend exp to remove it later if you change your mind.%^RESET%^");
        tell_object(TP, "Enter <yes> to add the feat, anything else to abort.");
        input_to("confirm_add_hybrid", TP, tmp, "");
        return 1;

    case "remove":
//        info -= ({ info[0] });
//	  if(!sizeof(info))
        if (sscanf(str, "%s %s", category, tmp) != 2) {
            tell_object(TP, "See <help feats> for syntax.");
            return 1;
        }
//        if(sizeof(info)) { tmp = implode(info," "); }
        if (!FEATS_D->can_remove_feat(TP, tmp)) {
            feat = "/cmds/feats/" + tmp[0..0] + "/_" + replace_string(tmp, " ", "_") + ".c";
            if (!file_exists(feat)) {
                tell_object(TP, "%^BOLD%^The feat " + tmp + " is not a real feat, "
                            "please check your spelling and try again.");
                return 1;
            }
            required = (string*)feat->query_required_for();
            for (i = 0; i < sizeof(required); i++) {
                if (FEATS_D->has_feat(TP, required[i])) {
                    my_required += ({ required[i] });
                }
            }
            if (!sizeof(my_required)) {
                tell_object(TP, "%^BOLD%^The feat " + tmp + " is a feat that you were granted "
                            "freely for your class.  You are not allowed to remove it.");
            }else {
                tell_object(TP, "%^BOLD%^The feat " + tmp + " is a feat required by others.  You "
                            "must also get rid of " + implode(my_required, " ") + " before you can remove "
                            "your " + tmp + " feat.");
            }
        }else {
            if (TP->query("negative level")) {
                tell_object(TP, "You have a negative level and must have it removed before " +
                            "you can remove any feats!");
                return 1;
            }
            if (intp("/daemon/user_d.c"->get_scaled_level(TP))) {
                tell_object(TP, "You have scaled your level down and must revert it back to " +
                            "normal before you can remove any feats!");
                return 1;
            }
            i = calculate_feat_cost(TP);
            if ((tmp == "archmage" || tmp == "greater spell mastery") && FEATS_D->has_feat(TP, "spellmastery")) {
                if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && i > 0) {
                    tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                                "" + tmp + "?  It will cost you %^MAGENTA%^" + i + "%^YELLOW%^ "
                                "exp, and you will be required to re-confirm your spellmastery option.%^RESET%^");
                }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && i > 0) {
                    tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                                "" + tmp + "?  It will cause you to incur a character improvement tax of " +
                                "%^MAGENTA%^" + i + "%^YELLOW%^.  This tax will reduce all future " +
                                "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid, "
                                "and you will be required to re-confirm your spellmastery option.%^RESET%^");
                }else {
                    tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                                "" + tmp + "?");
                }
                tell_object(TP, "Please type the name of the spell that you would like "
                            "your spellmastery feat to use.  It must be of level 1 or 2 only.  Type anything "
                            "else to abort.");
                input_to("remove_spell_mastery_spell", TP, tmp);
                return 1;
            }

            if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0 && i > 0) {
                tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                            "" + tmp + "?  It will cost you %^MAGENTA%^" + i + "%^YELLOW%^ exp.%^RESET%^");
            }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1 && i > 0) {
                tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat "
                            "" + tmp + "?  It will cause you to incur a character improvement tax of " +
                            "%^MAGENTA%^" + i + "%^YELLOW%^.  This tax will reduce all future " +
                            "experience gained by %^RED%^50%%^YELLOW%^ until it is repaid.%^RESET%^");
            }else {
                tell_object(TP, "%^YELLOW%^Are you sure you want to remove the feat " +
                            tmp + "?");
            }
            tell_object(TP, "Enter <yes> to remove the feat " + tmp + ", anything else to "
                        "abort.");
            input_to("confirm_remove", TP, tmp, "");
        }
        return 1;
    }
    tell_object(TP, "See <help feats> for syntax.");
    return 1;
}

int human_bonus_feat()
{
    string myrace, subrace;
    myrace = TP->query_race();
    subrace = (string)TP->query("subrace");

    if (myrace == "human") {
        if (!subrace || subrace == "" || (subrace != "tiefling" && subrace != "aasimar" && subrace != "feytouched" && (strsrch(subrace, "genasi") == -1))) {
            return 1; //bonus feat for baseline humans
        }
    }
    return 0;
}

int help()
{
    write("
%^CYAN%^NAME%^RESET%^

feats - manipulate or view your feats

%^CYAN%^SYNTAX%^RESET%^

feats allowed
feats check|add|remove %^ULINE%^%^ORANGE%^FEAT_NAME%^RESET%^
feats martial|spellcraft|hybrid %^ULINE%^%^ORANGE%^FEAT_NAME%^RESET%^
feats list [martial|spellcraft|hybrid|general]
feats fix

%^CYAN%^DESCRIPTION%^RESET%^

Feats represents specialized techniques or powers a character can learn throughout its career. Some feats are class-specific (usually gained for free with class-levels), while others are generic and must be paid for by adding to your exp tax (see <help exp tax>). A character gains 1 generic feat every 3. level which can be bought in such a way. Feats awarded by character class are added automatically. Some classes gain additional free feats known as bonus feats. When you level your character, you will get notified if you are allowed new feats.

Feats are divided into types (martial, spellcraft, hybrid, generic, epic) and organized in feat trees.  Some feats have prerequisites as specified in their individual help files.

The following commands apply:

%^ORANGE%^<feats allowed>%^RESET%^
    Tells you how many feats you are allowed at your current level.
%^ORANGE%^<feats check %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Tells you if you meet all the requirements to take this feat.
%^ORANGE%^<feats add %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Will add the feat if you have any remaining levelling feats.
%^ORANGE%^<feats remove %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Will remove the feat if you no longer want to retain it.
%^ORANGE%^<feats martial|spellcraft|hybrid %^ORANGE%^%^ULINE%^FEAT%^RESET%^%^ORANGE%^>%^RESET%^
    Will add the feat of given category if you have any bonus feats in it.
%^ORANGE%^<feats list martial|spellcraft|hybrid|general|epic>%^RESET%^
    Displays the specified feat trees.
%^ORANGE%^<feats fix>%^RESET%^
    Will attempt to fix your feat tree. If your feats seem incorrect, use this command.
%^ORANGE%^<feats wipe>%^RESET%^
    Will wipe all your feats once per character or if devs granted you free wipe.

%^CYAN%^COLOR CODING%^RESET%^

If your terminal supports color, you may benefit from color coding of the feats according to type, status and if the player has the feat or not:
  %^CYAN%^-- Feat%^RESET%^: Does not have feat.
  %^RESET%^%^RED%^00 Feat%^RESET%^: Has feat, but no longer meets prerequisites.
  %^BOLD%^%^GREEN%^00 Feat%^RESET%^: Has feat and it gives a permanent bonus.
  %^YELLOW%^00 Feat:%^RESET%^ Has duration feat which is currently active.
  %^BOLD%^%^CYAN%^00 Feat%^RESET%^: Requires input from character to activate feat.
  %^BOLD%^%^BLUE%^00 Feat%^RESET%^: A temporary feat which has been granted by an item or spell.
The numbers listed before the feats indicate which level the feats were gained at:
  %^BOLD%^%^CYAN%^00%^RESET%^: The feat has been bought normally.
  %^BOLD%^%^MAGENTA%^00%^RESET%^: The feat has been granted for free (class feats).
  %^YELLOW%^00%^RESET%^: The feat has been bought with bonus combat, magic or hybrid feats.

Adding and removing normal feats will add to your character improvement tax (see %^ORANGE%^<help exp tax>%^RESET%^) and slow your level advancement. This is to simulate the extra training that it requires to learn the new abilities or to forget your previous training.

%^CYAN%^SEE ALSO%^RESET%^

exp tax, skills, stats, score, hp, bonuses
");

    if (avatarp(TP)) {
        write("
%^CYAN%^IMMORTALS%^RESET%^

feats %^ULINE%^%^ORANGE%^PLAYER%^RESET%^

    To see a list of their feats.

feats wipe

    To clear all of your feats.
");
    }
    return 1;
}
