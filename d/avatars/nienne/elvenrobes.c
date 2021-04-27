#include <std.h>
inherit PARMOUR;

int tracker;

void create() {
   ::create();
   set_name("satin robe");
   set_id(({"robe","satin robe","vestments","vestments of the high art","trimmed robe","trimmed satin robe","elaborately trimmed satin robe"}));
   set_short("%^BOLD%^%^BLUE%^V%^RESET%^%^BLUE%^es%^BOLD%^tme%^RESET%^%^BLUE%^nt%^BOLD%^s of the %^WHITE%^Hi%^YELLOW%^g%^WHITE%^h A%^YELLOW%^r%^WHITE%^t%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLUE%^an %^WHITE%^ela%^CYAN%^bo%^WHITE%^rat%^YELLOW%^e%^WHITE%^ly %^BLUE%^trimmed sa%^RESET%^%^BLUE%^ti%^BOLD%^n robe%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Multiple layers of %^RESET%^%^CYAN%^sh%^BLUE%^im%^CYAN%^me%^GREEN%^r%^CYAN%^ing "
"s%^BOLD%^a%^RESET%^%^CYAN%^tin %^BOLD%^%^WHITE%^form this magnificent robe, so finely made that you could not "
"even begin to guess at its worth.  It has been cut to fit a slender frame, and certainly not a tall one.  "
"Its lower layer is crafted of %^BLUE%^rich b%^RESET%^%^BLUE%^l%^BOLD%^ue %^WHITE%^cloth that falls in elegant"
", comfortable folds along the wearer's body, all the way to the ground.  It is undecorated save for a "
"%^RESET%^%^RED%^deep s%^BOLD%^ca%^RESET%^%^RED%^rlet %^BOLD%^%^WHITE%^sash that wraps several times about the "
"waist, leaving the ends to trail free.  However, it is the overcoat partnered with this relatively simple "
"first layer that creates the true effect of the robe.  The upper layer is formed of similar satin, but of a "
"much deeper hue, almost %^RESET%^%^BLUE%^midnight blue%^BOLD%^%^WHITE%^.  A brace of %^YELLOW%^go%^RESET%^"
"%^ORANGE%^ld%^YELLOW%^en %^WHITE%^cloth covers both shoulders, leading down to the wide band of %^BLUE%^emb"
"%^YELLOW%^r%^BLUE%^oi%^WHITE%^de%^BLUE%^ry %^WHITE%^that encircles the neck, both sleeves, and the full "
"hemline of the coat from the throat to the floor, and fully encircling its feet.  The band is set upon a base "
"of the same %^BOLD%^%^BLUE%^rich b%^RESET%^%^BLUE%^l%^BOLD%^ue %^WHITE%^color as the undercoat, and is "
"patterned in %^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d %^WHITE%^thread that forms a tracery of arcane "
"runes.  Shifting among them, flecks of %^RESET%^si%^BOLD%^l%^RESET%^ver %^BOLD%^mark out what might be tiny "
"stars that become more visible with movement.  The entire garment gives an overall appearance of splendor, "
"almost %^RESET%^%^MAGENTA%^re%^RED%^gal%^MAGENTA%^ity%^BOLD%^%^WHITE%^, and would make the wearer look very "
"impressive indeed.\n%^RESET%^");
   set_lore("Elven archmagi prize such garments as this, crafted through their incredible skill at both "
"magical and mundane artistry.  They are always made of fine cloth, often patterned with emblems that are "
"favored by elven wizards in detailed embroidery.  In contrast to the cleverly-camouflaged armor that "
"elvenkind usually crafts, these robes are usually made from vibrant hues that contrast in a bold display of "
"color.  Many hold enchantments to further enhance the power of the magus wearing them.  They are rare to "
"find at all, and even more rare to own, as only specially chosen magi from among their kin are ever gifted "
"with them.");
   set_property("lore",16);
   set_value(20000);
   set_property("enchantment",3);
   set_weight(5);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(2);
   set_max_internal_encumbrance(25);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   tracker = 0;
}

int wearme() {
   if((string)ETO->query_name() != "isaiah" && !avatarp(ETO)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The elegant robe is obviously not designed to fit one such as "
"you.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The elegant robe was obviously designed for someone other than "
+ETO->QCN+"%^BOLD%^%^WHITE%^, as it simply does not fit "+ETO->QO+".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The robe settles into soft, comfortable folds around you.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The robe settles into soft, comfortable folds around "+ETO->QCN+"%^BOLD%^"
"%^WHITE%^.%^RESET%^",ETO);
   ETO->set_property("good item",1);
   ETO->set_property("spell penetration",5);
   ETO->set_property("empowered",1);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You miss the soft touch of the robes already.%^RESET%^");
   ETO->set_property("good item",-1);
   ETO->set_property("spell penetration",-5);
   ETO->set_property("empowered",-1);
   return 1;
}

void init() {
   ::init();
   add_action("contactem","contact");
}

int contactem(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You must be wearing the robe to activate it.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You need to specify who you want to contact.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"The robe is still recharging for another use.");
     return 1;
   }
   tracker = time() + 14400;
   new("/cmds/priest/_telepathy")->use_spell(TP,str,30);
   return 1;
}

void resetme() { tracker = 0; }
