#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create(); 

    set_long(""+ ::query_long() + "\n%^RED%^Ahead of you to the north lies a massive "
        "tower-shaped billowing black column of mist. There appears to be no way into "
        "the swirling mass, but perhaps closer up you may find entrance into this mystical "
        "and evil place that must be the tower known only as Demongate.%^RESET%^");

    set_listen("default","Your mind screams in panic and you fight the urge to flee!");
    set_smell("default","Blood, evil, death, decay, insanity - it's all here and waits for you to join.");

    add_item("tower","%^RED%^Ahead of you to the north lies a massive tower-shaped billowing "
        "black column of mist. There appears to be no way into the swirling mass, but perhaps "
        "closer up you may find entrance into this mystical and evil place that must be the "
        "tower known only as Demongate.%^RESET%^");

    set_exits((["southwest": RPATH "f25",
	            "north": RPATH "f29",
      ]));
}
