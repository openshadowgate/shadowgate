#include <std.h>
inherit "/std/bag_logic";

void create() {

    ::create();
    set_id( ({"chest", "lkchest","crate","wooden crate",}) );
    set_name("%^RESET%^%^ORANGE%^crate%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^A large shipping crate%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is a four foot cubical wooden crate.  The lid has been pryed off and the contents are visible.%^RESET%^");
    set_open_long("%^RESET%^%^ORANGE%^This is a four foot cubical wooden crate.  The lid has been pryed off and the contents are visible.%^RESET%^");
    set_closed_long("%^RESET%^%^ORANGE%^This is a 4 foot cubical crate used to ship goods.  The lid has been
securely nailed down as to prevent any tampering or such.%^RESET%^");
    set_no_clean(1);
    set_weight(25);
    set_value(10);
    set_max_internal_encumbrance(100);
    set_possible_to_close(1);
}
