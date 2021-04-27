inherit "/std/food.c";

void create(){
        ::create();
        set_name("%^BOLD%^%^RED%^fr%^RESET%^%^RED%^e%^BOLD%^sh str%^WHITE%^a%^RED%^wb%^RESET%^%^RED%^e%^BOLD%^rries%^RESET%^");
        set_id(({"strawberries","fresh strawberries","strawberry","food","fruit"}));
        set_short("%^RESET%^A handful of %^BOLD%^%^RED%^fr%^RESET%^%^RED%^e%^BOLD%^sh str%^WHITE%^a%^RED%^wb%^RESET%^%^RED%^e%^BOLD%^rr%^WHITE%^i%^RED%^es%^RESET%^");
        set_long("%^RESET%^%^RED%^A handful of small, %^BOLD%^fr%^RESET%^%^RED%^e%^BOLD%^sh %^RESET%^%^RED%^w%^BOLD%^i%^RESET%^%^RED%^ld %^BOLD%^str%^WHITE%^a%^RED%^wb%^RESET%^%^RED%^e%^BOLD%^rr%^WHITE%^i%^RED%^es%^RESET%^%^RED%^ that are perfectly %^BOLD%^r%^WHITE%^i%^RED%^pe%^RESET%^%^RED%^.");
        set_destroy();
        set_poison(0);
        set_strength(10);
        set_my_mess("%^RESET%^%^RED%^The %^BOLD%^str%^WHITE%^a%^RED%^wb%^RESET%^%^RED%^e%^BOLD%^rr%^WHITE%^i%^RED%^es %^RESET%^%^RED%^are both %^BOLD%^juicy %^RESET%^%^RED%^and %^BOLD%^sw%^WHITE%^e%^RED%^et%^RESET%^%^RED%^.");
        set_your_mess("%^RESET%^%^RED%^bites into a %^BOLD%^fr%^RESET%^%^RED%^e%^BOLD%^sh %^RESET%^%^RED%^w%^BOLD%^i%^RESET%^%^RED%^ld %^BOLD%^str%^WHITE%^a%^RED%^wb%^RESET%^%^RED%^e%^BOLD%^rr%^WHITE%^i%^RED%^es%^RESET%^%^RED%^ that are perfectly %^BOLD%^r%^WHITE%^i%^RED%^pe%^RESET%^%^RED%^.");
        set_weight(1);
        set_value(0);
}
