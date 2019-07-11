// Created from echolist with modifications -Ares 08/09/05
#include <std.h>
#include <daemons.h>
#include <security.h>
inherit DAEMON;

void help();

int cmd_echodeity(string str)
{
    string deity,mydeity,line;
    object * targets=({ }),current,*ppl=({});
    int i;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) return help();
    if(sscanf(str,"%s %s", deity,line) != 2) return help();
    
    ppl += users();

    for(i=0;i<sizeof(ppl);i++)
    {
        mydeity = ppl[i]->query_diety();
        if(mydeity == deity) { targets += ({ppl[i]}); }
    }

	seteuid(UID_LOG);
	log_file("shouts", geteuid(previous_object())+" (echodeity):("+deity+") "+line+"\n");
	seteuid(getuid());
	line = replace_string(line,"%^NL%^","\n");
	message("environment",line,targets);
	message("environment","You echodeity "+deity+":\n"+line+"",TP);
	return 1;

}

    void help()
    {
        write("Syntax: echodeity <deity>\n The command will send an "
            "echo to all players currently connected who follow "
            "said deity.");
	return 1;
    }
