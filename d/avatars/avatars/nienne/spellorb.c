#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/club"; //closest simple option

void set_element(string myelement);
void activate_orb();
void deactivate_orb();
string mysetting, thecolor, theshort;
int activated, cooling;

void create() {
    ::create();
    set_element("fire");
    set_name("orb");
    set_id(({"orb"}));
    set_lore("%^WHITE%^%^BOLD%^The series of creations known as the Spheres of Elemental Wrath were devised by the "
"shamans of the Jin Chao Kingdom, several centuries before their demise.  To their people, the balance of the five "
"elements was a key aspect of their religious and philosophical attitudes, so it was seen as high accomplishment to "
"create such a magical item that captured the essence of each of these.  Yet while fire, water, earth and air were able "
"to be harnessed within the orb, the precious fifth element of spirit seemed to elude even their skills.  It was said "
"that one with enough presence of will could %^YELLOW%^shift %^WHITE%^the orb to embody any one of these four elements at "
"a given time.%^RESET%^\n");
    set_property("lore difficulty",27);
    set_wc(1,2);
    set_large_wc(1,2);
    set_size(3);
    set_cointype("gold");
    set_value(12550);
    set("intbonus",1); //offsetting this with negative thac0 and low discern so it doesn't get outta hand.
    set("wisbonus",1);
    set("chabonus",1);
    set_property("able to cast", 1);
    set_wield((:TO,"wield_fun":));
    set_unwield((:TO,"unwield_fun":));
    set_heart_beat(1);
}

void init() {
   ::init();
   add_action("shift_fun","shift");
   add_action("cast_fun","cast");
   add_action("cast_fun","chant");
   add_action("cast_fun","manifest");
   if(!userp(ETO)) return;
   if(query_size() != ((int)ETO->query_size())) set_size(((int)ETO->query_size()));
}

int wield_fun(){
    int toenchant;
    if((int)ETO->query_level() < 21) {
      tell_room(ETO,"%^BOLD%^You must train further before you can attempt to use a weapon of this calibre.%^RESET%^");
      return 0;
    }
    tell_room(EETO,"%^RESET%^"+thecolor+"The smoky haze of the orb comes to life, roiling angr%^BOLD%^i%^RESET%^"+thecolor+
"ly within its glassy prison.%^RESET%^");
    toenchant = (int)ETO->query_level()/7;
    if(toenchant > 5) toenchant = 5;
    while((int)query_property("enchantment") != toenchant) {
      remove_property("enchantment");
      set_property("enchantment",toenchant);
    }
    ETO->add_attack_bonus(-2);
    ETO->add_damage_bonus(-2);
    return 1;
}

int unwield_fun() {
    remove_property("enchantment");
    ETO->add_attack_bonus(2);
    ETO->add_damage_bonus(2);
    if(activated) {
      activated = 0;
      cooling = 48;
      deactivate_orb();
    }
    tell_room(EETO,"%^RESET%^"+thecolor+"The orb calms again, its inner mists becoming still.%^RESET%^");
    return 1;
}

int cast_fun() {
   if(!objectp(TO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_wielded()) return 0;
   if((int)query_property("enchantment") < 4) return 0;
   if(random(1000) < 150) ETO->set_property("clearcasting",1);
   return 0;
}

int shift_fun(string str) {
    if(!str) return 0;
    if(str != "fire" && str != "water" && str != "air" && str != "earth")
      return notify_fail("The orb won't shift to that element!");
    if(!TO->query_wielded()) return notify_fail("You must wield the orb to impose your will upon it!");
    if(activated) return notify_fail("You can't shift the orb's element while it is active!");
    set_element(str);
    tell_room(EETO,"%^BOLD%^%^WHITE%^A violent storm of colors whirls through the misty depths of the "
"orb, before it finally settles on "+theshort+"%^BOLD%^%^WHITE%^.%^RESET%^");
    return 1;
}

void set_element(string myelement) {
   mysetting = myelement;
   switch(myelement) {
     case "fire":
       theshort = "%^RESET%^%^RED%^r%^MAGENTA%^u%^BOLD%^b%^RESET%^%^RED%^y-r%^BOLD%^e%^RESET%^%^RED%^d";
       thecolor = "%^RED%^";
     break;
     case "water":
       theshort = "%^RESET%^%^BLUE%^co%^BOLD%^b%^CYAN%^a%^RESET%^%^BLUE%^lt-bl%^CYAN%^u%^BLUE%^e";
       thecolor = "%^BLUE%^";
     break;
     case "air":
       theshort = "%^RESET%^%^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en-ye%^YELLOW%^ll%^RESET%^%^ORANGE%^ow";
       thecolor = "%^ORANGE%^";
     break;
     case "earth":
       theshort = "%^RESET%^%^GREEN%^f%^BOLD%^o%^RESET%^%^GREEN%^r%^ORANGE%^e%^GREEN%^st-gr%^BOLD%^e%^YELLOW%^e%^RESET%^%^GREEN%^n";
       thecolor = "%^GREEN%^";
     break;
   }
   set_short("%^RESET%^"+thecolor+"Sph%^BOLD%^e%^RESET%^"+thecolor+"re of El%^BOLD%^e%^RESET%^"+thecolor+"mental Wr%^BOLD%^a%^RESET%^"+thecolor+"th%^RESET%^");
   set_obvious_short("%^RESET%^"+thecolor+"glo%^BOLD%^s%^RESET%^"+thecolor+"sy glass orb%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This orb seems just large enough to fit comfortably in both of your hands, if you so "
"desired.  It appears to be made of %^RESET%^%^CYAN%^g%^BOLD%^l%^RESET%^%^CYAN%^ass%^BOLD%^%^WHITE%^, though surprisingly "
"it is far more resilient to damage than such a material would usually afford.  The glass itself is perfectly smooth, "
"without crack or scratch to mar its gleaming surface, and is tinted a soft shade of "+theshort+"%^BOLD%^%^WHITE%^.  "
"Fairly light in weight, as though hollow inside, a closer inspection reveals that it is filled with some kind of "
"%^RESET%^c%^BOLD%^%^BLACK%^l%^RESET%^ou%^BOLD%^%^BLACK%^d%^RESET%^y %^BOLD%^%^WHITE%^substance that drifts lazily within "
"the confines of its transparent prison.  A pretty trinket, perhaps, or something more?%^RESET%^\n");
}

void heart_beat(){
   if(!objectp(TO)) return;
   if(!userp(ETO)) return;
   if(!TO->query_wielded()) {
     if(activated) deactivate_orb();
     return;
   }
   if(activated) {
     activated--;
     if(!activated) {
       deactivate_orb();
       cooling = 48;
     }
     return;
   }
   if(cooling) {
     cooling--;
     return;
   }
   if((int)query_property("enchantment") < 5) return;
   if(!sizeof(ETO->query_attackers())) return;
   if(random(2500) < 400) {
     activated = 12;
     activate_orb();
   }
}

void activate_orb() {
   string myadj;
   if(!objectp(TO)) return;
   if(!userp(ETO)) return;
   switch(mysetting) {
     case "fire": myadj = "fiery strength of the flames"; break;
     case "water": myadj = "surging strength of the waters"; break;
     case "earth": myadj = "rugged strength of the earth"; break;
     case "air": myadj = "whirling strength of the storm"; break;
   }
   tell_object(ETO,""+thecolor+"The sphere of glass flares with ra%^BOLD%^d%^RESET%^"+thecolor+"iant light, and you feel "
"the "+myadj+" surge through you!%^RESET%^");
   tell_room(EETO,""+thecolor+"The sphere of glass in "+ETO->QCN+"'s hands starts glowing with ra%^BOLD%^d%^RESET%^"
+thecolor+"iant light!%^RESET%^",ETO);
   ETO->set_property("spell penetration",10);
   ETO->set_property("empowered",2);
}

void deactivate_orb() {
   string myadj;
   if(!objectp(TO)) return;
   if(!userp(ETO)) return;
   switch(mysetting) {
     case "fire": myadj = "fiery strength of the flames"; break;
     case "water": myadj = "surging strength of the waters"; break;
     case "earth": myadj = "rugged strength of the earth"; break;
     case "air": myadj = "whirling strength of the storm"; break;
   }
   tell_object(ETO,""+thecolor+"The "+myadj+" fades from you.%^RESET%^");
   tell_room(EETO,""+thecolor+"The orb stops glowing again.%^RESET%^",ETO);
   ETO->set_property("spell penetration",-10);
   ETO->set_property("empowered",-2);
}
