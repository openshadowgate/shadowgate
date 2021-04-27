// Coded by Lujke. These are the devilkin's dancing boots. They are
// enchanted to +1, have an ac setting of -1 when worn, but give a bonus
// of +1 to dex.


#include <std.h>
#include <move.h>
inherit ARMOUR;

void create()
{
  ::create();
  set_obvious_short("%^YELLOW%^G%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^"
                   +"%^ORANGE%^e%^YELLOW%^n M%^RESET%^%^ORANGE%^a"
                   +"%^YELLOW%^ne%^RESET%^");
  set_name("%^YELLOW%^W%^RESET%^%^ORANGE%^e%^YELLOW%^mic m%^RESET%^"
           +"%^ORANGE%^a%^YELLOW%^ne");
  set_short("%^YELLOW%^Tr%^RESET%^%^ORANGE%^o%^YELLOW%^phy of the fallen"
           +" %^BOLD%^%^BLACK%^pr%^RESET%^e%^BOLD%^%^BLACK%^y%^RESET%^");
  set_id(({"mane","trophy","wemic mane", "coif"}));
  set_long("%^YELLOW%^A coif made from the flowing g%^RESET%^%^ORANGE%^o"
          +"%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n m%^RESET%^"
          +"%^ORANGE%^a%^YELLOW%^ne of a wemic. It is not finely crafted,"
          +" but put together with a rough, uncaring barbaric"
          +" practicality. The s%^RESET%^%^ORANGE%^t%^YELLOW%^i%^RESET%^"
          +"%^ORANGE%^t%^YELLOW%^c%^RESET%^%^ORANGE%^h%^YELLOW%^e"
          +"%^RESET%^%^ORANGE%^s%^YELLOW%^ show, but they will hold it"
          +" together and make it into good protection from the elements."
          +"%^RESET%^"
	);
  set_weight(5);
  set_type("clothing");
  set_limbs(({"head"}));
  set_ac(0);
  set_property("enchantment",1);
  set_value(50);
  set_wear((:TO,"wearme":));
  set_size(2);
}

int wearme()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO,"As you pull the %^YELLOW%^w%^RESET%^%^ORANGE%^e"
                 +"%^YELLOW%^mic m%^RESET%^%^ORANGE%^a%^YELLOW%^ne"
                 +"%^RESET%^ over your head, you are reminded of the many"
                 +" victories of the %^BOLD%^%^GREEN%^B%^RESET%^%^GREEN"
                 +"%^eas%^BOLD%^%^GREEN%^tlord");
  tell_room(EETO,ETO->query_cap_name() + " slides on the " + query_name()
                + " and ajusts it on " + (string)ETO->QP + " head.\n\n"
                + ETO->query_cap_name()
                + " smiles grimly", ETO);
  return 1;
}

