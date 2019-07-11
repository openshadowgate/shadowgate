// /d/magic/symbols/akadi_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"quartz","augelite","turquoise","beryllonite","blue spinel","sapphire"})
#define TYPES ({"bracelet","ring","necklace"})

string gem;
string type;

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!type)
      type = TYPES[random(sizeof(TYPES))];
   set_id(({"holy symbol","symbol","akadi_holy_symbol",type,gem+" "+type}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_long("This is a beautifully made "+gem+" "+type+". A white cloud - magically etched onto the blue stone - sparkles as light is reflected off the "+type+".");
   set_name(gem+" "+type);
   if(member_array(gem[0],({"a","e","i","o","u"}))==-1){
      set_short("a "+gem+" "+type);
   }
   if(gem == "augelite") {
      set_short("an "+gem+" "+type);
   }
}
