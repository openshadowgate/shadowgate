//Offshoot of avatarmail for reporting pk's *Styx*  6/2002

#include <std.h>

inherit DAEMON;

object getBoard(){
    object ob;
    ob = present("pkmail board",find_object_or_load("/d/dagger/pkboard"));
    if (!objectp(ob)) {
        "/d/dagger/pkboard"->reset();
    }
    return ob;
}

int cmd_pkmail(string str) {
    object board;
    board = getBoard();
    if(!str)
        return notify_fail("Please specify a title for your message, preferably something "
	  "like 'name's attack on me' or 'my attack on name(s)'.  The correct "
           "syntax is <pkmail [title of message]>.  You will then get a "
	   "screen to enter your message.\n"
        );
    if(strlen(str) > 30)
        return notify_fail("Please be more brief on the title, less than 30 characters.\n  You can elaborate in the editor.\n");
     
    tell_object(TP,"You are now in edit to post a message to a board "
           "for reporting PK attacks.  Please be brief but include the "
	   "5 w's -\n %^BOLD%^%^WHITE%^Who %^RESET%^(include witnesses, even NPC's "
	   "you know might have seen something),\n%^BOLD%^What %^RESET%^"
	   "(mugging, kill, torture, outcome),\n%^BOLD%^When %^RESET%^"
	   "(mud time from the 'date' command, time of day IC and weather),\n"
	   "%^BOLD%^Where %^RESET%^(indoors or outdoors and as specific as "
	   "meaningful, i.e. weapon shop in Shadow), and \n%^BOLD%^Why %^RESET%^"
	   "(if you are the victim, this may be just relating what RP you recall "
	   "that might have contributed or simply tell how you know the "
	   "attacker, if you even know who it was).  Also include a brief \n"
	   "%^BOLD%^How%^RESET%^, "
	   "including relevant info. such as if you were invisible, they were "
	   "blind the whole time, etc.\n"
           "The title is set to:  %^BOLD%^%^YELLOW%^"+str);
    board->post_message(str);
    return 1;
}

int help(){
  write(
@STYX
  pkmail <title of message>        (puts you into a board editor)
  
  Mortals cannot view, read, or access the board directly in any way.
  pkmail is required for all attackers and victims to report on pk attacks

  This command post your message to a board that the immortals read to 
review pk events - attacks, not just kills.  The purpose is to allow the
immortals to make judgements about the chance citizens might have reported
something to the local law, PC's, church officials, etc. as well as review
how alignments are being played and watch for excessive pking.
  Information on why may also be used to determine what plots the deceased
would be out of from a death, so be sure to include what intentions you
may have had in that regard (i.e. there is a war, they are one of the
enemy, therefore they should no longer be part of that war).

see also:  avatarmail, lawmail, bug, typo
STYX
   );
   write(
@STYX
The information needed (briefly) is mostly the 5 w's of reporting:
-----------------------------------------------------------------
  %^BOLD%^Who %^RESET%^(include witnesses, even NPC's you know might have seen something),
  %^BOLD%^What %^RESET%^(mugging, kill, torture, outcome),
  %^BOLD%^When %^RESET%^(mud time from the 'date' command, time of day IC and weather),
  %^BOLD%^Where %^RESET%^(indoors or outdoors and as specific as meaningful, i.e. weapon shop in Shadow), and 
  %^BOLD%^Why %^RESET%^(if you are the victim, this may be just relating what RP you recall that might have contributed or simply tell how you know the attacker, or if you even know who it was)
Also include a brief 
   %^BOLD%^How%^RESET%^, including relevant info. such as if you were invisible, they were blind the whole time, any special items used or other important details.  Again, please be reasonably concise.

see also:  avatarmail
STYX
  );
  return 1;
}
