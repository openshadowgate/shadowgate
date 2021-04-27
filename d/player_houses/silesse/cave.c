
#include <std.h>
inherit ROOM;

void create()
{
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_name("An immense cavern");
    set_short("An immense cavern");
    set_long("%^RESET%^%^ORANGE%^The sheer size of this cavern is a wonder to behold.  Easily three hundred feet wide and equally as long, it appears to have been naturally formed and is nearly completely %^BLUE%^dark%^ORANGE%^.  What little %^RESET%^light%^ORANGE%^"
             " that filters in, does so through a %^GREEN%^thick curtain %^ORANGE%^of %^GREEN%^vines %^ORANGE%^to the south.  To the west,"
             " the cavern turns slightly and the floor begins a descent towards a %^BLUE%^tunnel %^ORANGE%^marked by the unmistakable %^MAGENTA%^gl%^BOLD%^o%^RESET%^%^MAGENTA%^w %^ORANGE%^of %^MAGENTA%^f%^BOLD%^a%^WHITE%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^ie"
             " f%^BOLD%^i%^RESET%^%^MAGENTA%^re%^ORANGE%^.  All along"
             " the walls of this immense cavern are rows of neatly stacked crates and towering piles of baskets filled with freshly %^GREEN%^harvested food%^ORANGE%^. Each rows position is marked only by a small patch of"
             " %^BOLD%^%^GREEN%^iridescent lichen%^RESET%^%^ORANGE%^.\n");
    set_smell("default", "%^RESET%^%^CYAN%^The cool air of this %^ORANGE%^cavern %^CYAN%^carries the faint scent of %^RESET%^salty ocean %^CYAN%^mingled with %^MAGENTA%^exotic perfumes%^CYAN%^, %^BOLD%^%^BLUE%^%^fine foods%^RESET%^%^CYAN%^, and %^ORANGE%^quality leathers.");
    set_listen("default", "%^BOLD%^%^BLUE%^You can hear the soft roar of waves crashing in the distance.");
    set_items(([
                   "crates" : "%^RESET%^%^ORANGE%^Looking up the rows upon rows of neatly stacked crates, you come to realize that there is probably enough here"
                   " to feed a small army",
                   "vines" : "%^RESET%^%^GREEN%^Easily spotted from any place within the %^BLUE%^dark cavern%^GREEN%^, these vines are almost illuminated"
                   " by the very %^RESET%^faint glow %^GREEN%^of %^RESET%^light %^GREEN%^that filters through, though they appear too thick to part.",
                   "lichen" : "%^BOLD%^%^GREEN%^Not really casting any light, these tiny patches of glowing subterranian moss look more to mark the position"
                   " of the crates.",
                   "baskets" : "%^RESET%^%^GREEN%^Baskets filled with freshly harvested fruits and vegetables are stacked into high piles along the walls.  Wherever the bounty came from, must have been nearby.",
               ]));
    set_exits(([
                   "west" : "/d/player_houses/aunuit/tunnel200.c",
               ]));
}

void reset()
{
    ::reset();
    if ((string)TO->query_exit("beach") == "/d/shadow/virtual/sea/rilynath.dock.c") {
        tell_room(TO, "%^RESET%^%^GREEN%^The vines fall back into place, concealing the exit to the beach%^RESET%^%^GREEN%^");
        remove_exit("beach");
    }
}

void init()
{
    ::init();
    add_action("part", "part");
}

int part(string str)
{
    if (!objectp(TP)) {
        return 1;
    }
    tell_object(TP, "%^RESET%^%^ORANGE%^Spreading your arms wide, you command the %^GREEN%^vines %^ORANGE%^covering the"
                " %^BOLD%^%^BLACK%^exit %^RESET%^%^ORANGE%^to part.");
    TP->force_me("say Amin naia lle a' kirma!");
    tell_object(TP, "%^RESET%^%^GREEN%^In response to the power of your command, the vines pull back on either side,"
                " revealing the exit to the beach!");
    tell_room(TO, "%^RESET%^%^GREEN%^In response to the power of " + TPQCN + "'s command, the vines pull back to either side, revealing an exit to the beach!", TP);
    add_exit("d/shadow/virtual/sea/rilynath.dock", "beach");
    call_out("set_vine_closed", 10);
    return 1;
}

void set_vine_closed()
{
    tell_room(TO, "%^RESET%^%^GREEN%^The vines fall back into place%^RESET%^%^GREEN%^");
    TO->remove_exit("beach");
    return;
}
