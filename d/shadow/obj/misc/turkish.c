//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>

inherit OBJECT;

int loads,sp, min_con;

void create() {
    ::create();
    loads = 10;
    set_id(({ "white dragon tobacco","dragon tobacco","tobacco" }) );
    set_name("white dragon tobacco");
    set_short("%^BOLD%^%^WHITE%^White Dragon Tobacco%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This excellent mixture is a blend of first choice Undalish,"+
		" Burley, and Black Cavendish. A promise for a unique "+
		"smoking experience, which is crowned by a wonderful amaretto"+
		" aroma that also gives enjoyment to the smokers' surroundings."+
		"  A popular tobacco that was first sold in Antioch's White Dragon Inn.\n"
		"%^BOLD%^%^CYAN%^You should pack this in a pipe.\n"
		"%^BOLD%^%^BLUE%^There are "+loads+" loads left.");
    set_weight(3);
    set_value(950);
    sp = 4;
    min_con = 13;
}

int set_uses(){
    loads -= 1;
        set_long("This excellent mixture is a blend of first choice Undalish,"+
		" Burley, and Black Cavendish. A promise for a unique "+
		"smoking experience, which is crowned by a wonderful amaretto"+
		" aroma that also gives enjoyment to the smokers' surroundings."+
		"  A popular tobacco that was first sold in Antioch's White Dragon Inn.\n"
		"%^BOLD%^%^CYAN%^You should pack this in a pipe.\n"
		"%^BOLD%^%^BLUE%^There are "+loads+" loads left.");
        write("\n%^BOLD%^%^WHITE%^You smell the rich amaretto infused aroma of the tobacco.");
        say("\n\n%^BOLD%^%^WHITE%^You smell the rich amaretto infused aroma of the tobacco.",
        environment(this_object()));
	
    if(loads < 1){
	write("%^BOLD%^%^WHITE%^Your pouch of White Dragon Tobacco is empty, so you discard it!");
	remove();
	}
	return sp;
}

int query_uses(){ return loads;}

int query_con_check() { return min_con; }
