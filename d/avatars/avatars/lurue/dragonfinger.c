#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("skeleton ring");
	set_id(({ "finger ring", "ring", "skeleton ring", "skelton finger ring", "dragon ring" }));
	set_short("%^BOLD%^%^GREEN%^R%^BLACK%^i%^RESET%^%^GREEN%^n%^BOLD%^g %^BLACK%^o%^GREEN%^f %^RESET%^%^GREEN%^th%^BOLD%^%^BLACK%^e %^GREEN%^U%^BLACK%^n%^RESET%^%^GREEN%^d%^BOLD%^ea%^RESET%^%^GREEN%^d %^BLACK%^%^BOLD%^W%^RESET%^%^GREEN%^y%^BOLD%^rm%^BLACK%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a %^GREEN%^s%^RESET%^%^GREEN%^k%^BOLD%^e%^BLACK%^l%^RESET%^%^GREEN%^e%^BOLD%^ta%^RESET%^%^GREEN%^l %^BOLD%^%^BLACK%^finger ring%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This ring is made from the hollowed out %^WHITE%^spike %^BLUE%^of a wyvern's ridge spine"
".  The spine has been hollowed and cut into three pieces, with the large piece and end piece both retaining a hoop of "
"%^WHITE%^bone %^BLUE%^on the underside to allow the ring to be worn.  Set with %^GREEN%^t%^BLACK%^a%^RESET%^%^GREEN%^r"
"%^BOLD%^ni%^BLACK%^s%^GREEN%^h%^RESET%^%^GREEN%^e%^BOLD%^d c%^BLACK%^o%^RESET%^%^GREEN%^p%^BOLD%^p%^BLACK%^e%^RESET%^"
"%^GREEN%^r r%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^v%^RESET%^%^GREEN%^e%^BOLD%^t%^RESET%^%^GREEN%^s %^BOLD%^%^BLUE%^at the "
"points where these three pieces connect, creating joints that will not give out despite flexing the finger.  The effect "
"is that of a %^WHITE%^bony talon %^BLUE%^that tapers to a dangerous point.%^RESET%^");
	set_weight(1);
	set_value(1000);
	set_lore("After creating an undead mount from the corpse of a wyvern, this ring was formed in order for the owner "
"to summon the mount when needed.  Though the ring is surrounded in power, this power is mostly meant to contain the "
"mount's temperament and subject it to the rider's will.  Without wearing this ring any who dared try to ride such a "
"creature would likely be quickly made into lunch.  Both the creature and ring were presented to the 2nd annual Spooky "
"Story Telling Contest Winner, Belendithas for his strange and twisted tale of a person haunted by their past in the form "
"of a small child.");
	set_property("lore difficulty",12);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
      set_wear((:TO,"wear_fun":));
}

void init(){
   ::init();
   add_action("summon_fun","summon");
}

int wear_fun(){
    if((string)ETO->query_name() != "belendithas" && !avatarp(ETO)) {
      tell_object(ETO,"You can't wear that.");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^You remember as you put on the ring, that it is %^YELLOW%^<summon wyvern> %^WHITE%^"
"to call to your mount.%^RESET%^");
    return 1;
}

int summon_fun(string str) {
    object ob;
    if(!str) {
      notify_fail("Summon what?");
      return 0;
    }
    if(str != "wyvern") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(!TO->query_worn()) {
      tell_object(TP,"You should try wearing the ring first.");
      return 1;
    }
    if(present("skeletal wyvern")) {
      tell_object(TP,"That is already here!");
      return 1;
    }
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^speaks words of summoning, and a cloudy haze forms in "
"the air, coalescing into the shape of a horrific skeletal wyvern!%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^%^BLACK%^You speak the words of summoning as a cloudy haze forms in the air, coalescing into "
"the shape of your faithful skeletal wyvern.%^RESET%^");
    ob=find_object_or_load("/d/avatars/nienne/dithaswyvern");
    ob->set_owner(TP);
    ob->move(EETO);
    return 1;
}

int isMagic(){ return 1; }