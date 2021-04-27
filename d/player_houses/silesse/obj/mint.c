inherit "/std/food.c";

void create(){
        ::create();
        set_name("%^BOLD%^%^GREEN%^Fresh m%^RESET%^%^GREEN%^i%^GREEN%^nt%^RESET%^");
        set_id(({"strawberries","fresh mint","mint","food","sprig of mint","herb"}));
        set_short("%^RESET%^%^GREEN%^A %^ORANGE%^sprig %^GREEN%^of %^BOLD%^fresh m%^RESET%^%^GREEN%^i%^BOLD%^nt%^RESET%^");
        set_long("%^RESET%^%^GREEN%^This %^ORANGE%^sprig %^GREEN%^of %^BOLD%^bright gr%^RESET%^%^GREEN%^ee%^BOLD%^n%^RESET%^%^GREEN%^, %^BOLD%^l%^RESET%^%^GREEN%^ea%^BOLD%^fy h%^RESET%^%^GREEN%^e%^BOLD%^rb %^RESET%^%^GREEN%^smells just like %^BOLD%^m%^RESET%^%^GREEN%^i%^BOLD%^nt%^RESET%^%^GREEN%^.%^RESET%^");
        set_destroy();
        set_poison(0);
        set_strength(1);
        set_my_mess("%^RESET%^%^GREEN%^Your mouth %^ORANGE%^tingles %^GREEN%^as you eat the %^CYAN%^cool%^GREEN%^, %^BOLD%^refreshingly sw%^RESET%^%^GREEN%^ee%^BOLD%^t m%^RESET%^%^GREEN%^i%^BOLD%^nt%^RESET%^%^GREEN%^.%^RESET%^");
        set_your_mess("%^RESET%^%^GREEN%^chews on a %^BOLD%^l%^RESET%^%^GREEN%^ea%^BOLD%^fy h%^RESET%^%^GREEN%^e%^BOLD%^rb %^RESET%^%^GREEN%^that smells just like %^BOLD%^m%^RESET%^%^GREEN%^i%^BOLD%^nt%^RESET%^%^GREEN%^.%^RESET%^.");
        set_weight(1);
        set_value(0);
}
