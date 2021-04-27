#include <std.h>
#define SAVE_D "/daemon/save_d"
inherit "/d/player_houses/valas/mon/bgolem";

void create(){
        ::create();
        set_speed(60);
        set_moving(1);
        set_nogo(({"/d/player_houses/valas/mon/tower1","/d/player_houses/valas/mon/entrance"}));
}