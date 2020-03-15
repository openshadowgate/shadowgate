//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>

inherit OBJECT;

int loads,sp, min_con;

void create() {
    ::create();
    loads = 10;
    set_id(({ "hafling's homeblend tobacco", "tobacco" }) );
    set_name("halfling's homeblend tobacco");
    set_short("%^RESET%^%^GREEN%^Halfling's Homeblend Tobacco%^RESET%^");
    set_long("%^GREEN%^A mixture of broad and very ripe Halfling Burley,"+
		" double fermented Black Cavendish. A wonderful natural "+
		"sweetness with a touch of apple flavor.\n"
		"%^BOLD%^%^GREEN%^You should pack this in a pipe.\n"
		"%^YELLOW%^There are "+loads+" loads left.");
    set_weight(3);
    set_value(350);
    sp = 2;
    min_con = 10;
}

int set_uses(){
    loads -= 1;
       set_long("%^GREEN%^A mixture of broad and very ripe Halfling Burley,"+
		" double fermented Black Cavendish. A wonderful natural "+
		"sweetness with a touch of apple flavor.\n"
		"%^BOLD%^%^GREEN%^You should pack this in a pipe.\n"
		"%^YELLOW%^There are "+loads+" loads left.");
        write("\n%^GREEN%^You smell the sweet odor of fresh tobacco with a hint of apple.");
        say("\n%^GREEN%^You smell the sweet odor of fresh tobacco with a hint of apple.",
        environment(this_object()));
	
    if(loads < 1){
	write("%^GREEN%^Your pouch of Halfling's Homeblend is empty, so you discard it!");
	remove();
	}
	return sp;
}

int query_uses(){ return loads;}

int query_con_check() { return min_con; }
