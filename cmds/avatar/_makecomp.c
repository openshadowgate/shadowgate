#include <std.h>
#include <daemons.h>
#include <move.h>
#include <spellcomponents.h>
#include "/daemon/nwps_d.h"

#define VTYPES ({"psion", "bard", "mage"})

inherit DAEMON;
int help(){
    write(
@SAIDE
Usage: makecomp <type> || makecomp <type> <amount> <comp>

Makecomp <type> will display a list of valid components 
of the <type> specified.

Valid <type> arguments are bard | psion | mage

Makecomp <type> <amount> <comp> will create the <amount> of
<type> <comp> that you specify.

Example: makecomp mage 2 diamond dust
SAIDE
    );
    return 1;
} 

void make_comps(string type, string comp, int amount);
void check_create(string str, string type, string comp, int amount);

int cmd_makecomp(string str)
{
    	int x, amt, i;
    	string list, *comps, tmp2, header, type, thead;
	header = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    	if (!str) 
	{
	  	tell_object(TP, "The syntax has changed as of March 1st, 2011 - Saide.");
	  	help();
		return 1;
	}

	if(member_array(str, VTYPES) != -1)
	{
		if(str == "mage")
		{
			comps = MAGE_COMPONENTS;
		}
		if(str == "psion")
		{
			comps = PSI_COMPONENTS;
		}
		if(str == "bard")
		{
			comps = BARDCOMPS;
		}
		comps = sort_array(comps,"alphabetical_sort",find_object_or_load(FILTERS_D));
		i = strlen(header);
		thead = "%^BLUE%^"+implode(explode(header, "")[0..(i/2)], "");
		thead += "%^BOLD%^%^WHITE%^ - "+capitalize(str)+" Components - %^RESET%^";
		thead += "%^BLUE%^"+ implode(explode(header, "")[(i/2+1)..(i-1)], "");
		thead += "%^RESET%^\n";
		write(thead);
		for(x = 0; x < sizeof(comps);x++) 
		{
            	if(list) 
			{  
            		list += x + 1 + ": %^CYAN%^"+comps[x]+"%^RESET%^\n";
           	 		continue;
            	}
            	list = x + 1 + ": %^CYAN%^"+comps[x]+"%^RESET%^\n";
            	continue;
        	}
        	TP->more(explode(list,"\n"));
        	return 1;
  	}

    	if(sscanf(str,"%s %d %s",type,amt,tmp2) == 3) 
	{
      	if(amt < 1) 
		{
            	write("%^RED%^ERROR:%^RESET%^  Cannot create less than 1 "+
            	"component.");
            	return 1;
        	}

		if(member_array(type, VTYPES) == -1)
		{
			tell_object(TP, "%^RED%^ERROR:%^RESET%^  "+type+
			" is not recognized as a valid <type> argument.");
			help();
			return 1;
		}
		if(type == "mage")
		{
			comps = MAGE_COMPONENTS;
		}
		if(type == "psion")
		{
			comps = PSI_COMPONENTS;
		}
		if(type == "bard")
		{
			comps = BARDCOMPS;
		}
        	if(member_array(tmp2,comps) == -1) 
		{
            	write("%^RED%^ERROR:%^RESET%^ "+tmp2+" not recognized as "+
	            "valid component.");
      	      write("Continue with creation?  yes or no?");
	            input_to("check_create",type, tmp2, amt);
      	      return 1;
        	}   
        	make_comps(type, tmp2, amt);
        	return 1;
    	}
    	help();
    	return 1;
}

void check_create(string str,string type,string comp,int amount) 
{
	if(str == "yes" || str == "y") 
	{
      	write("Creating comp at your own risk.");
        	make_comps(type, comp,amount);
        	return 1;
    	}
    	write("Aborting creation....Comp will not be made.");
    	return 1;
}

void make_comps(string type, string comp, int amount) 
{
	object ob;
      ob = new("/d/magic/store_comp");
      ob->set_name(comp);
      ob->set_id(({comp,"component"}));
      ob->set_short(capitalize(comp)+" (a spell component)");

	ob->set_long("             " + amount + " " +capitalize(comp)+
    	". \n" + ob->query_long());
	ob->set_comp_quantity(to_int(amount));
	write("You create "+amount+" " + type + " "+ comp+".");
    	if((int)(ob->move(TP)) != MOVE_OK) 
	{
      	write("Cannot carry, moving to room instead.");
        	ob->move(ETP);
        	return 1;
    	}
}


