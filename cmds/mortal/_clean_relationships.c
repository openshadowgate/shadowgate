// coded by Ares 6/06, moved to mortal commands by *Styx*

#include <std.h>

inherit DAEMON;

int cmd_clean_relationships(string str)
{
    object player;
    mapping relationships;
    string *names;
    int i, count, startwith;
    int flag;
	player = TP;
    flag = str=="all"?1:0;
    if(avatarp(TP)) {
        if(str&&!flag)
        {
            if(!player=find_player(str))
            {
            tell_object(TP,"The target must be online for this command.");
            return 0;
            }
        }
    }
    if(!player->is_player()) { return 0; }

    relationships = player->getRelationships();
    if(!mapp(relationships)) { return 0; }
    names = keys(relationships);
    count = 0;
    startwith = sizeof(names);
    if(startwith)
    {
        for(i=0;i<startwith;i++)
        {
            if(!flag)
                if(user_exists(names[i]))
                    continue;
            tell_object(TP,"Cleaning... "+names[i]);
            player->remove_relationship(names[i]);
	    count++;
        }
        player->force_me("save");
        tell_object(TP,"Cleaned "+startwith+" names and removed "+count+".");
        return 1;
    }
    tell_object(TP,"Cleaned 0 names.");
    return 1;
}


void help()
{

    write("
%^CYAN%^NAME%^RESET%^

clean_relationships - remove suicied, rid or vanished players from your memory

%^CYAN%^SYNTAX%^RESET%^

clean_relationships [all]

%^CYAN%^DESCRIPTION%^RESET%^

The command runs through the list of recognized names that the player has and deletes any from the list who have been rid or used suicide comman.

With argument all it allow you to forget everyone.

%^CYAN%^SEE ALSO%^RESET%^

recognize
");

    if(avatarp(TP))
        write("
%^CYAN%^IMMORTALS%^RESET%^

You can use it on target by adding their name.

<clean_relationships [NAME]>

");
}
