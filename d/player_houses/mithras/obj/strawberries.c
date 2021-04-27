inherit "/std/food.c";

void create(){
   ::create();
   set_name("strawberries");
   set_id(({"strawberries","food"}));
   set_short("%^RESET%^%^RED%^a handful of wild st%^BOLD%^r%^RESET%^%^RED%^awber%^MAGENTA%^ri%^RED%^es%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^A bunch of ripe %^RESET%^%^RED%^st%^BOLD%^r%^RESET%^%^RED%^awber%^MAGENTA%^ri%^RED%^es%^BOLD%^%^WHITE%^, dotted with tiny %^BOLD%^%^BLACK%^seeds%^BOLD%^%^WHITE%^.  Broad %^RESET%^%^GREEN%^l%^BOLD%^ea%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^s %^BOLD%^%^WHITE%^plaster the top of each, some still clinging to faded %^RESET%^petals %^BOLD%^%^WHITE%^that are easily brushed away.%^RESET%^");
   set_my_mess("%^RESET%^%^RED%^The strawberries are plump and %^ORANGE%^juicy%^RED%^, their sweetness laced with a slightly %^CYAN%^tart %^RED%^bite.%^RESET%^");
   set_your_mess("%^RESET%^eats a handful of plump, juicy %^RED%^st%^BOLD%^r%^RESET%^%^RED%^awber%^MAGENTA%^ri%^RED%^es%^RESET%^.");
   set_destroy();
   set_poison(0);
   set_strength(10);
   set_weight(1);
   set_value(0);
}