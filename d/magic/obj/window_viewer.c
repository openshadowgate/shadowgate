#include <std.h>
inherit "/d/magic/obj/shadowlistener.c";

void heart_beat()
{
   if(!objectp(TO)) { return; }
   if(follower->query_true_invis()) 
   {
       self_destruct();
       return;
   }
}
