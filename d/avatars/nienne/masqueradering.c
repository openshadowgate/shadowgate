#include <std.h>
inherit ARMOUR;

string myidentity, myadjective;
int isdisguised;

void create(){
	::create();
	set_name("strange ring");
	set_id(({ "ring", "strange ring", "mystical silver ring", "silver ring", "masquerade ring", "masq ring" }));
	set_short("%^BOLD%^%^WHITE%^a %^MAGENTA%^m%^CYAN%^ys%^BLUE%^ti%^GREEN%^ca%^RESET%^%^YELLOW%^l %^WHITE%^silver ring%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^Ma%^CYAN%^sq%^BLUE%^ue%^GREEN%^ra%^YELLOW%^de %^RESET%^%^ORANGE%^Ri%^BOLD%^%^RED%^ng%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This strange band looks like it might be made from silver, yet it glows with a "
"%^MAGENTA%^po%^CYAN%^we%^BLUE%^rf%^GREEN%^ul %^YELLOW%^au%^RED%^ra %^WHITE%^that shifts and changes with every moment.  "
"Looking closely, you can see there is writing upon the inside surface.  Maybe you should try reading it.%^RESET%^");
	set("read","\nMasquerade Ring:\n\n"
"The ring allows you to alter your adjective completely by entering a line of text.  You do not have to retain the use "
"of your race ($R) in this case, but will need to add color and an 'A/An' at the beginning if you want one to appear.\n\n"
"To use this device type %^BOLD%^%^CYAN%^<costumeme identity adjective>%^RESET%^, where identity is 'what' you are (human"
", ghost, etc) and adjective is how you will be seen.  The adjective must contain your identity, so that other players "
"know how to look at you.  %^BOLD%^%^CYAN%^<costumeme current>%^RESET%^ will inform you of your current disguise, and "
"%^BOLD%^%^CYAN%^<costumeme reset>%^RESET%^ will restore your original description (you must do this, or remove the ring, "
"before setting a new identity).  Note that this will not change your description and you will need to alter it normally "
"though the %^BOLD%^%^MAGENTA%^<describe> %^RESET%^command.\n\n"
"Removing the ring or logging out will reset your adjective to its original adjective.  Please be aware that consequences "
"will follow the abuse of this ability.\n\n"
"Please note, the ring will only function within the halls of the masquerade ball and will vanish when you leave.\n");
      set("langage","wizish");
	set_weight(0);
	set_value(0);
	set_lore("These rings were designed by the psion enclave of Torm in order to allow guests to the Masquerade Ball to "
"be disguised.  Their function causes the mind to forget the little tell-tell give a-ways and to see the wearer as a "
"completely new person.  Because the rings require some mental focus and energy to function, they can only be used in "
"places that are completely designed by the mind.");
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
      set_remove((:TO,"remove_fun":));
      set_heart_beat(1);
}

int remove_fun() {
   ETO->set_disguise("");
   ETO->set_disguised(0);
   isdisguised = 0;
   myidentity = "";
   myadjective = "";
   return 1;
}

void heart_beat() {
   object location;
   string locstring;
   if(!objectp(ETO)) return;
   if(userp(ETO) && objectp(EETO)) location = EETO;
   else location = ETO;
   locstring = base_name(location);
   if(strsrch(locstring,"/d/av_rooms/lurue/masq") == -1) {
     tell_room(location,"%^ORANGE%^Taking the ring outside of the safe zone causes it to disintegrate!%^RESET%^");
     TO->remove();
   }
}

void init() {
   ::init();
   add_action("costume_fun","costumeme");
}

int costume_fun(string str) {
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You need to be wearing the ring.\n");
   if(!str) return notify_fail("Please read the ring in order to see the appropriate syntaxes.\n");
   if(str == "current") {
     if(!isdisguised) return notify_fail("You are not currently disguised.\n");
     tell_object(TP,"%^YELLOW%^Your current identity is '"+myidentity+"%^YELLOW%^' and your current adjective is '"
+myadjective+"%^YELLOW%^'.%^RESET%^");
     return 1;
   }
   if(str == "reset") {
     if(!isdisguised) return notify_fail("You are not currently disguised.\n");
     tell_object(TP,"%^YELLOW%^You remove your disguise and go back to looking as you normally do.%^RESET%^");
     TP->set_disguise("");
     TP->set_disguised(0);
     isdisguised = 0;
     myidentity = "";
     myadjective = "";
     return 1;
   }
   if(isdisguised) return notify_fail("You are already disguised.  Please <costumeme reset> if you wish to try again.\n");
   if(sscanf(str,"%s %s", myidentity, myadjective) != 2)
     return notify_fail("Please read the ring in order to see the appropriate syntaxes.\n");
   if(strsrch(myadjective,myidentity) == -1)
     return notify_fail("Your new adjective must include your identity, so other players can look at you.\n");

   tell_object(TP,"%^YELLOW%^Your current identity is '"+myidentity+"%^YELLOW%^' and your current adjective is '"
+myadjective+"%^YELLOW%^'.%^RESET%^");
   isdisguised = 1;
   TP->add_id(myidentity);
   TP->set_disguised(1);
   TP->set_disguise(myadjective);
   return 1;
}

int isMagic(){ return 1; }
