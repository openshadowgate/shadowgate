#include <std.h>


inherit ROOM;


void create(){
  ::create();
  set_short("Inside a tent");
  set_long( "You are inside a big tent. If someone has a better description of it that they would like"
           " to give to Lujke, he will very happily update it." );
  set_property("light",2);
}
