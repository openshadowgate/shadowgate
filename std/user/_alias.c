// alias command
#include <std.h>
 
inherit DAEMON;
 
void alias_reset();
int sort(string one,string two); 
 
varargs int cmd_alias (string str, int first) 
{
    int i, sl;
    int index;
    string verb,cmd,*elements,melnmarn;
    object act_ob;
    mapping alias;

    if(!objectp(PO) || !interactive(PO)) { return 0; }
  
    act_ob = PO;


    if(str == "-clear")  
    {
        act_ob->clear_aliases();
        return 1;
    }
  
    if(str == "-reset") 
    {
        alias_reset();
        return 1;
    }
  
    alias = (mapping)act_ob->query_aliases();

    if(!str) 
    {
        if (!mapp(alias))	
        {
            if(pointerp(alias)) write("Your alias mapping is a pointer!");
            if(intp(alias)) write("Your alias mapping is an integer!");
            if(stringp(alias)) write ("Your alias mapping is a string!");
            if(alias == 0) write ("Your alias mapping is 0!");
            notify_fail("You have some bad aliases, dude!");
            return 0;
	    }

        elements = keys(alias);
        if(!elements || !sizeof(elements)) 
        {
	        write("No aliases defined.");
	        return 1;
	    }
      
        elements = sort_array(elements,"sort");
      
        melnmarn = "";
        for(i = 0; i < sizeof(elements); i++) 
        {
	        melnmarn += sprintf("%%^YELLOW%%^%-10s %%^RESET%%^%%^CYAN%%^%-50s \n",elements[i],alias[elements[i]]);
	    }

        act_ob->more(explode(melnmarn,"\n"));
        return 1;
    }

    if(sscanf(str,"%s %s",verb,cmd) == 2)  
    {
        // added pray to prevent screwing up praying in churches *Styx* 11/20/03, last change 7/98
        if(verb=="alias" || verb == "pray")  
        {
            notify_fail ("Sorry, we can't allow you to alias 'alias' or 'pray'.\n");
            return 0;
        }
        if(!first)
        {
            if (!alias[verb]) 
            { 
                write("Alias: "+verb+" ("+cmd+") added."); 
            }
            else
            {
                write("Alias: "+verb+" ("+cmd+") altered.");
            }
        }
      
        act_ob->add_alias(verb,cmd);
        return 1;
    }
    
    if(!alias[str]) 
    {
        write("The alias "+str+" wasn't found.");
        return 1;
    }
    
    printf("%-15s%s\n",str,alias[str]);
    return 1;
}

int sort(string one,string two) { return strcmp(one,two); } 
 
varargs void alias_reset()
{  
    if (!interactive(previous_object())) { return; }
    cmd_alias("exa look $*",1);
    cmd_alias("i inventory",1);
    cmd_alias("l look $*",1);
    cmd_alias("$' say $*",1);
    cmd_alias("$\" say $*",1);
    cmd_alias("bio biography",1);
    cmd_alias("$: emote $*",1);
    cmd_alias("e east");
    cmd_alias("w west");
    cmd_alias("n north");
    cmd_alias("s south");
    cmd_alias("u up");
    cmd_alias("d down");
    cmd_alias("ne northeast");
    cmd_alias("nw northwest");
    cmd_alias("sw southwest");
    cmd_alias("se southeast");
}
 
 
int help()
{
  write("Flags accepted:\n"
	"    -reset\tClears aliases and sets them to defaults.\n"
	"    -clear\tClears all aliases.\n"
	"\nalias\t\t\tView current aliases.\n"
	"alias <alias> <command>\tSet the verb alias to execute command.\n"
	"alias <alias>\t\tCheck the value of <alias>\n"
	"unalias <alias>\t\tRemove <alias> from the alias list.\n"
	"\nSubstitution variable that exist are:\n"
	"    $# - Where # is the number of the word after the verb to substitute.\n"
	"    $* - Will be substituted with everything after the verb.\n"
	"\nPrefixing the alias' verb with a $ allows you to set up a verb that does not\n"
	"require a space after it. i.e. 'alias $' say $*' will allow you to do says as:\n"
	"'Hey! This is most Stufly!\n"
	"\nLook at the default aliases for examples.\n"
	"See also: unalias, nickname, unnickname, history\n");
	return 1;
}
