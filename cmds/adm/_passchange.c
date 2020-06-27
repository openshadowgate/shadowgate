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

inherit OB_USER;

int cmd_passchange(string str)
{
    if (TP->query_forced()) {
        log_file("illegal", "passwd: (forced): "+ctime(time())+" "+this_player()->query_name()+"\n");
        notify_fail("You must act of your own free will.\n");
        return 1;
    }

    if (str && member_group(getuid(TP), "law_c")) {
        adm_pass(str);
        return 1;
    }

    if (!str) {
        write("No such user.");
        TO->remove();
        return 1;
    }

    return 1;
}

adm_pass(string uname)
{
    string fname;

    fname = "/adm/save/users/" + uname[0..0] + "/" + uname;

    if (!file_exists("/adm/save/users/" + uname[0..0] + "/" + uname + ".o")) {
        write("No such user.");
        TO->remove();
        return 1;
    }

    write("Changing password for " + uname);



    write("Password:");
    input_to("adm_pw_entry", 1, fname, uname);
}

adm_pw_entry(string str, string fname, string uname)
{
    if(!str)
    {
        write("Empty password");
        TO->remove();
        return;
    }

    write("Retype new password:");
    input_to("adm_pw_verify", 1, fname, uname, str);
}

adm_pw_verify(string str, fname, uname, passwd)
{

    string salt, pass;

    if (str != passwd) {
        write("Sorry, passwords do not match.");
        TO->remove();
        return;
    }

    if (FPL(uname)) {
        write("Error: User is online.");
        TO->remove();
        return;
    }

    salt = PWGEN->random_salt(43);
    pass = crypt(passwd, "$6$" + salt);

    if(!seteuid(UID_USERSAVE))
    {
        write("Permission denied");
        TO->remove();
        return;
    }
    restore_object(fname);
    set_password(pass);
    seteuid(UID_USERSAVE);
    save_object(fname);
    seteuid(getuid());

    TO->remove();
    return;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

passchange - change someone's password

%^CYAN%^DESCRIPTION%^RESET%^

The command allows you to change someone's password.

%^CYAN%^SEE ALSO%^RESET%^

setenv, chfn, who, passwipe, peo

"
        );
}
