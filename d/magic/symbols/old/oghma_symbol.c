// /d/magic/symbols/oghma_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define SDESC ({"a black and gold brocade vest","a purple silk vest","a crimson velvet vest"})

string sdesc;

void create(){
   ::create();
   if(!sdesc)
      sdesc = SDESC[random(sizeof(SDESC))];
   set_id(({"holy symbol","symbol","oghma_holy_symbol","vest"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_short(""+sdesc+"");
   if(sdesc == "a black and gold brocade vest"){
      set_long("A vest made from black and gold brocade.  The vest depicts many gylphs, sigils, runes, and symbols of magical power, arcane meaning, and significance of various races and realms down through the ages.  Over the left chest the symbol of a blank scroll is most prominent.");
   }
   if(sdesc == "a purple silk vest") {
      set_long("This is a vest made from purple silk.  The vest is adorned with holy symbol of Oghma, a blank scroll, on the back.  A symbol of two cupped hands, fingers uppermost and thumbs touching covers either side ont he front of the vest.  This symbol is called the Chelsinara and followers Oghma know that it means 'I learn'.");
   }
   if(sdesc == "a crimson velvet vest") {
      set_long("This is a vest made from crimson velvet.  The vest is adorned with holy symbol of Oghma, a blank scroll, on the back.  A symbol of two cupped hands, fingers uppermost and thumbs touching covers either side ont he front of the vest.  This symbol is called the Chelsinara and followers Oghma know that it means 'I learn'.");
   }
}

