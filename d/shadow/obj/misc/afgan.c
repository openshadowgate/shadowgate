//Gave new desc and made it more IG - Cythera 4/05

#include <std.h>

inherit OBJECT;

int loads,sp, min_con;

void create() {
    ::create();
    loads = 10;
    set_id(({ "luxury of tharis tobacco","tobacco" }) );
    set_name("luxury of tharis");
    set_short("%^BOLD%^%^BLACK%^Luxury of Tharis Tobacco%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Incredibly popular and very rare. Mild, golden Cordazethes,"+
		" that possess a natuarlly high sweetness, are mixed with a "+
		"very mild Black Cavendish. A fresh flavor with essences of "+
		"exotic fruits and a touch of Bourbon Vanilla is added to make"+
		" this a very mild blend.\n"
		"%^YELLOW%^You should pack this in a pipe.\n"
		"%^RESET%^There are "+loads+" loads left.");
    set_weight(3);
    set_value(2000);
    sp = 5;
    min_con = 14;
}

int set_uses(){
    loads -= 1;
        set_long("%^BOLD%^%^BLACK%^Incredibly popular and very rare. Mild, golden Cordazethes,"+
		" that possess a natuarlly high sweetness, are mixed with a "+
		"very mild Black Cavendish. A fresh flavor with essences of "+
		"exotic fruits and a touch of Bourbon Vanilla is added to make"+
		" this a very mild blend.\n"
		"%^YELLOW%^You should pack this in a pipe.\n"
		"%^RESET%^There are "+loads+" loads left.");
        write("\n%^BOLD%^%^BLACK%^You smell the sweet aroma of the bourbon infused tobacco.");
        say("\n%^^BOLD%^%^BLACK%^You smell the sweet aroma of the bourbon infused tobacco.", environment(this_object()));
	
    if(loads < 1){
	write("%^BOLD%^%^BLACK%^Your pouch of Luxery of Tharis is empty, so you discard it!");
	remove();
	}
	return sp;
}

int query_uses(){ return loads;}

int query_con_check() { return min_con; }
