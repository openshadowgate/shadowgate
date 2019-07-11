/* Offshoot of avatarmail for handling law complaints *Styx*  7/2003
   "/cmds/mortal/_lawmail.c" inherits this file so the code could be put here for security purposes
*/

#include <std.h>
#define LOCATION "/adm/save/lawboardroom"

inherit DAEMON;

object getBoard()
{
    object ob;
    ob = present("Law_Mail board",find_object_or_load(LOCATION));
    if (!objectp(ob)) {
        LOCATION->reset();
    }
    return ob;
}

int cmd_lawmail(string str)
{
    object board;
    board = getBoard();
    if(!str) 
        return notify_fail(
	  "Please specify a brief title for your message, preferably something "
	  "like 'name's attack on me' or 'abuse of this or that'.  The correct "
          "syntax is <lawmail [title of message]>.  You will then get a "
	  "screen to enter your message.\n"
	);

    if(strlen(str) > 30)
       return notify_fail("Please be more brief on the title, less than 30 characters.\n  You can elaborate in the editor.\n");
     
    tell_object(TP,"You are now in edit to post a message to the "
           "immortals who handle law complaints.  Please supply all "
	   "relevant facts and names of witnesses or logs if brief, "
	   "but do not spam with an excess of information.  We will "
	   "mail or catch you on to ask for more information if needed.  "
	   "Please do not whine.\n"
           "The title is set to:  %^BOLD%^%^YELLOW%^"+str);
     board->post_message(str);
     return 1;
}

int help(){
  if(avatarp(TP))
    write(
@STYX
   Only immortals (avatar and above) see this -
If you are witness to a discussion or event that results in a <lawmail>, please lawmail what you know to be fact and how you know as well as names of those involved or witnesses, esp. if the one who is mailing does not know the login name of the one they are reporting on/against.  
A copy/paste of excerpts from logs or killers list, etc. if applicable might also be useful.  Send whatever you think might be helpful without spamming.  If you have a log, save it until you hear from us if we need it or not.
Thanks in advance for your help.  Mortal's section below
-------------------------------------
STYX
    );
  write(
@STYX
  %^GREEN%^<lawmail [title of message]>%^RESET%^        (puts you into a board editor)
  
  <lawmail> is to be used when you believe a game rule has been broken
or someone is cheating in some fashion.  

Note:  Mails that are only or even predominantly complaining (whining) and being immature about being killed, loss of gear, etc. - especially without clear issues of rules being broken - will most likely be ignored completely.

If you cannot discuss your situation calmly and maturely, it is best to log out, think about the long term and big picture, and then come back to mail or discuss it when you can.  Do be sure to get permission, however, from anyone you are in a RP situation with first and to follow up with them later in some fashion.

%^YELLOW%^The command posts your message to a board that only the immortals who handle law complaints can access.  You may not get a direct response or details about the results of the review and it may take some time for us to speak to everyone who may have relevant information, but all complaints are reviewed in due time.%^RESET%^

Please include a reasonable amount of detail about the situation and brief, relevent logs if available.  If we feel we need more information, one of the immortals handling law issues will contact you and/or the other parties involved.  
If you do not know the real (login) name of the character you are reporting on, try to get the attention of any immortal and point them out by description or adjective.  Ask that immortal to lawmail the name as additional information they may have available regarding your complaint.
STYX
   );
   write(
@STYX
Issues simply of sportsmanship or questionable RP should be addressed in <pkmail> (if applicable) or <avatarmail> if no immortal is available to discuss and help resolve it at the time.

Everyone please remember - this is a Role-Play enforced game.  Cheating may get you levels or funds or other things you think you 'need' until you get caught at it.  In the long run it will only cause you to lose the respect of your fellow players and the immortals.  It will hurt you the player and your character in the long run if not get it or all of them rid.  

You win at this game by RPing so well your character makes a memorable mark on the RP of the game and becomes a part of the IC history.  The sort of mark that even his or her arch enemies' players respect and have fond memories of the challenge of playing against or with.  That and, of course, having fun yourself by enjoying the challenge of overcoming hardship as well as rejoicing when things work out as planned.  
STYX
  );
  write(
@STYX
That is the spirit and essence of the game.  Please keep that in mind before you abuse it or complain about things being tough for your character for whatever reason or crying foul against someone who may simply be doing their best to make their mark and contributing to the challenge and RP.  
No one is perfect and all players make mistakes sooner or later.  Please try to work together in the spirit of the game unless rules are clearly broken that merit admin attention.  In those cases, <lawmail> is your correct recourse.

see also:  avatarmail, pkmail, bug, typo
STYX
  );
  return 1;
}
