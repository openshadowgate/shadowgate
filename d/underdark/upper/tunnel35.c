#include <std.h> 
#include "../defs.h" 
inherit INH+"spiderarches"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"south":UPPER"tunnel29",
"southwest":UPPER"tunnel31",
"west":UPPER"tunnel34",
"northwest":UPPER"tunnel38",
   ])); 
}