#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("wooden armor");
	set_id(({ "armor", "wooden armor", "light wooden armor", "armor of the living forest" }));
	set_short("%^RESET%^%^ORANGE%^armor of the %^GREEN%^li%^ORANGE%^v%^GREEN%^in%^BOLD%^g %^RESET%^%^ORANGE%^fo%^GREEN%^r%^ORANGE%^e%^GREEN%^%^BOLD%^s%^RESET%^%^ORANGE%^t%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^light wooden armor%^RESET%^");
	set_long(
"%^RESET%^This armor is a spectacular creation, formed entirely of %^ORANGE%^wood%^RESET%^ from several different types of trees, it is light, flexible, yet created masterfully. The %^ORANGE%^plates of wood%^RESET%^ have been overlapped and tied with %^BLACK%^%^BOLD%^dried%^RESET%^ and %^ORANGE%^cured%^RESET%^ %^GREEN%^vines%^RESET%^ that seem to provide as much structure as any metal rivets. The entire surface of the armor is scored with %^BLACK%^%^BOLD%^cuts%^RESET%^ and %^BLACK%^%^BOLD%^nicks%^RESET%^"
", but the %^ORANGE%^wood %^RESET%^itself looks fresh and alive. An %^BOLD%^ivory crest %^RESET%^is inlaid into the left breast of the armor of a unicorn. The inside of the armor is lined with %^GREEN%^green silk %^RESET%^and buckles at the side with %^BOLD%^ivory buckles%^RESET%^."
	);
	set_weight(15);
	set_value(10000);
	set_lore(
@AVATAR
Crafted in the deepest forest workshops of The Needles, this armor was to
be the mantle of the second in command of The Needles. Its creation was
blessed by Mielikki, and over the year it took to craft it, a vigilant
unicorn stood over the armorsmith. The armor fell into obscurity as it was
lost in transport to a Malarite raid.
AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
        set_property("enchantment",4);
        set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
        set_struck((:TO,"struck":)); // Changed from struck_func 6/12/06 by Lujke, as the
                                     // function had actually been defined as 'struck'
}
int wear_func(){
   if((string)ETO->query_diety() != "mielikki" && !avatarp(ETO)) {
     tell_object(ETO,"The armor doesn't seem to fit you.");
     tell_room(EETO,"The armor doesn't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+"%^RESET%^%^GREEN%^ buckles on the "+query_short()+"%^RESET%^%^GREEN%^, the wood seeming to adjust itself around them%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^As you buckle on the "+query_short()+"%^RESET%^%^GREEN%^, you can feel the wood stretch and settle against you%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETOQCN+"%^RESET%^%^GREEN%^ removes the "+query_short()+"%^RESET%^%^GREEN%^ slowly%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^GREEN%^As you remove the "+query_short()+"%^RESET%^%^GREEN%^ the wood becomes still again%^RESET%^");
	return 1;
}

int struck(int damage, object what, object who){
   int level;
   if(!objectp(EETO)) return 1;
   if(EETO->query_property("no sticks")) return 1;
   if(present("snake 5",EETO)) return 1;
   if(random(1000) <= 300){
     if(EETO->query_property("used sticks")) EETO->remove_property("used sticks");
     tell_room(EETO,"%^ORANGE%^"+who->QCN+"'s blow causes shards of wood to "
"fall from "+ETO->QCN+"'s armor, and they come alive as they hit the "
"ground!%^RESET%^",ETO);
     tell_object(ETO,"%^ORANGE%^"+who->QCN+"'s blow causes shards of wood to "
"fall from your armor, and they come alive as they hit the ground!%^RESET%^");
   level = (int)ETO->query_lowest_level() - 8;
     new("/cmds/priest/_sticks_into_snakes")->use_spell(ETO,0,level);
     return 1;
   }
   return 1;
}
