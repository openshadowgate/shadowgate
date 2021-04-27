#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
   ::create();
   set_name("patterned robes");
   set_id(({"robes","patterned robes","elaborate robes","elaborately patterned robes","mantle","deceivers mantle","deceiver's mantle"}));
   set_short("%^BOLD%^%^BLACK%^De%^RESET%^c%^BOLD%^%^BLACK%^ei%^RESET%^%^MAGENTA%^v%^RED%^e%^BOLD%^%^BLACK%^r's M%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^n%^RESET%^tl%^BOLD%^%^BLACK%^e%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^el%^RESET%^a%^BOLD%^%^BLACK%^bor%^RESET%^%^MAGENTA%^at%^BOLD%^%^BLACK%^ely pa%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^te%^RESET%^r%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^ed ro%^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^es%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^These robes are of a %^BOLD%^%^CYAN%^startling %^BOLD%^%^WHITE%^appearance, marked "
"as they are with random patterning that draws and distracts the eye. Made from heavy folds of %^RESET%^"
"%^MAGENTA%^silk%^BOLD%^%^WHITE%^, the robes have been layered to form a naturally flowing garment that makes it "
"difficult to discern the exact outline of the wearer. Their ebon surface has been decorated with a series of "
"swirling whorls in varying hues of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r "
"%^BOLD%^%^WHITE%^and %^RESET%^%^MAGENTA%^v%^RED%^i%^MAGENTA%^o%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^et"
"%^BOLD%^%^WHITE%^. The artwork is seemingly random in nature, and only serve to further unsettle the eye, "
"even more so when the wearer moves. A closer look reveals the true reason for the heaviness & multi-layered style "
"of the garment - it has actually been stitched & reinforced around a suit of impossibly fine %^RESET%^chainmail"
"%^BOLD%^%^WHITE%^. Hidden within the folds, its darksteel links gleam with a %^BOLD%^%^BLACK%^m%^RESET%^al"
"%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^na%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^t %^BOLD%^%^WHITE%^light"
". In places, stains of a %^RESET%^%^RED%^de%^BOLD%^%^RED%^e%^RESET%^%^RED%^p cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^mson "
"%^BOLD%^%^WHITE%^have been splattered across the metal, and no amount of cleaning seems able to remove them.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Despite that Delilah the Deraged had a reputation for unpredictability, some "
"things could be said with certainty: that she had a touch for style, and that she always eventually got what "
"she wanted.  One particular item that piqued her interest was a suit of Celestial Chainmail, which was known "
"to be so finely made that it would not even be noticed beneath clothing, a deception that appealed greatly to "
"her. After some efforts, she finally managed to procure such a suit of armor from an unfortunate priest of "
"Lathander, Rhiannon Dawnspire. Yet still her desire was unmet, for the armor could not be worn by a servant of "
"darkness. Not to be denied, Delilah concocted a ritual offering to the Mad God, offering Rhiannon's agony and "
"life-force as a blessing upon the armor. The once-holy chainmail was corrupted beyond restoration, stained "
"eternally with the blood of the priestess of light. It is said that Delilah wove the resulting armor into the "
"folds of a fine robe, and wore it for the rest of her days. But then, who could really tell?\n%^YELLOW%^-exerpt "
"from 'Servants of the Dark Sun: insane, or inspired?' by Alverus D Wright.%^RESET%^");
   set_property("lore difficulty",25);
   set_weight(25);
   set_property("enchantment",5);
   set_item_bonus("influence",3);
   set_value(22400);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if((string)ETO->query_name() != "alzar" && !avatarp(ETO)) {
     tell_object(ETO,"The elaborate robes seem not to fit you.");
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^The robes settle comfortably into place, their protections concealed from view.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^The robes settle comfortably over "+ETOQCN+"'s body.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You remove the elaborate robes, already unsettled at the loss of their protections.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" removes "+ETO->QP+" elaborate robes, looking uneasy.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(random(500) < 100){
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+who->QCN+" makes a strike at "+ETOQCN+"'s exposed side, only to be "
"deflected by some kind of hidden protection!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^WHITE%^%^BOLD%^"+who->QCN+" makes a strike at your 'exposed' side, only to be deflected "
"by the hidden links of chainmail! "+capitalize(who->QS)+" looks surprised!%^RESET%^");
     tell_object(who,"%^WHITE%^%^BOLD%^You make a strike at "+ETOQCN+"'s exposed side, only to have the blow "
"deflected by some kind of hidden protection!%^RESET%^");
     return (-1)*damage;
   }
}