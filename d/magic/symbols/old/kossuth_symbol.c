// /d/magic/symbols/kossuth_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"flamedance"})
#define TYPES ({"pendant","ring","brooch","bracelet"})

string gem;
string type;

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!type)
      type = TYPES[random(sizeof(TYPES))];
   set_id(({"holy symbol","symbol","kossuth_holy_symbol",type,gem+" "+type}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_long("The "+gem+" set in the "+type+" glows with an inner fire. The stone is in the shape of a single springing flame, flickering as if it is alive.");
   set_name(gem+" "+type);
   if(member_array(gem[0],({"a","e","i","o","u"}))==-1){
      set_short("a "+gem+" "+type);
   }
   else{
      set_short("an "+gem+" "+type);
   }
}
