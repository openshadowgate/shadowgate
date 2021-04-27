// customised hairpin for dorje directly copied from token hunt's 'forgotten soul', paid by alzar.
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("ebony hairpin");
   set_short("%^BLACK%^%^BOLD%^Black Talon%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^ebony hairpin%^RESET%^");
   set_id(({"hairpin","pin","Hairpin","Pin","ebony hairpin","black talon","black talon hairpin","talon"}));
   set_long("%^MAGENTA%^This elegant hairpin is crafted from a single piece of "
"%^BLACK%^%^BOLD%^flawless ebony%^RESET%^%^MAGENTA%^.  The handle is shaped to fit "
"comfortably within one's hand, and is carved in an ornate fashion, set with tiny "
"chips of %^BOLD%^%^MAGENTA%^am%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^th%^WHITE%^y%^MAGENTA%^st%^RESET%^%^MAGENTA%^ "
"and %^BOLD%^%^WHITE%^di%^CYAN%^a%^WHITE%^mond%^RESET%^%^MAGENTA%^, that glitter darkly in any reflected "
"light.  A smooth, slender point extends from this handle, to be placed through the hair, "
"though this hairpin seems uncharacteristically sharp - it would be best to be careful "
"when trying to wear it.%^RESET%^\n");
   set_weight(4);
   set_value(1025);
   set_ac(0);
   set_size(-1);
   set_type("clothing");
   set_limbs(({"head"}));
   set_lore("%^WHITE%^%^BOLD%^A particularly distinct accessory created by crafters hired "
"by the temple of the Black Hand, and gifted to the reknowned assassin Tatsu'ei, as a "
"reward for her service in the temple's name.  Some rumours tell it to be more than simply "
"a pretty hairpiece, but quite dangerous in her hands also.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_property("enchantment",2);
   set("intbonus",1);
   set("wisbonus",1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"strike_func":));
}

int wear_fun() {
   tell_object(ETO,"%^MAGENTA%^You twist your hair into place and secure it with the hairpin, careful "
"not to harm yourself on its sharp tip.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" twists "+ETO->QP+" hair into place and secures it carefully "
"with the hairpin.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^MAGENTA%^You slide the hairpin free, letting your hair fall loose again.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" slides the hairpin free, letting "+ETO->QP+" hair fall "
"loose.%^RESET%^",ETO);
   return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes glow with a fathomless %^RESET%^%^MAGENTA%^purple aura %^BOLD%^%^BLACK%^as they move between "+who->QCN+"'s defenses and land a telling blow.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^Knowledge fills your mind and the world seems to fade away as your focus narrows upon "+who->QCN+".  With a movement both %^RESET%^%^MAGENTA%^graceful %^BOLD%^%^BLACK%^and %^RESET%^cunning%^BOLD%^%^BLACK%^, you dart forward, turn and lay a devastating blow upon "+who->QCN+"'s body!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s eyes glow with a fathomless %^RESET%^%^MAGENTA%^purple aura %^BOLD%^%^BLACK%^as they move between your defenses and land a telling blow.%^RESET%^");
		who->do_damage("torso",roll_dice(12,2));
return damage;	}
}