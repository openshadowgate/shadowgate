
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather jerkin");
	set_id(({ "jerkin", "leather jerkin" }));
	set_short("%^BOLD%^%^GREEN%^Jerkin of the %^RESET%^%^GREEN%^F%^BOLD%^o%^RESET%^%^GREEN%^r%^ORANGE%^e%^GREEN%^s%^BOLD%^t%^RESET%^");
set_obvious_short("%^RESET%^%^GREEN%^A green leather jerkin%^RESET%^");
	set_long("%^GREEN%^This snug fitting sleeveless jerkin is made of the"+
		" finest softest leather.  The soft leather has been dyed an "+
		"intense green shade, giving the fabric added depth.  Stitched"+
		" into the leather on the left and right breast are images of a "+
		"cluster of three %^ORANGE%^oak%^RESET%^%^GREEN%^ leaves.  The "+
		"front of the jerkin proudly displays an image of a %^BOLD%^%^WHITE%^"+
		"unicorn's head%^RESET%^%^GREEN%^, facing to the left.  "+
		"%^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r"+
		"%^BOLD%^y%^RESET%^%^GREEN%^ threads are used to give the image "+
		"depth and a majestic touch.  The inside of the sleeveless jerkin "+
		"is lined with soft %^BOLD%^cashmere wool%^RESET%^%^GREEN%^, giving"+
		" it a hidden luxury to the wearer.  The jerkin seems to be treated"+
		" with magic to protect it from dirt and filth, never seeming to "+
		"stain.%^RESET%^\n");
	set_weight(4);
	set_value(4000);
	set_lore("Feledor Oakbow was a half-elven ranger dedicated to the ways of"+
		" Mielikki, who became a hero both of Silvanus' and Mielikki's faith."+
		"  Working to protect the forest around the Moonstone Valley from the"+
		" growing number of undead and monsters, Feledor provided to be a "+
		"valuable aid to the druids and fey.  With his trusty oak bow and his"+
		" twin broadswords, Feledor would not wait for the creatures of the "+
		"forest to come to him, he went to them.  Stalking through the corrupted"+
		" woods, Feledor proved to be effective in thinning the monsters out.  "+
		"The fey and druids of the valley came together to craft him a jerkin in"+
		" honor of his work.  Though the last anyone remembers of seeing Feledor"+
		" was when he went of to find a new plant that was growing in the woods,"+
		" one rumored to turn the monsters and animals of the forest into zombies.");
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
   if((int)ETO->query_lowest_level() < 18){
      tell_object(ETO,"This jerkin is too fine for you!");
      return 0;
   }
   if((string)ETO->query_gender() == "male"){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" slides into a jerkin that molds itself to his body, accentuating every muscle of his torso.",ETO);
	tell_object(ETO,"%^GREEN%^You slide yourself into the handsome jerkin, feeling the soft warmth of the silver cashmere against your skin.");
ETO->add_stat_bonus("charisma",2);
ETO->add_attack_bonus(1);
	return 1;
   }
   tell_object(ETO,"Try as you might, you just can't seem to fit "+
      "the cashmere jerkin to your form.");
   return 0;
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" slides off the green jerkin and lets out a slight sigh.",ETO);
	tell_object(ETO,"%^GREEN%^You remove the snug fitting jerkin, giving a slight sigh as you do so.");
ETO->add_stat_bonus("charisma",-2);
ETO->add_attack_bonus(-1);
	return 1;
}
