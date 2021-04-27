#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",1);
    set_property("light",0);
    set_name("A little shack");
    set_short("%^RESET%^%^ORANGE%^A little shack%^RESET%^");
    set_long("%^RESET%^This shack seems much more roomy inside than out, and is closely sealed without %^CYAN%^"
"windows%^RESET%^, allowing very little light to filter in.  The room is %^YELLOW%^illuminated %^RESET%^by a "
"single lantern near the back, which reveals a few minor details of the room itself.  A small open %^RED%^fire"
"-pit %^RESET%^is off to one side, set across the top with a stand to hold a kettle or cauldron for cooking.  "
"A desk and chair are against the opposite wall, set with a tidy stack of %^BOLD%^%^WHITE%^papers%^RESET%^, an "
"inkwell, and several fresh-cut quills.  A large chest rests at the foot of the only other piece of furniture "
"in the room, a low-set %^BLUE%^bed %^RESET%^only large enough for a single small person.\n");
    set_smell("default","It smells dry and musty in here, as though not much fresh air gets in.");
    set_listen("default","It is very quiet here.");
}