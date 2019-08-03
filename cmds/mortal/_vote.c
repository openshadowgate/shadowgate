#include <std.h>

int cmd_vote(string str)
{
    write("%^GREEN%^-=<%^ORANGE%^Vote for ShadowGate%^GREEN%^>=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    write(
"%^BOLD%^%^GREEN%^  We hope you enjoy playing ShadowGate!
  Please, consider voting for us to bring more people into the game:
     Top Mud Sites:     %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/sg-tms%^RESET%^%^BOLD%^%^GREEN%^
     The Mud Connector: %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/sg-tmc%^RESET%^%^BOLD%^%^GREEN%^
  Thank you! "
        );        
    if(str == "social")
    {
        write("%^GREEN%^-=<%^ORANGE%^Social networks%^GREEN%^>=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
        write(
"%^BOLD%^%^GREEN%^  Discord:   %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/discord-sg%^RESET%^%^BOLD%^%^GREEN%^
%^BOLD%^%^GREEN%^  Mastodon:  %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/toot-sg%^RESET%^%^BOLD%^%^GREEN%^   @shadowgate@mastodon.sdf.org
%^BOLD%^%^GREEN%^  Github:    %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/github-sg%^RESET%^%^BOLD%^%^GREEN%^ @shadowgate
%^BOLD%^%^GREEN%^  FaceBook:  %^RESET%^%^BOLD%^%^CYAN%^%^ULINE%^https://bit.ly/fbook-sg%^RESET%^%^BOLD%^%^GREEN%^"            );
    }
    write("%^GREEN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    return 1;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

vote - display voting information to help the game

%^CYAN%^SYNTAX%^RESET%^

vote [social]

%^CYAN%^DESCRIPTION%^RESET%^

This command will display ways for you to vote for the game on various listings to get the word out there and help to bring new players in!



%^CYAN%^SEE ALSO%^RESET%^

who, score, mail
"        
        );
}
    
