#include <std.h>
inherit ARMOUR;
int hooded;

void create(){
	::create();
	set_name("hooded robe");
	set_id(({ "robe", "hooded robe", "blue hooded robe", "blue robe" }));
	set_short("%^BOLD%^%^BLUE%^Robe of %^YELLOW%^s%^BOLD%^%^WHITE%^t%^YELLOW%^a%^BOLD%^%^WHITE%^r%^YELLOW%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A blue hooded robe%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This robe is made from a deep blue and thick cloth.  It has been sewn flawlessly and shows no signs of wearing, suggesting that something abnormal has been prolonging its life.  Sewn into the robe, on both the front and back, are patterns of %^YELLOW%^s%^BOLD%^%^WHITE%^t%^YELLOW%^a%^BOLD%^%^WHITE%^r%^YELLOW%^s%^BOLD%^%^BLUE%^.  The patterns vary dramatically in size and coloration and offer an almost hypnotic affect to anyone gazing at them.  A hood has been sewn seamlessly to the top of the back of the robe and would allow the wearer to %^RESET%^%^WHITE%^pull%^BOLD%^%^BLUE%^ it up over their head at will.%^RESET%^");
	set_weight(4);
	set_value(1000);
	set_lore(
@AVATAR
%^RED%^This robe was rumored to have had a powerful affect at one time, but it has either been drained of its magic or the knowledge of the method to activate it has been lost.%^RESET%^
AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
 hooded = 0;
}

void init() {
 ::init();
 if(interactive(ETO)) {
 add_action("pull_function","pull");
 }
}

int pull_function(string str) {
 if(str == "hood") {
   if(!TO->query_worn()) {
     tell_object(ETO,"You need to wear the robe first.");
     return 1;
   }
   if(hooded == 0) {
     hooded = 1;
     tell_object(ETO,"%^BOLD%^%^BLUE%^You pull the hood of the robe up over your head.%^RESET%^");
     if(!ETO->query_invis()) {
       tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLUE%^ pulls the hood of "+ETO->QP+"%^BOLD%^%^BLUE%^ robe up over "+ETO->QP+"%^BOLD%^%^BLUE%^ head.%^RESET%^",ETO);
     }
     return 1;
   }
   if(hooded == 1) {
     hooded = 0;
     tell_object(ETO,"%^BOLD%^%^BLUE%^You pull the hood of the robe from your head.%^RESET%^");
     if(!ETO->query_invis()) {
       tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLUE%^ pulls the hood of "+ETO->QP+"%^BOLD%^%^BLUE%^ robe from "+ETO->QP+"%^BOLD%^%^BLUE%^ head.%^RESET%^",ETO);
     }
     return 1;
   }
  }
 return 0;
}

int wear_func(){
 if(!ETO->query_invis()) {
	 tell_room(EETO,ETO->QCN+"%^YELLOW%^ pulls the robe tightly around "+ETO->QO+"self.%^RESET%^",ETO);
  }
	 tell_object(ETO,"%^YELLOW%^You pull your robe tightly around yourself.%^RESET%^");
	 return 1;
}

int remove_func() {
 if(!ETO->query_invis()) {
	 tell_room(EETO,ETO->QCN+"%^YELLOW%^ loosens the robe.%^RESET%^",ETO);
 }
	tell_object(ETO,"%^YELLOW%^You loosen your robe.%^RESET%^");
	return 1;
}
