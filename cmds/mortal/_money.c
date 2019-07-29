//      /bin/user/_money.c
//      from the Nightmare mudlib
//      a comand to allow players to search their pockets
//      created by Descartes of Borg 25 april 1993

#include <str_fmt.h>

#include <std.h>

inherit DAEMON;

int cmd_money(string str) {
    string *currs;
    string borg;
    int i, tmp;

    if(str) return 0;  /* to allow the wiz command to work */
    currs = (string *)this_player()->query_currencies();
    if(!currs || !sizeof(currs)) {
        write("You are broke.");
     tell_room(ETP,this_player()->query_cap_name()+" comes up with empty pockets.",TP);
        return 1;
    }
    tell_room(ETP,this_player()->query_cap_name()+" fishes through "+
      this_player()->query_possessive()+" pockets examining some money.",TP);
    write("%^BOLD%^%^CYAN%^In your pockets you find these coins:");
    write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    for(i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg = sprintf("     %%^CYAN%%^%-10s%%^MAGENTA%%^:  %%^GREEN%%^%s %%^BOLD%%^%%^GREEN%%^coins.",capitalize(currs[i]),english_number(this_player()->query_money(currs[i])));
    	write((borg));
    }
    write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

money - look into your purse

%^CYAN%^DESCRIPTION%^RESET%^

This command displays currency you have on yourself.

%^CYAN%^SEE ALSO%^RESET%^

inventory, eq, score
"
    );
}
