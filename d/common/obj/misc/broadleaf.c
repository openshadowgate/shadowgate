//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>

inherit OBJECT;

int loads,sp, min_con;

void create() {
    ::create();
    loads = 10;
    set("id", ({ "dwarf's pride tobacco","tobacco" }) );
    set_name("dwarf's pride tobacco");
    set_short("%^RESET%^%^BLUE%^Dwarf's Pride Tobacco%^RESET%^");
    set_long("%^BLUE%^A mild blend of orange and mahogany dwarven "+
		"tobaccos with aromatic Halfling Burley and Fired Stoutfolk"+
		" leaf, lightly flavoured with whiskey.\n"
		"%^BOLD%^%^BLUE%^You should pack this in a pipe.\n"
		"%^WHITE%^There are "+loads+" loads left.");
    set_weight(3);
    set_value(250);
    sp = 1;
    min_con = 5;
}

int set_uses(){
    loads -= 1;
        set_long("%^BLUE%^A mild blend of orange and mahogany dwarven "+
		"tobaccos with aromatic Halfling Burley and Fired Stoutfolk"+
		" leaf, lightly flavoured with whiskey.\n"
		"%^BOLD%^%^BLUE%^You should pack this in a pipe.\n"
		"%^WHITE%^There are "+loads+" loads left.");
        write("\n%^BLUE%^You smell the odor of whiskey infused dwarven tobacco.");
        say("\n%^BLUE%^You smell the odor of whiskey infused dwarven tobacco.",
        environment(this_object()));
	
    if(loads < 1){
	write("%^BLUE%^Your pouch of Dwarf's Pride tobacco is empty, so you discard it!");
	remove();
	}
	return sp;
}

int query_uses(){ return loads;}

int query_con_check() { return min_con; }
