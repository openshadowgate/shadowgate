#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/club"; //closest simple option

int activated, cooling;
void set_element(string myelement);
void activate_skull();
void deactivate_skull();

void create() {
    ::create();
    set_name("skull");
    set_id(({"Variathris' Demented Cogitation","variathris","skull","cogitation","jawless skull"}));
    set_short("%^RESET%^%^MAGENTA%^Var%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^athris' Demen%^BOLD%^%^BLACK%^te%^RESET%^%^MAGENTA%^d Cogit%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^tion%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^a j%^RESET%^a%^BOLD%^%^WHITE%^wl%^RESET%^es%^BOLD%^%^WHITE%^s sk%^RESET%^ul%^BOLD%^%^WHITE%^l%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This %^RESET%^skull %^BOLD%^%^WHITE%^appears to be that of a grown man or woman, judging by its size. It has been polished %^RESET%^%^CYAN%^smooth"
"%^BOLD%^%^WHITE%^, though whether caused by manual effort or simply by age and decay isn't clear. The %^RESET%^%^RED%^jawbone %^BOLD%^%^WHITE%^has been removed or otherwise lost, "
"for the skull consists of the upper portion only. All of its top row of teeth seem to still be stuck in their sockets, and a %^RESET%^%^MAGENTA%^dull glow %^BOLD%^%^WHITE%^emanates "
"from within the skull itself, shedding a faint and %^RESET%^%^GREEN%^ma%^BOLD%^%^GREEN%^l%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^gn%^BOLD%^%^BLACK%^an%^RESET%^%^GREEN%^t "
"%^BOLD%^%^WHITE%^light from its empty eye sockets. Upon the brow, a single sigil has been carved of an eight-pointed %^RESET%^%^MAGENTA%^star%^BOLD%^%^WHITE%^, with tendrils snaking "
"out between the points.\n%^RESET%^");
    set_lore("%^WHITE%^%^BOLD%^Variathris was a well-known servant of the Dark Sun during the late 500's SG. He was known by many names (usually when not in his hearing); the Scourge of "
"the South, the Mad Magus, the Twisted Tormentor of Tharis, and others. Ever unpredictable, he was said to take great delight in the murder of a strange assortment of targets, whether they be "
"of light or dark. Tharisian elves and humans alike watched the shadows in fear for his step, concealed as he would usually be in illusion craft. Too many different tales tell of how he may "
"have died, a variety of great names of the era wanting to claim credit for his eventual demise. It is said that Cyric's hand still weighed upon him at the last, though, cursing him to continue "
"his existence when he would otherwise have been finally released from the Reaver's maddening touch. Still others claim that so mad was he in life, that he inflicted such a curse upon himself, "
"that he might have eternal life. Or unlife, at least.%^RESET%^\n");
    set("no curse",1);
    set_property("lore difficulty",35);
    set_property("able to cast",1);
    set_property("enchantment",5);
    set_item_bonus("attack bonus",-5);
    set_item_bonus("damage bonus",-5);
    set_item_bonus("wisdom",2);
    set_property("repairtype",({ "jewel" }));
    set_cointype("gold");
    set_value(11550);
    set_wield((:TO,"wield_fun":));
    set_unwield((:TO,"unwield_fun":));
    set_heart_beat(1);
   set_property("no offer",1);
}

void init() {
   ::init();
   add_action("cast_fun","cast");
   add_action("cast_fun","chant");
   add_action("cast_fun","manifest");
   add_action("skull_chat","voice");
   if(!userp(ETO)) return;
   if(query_size() != (int)ETO->query_size()) set_size((int)ETO->query_size());
}

int wield_fun(){
    int toenchant;
    if(!avatarp(ETO) && (string)ETO->query_name() != "sierra") {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You take up the skull, and as you look down upon it, its eye sockets blaze with an %^BOLD%^%^BLACK%^u%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^h"
"%^BOLD%^%^GREEN%^o%^RESET%^l%^BOLD%^%^BLACK%^y %^BOLD%^%^WHITE%^light that seems to sear right through your eyes and into your soul.  The world fades in a storm of maddening "
"%^BOLD%^%^RED%^screams %^BOLD%^%^WHITE%^and %^RESET%^%^MAGENTA%^laughter %^BOLD%^%^WHITE%^that echo throughout your mind.  When your senses return, the skull is lying harmlessly on the "
"ground before you, and your whole body is trembling.  A sinuous voice whispers from seemingly nowhere, %^RESET%^%^MAGENTA%^'%^RESET%^Now let's not do that again, hmm?%^MAGENTA%^'%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+"%^BOLD%^%^WHITE%^ attempts to take up the skull, and its eye sockets blaze with an %^BOLD%^%^BLACK%^u%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^h"
"%^BOLD%^%^GREEN%^o%^RESET%^l%^BOLD%^%^BLACK%^y %^BOLD%^%^WHITE%^light!  "+ETO->QS+" drops it and falls to "+ETO->QP+" knees, "+ETO->QP+" entire body trembling and "+ETO->QP+" eyes filled with "
"horror.  Moments pass before "+ETO->QS+" finally manages to pull "+ETO->QO+"self together and look around.%^RESET%^",ETO);
      TO->set_property("magic",1);
      ETO->do_damage("torso",roll_dice(20,10));
      TO->set_property("magic",-1);
      ETO->force_me("drop variathris");
      return 0;
    }
    tell_room(EETO,"%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^dull glow %^BOLD%^%^BLACK%^emanates from the eye sockets of the %^RESET%^skull%^BOLD%^%^BLACK%^.%^RESET%^");
    tell_object(ETO,"%^MAGENTA%^You realise you could compel the skull to speak with %^RESET%^<voice>%^MAGENTA%^.%^RESET%^");
    TO->set_overallStatus(100);
    return 1;
}

int unwield_fun() {
    tell_room(EETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^glow %^BOLD%^%^BLACK%^fades, leaving the skull to appear nothing more than %^RESET%^lifeless bone%^BOLD%^%^BLACK%^.%^RESET%^");
    return 1;
}

int cast_fun() { // 15% chance while casting any given spell to not use the spell slot.
   if(!objectp(TO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_wielded()) return 0;
   if((int)query_property("enchantment") < 4) return 0;
   if(random(1000) < 150) {
     ETO->set_property("clearcasting",1);
     tell_object(ETO,"%^BOLD%^%^BLACK%^The skull's eyes %^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^, like a heartbeat that throbs through your entire body. For just a second, %^RESET%^%^CYAN%^stark clarity %^BOLD%^%^BLACK%^pierces the m%^RESET%^%^GREEN%^a%^RED%^d%^BOLD%^%^BLACK%^d%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^n%^BOLD%^%^RED%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g whispers that haunt you.%^RESET%^");
   }
   return 0;
}

void heart_beat(){ // 15% chance during combat to empower the user for 12sec.
   if(!objectp(TO)) return;
   if(!userp(ETO)) return;
   if(activated) {
     if(!TO->query_wielded()) {
       deactivate_skull();
       activated = 0;
       return;
     }
     activated--;
     if(!activated) {
       deactivate_skull();
       cooling = 48;
     }
     return;
   }
   if(cooling) {
     cooling--;
     return;
   }
   if(!sizeof(ETO->query_attackers())) return;
   if(!TO->query_wielded()) return;
   if(random(2500) < 400) {
     activated = 12;
     activate_skull();
   }
}

void activate_skull() {
   if(!objectp(TO)) return;
   if(!userp(ETO)) return;
   tell_object(ETO,"%^BOLD%^%^BLACK%^The eyes of the skull %^BOLD%^%^WHITE%^b%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^z%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ with malignant light, and you feel a sudden rush of %^RESET%^%^RED%^po%^BOLD%^%^RED%^we%^RESET%^%^RED%^r %^BOLD%^%^BLACK%^surge through you!%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The eyes of the skull in "+ETO->QCN+"'s hand %^BOLD%^%^WHITE%^b%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^z%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^ with malignant light!%^RESET%^",ETO);
   ETO->set_property("spell penetration",20);
   ETO->set_property("empowered",2);
   TO->set_obvious_short("%^BOLD%^%^WHITE%^a j%^RESET%^a%^BOLD%^%^WHITE%^wl%^RESET%^es%^BOLD%^%^WHITE%^s sk%^RESET%^ul%^BOLD%^%^WHITE%^l%^RESET%^ %^BOLD%^%^MAGENTA%^(eye sockets glowing)%^RESET%^");
   TO->set_short("%^RESET%^%^MAGENTA%^Var%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^athris' Demen%^BOLD%^%^BLACK%^te%^RESET%^%^MAGENTA%^d Cogit%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^tion%^RESET%^ %^BOLD%^%^MAGENTA%^(eye sockets glowing)%^RESET%^");
}

void deactivate_skull() {
   string myadj;
   if(!objectp(TO)) return;
   if(!userp(ETO)) return;
   tell_room(EETO,"%^BOLD%^%^BLACK%^The skull's eyes return to a %^RESET%^%^MAGENTA%^dull glow%^BOLD%^%^BLACK%^.%^RESET%^");
   ETO->set_property("spell penetration",-20);
   ETO->set_property("empowered",-2);
   TO->set_obvious_short("%^BOLD%^%^WHITE%^a j%^RESET%^a%^BOLD%^%^WHITE%^wl%^RESET%^es%^BOLD%^%^WHITE%^s sk%^RESET%^ul%^BOLD%^%^WHITE%^l%^RESET%^");
   TO->set_short("%^RESET%^%^MAGENTA%^Var%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^athris' Demen%^BOLD%^%^BLACK%^te%^RESET%^%^MAGENTA%^d Cogit%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^tion%^RESET%^");
}

int skull_chat(string str) {
   string *say1 = ({"shrieks","howls","whispers","hisses","voices","snarls","chatters","cackles","reveals","utters","screeches","murmurs","mumbles","mutters","sighs","articulates", "babbles","grumbles","asserts","conveys"});
   string *say2 = ({"softly","fiercely","eerily","low","quickly","shrilly","darkly","wickedly","in an odd tone","in quick syllables","with precision","with force","with emphasis","bleakly","sharply","with fervor","in an undertone","blithely","briskly","zealously","with indifference"});
   string mysay;
   if(!TO->query_wielded()) return 0;
   if(!str) {
     switch(random(400)) {
       case 0..99: tell_room(EETO,"%^BOLD%^%^BLACK%^The skull snarls and mutters to itself.%^RESET%^"); break;
       case 100..199: tell_room(EETO,"%^BOLD%^%^BLACK%^A low %^RESET%^%^CYAN%^hiss %^BOLD%^%^BLACK%^emanates from the skull.%^RESET%^"); break;
       case 200..299: tell_room(EETO,"%^BOLD%^%^BLACK%^An %^RESET%^%^MAGENTA%^eerie light %^BOLD%^%^BLACK%^gleams briefly from the skull's eye sockets.%^RESET%^"); break;
       default: tell_room(EETO,"%^BOLD%^%^BLACK%^The skull grumbles softly.%^RESET%^"); break;
     }
     return 1;
   }
   if(!random(3)) mysay = say1[random(sizeof(say1))];
   else mysay = say1[random(sizeof(say1))] + " " + say2[random(sizeof(say2))];
   tell_room(EETO,"%^BOLD%^%^BLACK%^The skull "+mysay+":%^RESET%^%^MAGENTA%^ '%^RESET%^"+str+"%^RESET%^%^MAGENTA%^'%^RESET%^");
   return 1;
}
