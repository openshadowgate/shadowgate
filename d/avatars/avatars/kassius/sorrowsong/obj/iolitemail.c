#include <std.h>;
#include "../sorrowsong.h"
inherit "/d/common/obj/armour/hide.c";

void create(){
    ::create();
    set_name("chainmail");
    set_id(({"chainmail","chain mail", "mail", "chain", "chainshirt","hide","crystal breastplate","crystals","crystal","crystal hide","crystal chainmail"}));
    set_short("%^BOLD%^%^CYAN%^I%^BOLD%^%^BLUE%^ol%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^te %^BLUE%^Chainmail%^RESET%^");
    set_obvious_short("%^RESET%^%^BLUE%^Cr%^BOLD%^%^CYAN%^y%^RESET%^%^BLUE%^s%^BOLD%^%^CYAN%^t%^RESET%^%^BLUE%^al Ch%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^inm%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^il%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This suit of armor is rather odd, but a remarkable feat of craftsmanship."+
	  " Instead of typical metal links being forged together this suit has somehow been shaped from "+
	  "%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^io%^WHITE%^l%^MAGENTA%^et%^WHITE%^ crystals with tinges of %^BOLD%^%^CYAN%^sky blue%^WHITE%^"+
	  " streaking through each crystal. The crystals sh%^MAGENTA%^i%^WHITE%^ft in color depending on your angle of view. One view of the" 
	  " crystals are a %^RESET%^%^MAGENTA%^violette blue%^BOLD%^%^WHITE%^, while from another perspective they are as translucent as "
	  "%^RESET%^%^CYAN%^water%^BOLD%^%^WHITE%^. An aerial view of each crystal gives them a %^RESET%^%^ORANGE%^h%^BOLD%^%^YELLOW%^o"
	  "%^RESET%^%^ORANGE%^ney-yellow %^BOLD%^%^WHITE%^gl%^BOLD%^%^ORANGE%^o%^BOLD%^%^WHITE%^w in appearance.");
    set_lore("%^RESET%^%^CYAN%^A druidic grove stumbled upon a crystal that was highly unique in color."
	" The crystals are known as Iolite and usually are a violet, but can be a brown, blue and the most precious are violet and sky blue."
	" The eldest druid was able to meld these crystals into a cherished set of armor for the most worthy of druids.");
    set_value(2000);
    set_size(2);
    set_property("enchantment",5);
    set_property("lore diffculty",40);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}


int wear_func(){
      tell_object(ETO,"The %^BOLD%^%^WHITE%^crystals%^RESET%^ glow as they wrap about you.");
      tell_room(EETO, "The Crystals composing " +ETOQCN + "'s suit %^BOLD%^%^YELLOW%^glow%^RESET%^ as "+ETO->QS+ " dons the armor.",ETO);
	  ETO->add_temporary_feat("death ward"); 
	  return 1;}

int remove_func(){
    tell_object(ETO,"The %^BOLD%^%^WHITE%^crystals%^RESET%^ fade as you remove them.");
    tell_room(EETO, ETOQCN + "'s chainmail dims as "+ETO->QS+ " removes it.", ETO);
    ETO->remove_temporary_feat("death ward"); 
	return 1;}
	


