#include <std.h>

// made by Lujke as a 'repaired' ragged cloak. Unfortunately, the repairer managed to damage the enchantment
// during the process of repairs.

inherit ARMOUR;

void create() {
   ::create();
   set_name("patchwork cloak");
   set_id(({"cloak","patchwork cloak"}));
   set_obvious_short("%^MAGENTA%^p%^RED%^a%^BLUE%^t%^BOLD%^%^YELLOW%^c%^RESET%^%^CYAN%^h%^BLUE%^w%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^r%^RED%^k"
                    +"%^RESET%^ cloak");
set_short("%^MAGENTA%^b%^RED%^a%^ORANGE%^r%^BOLD%^%^BLACK%^d%^YELLOW%^'%^RESET%^%^CYAN%^"
              +"s%^BOLD%^%^BLUE%^ c%^RESET%^%^GREEN%^l%^MAGENTA%^o%^ORANGE%^a%^RED%^k");

   set_long("This cloak possesses multiple fabric pieces of varying"
          +" %^MAGENTA%^c%^RED%^o%^BOLD%^%^YELLOW%^l%^BLUE%^o"
          +"%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^s%^RESET%^, forming "
          +"a patchwork of faded and bright colors. Some small"
          +" holes within the colored patches have been stitched closed"
          +" with a %^BOLD%^%^RED%^red silk%^RESET%^, while patterns of"
          +" %^MAGENTA%^magenta%^RESET%^, %^BOLD%^%^WHITE%^g%^BOLD%^"
          +"%^BLACK%^r%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^y%^RESET%^,"
          +" %^BLUE%^blue%^RESET%^, %^BOLD%^%^YELLOW%^gold%^RESET%^,"
          +" and %^GREEN%^green%^RESET%^ make up the rest of this oddly"
          +" inoffensive cloak. It ties at the neck while hugging the"
          +" shoulders of a lean man perfectly. Embroidered into a small"
          +" %^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^e"
          +"%^BOLD%^%^BLACK%^y%^RESET%^ patch is an open %^BOLD%^"
          +"%^WHITE%^S%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^"
          +"%^WHITE%^r%^RESET%^ hand with stylised gusts of %^CYAN%^"
          +"wind%^RESET%^ surrounding it. ");
   set_lore("This much repaired cloak was once a cloak worn by one "+
      "of the Great Bards.  This was not so much a guild as a measure "+
      "of honor bestowed upon some bards of the land.  A visit from "+
      "a true bard to a small town was a real honor and pleasure for "+
      "the townspeople.  In preparation for such an event, the goodwives "+
      "of the town would often get together and make a gift of some "+
      "sort to the bard.  The goodwives of Koenig used to make "+
      "these cloaks.  Each patch was taken from an article of clothing "+
      "of import to all the villagers.  The women gathered the patches "+
      "and sewed them into the cloak so that a little piece of the "+
      "village might go with the bard wherever he traveled.");
   set_weight(6);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(200);
//   set_property("enchantment",1);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   tell_object(ETO,"%^MAGENTA%^As you put on the patched up cloak, "
               +"you are reminded of some of your happiest experiences of entertainment");
   return 1;
}

int remove_func() {
   tell_object(ETO,"%^MAGENTA%^You put aside your thoughts of the stage");
   return 1;
}
