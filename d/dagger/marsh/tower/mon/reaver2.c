//Added scrap paper drop Octothorpe 5/25/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"

inherit "/d/dagger/marsh/tower/mon/reaverB.c";

void create(){
    ::create();
    set_gender("male");
    new( OPATH "gem2.c" )->move(TO);
    if(!random(3)){
        new("/d/dagger/marsh/tower/obj/scrap2.c")->move(TO);
    }
}
