/** -*-C++-*- **
 * sefun.c -- craz's personal sefun daemon.  this daemon contains funtions
 *  that are commonly used through craz's junk... >:P
 *
 * craz@shadowgate -- 9609 -- creation 
 *****/
#include <std.h>
#include "/realms/craz/include/defs.h"

inherit DAEMON;

/* prototype some member functions */
static void create();
string *loadConfig( string file );
string trim( string str );
static int loadConfig_filter( string e );


/*****
 * static void create();
 *  -- apply that the driver calls when this object is first created
 *****/
static void create()
{
  daemon::create();

  seteuid( getuid() );
}


/*****
 * string *loadConfig( string file );
 *  -- reads the file specified by 'file' and returns an array where each
 *     element is a line in the file.  blank lines and text after a #
 *     are ignored.  all leading and trailing spaces on the lines are
 *     removed.  this function is intended for configuration files
 *****/
string *loadConfig( string file )
{
  string *ret;
  string s;
  int c, x;
  
  /* read in the file */
  if ( ( s = read_file( file ) ) == 0 )
    error( "CRAZ_SEFUN_D::loadConfig -- unknown file '" + file + "'\n" );

  /* remove all the leading and trailing spaces && trim out comments */
  for ( ret = explode( s, "\n" ), c = 0; c < sizeof( ret ); ++c ) {
    ret[c] = trim( ret[c] );

    x = strsrch( ret[c], '#' );

    if ( x == 0 )
      ret[c] = "";
    else if ( x > 0 )
      ret[c] = ret[c][0..x - 1];
  }

  /* filter out unwanted lines */
  ret = filter_array( ret, "loadConfig_filter", TO() );
  
  /* all done. */
  return ret;
}


/*****
 * string trim( string str );
 *  -- removes the beginning and trailing spaces in the string 'str'
 *****/
string trim( string str )
{
  int b, e;

  /* find the beginning of the string w/o whitespace */
  for ( b = 0;
	member_array( str[b], ({ ' ', '\t' }) ) != -1;
	b++ )
    ;

  /* find the end of ending of the string w/o whitespace */
  for ( e = strlen( str ) - 1; 
        b < e && member_array( str[e], ({ ' ', '\t' }) ) != -1;
        e-- )
    ;

  /* return the sub string */
  return str[b..e];
}


/*****
 * static int loadConfig_filter( string e );
 *  -- internal function used by loadConfig.  this function filters out
 *     any unwanted lines from the configuration file
 *****/
static int loadConfig_filter( string e )
{
  int c;

  /* make sure there is something in the string */
  if ( !e || e == "" )
    return 0;

  /* everything passed... keep this line */
  return 1;
}

