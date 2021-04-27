#include <std.h>
inherit ARMOUR;
int tracker;

void create(){
	::create();
	set_name("skullcap");
	set_id(({ "skullcap", "cap", "draconic mind" }));
	set_short("%^BOLD%^%^WHITE%^S%^BLUE%^k%^RESET%^u%^BOLD%^%^BLUE%^l%^WHITE%^l%^RESET%^%^BLUE%^cap %^ORANGE%^of the%^BOLD%^%^RED%^ Dr%^RESET%^%^RED%^a%^BOLD%^%^RED%^c%^RESET%^%^RED%^o%^BOLD%^%^RED%^n%^RESET%^%^RED%^i%^BOLD%^c%^YELLOW%^ M%^RESET%^%^ORANGE%^i%^BOLD%^nd%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^sca%^BOLD%^l%^RESET%^%^ORANGE%^ed %^BLUE%^skullcap%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^This skullcap consists of tiny overlapping %^ORANGE%^to%^BOLD%^p%^RESET%^%^ORANGE%^az%^MAGENTA%^ scales of a %^BOLD%^%^WHITE%^br%^CYAN%^i%^WHITE%^lli%^CYAN%^a%^WHITE%^nt%^RESET%^%^MAGENTA%^ hue. The scales have been sewn on what can only be described as an %^CYAN%^octopus%^MAGENTA%^ tentacle, complete with its sticky suction pads. The cap extends down past the back of the %^BOLD%^%^WHITE%^s%^BLUE%^k%^RESET%^u%^BOLD%^%^BLUE%^l%^WHITE%^l%^RESET%^%^MAGENTA%^ to protect the neck of the wearer minimally. This section is free of the suction pads, leaving a %^ORANGE%^mo%^RESET%^t%^ORANGE%^t%^RESET%^l%^ORANGE%^ed%^MAGENTA%^ smooth %^BLUE%^r%^RESET%^u%^BLUE%^bbe%^RESET%^r%^BLUE%^y%^MAGENTA%^ skin. There are two small %^BOLD%^%^CYAN%^holes%^RESET%^%^MAGENTA%^ high up on the forehead of the cap to allow two %^RESET%^protrusions%^MAGENTA%^ to extend through. Closer examination reveals unknown %^BOLD%^%^GREEN%^gl%^RESET%^%^BLUE%^y%^BOLD%^%^GREEN%^phs %^RESET%^%^MAGENTA%^ on the surface of the scales.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^As you peer at the %^GREEN%^gl%^RESET%^%^BLUE%^y%^BOLD%^%^GREEN%^phs%^WHITE%^ they rearrange themselves and form a message:

	%^RESET%^%^CYAN%^Feel your mortal soul %^BOLD%^%^WHITE%^rise%^RESET%^%^CYAN%^ to truly be free.%^RESET%^

AVATAR
	);
     set("langage","kobold");	set_weight(3);
	set_value(4750);
	set_lore(
@AVATAR
There are still dragons who inhabit not only the Prime Material Plane, but the Inner Planes. This race of dragons are known as gem dragons. Because of their detachment from this world, they are still very much steeped in draconica magic. Kiirolathnaleter, The Incarnum, created this skullcap specifically for a kobold, after hearing about a certain one who has been attempting to bring draconica back into this world, in hopes that it will aid him in his efforts. The scales used to form the cap are cast off scales from Kiirolathnaleter's head and neck area, so that they are small enough not to encumber the kobold. He then laid his ancient magic upon the item, to further enhance it and keep it upon the kobolds head.

AVATAR
	);
	set_property("lore difficulty",20);
	set("intbonus",1);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(1);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The %^GREEN%^gl%^RESET%^%^BLUE%^y%^BOLD%^%^GREEN%^phs%^BLUE%^ on "+ETOQCN+"'s skullcap flash a %^WHITE%^bright%^RESET%^%^ORANGE%^ to%^BOLD%^p%^RESET%^%^ORANGE%^az%^BOLD%^%^BLUE%^ and %^CYAN%^pu%^RESET%^l%^BOLD%^%^CYAN%^ses%^BLUE%^ once before subsiding as they wear it.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the suction cups %^RESET%^%^GREEN%^grip%^BOLD%^%^BLUE%^ your head as you pull the skullcap on and fit your horns into the holes.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^You can hear a slight *slocking* noise as "+ETOQCN+" removes their cap.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the cups release their hold on you as you remove the cap.%^RESET%^");
	return 1;
}

void init() {
   ::init();
   add_action("fatefun","rise");
}

int fatefun(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You must be wearing the skullcap to activate it.");
     return 1;
   }
   if(str) {
     tell_object(TP,"You can only use <rise>.");
     return 1;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the skullcap's power today.");
     return 1;
   }
   tracker = time() + 28800;
   new("/cmds/wizard/_fly")->use_spell(TP,TP,30);
   return 1;
}