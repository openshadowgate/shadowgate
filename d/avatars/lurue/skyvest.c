#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("vest of the skies");
	set_id(({ "vest", "vest of the skies", "sky vest", "armor", "leather", "buckskin", "buckskin vest", "embroidered vest" }));
	set_short("%^YELLOW%^V%^CYAN%^e%^YELLOW%^st %^CYAN%^o%^YELLOW%^f t%^CYAN%^h%^YELLOW%^e %^YELLOW%^Sk%^CYAN%^i%^YELLOW%^es%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^an %^GREEN%^e%^BLUE%^m%^WHITE%^b%^RED%^r%^CYAN%^o%^YELLOW%^i%^RESET%^%^CYAN%^d%^RED%^e%^WHITE%^r%^BLUE%^e%^GREEN%^d %^ORANGE%^buckskin vest%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This little buckskin vest is finely made and padded with soft cotton inside to make it a protective as well as stylish.  Buttoned up the front via %^YELLOW%^wooden buttons%^RESET%^%^ORANGE%^, the jacket is meant to fit a small child or very tiny person.  Though the cut is standard, it is the elaborate detail of embroidery that sets this jacket apart.  Covered in %^YELLOW%^gold%^RESET%^%^ORANGE%^, %^GREEN%^green%^ORANGE%^, %^BLUE%^blue%^ORANGE%^, %^RED%^red%^ORANGE%^, orange and %^WHITE%^silver %^ORANGE%^stitches, the whole vest is ornamented with intricately detailed birds. From tiny %^BLUE%^humming birds%^ORANGE%^ to large %^YELLOW%^hawks %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^owls%^RESET%^%^ORANGE%^, the birds fly amongst lush %^GREEN%^foliage %^ORANGE%^and %^BOLD%^%^CYAN%^brilliant blue %^RESET%^%^ORANGE%^skies.  A delicate %^YELLOW%^gold braid %^RESET%^%^ORANGE%^has been added to the hems adding extra eloquence to the already stunning piece. %^RESET%^

AVATAR
	);
	set_weight(13);
	set_value(4000);
	set_lore(
@AVATAR
Amongst many of the firbolg clans it is tradition to create items of spectacular hand-crafted beauty as well as functionality.  This tradition is so well kept amongst some of the clans that some seamstresses spend their entire life creating just one perfect garment.  This vest is the work of such a life's craft.  Designed by Olga Heathrawl the small vest was a great challenge for the large fingered woman.  When questioned why she would make a child's vest she always said that there was a purpose but would never explain why.  On the day when she added the final stitch Olga handed the vest to her youngest grandchild Verna and told her that when the day came for the vest to be bestowed, Verna would have the wisdom to know.  Olga died shortly thereafter.

AVATAR
	);
	set_property("lore difficulty",22);
//	set("wisbonus",2);
      set_item_bonus("wisdom",2);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(1);
      set_ac(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
   if((string)ETO->query_name() != "kerrid") {
     tell_object(ETO,"The vest just doesn't fit you.");
     return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" slips the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ around their shoulders and seems ready to take on the world!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^Slipping the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ over your shoulders, you suddenly feel as though the whole world is open to you!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" sighs as they remove their %^RESET%^%^"+query_short()+"%^RESET%^.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The world seems less vivid as you draw the %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ off.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^The bird designs on "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ come to life and fly toward "+who->QCN+"!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^The %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ seems to %^YELLOW%^glow %^CYAN%^for a moment then a flock of birds bursts forth surrounding "+who->QCN+" and confusing their aim!%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^The bird designs on "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^CYAN%^ come to life and fly toward you!  The whole world seems to explode in a brilliant burst of colorful, confusing wings!%^RESET%^");
		who->set_paralyzed(random(5));
return damage;	}
}