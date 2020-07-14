#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("brick");
    set_id(({"gold brick","brick"}));
    set_short("%^BOLD%^%^YELLOW%^gold brick");
    set_long(
      "%^ORANGE%^A heavy brick of pure gold"
    );
    set_weight(10); //three per sack
    set_value(10000 * (1+ random(3)));
}

int read(string str){
    if(!str || str != "brick") return  0;

    tell_room(environment(TO),TPQCN+" reads the writing on the top of the gold brick!",TP);
    write("\n\n\t\%^BOLD%^%^YELLOW%^99% PURE GOLD BY WEIGHT.  Certified by T.G.D.");
    return 1;
}
