//meadow.c - entry meadow to Shrydelhi's house - coded by Circe 9/10/03
#include <std.h>
#include "shry.h"
inherit ROOM;
int found_flowers = 0;
int found_berries = 0;
int found_key = 0;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("A lush meadow");
   set_short("A lush meadow ");
   set_long("The %^GREEN%^forest %^RESET%^gives way to an incredibly beautiful "+
      "meadow, dappled with the brilliant colors of the "+
      "%^MAGENTA%^w%^BOLD%^%^CYAN%^i%^BLUE%^l%^BOLD%^%^RED%^d%^BOLD%^%^MAGENTA%^f"+
      "%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^o%^RESET%^%^RED%^w%^BOLD%^%^MAGENTA%^RESET%^%^e%^CYAN%^r%^BLUE%^s "+
      "%^RESET%^growing throughout the clearing. A %^BOLD%^%^CYAN%^babbling brook "+
      "%^RESET%^slowly meanders through the back edge of the meadow, where wild "+
      "%^RED%^b%^BOLD%^%^RED%^e%^RESET%^%^RED%^rr%^BOLD%^%^RED%^i%^RESET%^%^RED%^es "+
      "%^RESET%^grow in abundance and mark the edge of the %^GREEN%^forest.  "+
      "%^RESET%^A single large, %^RESET%^%^ORANGE%^ancient oak tree %^RESET%^grows "+
      "in the rough center of the meadow, surrounded by tiny pinpricks of "+
      "%^YELLOW%^glowing lights %^RESET%^floating about."+
      "\n");
   set("night long",
      "The moon bathes a beautiful meadow in her silvery essence.  "+
      "Everything seems to sparkle in the moonlight as if there is "+
      "a special kind of magic on the meadow.  The brook, flowers "+
      "and even the berries take on a silvery hew.  Even the large "+
      "Oak at the north side of the meadow has given away its color to "+
      "the more blue-silver illumination of the moon."
   );
   set_smell("default","You smell the fresh scent of wildflowers.");
   set_listen("default","You hear the soft babble of the brook flowing over smooth rocks.");
   set_items(([
      (({"wildflowers","flowers"})) : "%^MAGENTA%^w%^BOLD%^%^CYAN%^i%^BLUE%^l%^BOLD%^%^RED%^d"+
         "%^BOLD%^%^MAGENTA%^f%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^o%^RESET%^%^RED%^w%^BOLD%^%^MAGENTA%^e"+
         "%^CYAN%^r%^BLUE%^s %^RESET%^in every imaginable color dapple the %^GREEN%^tall grass "+
         "%^RESET%^of the meadows in soft hues of %^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^u"+
         "%^BOLD%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^pl%^RESET%^MAGENTA%^e%^BOLD%^%^MAGENTA%^s, "+
         "%^BLUE%^b%^RESET%^CYAN%^l%^BOLD%^%^BLUE%^u%^BOLD%^%^CYAN%^e%^BOLD%^%^BLUE%^s, "+
         "%^YELLOW%^yellows %^RESET%^and %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^ds%^RESET%^.",
      "berries" : "%^RESET%^%^GREEN%^Various types of berry bushes tumble out of the forest "+
         "to meet the edge of the meadow, casting their %^BOLD%^%^BLACK%^shadow "+
         "%^RESET%^%^GREEN%^across part of the %^BOLD%^%^CYAN%^brook%^RESET%^.", 
      "brook" : "%^BOLD%^%^CYAN%^A babbling brook bubbles as its crystal waters "+
         "make their way over smooth rocks at the back edge of the meadow.  The smooth, "+
         "gray rocks seem to lift and move slightly with the current.%^RESET%^",
      "lights" : "%^BOLD%^%^YELLOW%^Several glowing fireflies fly about the base "+
         "of the tree, giving it an almost magical appearance.%^RESET%^",
      "tree" : "%^GREEN%^A single ancient oak tree grows in the middle of the "+
         "meadow.  Its sheer size is impressive, with an abundance of natural "+
         "wildlife living in its umbrella of branches and leaves. Natural growth "+
         "around the tree has formed into what look like steps spiraling up to a large "+
         "branch that looks more like a platform.  More interestingly, another natural "+
         "formation at the platform looks much like a large door or entrance of sorts "+
         "that leads into the trunk of the tree itself.%^RESET%^", 
      (({"steps", "stairs"})) : "%^RESET%^%^ORANGE%^Natural growth at the trunk of the tree has "+
         "formed into what looks very much like steps that spiral up around the tree "+
         "and eventually lead to a large, flat branch that looks more like a "+
         "platform.%^RESET%^",
      "platform" : "%^RESET%^%^ORANGE%^A large branch has grown to be somewhat "+
         "flat and smooth at the top, looking very much like a platform that gives way "+
         "to a large opening into the tree itself.%^RESET%^"])); 
   set_exits(([
      "forest" : SHRY"path2",
      "steps" : SHRY"platform"
   ]));
   set_search("default","A strange shadow underneath the rocks in the brook catches your eye.");
   set_search("brook", (: TO, "search_brook" :) );
}

void init()
{
	::init();
	add_action("pick", "pick");
      add_action("gather", "gather");
      add_action("drink_func", "drink");
}

void reset()
{
   ::reset();
   if(!present("butterfly")) {
      if(query_night() == 1) {
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
         new(MON"shry_butterfly")->move(TO);
      }
   }
}

int search_brook() {
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
      if(found_key) {
         tell_object(TP, "You reach into the brook but find only rocks and sand.");
         tell_room(ETP, ""+TPQCN+" reaches deep into the brook and lets a few rocks slip "+
            "through "+TP->query_possessive()+" fingers.",TP);
         return 1;
      }
      else{
         tell_object(TP,"You lift a small rock in the brook and find a twig hidden underneath.");
         tell_room(ETP,"Lifting a small rock, "+TPQCN+" retrieves a small, wet twig.",TP);
         new(OBJ"shry_twig_key")->move(TP);
         found_key = 1;
         return 1;
      }
}

int pick(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
	tell_object(TP,"Pick what?");
	return 1;
	}
	if(str != "flowers" && str != "wildflowers") {
	write("You do not see that here.");
	return 1;
	}
      if(found_flowers) {
	tell_object(TP,"You cannot find any stray wildflowers to pick.");
	return 1;
	}
	else {
	tell_object(TP,"%^YELLOW%^You pick a lovely bouquet of wildflowers and tie them "+
         "together with an ivy vine.");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" picks a lovely bouquet of wildflowers and ties "+
         "them with an ivy vine.",TP);
	new(OBJ"shry_flowers")->move(TO);
	found_flowers = 1;
	return 1;
	}
}

int gather(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
	tell_object(TP,"Gather what?");
	return 1;
	}
	if(str != "berries" && str != "berry") {
	write("You do not see that here.");
	return 1;
	}
      if(found_berries) {
      tell_object(TP,"All the bushes are bare.");
      return 1;
      }
      else {
      tell_object(TP,"%^MAGENTA%^You stain your hands with juice as you gather a few plump berries.");
      tell_room(ETP,"%^MAGENTA%^"+TPQCN+" gathers berries as juice stains "+TP->query_possessive()+" "+
         "fingertips.",TP);
      new(OBJ"shry_berries")->move(TP);
      found_berries = 1;
      return 1;
      }
}

int drink_func(string str) {
   if(!str) return 0;
   if(str != "water from brook" && str != "from brook")
      return 0;
   if(!TP->add_quenched(20))
      return notify_fail("Your stomach is sloshing already!\n");
   tell_object(TP,"Kneeling by the brook's edge, you take a deep drink of the cool water.");
   tell_room(TO,""+TPQCN+" kneels at the edge of the brook and takes a deep drink of the clear water.",TP);
   return 1;
}