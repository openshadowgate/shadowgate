// /d/magic/symbols/istishia_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"jade","emerald","malachite","aquamarine","water opal"})
#define TYPES ({"medallion","ring","brooch"})

string gem;
string type;

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!type)
      type = TYPES[random(sizeof(TYPES))];
   set_id(({"holy symbol","symbol","istishia_holy_symbol",type,gem+" "+type}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_long("This is a finely crafted "+gem+" "+type+". A cresting wave is carved deep into the "+gem+" and the colors shift with the light, as if water is moving within.");
   set_name(gem+" "+type);
   if(member_array(gem[0],({"a","e","i","o","u"}))==-1){
      set_short("a "+gem+" "+type);
   }
   if(gem == "emerald" || gem == "aquamarine") {
      set_short("an "+gem+" "+type);
   }
}

