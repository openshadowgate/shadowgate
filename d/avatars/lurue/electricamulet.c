#include <std.h>
inherit ARMOUR;

int tracker;

void create(){
	::create();
	set_name("amulet");
	set_id(({ "storm-touched amulet", "amulet", "storm touched amulet" }));
	set_short("%^YELLOW%^S%^CYAN%^t%^YELLOW%^o%^BLACK%^r%^YELLOW%^m-T%^WHITE%^o%^YELLOW%^uc%^CYAN%^h%^YELLOW%^ed A%^BLACK%^m%^YELLOW%^ul%^CYAN%^e%^YELLOW%^t%^RESET%^");
	set_obvious_short("%^RESET%^a curious %^YELLOW%^a%^CYAN%^m%^YELLOW%^u%^WHITE%^l%^BLACK%^e%^YELLOW%^t%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^Suspended from a necklace of %^CYAN%^raindrops%^WHITE%^, a glittering ball of %^YELLOW%^lightning %^WHITE%^hovers.  Glittering with the raw %^YELLOW%^electric power%^WHITE%^ of a storm's lightning, this bolt seems to be self contained and can be touched, handled or otherwise manipulated.  And yet, just touching it causes the hairs on your arm to stand on end as the %^CYAN%^whisper of power %^WHITE%^fills your senses and awakens the potential of the necklace's power.%^RESET%^


AVATAR
	);
	set_weight(3);
	set_value(5000);
	set_lore(
@AVATAR

Lightning, when subjected to intense, powerful, psionic powers can, on occasion, be made solid.  Or so the shapers sometimes claim.  These claims are founded in the principles that the shapers use to guide them in the creation of energy forms.  The claims further suggest that these raw, random creations are not as restricted as the their own abilities, but as raw power have the unlimited ability to call upon their inner powers.  Or at least as much as the owner is able to draw upon them. 


AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
}

int wear_func(){
      if((string)ETO->query_name() != "innaeli" && !avatarp(ETO)) {
        tell_object(ETO,"This armor doesn't fit you.");
        return 0;
      }
	tell_object(ETO,"%^YELLOW%^As you draw your "+query_short()+" %^YELLOW%^on that sense of potential fills your mind with a single command: %^WHITE%^release lightning%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("zap_fun","release");
}

int zap_fun(string str){
   object *myatk, target;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You need to be wearing the amulet.\n");
   if(!str) return notify_fail("Release what?\n");
   if(str != "lightning") return notify_fail("You can't release that.\n");
   myatk = TP->query_attackers();
   if(!sizeof(myatk)) return notify_fail("There are no foes near enough to unleash the storm upon!\n");
   if(tracker > time()) return notify_fail("The amulet fizzles but seems not fully charged yet.\n");
   target = myatk[random(sizeof(myatk))];
   if(!objectp(target)) return notify_fail("The amulet fizzles but doesn't seem to work.\n");
   tracker = time() + 43200;
   new("/cmds/wizard/_chain_lightning")->use_spell(TP,target,35);
   return 1;
}