#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("mystical bag");
	set_id(({ "bag", "mystical bag", "masquerade bag", "silver bag" }));
	set_obvious_short("%^BOLD%^%^WHITE%^a %^MAGENTA%^m%^CYAN%^ys%^BLUE%^ti%^GREEN%^ca%^RESET%^%^YELLOW%^l %^WHITE%^silver bag%^RESET%^");
	set_short("%^BOLD%^%^MAGENTA%^Ma%^CYAN%^sq%^BLUE%^ue%^GREEN%^ra%^YELLOW%^de %^RESET%^%^ORANGE%^Ba%^BOLD%^%^RED%^g%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This strange bag looks like it might be made from "
"silver cloth, yet it glows with a %^MAGENTA%^po%^CYAN%^we%^BLUE%^rf%^GREEN%^ul "
"%^YELLOW%^au%^RED%^ra %^WHITE%^that shifts and changes with every moment.  "
"About the size of a standard pouch it is strangely heavy though the fabric is "
"very light and always seems to be flat and empty even when it is holding "
"something.  A draw string allows the bag to be open and closed as well as "
"hooked about the wrist or over a belt to keep it secure.  A small label has "
"been sewn onto the inside of the bag, you may want to read it.%^RESET%^");
	set("read","\nMasquerade Bag:\n\n"
"This bag is designed for use only during the Masquerade Ball and will vanish if it is taken outside of the Masquerade "
"grounds.  When the bag vanishes the entire contents will drop into your inventory but will not auto wear.  It is "
"suggested that you use caution and you remove things from the bags before leaving.  You may also want to take a log of "
"your bag's inventory in case of an error/bug or disconnection.\n\n"
"Please note that the bag has a huge storage capacity.  Is meant for you to be able to place your standard adventuring "
"gear/equipment into it so that you can wear a costume and not have your gear give you away.  However, to prevent abuse, "
"the bags will not hold kits, water or other stackables.  Likewise, just like normal sacks this bag will not hold items "
"that have things in them (sacks, pouches, mage robes, etc) until you empty them.\n");
      set("langage","wizish");
      set_weight(0);
	set_value(0);
	set_lore("These bags were designed by the psion enclave of Torm in order to allow guests to store their standard "
"gear away in a safe place that they could keep with them during the Masquerade Ball.  Because the bags require some "
"mental focus and energy to function, they can only be used in places that are completely designed by the mind.");
	set_property("lore difficulty",0);
	set_max_internal_encumbrance(300);
      set_type("ring");
	set_limbs(({ "right hand" }));
      set_size(2);
      set_heart_beat(1);
}

void heart_beat() {
   object location, *baginven;
   string locstring;
   if(!objectp(ETO)) return;
   if(userp(ETO) && objectp(EETO)) location = EETO;
   else location = ETO;
   if(ETO->is_container() && !userp(ETO)) {
     if(userp(EETO)) tell_object(EETO,"%^ORANGE%^The bag disintegrates as you try to stuff it away.%^RESET%^");
     TO->remove();
   }
   locstring = base_name(location);
   if(strsrch(locstring,"/d/av_rooms/lurue/masq") == -1) {
     tell_room(location,"%^ORANGE%^Taking the bag outside of the safe zone causes it to disintegrate!%^RESET%^");
     baginven = all_inventory(TO);
     if(sizeof(baginven)) {
       tell_room(location,"%^ORANGE%^The contents of the bag spill out onto the ground!%^RESET%^");
       while(sizeof(baginven)) {
         baginven[0]->move(location);
         baginven = all_inventory(TO);
       }
     }
     TO->remove();
   }
}

int isMagic(){ return 1; }

int item_allowed(object what) {
  ::item_allowed(what);
  if((string)what->query_name() == "holy water" || member_array("vial",what->query_id()) != -1) {
    notify_fail("This doesn't seem to fit in the bag.\n");
    return 0;
  }
  return 1;
}