#include <std.h>
#include <daemons.h>
#include <weapon_enhancements.h>

inherit DAEMON;

int cmd_enhance(string str)
{
    object enhanceob, oldob;
    mapping enhances, enhance;
    string enhancement_name, *arguments, *temp = ({}), *display = ({}), * normal_enhances = ({});
    int i;

    if (!objectp(TP)) {
        return 0;
    }

    if (!FEATS_D->has_feat(TP, "arcane pool") &&
        !FEATS_D->has_feat(TP, "divine bond")) {
        return 0;
    }
    
    if (!stringp(str) || str == "" || str == " ") {
        //turn on this thing
        int power;

        if (!(int)"/daemon/user_d.c"->spend_pool(TP, 1, "arcana"))
        {
            if (!(int)"/daemon/user_d.c"->spend_pool(TP, 1, "grace"))
            {
                tell_object(TP, "%^CYAN%^You can't enhance your weapon!%^RESET%^");
                return 1;
            }
        }

        enhances = get_enhances(TP);
        power = TP->query_property("enhancement bonus");
        if (power) {
            TP->remove_property("enhancement timer");
            TP->remove_property("enhancement bonus");
            TP->add_attack_bonus(-power);
            TP->add_damage_bonus(-power);
        }
        temp = keys(enhances);
        power = 1;
        if (FEATS_D->has_feat(TP, "arcane pool")) { power += ((int)TP->query_guild_level("magus") + 7) / 8; }
        if (FEATS_D->has_feat(TP, "divine bond")) { power += ((int)TP->query_guild_level("paladin") + 1) / 6; }
        if (!sizeof(temp))
        {
            tell_object(TP, "You don't seem to have any additional enhancements in your list.");
        }
        else {

            string element, property_name;
            int is_burst, has_element, is_alignement, cost;
            mapping this_enhance;
            this_enhance = VALID_ENHANCEMENTS;
            for (i = 0;i < sizeof(temp);i++)
            {
                enhancement_name = temp[i];
                enhance = enhances[enhancement_name];
                if (!this_enhance[enhancement_name]) { continue; }
                property_name = this_enhance[enhancement_name]["property"];
                cost = (int)this_enhance[enhancement_name]["cost"];
                if (is_burst = strsrch(property_name, "burst") + 1) {
                    element = replace_string(property_name, " burst", "");
                    if (has_element = TP->query_property(element)) {
                        cost -= 1;
                    }
                }
                if (power - cost >= 0) {                   
                    if (strsrch(property_name, "alignment ") + 1) {
                        is_alignement = strsrch(property_name, (string)TP->query_true_align()) + 1;
                        if (!is_alignement) {
                            tell_object(TP, "Your alignment doesn't match to " + enhancement_name + ".");
                            continue;
                        }
                    }
                    TP->set_property(property_name, 1);
                    if (is_burst && !has_element) {
                        TP->set_property(element, 1);
                        power -= cost;
                    }
                    tell_object(TP, "Appliying " + enhancement_name + " to your weapon.");
                    power -= cost;
                    TP->set_property("weapon enhancements", 1);
                }
                else {
                    tell_object(TP, "Can't apply " + enhancement_name + " to your weapon.");
                }
            }
        }
        if (power) {
            TP->set_property("enhancement bonus", power);
            TP->add_attack_bonus(power);
            TP->add_damage_bonus(power);
        }
        TP->set_property("enhancement timer", 16);
        return 1;
    }
    
    arguments = explode(str, " ");

    if (!sizeof(arguments)) {
        return 1;
    }

    switch (arguments[0])
    {
        
    case "add":

        if (sizeof(arguments) < 2) {
            tell_object(TP, "Syntax: <enhance add PROPERTY NAME>");
            return 1;
        }
        for (i = 1; i < sizeof(arguments); i++) {
            temp += ({ arguments[i] });
        }

        enhancement_name = implode(temp, " ");

        if (!does_enhance_exist(TP, enhancement_name)) {
            write("The enhancement " + enhancement_name + " doesn't seem to exist.\n");
            return 1;
        }
        if (!enhancement_name) {
            return 1;
        }
        enhances = get_enhances(TP);
        delete_enhance(TP, enhancement_name);
        enhances[enhancement_name] = ({ });
        tell_object(TP, "Adding enhancement: " + enhancement_name + "");
        save_enhances(TP, enhances);
        return 1;

    case "clear":

        tell_object(TP, "Clearing all of your enhancements...");
        delete_enhances(TP);
        return 1;

    case "remove":

        if (sizeof(arguments) < 2) {
            tell_object(TP, "Syntax: <enhance remove PROPERTY NAME>");
            return 1;
        }
        for (i = 1; i < sizeof(arguments); i++) {
            temp += ({ arguments[i] });
        }

        enhancement_name = implode(temp, " ");
        tell_object(TP, "Deleting the enhancement: " + enhancement_name);
        delete_enhance(TP, enhancement_name);
        return 1;

    case "list":

        enhances = get_enhances(TP);
        temp = keys(enhances);
        if (!sizeof(temp))
        {
            tell_object(TP, "You don't seem to have any enhancements added to your list yet.");
            return 1;
        }
        
        display += ({ "%^RESET%^%^BOLD%^%^BLUE%^--==%^RESET%^%^BOLD%^%^CYAN%^< %^RESET%^%^BOLD%^Enhancements to be applied %^RESET%^%^BOLD%^%^CYAN%^>%^RESET%^%^BOLD%^%^BLUE%^==--%^RESET%^" });

        for (i = 0;i < sizeof(temp);i++)
        {
            enhancement_name = temp[i];
            enhance = enhances[enhancement_name];
            normal_enhances += ({ enhancement_name });
            if (enhance)
            {
                display += ({ "  %^RESET%^%^BOLD%^%^GREEN%^" + enhancement_name + "" });
            }

        }

        TP->more(display);
        
        return 1;
    }
    return 0;
}

// checks if it's an actual enhancement
int does_enhance_exist(object obj, string str)
{
    int property_num;
    string * enhancements;
    enhancements = ({ });
    if (FEATS_D->has_feat(obj, "divine bond")) { enhancements += PALADIN_ENHANCEMENTS; }
    if (FEATS_D->has_feat(obj, "arcane pool")) { enhancements += MAGUS_ENHANCEMENTS; }
    enhancements = distinct_array(enhancements);
    if (member_array(str, enhancements) != -1) { return 1; }
    return 0;
}


int add_enhance(object obj, string enhancement_name, mapping enhance)
{
    mapping enhances;
    if (!objectp(obj)) { return 0; }
    if (!mapp(enhance) || !sizeof(keys(enhance))) { return 0; }
    enhances = get_enhances(obj);
    delete_enhance(obj, enhancement_name);
    enhances[enhancement_name] = enhance;
    save_enhances(obj, enhances);
    return 1;
}


int delete_enhance(object obj, string enhancement_name)
{
    mapping enhances;
    if (!objectp(obj)) { return 0; }
    enhances = get_enhances(obj);
    enhances = map_delete(enhances, enhancement_name);
    save_enhances(obj, enhances);
    return 1;
}


mapping get_enhances(object obj)
{
    mapping temp;
    temp = (mapping)obj->query("enhance_list");
    if (!mapp(temp) || !sizeof(keys(temp))) { return ([]); }
    return temp;
}


void delete_enhances(object obj)
{
    if (!objectp(obj)) { return; }
    obj->delete("enhance_list");
    return;
}


void save_enhances(object obj, mapping enhances)
{
    if (!objectp(obj)) { return; }
    if (!mapp(enhances) || !sizeof(enhances)) { return; }
    obj->set("enhance_list", enhances);
    return;
}


void off_enhances(object obj)
{
    int i, enh_bonus;
    string * temp = ({});
    mapping enhances;
    if (!objectp(obj)) { return; }
    tell_object(obj, "%^CYAN%^Your weapon enhancements fade.%^RESET%^");
    obj->remove_property("enhancement timer");
    enh_bonus = obj->query_property("enhancement bonus");
    if (enh_bonus) {
        obj->remove_property("enhancement bonus");
        obj->add_attack_bonus(-enh_bonus);
        obj->add_damage_bonus(-enh_bonus);
    }
    enhances = VALID_ENHANCEMENTS;
    temp = keys(enhances);
    if (!sizeof(temp))
    {
        tell_object(obj, "Error.");
    }
    for (i = 0;i < sizeof(temp);i++)
    {
        obj->remove_property(enhances[temp[i]]["property"]);
    }
    return;
}


void help()
{

    write(
"
%^CYAN%^NAME%^RESET%^

enhance - apply stored list of enhancements

%^CYAN%^SYNOPSIS%^RESET%^

enhance
enhance list
enhance add %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^
enhance remove %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^
enhance clear

%^CYAN%^DESCRIPTION%^RESET%^

The command will allow player to store a list of enhancements they can apply to their weapon instead of adding an enhancement bonus. The enhancements will cycle one at a time. If the player doesn't have enough enhancement bonus, enhancements process will be interrupted.

%^ORANGE%^<enhance list>%^RESET%^
  Will list all added enhancements.

%^ORANGE%^<enhance add %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^%^ORANGE%^>%^RESET%^
  Will add %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^ to the enhancement list.

%^ORANGE%^<enhance remove %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^%^ORANGE%^>%^RESET%^
  Will remove %^ORANGE%^%^ULINE%^PROPERTY_NAME%^RESET%^ from the enhancement list.

%^ORANGE%^<enhance clear>%^RESET%^
  Will clear your enhancement list.

%^CYAN%^SEE ALSO%^RESET%^

magus, arcane pool, paladin, weapon bond
"
        );
}
