// Feat was opened to cleric/druid/oracle spells, but never had settings for their spell type.
// Have put in a half-fix for now to select the first default class that can cast it.
// Temporary overrides for sorc -> mage and oracle -> cleric cuz all sorc spells are "mage",
// and most oracle spells are cleric, so will conflict if querying by base class.
// Will at least stop people enchanting spells from classes they don't have for now!
// Longterm it needs a proper set of queries for can_cast etc. N, 7/3/20.
#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

string castclass;

void create()
{
    ::create();
    feat_type("instant");
    feat_category("ArcaneSpellcraft");
    feat_name("enchant");
    feat_syntax("enchant ITEM");
    feat_classes(({"mage", "sorcerer", "oracle", "druid", "cleric", "psion"}));
    feat_desc("This feat allows a caster to enchant items with charges of spells they already know. The enchanted item can be used as easily by the caster themselves, as those without training. Creating such an item drains the essence of the mage, however, and should not be taken lightly.

Enchanting uses gems as material components. Any gem would do, but it will be destroyed on use.");
    feat_prereq("Mage, Sorcerer, Psion, Cleric, Druid, Oracle");
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
        !ob->is_class("cleric") &&
        !ob->is_class("druid") &&
        !ob->is_class("oracle") &&
        !ob->is_class("sorcerer") &&
        !ob->is_class("psion")) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_enchant(string str)
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
    object ob;

    if (!arg) {
        return help();
    }
    if (caster->query_bound()) {
        write("You can't enchant an item whilst bound.");
        return 1;
    }

    ob = present(arg, caster);
    if (!objectp(ob)) {
        ob = present(arg, environment(caster));
    }
    if (!objectp(ob)) {
        return notify_fail("There is no " + arg + " around.\n");
    }
    if (!environment(caster)->is_lab() && !present("portable lab", environment(caster))) {
        write("You can only enchant items in a laboratory.");
        return 1;
    }
    if (ob->query("uses")) {
        write("This object already has magic instilled in it.");
        return 1;
    }
    if (max(all_inventory(caster)->id("gem")) < 1) {
        write("%^BOLD%^%^RED%^You need a gem in your inventory to focus your magic through.");
        return;
    }else {
        write("%^BOLD%^%^RED%^You will be using " + (filter_array(all_inventory(caster), (: $1->id("gem") :))[0])->query_short() + "%^RESET%^%^BOLD%^%^RED%^ as a material component.");
    }
    if ((string*)TP->query_attackers() != ({})) {
        tell_object(TP, "You are far too busy fighting to do that right now!");
        return 1;
    }
    tell_room(environment(caster), "%^BOLD%^%^RED%^" + caster->QCN + " starts the process of enchanting the " + ob->query_short() + ".", caster);
    write("%^BOLD%^%^RED%^You start the process of enchanting the " + ob->query_short() + ".");
    write("%^YELLOW%^Enter spell name:");
    write("~q to cancel");
    input_to("select_spell", 0, ob);
    return;
}

void select_spell(string str, object ob)
{
    string spell, filename;
    string* names, * myclasses;
    object bag;
    int i;

    if (str == "~q") {
        return;
    }
    write("%^BOLD%^%^RED%^You have selected: %^GREEN%^" + str + "...");

    spell = replace_string(str, " ", "_");
    spell = "/cmds/spells/" + spell[0..0] + "/_" + spell;
    filename = spell + ".c";
    if (!file_exists(filename)) {
        tell_object(caster, "%^BOLD%^%^RED%^That spell does not exist");
        write("%^BOLD%^%^RED%^You start the process of enchanting the " + ob->query_short() + ".");
        write("%^YELLOW%^Enter spell name:");
        write("~q to cancel");
        input_to("select_spell", 0, ob);
        return;
    }
    myclasses = caster->query_classes();
    if (!sizeof(myclasses)) {
        tell_object(caster, "You don't have any classes! Please contact an imm to unbork yourself!");
        return;
    }
    if (caster->is_class("sorcerer")) {
        myclasses += ({ "mage" });                              // patch to pick up mage spell list for sorcs
    }
    if (caster->is_class("oracle")) {
        myclasses += ({ "cleric" });                            // patch to pick up cleric spell list for oracles
    }
    for (i = 0; i < sizeof(myclasses); i++) {
        if (filename->query_spell_level(myclasses[i])) {
            castclass = myclasses[i];
        }
    }
    if (castclass == "") {
        tell_object(caster, "Your class can't cast that spell, please try again.");
        write("%^BOLD%^%^RED%^You start the process of enchanting the " + ob->query_short() + ".");
        write("%^YELLOW%^Enter spell name:");
        write("~q to cancel");
        input_to("select_spell", 0, ob);
        return;
    }

    //TODO: Fix corresponding code in use
    /* if(spell->query_arg_needed()){ */
    /*     write("You can't enchant something with that spell."); */
    /*     write("%^BOLD%^%^RED%^You start the process of enchanting the "+ob->query_short()+"."); */
    /*     write("%^YELLOW%^Enter spell name:"); */
    /*     write("~q to cancel"); */
    /*     input_to("select_spell",0,ob); */
    /*     return; */
    /* } */

    write("%^YELLOW%^Number of charges (15 max):");
    write("~q to cancel");
    input_to("spell_charges", 0, ob, str, spell);
    return;
}

/**
 * Maximum level for enchanted spells to cast
 */
int maximum_enchant_level()
{
    return max(({ caster->query_guild_level("mage"),
                  caster->query_guild_level("sorcerer"),
                  caster->query_guild_level("oracle"),
                  caster->query_guild_level("druid"),
                  caster->query_guild_level("cleric"),
                  caster->query_guild_level("psion") })) +
           (int)caster->query_property("empowered");
}

void spell_charges(string str, object ob, string spell, string file)
{
    int charges;
    if (str == "~q") {
        return;
    }
    charges = atoi(str);
    if (charges < 1) {
        write("You must apply at least one charge to the item.");
        write("%^YELLOW%^Number of charges (15 max):");
        write("~q to cancel");
        input_to("spell_charges", 0, ob, spell, file);
        return;
    }
    if (charges > 15) {
        write("You may only input a maximum of 15 charges to an item.");
        write("%^YELLOW%^Number of charges (15 max):");
        write("~q to cancel");
        input_to("spell_charges", 0, ob, spell, file);
        return;
    }
    write("%^YELLOW%^Level of spell casting (between 1 and " + maximum_enchant_level() + "):");
    write("~q to cancel");
    input_to("spell_level", 0, ob, spell, file, charges);
    return;
}

void spell_level(string str, object ob, string spell, string file, int charges)
{
    int level, expdrain;
    object spellcopy;

    if (str == "~q") {
        return;
    }
    level = atoi(str);
    if (level < 1 || level > maximum_enchant_level()) {
        write("%^YELLOW%^Level of spell casting (between 1 and " + maximum_enchant_level() + "):");
        write("~q to cancel");
        input_to("spell_level", 0, ob, spell, file, charges);
        return;
    }
    expdrain = (9900 * level - 5000) / 89 * charges;
    write("%^BOLD%^%^GREEN%^The enchantment is almost prepared, and will drain you of %^RED%^" + expdrain + "%^RED%^ exp.");
    write("Type 'yes' to complete the enchantment, or anything else to cancel.");
    input_to("do_enchant", 0, ob, spell, file, charges, level, expdrain);
}

void do_enchant(string str, object ob, string spell, string file, int charges, int level, int expdrain)
{
    int i;
    string* names, diamond;
    object bag;

    if (str != "yes") {
        write("The enchantment fizzles and is lost.");
        return;
    }

    if(!avatarp(caster)) {
        if (max(all_inventory(caster)->id("gem")) < 1) {
            write("%^BOLD%^%^RED%^You need a gem in your inventory to focus your magic through.");
            return;
        }else {
            (filter_array(all_inventory(caster), (: $1->id("gem") :))[0])->remove();
        }

        if ((int)"/daemon/config_d.c"->check_config("character improvement") == 0) {
            caster->add_exp(expdrain * -1);
            caster->resetLevelForExp(0);
            tell_object(caster, "Subtracting " + expdrain + " experience points.");
        }else if ((int)"/daemon/config_d.c"->check_config("character improvement") == 1) {
            if ((int)caster->set_XP_tax(expdrain, 0, "improvement") == -1) {
                tell_object(caster, "Currently your character improvement tax is above the maximum allowed. " +
                            "You must first reduce it before you can enchant this item.");
                return 1;
            }
            if (expdrain > 0) {
                tell_object(caster, "Incuring character improvement tax of " + expdrain + ". All future experience gained will be " +
                            "reduced by 50% until it is repaid.");
            }
        }
    }

    ob->set("effect", "spell_effect");
    ob->set("uses", charges);
    ob->set("spell", spell);
/*    if (caster->is_class("psion"))
        ob->set("spell type","psion");
    else
        ob->set("spell type","mage"); */
    ob->set("spell type", castclass);
    ob->set("level", level);
    write("%^BOLD%^You lift the gem and focus your energy into it.");
    tell_room(environment(caster), "%^BOLD%^%^RED%^" + caster->QCN + " lifts the gem and starts to focus on it.", caster);
    write("%^BOLD%^You start to cast " + spell + " and focus the energy through the gem.");
    tell_room(environment(caster), "%^BOLD%^%^RED%^" + caster->QCN + " starts to cast a spell.", caster);
    tell_room(environment(caster), "%^BOLD%^%^YELLOW%^The " + ob->query_short() + " starts to glow.");
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
