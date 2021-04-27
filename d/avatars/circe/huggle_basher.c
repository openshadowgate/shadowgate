#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"warhammer","hammer","large hammer","large war hammer","huggle basher","basher"}));
   set_name("huggle basher");
   set_short("%^BOLD%^%^CYAN%^H%^BLUE%^u%^GREEN%^g%^YELLOW%^g"+
      "%^RED%^l%^MAGENTA%^e %^BLACK%^B%^GREEN%^a%^CYAN%^s"+
      "%^YELLOW%^h%^RED%^e%^BLUE%^r%^RED%^!!!%^RESET%^");
   set_long("%^YELLOW%^This massive hammer is carved with painted "+
      "images of %^GREEN%^C%^CYAN%^a%^RED%^r%^BLUE%^e%^YELLOW%^ B"+
      "%^WHITE%^e%^BLACK%^a%^RESET%^%^MAGENTA%^r%^BOLD%^s%^YELLOW%^"+
      ", %^WHITE%^My Little Ponies%^YELLOW%^, and all things %^MAGENTA%^"+
      "cute%^YELLOW%^.  It has long, %^GREEN%^s%^RESET%^%^GREEN%^i"+
      "%^CYAN%^l%^BOLD%^k%^BLUE%^e%^MAGENTA%^n ribbons %^YELLOW%^"+
      "that curl around the handle and %^WHITE%^padded %^YELLOW%^"+
      "heads to soften the blow.  Along the handle is a message you "+
      "could read.%^RESET%^");
   set("read","%^BOLD%^%^WHITE%^Wield this, thy %^MAGENTA%^hammer"+
      "%^WHITE%^, in moments of extreme annoyance "+
      "from the silly soul which dares to %^CYAN%^HUGGLE %^WHITE%^you!%^RESET%^");
   set_weight(15);
   set_size(3);
   set_value(10);
   set_wc(4,5);
   set_large_wc(4,6);
   set_type("bludgeoning");
   set_prof_type("hammer");
   set_weapon_speed(8);
   set_property("enchantment",10);
   set_property("no curse",1);
   set_wield((:TO,"extra_wield":));
   set_hit((:TO,"extra_hit":));
}

int extra_wield(){
   if((string)ETO->query_name() == "lurue"){
      tell_object(ETO,"%^BOLD%^%^MAGENTA%^You heft your hammer "+
         "and go out in search of the vicious huggle monsters "+
         "to <%^CYAN%^bash%^MAGENTA%^>!%^RESET%^");
   }
   return 1;
}

void init(){
   ::init();
   add_action("bash","bash");
}

int bash(string str){
   object ob;
   if(!(ob = present(str,environment(TP)))){
      tell_object(ETO,"That is not here!");
   return 1;
   }
   if(!objectp(ob)) return 1;
   if(!objectp(ETO)) return 1;
   if(!present(ob,EETO)){
      tell_object(ETO,"You do not see that here.");
      return 1;
   }
   if(ob == ETO){
      tell_object(ETO,"Why would you want to do that?");
      return 1;
   }
   tell_object(ETO,"%^YELLOW%^With glee, you %^MAGENTA%^BASH%^YELLOW%^ "+
      ""+ob->QCN+" over the head, sending up showers of pretty images, "+
      "Care Bear style.%^RESET%^");
   tell_object(ob,"%^YELLOW%^With a gleeful grin, "+ETOQCN+" bashes you "+
      "over the head with a very colorful hammer!%^RESET%^");
   tell_room(EETO,"%^YELLOW%^A shower of images fills the air as "+
      ""+ETOQCN+" bashes "+ob->QCN+" over the head with a colorful "+
      "hammer!%^RESET%^",({ETO,ob}));
   return 1;
}

int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(4)){
        tell_room(EETO,"%^BOLD%^WHITE%^A horde of pretty %^CYAN%^My Little "+
           "Ponies %^WHITE%^with %^GREEN%^s"+
           "%^CYAN%^y%^BLUE%^m%^MAGENTA%^b%^RESET%^%^MAGENTA%^o"+
           "%^BOLD%^%^RED%^l%^YELLOW%^s %^WHITE%^on their bottoms "+
           "mystically appears and %^MAGENTA%^tramples "+
           "%^WHITE%^"+vic->QCN+"!  %^CYAN%^WHEE!!%^RESET%^",vic);
        tell_object(vic,"%^BOLD%^%^WHITE%^A horde of pretty "+
           "%^CYAN%^My Little Ponies %^WHITE%^with %^GREEN%^s"+
           "%^CYAN%^y%^BLUE%^m%^MAGENTA%^b%^RESET%^%^MAGENTA%^o"+
           "%^BOLD%^%^RED%^l%^YELLOW%^s %^WHITE%^on their bottoms "+
           "suddenly appears and %^MAGENTA%^tramples %^WHITE%^you!%^RESET%^");
        vic->set_tripped(1,"You are recovering from the deathly attack "+
           "of the pretty ponies!  Oh, the humanity!");
        vic->do_damage("torso",random(50)+10);
        return 1;
    }
    if(!random(3)) {
        tell_object(ETO,"%^BOLD%^%^RED%^You yell: %^BOLD%^%^MAGENTA%^Care Bear "+
           "STARE%^RED%^!\n%^YELLOW%^A pure beam of light poors forth from "+
           "your belly, just like Sunshine Bear!%^RESET%^");
        tell_object(vic,"%^BOLD%^%^RED%^"+ETOQCN+" yells: %^BOLD%^%^MAGENTA%^Care Bear "+
           "STARE%^RED%^!\n%^YELLOW%^A pure beam of light poors forth from "+
           ""+ETO->QP+" belly, knocking you down!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" yells: %^BOLD%^%^MAGENTA%^Care Bear "+
           "STARE%^RED%^!\n%^YELLOW%^A pure beam of light poors forth from "+
           ""+ETO->QP+" belly, knocking "+vic->QCN+" down!%^RESET%^", ({ETO,vic}));
        vic->set_tripped(1,"You are still trying to stand from the powerful stare!");
        return 1;
    }
    else return 1;
}
