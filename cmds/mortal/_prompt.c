// Command to change prompt to different things
// Coded by Bane@Shadowgate
#include <std.h>
inherit DAEMON;
void cmd_prompt(string str){
    if(!str)
    {
        TP->setenv("prompt","%^BOLD%^BLACK%^-%^RED%^>%^RESET%^");
        TP->initialize();
        write("Prompt reset.");
        return 1;
    }
    TP->setenv("prompt", str);
    TP->initialize();
    write("Prompt changed.");
    return 1;
}
void help(){
    write("
	Command that allows you to change your current prompt settings.
	When used with no arguments(i.e. <prompt>), the prompt
	will reset to a default of %^BOLD%^BLACK%^-%^RED%^>%^RESET%^, Otherwise the prompt will
	become whatever you type after the prompt command.  [Example: prompt 
	Bane >] would look like this at my prompt:
		Bane >
	To change the prompt to show your current hit points use the argument 
	$h, and to show your maximum hit points use the argument $H.  If you 
	wish to show your current hit points over your maximum hit points use
	$h/$H.  [Example: prompt $h/$H >] would look like:
		300/320 >


	available codes: 
	  $F capitalized shapeshifted form
	  $f lower case shapeshifted form
	  $h current hp
	  $H maximum hp
	  $p power points
	  $P maximum power points
	  $L current language
	  $N name of mud
	  $r rage status
	  $S condition
	  $W current wimpy %
	  $E eldritch essence
	  $k available ki
	  $K maximum ki      
    ");
  if (avatarp(TP)) {
    write("$I shows True Invis / Mortal Invis / Stealthed status");
  }
    return 1;
}