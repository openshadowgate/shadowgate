#include <std.h>

int cmd_plog(string str)
{
    TP->more("/log/plog/"+str);
    return 1;
}

void help(){
  write(
"
%^CYAN%^NAME%^RESET%^

plog - review recent player activity

%^CYAN%^SYNTAX%^RESET%^

plog %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will display command history typed in by aa with the %^ORANGE%^%^ULINE%^NAME%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

elog, log, replog, log_file()
"
	);
}
