#include <std.h>
inherit ARMOUR;
int tracker;

void create(){
	::create();
	set_name("glass amulet");
	set_id(({ "amulet", "hourglass", "hourglass of the dark fate", "dark fate hourglass", "hour glass", "glass and horn amulet" }));
	set_short("%^BOLD%^%^BLACK%^H%^RESET%^%^ORANGE%^o%^YELLOW%^u%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^gl%^RESET%^%^ORANGE%^a%^YELLOW%^s%^BLACK%^s %^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^f t%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e D%^RESET%^%^ORANGE%^a%^YELLOW%^r%^BLACK%^k F%^RESET%^%^ORANGE%^a%^YELLOW%^t%^BLACK%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^RESET%^glass %^ORANGE%^and %^BOLD%^%^BLACK%^horn %^RESET%^%^ORANGE%^amulet%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Hanging from a %^ORANGE%^golden chain%^RESET%^, this small %^BOLD%^%^WHITE%^crystalline amulet %^RESET%^is hourglass in shape.  Two slender globes of %^BOLD%^%^WHITE%^clear glass %^RESET%^are connected to one another through a narrowed tube in the center.  Through this, a pool of powdery, %^BOLD%^%^BLACK%^ash-gray sand %^RESET%^slides with a fine %^ORANGE%^trickle %^RESET%^when the device is tilted back and forth.  Caps of %^BOLD%^%^BLACK%^black horn %^RESET%^encircle each end, allowing it to be set upon a flat surface.  From these horn caps, five long, thin %^BOLD%^%^BLACK%^prongs %^RESET%^wrap their respective ends tightly in a knobbed grip.  Uneven and curved, the prongs give an appearance of %^BOLD%^%^WHITE%^%^finger bones %^RESET%^stripped of flesh and %^BOLD%^%^BLACK%^blackened %^RESET%^with fire.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR


             %^RESET%^%^MAGENTA%^>> %^BLACK%^%^BOLD%^fate %^RESET%^%^MAGENTA%^<<%^RESET%^



AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(4000);
	set_lore(
@AVATAR

%^BOLD%^%^BLACK%^There are those who whisper in the shadows of the darkest bars, that when Beshaba walks amongst the world she sometimes comes as a trinket seller, hawking her wares to any who will buy, and sometimes to those who will not. The ones who whisper these things often claim to have seen Black Bess and to know that this rumor is in fact true.  They claim this with such fervor that it is hard to deny their statement as anything but truth.  For they tell of how a seller will grip them by the arm in such a way that their whole body is commanded to stay, and into their hands this vendor will press a token.  "A pretty for your Lady's neck," she might say, "is only a copper, a copper is all."  Those who pay may find themselves surrounded by others whose fortune has failed, while those who refuse still carry away the trinket somehow and find themselves surrounded by those whose fortunes are much better then their own.    %^RESET%^


AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      tracker = 0;
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks startled as they look down at their "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you fasten the clasp of the %^RESET%^%^ORANGE%^golden chain%^BOLD%^%^BLACK%^, the trickle of sand begins to flow upward within its %^WHITE%^crystalline %^BLACK%^chamber.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" almost looks relieved as they remove their "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You undo the %^RESET%^%^ORANGE%^golden clasp %^BOLD%^%^BLACK%^and the ashy colored sand ceases its upward flow through the %^WHITE%^crystalline %^BLACK%^hourglass.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("fatefun","fate");
}

int fatefun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You must be wearing the amulet to activate it.");
     return 1;
   }
   if(str) {
     tell_object(TP,"You can only use <fate>.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the amulet's power today.");
     return 1;
   }
   tracker = time() + 28800;
   new("/cmds/spells/f/_fortune_fate")->use_spell(TP,TP,30,100,"cleric");
   return 1;
}
