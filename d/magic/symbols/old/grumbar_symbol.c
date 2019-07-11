// /d/magic/symbols/grumbar_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";


#define GEMS ({"ruby","sardonyx"})
#define TYPES ({"ring","pendant"})

string gem;
string type;

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!type)
      type = TYPES[random(sizeof(TYPES))];
   set_id(({"holy symbol","symbol","grumbar_holy_symbol",type,gem+" "+type}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_long("This is a brilliant "+gem+" "+type+". The shape of a mountain range is carved into the face of the stone.");
   set_name(gem+" "+type);
   if(member_array(gem[0],({"a","e","i","o","u"}))==-1){
      set_short("a "+gem+" "+type);
   }
   else{
      set_short("an "+gem+" "+type);
   }
}

