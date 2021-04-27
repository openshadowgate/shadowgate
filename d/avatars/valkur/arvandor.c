#include <std.h>
inherit "/std/food";

void init(){
	::init();
		add_action("eat_me","eat");
}

void create() {
	::create();
		set_name("food");
		set_short("%^BOLD%^%^GREEN%^An oddly %^WHITE%^perfect %^RED%^"+
			"a%^RESET%^%^RED%^pp%^BOLD%^%^GREEN%^l%^RED%^e%^RESET%^");
		set_long("%^BOLD%^%^GREEN%^This is one of the largest pieces of "+
			"fruit you've ever seen! An enourmous %^RED%^a%^RESET%^"+
			"%^RED%^pp%^BOLD%^%^GREEN%^l%^RED%^e%^GREEN%^, unbruised "+
			"and fantastically smooth and ripe. Light reflects off "+
			"its surface like it was made of tastey steel. Just holding "+
			"it seems to fill you with an inner calm, you can only "+
			"imagine what eating it would feel like...");
   set_strength(15);
}


int eat_me(string str){
	object eatfood;
	tell_object(TP,"%^BOLD%^%^WHITE%^You feel a strange cooling fill "+
		"you as you eat, starting in your chest the cold senstation "+
		"moves out to your skin, soothing your wounds and leaving you "+
		"feeling refreshed and at peace.");
	tell_room(ETP,"%^BOLD%^%^WHITE%^As "+TP->QCN+" finsihes off the "+
		"fruit you notice a dramatic change in his skin, the angry red "+
		"scares pale significantly and some of the hardness around his "+
		"eyes relaxes.",TP);
	remove();
	return 1;
}

