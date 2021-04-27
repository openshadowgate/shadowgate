//armor template

#include <std.h>

#define MAGIC_EFFECT_D "/daemon/magic_effect"


inherit ARMOUR;

int whichWear;
int whichRemove;
int whichStruck;
int uses;

void create(){
     ::create();
     set_name("helmet");
     set_id(({ "helm", "helmet" }));
     set_short("%^BOLD%^%^BLACK%^visored %^RESET%^%^GREEN%^jade helmet%^RESET%^");
     set_long(
@PLAYER
"%^RESET%^%^GREEN%^This helm is made of steel that has been tinted to a shade of jade. The helmet is small and sleek in design, with raised openings for elven ears to rest comfortably on the outside. The face of the helmet is open, except for a small enchanted %^BOLD%^%^BLACK%^dark glass %^RESET%^%^GREEN%^that covers from the top of the helmet down to just above the mouth of the wearer.%^RESET%^\n\nHigh quality"
PLAYER
    );
    set_weight(6);
    set_value(42);
    set_ac(2);
    set_size(2);
    set_type("armor");
    set_limbs(({ "head" }));
    set_property("enchantment",1);
    set_property("creator","tengri");
    set_property("quality",143);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"struck_func":));
    uses = random(10)+5;
}
void init(){
    ::init();
    add_action("use","use");
}

int wear_func(){
     return MAGIC_EFFECT_D->magic_wear(whichWear, TP);        
}

int remove_func(){
     return MAGIC_EFFECT_D->magic_remove(whichRemove, TP);        
}

int struck_func(int dam, object what, object who){
     return MAGIC_EFFECT_D->magic_struck(whichStruck, ETO, dam, what, who);        
}
int use(string str){
   if(!TO->query_worn()){
      return 0;
   }
   if(!str) notify_fail("What are you trying to do.  You mean use the helm?");
   if(str == "helm"||str=="the helm"||str=="visor"){             
      tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" concentrates hard and "+ETO->query_possessive()+" begins to glow!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^You close your eyes and your helm begins to glow as you will it to aid you!%^RESET%^");
      new("/cmds/priest/_dispel_magic.c")->use_spell(ETO,environment(ETP),50,100);
      uses--;
      return 1;
   }
}


set_whichWear(int i){
     whichWear=i;
}

set_whichRemove(int i){
     whichRemove=i;
}

set_whichStruck(int i){
    whichStruck=i;
}
