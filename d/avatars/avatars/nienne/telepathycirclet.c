#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int charges;

void create() {
   ::create();
   set_name("circlet");
   set_id(({"circlet","gemmed circlet","silver circlet","circlet of telepathy","Circlet of Telepathy"}));
   set_short("%^BOLD%^%^BLACK%^C%^RESET%^ir%^BOLD%^%^BLACK%^c%^RESET%^le%^BOLD%^%^BLACK%^t %^RESET%^of %^MAGENTA%^Te%^RED%^l%^MAGENTA%^epa%^RED%^t%^MAGENTA%^hy%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a %^RESET%^%^WHITE%^g%^CYAN%^e%^WHITE%^mm%^MAGENTA%^e%^WHITE%^d %^BOLD%^%^BLACK%^c%^RESET%^ir%^BOLD%^%^BLACK%^c%^RESET%^le%^BOLD%^%^BLACK%^t%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This simple circlet bears no flaws or "
"blemishes, existing as a perfect circle of brightly polished "
"%^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^BLACK%^.  Set within the front "
"of the piece is a single oval gemstone of mottled opal, reflecting soft "
"%^RESET%^p%^CYAN%^a%^WHITE%^st%^MAGENTA%^e%^WHITE%^l %^BOLD%^%^BLACK%^hues "
"when moved.  Tiny etchings of %^BLUE%^a%^CYAN%^r%^BLUE%^ca%^CYAN%^n%^BLUE%^e "
"%^BLACK%^runes pattern the outer surface of the circlet itself.%^RESET%^");
   set_weight(0);
   set_limbs(({"head"}));
   set_ac(0);
   set_value(2000);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   charges = 30+ random(11);
}

void init() {
   ::init();
   add_action("contact_me","contact");
}

int wear_fun() {
   if((int)ETO->query_highest_level() < 30) {
     tell_object(ETO,"Some kind of magical warding prevents you from wearing "
"the circlet.");
     tell_room(EETO,""+ETOQCN+" seems unable to wear the circlet.",ETO);
     return 0;
   }
   return 1;
}

int contact_me(string str) {
   if(!TO->query_worn()) {
     notify_fail("You should be wearing the circlet to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to contact.\n");
     return 0;
   }
   if(!charges) {
     notify_fail("The circlet's power is already depleted.\n");
     return 0;
   }
   charges--;
   new("/cmds/priest/_telepathy")->use_spell(ETO,str,40);
   return 1;
}

int isMagic(){ return 1; }

void renew_charges() { charges = 30+ random(11); }
int is_tazrak_charged() { return 1; }