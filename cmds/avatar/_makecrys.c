#include <std.h>
#include <daemons.h>
#include <move.h>
#include <psi_components.h>
#include "/daemon/nwps_d.h"

inherit DAEMON;
int help(){
    write(
@SAIDE
Usage: makecrys || makecrys <amount> <crystal>

Makecrys will display a list of valid crystals. 

Makecrys <amount> <crystal> will create the <amount> of
<crystals> that you specify.

Example: makecrys 2 black sapphire
SAIDE
    );
    return 1;
} 

void make_comps(string comp,int amount);
void check_create(string str,string comp,int amount);

int cmd_makecrys(string str){
    int x, amt;
    string list, *comps, tmp2;
    comps = keys(PSI_COMPONENTS);
    comps = sort_array(comps,"alphabetical_sort",find_object_or_load(FILTERS_D));
    if (!str) {
        write("%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^\n");
        for(x = 0; x < sizeof(comps);x++) {
            if(list) {  
            list += x + 1 + ": %^CYAN%^"+comps[x]+"%^RESET%^\n";
            continue;
            }
            list = x + 1 + ": %^CYAN%^"+comps[x]+"%^RESET%^\n";
            continue;
        }
        TP->more(explode(list,"\n"));
        return 1;
    }

    if(sscanf(str,"%d %s",amt,tmp2) == 2) {
        if(amt < 1) {
            write("%^RED%^ERROR:%^RESET%^  Cannot create less than 1 "+
            "crystal.");
            return 1;
        }
        if(member_array(tmp2,comps) == -1) {
            write("%^RED%^ERROR:%^RESET%^ "+tmp2+" not recognized as "+
            "valid crystal.");
            write("Continue with creation?  yes or no?");
            input_to("check_create",tmp2,amt);
            return 1;
        }   
        make_comps(tmp2,amt);
        return 1;
    }
    help();
    return 1;
}

void check_create(string str,string comp,int amount) {
    if(str == "yes" || str == "y") {
        write("Creating crystal at your own risk.");
        make_comps(comp,amount);
        return 1;
    }
    write("Aborting creation....Crystal will not be made.");
    return 1;
}

void make_comps(string comp,int amount) {
    object ob;
    ob = new("/d/magic/store_psi_comp");
    ob->set_name(comp);
    ob->set_id(({comp,"crystal"}));
    ob->set_short(capitalize(comp)+" (a psionic crystal)");
    ob->set_long("             " + amount + " " +capitalize(comp)+
    ". \n" + ob->query_long());
    ob->set_comp_quantity(to_int(amount));
    write("You create "+amount+" " + comp+".");
    if((int)(ob->move(TP)) != MOVE_OK) {
        write("Cannot carry, moving to room instead.");
        ob->move(ETP);
        return 1;
    }
}


