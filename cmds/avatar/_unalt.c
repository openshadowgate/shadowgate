// /cmds/avatar/_unalt.c
// Pator@ShadowGate Aug 19 2003
// Keep track of all multiple characters without log in restrictions 
// like the <link>/<unlink> command
// based on code created by Pallando (93-05-26)
 
#include <std.h>
#include <security.h>
#include <daemons.h>
 
inherit DAEMON;
 
int cmd_unalt( string arg )
{
  string *names;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
 
  if( !wizardp( previous_object() ) ) {
		notify_fail("Only wizards and arches can remove alternative characters");
	}

  if( !arg )
  {
    notify_fail("Correct syntax: unalt <name>\n");
    return 0;
  }
 
    if( MULTI_ALT_D-> unlink( arg ) ) write(capitalize(arg) + " is unlinked." );
    else write(capitalize(arg)+" was not linked in the first place.");
    return 1;
 
}
 
int help()
{
  write( @EndText
Syntax: unalt <char> 
Effect: Removes the alternate character <char> from all the other chars of this player
Warning: Always type the names in lower case.
EndText
  );
  return 1;
}
