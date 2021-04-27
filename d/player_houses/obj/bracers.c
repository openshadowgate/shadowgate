#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("moonstone bracers");
    set_id(({"bracers","bracer","moonstone bracer","moonstone bracers","moonshadow bracer","moonshadow bracers","bracers of the moonshadow"}));
    set_short("%^WHITE%^%^BOLD%^Br%^RESET%^%^WHITE%^a%^BOLD%^cers of the Mo%^RESET%^%^WHITE%^o%^BOLD%^nsha%^RESET%^%^WHITE%^d%^BOLD%^ow%^RESET%^");
    set_obvious_short("%^WHITE%^%^BOLD%^mo%^RESET%^%^WHITE%^o%^BOLD%^nsto%^RESET%^%^WHITE%^n%^BOLD%^e br%^RESET%^%^WHITE%^a%^BOLD%^cers");
    set_long("%^CYAN%^These bracers are a striking piece of craftsmanship, and are made entirely of solid "
"moonstone.  The %^WHITE%^%^BOLD%^mi%^RESET%^%^WHITE%^l%^BOLD%^ky-w%^RESET%^%^WHITE%^h%^BOLD%^ite "
"%^RESET%^%^CYAN%^surface has been polished to a flawless shine, and the hinges are so perfectly shaped that "
"when they are clasped beneath the wearer's forearms, the hingeline disappears entirely from view.  Across "
"the surface of the bracers themselves, small etchings form the shapes of various phases of the moon in "
"elven-styled artistry, and lined with %^WHITE%^%^BOLD%^molten silver%^RESET%^%^CYAN%^ to highlight each "
"image.  The bracers are truly stunning to behold.\n%^RESET%^");    
    set_weight(10);
    set_value(1000);
    set_type("bracer");
    set_limbs(({"torso"}));
    set_size(2);
    set_wear((:TO,"wear_fun":));
    set_remove((:TO,"remove_fun":));
}

int wear_fun(){
    if((string)ETO->query_name() != "kiya") {
      tell_object(ETO,"%^CYAN%^The bracers shimmer and disappear as you try to wear them!%^RESET%^");
      tell_room(EETO,"CYAN%^The bracers shimmer and disappear from "+ETO->QCN+"'s hands!%^RESET%^",ETO);
      TO->remove();
      return 0;
    }
    tell_room(EETO,"%^CYAN%^A shimmer of light passes over the %^WHITE%^%^BOLD%^silver-lined%^RESET%^%^CYAN%^"
" etchings on "+ETO->QCN+"'s bracers.%^RESET%^",ETO);
    tell_object(ETO,"%^CYAN%^A shimmer of light passes over the %^WHITE%^%^BOLD%^silver-lined "
"%^RESET%^%^CYAN%^etchings on your bracers.%^RESET%^");
    return 1;
}

int remove_fun(){
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+" gently unclasps the exquisite bracers%^RESET%^.",ETO);
    tell_object(ETO,"%^CYAN%^You gently unclasp the exquisite bracers%^RESET%^.");
    return 1;
}
