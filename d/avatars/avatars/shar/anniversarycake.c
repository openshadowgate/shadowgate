//anniversarycake.c - For SG's anniversary.  Coded by Circe 10/16/03
inherit "/std/food.c";

void create(){
        ::create();
        set_name("anniversary cake");
        set_id(({"cake","anniversary cake","chocolate cake","slice","food"}));
        set_short("%^BOLD%^%^WHITE%^A delicious %^CYAN%^a%^BLUE%^n%^GREEN%^n%^MAGENTA%^i%^RED%^v%^YELLOW%^e%^CYAN%^r%^BLUE%^s%^GREEN%^a%^MAGENTA%^r%^RED%^y %^MAGENTA%^cake%^RESET%^");
        set_long(
           "%^BOLD%^%^CYAN%^This delicious looking cake is made of "+
           "%^BLACK%^double "+
           "chocolate fudge chunk goodness%^CYAN%^.  The %^BLACK%^"+
           "chocolate icing "+
           "%^CYAN%^is practically dripping with %^BLUE%^s%^GREEN%^p"+
           "%^MAGENTA%^r%^RED%^i%^YELLOW%^n"+
           "%^CYAN%^k%^BLUE%^l%^GREEN%^e%^MAGENTA%^s %^CYAN%^and looks "+
           "heavenly.  A message has been spelled out in the sprinkles "+
           "you could read.%^RESET%^"
        );
        set_read(
@CIRCE
      %^BOLD%^%^CYAN%^Happy 10th Anniversary %^BLACK%^ShadowGate%^CYAN%^!

%^WHITE%^We are glad you are here to celebrate with us!%^RESET%^
CIRCE
        );
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_my_mess("You gobble up the gooey cake in celebration of 10 wonderful years!");
        set_your_mess("smiles happily after eating the gooey cake.");
        set_weight(1);
        set_value(0);
}
