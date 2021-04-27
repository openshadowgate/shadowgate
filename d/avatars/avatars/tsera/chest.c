//	chest.c


inherit "/std/bag_logic";
object ob;
void create() {
    object money;

    ::create();
    set_id( ({"chest", "large chest"}) );
    set_name("chest");
    set("short", "A large chest");
    set("long", "A large chest.");
    set_open_long("%^RESET%^This old chest is quite large and somewhat %^BLUE%^regal %^RESET%^looking.  The"
" corners have been reinforced with %^YELLOW%^golden jousts %^RESET%^and the lid has been encrusted with many"
" colorful %^YELLOW%^g%^GREEN%^e%^BLUE%^m%^MAGENTA%^s%^RESET%^ that seem to %^BOLD%^%^WHITE%^sparkle"
" %^RESET%^endlessly.  The lock face is quite intricate, made of a swirling pattern %^YELLOW%^gold filagree"
" %^RESET%^with a tiny keyhole in the center.\nIt is open.");
    set_closed_long("%^RESET%^This old chest is quite large and somewhat %^BLUE%^regal %^RESET%^looking."
"  The corners have been reinforced with %^YELLOW%^golden jousts %^RESET%^and the lid has been encrusted with"
" many colorful %^YELLOW%^g%^GREEN%^e%^BLUE%^m%^MAGENTA%^s%^RESET%^ that seem to %^BOLD%^%^WHITE%^sparkle"
" %^RESET%^endlessly.  The lock face is quite intricate, made of a swirling pattern %^YELLOW%^gold filagree"
" %^RESET%^with a tiny keyhole in the center.\nIt is closed.");
    set_no_clean(1);
    set_weight(25);
    set_value(2);
    set_max_internal_encumbrance(50);
    set_possible_to_close(1);
    ob = new("/std/obj/coins");
    ob->set_money("gold",random(200)+4300);
    ob->move(TO);
    set_lock("locked");
    set_key("chest");
}
