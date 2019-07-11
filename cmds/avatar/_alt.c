// /cmds/avatar/_unalt.c
// Pator@ShadowGate Aug 19 2003
// Keep track of all multiple characters without log in restrictions 
// like the <link>/<unlink> command
// based on code created by Pallando (93-05-26)
 
#include <std.h>
#include <security.h>
#include <daemons.h>
 
inherit DAEMON;
 
int cmd_alt( string arg )
{
  string *names, *str;
  int i; 

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
 
if ( !avatarp( previous_object() ) ) return 0;
  if( !arg )
  {
   MULTI_ALT_D-> list_links();
    return 1;
  }
 
  names = explode( arg, " " );
  if( sizeof( names ) < 2 )
  {
    if(str=MULTI_ALT_D->is_linked_char( arg ) ) {
     for(i=0;i<sizeof(str);i++)
      write( capitalize(arg) + " is linked to "+capitalize(str[i])+"." );}
    else write( capitalize(arg) + " is not linked.");  
    return 1;
  }
   if( MULTI_ALT_D-> make_link( names ) )
  {
    write( "Ok, link made.\n" );
    // If you want to log links made, this is the place to do it.
    seteuid(UID_LOG);
    log_file( "watch/alt_char", ctime( time() ) + " "+
      capitalize( geteuid( this_player() ) ) + " linked : " +
      arg + "\n" );
    seteuid(getuid());
  }
  return 1;
}
 
int help()
{
  write( @EndText
Syntax: %^YELLOW%^%^BOLD%^alt%^RESET%^ <main_char> <other_char> [<other_char>] [<other_char>] ...
Effect: Links a player <main_char> to his other characters <other_char>s
        Different than the <link> command, <alt> has no impact on login
        capabilities of the different chars. It is a pure housekeeping solution
Syntax: %^YELLOW%^%^BOLD%^alt%^RESET%^ <char>
Effect: Returns the other character of <char>. 
Syntax: %^YELLOW%^%^BOLD%^alt%^RESET%^
Effect: lists all linked characters.
Note:   To remove an alterante character, use the <unalt> command
Warning: Always type the names in lower case.
EndText
  );
  return 1;
}
