//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>

inherit OBJECT;

int loads,sp, min_con;

void create() {
    ::create();
    loads = 10;
    set_id(({ "pirate's booty tobacco","tobacco" }) );
    set_name("pirate's booty tobacco");
    set_short("%^RESET%^%^CYAN%^Pirate's Booty Tobacco%^RESET%^");
    set_long("%^CYAN%^A smooth exquisite blend of black cavendish, burley and "+
		"three different cordizans. Notes of honey, vanilla and "+
		"orange are added to this favorite tobacco of sailors and pirates.\n"
		"%^GREEN%^You should pack this in a pipe.\n"
		"%^BOLD%^%^GREEN%^There are "+loads+" loads left.");
    set_weight(3);
    set_value(500);
    sp = 5;
    min_con = 12;
}

int set_uses(){
    loads -= 1;
        set_long("%^CYAN%^A smooth exquisite blend of black cavendish, burley and "+
		"three different cordizans. Notes of honey, vanilla and "+
		"orange are added to this favorite tobacco of sailors and pirates.\n"
		"%^GREEN%^You should pack this in a pipe.\n"
		"%^BOLD%^%^GREEN%^There are "+loads+" loads left.");
        write("\n%^BOLD%^%^CYAN%^%^You smell the sweet odor of honey, vanilla, and orange"+
		" infused with tobacco.");
        say("\n%^BOLD%^%^CYAN%^You smell the sweet odor of honey, vanilla, and orange "+
		"infused tobacco.",
        environment(this_object()));
	
    if(loads < 1){
	write("%^CYAN%^Your pouch of Pirate's Booty Tobacco is empty, so you discard it!");
	remove();
	}
	return sp;
}

int query_uses(){ return loads;}

int query_con_check() { return min_con; }
