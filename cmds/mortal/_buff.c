#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit DAEMON;

int cmd_buff(string str)
{
    object buffob,oldob;
    mapping buffs,buff;
    string spell_name, extra, *arguments, *temp = ({}), temp_string, target, special, *normal_buffs = ({}), *targeted_buffs = ({}), *special_buffs = ({}), *display = ({}), *myspells = ({});
    int i;

    if (!objectp(TP)) {
        return 0;
    }

    if (!stringp(str) || str == "" || str == " ") {
        oldob = present("buffobxyz", TP);
        if (objectp(oldob)) {
            oldob->remove();
        }
        buffob = new("/cmds/mortal/obj/buffob.c");
        buffob->set_owner(TP);
        buffob->move(TP);
        return 1;
    }

    arguments = explode(str, " ");

    if (!sizeof(arguments)) { return 1; }

    switch (arguments[0])
    {
    case "add":

        if (sizeof(arguments) < 2)
        {
            tell_object(TP, "Syntax: <buff add SPELL NAME> or <buff add SPELL NAME $T> or <buff add SPELL NAME | cast CLASS SPELL ARGUMENTS>");
            return 1;
        }
        for (i = 1;i < sizeof(arguments);i++)
        {
            temp += ({ arguments[i] });
        }

        temp_string = implode(temp, " ");
        spell_name = parse_spell(temp_string);
        if (!spell_name) { return 1; }
        extra = parse_other(spell_name, temp_string);
        target = parse_target(extra);
        special = parse_special(TP,extra);
        if (special == -1)
        {
            tell_object(TP, "Aborting...");
            return 1;
        }
        if (special)
        {
            if (strsrch(special, spell_name) == -1)
            {
                tell_object(TP, "You must include the spell name in your special cast string.  Aborting...");
                return 1;
            }
        }
        buffs = get_buffs(TP);
        delete_buff(TP, spell_name);
        buffs[spell_name] = (["target":target, "special" : special]);
        tell_object(TP, "Adding buff: " + spell_name + "");
        if (target) { tell_object(TP, "target: " + target); }
        if (special) { tell_object(TP, "special cast string: " + special); }
        save_buffs(TP,buffs);
        return 1;

    case "clear":

        tell_object(TP, "Clearing all of your buffs...");
        delete_buffs(TP);
        return 1;

    case "remove":

        if (sizeof(arguments) < 2)
        {
            tell_object(TP, "Syntax: <buff remove SPELL NAME>");
            return 1;
        }
        for (i = 1;i < sizeof(arguments);i++)
        {
            temp += ({ arguments[i] });
        }

        temp_string = implode(temp, " ");
        spell_name = temp_string;
        tell_object(TP, "Deleting the buff: " + spell_name);
        delete_buff(TP, spell_name);
        return 1;

    case "diff":

        buffs = get_buffs(TP);
        myspells = TP->query_property("spelled");

        tell_object(FPL("ilmarinen"),":"+identify(buffs));

        return 1;

    case "list":

        buffs = get_buffs(TP);
        temp = keys(buffs);
        if (!sizeof(temp))
        {
            tell_object(TP, "You don't seem to have any buffs added to your list yet.");
            return 1;
        }

        display += ({ "%^RESET%^%^BOLD%^%^BLUE%^--==%^RESET%^%^BOLD%^%^CYAN%^< %^RESET%^%^BOLD%^Buffs to be Cast %^RESET%^%^BOLD%^%^CYAN%^>%^RESET%^%^BOLD%^%^BLUE%^==--%^RESET%^\n" });

        for (i = 0;i < sizeof(temp);i++)
        {
            spell_name = temp[i];
            buff = buffs[spell_name];
            if (buff["special"]) { special_buffs += ({ spell_name }); }
            else if (buff["target"]) { targeted_buffs += ({ spell_name }); }
            else normal_buffs += ({ spell_name });
        }

        if (sizeof(normal_buffs))
        {
            for (i = 0;i < sizeof(normal_buffs);i++)
            {
                display += ({ "  %^RESET%^%^BOLD%^%^GREEN%^" + normal_buffs[i] + "" });
            }
        }

        if (sizeof(targeted_buffs))
        {
            display += ({ "" });
            for (i = 0;i < sizeof(targeted_buffs);i++)
            {
                spell_name = targeted_buffs[i];
                buff = buffs[spell_name];
                target = buff["target"];
                display += ({ "   %^RESET%^%^BOLD%^%^CYAN%^" + arrange_string(spell_name,27) + "Target: " + target + "" });
            }
        }

        if (sizeof(special_buffs))
        {
            display += ({ "" });
            for (i = 0;i < sizeof(special_buffs);i++)
            {
                spell_name = special_buffs[i];
                buff = buffs[spell_name];
                special = buff["special"];
                display += ({ "    %^RESET%^%^BOLD%^%^MAGENTA%^" + arrange_string(spell_name,27) + "Special: " + special + "" });
            }
        }
        TP->more(display);
        return 1;
    }
    return 0;
}


// picks out the special cast string and leaves any target information included intact for processing in the buff object later
string parse_special(object obj,string str)
{
    string special,*temp;
    if (!stringp(str) || str == "" || str == " ") { return 0; }
    if (strsrch(str, "|") == -1) { return 0; }
    if (strsrch(str, "cast") == -1)
    {
        write("You must have cast in your syntax for special cast strings.  Syntax <buff add spell name | cast class spell name arguments>");
        return -1;
    }
    special = replace_string(str, "| ", "", 1);
    temp = explode(special, " ");
    if (sizeof(temp) < 3)
    {
        write("Syntax <buff add spell name | cast class spell name arguments>");
        return -1;
    }
    if (!obj->is_class(temp[1]) && temp[1] != "innate")
    {
        write("You don't seem to have the class " + temp[1] + ".");
        return -1;
    }
    return special;
}


// picks the target from the string passed to it.  should NOT have the spell name in this string
string parse_target(string str)
{
    string target;
    int position;
    if (!stringp(str) || str == "" || str == " ") { return 0; }
    if (strsrch(str, "$") == -1) { return 0; }
    if (strsrch(str, "|") != -1) { return 0; }
    position = strsrch(str, " ");
    if (position != -1) { target = arrange_string(str, position); }
    else { target = str; }
    return target;
}


// returns everything that's not the spell name
string parse_other(string spell, string str)
{
    string other;
    if (!stringp(spell)) { return 0; }
    if (str == spell) { return spell; }
    if (strsrch(str, "$") == -1 && strsrch(str, "|") == -1) { return spell; }
    other = replace_string(str, spell + " ", "",1);
    return other;
}


// strips the spell name out of the string passed to it
string parse_spell(string str)
{
    int position;
    if (!stringp(str) || str == "" || str == " ") { return 0; }
    if (does_spell_exist(str)) { return str; }
    position = strsrch(str, " |");
    if (position == -1) { position = strsrch(str," $"); }
    if (position != -1)
    {
        str = arrange_string(str, position);
        if (does_spell_exist(str)) { return str; }
        else
        {
            write("The spell " + str + " doesn't seem to exist.\n");
            return 0;
        }
    }
    if (does_spell_exist(str)) { return str; }
    return 0;
}


// checks if it's an actual spell
int does_spell_exist(string str)
{
    string first_letter,spell_name;
    if (!stringp(str) || str == "" || str == " ") { return 0; }
    first_letter = str[0..0];
    spell_name = replace_string(str, " ", "_");
    spell_name = "/cmds/spells/" + first_letter + "/_" + spell_name + ".c";
    if (file_exists(spell_name)) { return 1; }
    return 0;
}


int add_buff(object obj, string spell, mapping buff)
{
    mapping buffs;
    if (!objectp(obj)) { return 0; }
    if (!mapp(buff) || !sizeof(keys(buff))) { return 0; }
    buffs = get_buffs(obj);
    delete_buff(obj, spell);
    buffs[spell] = buff;
    save_buffs(obj, buffs);
    return 1;
}


int delete_buff(object obj, string spell)
{
    mapping buffs;
    if (!objectp(obj)) { return 0; }
    buffs = get_buffs(obj);
    buffs = map_delete(buffs, spell);
    save_buffs(obj, buffs);
    return 1;
}


mapping get_buffs(object obj)
{
    mapping temp;
    temp = (mapping)obj->query("buff_list");
    if (!mapp(temp) || !sizeof(keys(temp))) { return ([]); }
    return temp;
}


void delete_buffs(object obj)
{
    if (!objectp(obj)) { return; }
    obj->delete("buff_list");
    return;
}


void save_buffs(object obj, mapping buffs)
{
    if (!objectp(obj)) { return; }
    if (!mapp(buffs) || !sizeof(keys(buffs))) { return; }
    obj->set("buff_list", buffs);
    return;
}


void help()
{

    write(
"
%^CYAN%^NAME%^RESET%^

buff - cast stored list of spells

%^CYAN%^SYNTAX%^RESET%^

buff
buff list
buff add %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^
buff add %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^ | cast %^ORANGE%^%^ULINE%^CAST_ARGUMENTS%^RESET%^
buff remove %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^
buff clear

%^CYAN%^DESCRIPTION%^RESET%^

The command will allow player to store a list of buff spells they can start casting with a single command. The buffs will cycle one at a time for either the player or their party members, depending on the syntax. If the player doesn't have enough spells, spell levels, power points or components, buff process will be interrupted. Buff can be used only while at peace and will stop if the player gets into combat. Moving will also interrupt the process.

%^ORANGE%^<buff list>%^RESET%^
    Will list all added buffs and their arguments.

%^ORANGE%^<buff add %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^%^ORANGE%^ | cast %^ORANGE%^%^ULINE%^CAST_ARGUMENTS%^RESET%^%^ORANGE%^>%^RESET%^
    Will add a spell with special cast arguments. For example, <buff add resist energy | cast druid resist energy on fire> for druids will add spell resist energy to be cast with fire argument.

%^ORANGE%^<buff remove %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^%^ORANGE%^>%^RESET%^
    Will remove %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^ from the list.

%^ORANGE%^<buff clear>%^RESET%^
    Will clear your buff list.

%^CYAN%^SEE ALSO%^RESET%^

prepare, cast
"
        );
}
