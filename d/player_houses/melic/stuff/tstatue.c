#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"statue","titan","titan statue"}) );
    set_name("titan statue");
    set_short("A large statue of a titan");
    set_weight(1000000);
    set_long("The statue of a titan looks very life-like.  It is over 25 feet tall "+
		"and is clothed in a long flowing toga.  Adorned with fantastic jewelry it "+
		"is made to look as beautiful as possible.  It looks incredibly strong and "+
		"could probably crush you quite easily if it were alive."
    );
    set_value(0);
}