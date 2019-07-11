//_adjective

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_adjective(string str)
{
    object desc;

    desc = new(DESC_D);

    if(!str) {

        write("You will now be seen as "+TP->getWholeDescriptivePhrase()+".");
        return 1;
    }

    TP->setDescriptivePhrase(str);

    desc->set_profile_stuff(str,"adjective",TP);

    write("You will now be seen as "+TP->getWholeDescriptivePhrase()+".");
    return 1;

}

int help(){

    write("
%^CYAN%^NAME%^RESET%^

adjective - set short description of your character

%^CYAN%^SYNOPSIS%^RESET%^

adjective [%^ULINE%^%^ORANGE%^TEXT%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command sets short description or your character, a phrase that precedes you to a stranger when they observe a room and a line you can see in who list.

You are required to use automatic racial substitutions %^CYAN%^$R%^RESET%^, for your race, or %^CYAN%^$SR%^RESET%^ in the adjective. If you won't, %^CYAN%^$R%^RESET%^ will be appended to the end of your description.

In addition to that, there are several substitutions to expand your adjective:

    %^CYAN%^$CSR%^RESET%^ - capitalized subrace

    %^CYAN%^$B%^RESET%^ - body type

    %^CYAN%^$B%^RESET%^ - gender

    %^CYAN%^$E%^RESET%^ - eye color

    %^CYAN%^$H%^RESET%^ - hair color

    Your adjective should be something appropriate that someone could tell almost immediately about your character. It should also be fairly short and succinct as well as stable over reasonable periods of time. 

%^CYAN%^EXAMPLES%^RESET%^

$R with long hair
        
    A human with long hair, if you are a human.

$SR with blue hair
        
    A water genasi with blue hair, if your subrace is water genasi.

$G $R with a $B build

    A male human with a scrawny build, if you are human male with scrawny build.

%^CYAN%^SEE ALSO%^RESET%^

describe, who, colors
");
}

