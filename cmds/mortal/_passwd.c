/*
// This is part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Written by Sulam (12-9-91)
// Help added by Brian (1/28/92)
*/

#include <std.h>
#include <security.h>
#include <pwgen.h>

inherit DAEMON;

private static string tmp;

int
cmd_passwd() {
    string name;

    if(!this_player() || !userp(this_player()) || 
      (this_player() != this_player(1)) ||
      (this_player() != previous_object())
    ) {
        log_file("illegal", "password: "+ctime(time())+" "+geteuid(previous_object())+"\n");
        notify_fail("Ok.\n");
        return 0;
    }
    if(this_player()->query_forced()) {
        log_file("illegal", "passwd: (forced): "+ctime(time())+" "+this_player()->query_name()+"\n");
        notify_fail("You must act of your own free will.\n");
        return 0;
    }
    notify_fail("Sorry.\n");
    name = (string) this_player()->query_name();
    if(name == "guest") {
	notify_fail("Cannot change password for Guest.\n");
	return 0;
    }
    write("Changing password for "+name+" on Nightmare\n");
    write("Old password:");
    input_to("oldpass", 1);
    return 1;
}

nomask static int oldpass(string pass) {
    string password;

    if (!pass) return 0;    
    seteuid(UID_USERACCESS);
    password = (string) this_player()->query_password();
    seteuid(getuid());
    if (password != crypt(pass, password)) return 0;
    write("\nNew password:");
    input_to("newpass", 1);
    return 1;
}

nomask static int newpass(string pass) {
    tmp = pass;
    if (strlen(tmp)<5) {
	write("Your new password must have more than 5 characters.\n");
	return 0;
    }
    write("\nAgain:");
    input_to("npass2", 1);
    return 1;
}

nomask static int npass2(string pass) {
    string salt;
    
    if (pass != tmp) {
	write("The passwords must match.\n");
	return 0;
    }
    if (this_player(1) != this_player()) {
	write("You must do this with out being forced.\n");
	return 0;
    }
    salt = PWGEN->random_salt(43); //Make it better someone
    pass = crypt(pass, "$5$"+salt);
    seteuid(UID_USERACCESS);
    this_player()->set_password(pass);
    seteuid(getuid());
    write("\n");
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

passwd - change yor password

%^CYAN%^DESCRIPTION%^RESET%^

The command allows you to change your password. Do this at least once a year.

%^CYAN%^SEE ALSO%^RESET%^

setenv, chfn, who

"
);
}
/* EOF */
