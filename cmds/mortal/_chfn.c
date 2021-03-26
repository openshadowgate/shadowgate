#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_chfn(string arg) {
    if( (string)this_player()->query_name() == "guest" ) return 0;
    write("Changing finger information on " +
          (string) this_player()->query_name() + " at ShadowGate.\n");
    write("Default values are printed inside '[]'.\n");
    write("To accept the default, type <return>.\n");
    write("\n");
    write("Email address ["+this_player()->query_email()+"] : ");
    input_to("new_email");
    return 1;
}

void warning_display()
{
    write ("Input any information you wish to show up at the bottom of your finger display.

Type ** to exit.");
}

protected void new_email(string e)
{
    string user,host, olde;
    olde=this_player()->query_email();
    if (!e && stringp(olde))
    {
        write ("Leaving email as ["+olde+"].");
        warning_display();
        input_to("ooc_contact");
        return;
    }

    if( (strlen(e) > 0 ) && sscanf(e,"%s@%s",user,host) != 2)
    {
        write("Email address must be in the form user@host.\nPlease input again.");
        write("Email address ["+olde+"] : ");
        input_to("new_email");
        return;
    }
    if (e == olde)
    {
        warning_display();
        input_to("ooc_contact");
        return;
    }
    if( e && strlen( e ) > 0 )
    {
        seteuid(UID_USERACCESS);
        this_player()->set_email(e);
        seteuid(getuid());
        seteuid(UID_LOG);
        log_file("player/chfn",this_player()->query_name()+":"+olde+" -> "+e+" .\n");
        seteuid(getuid());
        warning_display();
        //write("OOG Contact Information:\n");
        input_to("ooc_contact", "");
        return;
    }
    return 1;
}

protected void ooc_contact(string cont, string contact)
{
    if(cont == "**")
    {
        if(stringp(contact) && contact != "")
        {
            write("Setting ooc contact information to \n\n"+contact);
            this_player()->set("ooc contact", contact);
            return;
        }
        else
        {
            write("Exiting chfn, without setting any additional information.");
            this_player()->delete("ooc contact");
            return;
        }
    }
    if(!cont || cont == "")
    {
        if(!stringp(contact)) contact = "";
        else contact += "\n";
        write("Inserting carriage return. Enter any additional OOG contact information. Or enter ** to exit.");
        input_to("ooc_contact", contact);
        return;
    }
    else
    {
        if(stringp(contact)) contact += cont;
        else contact = cont;
        write("Enter any additional OOG contact information. Or enter ** to exit.");
        input_to("ooc_contact", contact);
        return;
    }
}

int
help() {
    write("
%^CYAN%^NAME%^RESET%^

chfn - change user information

%^CYAN%^DESCRIPTION%^RESET%^

Asks and updates your information for finger command.

With exception of an e-mail, providing data here is strictly voluntary.

Reminder, do no use information provided by others to harass them.

%^CYAN%^SEE ALSO%^RESET%^

finger, who, set, passwd, ignore
"
        );
    return 1;
}
