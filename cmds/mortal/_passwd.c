/*
// This is part of the TMI distribution mudlib.
// Please retain this header if you use this file.
// Written by Sulam (12-9-91)
// Help added by Brian (1/28/92)
*/

#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>
#include <config.h>
#include <pwgen.h>

/**
 * @file
 */

inherit DAEMON;

private static string tmp;
private object user;
private string playerf;

int cmd_passwd(string str)
{
    string name;

    if(!this_player() ||
       !userp(this_player()) ||
       (this_player() != this_player(1)) ||
       (this_player() != previous_object())
        )
    {
        log_file("illegal", "password: "+ctime(time())+" "+geteuid(previous_object())+"\n");
        notify_fail("Ok.\n");
        return 0;
    }
    if(this_player()->query_forced())
    {
        log_file("illegal", "passwd: (forced): "+ctime(time())+" "+this_player()->query_name()+"\n");
        notify_fail("You must act of your own free will.\n");
        return 0;
    }
    //dis doesn't work, can't call restore somewhy
    if(str != "" &&
       member_group(geteuid(TP), "law_c"))
    {
        playerf = sprintf("%s/%s/%s", "/adm/save/users", str[0..0], str);
        user=new(OB_USER);
        user->restore_object(playerf);
        playerf = str;
    }
    else
    {
        user=TP;
    }
    notify_fail("Sorry.\n");
    name = (string)user->query_name();
    write("Changing password for "+name+".");
    if(user==TP)
    {
        write("Old password:");
        input_to("oldpass", 1);
    }
    else
    {
        write("\nNew password:");
        input_to("newpass", 1);
    }
    return 1;
}

nomask static int oldpass(string pass)
{
    string password;

    if(!pass)
        return 0;
    seteuid(UID_USERACCESS);
    password = (string)this_player()->query_password();
    seteuid(getuid());
    if (password != crypt(pass, password))
        return 0;
    write("\nNew password:");
    input_to("newpass", 1);
    return 1;
}

nomask static int newpass(string pass)
{
    tmp = pass;
    if (strlen(tmp)<0)
    {
        write("Your new password must have no less than 8 characters.\n");
        return 0;
    }
    write("\nAgain:");
    input_to("npass2", 1);
    return 1;
}

nomask static int npass2(string pass)
{
    string salt;

    if (pass != tmp)
    {
        write("The passwords must match.\n");
        return 0;
    }
    if (this_player(1) != this_player())
    {
        write("You must do this with out being forced.\n");
        return 0;
    }
    salt = PWGEN->random_salt(43);
    pass = crypt(pass, "$5$"+salt);
    seteuid(UID_ROOT);
    user->set_password(pass);
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
