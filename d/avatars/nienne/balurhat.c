#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create() {
   ::create();
   set_name("top hat");
   set_id(({"hat","top hat","tophat","macabre top hat","macabre hat","brim","brilliant brim"}));
   set_short("%^BOLD%^%^BLACK%^Balur Black's Br%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ll%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ant Br%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^m%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A M%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^c%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^bre Top Hat%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This top hat is a thing of remarkable craft and yet macabre taste. It is sewn of the finest black velvet "
"with a %^BOLD%^%^WHITE%^bright %^BOLD%^%^BLACK%^band of %^BOLD%^%^WHITE%^white leather %^BOLD%^%^BLACK%^around its base. Sewn along the "
"band are various %^BOLD%^%^RED%^child-like dolls%^BOLD%^%^BLACK%^ depicted in detailed %^RESET%^%^RED%^torment%^BOLD%^%^BLACK%^, their "
"tiny faces twisted grotesquely as they %^BOLD%^%^RED%^bleed%^BOLD%^%^BLACK%^ from numerous wounds. Set between the child figures are "
"dark black gemstones that %^RESET%^%^BLUE%^glint eerily %^BOLD%^%^BLACK%^whenever the light strikes them.%^RESET%^\n");
    set_limbs(({ "head" }));
    set_weight(6);
    set_ac(0);
    set_lore("%^BOLD%^%^WHITE%^Such a hat as this could only be the possession of the man Balur Black, a tiefling of renown across the "
"realms. His reputation as a toymaker was easily superceded by a reputation for the corrupt designs he raised by means of the craft, "
"terrifying images said to be a true representation of their subjects' inner demons. He was said to have a particular fondness for taking "
"children under his wing, although whether this is ever to their empowerment or their corruption really depends on the source of the "
"opinion.");
    set_value(0);
    set_item_bonus("spellcraft",4);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO,"strikeme":));
}

// sorry, dat hat ain't gon fit a book! Or anything else for that matter. Components only!
int item_allowed(object item) { return 0; }

int wearme() {
    int mychant;
    if((string)ETO->query_name() != "balur" && !avatarp(ETO)) {
      tell_object(ETO,"You try to set the hat straight, but it doesn't seem to fit you.");
      tell_room(EETO,"The hat doesn't seem to fit "+ETO->QCN+".",ETO);
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^You settle the top hat upon your head. The %^RESET%^%^RED%^anguished %^BOLD%^%^BLACK%^cry of the child-like dolls rings in your ears, a delightful harmony that makes you want to sing and dance!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" settles the velvet top hat upon "+ETO->QP+" head, and you're sure you hear a helpless cry of %^RESET%^%^RED%^anguish %^BOLD%^%^BLACK%^from the little child-like dolls attached to it.%^RESET%^",ETO);
    tell_object(ETO,"%^BLUE%^You remember you can still %^YELLOW%^<summon vi>%^RESET%^%^BLUE%^, though it will take you a few moments concentration to convince him!%^RESET%^");
    ETO->add_search_path("/cmds/bard");
// only active commands here are lore/song/story, and make/detect (which are both class locked). So basically this should grant him access back to the lore command without being a bard.
    mychant = (int)ETO->query_level()/6;
    if(mychant > 5) mychant = 5;
    while ((int)TO->query_property("enchantment") != mychant) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",mychant);
    }
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^BLACK%^You remove your stylish top hat.%^RESET%^");
    ETO->delete_search_path("/cmds/bard");
    return 1;
}

int strikeme(int damage, object what, object target) {
   if(!random(3)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^With a %^BOLD%^%^WHITE%^grin %^BOLD%^%^BLACK%^and a thumb to tip your hat brim, you evade the blow by vanishing and reappearing elsewhere in a b%^YELLOW%^u%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^s%^BOLD%^%^BLACK%^t of %^RESET%^smoke %^BOLD%^%^BLACK%^and %^YELLOW%^c%^BOLD%^%^RED%^i%^YELLOW%^nd%^BOLD%^%^RED%^e%^YELLOW%^rs%^BOLD%^%^BLACK%^!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" %^BOLD%^%^WHITE%^grins %^BOLD%^%^BLACK%^and thumbs the brim of "+ETO->QP+" top hat, before vanishing from harm's way and reappearing elsewhere in a b%^YELLOW%^u%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^s%^BOLD%^%^BLACK%^t of %^RESET%^smoke %^BOLD%^%^BLACK%^and %^YELLOW%^c%^BOLD%^%^RED%^i%^YELLOW%^nd%^BOLD%^%^RED%^e%^YELLOW%^rs%^BOLD%^%^BLACK%^!%^RESET%^",ETO);
     return (-1)*damage;
   }
   return 0;
}

void init(){
   ::init();
   add_action("summon_fun","summon");
}

int summon_fun(string str){
   object ob;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) {
     notify_fail("What do you want to summon?\n");
     return 0;
   }
   if(str != "vi") {
     notify_fail("You can't summon that.\n");
     return 0;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You should try wearing the hat first.");
     return 1;
   }
   if(present("Master Vi")) {
     tell_object(TP,"He is already here!");
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You conjure Master Vi before you!");
   ob=find_object_or_load("/d/avatars/nienne/mastervi");
   ob->move(EETO);
   return 1;
}