

#include <std.h>
#define SCRY_D "/daemon/ic_scry_locate_d"
inherit OBJECT;
int wield_func;
int unwield_func;




create() {
    ::create();

   set_id(({"mirror","hand mirror","magic mirror","wood mirror","fine mirror"}));
   set_name("%^BOLD%^%^RED%^V%^RESET%^%^RED%^a%^MAGENTA%^n%^BOLD%^i%^RESET%^%^RED%^t%^BOLD%^y%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^An o%^BOLD%^a%^RESET%^%^ORANGE%^k and %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^er %^RESET%^%^ORANGE%^hand %^RESET%^mi%^BOLD%^rr%^RESET%^or");
   set_long("%^RESET%^%^ORANGE%^A %^RESET%^si%^BOLD%^lv%^RESET%^er r%^BOLD%^e%^RESET%^fl%^BOLD%^ec%^RESET%^i%^BOLD%^v%^RESET%^e"
            " %^BOLD%^su%^RESET%^rf%^BOLD%^ace %^RESET%^%^ORANGE%^is set within an %^MAGENTA%^elaborately %^ORANGE%^carved"
            " %^BOLD%^o%^RESET%^%^ORANGE%^a%^BOLD%^k%^RESET%^%^ORANGE%^e"
            "%^BOLD%^n frame%^RESET%^%^ORANGE%^ of twisted vines and %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^%^RED%^roses%^ORANGE%^.  A long,"
            "twisting handle by which to hold this %^RESET%^mi%^BOLD%^rr%^RESET%^or %^ORANGE%^has been %^YELLOW%^polished smooth%^RESET%^%^ORANGE%^,"
            " it's end unfurling to clutch a single fist sized %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^%^ORANGE%^whose worth alone could easily"
            " be a small %^CYAN%^fortune.%^RESET%^");
   set_lore("%^RESET%^%^ORANGE%^Rumors tell of a %^BOLD%^%^RED%^vain %^RESET%^%^ORANGE%^young man in service of the temple of %^BOLD%^%^RED%^Sune"
            " %^RESET%^%^ORANGE%^who thought so much of himself, he created"
            " %^CYAN%^magic %^RESET%^mi%^BOLD%^rr%^RESET%^or %^ORANGE%^by which all could view him, the most handsome of all the lands.  Of course such items"
            " are only in %^CYAN%^myth %^ORANGE%^and %^MAGENTA%^legend%^ORANGE%^...%^RESET%^");
   set_weight(3);
   set_size(1);
   set_value(52000);
   set_cointype("gold"); 
   set_property("repairtype",({"woodwork"})); 
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set("chabonus",2);

}



int wield_func(){
      tell_object(ETO,"%^RESET%^%^ORANGE%^The %^RESET%^si%^BOLD%^lv%^RESET%^er r%^BOLD%^e%^RESET%^fl%^BOLD%^ec%^RESET%^t%^BOLD%^i%^RESET%^ve su%^BOLD%^rf%^RESET%^ace %^ORANGE%^of the %^RESET%^hand mirror %^ORANGE%^begins to %^CYAN%^gl%^BOLD%^o%^RESET%^%^CYAN%^w softly%^ORANGE%^.");
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The %^RESET%^si%^BOLD%^lv%^RESET%^ered surface %^ORANGE%^of  "+ETO->query_cap_name()+"'s
%^RESET%^hand mirror %^ORANGE%^begins to %^CYAN%^gl%^BOLD%^o%^RESET%^%^CYAN%^w softly %^ORANGE%^as "+ETO->query_subjective()+" takes hold of it.%^RESET%^",ETO);
      TO->set_property("able to cast");
   return 1;
}


int unwield_func(){
   return 1;
}
