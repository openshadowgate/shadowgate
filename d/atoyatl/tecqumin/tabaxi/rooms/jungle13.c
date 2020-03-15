#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit J_ROOM;


void create() {
  ::create();
  set_exits( ([ 
                "northeast" : TABAXROOM + "jungle12",
                     "west" : TABAXROOM + "jungle14"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}
