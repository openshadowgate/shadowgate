
//armor template

#include <std.h>
#define MAGIC_EFFECT_D "/daemon/magic_effect"

inherit WEAPON;

int whichWield;
int whichUnwield;
int whichHit;

void create(){
     ::create();
     set_name("Dragon Tongue");
     set_id(({ "sword", "Dragon Tongue" }));
     set_short("A adamantium short sword");
     set_long(
@PLAYER
"%^RESET%^%^CYAN%^Wro%^BOLD%^ugh%^RESET%^%^CYAN%^t out of the t%^BOLD%^al%^RESET%^%^CYAN%^on of a %^BOLD%^%^BLACK%^d%^BLUE%^r%^BLACK%^a%^BLUE%^g%^BLACK%^o%^BLUE%^n%^RESET%^%^CYAN%^, this short s%^BOLD%^wor%^RESET%^%^CYAN%^d is a sample of true e%^BOLD%^xc%^RESET%^%^CYAN%^ell%^BOLD%^enc%^RESET%^%^CYAN%^e. Its bl%^BOLD%^ad%^RESET%^%^CYAN%^e is carefully curved in re%^BOLD%^sem%^RESET%^%^CYAN%^ble%^BOLD%^nc%^RESET%^%^CYAN%^e of its %^BOLD%^%^BLACK%^d%^BLUE%^r%^BLACK%^a%^BLUE%^g%^BLACK%^o%^BLUE%^n%^RESET%^%^CYAN%^ claw form, enhanced with a razor sharp e%^BOLD%^dg%^RESET%^%^CYAN%^e running all the way to the bent po%^BOLD%^in%^RESET%^%^CYAN%^t. Sashes of %^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^and %^MAGENTA%^purple %^ORANGE%^leather %^CYAN%^are wound around the deli%^BOLD%^cat%^RESET%^%^CYAN%^e handle, which is cle%^BOLD%^arl%^RESET%^%^CYAN%^y made to fit a sle%^BOLD%^nde%^RESET%^%^CYAN%^r hand. The colors are well mat%^BOLD%^che%^RESET%^%^CYAN%^d to the %^BOLD%^bl%^BLUE%^uis%^CYAN%^h %^RESET%^%^CYAN%^tint of the semi %^RESET%^tr%^BOLD%^ans%^CYAN%^lu%^WHITE%^ce%^RESET%^nt %^RESET%^%^CYAN%^blade, giving it an  %^BOLD%^a%^YELLOW%^u%^CYAN%^r%^YELLOW%^a %^RESET%^%^CYAN%^of stylish simpl%^BOLD%^ici%^RESET%^%^CYAN%^ty. Encased within the ta%^BOLD%^lo%^RESET%^%^CYAN%^n in breatht%^BOLD%^aki%^RESET%^%^CYAN%^ng detail is a likeness of a %^BOLD%^%^GREEN%^s%^MAGENTA%^p%^GREEN%^a%^MAGENTA%^r%^GREEN%^r%^MAGENTA%^o%^GREEN%^w %^RESET%^%^CYAN%^in full flight. A %^BOLD%^%^YELLOW%^golden %^RESET%^%^CYAN%^dice has been for%^BOLD%^ge%^RESET%^%^CYAN%^d onto e%^BOLD%^ith%^RESET%^%^CYAN%^er end of the swir%^BOLD%^lin%^RESET%^%^CYAN%^g %^BOLD%^%^WHITE%^p%^YELLOW%^l%^WHITE%^a%^YELLOW%^t%^WHITE%^i%^YELLOW%^n%^WHITE%^u%^YELLOW%^m %^RESET%^%^CYAN%^cross piece as a tribute to %^BOLD%^%^MAGENTA%^Tymora%^RESET%^%^CYAN%^.%^RESET%^\n\nExcellent quality"
PLAYER
    );
    set_weight(2);
    set_value(15);
    set_size(1);
    set_type("slashing");
    set_prof_type("short blades");
    set_property("creator","drille");
    set_property("quality",215);
    set_wc(2,6);
    set_large_wc(2,8);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    
}

int wield_func(){
     return MAGIC_EFFECT_D->magic_wield(whichWield, TP);        
}

int unwield_func(){
     return MAGIC_EFFECT_D->magic_unwield(whichUnwield, TP);        
}

int hit_func(object target){
     return MAGIC_EFFECT_D->magic_hit(whichHit, ETO, target);        
}



set_whichWield(int i){
     whichWield = i;
}

set_whichUnwield(int i){
     whichUnwield = i;
}

set_whichHit(int i){
     whichHit =i;
}

