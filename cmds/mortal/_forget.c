#include <std.h>

#define SYNTAX "Syntax:  forget <classtype> <spellname>\n"

inherit DAEMON;

int cmd_forget(string str)
{
    string myclass, myspell;

    if(!str) { return notify_fail("Forget what?\n"); }
    if(sscanf(str, "%s %s", myclass, myspell) != 2) { return notify_fail(SYNTAX); }
    if(!TP->is_class(myclass)) { return notify_fail("You cannot cast spells as a "+myclass+"!\n"); }

    if(myclass == "antipaladin") { myclass = "paladin"; }
    TP->set_property("forgetting spell",1);
    if (!TP->forget_memorized(myclass,myspell,1)) 
    { 
        TP->remove_property("forgetting spell");
        return notify_fail("The spell, '"+myspell+"' is not in your memory! Use <fixspells> if this is wrong.\n"); 
    }
    else 
    {
        TP->remove_property("forgetting spell");
        tell_object(TP, "The spell, '"+myspell+"' has been forgotten successfully!");
    }
    return 1;
}


void help() 
{
    write("
%^CYAN%^NAME%^RESET%^

forget - forget a spell

%^CYAN%^SYNTAX%^RESET%^

forget %^ORANGE%^%^ULINE%^CLASS%^RESET%^ %^ORANGE%^%^ULINE%^SPELL%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Removes spell from your memorized list. If it fails and spell is still there you might want to look into %^ORANGE%^<fixspells>%^RESET%^ command.

%^CYAN%^SEE ALSO%^RESET%^

fixspells, recall, prepare, cast
");
}
