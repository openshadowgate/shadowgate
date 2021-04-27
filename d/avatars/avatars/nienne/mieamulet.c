#include <std.h>
#include <daemons.h>
inherit ARMOUR;

#define MYSPELLS "/d/avatars/nienne/amulet/"
int abear, acheetah, aowl, apanther, atrees, awaters, awinds, awolf;

void create() {
   ::create();
   set_name("carved ivory amulet");
   set_id(({"amulet","ivory amulet","pledge","darlynns pledge","carved ivory amulet","carved amulet","darlynn's pledge","Darlynn's Pledge","darlynnamulet"}));
   set_short("%^RESET%^%^GREEN%^Da%^CYAN%^r%^GREEN%^ly%^CYAN%^n%^GREEN%^n's Ple%^CYAN%^d%^GREEN%^ge%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^carved ivory amulet%^RESET%^");
   set_long("This flat circular amulet is somewhat plain, yet beautiful in "
"its %^CYAN%^simplicity%^RESET%^. It has been carved, seemingly by hand, from "
"a single piece of solid %^BOLD%^ivo%^RESET%^r%^BOLD%^y%^RESET%^, and "
"features the image of a %^ORANGE%^unicorn's head %^RESET%^encircled by a "
"patterning of %^GREEN%^leaves %^RESET%^and %^BOLD%^%^GREEN%^vines%^RESET%^. "
"The unicorn faces to the left, with some form of pale dye tinting its eye to "
"a soft %^BOLD%^%^CYAN%^azure%^RESET%^, and its spiral horn to a gentle "
"%^YELLOW%^golden hue%^RESET%^. The unicorn itself bears the color of the "
"ivory, a %^BOLD%^dull w%^RESET%^h%^BOLD%^ite%^RESET%^, while the bordering "
"leaves have been tinted with several pale shades of "
"%^GREEN%^gre%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^. A long, braided length of "
"%^ORANGE%^tanned leather %^RESET%^has been threaded through the amulet with "
"a series of intricate knots, and would hold the amulet comfortably at the "
"neck of whoever wore it. Upon the underside, lines of %^CYAN%^flowing script "
"%^RESET%^have been etched into the ivory.\n");
   set_limbs(({"neck"}));
   set_weight(0);
   set_value(0);
   set_ac(1);
   set_type("ring");
   set_language("elven");
   set_read("\n\n%^BOLD%^%^WHITE%^Only look to the aspects and the wild will aid you true%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the bear %^WHITE%^for resilience to see you through%^RESET%^\n\n"
"%^BOLD%^%^YELLOW%^Invoke the waters %^WHITE%^to restore you back to health%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the panther %^WHITE%^to be gifted with its stealth%^RESET%^\n\n"
"%^BOLD%^%^YELLOW%^Invoke the owl %^WHITE%^and you will see with vision clear%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the trees %^WHITE%^and no strong blows will you fear%^RESET%^\n\n"
"%^BOLD%^%^YELLOW%^Invoke the cheetah %^WHITE%^to be gifted feline speed%^RESET%^\n"
"%^BOLD%^%^YELLOW%^Invoke the wolf %^WHITE%^to give you strength in time of need%^RESET%^\n\n"
"%^BOLD%^%^YELLOW%^Invoke the winds %^WHITE%^to take you out of harm%^RESET%^\n"
"%^BOLD%^%^WHITE%^And so the Lady will keep you safe within her arms%^RESET%^\n");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("death keep",1);
   abear = 0;
   acheetah = 0;
   aowl = 0;
   apanther = 0;
   atrees = 0;
   awaters = 0;
   awinds = 0;
   awolf = 0;
}

int wear_fun() {
   tell_object(ETO,"%^GREEN%^A quiet assurance fills you, as you recall the "
"promise made to you.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" smiles with an expression of quiet "
"serenity.%^RESET%^",ETO);
   while ((int)TO->query_property("enchantment") != (-1)) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",(-1));
   }
   TO->set_overallStatus(100);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^GREEN%^You feel a gentle sense of sadness as you remove "
"the amulet.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" seems saddened to remove the "
"amulet.%^RESET%^",ETO);
   return 1;
}

void init() {
   ::init();
   add_action("invoke_me","invoke");
}

int invoke_me(string str) {
   if(!str) {
     notify_fail("What do you want to invoke?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to wear the amulet first.\n");
     return 0;
   }
   if(str != "the bear" && str != "the cheetah" && str != "the owl" && str != "the panther" && str != "the trees" && str != "the waters" && str != "the winds" && str != "the wolf") {
     notify_fail("You can't invoke that.\n");
     return 0;
   } 
   if(str == "the bear") {
     if(abear > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     abear = time() + 28800;
     new(MYSPELLS"_aspect_of_the_bear")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the cheetah") {
     if(acheetah > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     acheetah = time() + 28800;
     new(MYSPELLS"_aspect_of_the_cheetah")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the owl") {
     if(aowl > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     aowl = time() + 28800;
     new(MYSPELLS"_aspect_of_the_owl")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the panther") {
     if(apanther > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     apanther = time() + 28800;
     new(MYSPELLS"_aspect_of_the_panther")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the trees") {
     if(atrees > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     atrees = time() + 28800;
     new(MYSPELLS"_aspect_of_the_trees")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the waters") {
     if(awaters > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     awaters = time() + 28800;
     new(MYSPELLS"_aspect_of_the_waters")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the winds") {
     if(awinds > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     awinds = time() + 28800;
     new(MYSPELLS"_aspect_of_the_winds")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   if(str == "the wolf") {
     if(awolf > time()) {
       notify_fail("You've already used this spell today.\n");
       return 0;
     }
     awolf = time() + 28800;
     new(MYSPELLS"_aspect_of_the_wolf")->use_spell(ETO,0,ETO->query_lowest_level());
     return 1;
   }
   notify_fail("Oops, you broke it.\n");
   return 0;	
}

void reset_timer(string str) {
   if(!str) return notify_fail("Reset what?\n");
   if(str = "bear") { abear = 0; return; }
   if(str = "cheetah") { acheetah = 0; return; }
   if(str = "owl") { aowl = 0; return; }
   if(str = "panther") { apanther = 0; return; }
   if(str = "trees") { atrees = 0; return; }
   if(str = "waters") { awaters = 0; return; }
   if(str = "winds") { awinds = 0; return; }
   if(str = "wolf") { awolf = 0; return; }
   return notify_fail("You can't reset that timer.\n");
}
