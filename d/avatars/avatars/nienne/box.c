#include <std.h>
inherit "/std/bag_logic";

void create() {
    ::create();
    set_id( ({"box","cubical box","little box","little cubical box",}) );
    set_name("%^RESET%^%^ORANGE%^box%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^A little cubical box%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is a half-foot wide cubical wooden box.  The lid has been carefully clasped shut.%^RESET%^");
    set_open_long("%^RESET%^%^ORANGE%^This is a half-foot wide cubical wooden box.  The lid has been opened to display the inner contents.%^RESET%^");
    set_closed_long("%^RESET%^%^ORANGE%^This is a half-foot wide cubical wooden box.  The lid has been carefully clasped shut.%^RESET%^");
    set_no_clean(1);
    set_weight(1);
    set_value(10);
    set_max_internal_encumbrance(8);
    set_possible_to_close(1);
    set_closed(1);
}
