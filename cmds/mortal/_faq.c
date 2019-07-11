//      /bin/user/_faq.c
//      from the Nightmare Mudlib
//      something to more the faq file
//      created by Descartes of Borg 930810
//      from the idea from the TMI 0.8 Mudlib

#include <std.h>
#include <files.h>

int cmd_faq(string str) {
    this_player()->more(FILE_FAQ);
    return 1;
}

void help() {
    write("Syntax: <faq>\n\n"
      "If you have not typed this command, you should do so next.\n"
      "The command pages through a list of frequently asked mud\n"
      "questions.\n"
     "If you have a web browser available, it is also posted at:\n"
    "     %^BOLD%^%^BLUE%^http://www.firedragon.com/shadowgate/faq.htm%^RESET%^\n"
    );
}
