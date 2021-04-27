#include <std.h>
#include "/cmds/priest/minor_creation.h"
inherit ARMOUR;

int OWNED, tracker, trackerb;
string owner;

void create(){
	::create();
	set_name("loin cloth");
	set_id(({ "loin cloth", "useful loincloth", "loincloth" }));
	set_short("%^RESET%^%^ORANGE%^U%^YELLOW%^s%^BLACK%^e%^YELLOW%^f%^RESET%^%^ORANGE%^ul L%^YELLOW%^o%^BLACK%^i%^YELLOW%^n%^RESET%^%^ORANGE%^cl%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^th%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a leather loincloth%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Made from leather, this garment is designed to be buckled about the waist and features a sturdy looking %^BOLD%^%^BLACK%^black belt %^RESET%^%^ORANGE%^to which the leather has been sewn along the sides and back.  Curved and shaped around the hips, a long strip of narrow leather has been left hanging in the back.  The front of the garment is free of leather, but an oval loop of %^YELLOW%^brass %^RESET%^%^ORANGE%^is affixed below the buckle.  Through this, the strip of leather can be threaded after being drawn between the legs.  The strip is long enough so that a slight skirt forms in front, adding an additional layer of %^BOLD%^%^BLACK%^protection %^RESET%^%^ORANGE%^to the delicate spot it covers.  Curiously, a second %^YELLOW%^ring %^RESET%^%^ORANGE%^has been sewn into the back, just below where the tailbone of a humanoid might end.  The second ring appears to have been added as an afterthought, but the craftsmanship is still exceptional.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^A little tag on the back of the belt reads:
%^RESET%^%^ORANGE%^This useful tool will make you what you %^RED%^need%^ORANGE%^ in any given situations.  All you have to do is ask and you'll find a bandage or climbing tools, a lantern or dark lantern along with a vial of oil or dark oil.  You can request a fishing pole, some flint, a rope, a torch, a square of soap or even a writing quill.  You can even get a small sack or a pouch.  And for protection some scalemail and robes, or a mace and shield to defend yourself.  Just will what you %^RED%^need%^ORANGE%^.%^RESET%^

AVATAR
	);
     set("langage","kobold");	set_weight(2);
	set_value(2000);
	set_lore(
@AVATAR
The Seneca Armory pledged to make a suit of armor for the first place winner of the Adventurous Summer storytelling contest. What they didn't anticipate was who would win, a little topaz kobold named Adderlash.  After a great deal of debate and a lot more failed attempts, this loincloth was created for the scaled creature as his prize.  Some rumors say that even though it was a strange request, that the armor was still imbued with a magical enchantment worthy of anything that might be made at the Seneca Armory. 

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("clothing");
	set_limbs(({ "left leg", "right leg" }));
	set_size(1);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^You strap the belt around your waist and wrap the leather flap up between your legs, marveling at how your tail fits just right through the hole in the back.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^The brass rings clang together like a bell as you draw the loincloth off and toss it aside.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("create_fun","need");
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
   }
}

int create_fun(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     notify_fail("You need to be wearing the loincloth.\n");
     return 0;
   }
   if(!str) {
     notify_fail("What do you need?\n");
     return 0;
   }
   if(member_array(str,keys(STUFF)) == -1){
      notify_fail("The loincloth cannot conjure you a "+str+"!\n");
      return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used up the loincloth's enchantments for today.");
     return 1;
   }
   if(trackerb) {
     tracker = time() + 28800;
     trackerb = 0;
   }
   else { trackerb = 1; }
   new("/cmds/priest/_minor_creation")->use_spell(TP,str,25);
   return 1;
}