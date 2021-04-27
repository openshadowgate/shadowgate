#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int trackera, trackerb, trackerc;

void create(){
        ::create();
        set_name("mithril crown");
        set_id(({ "crown", "mithril crown", "flame covered crown", "crown of the silver flame" }));
        set_short("%^BOLD%^%^WHITE%^C%^YELLOW%^r%^BOLD%^%^WHITE%^o%^YELLOW%^w%^BOLD%^%^WHITE%^n of the %^BOLD%^%^CYAN%^S%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^lv%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^r F%^BOLD%^%^WHITE%^l%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^m%^BOLD%^%^CYAN%^e%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^a %^BOLD%^%^CYAN%^fla%^BOLD%^%^WHITE%^m%^BOLD%^%^CYAN%^e covered %^BOLD%^%^WHITE%^mi%^YELLOW%^t%^BOLD%^%^WHITE%^hril crown%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This gleaming crown is forged from a "
"single billet of pure silvery mithril.  The metal has been shaped into "
"form by a master of the craft as all indication of tool marks and joints "
"have been completely removed.  In the front of the mithril circlet a set "
"of five %^BOLD%^%^CYAN%^moonstones %^BOLD%^%^WHITE%^have been set.  The "
"largest, worn over the brow of the head, is at least as big as a child's "
"hand and is oval in shape.  To either side of the large moonstone a set "
"of crescent-shaped moonstones have been set, and beside these, thin "
"tapered moonstones curve around to either side of the crown.  These "
"gemstones sparkle with a %^YELLOW%^brilliant light %^BOLD%^%^WHITE%^that "
"flickers and reflects the motion of the %^BOLD%^%^CYAN%^silvery flames "
"%^BOLD%^%^WHITE%^that dance along the top of the crown.  Though cool to "
"the touch, there is a powerful energy that constantly swirls and resonates "
"within the ever shifting swirl of %^BOLD%^%^CYAN%^silvery flames"
"%^BOLD%^%^WHITE%^.\n%^RESET%^");
        set_weight(10);
        set_value(0);
        set_lore("This was once said to have been a Crown of the Arcane "
"Flame, an artifact created by the Lich of Attaya.  It was transformed by "
"the hand of Eilistraee for Aunuit Rilynath, a faithful priestess. "
"Together with a gathering of elvenkind, a ritual was enacted to beseech "
"the seldarine to restore the drow allies of Rilynath, once elves, to "
"their rightful forms following a curse put upon them by the sun elves of "
"Selu'havessthyr. With the combined strength of the elves, Aunuit aided "
"in the ritual's success, and was blessed by the touch of Eilistraee for "
"her efforts. While the artifact is said to work similarly to the original "
"crown, the touch of the Dark Maiden served to alter its powers.");
        set_property("lore difficulty",25);
        set_type("clothing");
        set_limbs(({ "head" }));
        set_size(-1);
        set_property("enchantment",5);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
        trackera = 0;
        trackerb = 0;
        trackerc = 0;
}

int wear_func(){
        if((string)ETO->query_name() != "aunuit" && !avatarp(ETO)) {
          tell_object(ETO,"%^BOLD%^%^WHITE%^The brilliant crown seems not to fit you.%^RESET%^");
          return 0;
        }
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" places the crown upon "+ETO->QP+" head.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^WHITE%^As you don the crown, knowledge fills your mind.  "
"%^BOLD%^%^CYAN%^Summon %^BOLD%^%^WHITE%^fire to smite your enemy.  %^BOLD%^%^CYAN%^Conjure "
"%^BOLD%^%^WHITE%^strength to dissolve their protections.  %^BOLD%^%^CYAN%^Invoke "
"%^BOLD%^%^WHITE%^the depths of the mind to ward against their coming.%^RESET%^");
        return 1;
}

int remove_func(){
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" looks a little confused as "+ETO->QS+" removes "
+ETO->QP+" crown.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^WHITE%^All the knowledge seeps from your mind as you remove your "
"crown.%^RESET%^");
        return 1;
}

void init() {
   ::init();
   add_action("fireball_fun","summon");
   add_action("dispel_fun","conjure");
   add_action("scryproof_fun","invoke");
}

int fireball_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the crown.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You should use <summon at target>.");
     return 1;
   }
   if(sscanf(str,"at %s",mytarg) == 1) {
     if(trackera > time()) {
       tell_object(TP,"The crown is still recharging that power.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     trackera = time() + 28800;
     new("/d/avatars/nienne/spells/_moonfire")->use_spell(TP,present(mytarg,ETP),30,100,"mage");
     return 1;
   }
   tell_object(TP,"You should use <summon at target>.");
   return 1;
}

int dispel_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the crown.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You should use <conjure at target>.");
     return 1;
   }
   if(sscanf(str,"at %s",mytarg) == 1) {
     if(trackerb > time()) {
       tell_object(TP,"The crown is still recharging that power.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     trackerb = time() + 43200;
     new("/d/avatars/nienne/spells/_moonmote_dispel")->use_spell(TP,present(mytarg,ETP),30,10,"mage");
     return 1;
   }
   tell_object(TP,"You should use <conjure at target>.");
   return 1;
}

int scryproof_fun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the crown.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You should use <invoke at target>.");
     return 1;
   }
   if(sscanf(str,"at %s",mytarg) == 1) {
     if(trackerc > time()) {
       tell_object(TP,"The crown is still recharging that power.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     trackerc = time() + 86400;
     new("/d/avatars/nienne/spells/_moonlight_protection")->use_spell(TP,present(mytarg,ETP),30,100,"mage");
     return 1;
   }
   tell_object(TP,"You should use <invoke at target>.");
   return 1;
}
