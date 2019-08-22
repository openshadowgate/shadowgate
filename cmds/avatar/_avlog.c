#include <std.h>

int cmd_avlog(string str)
{
    TP->more("/log/avlog/"+str);
    return 1;
}

void help(){
  write(
"
%^CYAN%^NAME%^RESET%^

avlog - review imms activity

%^CYAN%^SYNTAX%^RESET%^

avlog %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will display command history typed in by an imm with the %^ORANGE%^%^ULINE%^NAME%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

elog, log, replog, log_file()
"
	);
}
