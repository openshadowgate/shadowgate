#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("breathweapon");
   set_short("%^BOLD%^%^CYAN%^mine breathweapons! leet%^RESET%^");
   set_id(({"breath","breathweapon","dagronz","breathweapons","breath weapon"}));
   set_long("This is magical device only for blue dagronz. None for others.\n");
   set_weight(0);
   set_value(0);
   set_ac(0);
   set_size(2);
   set_type("ring");
   set_limbs(({"neck"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int is_detectable() { return !query_worn(); }

void init() {
   ::init();
   add_action("thunder_fun","breathe");
}

int wear_fun() {
   if(!avatarp(ETO)) return 0;
   tell_object(ETO,"%^BLUE%^Leet blue dagronz breathweapon, kgo! Types %^RESET%^breathe %^BLUE%^to use.%^RESET%^");
   TO->set_hidden(1);
   return 1;
}

int remove_fun() {
   if((int)TO->query_hidden()) TO->set_hidden(0);
   return 1;
}

int thunder_fun(string str) {
   object *pplz;
   int i;
   if(!userp(ETO)) return 0;
   if(!avatarp(ETO)) return 0;
   pplz = all_living(EETO);
   if(ETO->query_bound() || ETO->query_unconscious()) {
     ETO->send_paralyzed_message("info",ETO);
     return 1;
   }
   if(!query_worn()) {
     write("Wearing the mad dagronz breathweapon might help.\n");
     return 1;
   } 
   if (str) {
     tell_object(ETO,"Just %^BLUE%^breathe%^RESET%^.");
     return 0;
   }
   tell_object(ETO,"%^YELLOW%^Energy begins to gather in your %^BLUE%^maw%^YELLOW%^ as you let loose a stream of pure "
"%^CYAN%^energy%^YELLOW%^!%^RESET%^\n");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The light in the room seems to draw towards the %^BLUE%^dragon's%^WHITE%^ mouth "
"and he lets loose a stream of pure %^CYAN%^energy%^WHITE%^!%^RESET%^\n",ETO);
   for(i=0;i<sizeof(pplz);i++) {
     if(pplz[i] != ETO && !pplz[i]->query_true_invis() && objectp(pplz[i])) {
       tell_object(pplz[i],"%^BOLD%^%^CYAN%^Pure plasma courses through your body %^RED%^wreaking terrible %^CYAN%^"
"harm!%^RESET%^\n");
       pplz[i]->do_damage("torso",roll_dice(15,8));
     }
   }
   return 1;
}
