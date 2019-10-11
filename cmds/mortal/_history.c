#include <std.h>

int cmd_history(string str)
{
    string fname;

    if(!avatarp(TP))
        fname = "/log/plog/"+TP->query_name();
    else
        fname = "/log/avlog/"+TP->query_name();
    TP->more(fname);
    return 1;
}

void help(){
  write(
"
%^CYAN%^NAME%^RESET%^

history - display your command history

%^CYAN%^DESCRIPTION%^RESET%^

This will display all commands you have enetered recently.

%^CYAN%^SEE ALSO%^RESET%^

prompt, set, score, hp, money
"
	);
}
