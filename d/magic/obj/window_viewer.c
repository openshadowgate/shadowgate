#include <std.h>
inherit "/d/magic/obj/shadowlistener.c";

void heart_beat()
{
   if(!objectp(TO)) { return; }
}

catch_tell(string str){
   if(!objectp(caster)){
      dest_me();
      return;
   }
   tell_object(caster,"%^CYAN%^Through the window you see:%^RESET%^   "+str);
}

