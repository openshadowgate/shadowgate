//mask_jester.c - special porcelain mask
//for new Seneca ~Circe~ 12/22/07 -adapted as a prize for the festival by Tsera 05/23/2013
#include <std.h>
#include "/d/attaya/newseneca/seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("jester mask");
   set_obvious_short("%^BOLD%^%^RED%^a t%^YELLOW%^r%^RED%^i"+
      "%^BLUE%^-%^YELLOW%^c%^RED%^o%^BLUE%^l%^YELLOW%^o%^RED%^r "+
      "%^RED%^eyemask%^RESET%^");
   set_short("%^BOLD%^%^RED%^Mask of the %^YELLOW%^J%^RED%^e"+
      "%^BLUE%^s%^YELLOW%^t%^RED%^e%^BLUE%^r%^RESET%^");
   set_id(({"mask","jester mask","eyemask","jester eyemask","tri-color mask","tri-color eyemask","mask of the jester","Mask of the Jester"}));
   set_long("%^RESET%^%^RED%^A molded leather eyemask painted "+
      "%^BOLD%^brilliant red %^RESET%^%^RED%^makes up the "+
      "base for this creation.  The %^BOLD%^red %^RESET%^"+
      "%^RED%^lightens to vibrant %^YELLOW%^yellow %^RESET%^"+
      "%^RED%^near the center of the mask along the bridge of "+
      "the nose, and %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n "+
      "%^BOLD%^s%^RESET%^%^ORANGE%^c%^BOLD%^r%^RESET%^%^ORANGE%^o"+
      "%^BOLD%^l%^RESET%^%^ORANGE%^l%^BOLD%^w%^RESET%^%^ORANGE%^o"+
      "%^BOLD%^r%^RESET%^%^ORANGE%^k %^RED%^spirals along "+
      "the face, their edges touching the %^YELLOW%^gold braid "+
      "%^RESET%^%^RED%^that bounds the mask.  Curling %^BOLD%^"+
      "velvet plumes %^RESET%^%^RED%^in %^BOLD%^%^RED%^red "+
      "%^RESET%^%^RED%^and %^BOLD%^%^BLUE%^blue %^RESET%^%^RED%^edged "+
      "in %^YELLOW%^gold %^RESET%^%^RED%^rise from the crown of "+
      "the mask, each of their tips ending in a tiny %^YELLOW%^"+
      "golden bell%^RESET%^%^RED%^.  %^BOLD%^Silken ribbons "+
      "%^RESET%^%^RED%^are attached at each corner of the mask "+
      "and may be tied around the head to secure it.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLUE%^t%^YELLOW%^r%^RED%^i"+
      "%^BLUE%^-%^YELLOW%^c%^RED%^o%^BLUE%^l%^YELLOW%^o%^RED%^r");
   set_costume("eyemask");
   set_value(750);
   set_limbs(({"head"}));
   set_lore("%^BOLD%^%^RED%^This mask is said to be the prize given for %^YELLOW%^best performance %^RED%^at the festival hosted by the temples of Kossuth and"         
            " Sune in %^BLUE%^Torm%^RED%^, dated %^GREEN%^12 Growingdays 712 SG.%^RESET%^");
   set_property("lore difficulty",17);
   set_size(1);
   set_item_bonus("negative energy resistance",5);
   set_item_bonus("bonus spell slots",1);
}

