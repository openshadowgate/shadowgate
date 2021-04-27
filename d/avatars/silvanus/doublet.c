//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("doublet");
    set_id(({"armor","doublet","doublet","%^BOLD%^%^CYAN%^Sapphire wedding doublet%^RESET%^",}));
    set_short("%^BOLD%^%^CYAN%^Sapphire wedding doublet%^RESET%^");
    set_long(
@ARMOR
%^BOLD%^%^CYAN%^This rich %^MAGENTA%^deep%^CYAN%^ %^BLUE%^sapphire %^BLUE%^v%^MAGENTA%^e%^BLUE%^l%^MAGENTA%^v%^BLUE%^e%^MAGENTA%^t%^CYAN%^ doublet is the true marking of a %^YELLOW%^gentleman%^CYAN%^. The doublet accentuates the wearers' %^RED%^broad%^CYAN%^ chest and %^RED%^muscular%^CYAN%^ shoulders giving him an added %^BLUE%^masculine%^CYAN%^ feel. Wide %^YELLOW%^sleeves%^CYAN%^ drape down to the mid arm, and the lush %^BLUE%^v%^MAGENTA%^e%^BLUE%^l%^MAGENTA%^v%^BLUE%^e%^MAGENTA%^t%^CYAN%^ is %^WHITE%^e%^BLUE%^m%^WHITE%^b%^BLUE%^r%^WHITE%^o%^BLUE%^i%^WHITE%^d%^BLUE%^e%^WHITE%^r%^BLUE%^e%^WHITE%^d%^CYAN%^ with %^WHITE%^silver %^YELLOW%^stars%^CYAN%^ that %^YELLOW%^glisten%^CYAN%^ as he walks%^RESET%^.
ARMOR
        );
    set_weight(4);
    set_size(2);
    set_type("clothing");
    set_limbs(({"torso",}));
    set_ac(0);
    set_property("enchantment",0);
    set_value(300);
}