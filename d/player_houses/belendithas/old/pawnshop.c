//Octothorpe (4/13/10)
//Belendithas HM House
//NW to "pit", NE to altar which will have secret doohickey to TP player into foyer
//Real altar room and Dithas's bedroom will be east exit off of foyer, torture room is west of foyer

#include <std.h>
inherit VAULT;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(SLICK_FLOOR);
   set_name("The Sleazy Pit (A night club)");
   set_short("%^RESET%^%^MAGENTA%^The %^RESET%^%^BLUE%^Sleazy "+
      "%^BOLD%^%^BLACK%^Pit%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The name of the place defies the logic "+
      "of this very posh and upscale night club.  Upon first entering "+
	  "your senses are all overwhelmed by the music, the expensive "+
	  "incense wafting from canisters %^RED%^burning %^BLACK%^and "+
	  "hanging from the ceiling by %^WHITE%^thin ornate chains"+
	  "%^BLACK%^, people laughing or yelling, lines of people "+
	  "waiting to buy the latest and greatest items or poor "+
	  "%^YELLOW%^adventurers%^BLACK%^ pawning their hard earns "+
	  "treasures for a little mad money.  %^RESET%^%^ORANGE%^"+
	  "Nude and nearly nude %^BOLD%^%^MAGENTA%^dancers%^BLACK%^, "+
	  "both male and female strut their irresistable shapes atop "+
	  "the %^BLUE%^very long bar%^BLACK%^ that makes up the entire "+
	  "length of one side of the club.  %^RESET%^%^GREEN%^The middle "+
	  "of the club%^BOLD%^%^BLACK%^ is a hodge-podge of %^BLUE%^coffee "+
	  "tables%^BLACK%^, %^RED%^cocktail couches%^BLACK%^ and a %^RESET%^"+
	  "%^ORANGE%^dance floor%^BOLD%^%^BLACK%^ for those who would rather "+
	  "dance than watch the %^RED%^e%^RESET%^%^RED%^r%^BOLD%^o%^RESET%^"+
	  "%^RED%^t%^BOLD%^i%^RESET%^%^RED%^c %^BOLD%^%^BLACK%^displays "+
	  "on the bar.  There are %^GREEN%^menus%^BLACK%^ at the bar and "+
	  "on the coffee tables.  %^CYAN%^The far side of this shop"+
	  "%^BLACK%^ is an equally long series of %^WHITE%^glass "+
	  "displays%^BLACK%^ filled with every kind of item you might "+
	  "find if you were an adventurer from silk rope to the most "+
	  "prized artifacts the realm has every known.  Now that you've "+
	  "entered %^BLUE%^The %^RESET%^%^RED%^Sleazy%^BOLD%^%^WHITE%^ "+
	  "Pit, figure out which of the earthly pleasures or treasures "+
	  "can be yours. There is a sign hanging from the ceiling near "+
	  "the back of the club.");
   set_smell("default","Rich incenses engulf your nostrils.");
   set_listen("default","Sensual, rhythmic music rises and falls "+
      "constantly.  Many voices chit-chatting or ordering drinks can "+
	  "be heard.  Discussion of the purchase of goods seeps into the "+
	  "general hubub once in a while.");
   set_items(([
      ({"menu","cocktail menu"}) : "Maybe you could read menu",
	  ({"cocktail couch","couch"}) : "These couches are all arranged "+
	     "where you and your friends can sit for drinks in comfort.",
	  ({"displays", "glass displays" }) : "Do you want to looked at pawned items?",
	  ({"sign"}) : "Perhaps you want to 'read sign'?"
   ]));
   set_exits(([
      "south" : "/d/attaya/newseneca/rooms/street6",
	  /*"northwest" : "WIZ (filename)",
	  "northeast" : "WIZ (filename)"*/
   ]));
   set_door("huge double doors","/d/attaya/newseneca/rooms/street6","south",0);
   set_door_description("huge double doors", "These two doors are almost "+
      "as tall as the building itself.  They are made out of wrought "+
	  "iron and have rows up on rows of small stained glass windows "+
	  "behind an ever curling set of gothic burglar bars.  It would "+
	  "easily take 2 large men to push either of these doors open or shut.");
   /*set_door("sliding door","WIZ (filename)","northeast",0);
   set_door_description("sliding door", "This simple door is a pocket "+
      "door that slides right into the wall when opened and fits nearly "+
	  "perfectly with the wall when closed.  It is made of a tarred pine "+
	  "and seems well used.");
   set_door("french doors", "WIZ (filename)","northwest",0);
   set_door_descrition("french doors", "These custom made doors are "+
      "made of a hardy oak, finsished with a matte black stain.  Small "+
	  "windows form an array of see through portals on each door, though "+
	  "a curtain on the inside prevents the viewer for seeing anything "+
	  "on the other side.  The knobs on the doors are a lever type made "+
	  "of a polished brass and matches the rest of the fancy decour of "+
	  "the club.");*/
}