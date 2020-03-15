//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>

inherit OBJECT;

int loads,sp, min_con;

void create() {
    ::create();
    loads = 10;
    set_id(({"brazil","tsarven","tobacco","tsarven tobacco","tsarven"}));
    set_name("tsarven");
    set_short("%^RESET%^%^RED%^Tsarven tobacco%^RESET%^");
    set_long("%^RED%^A satisfying, spicy and aromatic blend of Black Cavendish,"+
		" Golden & Red Undrin, mixed with luxury brocken flake. The "+
		"aromatic recipe of Vanilla and Rum make this blend smooth and"+
		" very pleasent.\n"
		"%^ORANGE%^You should pack this in a pipe.\n"
		"%^YELLOW%^There are "+loads+" loads left.");
    set_weight(3);
    set_value(400);
    sp = 3;
    min_con = 10;
}

int set_uses(){
    loads -= 1;
        set_long("%^RED%^A satisfying, spicy and aromatic blend of Black Cavendish,"+
		" Golden & Red Undrin, mixed with luxury brocken flake. The "+
		"aromatic recipe of Vanilla and Rum make this blend smooth and"+
		" very pleasent.\n"
		"%^ORANGE%^You should pack this in a pipe.\n"
		"%^YELLOW%^There are "+loads+" loads left.");
        write("\n%^RED%^You smell the aromatic odor vanilla and rum infused with the exotic tobacco.");
        say("\n%^BLUE%^You smell the aromatic odor of vanilla and rum infused with the exotic tobacco.",
        environment(this_object()));
	
    if(loads < 1){
	write("%^RED%^Your pouch of Tsarven Tobacco is empty, so you discard it!");
	remove();
	}
	return sp;
}

int query_uses(){ return loads;}

int query_con_check() { return min_con; }
